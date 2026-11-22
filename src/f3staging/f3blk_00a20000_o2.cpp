// src/f3staging/f3blk_00a20000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a29490 (community match, verified in this file)
struct Sparse434 {
    int* data;
    unsigned int unk04;
    int last;
    __forceinline int SkipEmpty(int index) const {
        int limit = last;
        while (index <= limit && data[index] == -1)
            ++index;
        return index;
    }
};
struct Owner434 {
    void FUN_00a29450(int key, int value);
    void FUN_00a29490(Sparse434* source);
};
// pdb: hkDataObject::~hkDataObject | hkDataObject.obj | fnv360_0721_beta, call_gap, low
void Owner434::FUN_00a29490(Sparse434* source) {
    for (int index = source->SkipEmpty(0); index <= source->last; index = source->SkipEmpty(index + 1))
        FUN_00a29450(source->data[index], source->data[source->last + index + 1]);
}

// @f3 0x00a26260 (community match, verified in this file)
struct Node472 {
    unsigned short type,unk02; unsigned int unk04,unk08,unk0c,unk10; Node472* next;
    void FUN_009a1a90(void*,float,void*,void*,void*,void*);
    void FUN_009a1a80(void*,float,void*,void*,void*,void*);
    void FUN_009a1da0(void*,float,void*,void*,void*,void*);
};
struct Holder472 { unsigned int unk00,unk04,unk08,unk0c; Node472* node; };
struct FUN_00a26260 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    volatile Holder472* holder;
    void Dispatch(void*,float,void*,void*,void*,void*);
};
void FUN_00a26260::Dispatch(void* first,float scalar,void* third,void* fourth,void* fifth,void* sixth) {
    volatile Holder472* current=holder;
    Node472* node=current->node;
    if(!node) return;
    while(node->type>=0x17) {
        switch(node->type) {
        case 0x1a: node->FUN_009a1da0(first,scalar,third,fourth,fifth,sixth);break;
        case 0x18: node->FUN_009a1a80(first,scalar,third,fourth,fifth,sixth);break;
        case 0x17: node->FUN_009a1a90(first,scalar,third,fourth,fifth,sixth);break;
        }
        node=node->next;
    }
}

// @f3 0x00a3b660 (community match, verified in this file)
namespace f3m_00a3b660 {
namespace f3m_00a3b660 {
struct MaskArg
{
    unsigned int* ptr;
};

// pdb: setTerminalsFromVertex | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00a3b660(int key, MaskArg mask, int flag)
{
    unsigned int* __restrict p = mask.ptr;
    unsigned int u = (unsigned int)(key >> 4);
    int z = ~(u >> 3) & 1;
    int y = ~(u >> 2) & 1;
    int x = ~(u >> 1) & 1;
    unsigned int bit;
    if (flag != 0)
    {
        bit = 1u << (2 * (y + 2 * x));
        if (!(*p & (bit * 2)))
            *p += bit;
    }
    if (flag != 1)
    {
        bit = 1u << (2 * (z + 2 * x + 4));
        if (!(*p & (bit * 2)))
            *p += bit;
    }
    if (flag != 2)
    {
        bit = 1u << (2 * (z + 2 * y + 8));
        if (!(*p & (bit * 2)))
            *p += bit;
    }
}

void FUN_00a3b660_caller(int key, MaskArg mask, int flag)
{
    FUN_00a3b660(key, mask, flag);
}
}
}   // namespace f3m_00a3b660

// @f3 0x00a3ba00 (community match, verified in this file)
namespace f3m_00a3ba00 {
// pdb: getAxisMapFromFeatureBitSet | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) unsigned int FUN_00a3ba00(const float* apValues, int* piIndex)
{
    int idx;
    unsigned int uiFlag;
    if (apValues[0] > apValues[1])
    {
        idx = 0;
        uiFlag = 0x80;
    }
    else
    {
        idx = 1;
        uiFlag = 0x40;
    }
    if (apValues[2] > apValues[idx])
    {
        idx = 2;
        uiFlag = 0x20;
    }
    *piIndex = idx;
    return uiFlag;
}
volatile int g_in; volatile int g_out; float* volatile g_p; int* volatile g_i;
void caller_of_FUN_00a3ba00() { g_out = FUN_00a3ba00(g_p, g_i); }
}   // namespace f3m_00a3ba00

// @f3 0x00a3b6f0 (community match, verified in this file)
namespace f3m_00a3b6f0 {
inline void addCell9(int& mask, int cell) {
    int bit = 1 << (2*cell);
    if (!(mask & (2*bit))) mask += bit;
}
// pdb: setTerminalsFromEdge | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00a3b6f0(int& mask, int packedValue) {
    int axis = packedValue & 15;
    unsigned int bits = packedValue >> 4;
    int x = (~(bits >> 3)) & 1;
    int y = (~(bits >> 2)) & 1;
    int z = (~(bits >> 1)) & 1;
    if (axis == 0) addCell9(mask, y + 2*z);
    else if (axis == 1) addCell9(mask, x + 2*z + 4);
    else addCell9(mask, x + 2*y + 8);
}
volatile int input9;
int mask9;
void caller9() { FUN_00a3b6f0(mask9, input9); }
}   // namespace f3m_00a3b6f0

// @f3 0x00a23370 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e855ac[];
extern const char DAT_00e32798[];
namespace f3m_00a23370 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Command20 { const char* name; unsigned int ticks; unsigned int unk08; };
struct Stream20 { unsigned int unk00; Command20* cursor; unsigned int unk08; Command20* limit; };
struct Arg20 { unsigned int unk00; int key; char* base; };
struct Env20 { unsigned int unk00,unk04; void* context; };
struct Target20 { void FUN_00a21830(void*, Arg20*, Arg20*, Env20*, int); };
void __cdecl FUN_00a23320(int,void*);
// pdb: hkCpuSplitSimulationIslandJob | hkpCpuSplitSimulationIslandJob.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkCpuSplitSimulationIslandJob(Env20* env, Target20* target, Arg20* arg) {
    Stream20* s = (Stream20*)TlsGetValue(DAT_0116913c);
    Command20* c=s->cursor;
    if(c<s->limit) {
        c->name=DAT_00e855ac;
        _ReadWriteBarrier();
        volatile unsigned int ticks=(unsigned int)__rdtsc();
        c->ticks=ticks;
        s->cursor=c+1;
    }
    FUN_00a23320(arg->key,arg->base+0x5c);
    Stream20* s2=(Stream20*)TlsGetValue(DAT_0116913c);
    Command20* c2=s2->cursor;
    if(c2<s2->limit) {
        c2->name=DAT_00e32798;
        _ReadWriteBarrier();
        volatile unsigned int ticks2=(unsigned int)__rdtsc();
        c2->ticks=ticks2;
        s2->cursor=c2+1;
    }
    target->FUN_00a21830(env->context,arg,arg,env,0);
}
}   // namespace f3m_00a23370

// @f3 0x00a2a180 (community match, verified in this file)
namespace f3m_00a2a180 {
struct S_00dbe710_Element
{
    int unk00;
    int m_next;
};

class S_00dbe710
{
public:
    S_00dbe710_Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int unk0C;
    int unk10;
    int unk14;
    int m_firstFree;

    int FUN_00a2a180();
};

extern void __cdecl sub_901F10(void* arg0, int arg1);

int S_00dbe710::FUN_00a2a180()
{
    int idx = m_firstFree;
    if (idx != -1)
    {
        m_firstFree = m_data[idx].m_next;
        return idx;
    }
    int n = m_iElementCount;
    if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        sub_901F10(this, 8);
    m_iElementCount += 1;
    return n;
}
}   // namespace f3m_00a2a180

// @f3 0x00a2a1d0 (community match, verified in this file)
namespace f3m_00a2a1d0 {
namespace f3m_00a2a1d0 {
struct EntryA2 {
    int key;
    int next;
};
struct HashA2 {
    int* buckets;
    int unk04;
    int offset;
    int FUN_00922790(int key);
};
struct TableA2 {
    EntryA2* entries;
    int unk04;
    int unk08;
    HashA2 hash;
    int freeHead;
    int FUN_00a2a1d0(int key, int index);
};
// pdb: hkDataWorldDict::ObjectTracker::untrackStructArray | hkDataObjectDict.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkSerializeMultiMap<class hkDataClassDict *,class hkDataArrayImpl *,class hkPointerMap<class hkDataClassDict *,int,struct hkContainerHeapAllocator> >::removeByIndex)
// pdb params: a
int TableA2::FUN_00a2a1d0(int key, int index)
{
    int victim = entries[index].next;
    if (victim != -1) {
        entries[index] = entries[victim];
    } else {
        HashA2& h = hash;
        int h0 = h.FUN_00922790(key);
        victim = ((volatile int*)h.buckets)[h.offset + h0 + 1];
        if (victim != index) {
            entries[index] = entries[victim];
            h.buckets[h.offset + h0 + 1] = index;
        } else {
            h.buckets[h.offset + h0 + 1] = -1;
            index = -1;
        }
    }
    entries[victim].next = freeHead;
    freeHead = victim;
    return index;
}
}
}   // namespace f3m_00a2a1d0

// @f3 0x00a26c90 (community match, verified in this file)
namespace f3m_00a26c90 {

struct SectorTrack
{
    int m_iBytesUsedInLastSector;
    unsigned char** m_pSectors;
    int m_iSectorCount;
    int m_iUnk0c;
};

struct SectorCollector
{
    virtual void vf0();
    virtual void vf4();
    virtual void addArray(const char* name, int type, void* data, int usedBytes, int maxBytes);
    virtual void addChildObject(const char* name, int type, void* obj);
};

struct ContactInput
{
    unsigned char* m_pBase;
};



extern "C" void _ReadWriteBarrier(void);

typedef void(__cdecl* SectorVisitFn)(unsigned char* p, unsigned char* elem, void* in, void* collector);

// pdb: hkpAgentMachineUtil::calcNnStatistics | hkpAgentMachineUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap), high
void __cdecl hkpAgentMachineUtil_calcNnStatistics(SectorTrack* track, ContactInput* in, SectorCollector* collector)
{
    int k = 0;
    int i = 0;
    for (i = 0; i < track->m_iSectorCount; i++)
    {
        unsigned char* sec = track->m_pSectors[i];
        _ReadWriteBarrier();
        int used = (i + 1 == track->m_iSectorCount) ? track->m_iBytesUsedInLastSector : 0x200;
        collector->addArray("Sector", 8, sec, used, 0x200);
    }
    for (k = 0; k < track->m_iSectorCount; )
    {
        
        unsigned char* sec = track->m_pSectors[k];
        _ReadWriteBarrier();
        k++;
        unsigned char* end = (k == track->m_iSectorCount) ? sec + track->m_iBytesUsedInLastSector : sec + 0x200;
        unsigned char* p = sec;
        while (p < end)
        {
            unsigned char* elem;
            switch (p[0])
            {
            case 2:
            case 6:
                elem = p + 0x20;
                break;
            case 4:
                elem = p + 0x30;
                break;
            default:
                goto advance;
            }
            SectorVisitFn fn = *(SectorVisitFn*)(in->m_pBase + 0x16cc + p[1] * 80);
            if (fn)
                fn(p, elem, in, collector);
            collector->addChildObject("ContactMgr", 8, (void*)(*(int*)(p + 8)));
        advance:
            p += p[3];
        }
    }
}
}   // namespace f3m_00a26c90

// @f3 0x00a2a4e0 (community match, verified in this file)
namespace f3m_00a2a4e0 {
struct Block
{
    int size;
    int unk04;
    int unk08;
    int unk0C;
};

struct Entry
{
    unsigned char type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char size;
    int key1;
    int key2;
    int unk0C;
};

// pdb: hkAgent1nMachine_FindAgent | hkpAgent1nMachine.obj | tesv_win, objrun_open, low
Entry* __cdecl FUN_00a2a4e0(Block*** list, int key1, int key2, void** out)
{
    Block** ppBlock = *list;
    Block* pkBlock = *ppBlock;
    Entry* entry = (Entry*)((char*)pkBlock + 0x10);
    char* end = (char*)pkBlock + pkBlock->size + 0x10;
    ppBlock++;
    for (;;) {
        do {
            void* blocks;
            switch (entry->type) {
            case 2:
            case 3:
            case 6:
                blocks = (char*)entry + 0x10;
                break;
            case 4:
            case 5:
                blocks = (char*)entry + 0x20;
                break;
            case 1:
                return 0;
            case 0:
                goto advance;
            default:
                continue;
            }
            if (entry->key2 == key2 && entry->key1 == key1) {
                *out = blocks;
                return entry;
            }
        advance:
            entry = (Entry*)((char*)entry + entry->size);
        } while ((char*)entry < end);

        pkBlock = *ppBlock;
        entry = (Entry*)((char*)pkBlock + 0x10);
        end = (char*)pkBlock + pkBlock->size + 0x10;
        ppBlock++;
    }
}
}   // namespace f3m_00a2a4e0

// @f3 0x00a26a60 (community match, verified in this file)
namespace f3m_00a26a60 {
struct Header22 { int v[8]; };
struct S22 { int unk00; unsigned short count4; unsigned short count6; unsigned char unk08; unsigned char unk09; unsigned char byteA; unsigned char unk0b; int unk0c; Header22 hdr; float f[8]; };

// pdb: hkpSimpleContactConstraintAtomUtil::copyContents | hkpConstraintAtomUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_gap) + skyrim(call_seq), high
void __cdecl hkpSimpleContactConstraintAtomUtil_copyContents(S22* dst, S22* src)
{
    dst->hdr = src->hdr;
    dst->count4 = src->count4;
    float* sF = src->f;
    char* dstEnd = (char*)dst + (dst->count6 << 5) + 0x30;
    char* srcEnd = (char*)src + (src->count6 << 5) + 0x30;
    int stride = src->byteA;
    int i = 0;
    if (src->count4 > 0)
    {
        int inner = stride >> 2;
        float* dF = dst->f;
        do
        {
            dF[0]=sF[0]; dF[1]=sF[1]; dF[2]=sF[2]; dF[3]=sF[3];
            float* d2 = dF + 4; float* s2 = sF + 4;
            d2[0]=s2[0]; d2[1]=s2[1]; d2[2]=s2[2]; d2[3]=s2[3];
            dF += 8; sF += 8;
            int* sI = (int*)srcEnd; int* dI = (int*)dstEnd;
            int* sp = sI; int* dp = dI;
            for (int j = 0; j < inner; j++) *dp++ = *sp++;
            srcEnd += stride; dstEnd += stride;
        } while (++i < src->count4);
    }
}
}   // namespace f3m_00a26a60

// @f3 0x00a29dd0 (community match, verified in this file)
namespace f3m_00a29dd0 {
namespace f3m_00a29dd0 {
struct QSparse {
    int* data;
    unsigned int unk04;
    int last;
    __forceinline int SkipEmpty(int index) const {
        int limit = last;
        while (index <= limit && data[index] == -1)
            ++index;
        return index;
    }
};
class FUN_00922cb0 {
public:
    int* data;
    unsigned int unk04;
    int last;
    FUN_00922cb0() throw();
    ~FUN_00922cb0() throw();
    void FUN_00922710(int key, int value) throw();
};
class FUN_00a29d30 {
public:
    int unk00;
    int unk04;
    int unk08;
    QSparse map;
    int unk18;
    FUN_00a29d30() throw();
    ~FUN_00a29d30() throw();
    int FUN_00a297c0() throw();
    void FUN_00a29490(FUN_00922cb0* source) throw();
};
struct QNode {
    int FUN_009b0490() throw();
};
struct QMap {
    int FUN_009b10f0(int a, int b) throw();
    void FUN_009b0e60(int a, QNode* b) throw();
};
struct QVisitor {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual int v2C(int x) throw();
};
struct QCloner {
    QNode* FUN_00a29960(QNode* src, int x, FUN_00a29d30* pending) throw();
    QNode* FUN_00a29dd0(QNode* src, QVisitor* visitor, QMap* map, QMap* out) throw();
};

// pdb: hkDataObjectUtil::toResourceWithRegistry | hkDataObjectUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: src, classReg
QNode* QCloner::FUN_00a29dd0(QNode* src, QVisitor* visitor, QMap* map, QMap* out) throw()
{
    FUN_00a29d30 pending;
    int k1 = src->FUN_009b0490();
    int k2 = src->FUN_009b0490();
    int mapped = map->FUN_009b10f0(k2, k1);
    QNode* result = FUN_00a29960(src, mapped, &pending);
    int rk = result->FUN_009b0490();
    out->FUN_009b0e60(rk, result);
    if (pending.FUN_00a297c0() > 0) {
        FUN_00922cb0 found;
        for (int i = pending.map.SkipEmpty(0); i <= pending.map.last; i = pending.map.SkipEmpty(i + 1)) {
            QNode* n = (QNode*)pending.map.data[i];
            int n1 = n->FUN_009b0490();
            int n2 = n->FUN_009b0490();
            int key = map->FUN_009b10f0(n2, n1);
            int value = visitor->v2C(key);
            if (!value)
                value = out->FUN_009b10f0(key, 0);
            if (value)
                found.FUN_00922710((int)n, value);
        }
        pending.FUN_00a29490(&found);
    }
    if (pending.FUN_00a297c0() > 0) {
        FUN_00922cb0 found;
        for (int i = pending.map.SkipEmpty(0); i <= pending.map.last; i = pending.map.SkipEmpty(i + 1)) {
            QNode* n = (QNode*)pending.map.data[i];
            found.FUN_00922710((int)n, (int)FUN_00a29dd0(n, visitor, map, out));
        }
        pending.FUN_00a29490(&found);
    }
    return result;
}
}
}   // namespace f3m_00a29dd0

// @f3 0x00a3b750 (community match, verified in this file)
namespace f3m_00a3b750 {
struct EntryA3 {

    union {

        unsigned int pair00;

        struct {

            unsigned char kind00;

            unsigned char code01;

            unsigned short unk02;

        };

    };

};

struct RecordA3 {

    EntryA3 entries00[8];

    unsigned char depth20;

    unsigned char count21;

    bool status22;

};

static __forceinline int AxisA3(int packed) {

    int code=packed>>4;

    if(code&8) return 0;

    return (code&4)?1:2;

}

static __forceinline void AddA3(int& counts,int key) {

    int bit=1<<((unsigned int)key*2);

    if(!(counts&(bit*2))) counts+=bit;

}

static __forceinline void AddOtherAxesA3(int& counts,unsigned char packed,int omittedAxis) {

    unsigned int code=packed>>4;

    unsigned int z=(~(code>>3))&1;

    unsigned int y=(~(code>>2))&1;

    unsigned int x=(~(code>>1))&1;

    if(omittedAxis!=0) AddA3(counts,y+2*x);

    if(omittedAxis!=1) AddA3(counts,z+2*x+4);

    if(omittedAxis!=2) AddA3(counts,z+2*y+8);

}

static __forceinline void AddEncodedAxisA3(int& counts,int packed) {
    int axis=packed&15;
    unsigned int code=packed>>4;
    int z=(~(code>>3))&1;
    int y=(~(code>>2))&1;
    int x=(~(code>>1))&1;
    if(axis==0) AddA3(counts,y+2*x);
    else if(axis==1) AddA3(counts,z+2*x+4);
    else AddA3(counts,z+2*y+8);
}
// pdb: hkpBoxBoxCollisionDetection::checkCompleteness | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, uconst + bridge(uconst|uconst) + skyrim(uconst), high
void __stdcall hkpBoxBoxCollisionDetection_checkCompleteness(RecordA3* record,int first,int second) {

    if(record->count21<3) return;

    if(record->depth20>=4) {

        record->status22=true;

        return;

    }

    int firstAxis=AxisA3(first);

    second=AxisA3(second);

    int firstCounts=0;

    int secondCounts=0;

    for(int i=0;i<record->count21;++i) {

        const EntryA3& entry=record->entries00[i];

        if(entry.kind00<=2) AddOtherAxesA3(secondCounts,entry.code01,second);

        else if(entry.kind00<=6) AddOtherAxesA3(firstCounts,entry.code01,firstAxis);

        else {

            AddEncodedAxisA3(firstCounts,entry.kind00);

            AddEncodedAxisA3(secondCounts,entry.code01);

        }

    }

    bool haveUnpaired=((firstCounts&0x555555)>0)||((secondCounts&0x555555)>0);

    record->status22=!haveUnpaired;

}

}   // namespace f3m_00a3b750

// @f3 0x00a28f90 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace na28f90 {
struct fd_set_ { unsigned int fd_count; unsigned int fd_array[64]; };
struct timeval_ { long tv_sec; long tv_usec; };
struct in_addr_ { unsigned long s_addr; };
struct sockaddr_in_ { short sin_family; unsigned short sin_port; in_addr_ sin_addr; unsigned int sin_zero[2]; };
int __stdcall FUN_00c2092e(int nfds, fd_set_* r, fd_set_* w, fd_set_* e, const timeval_* t) throw();
int __stdcall FUN_00c20928(unsigned int s, fd_set_* set) throw();
unsigned int __stdcall FUN_00c20922(unsigned int s, sockaddr_in_* addr, int* len) throw();
unsigned short __stdcall FUN_00c2091c(unsigned short v) throw();
char* __stdcall FUN_00c20916(in_addr_ a) throw();
int __stdcall FUN_00c20910(unsigned int s, int level, int name, const char* val, int len) throw();
struct ThreadMemory {
    void* FUN_008f6d30(int size, int cls) throw();
    void FUN_008f6d90(void* p, int size, int cls) throw();
};
static __forceinline ThreadMemory* Mem() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> static __forceinline void DeallocateChunk(T*& p, int n, int cls) { ThreadMemory* m = Mem(); m->FUN_008f6d90(p, n * sizeof(T), cls); }
template <class T> static __forceinline T* AllocateChunk(int n, int cls) { return (T*)Mem()->FUN_008f6d30(n * sizeof(T), cls); }
struct String {
    char* data;
    int size;
    int capAndFlags;
    __forceinline String() {
        data = AllocateChunk<char>(1, 0x17);
        size = 1;
        capAndFlags = 1;
        data[0] = 0;
    }
    __forceinline void Free() {
        if ((capAndFlags & 0x80000000) == 0)
            DeallocateChunk(data, capAndFlags & 0x3fffffff, 0x17);
    }
    void FUN_009236d0(const char* fmt, ...) throw();
};
struct Ostream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00923070(void* buf, int size) throw();
    Ostream& FUN_00943b80(const String& s) throw();
    void FUN_00943a60() throw();
};
struct Error {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
struct Buf512 { int c[128]; };
struct Socket {
    int unk00[8];
    unsigned int m_socket;
    Socket* FUN_00a28d60(unsigned int s) throw();
    static void* operator new(unsigned int size) {
        void* p = Mem()->FUN_008f6d30(size, 0x15);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    Socket* hkBsdSocket_pollForNewClient();
};
}
extern na28f90::Error* DAT_010f3364;
namespace na28f90 {
// pdb: hkBsdSocket::pollForNewClient | hkBsdSocket.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(ustr), high
Socket* Socket::hkBsdSocket_pollForNewClient()
{
    if (m_socket != -1)
    {
        fd_set_ readFds;
        readFds.fd_count = 0;
        do {
            unsigned int __i;
            for (__i = 0; __i < readFds.fd_count; __i++)
                if (readFds.fd_array[__i] == m_socket)
                    break;
            if (__i == readFds.fd_count)
                if (readFds.fd_count < 64)
                {
                    readFds.fd_array[__i] = m_socket;
                    readFds.fd_count++;
                }
        } while (0, 0);
        fd_set_ exceptFds;
        exceptFds.fd_count = 0;
        do {
            unsigned int __i;
            for (__i = 0; __i < exceptFds.fd_count; __i++)
                if (exceptFds.fd_array[__i] == m_socket)
                    break;
            if (__i == exceptFds.fd_count)
                if (exceptFds.fd_count < 64)
                {
                    exceptFds.fd_array[__i] = m_socket;
                    exceptFds.fd_count++;
                }
        } while (0, 0);
        int nfds = int(m_socket);
        nfds++;
        timeval_ t;
        t.tv_sec = 0;
        t.tv_usec = 0;
        int numHits = FUN_00c2092e(nfds, &readFds, 0, &exceptFds, &t);
        if (numHits > 0 && FUN_00c20928(m_socket, &readFds))
        {
            sockaddr_in_ from;
            int fromLen = sizeof(from);
            unsigned int s = FUN_00c20922(m_socket, &from, &fromLen);
            String msg;
            msg.FUN_009236d0("Socket got connection from [%s:%d]\n", FUN_00c20916(from.sin_addr), FUN_00c2091c(from.sin_port));
            {
                Buf512 buf;
                Ostream os;
                os.FUN_00923070(&buf, sizeof(buf));
                os.FUN_00943b80(msg);
                DAT_010f3364->message(0, -1, (const char*)buf.c, ".\\System\\Io\\Socket\\Bsd\\hkBsdSocket.cpp", 0x194);
                os.FUN_00943a60();
            }
            if (s == -1)
            {
                msg.Free();
            }
            else
            {
                int noDelay = 1;
                FUN_00c20910(s, 6, 1, (const char*)&noDelay, 4);
                Socket* result = (new Socket)->FUN_00a28d60(s);
                msg.Free();
                return result;
            }
        }
    }
    return 0;
}
}

// @f3 0x00a216a0 (community match, verified in this file)
namespace f3m_00a216a0 {
struct Context_a216a0 {
    __declspec(align(16)) int unk00;
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
};

struct Bucket_a216a0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    void FUN_00a223d0(int value);
    void FUN_00a22380(int value);
};

struct Data_a216a0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Bucket_a216a0 buckets[1];
};

struct Owner_a216a0 {
    Data_a216a0* FUN_00a214a0(Context_a216a0* context);
    void FUN_00a214b0(int index, Data_a216a0* data);
    void FUN_00a213f0(Context_a216a0* context);
    void hkJobQueue_addJob(int value, int mode, int index);
};

// pdb: hkJobQueue::addJob | hkJobQueue.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(call_seq), high
void Owner_a216a0::hkJobQueue_addJob(int value, int mode, int index)
{
    Context_a216a0 context;
    Data_a216a0* data = FUN_00a214a0(&context);
    if (mode == 0)
        data->buckets[index].FUN_00a223d0(value);
    else
        data->buckets[index].FUN_00a22380(value);
    FUN_00a214b0(index, data);
    FUN_00a213f0(&context);
}
}   // namespace f3m_00a216a0

// @f3 0x00a2f2b0 (community match, verified in this file)
#include <math.h>
struct __declspec(align(16)) GeomVec
{
    float x,y,z,w;
    GeomVec() {}
    void SetSub(const GeomVec& a,const GeomVec& b) {x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;}
    void SetCross(const GeomVec& a,const GeomVec& b) {x=a.y*b.z-a.z*b.y;y=a.z*b.x-a.x*b.z;z=a.x*b.y-a.y*b.x;}

    GeomVec operator-(const GeomVec& b) const
    {
        GeomVec r;
        r.x=x-b.x; r.y=y-b.y; r.z=z-b.z;
        return r;
    }
    GeomVec Cross(const GeomVec& b) const
    {
        GeomVec r;
        r.x=y*b.z-z*b.y;
        r.y=z*b.x-x*b.z;
        r.z=x*b.y-y*b.x;
        return r;
    }
    float Dot(const GeomVec& b) const { return z*b.z+(y*b.y+x*b.x); }
    float SquaredLength() const { double first=x*x; return (float)(first+y*y+z*z); }
    void Scale(float scale) { x*=scale; y*=scale; z*=scale; }
};
inline float GeomAbs(float value) { return (float)fabs(value); }
extern const float DAT_00de6e60;
extern const float DAT_00e34818;
extern const double DAT_00dc8088;
extern const signed char DAT_00e7c778[];
extern const float DAT_00db38b8;
static __declspec(noinline) int FUN_00a2ec80(const GeomVec& point,const GeomVec* vertices,GeomVec& dots)
{
    for(int k=0;k<3;++k)
    {
        int a=DAT_00e7c778[k+2];
        int b=DAT_00e7c778[k];
        if((&dots.x)[a]>=0.0f && (&dots.x)[b]>=0.0f)
        {
            GeomVec edgeA=vertices[a]-vertices[k];
            GeomVec edgeB=vertices[b]-vertices[k];
            GeomVec delta=point-vertices[k];
            GeomVec edgeC=vertices[3]-vertices[k];
            float test=edgeC.Dot(edgeB)*delta.Dot(edgeA)-delta.Dot(edgeB)*edgeC.Dot(edgeA);
            if(test<0.0f) (&dots.x)[b]=DAT_00db38b8;
            else (&dots.x)[a]=DAT_00db38b8;
        }
    }
    if(dots.x>0.0f)return 0;
    if(dots.y>0.0f)return 1;
    if(dots.z>0.0f)return 2;
    return -1;
}

// pdb: hkpGsk::processEdgeTriangle | hkpGsk.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: findClosestTriangle)
// pdb params: vertexA, vertexB, dimA, dimB, comingFromEdgeEdge, supportType
static __declspec(noinline) int FUN_00a2f2b0(const GeomVec& point,const GeomVec* vertices,float scale)
{
    GeomVec edge0; edge0.SetSub(vertices[2],vertices[1]);
    GeomVec edge1; edge1.SetSub(vertices[0],vertices[2]);
    GeomVec edge2; edge2.SetSub(vertices[1],vertices[0]);
    GeomVec edge3; edge3.SetSub(vertices[3],vertices[0]);
    GeomVec edge4; edge4.SetSub(vertices[3],vertices[1]);
    GeomVec edge5; edge5.SetSub(vertices[3],vertices[2]);
    GeomVec normals[3];
    normals[0].SetCross(edge0,edge4);
    normals[1].SetCross(edge1,edge5);
    normals[2].SetCross(edge2,edge3);
    GeomVec displacement; displacement.SetSub(point,vertices[3]);
    displacement.Scale(scale);
    GeomVec dots;
    float dy=displacement.y,dx=displacement.x,dz=displacement.z;
    dots.x=normals[0].x*dx+normals[0].y*dy+normals[0].z*dz;
    dots.y=normals[1].x*dx+normals[1].y*dy+normals[1].z*dz;
    dots.z=normals[2].x*dx+normals[2].y*dy+normals[2].z*dz;
    dots.w=0.0f;
    GeomVec absolute;
    absolute.x=GeomAbs(dots.x);
    absolute.y=GeomAbs(dots.y);
    absolute.z=GeomAbs(dots.z);
    GeomVec squared;
    squared.x=dots.x*absolute.x;
    squared.y=dots.y*absolute.y;
    squared.z=dots.z*absolute.z;
    GeomVec ratios;
    float length0=normals[0].SquaredLength();
    if(length0!=0.0f) ratios.x=squared.x/length0; else ratios.x=DAT_00de6e60;
    float length1=normals[1].SquaredLength();
    if(length1!=0.0f) ratios.y=squared.y/length1; else ratios.y=DAT_00de6e60;
    float length2=normals[2].SquaredLength();
    if(length2!=0.0f) ratios.z=squared.z/length2; else ratios.z=DAT_00de6e60;
    int index=1;
    if(ratios.x>ratios.y)
    {
        float temp=ratios.x;ratios.x=ratios.y;ratios.y=temp;index=0;
    }
    if(ratios.z<ratios.y)
    {
        float temp=ratios.y;ratios.y=ratios.z;ratios.z=temp;
        if(ratios.x>ratios.y)
        {float temp=ratios.x;ratios.x=ratios.y;ratios.y=temp;}
    }
    else index=2;
    if(ratios.z<DAT_00e34818) return -1;
    if(ratios.y*DAT_00dc8088<ratios.z) return index;
    GeomVec fallback=dots;
    return FUN_00a2ec80(point,vertices,fallback);
}
extern GeomVec* volatile geomPoint;
extern GeomVec* volatile geomVertices;
extern float volatile geomScale;
extern int volatile geomResult;
void geomCaller() { geomResult=FUN_00a2f2b0(*geomPoint,geomVertices,geomScale); }

// @f3 0x00a235a0 (community match, verified in this file)
extern unsigned long hkMonitorStream_tlsIndex;
namespace f3m_00a235a0 {
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

typedef float hkReal;
typedef unsigned int hkUint32;

union hkQuadReal
{
    struct
    {
        __declspec(align(16)) hkReal x;
        hkReal y;
        hkReal z;
        hkReal w;
    } f;
    struct
    {
        __declspec(align(16)) hkUint32 x;
        hkUint32 y;
        hkUint32 z;
        hkUint32 w;
    } u;
};

class hkVector4
{
  public:
    hkQuadReal m_quad;
    void setZero4()
    {
        m_quad.u.x = 0;
        m_quad.u.y = 0;
        m_quad.u.z = 0;
        m_quad.u.w = 0;
    }
};


class hkMonitorStream
{
  public:
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
        __forceinline void setTime() { hkUint32 ticks; __asm { rdtsc
            mov dword ptr[ticks], eax } m_time0 = ticks; }
    };
    struct TimerBeginListCommand : public TimerCommand
    {
        const char* m_nameOfFirstSplit;
    };

    static hkMonitorStream& getInstance()
    {
        return *static_cast<hkMonitorStream*>(TlsGetValue(hkMonitorStream_tlsIndex));
    }
    bool memoryAvailable() const { return m_end < m_capacityMinus16; }
    char* getEnd() const { return m_end; }
    void setEnd(char* p) { m_end = p; }
};

struct hkpConstraintQueryIn
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4;
    int m_solverInfo2b8;
};

struct hkpWorldA235
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int m_solverInfo1a0;
    int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4;
    int m_dynamicsStepInfo2b8;
};

struct hkpSimulationIslandA235
{
    hkpWorldA235* m_world;
    int unk04;
    int m_storageIndex;
};

struct hkpBuildJacobianTaskA235
{
    int unk00; int unk04;
    int m_accumulators08;
    int m_schemas0c;
    hkVector4* m_jacobians10;
    int unk14;
    int m_jacobiansSize18;
};

struct hkpSolverJobA235
{
    int unk00; int unk04; int unk08; int unk0c;
    int m_jobIndex10;
    int m_stepInfo14;
    int m_numTasks18;
    hkpBuildJacobianTaskA235* m_task1c;
};

struct hkpSimulationA235
{
    void FUN_00a21830(int storageIndex, hkpSolverJobA235* a, hkpSolverJobA235* b, int c, int d);
};

void __cdecl FUN_00a1b9f0(int* solverInfo, int jobIndex, int numTasks, int schemas, int accumulators, hkVector4* jacobians);

// pdb: hkCpuSolveConstraintBatchJob | hkpCpuSolveConstraintsJobs.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void __cdecl hkCpuSolveConstraintBatchJob(hkpSimulationIslandA235* island, hkpSimulationA235* simulation, hkpSolverJobA235* job)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "LtIntegrate";
            h->m_nameOfFirstSplit = "StSolve";
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }

    hkpBuildJacobianTaskA235* task = job->m_task1c;
    int accumulators = task->m_accumulators08;
    int schemas = task->m_schemas0c;
    hkVector4* jacobians = task->m_jacobians10;
    job->m_stepInfo14 = island->m_world->m_dynamicsStepInfo2b8;

    if (job->m_jobIndex10 == 0)
    {
        hkVector4 zero;
        zero.setZero4();
        unsigned int blocks = ((unsigned int)task->m_jacobiansSize18 + 15) & 0xfffffff0u;
        _ReadWriteBarrier();
        int count = int(blocks / 16u);
        if (count > 0)
        {
            int* p = reinterpret_cast<int*>(jacobians) + 2;
            do
            {
                p[-2] = 0;
                p[-1] = 0;
                p[0] = 0;
                p[1] = 0;
                p += 4;
            } while (--count != 0);
        }
    }

    FUN_00a1b9f0(&island->m_world->m_solverInfo1a0, job->m_jobIndex10, job->m_numTasks18, schemas, accumulators, jacobians);

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "lt";
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }

    simulation->FUN_00a21830(island->m_storageIndex, job, job, 0, 0);
}
}   // namespace f3m_00a235a0

// @f3 0x00a21500 (community match, verified in this file)
namespace f3m_00a21500 {
struct FUN_00a21500_Sub {
    int unk00;
    void FUN_00a222a0(void* p);
};

struct FUN_00a21500_Y {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00a21500_Sub sub14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    FUN_00a21500_Sub sub28;
};

__declspec(align(16)) struct FUN_00a21500_Local {
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
};

struct FUN_00a21500_cls {
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
    FUN_00a21500_Y* m_pY;   // +0x30
    void FUN_00a214a0(FUN_00a21500_Local* out);
    void FUN_00a213f0(FUN_00a21500_Local* in);
    void FUN_00a21500(void* p);
};

void FUN_00a21500_cls::FUN_00a21500(void* p)
{
    FUN_00a21500_Local local;
    this->FUN_00a214a0(&local);
    this->m_pY->sub14.FUN_00a222a0(p);
    this->m_pY->sub28.FUN_00a222a0(p);
    this->FUN_00a213f0(&local);
}
}   // namespace f3m_00a21500

// @f3 0x00a2ec10 (community match, verified in this file)
namespace f3m_00a2ec10 {
// 0x00a2ec10, 98 bytes, byte-exact under /MT /O2 /GS /EHsc /Gy (NOT under the
// pack's listed /MT /Od /Oy- /GS /EHsc /Gy): f3check MATCH, 98 = 98, no
// relocation diffs. pack_problem filed (awaiting triage) with
// compile_flags=[/MT,/O2,/GS,/EHsc,/Gy] and checkpoint chk_42b8fd21294a4c928b03,
// which the build host compiles.

// 16-byte, 16-byte-aligned vector: the align(16) is what produces the
// "and esp, -16" realigned frame in the original.
struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

// Computes the component-wise difference of two vectors into a local,
// copies *src (all four floats) to *dst, and returns the dot product of
// the copied .xyz with the difference .xyz.
static __declspec(noinline) float FUN_00a2ec10(Vec4* a, Vec4* b, Vec4* dst, Vec4* src)
{
    Vec4 d;

    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;

    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;

    return dst->x * d.x + dst->y * d.y + dst->z * d.z;
}

// In-TU caller: keeps the static callee alive and gives c2 the call site
// that this private register convention is negotiated for.
Vec4* volatile g_a;
Vec4* volatile g_b;
Vec4* volatile g_dst;
Vec4* volatile g_src;
volatile float g_sink;

void probe_caller_00a2ec10(void)
{
    g_sink = FUN_00a2ec10(g_a, g_b, g_dst, g_src);
}
}   // namespace f3m_00a2ec10

// @f3 0x00a30190 (community match, verified in this file)
#include <math.h>
namespace f3m_00a30190 {

class PaddedInt
{
public:
    __forceinline PaddedInt() {}
    __forceinline PaddedInt(int v) : m_val(v) {}
    __forceinline void operator=(int v) { m_val = v; }
    __forceinline int get() const { return m_val; }
    __forceinline operator int() const { return get(); }
private:
    int m_val;
};

inline float mathSqrt(float r) { return sqrtf(r); }
inline float mathSqrtInverse(float r) { return 1.0f / mathSqrt(r); }
inline int mathIsNegative(float r0) { return (r0 < 0) ? 8 : 0; }

class Vec4
{
public:
    __forceinline Vec4() {}
    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void setSub4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline void mul4(float rs)
    {
        float s = float(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline float dot3(const Vec4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline void fastNormalize3NonZero()
    {
        float l2 = (x * x) + (y * y) + (z * z);
        l2 = mathSqrtInverse(l2);
        this->mul4(l2);
    }
private:
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

enum SupportMode
{
    SUPPORT_MODE_A = 8
};

static __declspec(noinline) void FUN_00a30190(Vec4* __restrict vertexA, Vec4* __restrict vertexB, PaddedInt& dimB, Vec4& support, SupportMode stype)
{
    Vec4 edge; edge.setSub4(vertexB[1], vertexB[0]);
    Vec4 a; a.setSub4(vertexB[1], vertexA[0]);
    Vec4 b; b.setSub4(vertexB[0], vertexA[0]);
    float adot = a.dot3(edge);
    float bdot = b.dot3(edge);
    int aneg = mathIsNegative(adot);
    int bneg = mathIsNegative(bdot);
    if (aneg != bneg)
    {
        edge.fastNormalize3NonZero();
        Vec4 c; c.setCross(a, b);
        if (stype == SUPPORT_MODE_A)
        {
            support.setCross(edge, c);
        }
        else
        {
            support.setCross(c, edge);
        }
    }
    else
    {
        if (aneg != 0)
        {
            vertexB[0] = vertexB[1];
            vertexB[4] = vertexB[5];
        }
        dimB = dimB - 1;
        if (stype == SUPPORT_MODE_A)
        {
            support.setSub4(vertexA[0], vertexB[0]);
        }
        else
        {
            support.setSub4(vertexB[0], vertexA[0]);
        }
    }
}

Vec4* volatile g_va;
Vec4* volatile g_vb;
PaddedInt* volatile g_dimB;
Vec4* volatile g_sup;
volatile int g_stype;

void caller_00a30190()
{
    FUN_00a30190(g_va, g_vb, *g_dimB, *g_sup, (SupportMode)g_stype);
}
}   // namespace f3m_00a30190

// @f3 0x00a2f720 (community match, verified in this file)
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

static __forceinline float mathSqrt(float r)
{
    return (float)sqrt(r);
}

static __forceinline float mathSqrtInverse(float r)
{
    return 1.0f / mathSqrt(r);
}

static inline int mathIsNegative(float r0)
{
    return r0 < 0.0f;
}

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;

    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void setAll(float v)
    {
        x = v;
        y = v;
        z = v;
        w = v;
    }

    __forceinline void setAdd4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setSub4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void setMul4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x * v1.x;
        y = v0.y * v1.y;
        z = v0.z * v1.z;
        w = v0.w * v1.w;
    }

    __forceinline void mul4(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    __forceinline void setNeg4(const Vec4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }

    __forceinline void setW(const Vec4& v)
    {
        w = v.w;
    }

    __forceinline float dot3(const Vec4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

    __forceinline float horizontalAdd3() const
    {
        return (x + y) + z;
    }

    __forceinline float lengthSquared3() const
    {
        return this->dot3(*this);
    }

    __forceinline float lengthInverse3() const
    {
        float l2 = this->lengthSquared3();
        return l2 ? mathSqrtInverse(l2) : 0;
    }

    __forceinline void normalize3()
    {
        this->mul4(this->lengthInverse3());
    }

    __forceinline void setCross(const Vec4& v0, const Vec4& v1)
    {
        float nx = v0.y * v1.z - v0.z * v1.y;
        float ny = v0.z * v1.x - v0.x * v1.z;
        float nz = v0.x * v1.y - v0.y * v1.x;
        x = nx;
        y = ny;
        z = nz;
        w = 0.0f;
    }
};

struct LineSegResult
{
    Vec4 m_closestPointA;
    Vec4 m_closestAminusClosestB;
    float m_distanceSquared;
};

int __cdecl FUN_0096f780(const Vec4& A, const Vec4& dA, const Vec4& B, const Vec4& dB, LineSegResult& result);

static __declspec(noinline) void FUN_00a2f720(Vec4* vertexA, Vec4* vertexB, const Vec4& masterNormal, Vec4& pointAOut, Vec4& support)
{
    Vec4 edgeA; edgeA.setSub4(vertexA[1], vertexA[0]);
    Vec4 edgeB; edgeB.setSub4(vertexB[1], vertexB[0]);

    LineSegResult lineLineResult;
    FUN_0096f780(vertexA[0], edgeA, vertexB[0], edgeB, lineLineResult);

    support.setCross(edgeA, edgeB);

    float sumEdgeLenSqrd;
    {
        Vec4 edgeA2; edgeA2.setMul4(edgeA, edgeA);
        Vec4 edgeB2; edgeB2.setMul4(edgeB, edgeB);
        Vec4 sum; sum.setAdd4(edgeA2, edgeB2);
        sumEdgeLenSqrd = sum.horizontalAdd3();
    }

    float supportLenSqrd = support.lengthSquared3();
    if (supportLenSqrd * 0.001f > sumEdgeLenSqrd * sumEdgeLenSqrd)
    {
        if (mathIsNegative(support.dot3(masterNormal)))
        {
            support.setNeg4(support);
        }
        support.normalize3();
    }
    else
    {
        support = masterNormal;
    }

    Vec4 diff; diff.setSub4(vertexA[0], vertexB[0]);
    float dist = diff.dot3(support);
    pointAOut = lineLineResult.m_closestPointA;
    Vec4 dist4; dist4.setAll(dist);
    support.setW(dist4);
}

extern Vec4* volatile g_va;
extern Vec4* volatile g_vb;
extern Vec4* volatile g_mn;
extern Vec4* volatile g_pa;
extern Vec4* volatile g_sup;

void caller_stub()
{
    FUN_00a2f720(g_va, g_vb, *g_mn, *g_pa, *g_sup);
}

// @f3 0x00a2ee70 (community match, verified in this file)
namespace f3m_00a2ee70 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef const hkSimdReal& hkSimdRealParameter;

struct hkVector4Comparison
{
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };
    int m_mask;
    __forceinline int getMask() const { return m_mask; }
};

struct PlainVector
{
    float x, y, z, w;
};

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        x = v1.y * v2.z - v1.z * v2.y;
        y = v1.z * v2.x - v1.x * v2.z;
        z = v1.x * v2.y - v1.y * v2.x;
        w = 0.0f;
    }
    __forceinline hkSimdReal dot3(const hkVector4& v) const { double a = x * v.x; return a + y * v.y + z * v.z; }
    __forceinline void compareLessThanZero4(hkVector4Comparison& result) const
    {
        result.m_mask = ((x < 0.0f) ? hkVector4Comparison::MASK_X : 0) | ((y < 0.0f) ? hkVector4Comparison::MASK_Y : 0) |
                        ((z < 0.0f) ? hkVector4Comparison::MASK_Z : 0) | ((w < 0.0f) ? hkVector4Comparison::MASK_W : 0);
    }
};

__forceinline void hkVector4Util_dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1,
                                           const hkVector4& b1, const hkVector4& a2, const hkVector4& b2,
                                           hkVector4& dotsOut)
{
    dotsOut.set(a0.dot3(b0), a1.dot3(b1), a2.dot3(b2), 0.0f);
}

struct Simplex
{
    int countA, countB, unk08, unk0c, unk10, status, unk18, unk1c;
    hkVector4 a[4];
    hkVector4 unk60, unk70, unk80, unk90;
    hkVector4 verticesB[8];
    hkVector4 result, axis, unk140, unk150, weights;
    int FUN_00a2ee70(const hkVector4* point, hkVector4* vertices, int orient);
};

static __forceinline void swapFloat(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

static __forceinline hkVector4 copyVector(const PlainVector& p)
{
    hkVector4 v;
    reinterpret_cast<PlainVector&>(v) = p;
    return v;
}

static __forceinline hkVector4 triangleSideTests(const hkVector4* point, hkVector4* vertices, hkVector4& normal,
                                                 hkVector4& weights)
{
    hkVector4 edgeA;
    edgeA.setSub4(vertices[2], vertices[1]);
    hkVector4 edgeB;
    edgeB.setSub4(vertices[0], vertices[2]);
    hkVector4 edgeC;
    edgeC.setSub4(vertices[1], vertices[0]);
    normal.setCross(edgeA, edgeB);
    hkVector4 pa;
    pa.setSub4(*point, vertices[1]);
    hkVector4 pb;
    pb.setSub4(*point, vertices[2]);
    hkVector4 pc;
    pc.setSub4(*point, vertices[0]);
    hkVector4 ca;
    ca.setCross(pa, edgeA);
    hkVector4 cb;
    cb.setCross(pb, edgeB);
    hkVector4 cc;
    cc.setCross(pc, edgeC);
    hkVector4 dots;
    hkVector4Util_dot3_3vs3(ca, normal, cb, normal, cc, normal, dots);
    weights = dots;
    return dots;
}

// Barycentric side tests of a point against a triangle; optionally flips the orientation and swaps two vertices
// when the simplex point lies behind the face. FPU build of FNV Simplex::FUN_00da8500 (hkpgsk.cpp).
// pdb: findClosestTriangle | hkpGsk.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkpGsk::checkTriangleBoundaries)
int Simplex::FUN_00a2ee70(const hkVector4* point, hkVector4* vertices, int orient)
{
    hkVector4 normal;
    hkVector4 tested = triangleSideTests(point, vertices, normal, weights);
    hkVector4Comparison cmp;
    tested.compareLessThanZero4(cmp);
    int bits = cmp.getMask() & hkVector4Comparison::MASK_XYZ;
    if (orient)
    {
        result = normal;
        if (bits == hkVector4Comparison::MASK_XYZ)
        {
            hkVector4 d;
            d.setSub4(a[0], verticesB[0]);
            if (normal.dot3(d) < 0.0f)
            {
                result.setNeg4(normal);
                hkVector4 tmp = copyVector(reinterpret_cast<const PlainVector&>(vertices[0]));
                vertices[0] = vertices[1];
                vertices[1] = tmp;
                tmp = copyVector(reinterpret_cast<const PlainVector&>(vertices[4]));
                vertices[4] = vertices[5];
                vertices[5] = tmp;
                swapFloat(weights.x, weights.y);
                status = 1;
            }
        }
    }
    return bits;
}
}   // namespace f3m_00a2ee70

// @f3 0x00a297f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a297f0 {

extern void* (__stdcall* DAT_00d9b080)(unsigned long);
namespace f3m_00a297f0 {
struct ThreadMemory { void* FUN_008f6f60(int size, int cls) throw(); };
struct Elem { int f0; int f4; int f8; int fC; int f10; int f14; };
struct Key { int k; int a, b, c, d; };
class FUN_00922cb0 {
public:
    int* data;
    unsigned int unk04;
    int last;
    FUN_00922cb0() throw();
    ~FUN_00922cb0() throw();
    void FUN_00922710(int key, int value) throw();
    int FUN_00922790(int key) throw();
    int FUN_00922820(int key, int* out) throw();
    __forceinline bool Get(int key, int& out) { return FUN_00922820(key, &out) != 0; }
    __forceinline bool Has(int key) { return FUN_00922790(key) <= last; }
};
struct Other { void FUN_00a29760(int v, int* slot) throw(); };
void __cdecl FUN_009234e0(void* dst, const void* src, int size) throw();
int __cdecl FUN_00923640(int v) throw();
struct Cloner {
    int FUN_00a29500(int key, int flag) throw();
    Elem* FUN_00a297f0(Elem* src, int count, Key* keys, Key* repl, int nkeys, FUN_00922cb0* done, Other* other) throw();
};
Elem* Cloner::FUN_00a297f0(Elem* src, int count, Key* keys, Key* repl, int nkeys, FUN_00922cb0* done, Other* other) throw()
{
    if (!src) return 0;
    ThreadMemory* m = (ThreadMemory*)DAT_00d9b080(DAT_010f3170);
    Elem* out = (Elem*)m->FUN_008f6f60(count * sizeof(Elem), 6);
    FUN_009234e0(out, src, count * sizeof(Elem));
    FUN_00922cb0 local;
    Elem* e = out;
    for (int n = 0; n < count; n++, e++) {
        e->f0 = FUN_00923640(e->f0);
        e->f14 = 0;
        if (e->f4) {
            other->FUN_00a29760(e->f4, &e->f4);
        } else if (e->f8) {
            for (int i = 0; i < nkeys; i++) {
                if (e->f8 == (int)&keys[i]) {
                    e->f8 = (int)&repl[i];
                    done->FUN_00922710(e->f8, 0);
                    break;
                }
            }
            if (!done->Has(e->f8)) {
                int v;
                if (local.Has(e->f8)) {
                    int got;
                    v = 0;
                    if (!local.Get(e->f8, got)) v = got;
                } else {
                    v = FUN_00a29500(e->f8, 1);
                    done->FUN_00922710(v, 1);
                    local.FUN_00922710(e->f8, v);
                }
                e->f8 = v;
            }
        }
    }
    return out;
}
}
}   // namespace f3m_00a297f0

// @f3 0x00a2b780 (community match, verified in this file)
namespace f3m_00a2b780 {
struct Mat481 {
    float unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20;
    Mat481& FUN_00a2b780(const Mat481& src);
};
Mat481& Mat481::FUN_00a2b780(const Mat481& src) {
    unk00 = src.unk00;
    unk04 = src.unk04;
    unk08 = src.unk08;
    unk0C = src.unk0C;
    unk10 = src.unk10;
    unk14 = src.unk14;
    unk18 = src.unk18;
    unk1C = src.unk1C;
    unk20 = src.unk20;
    return *this;
}
}   // namespace f3m_00a2b780

// @f3 0x00a25be0 (community match, verified in this file)
namespace f3m_00a25be0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);

struct Cs00a25be0 { int unk00, unk04, unk08, unk0C, unk10, unk14; int unk18; int unk1C; };
struct Lock00a25be0 {
    int unk00, unk04, unk08, unk0C;
    Cs00a25be0* unk10;
    void FUN_00a25be0();
};

// pdb: hkpBroadPhase::unlockImplementation | hkpBroadPhase.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkpBroadPhase::lockImplementation)
void Lock00a25be0::FUN_00a25be0()
{
    Cs00a25be0* cs = unk10;
    cs->unk18 = -1;
    cs->unk1C = -1;
    LeaveCriticalSection(cs);
}
}   // namespace f3m_00a25be0

// @f3 0x00a214b0 (community match, verified in this file)
namespace f3m_00a214b0 {
struct Data_a216a0;
void __cdecl FUN_009b4a80(void* ptr, int value);

class Owner_a216a0 {
public:
    void FUN_00a214b0(int index, Data_a216a0* data);
};

struct Data_a216a0 {
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
};

// pdb: hkSemaphore::operator new | hkJobQueue.obj | fnv360_0822_debug, objrun_open, low
// pdb params: nbytes
void __thiscall Owner_a216a0::FUN_00a214b0(int index, Data_a216a0* data) {
    if (data->unk38 + data->unk24 != 0) {
        if (data->unk0c != 0) {
            data->unk0c = data->unk0c - 1;
            FUN_009b4a80(*(void**)((char*)this + 0x4c), 1);
            return;
        }
        if (data->unk04 != 0) {
            data->unk04 = data->unk04 - 1;
            FUN_009b4a80(*(void**)((char*)this + 0x50), 1);
        }
    }
}
}   // namespace f3m_00a214b0

// @f3 0x00a25680 (community match, verified in this file)
namespace f3m_00a25680 {
namespace f3m_00a25680 {
struct __declspec(align(16)) Event
{
    short m_type;
    short m_s02;
    int m_i04;
    int m_i08;
    int m_i0c;
};
struct Source
{
    short m_s00;
    short m_s02;
    int m_i04;
    int m_i08;
};
struct Queue
{
    void FUN_00a223d0(const Event* e);
};
struct Target
{
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    Queue m_queue;
};
struct Owner
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    char unk1c;
    bool m_bEnabled;
};
}

// pdb: spawnSplitSimulationIslandJob | hkpDynamicsJobQueueUtils.obj | fnv360_0822_retail, objopen_prop, medium
static __declspec(noinline) void FUN_00a25680(f3m_00a25680::Owner* owner, const f3m_00a25680::Source* src, f3m_00a25680::Target* target)
{
    if (owner->m_bEnabled)
    {
        f3m_00a25680::Event e;
        e.m_type = 5;
        e.m_s02 = src->m_s02;
        e.m_i04 = src->m_i04;
        e.m_i08 = src->m_i08;
        target->m_queue.FUN_00a223d0(&e);
    }
}

f3m_00a25680::Owner* volatile g_owner_00a25680;
const f3m_00a25680::Source* volatile g_src_00a25680;
f3m_00a25680::Target* volatile g_target_00a25680;
void caller_of_FUN_00a25680()
{
    FUN_00a25680(g_owner_00a25680, g_src_00a25680, g_target_00a25680);
}
}   // namespace f3m_00a25680

// @f3 0x00a36870 (community match, verified in this file)
namespace f3m_00a36870 {
namespace f3m_00a36870 {
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    Vec4() {}
    Vec4(float a,float b,float c,float d) : x(a),y(b),z(c),w(d) {}
    Vec4 operator-(const Vec4& other) const { return Vec4(x-other.x,y-other.y,z-other.z,w-other.w); }
    float SqrLength() const { return x*x+y*y+z*z; }
    Vec4& operator=(const Vec4& other) { x=other.x; y=other.y; z=other.z; w=other.w; return *this; }
};
struct Owner { Vec4 points[16]; Vec4 normal; float unk110,unk114,unk118,limit; };
struct Edge { unsigned int unk00; unsigned char first, second; };
struct Result { Vec4 start, delta, normal; };
static __declspec(noinline) int FUN_00a36870(Owner* owner, const Edge* edge, Result* result) {
    const Vec4& first = *(const Vec4*)((const char*)owner + edge->first);
    const Vec4& second = *(const Vec4*)((const char*)owner + edge->second);
    Vec4 delta = first - second;
    if (delta.SqrLength() > owner->limit) return 1;
    result->delta = delta;
    result->normal = owner->normal;
    result->start = first;
    return 0;
}
Owner* volatile callerOwner;
const Edge* volatile callerEdge;
Result* volatile callerResult;
volatile int callerReturn;
void caller_of_FUN_00a36870() { callerReturn = FUN_00a36870(callerOwner, callerEdge, callerResult); }
}
}   // namespace f3m_00a36870

// @f3 0x00a25bd0 (community match, verified in this file)
namespace f3m_00a25bd0 {
struct Sub { void FUN_00908a00(); };
struct Obj {
    char pad[0x10];
    Sub* sub;
    void FUN_00a25bd0();
};
// pdb: hkpBroadPhase::lockImplementation | hkpBroadPhase.obj | fnv360_0822_retail, call_gap_sim, low
void Obj::FUN_00a25bd0()
{
    sub->FUN_00908a00();
}
}   // namespace f3m_00a25bd0

// @f3 0x00a292c0 (community match, verified in this file)
namespace f3m_00a292c0 {
struct Obj {
    int pad[7];
    int unk1c;
    void FUN_00a292c0(int arg);
    void FUN_00a7df80(int arg);
};
// pdb: `anonymous namespace'::ClassVersion::operator== | hkVersionPatchManager.obj | fnv360_0822_debug, objrun_open, low
// pdb params: v
void Obj::FUN_00a292c0(int arg)
{
    int saved = unk1c;
    unk1c = 0;
    FUN_00a7df80(arg);
    unk1c = saved;
}
}   // namespace f3m_00a292c0

// @f3 0x00a28420 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a28420 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);


struct SourceA28420 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct TlsObjectA28420 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18(int value);

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
};

// pdb: hkpDefaultToiResourceMgr::endToiAndFreeResources | hkpDefaultToiResourceMgr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_sim), high
void __stdcall hkpDefaultToiResourceMgr_endToiAndFreeResources(unsigned int param1, unsigned int param2, SourceA28420* source) {
    int value = source->unk18;
    TlsObjectA28420* object =
        (TlsObjectA28420*)TlsGetValue(DAT_010f3170);

    object->unk20 = value;
    if (value == object->unk28)
        object->vf18(value);
}
}   // namespace f3m_00a28420

// @f3 0x00a2b7c0 (community match, verified in this file)
namespace f3m_00a2b7c0 {
struct Transform { float m[12]; void hkTransform_setInverse(const Transform& other); };
struct Info {
    int a, b, c, d;
    Transform transform;
    int unk40, unk44, unk48, unk4c, unk50;
    int e;
    int unk58, unk5c;
    float x, y, z, w;
};
// pdb: hkAgent1nMachine_flipInput | hkpAgent1nMachine.obj | tesv_win, call_gap, low
static __declspec(noinline) void FUN_00a2b7c0(const Info* in, Info* out)
{
    out->a = in->b;
    out->b = in->a;
    out->c = in->c;
    out->e = in->e;
    out->d = in->d;
    out->x = -in->x;
    out->y = -in->y;
    out->z = -in->z;
    out->w = in->w;
    out->transform.hkTransform_setInverse(in->transform);
}
extern Info* volatile g_in;
extern Info* volatile g_out;
void caller_of_FUN_00a2b7c0() { FUN_00a2b7c0(g_in, g_out); }
}

// @f3 0x00a28370 (community match, verified in this file)
namespace f3m_00a28370 {
struct StandIn_a28370 {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;

    StandIn_a28370* FUN_00a28370();
};

// pdb: hkpDefaultToiResourceMgr::hkpDefaultToiResourceMgr | hkpDefaultToiResourceMgr.obj | fnv360_0822_retail, uvref, high
StandIn_a28370* StandIn_a28370::FUN_00a28370() {
    unk06 = 1;
    unk00 = 0xe85764;
    unk08 = 0x20000;
    return this;
}
}   // namespace f3m_00a28370

// @f3 0x00a28450 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a28450 {
namespace f3m_00a28450 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a28450Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a28450 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a28300();
    D00a28450* FUN_00a28450(unsigned int flags);
};
// pdb: hkpDefaultToiResourceMgr::`scalar deleting destructor' | hkpDefaultToiResourceMgr.obj | fnv360_0721_beta, vtable, high
D00a28450* D00a28450::FUN_00a28450(unsigned int flags)
{
    FUN_00a28300();
    if (flags & 1) {
        D00a28450Heap* heap = (D00a28450Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}
}   // namespace f3m_00a28450

// @f3 0x00a22270 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a22270 {
namespace f3m_00a22270 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A2227Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct A2227Block { int unk[32]; };
inline void A2227Free(A2227Block* p, int n)
{
    A2227Heap* heap = (A2227Heap*)DAT_00d9b080(DAT_010f3170);
    heap->FUN_008f6d90(p, n * sizeof(A2227Block), 0x17);
}
struct A2227Storage {
    A2227Block* data;
    int capacity;
    void FUN_00a22270();
};
// pdb: hkJobQueueHwSetup::hkJobQueueHwSetup | hkJobQueue.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkQueue<struct hkJobQueue::JobQueueEntry>::~hkQueue<struct hkJobQueue::JobQueueEntry>)
void A2227Storage::FUN_00a22270()
{
    if (capacity)
        A2227Free(data, capacity);
}
}
}   // namespace f3m_00a22270

// @f3 0x00a29170 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a29170 {
namespace f3m_00a29170 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a29170Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a29170 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a28d40();
    D00a29170* FUN_00a29170(unsigned int flags);
};
// pdb: hkBsdSocket::`scalar deleting destructor' | hkBsdSocket.obj | tesv_win, vtable_prefix, medium
D00a29170* D00a29170::FUN_00a29170(unsigned int flags)
{
    FUN_00a28d40();
    if (flags & 1) {
        D00a29170Heap* heap = (D00a29170Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}
}   // namespace f3m_00a29170

// @f3 0x00a2a280 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a2a280 {
namespace f3m_00a2a280 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a2a280Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a2a280 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a2a060();
    D00a2a280* FUN_00a2a280(unsigned int flags);
};
// pdb: hkVersionPatchManager::applyPatchesDebug | hkVersionPatchManager.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: StructArrayImplementation::`vector deleting destructor')
// pdb params: worldToUpdate
D00a2a280* D00a2a280::FUN_00a2a280(unsigned int flags)
{
    FUN_00a2a060();
    if (flags & 1) {
        D00a2a280Heap* heap = (D00a2a280Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}
}   // namespace f3m_00a2a280

// @f3 0x00a35760 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a35760 {
namespace f3m_00a35760 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);   // TlsGetValue
struct ThreadMemory { void* FUN_008f6d30(int size, int tag) throw(); };
struct Pooled {
    static void* operator new(unsigned int size)
    {
        ThreadMemory* memory = (ThreadMemory*)DAT_00d9b080(DAT_010f3170);
        void* p = memory->FUN_008f6d30(size, 0x1f);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void*) {}
};
class FUN_00a35730 : public Pooled {
public:
    FUN_00a35730(void* a, void* b, void* c) throw();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
class FUN_00a34900 : public Pooled {
public:
    FUN_00a34900(void* a, void* b, void* c) throw();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
}

// pdb: hkpGskfAgent::createGskfAgent | hkpGskfAgent.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap), high
void* __cdecl hkpGskfAgent_createGskfAgent(void* a, void* b, void* unused, void* c)
{
    if (c)
        return new f3m_00a35760::FUN_00a35730(a, b, c);
    return new f3m_00a35760::FUN_00a34900(a, b, 0);
}
}   // namespace f3m_00a35760

// @f3 0x00a214a0 (community match, verified in this file)
namespace f3m_00a214a0 {
namespace f3m_00a214a0 {
struct Data;
struct Context;
struct LockedData {
    int cs[6];
    int owner, recursion;
    int unk20, unk24, unk28, unk2c;
    Data* data;
    void FUN_00908a00();
    Data* FUN_00a214a0(Context* context);
};
// pdb: hkJobQueue::lockQueue | hkJobQueue.obj | tesv_win, objopen_prop, low
Data* LockedData::FUN_00a214a0(Context*)
{
    FUN_00908a00();
    return data;
}
}
}   // namespace f3m_00a214a0

// @f3 0x00a29c30 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a29c30 {
namespace f3m_00a29c30 {
extern char DAT_0116a994;   // the hkClass this version patch reads
struct ArrayRef { void* data; int count; };
struct ClassAccessor {
    void* object;
    void* klass;
    void FUN_0093d7d0(void* obj, void* cls);   // constructor
};
struct MemberAccessor {
    void* accessor;
    void* member;
    void FUN_0093d600(ClassAccessor* owner, const char* name);   // constructor
    ArrayRef* FUN_0093d760(int index);   // as array
    void** FUN_0093d670(int index);      // as pointer
    void** FUN_0093d680(int index);      // as c-string
};
struct ThreadMemory { void FUN_008f6f90(void* p); };   // deallocate
inline ThreadMemory* Memory() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
struct Patcher {
    void FUN_00a29670(void* enums, int count);
    void FUN_00a29b90(void* members, int count, void* context);
    void FUN_00a29c30(void* object, void* context);
};
}

void f3m_00a29c30::Patcher::FUN_00a29c30(void* object, void* context)
{
    struct { ClassAccessor klass; MemberAccessor member; } l;
    ClassAccessor& klass = l.klass;
    MemberAccessor& member = l.member;
    klass.FUN_0093d7d0(object, &DAT_0116a994);
    member.FUN_0093d600(&klass, "declaredEnums");
    ArrayRef* enums = member.FUN_0093d760(0);
    FUN_00a29670(enums->data, enums->count);
    member.FUN_0093d600(&klass, "declaredMembers");
    ArrayRef* members = member.FUN_0093d760(0);
    FUN_00a29b90(members->data, members->count, context);
    member.FUN_0093d600(&klass, "defaults");
    void* defaults = *member.FUN_0093d670(0);
    ThreadMemory* m = Memory();
    m->FUN_008f6f90(defaults);
    member.FUN_0093d600(&klass, "name");
    void* name = *member.FUN_0093d680(0);
    m = Memory();
    m->FUN_008f6f90(name);
    m = Memory();
    m->FUN_008f6f90(object);
}
}   // namespace f3m_00a29c30

// @f3 0x00a29360 (community match, verified in this file)
namespace f3m_00a29360 {
namespace f3m_00a29360 {
struct A2936Sub { void FUN_009b10f0(int a, int b); };
struct A2936Owner {
    int unk00[11];
    A2936Sub unk2c;
    void FUN_00a29360(int value);
};
// pdb: hkTypeInfoRegistry::getTypeInfo | hkBuiltinTypeRegistry.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: typeName
void A2936Owner::FUN_00a29360(int value)
{
    unk2c.FUN_009b10f0(value, value);
}
}
}   // namespace f3m_00a29360

// @f3 0x00a213f0 (community match, verified in this file)
namespace f3m_00a213f0 {
namespace f3m_00a213f0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* section);
struct A213Lock {
    int section[6];
    int owner;
    int count;
    void FUN_00a213f0(int unused);
};
void A213Lock::FUN_00a213f0(int)
{
    owner = -1;
    count = -1;
    LeaveCriticalSection(this);
}
}
}   // namespace f3m_00a213f0

// @f3 0x00a348a0 (community match, verified in this file)
namespace f3m_00a348a0 {
extern float DAT_00db38b8;
struct A348Obj {
    int unk00[6];
    float unk18;
    int unk1c;
    float unk20, unk24, unk28, unk2c;
    void hkpGskBaseAgent_invalidateTim(int unused);
};
// pdb: hkpGskBaseAgent::invalidateTim | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void A348Obj::hkpGskBaseAgent_invalidateTim(int)
{
    unk20 = unk24 = unk28 = unk2c = 0.0f;
    unk18 = DAT_00db38b8;
}
}

// @f3 0x00a22250 (community match, verified in this file)
namespace f3m_00a22250 {
namespace f3m_00a22250 {
struct A2225Obj {
    int FUN_00a21830(int a, int b, int c, int d, int e);
    int FUN_00a22250(int a, int b, int c);
};
int A2225Obj::FUN_00a22250(int a, int b, int c)
{
    return FUN_00a21830(a, 0, b, 0, c);
}
}
}   // namespace f3m_00a22250

// @f3 0x00a25f60 (community match, verified in this file)
namespace f3m_00a25f60 {
namespace f3m_00a25f60 {
struct A25fTracker {
    virtual void V00(); virtual void V01(); virtual void V02();
    virtual int V0c(const char* name, int size, int value);
};
// pdb: hkAgent3Bridge::calcStatistics | hkpAgent3Bridge.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
int hkAgent3Bridge_calcStatistics(int unused, int* value, int unused2, A25fTracker* tracker)
{
    return tracker->V0c("ChildAgent2", 8, *value);
}
}
}   // namespace f3m_00a25f60

// @f3 0x00a25ce0 (community match, verified in this file)
extern void* DAT_00e8568c[];
extern void* DAT_00dcc494[];
namespace f3m_00a25ce0 {
namespace f3m_00a25ce0 {
struct A25ceMember { void FUN_00908ab0(int flags); };
struct A25ceObj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08;
    int unk0c;
    A25ceMember* unk10;
    void FUN_00a25ce0();
};
// pdb: hkpBroadPhase::~hkpBroadPhase | hkpBroadPhase.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void A25ceObj::FUN_00a25ce0()
{
    vtable = DAT_00e8568c;
    if (unk10) {
        unk10->FUN_00908ab0(1);
        unk10 = 0;
    }
    vtable = DAT_00dcc494;
}
}
}   // namespace f3m_00a25ce0

// @f3 0x00a2a060 (community match, verified in this file)
extern void* DAT_00e85ac4[];
namespace f3m_00a2a060 {
namespace f3m_00a2a060 {
struct A2a06ArrA { int unk00[3]; void FUN_009b1160(); };
struct A2a06ArrB { int unk00[3]; void FUN_00a29d60(); };
struct A2a06Obj {
    void** vtable;
    int unk04[7];
    A2a06ArrB unk20;
    A2a06ArrA unk2c;
    int unk38;
    A2a06ArrA unk3c;
    void FUN_00a7def0();
    void FUN_00a2a060();
};
// pdb: hkContainerResourceMap::`scalar deleting destructor' | hkResourceHandle.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void A2a06Obj::FUN_00a2a060()
{
    vtable = DAT_00e85ac4;
    unk3c.FUN_009b1160();
    unk2c.FUN_009b1160();
    unk20.FUN_00a29d60();
    FUN_00a7def0();
}
}
}   // namespace f3m_00a2a060

// @f3 0x00a25ba0 (community match, verified in this file)
extern void* DAT_00e8568c[];
namespace f3m_00a25ba0 {
namespace f3m_00a25ba0 {
struct A25baMember {
    int unk00;
    short unk04;
    void Reset() { unk00 = -47; unk04 = 0; }
    void hkMultiThreadCheck_disableChecks();
};
struct A25baObj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A25baMember unk08;
    int unk10;
    A25baObj* FUN_00a25ba0();
};
// pdb: hkpBroadPhase::hkpBroadPhase | hkpBroadPhase.obj | fnv360_0822_retail, caller_sim, high
A25baObj* A25baObj::FUN_00a25ba0()
{
    referenceCount = 1;
    vtable = DAT_00e8568c;
    unk08.Reset();
    unk10 = 0;
    unk08.hkMultiThreadCheck_disableChecks();
    return this;
}
}
}   // namespace f3m_00a25ba0

// @f3 0x00a29720 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a29720 {
namespace f3m_00a29720 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A2972Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A2972Pair { int a, b; };
struct A2972Member { int unk00[3]; void FUN_00922cf0(); };
struct A2972Obj {
    A2972Pair* data;
    int size;
    int capacityAndFlags;
    A2972Member unk0c;
    void FUN_00a29720();
};
// pdb: hkSerializeMultiMap<unsigned __int64,int>::~hkSerializeMultiMap<unsigned __int64,int> | hkVersionPatchManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void A2972Obj::FUN_00a29720()
{
    unk0c.FUN_00922cf0();
    if (!(capacityAndFlags & 0x80000000)) {
        int capacity = capacityAndFlags & 0x3fffffff;
        A2972Heap* heap = (A2972Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(data, capacity * sizeof(A2972Pair), 0x17);
    }
}
}
}   // namespace f3m_00a29720

// @f3 0x00a25e50 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a25e50 {
namespace f3m_00a25e50 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A25e5Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct A25e5Base {
    virtual ~A25e5Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A25e5Base() throw() { referenceCount = 1; }
    static void* operator new(unsigned int n)
    {
        A25e5Heap* heap = (A25e5Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x15);
        ((A25e5Base*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
struct A25e5Array {
    void* data;
    int size;
    int capacityAndFlags;
    A25e5Array() throw() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
struct A25e5Obj : A25e5Base {
    int unk08;
    int unk0c;
    A25e5Array unk10;
    A25e5Obj() throw() { unk08 = 0; unk0c = 0; }
    virtual ~A25e5Obj();
};
// pdb: hkTraceStreamcreate | hkTraceStream.obj | tesv_win, uvref, medium
A25e5Obj* FUN_00a25e50()
{
    return new A25e5Obj();
}
}
}   // namespace f3m_00a25e50

// @f3 0x00a21410 (community match, verified in this file)
namespace f3m_00a21410 {
namespace f3m_00a21410 {
void FUN_009b4a80(void* sem, int count);
struct A2141State { int unk00; int unk04; int unk08; int unk0c; };
struct A2141Obj {
    int unk00[19];
    void* unk4c;
    void* unk50;
    void FUN_00a21410(A2141State* s);
};
void A2141Obj::FUN_00a21410(A2141State* s)
{
    int n = s->unk04;
    s->unk04 = 0;
    while (n > 0) {
        FUN_009b4a80(unk50, 1);
        --n;
    }
    while (s->unk0c != 0) {
        FUN_009b4a80(unk4c, 1);
        --s->unk0c;
    }
}
}
}   // namespace f3m_00a21410

// @f3 0x00a295f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a295f0 {
namespace f3m_00a295f0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A295Heap { void* FUN_008f6f60(int size, int tag); };
void* FUN_009234e0(void* dst, const void* src, unsigned int n);
struct A295Member { int FUN_0093d900(); };
struct A295Class {
    int FUN_009b06a0();
    A295Member* FUN_009b06b0(int i);
};
void* __stdcall FUN_00a295f0(A295Class* klass, int* offsets)
{
    if (!offsets)
        return 0;
    int size = 0;
    int i = klass->FUN_009b06a0();
    while (--i >= 0) {
        if (offsets[i] != -1) {
            size = klass->FUN_009b06b0(i)->FUN_0093d900() + offsets[i];
            break;
        }
    }
    A295Heap* heap = (A295Heap*)DAT_00d9b080(DAT_010f3170);
    void* mem = heap->FUN_008f6f60(size, 6);
    FUN_009234e0(mem, offsets, size);
    return mem;
}
}
}   // namespace f3m_00a295f0

// @f3 0x00a261d0 (community match, verified in this file)
namespace f3m_00a261d0 {
namespace Task2383 {
struct Node {
    unsigned short type, unk02;
    unsigned int unk04, unk08, unk0c, unk10;
    Node* next;
    void FUN_009a1cc0(int,int,int,int,int);
    void FUN_009a1a20(int,int,int,int,int);
    void FUN_009a1c20(int,int,int,int,int);
};
struct Holder { unsigned int unk00,unk04,unk08,unk0c; Node* node; };
struct FUN_00a261d0 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    volatile Holder* holder;
    void Dispatch(int,int,int,int,int);
};
// pdb: hkpSimpleContactConstraintData::collisionResponseBeginCallback | hkpSimpleContactConstraintData.obj | tesv_win, objrun_prop, low
void FUN_00a261d0::Dispatch(int a,int b,int c,int d,int e) {
    volatile Holder* current = holder;
    Node* node = current->node;
    if (!node) return;
    while (node->type >= 0x17) {
        switch (node->type) {
        case 0x1a: node->FUN_009a1cc0(a,b,c,d,e); break;
        case 0x18: node->FUN_009a1a20(a,b,c,d,e); break;
        case 0x17: node->FUN_009a1c20(a,b,c,d,e); break;
        }
        node = node->next;
    }
}
}
}   // namespace f3m_00a261d0

// @f3 0x00a23770 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d35c[],DAT_00e855ec[],DAT_00e0811c[];
namespace f3m_00a23770 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace task2382 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Cmd {const char* name;unsigned ticks;int unk08;};
struct Stream {int unk00;char* end;int unk08;char* limit;};
struct Solver {int unk00,unk04;void* arg08;void* arg0c;void* arg10;};
struct Arg {int unk00,unk04,unk08,unk0c;Solver* solver;};
struct Context {char* world;int unk04;void* value;};
struct Target {void FUN_00a21830(void*,Arg*,Arg*,int,int);};
void __cdecl hkExportImpulsesAndRhs(void*,void*,void*,void*);
// pdb: hkCpuSolveExportResultsJob | hkpCpuSolveConstraintsJobs.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void __cdecl hkCpuSolveExportResultsJob(Context* context,Target* target,Arg* arg){
 Stream*s=(Stream*)TlsGetValue(DAT_0116913c);Cmd*c=(Cmd*)s->end;
 if((char*)c<s->limit){c->name=DAT_00e7d35c;*(const char**)((char*)c+12)=DAT_00e855ec;_ReadWriteBarrier();volatile unsigned ticks=(unsigned)__rdtsc();c->ticks=ticks;s->end=(char*)c+16;}
 Solver*solver=arg->solver;
 hkExportImpulsesAndRhs(context->world+0x1a0,solver->arg10,solver->arg0c,solver->arg08);
 Stream*s2=(Stream*)TlsGetValue(DAT_0116913c);Cmd*c2=(Cmd*)s2->end;
 if((char*)c2<s2->limit){c2->name=DAT_00e0811c;_ReadWriteBarrier();volatile unsigned ticks2=(unsigned)__rdtsc();c2->ticks=ticks2;s2->end=(char*)c2+12;}
 target->FUN_00a21830(context->value,arg,arg,0,0);
}
}
}   // namespace f3m_00a23770

// @f3 0x00a25e90 (community match, verified in this file)
struct Alloc25e90 {
    void FUN_008f6d90(void* data, unsigned int size, int tag);
};

typedef Alloc25e90* (__stdcall *AllocFn25e90)(int);

extern AllocFn25e90 FUN_00d9b080;
extern int FUN_00dcc494;

struct FUN_00a25e90_obj {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    void* unk10;
    int unk14;
    int unk18;

    FUN_00a25e90_obj* FUN_00a25e90(unsigned int flags);
};

// pdb: hkpMultiRayShape::`scalar deleting destructor' | hkpMultiRayShapeClass.obj | fnv360_0822_retail, vtable, high
FUN_00a25e90_obj* FUN_00a25e90_obj::FUN_00a25e90(unsigned int flags) {
    AllocFn25e90 allocator = FUN_00d9b080;

    if (!(unk18 & 0x80000000)) {
        unsigned int size = (unsigned int)unk18 & 0x3fffffffu;
        Alloc25e90* alloc = allocator(DAT_010f3170);
        alloc->FUN_008f6d90(unk10, size * 32, 0x17);
    }

    unk00 = (int)&FUN_00dcc494;

    if (flags & 1) {
        Alloc25e90* alloc = allocator(DAT_010f3170);
        alloc->FUN_008f6d90(this, unk04, 0x15);
    }

    return this;
}

// @f3 0x00a29d30 (community match, verified in this file)
namespace f3m_00a29d30 {
struct Sub29d30 {
    int unk00;
    int unk04;
    int unk08;
    void __thiscall FUN_00922cb0();
};

struct S29d30 {
    int a;
    int b;
    int c;
    Sub29d30 sub;
    int f18;
    S29d30* __thiscall FUN_00a29d30();
};

S29d30* __thiscall S29d30::FUN_00a29d30()
{
    a = 0;
    b = 0;
    c = 0x80000000;
    sub.FUN_00922cb0();
    f18 = -1;
    return this;
}
}   // namespace f3m_00a29d30

// @f3 0x00a3ba40 (community match, verified in this file)
extern int DAT_00e860b0;
namespace f3m_00a3ba40 {

static __declspec(noinline) int* FUN_00a3ba40(unsigned int x)
{
    return (int*)(((x >> 1) & 0x70) + (unsigned int)&DAT_00e860b0);
}

volatile int g_in_a3ba40;
volatile int g_out_a3ba40;
void caller_of_FUN_00a3ba40()
{
    g_out_a3ba40 = (int)FUN_00a3ba40((unsigned int)g_in_a3ba40);
}
}   // namespace f3m_00a3ba40

// @f3 0x00a30be0 (community match, verified in this file)
namespace f3m_00a30be0 {
struct FUN_00a30be0_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
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
    float unkA0;
    float unkA4;
    float unkA8;
    float unkAC;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    float unk130;
    float unk134;
    float unk138;
    float unk13C;

    void hkpGsk_convertFeatureToClosestDistance(int* param_1, float* param_2);
};

// pdb: hkpGsk::convertFeatureToClosestDistance | hkpGsk.obj | fnv360_0822_debug, objrun + skyrim(call_gap), high
void FUN_00a30be0_Obj::hkpGsk_convertFeatureToClosestDistance(int* param_1, float* param_2) {
    param_2[8] = *(float*)&param_1[3];
    param_2[0] = *(float*)&param_1[0];
    param_2[1] = *(float*)&param_1[1];
    param_2[2] = *(float*)&param_1[2];
    param_2[3] = *(float*)&param_1[3];

    if (this->unk00 == 1) {
        param_2[4] = this->unk20;
        param_2[5] = this->unk24;
        param_2[6] = this->unk28;
        param_2[7] = this->unk2C;
        return;
    }

    if (this->unk04 == 1) {
        float f = *(float*)&param_1[3];
        param_2[4] = this->unkA0 + f * param_2[0];
        param_2[5] = param_2[1] * f + this->unkA4;
        param_2[6] = param_2[2] * f + this->unkA8;
        param_2[7] = f * param_2[3] + this->unkAC;
        return;
    }

    param_2[4] = this->unk130;
    param_2[5] = this->unk134;
    param_2[6] = this->unk138;
    param_2[7] = this->unk13C;
}
}   // namespace f3m_00a30be0

// @f3 0x00a29380 (community match, verified in this file)
namespace f3m_00a29380 {

namespace f3m_00a29380 {
    struct MapA29380 {
        int unk00;
        int unk04;
        int unk08;
        int unk0C;

        void FUN_009b0e60(int key, int value);
    };

    class OwnerA29380 {
    public:
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
        MapA29380 map2C;
        MapA29380 map3C;

        void FUN_00a29380(int* entries);
    };

    void OwnerA29380::FUN_00a29380(int* entries) {
        if (!entries)
            return;
        int index = 0;
        int key = entries[0];
        if (!key)
            return;
        while (key) {
            int* current = entries + index * 2;
            map2C.FUN_009b0e60(key, current[1]);
            map3C.FUN_009b0e60(current[1], current[0]);
            ++index;
            key = entries[index * 2];
        }
    }
}
}   // namespace f3m_00a29380

// @f3 0x00a28480 (community match, verified in this file)
namespace f3m_00a28480 {
static __declspec(noinline) char* FUN_00a28480(char* p, int c)
{
    if (*p == (char)c)
        return p;
    do {
        if (*p == 0)
            return 0;
        p++;
    } while (*p != (char)c);
    return p;
}
volatile char* g_in28480;
volatile int g_char28480;
volatile char* g_out28480;
void caller_of_FUN_00a28480() { g_out28480 = FUN_00a28480((char*)g_in28480, g_char28480); }
}   // namespace f3m_00a28480

// @f3 0x00a28320 (community match, verified in this file)
extern const char DAT_00e85744[];
namespace f3m_00a28320 {

struct FUN_00a28320_Obj {
    virtual void vf0();
    virtual void vf4(const char* name, int value, void* param);
    virtual void vf8();
    virtual void vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
};


struct FUN_00a28320_This {
    void FUN_00a28320(FUN_00a28320_Obj* obj);
};

// pdb: hkpDefaultToiResourceMgr::getClassType | hkpDefaultToiResourceMgr.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: hkpDefaultToiResourceMgr::calcContentStatistics)
void FUN_00a28320_This::FUN_00a28320(FUN_00a28320_Obj* obj) {
    obj->vf4(DAT_00e85744, 2, this);
    obj->vf18();
}
}   // namespace f3m_00a28320

// @f3 0x00a28830 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a28830 {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() {}
};

namespace f3m_00a28830 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();

struct FreeElem
{
    FreeElem* m_pNext;
};
struct FreeList
{
    FreeElem* m_pHead;
    int m_iNumElem;
    void put(void* p)
    {
        FreeElem* elem = static_cast<FreeElem*>(p);
        FreeElem* head = m_pHead;
        m_iNumElem++;
        elem->m_pNext = head;
        m_pHead = elem;
    }
};
struct ThreadMemory
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int m_iMaxNumElemsOnFreeList;
    FreeList m_akFreeList[8];

    void FUN_008f6890(int row, void* p, int cls) throw();
    void deallocate(void* p, int row, int cls)
    {
        if (m_akFreeList[row].m_iNumElem >= m_iMaxNumElemsOnFreeList)
            FUN_008f6890(row, p, cls);
        else
            m_akFreeList[row].put(p);
    }
};

struct Node
{
    ~Node() { FUN_00951250(); }
    void FUN_00951250() throw();
    int unk00;
    static void operator delete(void* p)
    {
        ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        mem->deallocate(p, 3, 0x27);
    }
};
}

class FUN_00a28830 : public hkBaseObject
{
  public:
    virtual ~FUN_00a28830();
    int unk04;
    f3m_00a28830::Node* m_pNode;
};

// pdb: hkDisplayGeometry::~hkDisplayGeometry | hkDisplayGeometry.obj | fnv360_0822_retail, call_seq, medium
FUN_00a28830::~FUN_00a28830()
{
    if (m_pNode)
    {
        delete m_pNode;
        m_pNode = 0;
    }
}
}   // namespace f3m_00a28830

// @f3 0x00a22420 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a22420 {
namespace f3m_00a22420 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
struct FreeElem { FreeElem* m_pNext; };
struct FreeList
{
    FreeElem* m_pHead;
    int m_iNumElem;
    void put(void* p)
    {
        FreeElem* elem = static_cast<FreeElem*>(p);
        FreeElem* head = m_pHead;
        m_iNumElem++;
        elem->m_pNext = head;
        m_pHead = elem;
    }
};
struct ThreadMemory
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int m_iMaxNumElemsOnFreeList;
    FreeList m_akFreeList[8];
    void FUN_008f6890(int row, void* p, int cls) throw();
    void deallocate(void* p, int row, int cls)
    {
        if (m_akFreeList[row].m_iNumElem >= m_iMaxNumElemsOnFreeList)
            FUN_008f6890(row, p, cls);
        else
            m_akFreeList[row].put(p);
    }
};
}
namespace f3m_00a22420 {
struct A2242Block { int unk00; int unk04; int unk08; int unk0c; int unk10; void FUN_00a22270(); };
struct A2242Obj {
    void* next;
    int unk04; int unk08; int unk0c; int unk10;
    A2242Block blocks[3];
    A2242Obj* FUN_00a22420(unsigned int flags);
};
A2242Obj* A2242Obj::FUN_00a22420(unsigned int flags)
{
    A2242Block* p = blocks + 3;
    int n = 2;
    do {
        --p;
        p->FUN_00a22270();
    } while (--n >= 0);
    if ((flags & 1) && this) {
        f3m_00a22420::ThreadMemory* mem = (f3m_00a22420::ThreadMemory*)f3m_00a22420::TlsGetValue(DAT_010f3170);
        mem->deallocate(this, 6, 4);
    }
    return this;
}
}
}   // namespace f3m_00a22420

// @f3 0x00a22d40 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a22d40 {
namespace f3m_00a22d40 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
struct FreeElem { FreeElem* m_pNext; };
struct FreeList
{
    FreeElem* m_pHead;
    int m_iNumElem;
    void put(void* p)
    {
        FreeElem* elem = static_cast<FreeElem*>(p);
        FreeElem* head = m_pHead;
        m_iNumElem++;
        elem->m_pNext = head;
        m_pHead = elem;
    }
};
struct ThreadMemory
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int m_iMaxNumElemsOnFreeList;
    FreeList m_akFreeList[8];
    void FUN_008f6890(int row, void* p, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void deallocate(void* p, int row, int cls)
    {
        if (m_akFreeList[row].m_iNumElem >= m_iMaxNumElemsOnFreeList)
            FUN_008f6890(row, p, cls);
        else
            m_akFreeList[row].put(p);
    }
};
inline ThreadMemory& GetThreadMemory() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray()
    {
        if (m_capacityAndFlags >= 0)
            GetThreadMemory().FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(T), 0x17);
    }
    void release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
}
struct f3m_00a22d40_Obj
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
    f3m_00a22d40::hkArray<void*> m_kArray;
    f3m_00a22d40_Obj* FUN_00a22d40(unsigned int flags);
};
f3m_00a22d40_Obj* f3m_00a22d40_Obj::FUN_00a22d40(unsigned int flags)
{
    m_kArray.release();
    if ((flags & 1) && this)
        f3m_00a22d40::GetThreadMemory().deallocate(this, 7, 0x2c);
    return this;
}
}   // namespace f3m_00a22d40

// @f3 0x00a28390 (community match, verified in this file)
namespace f3m_00a28390 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;

struct hkBool
{
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
    char m_bool;
};

struct ThreadMemory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    char* m_pStackCurrent;
    int unk24; int unk28;
    char* m_pStackEnd;

    void* allocateStack(int nbytesIn)
    {
        int nbytes = (nbytesIn + 0x10) & ~0xf;
        char* current = m_pStackCurrent;
        char* next = current + nbytes;
        if (next <= m_pStackEnd)
        {
            m_pStackCurrent = next;
            return current;
        }
        return onStackOverflow(nbytes);
    }
};

struct Info
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    void* m_pBuffer;
    int m_iSize;
};
}

static __declspec(noinline) f3m_00a28390::hkBool __stdcall FUN_00a28310(int value)
{
    return true;
}

void* volatile g_keep_00a28310 = (void*)&FUN_00a28310;

struct f3m_00a28390_Obj
{
    int unk00;
    int unk04;
    int m_iSize;
    int hkpDefaultToiResourceMgr_beginToiAndSetupResources(int value, int unused, f3m_00a28390::Info* info);
};

// pdb: hkpDefaultToiResourceMgr::beginToiAndSetupResources | hkpDefaultToiResourceMgr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_prop), high
int f3m_00a28390_Obj::hkpDefaultToiResourceMgr_beginToiAndSetupResources(int value, int unused, f3m_00a28390::Info* info)
{
    if (FUN_00a28310(value))
    {
        int size = m_iSize;
        info->m_iSize = size;
        f3m_00a28390::ThreadMemory* mem = (f3m_00a28390::ThreadMemory*)f3m_00a28390::TlsGetValue(f3m_00a28390::DAT_010f3170);
        info->m_pBuffer = mem->allocateStack(size);
        info->m_i08 = 1000;
        info->m_i0c = 1000;
        info->m_i04 = 1000;
        info->m_i10 = 3;
        info->m_i14 = 4;
        info->m_i00 = 2;
        return 0;
    }
    return 1;
}

// @f3 0x00a221b0 (community match, verified in this file)
namespace f3m_00a221b0 {
extern unsigned long DAT_010f3170;
struct FreeElem { FreeElem* m_pNext; };
struct FreeList
{
    FreeElem* m_pHead;
    int m_iNumElem;
    void put(void* p)
    {
        FreeElem* elem = static_cast<FreeElem*>(p);
        FreeElem* head = m_pHead;
        m_iNumElem++;
        elem->m_pNext = head;
        m_pHead = elem;
    }
};
struct ThreadMemory
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int m_iMaxNumElemsOnFreeList;
    FreeList m_akFreeList[8];
    void FUN_008f6890(int row, void* p, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void deallocate(void* p, int row, int cls)
    {
        if (m_akFreeList[row].m_iNumElem >= m_iMaxNumElemsOnFreeList)
            FUN_008f6890(row, p, cls);
        else
            m_akFreeList[row].put(p);
    }
};
inline ThreadMemory& GetThreadMemory() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray()
    {
        if (m_capacityAndFlags >= 0)
            GetThreadMemory().FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(T), 0x17);
    }
    void release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
}
namespace f3m_00a221b0 {
struct CritSec
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CritSec* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSec* cs) throw();
struct GlobalLock
{
    CritSec m_kCriticalSection;
    int m_iOwner;
    int m_iCount;
    void FUN_00908a00();
    void Leave()
    {
        m_iOwner = -1;
        m_iCount = -1;
        LeaveCriticalSection(&m_kCriticalSection);
    }
};
extern GlobalLock DAT_011692e8;

struct Child
{
    void FUN_00a22420(unsigned int flags);
};
struct Node
{
    ~Node() { FUN_009b4a30(); }
    void FUN_009b4a30() throw();
    int unk00;
    static void operator delete(void* p)
    {
        ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        mem->deallocate(p, 1, 1);
    }
};
}

struct f3m_00a221b0_Obj
{
    f3m_00a221b0::CritSec m_kLock;
    int unk18;
    int unk1c;
    int unk20;
    f3m_00a221b0_Obj* m_pPrev;
    f3m_00a221b0_Obj* m_pNext;
    int unk2c;
    f3m_00a221b0::Child* m_pChild;
    int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48;
    f3m_00a221b0::Node* m_pNode;

    void FUN_00a221b0();
};

void f3m_00a221b0_Obj::FUN_00a221b0()
{
    if (m_pChild)
        m_pChild->FUN_00a22420(1);
    delete m_pNode;
    f3m_00a221b0::DeleteCriticalSection(&m_kLock);
    if (m_pPrev)
    {
        f3m_00a221b0::DAT_011692e8.FUN_00908a00();
        m_pPrev->m_pNext = m_pNext;
        if (m_pNext)
            m_pNext->m_pPrev = m_pPrev;
        f3m_00a221b0::DAT_011692e8.Leave();
    }
}

// @f3 0x00a29fb0 (community match, verified in this file)
namespace f3m_00a29fb0 {
namespace f3m_00a29fb0 {
struct Tag
{
};
struct Base
{
    Base(int value) throw();
    virtual ~Base();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
};
struct Member
{
    Member() throw() { FUN_00a297d0(); }
    void FUN_00a297d0() throw();
    int unk00; int unk04; int unk08;
};
struct PointerMap
{
    PointerMap(Tag tag) throw() { FUN_009b1110(tag); }
    void FUN_009b1110(Tag tag) throw();
    void FUN_009b0e60(int key, int value) throw();
    int unk00; int unk04; int unk08; int unk0c;
};
struct Pair
{
    int m_iKey;
    int m_iValue;
};
}

struct FUN_00a29fb0 : f3m_00a29fb0::Base
{
    FUN_00a29fb0(const f3m_00a29fb0::Pair* pairs, int value);
    virtual ~FUN_00a29fb0();
    f3m_00a29fb0::Member m_kMember;
    f3m_00a29fb0::PointerMap m_kForward;
    f3m_00a29fb0::PointerMap m_kReverse;
};

FUN_00a29fb0::FUN_00a29fb0(const f3m_00a29fb0::Pair* pairs, int value)
    : f3m_00a29fb0::Base(value), m_kForward(f3m_00a29fb0::Tag()), m_kReverse(f3m_00a29fb0::Tag())
{
    if (pairs)
    {
        for (int i = 0; pairs[i].m_iKey; i++)
        {
            m_kForward.FUN_009b0e60(pairs[i].m_iKey, pairs[i].m_iValue);
            m_kReverse.FUN_009b0e60(pairs[i].m_iValue, pairs[i].m_iKey);
        }
    }
}
}   // namespace f3m_00a29fb0

// @f3 0x00a29500 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a29500 {
namespace f3m_00a29500 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();

struct Heap
{
    void* FUN_008f6f60(int nbytes, int cls);
};
struct SubItem
{
    int m_i00;
    char* m_pcName;
};
struct Record
{
    char* m_pcName;
    SubItem* m_pItems;
    int m_iNumItems;
    int m_i0c;
    int m_i10;
};
inline Heap* GetHeap() { return (Heap*)TlsGetValue(DAT_010f3170); }
void __cdecl FUN_009234e0(void* dst, const void* src, int nbytes);
char* __cdecl FUN_00923640(const char* src);
}

f3m_00a29500::Record* __stdcall FUN_00a29500(const f3m_00a29500::Record* src, int count)
{
    using namespace f3m_00a29500;
    if (!src)
        return 0;
    Heap* heap = GetHeap();
    int bytes = count * sizeof(Record);
    Record* dst = (Record*)heap->FUN_008f6f60(bytes, 6);
    FUN_009234e0(dst, src, bytes);
    for (int i = 0; i < count; i++)
    {
        dst[i].m_pcName = FUN_00923640(dst[i].m_pcName);
        dst[i].m_i0c = 0;
        int n = dst[i].m_iNumItems;
        dst[i].m_pItems = (SubItem*)GetHeap()->FUN_008f6f60(n * sizeof(SubItem), 6);
        FUN_009234e0(dst[i].m_pItems, src[i].m_pItems, dst[i].m_iNumItems * sizeof(SubItem));
        for (int j = 0; j < dst[i].m_iNumItems; j++)
            dst[i].m_pItems[j].m_pcName = FUN_00923640(dst[i].m_pItems[j].m_pcName);
    }
    return dst;
}
}   // namespace f3m_00a29500

// @f3 0x00a254a0 (community match, verified in this file)
namespace f3m_00a254a0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;

struct ThreadMemory
{
    void* FUN_008f6d30(int nbytes, int align);
};
struct BulkAllocator
{
    virtual void v00();
    virtual void AllocateBlocks(void** blocks, int count, int blockSize);
};
extern BulkAllocator* DAT_010f3400;

struct BlockInfo
{
    void Init(void* data, int size)
    {
        m_iDataOffset = (int)((char*)data - (char*)this);
        m_i04 = 0;
        m_iSize = size;
    }
    int m_iDataOffset;
    int m_i04;
    int m_iSize;
};
struct Header
{
    int m_iCount;
    int m_iCount2;
    int m_iBlockSize;
    void* m_apBlocks[1];
};
inline ThreadMemory* GetMem() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
inline void InitBlock(void* p, int size)
{
    ((BlockInfo*)((char*)p + 0x10))->Init((char*)p + 0x20, size);
}
}

// pdb: hkpAgentSectorHeader::allocate | hkpDynamicsJobQueueUtils.obj | fnv360_0822_retail, call_gap + skyrim(call_gap), high
f3m_00a254a0::Header* __cdecl hkpAgentSectorHeader_allocate(int count, int stride)
{
    using namespace f3m_00a254a0;
    Header* header = (Header*)GetMem()->FUN_008f6d30((short)count * 4 + 0xc, 4);
    int size = stride << 4;
    int blockSize = size + 0x20;
    header->m_iCount2 = count;
    header->m_iCount = count;
    header->m_iBlockSize = blockSize;
    void** blocks = header->m_apBlocks;
    if (count < 4)
    {
        for (int i = 0; i < count; i++)
        {
            void* p = GetMem()->FUN_008f6d30(blockSize, 4);
            blocks[i] = p;
            if (p)
                InitBlock(p, size);
        }
    }
    else
    {
        DAT_010f3400->AllocateBlocks(blocks, count, blockSize);
        for (int i = 0; i < count; i++)
        {
            void* p = blocks[i];
            if (p)
                InitBlock(p, size);
        }
    }
    return header;
}

// @f3 0x00a28760 (community match, verified in this file)
extern int DAT_0116c254;
namespace f3m_00a28760 {
void __cdecl FUN_00a28760()
{
    DAT_0116c254++;
}
}   // namespace f3m_00a28760

// @f3 0x00a2a1c0 (community match, verified in this file)
namespace f3m_00a2a1c0 {
struct S {
    int a,b,c,d;
    int fld;
    int FUN_00a2a1c0();
};
int S::FUN_00a2a1c0()
{
    return fld & 0x7fffffff;
}
}   // namespace f3m_00a2a1c0

// @f3 0x00a29450 (community match, verified in this file)
namespace f3m_00a29450 {
// One key of the sparse map owned by FUN_00a29450: every stored value that shares a key is
// linked into a chain, and setting the key rewrites the value of each element in that chain.

enum { NO_LINK = -1 };          // end-of-chain marker stored in BucketLink::next

struct ValueCell {              // one stored value; the map writes it through its first field
    int m_iValue;
};

struct BucketLink {             // one element of a key's chain
    ValueCell* m_pCell;
    int m_iNext;                // index of the next link in the chain, NO_LINK at the end
};

struct ChainMap434 {
    BucketLink* m_pLinks;       // chain elements for every key

    int FUN_00a47f40(int key);          // first chain element holding this key, NO_LINK when absent
    void FUN_00a29450(int key, int value);
    void FUN_00a2a110(int key);         // the key changed: update whatever depends on it
};

void ChainMap434::FUN_00a29450(int key, int value)
{
    int link = FUN_00a47f40(key);
    if (link != NO_LINK) {
        do {
            m_pLinks[link].m_pCell->m_iValue = value;
            link = m_pLinks[link].m_iNext;
        } while (link != NO_LINK);
    }
    FUN_00a2a110(key);
}
}   // namespace f3m_00a29450

// @f3 0x00a22dc0 (community match, verified in this file)
namespace f3m_00a22dc0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;
struct FreeElem { FreeElem* m_pNext; };
struct FreeList
{
    FreeElem* m_pHead;
    int m_iNumElem;
    void put(void* p)
    {
        FreeElem* elem = static_cast<FreeElem*>(p);
        FreeElem* head = m_pHead;
        m_iNumElem++;
        elem->m_pNext = head;
        m_pHead = elem;
    }
};
struct ThreadMemory
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int m_iMaxNumElemsOnFreeList;
    FreeList m_akFreeList[8];
    void FUN_008f6890(int row, void* p, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void deallocate(void* p, int row, int cls)
    {
        if (m_akFreeList[row].m_iNumElem >= m_iMaxNumElemsOnFreeList)
            FUN_008f6890(row, p, cls);
        else
            m_akFreeList[row].put(p);
    }
};
inline ThreadMemory& GetThreadMemory() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray()
    {
        if (m_capacityAndFlags >= 0)
            GetThreadMemory().FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(T), 0x17);
    }
    void release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
}
namespace f3m_00a22dc0 {
struct BulkAllocator
{
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void FreeBlocks(void* blocks, int count, int cls);
};
extern BulkAllocator* DAT_010f3400;
struct Node
{
    Node* m_pNext;
};
struct Obj
{
    int unk00; int unk04; int unk08; int unk0c;
    int m_i10;
    void* m_pBlocks;
    int m_iNumBlocks;
    int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    void* m_pArray;
    unsigned short unk54;
    unsigned short m_usArrayCount;
    int unk58; int unk5c; int unk60; int unk64;
    Node* m_pFreeA;
    int unk6c; int unk70; int unk74;
    Node* m_pFreeB;
    void FUN_00a22d40(unsigned int flags);
};
}

static inline void FreeBytes(void* p, int nbytes, int cls, f3m_00a22dc0::ThreadMemory* m)
{
    m->FUN_008f6d90(p, nbytes, cls);
}

static __declspec(noinline) void FUN_00a22dc0(f3m_00a22dc0::Obj* o)
{
    using namespace f3m_00a22dc0;
    while (o->m_pFreeA)
    {
        Node* n = o->m_pFreeA;
        o->m_pFreeA = n->m_pNext;
        GetThreadMemory().deallocate(n, 15, 0x2c);
    }
    while (o->m_pFreeB)
    {
        Node* n = o->m_pFreeB;
        o->m_pFreeB = n->m_pNext;
        GetThreadMemory().deallocate(n, 4, 0x2c);
    }
    if (o->m_pBlocks)
    {
        DAT_010f3400->FreeBlocks(o->m_pBlocks, o->m_iNumBlocks, 0x2c);
        o->m_pBlocks = 0;
    }
    if (o->m_i10 > 1)
    {
        unsigned int n = o->m_usArrayCount;
        void* arr = o->m_pArray;
        ThreadMemory& m = GetThreadMemory();
        m.FUN_008f6d90(arr, n * 4, 1);
        o->m_pArray = 0;
    }
    o->FUN_00a22d40(1);
}

f3m_00a22dc0::Obj* volatile g_obj_00a22dc0;
void caller_of_FUN_00a22dc0()
{
    FUN_00a22dc0(g_obj_00a22dc0);
}

// @f3 0x00a21550 (community match, verified in this file)
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) int __stdcall InitializeCriticalSectionAndSpinCount(void*, unsigned long);
namespace na21550 {
struct Block { Block* next; };
struct Bucket { Block* head; int count; };
struct PoolHeap {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Bucket buckets[25];
    void* FUN_008f6800(int index, unsigned int tag);
};
static __forceinline void* PoolAlloc(int index, unsigned int tag) {
    PoolHeap* heap = (PoolHeap*)TlsGetValue(DAT_010f3170);
    Block* b = heap->buckets[index].head;
    if (b) {
        heap->buckets[index].count += -1;
        heap->buckets[index].head = b->next;
        return b;
    }
    return heap->FUN_008f6800(index, tag);
}
struct FUN_0094eda0 {
    FUN_0094eda0() throw();
    int v[5];
};
struct State {
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    FUN_0094eda0 items[3];
    __forceinline State() {}
    static void* operator new(unsigned int) { return PoolAlloc(6, 4); }
    static void operator delete(void* p);
};
struct FUN_009b4a10 {
    FUN_009b4a10(int a, int b) throw();
    static void* operator new(unsigned int) { return PoolAlloc(1, 1); }
    static void operator delete(void* p);
};
struct CritSec {
    void* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};
struct BSLock {
    CritSec cs;
    int owner;
    int count;
    void FUN_00908a00();
    __forceinline void Init() {
        InitializeCriticalSectionAndSpinCount(&cs, 0);
        owner = -1;
        count = -1;
    }
    __forceinline void Unlock() {
        owner = -1;
        count = -1;
        LeaveCriticalSection(&cs);
    }
};
}
using namespace na21550;
class FUN_00a21550 {
public:
    BSLock lock;
    int unk20;
    FUN_00a21550* prev;
    FUN_00a21550* next;
    int unk2c;
    State* state;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    FUN_009b4a10* obj4c;
    int a, b, c;
    FUN_00a21550(int a0, int a1, int a2);
    void FUN_00a21500(int v);
    void FUN_00a21470(int v);
};
extern FUN_00a21550 DAT_011692e8;
FUN_00a21550::FUN_00a21550(int a0, int a1, int a2)
{
    unk20 = 0;
    prev = 0;
    next = 0;
    DAT_011692e8.lock.FUN_00908a00();
    next = DAT_011692e8.next;
    if (next)
        next->prev = this;
    prev = &DAT_011692e8;
    DAT_011692e8.next = this;
    DAT_011692e8.lock.Unlock();
    lock.Init();
    state = new State;
    obj4c = new FUN_009b4a10(0, 1000);
    a = a0;
    b = a1;
    c = a2;
    state->unk10 = 0;
    state->unk04 = 0;
    state->unk08 = 0;
    state->unk0c = 0;
    state->unk00 = 0;
    FUN_00a21500(0x80);
    FUN_00a21470(0);
}

// @f3 0x00a25580 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace f3m_00a297f0 {
struct ThreadMemoryA25580 { void FUN_008f6d90(void* p, int size, int cls) throw(); };
struct BulkAllocatorA25580 {
    virtual void v00();
    virtual void AllocateBlocks(void** blocks, int count, int blockSize);
    virtual void FreeBlocks(void** blocks, int count, int blockSize);
};
extern BulkAllocatorA25580* DAT_010f3400;
struct Header {
    int m_iCount;
    int m_iCount2;
    int m_iBlockSize;
    void hkpAgentSectorHeader_deallocate();
    void* m_apBlocks[1];
};
// pdb: hkpAgentSectorHeader::deallocate | hkpDynamicsJobQueueUtils.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void Header::hkpAgentSectorHeader_deallocate()
{
    void** blocks = m_apBlocks;
    if (m_iCount < 4) {
        for (int i = 0; i < m_iCount; i++) {
            int size = m_iBlockSize;
            void* p = blocks[i];
            ThreadMemoryA25580* mem = (ThreadMemoryA25580*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(p, size, 4);
        }
    } else
        DAT_010f3400->FreeBlocks(blocks, m_iCount, m_iBlockSize);
    int bytes = (short)m_iCount * 4 + 0xc;
    ThreadMemoryA25580* mem = (ThreadMemoryA25580*)TlsGetValue(DAT_010f3170);
    mem->FUN_008f6d90(this, bytes, 4);
}
}

// @f3 0x00a29b90 (community match, verified in this file)
namespace f3m_00a29b90 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;

struct Heap
{
    void FUN_008f6f90(void* p);
};
struct Entry
{
    void* m_pData;
    int m_i04;
    void* m_pKey;
    int m_i0c;
    int m_i10;
    int m_i14;
};
struct Map
{
    int unk00;
    int unk04;
    int m_iLimit;
    int FUN_00922790(void* key);
    int FUN_009227d0(void* key, int flags);
    void FUN_00922710(void* key, int flags);
};
}

struct f3m_00a29b90_Obj
{
    void FUN_00a29670(void* key, int flags);
    void FUN_00a29b90(f3m_00a29b90::Entry* entries, int count, f3m_00a29b90::Map* map);
};

// pdb: findPatchIndexInDependencies | hkVersionPatchManager.obj | fnv360_0822_retail, caller_sim, low
void f3m_00a29b90_Obj::FUN_00a29b90(f3m_00a29b90::Entry* entries, int count, f3m_00a29b90::Map* map)
{
    if (count > 0)
    {
        void** pk = &entries->m_pKey;
        int n = count;
        do
        {
            void* key = *pk;
            if (key && map->FUN_00922790(key) <= map->m_iLimit && map->FUN_009227d0(key, 0))
            {
                FUN_00a29670(key, 1);
                map->FUN_00922710(key, 0);
            }
            void* data = pk[-2];
            f3m_00a29b90::Heap* heap = (f3m_00a29b90::Heap*)f3m_00a29b90::TlsGetValue(f3m_00a29b90::DAT_010f3170);
            heap->FUN_008f6f90(data);
            pk += 6;
        } while (--n);
    }
    f3m_00a29b90::Heap* heap = (f3m_00a29b90::Heap*)f3m_00a29b90::TlsGetValue(f3m_00a29b90::DAT_010f3170);
    heap->FUN_008f6f90(entries);
}

// @f3 0x00a22ec0 (community match, verified in this file)
namespace f3m_00a22ec0 {
typedef unsigned long DWORD;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern long (__stdcall* const DAT_00d9b1a8)(volatile long*,long);
struct MonitorEntry { const char* name; unsigned int ticks; int unk08; };
struct Monitor { int unk00; MonitorEntry* cursor; int unk08; MonitorEntry* end; };
extern DWORD DAT_0116913c;
extern DWORD DAT_010f3170;
extern const char str_00e8559c[];
extern const char str_00e85580[];
static __forceinline void timer(const char* name) {
 Monitor* monitor = (Monitor*)TlsGetValue(DAT_0116913c);
 MonitorEntry* cursor = monitor->cursor;
 if(cursor < monitor->end) {
  cursor->name = name;
  unsigned int ticks;
  __asm {
   rdtsc
   mov dword ptr[ticks], eax
  }
  cursor->ticks = ticks;
  monitor->cursor = cursor + 1;
 }
}
struct Node { Node* next; };
struct FreeList { Node* head; int count; };
struct Pool {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
 virtual void* Allocate(int size); virtual void Free(void* pointer);
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 char* cursor; int unk24; char* special; char* end; int unk30; int threshold;
 FreeList lists[16];
 void FUN_008f6890(int index,void* node,int tag);
 void FUN_008f6d90(void* pointer,int size,int tag);
 __forceinline char* allocate(int size) {
  char* result=cursor;
  char* next=result+size;
  if(next <= end) { cursor=next; return result; }
  return (char*)Allocate(size);
 }
 __forceinline void freeTemporary(char* pointer) {
  cursor=pointer;
  if(pointer==special) Free(pointer);
 }
 __forceinline void releaseNode(Node* node,int index) {
  FreeList& list=lists[index];
  if(list.count >= threshold) FUN_008f6890(index,node,0x2c);
  else { _ReadWriteBarrier(); Node* head=list.head; ++list.count; node->next=head; list.head=node; }
 }
};
struct Solver {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
 virtual void ReturnMemory(void* p,int size,int tag);
};
extern Solver* DAT_010f3400;
static __forceinline Pool* pool() { return (Pool*)TlsGetValue(DAT_010f3170); }
template<class T> static __forceinline void returnChunk(T*& pointer,int count,int tag) { Pool* memory=pool(); memory->FUN_008f6d90(pointer,count*sizeof(T),tag); }
struct Chunk { int count; Chunk* next; int unk08; int unk0c; unsigned int records[4]; };
struct Block {
 int unk00,unk04; int pending; volatile long refs; int threads;
 void* buffer; int bufferSize; char state; char unk1d; short unk1e;
 Chunk* chunks;
 int unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
 int* table; short unk54; unsigned short tableCount; int unk58;
 int* arrData; int arrSize; unsigned int arrCapacity;
 Node* bigNodes; int unk6c,unk70,unk74; Node* smallNodes;
};
struct Setup {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 char unk24; unsigned char oldFlags; unsigned char newFlags; char unk27;
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
};
struct Device {
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
 int unkac;
 int unkb0;
 int unkb4;
 int unkb8;
 int unkbc;
 int unkc0;
 char unkc4; unsigned char enabled; short unkc6;
 int unkc8;
 int unkcc;
 int unkd0;
 int unkd4;
 int unkd8;
 int unkdc;
 int unke0;
 int unke4;
 int unke8;
 int unkec;
 int unkf0;
 int unkf4;
 int unkf8;
 int unkfc;
 int unk100;
 int unk104;
 int unk108;
 int unk10c;
 int unk110;
 int unk114;
 int unk118;
 int unk11c;
 int unk120;
 int unk124;
 int unk128;
 int unk12c;
 int unk130;
 int unk134;
 int unk138;
 int unk13c;
 int unk140;
 int unk144;
 int unk148;
 int unk14c;
 int unk150;
 int unk154;
 int unk158;
 int unk15c;
 int unk160;
 int unk164;
 int unk168;
 int unk16c;
 int unk170;
 int unk174;
 int unk178;
 int unk17c;
 int unk180;
 int unk184;
 int unk188;
 int unk18c;
 int unk190;
 int unk194;
 int unk198;
 int unk19c;
};
struct Builder { void FUN_0098df40(int param48,int param4c,Device* device,char* marker); };
struct Owner { Device* device; Builder* builder; void* context; };
struct Job {
 unsigned short kind; unsigned short unk02;
 Setup* setup; Block* block; int unk0c; void* blocks;
 unsigned short unk14; unsigned short numBlocks; unsigned short count; unsigned short capacity;
 int param; int config20,config24,config28,config2c; int unk30; unsigned short pitch;
};
void __cdecl hkpWorldOperationUtil_markIslandInactiveMt(Device*,Setup*);
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(Device*,char*,int);
struct Output {
 void* FUN_00a21d70(int zero,int one,void* context,Job* job,int unused);
 void* FUN_00a21830(void* context,Job* job,Job* same,Owner* owner,int unused);
};
// pdb: hkpSingleThreadedJobsOnIsland::cpuBroadPhaseJob | hkpCpuBroadPhaseJob.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void* __cdecl hkpSingleThreadedJobsOnIsland_cpuBroadPhaseJob(Owner* owner,Output* output,Job* nextJobOut) {
 Job* job=nextJobOut;
 Setup* setup=job->setup;
 timer(str_00e8559c);
 if(job->block->pending && owner->device->enabled && (setup->newFlags & 12) && !(setup->oldFlags & 12))
  hkpWorldOperationUtil_markIslandInactiveMt(owner->device,setup);
 char* marker=&job->block->state;
 owner->builder->FUN_0098df40(setup->unk48,setup->unk4c,owner->device,marker);
 Block* block=job->block;
 long previous=DAT_00d9b1a8(&block->refs,-1);
 if(previous==block->threads) {
  if(block->chunks) {
   int total=0;
   for(Chunk* chunk=block->chunks;chunk;chunk=chunk->next) total+=chunk->count;
   Pool* memory=pool();
   int bytes=((total+1)<<4)&~15;
   char* copy=memory->allocate(bytes);
   int index=0;
   for(Chunk* chunk=block->chunks;chunk;chunk=chunk->next) {
    int n=chunk->count*4;
    unsigned int* dst=(unsigned int*)(copy+index*16);
    unsigned int* src=chunk->records;
    if(n>0) do { *dst++=*src++; } while(--n);
    index+=chunk->count;
   }
   hkpWorldCallbackUtil_fireContactImpulseLimitBreached(owner->device,copy,total);
   pool()->freeTemporary(copy);
  }
  *marker=2;
 } else {
  if(*marker!=2) {
   timer(str_00e85580);
   while(*(volatile char*)marker!=2) {}
   timer("Et");
  }
 }
 if(previous==1) {
  Block* block=job->block;
  while(block->bigNodes) {Node* n=block->bigNodes;block->bigNodes=n->next;pool()->releaseNode(n,15);}
  while(block->smallNodes) {Node* n=block->smallNodes;block->smallNodes=n->next;pool()->releaseNode(n,4);}
  if(block->buffer) { DAT_010f3400->ReturnMemory(block->buffer,block->bufferSize,0x2c); block->buffer=0; }
  if(block->threads>1) { int count=block->tableCount; int* table=block->table; returnChunk(table,count,1);block->table=0; }
  if((block->arrCapacity&0x80000000u)==0) returnChunk(block->arrData,block->arrCapacity&0x3fffffff,0x17);
  pool()->releaseNode((Node*)block,7);
 }
 int count=setup->unk60;
 if(count>0) {
  Device* device=owner->device;
  int capacity=device->unkd4;
  int param=setup->unk5c; int pitch=setup->unk58;
  job->kind=13;
  job->config20=device->unk190; job->config24=device->unk194; job->config28=device->unk198; job->config2c=device->unk19c;
  job->unk14=0; job->param=param; job->count=(unsigned short)count;job->capacity=(unsigned short)capacity;job->blocks=0;job->unk30=0;job->pitch=(unsigned short)pitch;
  if(count>capacity) {int n=(count-1)/capacity+1;job->blocks=hkpAgentSectorHeader_allocate(n,16);job->numBlocks=(unsigned short)n;}
  timer("Et");
  return output->FUN_00a21d70(0,1,owner->context,job,0);
 } else {
  timer("Et");
  return output->FUN_00a21830(owner->context,job,job,owner,0);
 }
}
}   // namespace f3m_00a22ec0

// @f3 0x00a293d0 (community match, verified in this file)
namespace f3m_00a293d0 {
struct FUN_00a293d0_Arg {
    int Probe();
    bool* SetFlag(bool* ok, int key);
    const char* Entry(int key);
    const char* Next(int key);
};
struct FUN_00a293d0_Sub {
    void* entries; int count, mask, unk0c;
    void Store(const char* a, const char* b);
};
struct ReferencedObject;
struct OwnerMap {
    void* table; int field10, field14, field18;
};
struct OwnerCollection {
    void* records; int count; unsigned int capacityAndFlags;
};
struct FUN_00a293d0_Owner {
    void* vtable; unsigned short unk04; short referenceCount; int unk08; OwnerMap map0c; ReferencedObject* reference1c; OwnerCollection collection20;
    FUN_00a293d0_Sub sub2c;
    FUN_00a293d0_Sub sub3c;
    void FUN_00a293d0(FUN_00a293d0_Arg* arg);
};
void FUN_00a293d0_Owner::FUN_00a293d0(FUN_00a293d0_Arg* arg) {
    int key = arg->Probe();
    bool ok;
    arg->SetFlag(&ok, key);
    if (!ok) return;
    FUN_00a293d0_Sub* first = &sub2c;
    FUN_00a293d0_Sub* second = &sub3c;
    do {
        const char* a = arg->Entry(key);
        const char* b = arg->Next(key);
        first->Store(a, b);
        second->Store(b, a);
        arg->SetFlag(&ok, key);
    } while (ok);
}
}   // namespace f3m_00a293d0

// @f3 0x00a29760 (community match, verified in this file)
namespace f3m_00a29760 {

namespace f3m_00a29760 {
struct Entry
{
    int* m_pKey;
    int m_iNext;
};
}

struct f3m_00a29760_Table
{
    f3m_00a29760::Entry* m_pEntries;

    int FUN_00a47f40(int value);
    void FUN_00a2a1d0(int value, int index);
    void FUN_00a480b0(int value, const void* key);
    void FUN_00a29760(int value, int* slot);
};

void f3m_00a29760_Table::FUN_00a29760(int value, int* slot)
{
    int current = *slot;
    int v = value;
    if (current != 0)
    {
        int index = FUN_00a47f40(current);
        if (index != -1)
        {
            f3m_00a29760::Entry* entries = m_pEntries;
            do
            {
                if (entries[index].m_pKey == slot)
                {
                    if (v == current)
                        return;
                    FUN_00a2a1d0(current, index);
                    break;
                }
                index = entries[index].m_iNext;
            } while (index != -1);
        }
    }
    if (v != 0)
        FUN_00a480b0(v, &value + 1);
    *slot = v;
}
}   // namespace f3m_00a29760

// @f3 0x00a29670 (community match, verified in this file)
namespace f3m_00a29670 {
struct f3m_00a29670_ThreadMemory {
    void FUN_008f6f90(void* p);
};
namespace f3m_00a29670 {
inline f3m_00a29670_ThreadMemory* Memory() {
    return (f3m_00a29670_ThreadMemory*)TlsGetValue(DAT_010f3170);
}
struct Item { int value; char* name; };
struct Enum { char* name; Item* items; int count; int unk0c, unk10; };
struct Patcher {
    void FUN_00a29670(Enum* enums, int count);
};
}

void f3m_00a29670::Patcher::FUN_00a29670(Enum* enums, int count)
{
    for (int i = 0; i < count; i++) {
        Enum& e = enums[i];
        Item* items = e.items;
        Item* it = items;
        for (int j = 0; j < e.count; j++, it++) {
            char* name = it->name;
            f3m_00a29670_ThreadMemory* m = Memory();
            m->FUN_008f6f90(name);
        }
        f3m_00a29670_ThreadMemory* m = Memory();
        m->FUN_008f6f90(items);
        char* enumName = e.name;
        m = Memory();
        m->FUN_008f6f90(enumName);
    }
    f3m_00a29670_ThreadMemory* m = Memory();
    m->FUN_008f6f90(enums);
}
}   // namespace f3m_00a29670

// @f3 0x00a21470 (community match, verified in this file)
namespace f3m_00a21470 {
void* __cdecl FUN_009234e0(void* dst, const void* src, unsigned int bytes);
struct Record21470 {
    unsigned char count;
    unsigned char index0;
    unsigned char index1;
    unsigned char index2;
};
struct Obj21470 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    void* allocated30;
    Record21470 first;
    Record21470 second;
    Record21470 third;
    void __thiscall FUN_00a21470(int unused);
};
void __thiscall Obj21470::FUN_00a21470(int unused)
{
    (void)unused;
    first.index0 = 0;
    first.index1 = 1;
    unsigned char* src = &first.count;
    *src = 2;
    *(volatile unsigned char*)&second.index0 = 1;
    second.index1 = 0;
    *(volatile unsigned char*)&second.count = 2;
    FUN_009234e0(&third, src, sizeof(first));
}
}   // namespace f3m_00a21470

// @f3 0x00a25600 (community match, verified in this file)
namespace f3m_00a25600 {
namespace f3m_00a25600 {
class FUN_00921790 {
public:
    FUN_00921790(const FUN_00921790& other);
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct Vec3 {
    float x, y, z;
};
struct Info : FUN_00921790 {
    Vec3 v50;
    Vec3 v5c;
    bool b68;
    int v6c;
};
struct Source {
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68;
    Info* info;
};
class FUN_00981430 {
public:
    FUN_00981430(void* a, void* b);
    int unk00;
};
}
class FUN_00a25600 {
public:
    FUN_00a25600(f3m_00a25600::Source* source, int b, int c);
    f3m_00a25600::Source* source;
    int b;
    int c;
    int unk0c;
    f3m_00a25600::Info info;
    f3m_00a25600::FUN_00981430 sub;
};
FUN_00a25600::FUN_00a25600(f3m_00a25600::Source* source, int b, int c)
    : source(source), b(b), c(c), info(*source->info), sub((char*)source + 0x1a0, (char*)source + 0x190)
{
}
}   // namespace f3m_00a25600

// @f3 0x00a2a090 (community match, verified in this file)
namespace f3m_00a2a090 {
namespace work_a2a090 {
struct Tag { char value; Tag() throw() : value(0) {} };
struct Owner;
struct Map {
    int unk00, unk04, unk08, unk0c;
    Map(Tag tag) throw() { FUN_009b1110(tag); }
    ~Map() throw() { FUN_009b1160(); }
    void FUN_009b1110(Tag tag) throw();
    void FUN_009b1160() throw();
    void dummy(int a) throw();
};
struct ExistingMap { int unk00, unk04, unk08; };
struct Cloner {
    int unk00, unk04, unk08;
    void* FUN_00a29dd0(void* src, Owner* visitor, Map* existing, Map* output) throw();
};
struct Owner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(Map* map) throw();
    virtual void* v2c(int key) throw();
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    Cloner cloner;
    ExistingMap existing;
    int unk38;
    Map out;
    int FUN_00a29360(int key) throw();
    void* FUN_00a7df80(int key) throw();
    void* FUN_00a2a090(int key) throw();
};
static __declspec(noinline) void FUN_00a292e0(Owner* self, Map* found) throw()
{
    if (self->unk18 > 0) {
        self->FUN_00a29360(found->unk04);
        self->FUN_00a29360(found->unk08);
    }
}
void* Owner::FUN_00a2a090(int key) throw()
{
    void* result = v2c(key);
    if (result || !unk1c) return result;
    void* source = FUN_00a7df80(FUN_00a29360(key));
    if (source) {
        Tag tag; Map found(tag);
        cloner.FUN_00a29dd0(source, this, &out, &found);
        FUN_00a292e0(this, &found);
        v28(&found);
    }
    return source;
}
}
}   // namespace f3m_00a2a090

// @f3 0x00a21d70 (community match, verified in this file)
extern unsigned long DAT_0116913c;
namespace f3m_00a21d70 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);

struct Sa21d70_TimerCommand {
    const char* m_name;
    unsigned int m_ticks;
    unsigned int unk08;

    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov ticks, eax } m_ticks = ticks; }
};

struct Sa21d70_MonitorStream {
    int unk00;
    Sa21d70_TimerCommand* m_end;
    int unk08;
    Sa21d70_TimerCommand* m_capacityMinusEpsilon;
};

struct __declspec(align(16)) Sa21d70_Entry {
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
};

struct Sa21d70_Queue {
    Sa21d70_Entry* m_data;
    int m_capacity;
    int m_head;
    int m_tail;
    int m_elementsInUse;
    void FUN_00a222a0(int capacity);
};

struct Sa21d70_DynamicData {
    int m_numActiveJobs;
    int m_numThreadsWaiting;
    int unk08;
    int m_numThreadsWaitingSpecial;
    int unk10;
    Sa21d70_Queue m_jobQueue[4];
};

struct Sa21d70_Semaphore {
    void FUN_009b4a40();
    static void __cdecl FUN_009b4a80(Sa21d70_Semaphore* sem, int count);
};

struct Sa21d70_QueueSet {
    unsigned char m_numQueues;
    unsigned char m_queueIndices[3];
};

struct Sa21d70_JobQueue;
typedef int (__cdecl *Sa21d70_PopJobFunc)(Sa21d70_JobQueue& queue, Sa21d70_DynamicData* data, Sa21d70_Entry& job, Sa21d70_Entry& jobOut);

struct Sa21d70_JobQueue {
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
    Sa21d70_QueueSet m_queueSets[3];
    Sa21d70_PopJobFunc m_popJobFunc;
    int unk44;
    int unk48;
    Sa21d70_Semaphore* m_specialSemaphore;
    Sa21d70_Semaphore* m_semaphore;

    Sa21d70_DynamicData* FUN_00a214a0(Sa21d70_Entry* storage);
    void FUN_00a213f0(Sa21d70_Entry* storage);
    void FUN_00a21410(Sa21d70_DynamicData* data);
    int FUN_00a21d70(int queueIndexOfNewJob, int addAtBack, int threadType, Sa21d70_Entry* jobInOut, int waitStatus);
};

// pdb: hkJobQueue::finishAddAndGetNextJob | hkJobQueue.obj | fnv360_0822_debug, ustr_rel, medium
// pdb params: oldJobType, priority, jobInOut, waitStatus
int Sa21d70_JobQueue::FUN_00a21d70(int queueIndexOfNewJob, int addAtBack, int threadType, Sa21d70_Entry* jobInOut, int waitStatus)
{
    {
        Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
        Sa21d70_TimerCommand* h = mon->m_end;
        if (h < mon->m_capacityMinusEpsilon) {
            h->m_name = "TtGetNextJob";
            h->setTime();
            mon->m_end = h + 1;
        }
    }

    bool isFirstTime = true;
    Sa21d70_Entry job;
    for (;;) {
        Sa21d70_DynamicData* data = FUN_00a214a0(&job);
        if (isFirstTime) {
            if (addAtBack == 0) {
                Sa21d70_Queue& queue = data->m_jobQueue[queueIndexOfNewJob];
                if (queue.m_elementsInUse >= queue.m_capacity) {
                    if (queue.m_capacity == 0)
                        queue.FUN_00a222a0(8);
                    else
                        queue.FUN_00a222a0(queue.m_capacity * 2);
                }
                if (queue.m_head == 0)
                    queue.m_head = queue.m_capacity;
                queue.m_head--;
                queue.m_data[queue.m_head] = *jobInOut;
                queue.m_elementsInUse++;
            } else {
                Sa21d70_Queue& queue = data->m_jobQueue[queueIndexOfNewJob];
                if (queue.m_elementsInUse >= queue.m_capacity) {
                    if (queue.m_capacity == 0)
                        queue.FUN_00a222a0(8);
                    else
                        queue.FUN_00a222a0(queue.m_capacity * 2);
                }
                if (queue.m_tail == queue.m_capacity)
                    queue.m_tail = 0;
                queue.m_data[queue.m_tail] = *jobInOut;
                queue.m_tail++;
                queue.m_elementsInUse++;
            }
            data->m_numActiveJobs--;
        }

        int noJobFound;
        int numQueues = m_queueSets[threadType].m_numQueues;
        for (int i = 0; i < numQueues; i++) {
            Sa21d70_Queue& queue = data->m_jobQueue[m_queueSets[threadType].m_queueIndices[i]];
            if (queue.m_elementsInUse != 0) {
                int head = queue.m_head;
                job = queue.m_data[head];
                queue.m_head = head + 1;
                if (queue.m_head == queue.m_capacity)
                    queue.m_head = 0;
                queue.m_elementsInUse--;
                if (m_popJobFunc(*this, data, job, *jobInOut) == 1) {
                    if (queue.m_elementsInUse >= queue.m_capacity) {
                        if (queue.m_capacity == 0)
                            queue.FUN_00a222a0(8);
                        else
                            queue.FUN_00a222a0(queue.m_capacity * 2);
                    }
                    if (queue.m_head == 0)
                        queue.m_head = queue.m_capacity;
                    queue.m_head--;
                    queue.m_data[queue.m_head] = job;
                    queue.m_elementsInUse++;
                }
                data->m_numActiveJobs++;
                noJobFound = 0;
                goto searched;
            }
        }
        noJobFound = 1;
    searched:
        isFirstTime = false;

        if (!noJobFound) {
            if (data->m_jobQueue[0].m_elementsInUse + data->m_jobQueue[1].m_elementsInUse) {
                if (data->m_numThreadsWaitingSpecial) {
                    data->m_numThreadsWaitingSpecial--;
                    Sa21d70_Semaphore::FUN_009b4a80(m_specialSemaphore, 1);
                } else if (data->m_numThreadsWaiting) {
                    data->m_numThreadsWaiting--;
                    Sa21d70_Semaphore::FUN_009b4a80(m_semaphore, 1);
                }
            }
            FUN_00a213f0(&job);
            Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
            Sa21d70_TimerCommand* h = mon->m_end;
            if (h < mon->m_capacityMinusEpsilon) {
                h->m_name = "Et";
                h->setTime();
                mon->m_end = h + 1;
            }
            return 0;
        }

        if (data->m_numActiveJobs == 0 && data->m_jobQueue[1].m_elementsInUse + data->m_jobQueue[0].m_elementsInUse == 0) {
            FUN_00a21410(data);
            FUN_00a213f0(&job);
            Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
            Sa21d70_TimerCommand* h = mon->m_end;
            if (h < mon->m_capacityMinusEpsilon) {
                h->m_name = "Et";
                h->setTime();
                mon->m_end = h + 1;
            }
            return 3;
        }

        if (waitStatus == 1) {
            FUN_00a213f0(&job);
            Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
            Sa21d70_TimerCommand* h = mon->m_end;
            if (h < mon->m_capacityMinusEpsilon) {
                h->m_name = "EtGetNextJob";
                h->setTime();
                mon->m_end = h + 1;
            }
            return 1;
        }

        if (threadType != 2) {
            data->m_numThreadsWaiting++;
            FUN_00a213f0(&job);
            {
                Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
                Sa21d70_TimerCommand* h = mon->m_end;
                if (h < mon->m_capacityMinusEpsilon) {
                    h->m_name = "TtWaitForSignal";
                    h->setTime();
                    mon->m_end = h + 1;
                }
            }
            m_semaphore->FUN_009b4a40();
            {
                Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
                Sa21d70_TimerCommand* h = mon->m_end;
                if (h < mon->m_capacityMinusEpsilon) {
                    h->m_name = "Et";
                    h->setTime();
                    mon->m_end = h + 1;
                }
            }
        } else {
            data->m_numThreadsWaitingSpecial++;
            FUN_00a213f0(&job);
            {
                Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
                Sa21d70_TimerCommand* h = mon->m_end;
                if (h < mon->m_capacityMinusEpsilon) {
                    h->m_name = "TtWaitForSignal";
                    h->setTime();
                    mon->m_end = h + 1;
                }
            }
            m_specialSemaphore->FUN_009b4a40();
            {
                Sa21d70_MonitorStream* mon = (Sa21d70_MonitorStream*)FUN_00d9b080(DAT_0116913c);
                Sa21d70_TimerCommand* h = mon->m_end;
                if (h < mon->m_capacityMinusEpsilon) {
                    h->m_name = "Et";
                    h->setTime();
                    mon->m_end = h + 1;
                }
            }
        }
    }
}
}   // namespace f3m_00a21d70

// @f3 0x00a398e0 (community match, verified in this file)
extern double FUN_00e86068, FUN_00e86060, FUN_00e86050, FUN_00e86048;
extern float FUN_00e86058;
namespace f3m_00a398e0 {
struct __declspec(align(16)) ZVec { float x,y,z,w; };
struct ZRecord { ZVec pos; ZVec attr; ZVec extra; };
struct ZSelect {
 ZRecord points[5];
 int FUN_00a398e0();
};
inline ZVec operator-(const ZVec& a,const ZVec& b) { ZVec r; r.x=a.x-b.x; r.y=a.y-b.y; r.z=a.z-b.z; return r; }
inline float LengthSqr(const ZVec& a) { float x=a.x; float y=a.y; float z=a.z; return x*x+y*y+z*z; }
inline ZVec Cross(const ZVec& a,const ZVec& b) { ZVec r; r.x=a.y*b.z-a.z*b.y; r.y=a.z*b.x-a.x*b.z; r.z=a.x*b.y-a.y*b.x; return r; }
// pdb: hkGskManifold_findRedundant5thPoint | hkpGskManifoldUtil.obj | fnv360_0822_debug, objrun, medium
int ZSelect::FUN_00a398e0() {
 float maximum=0.0f;
 float minimum=3.40282e+38f;
 int first=0;
 int second=0;
 int selected[5]={0,0,0,0,0};
 float d[4];
 int i;
 for(i=0;i<4;i++) {
  ZVec v=points[4].pos-points[i].pos;
  d[i]=LengthSqr(v);
  if(d[i]>maximum) { maximum=d[i]; first=i; }
  if(d[i]<minimum) { minimum=d[i]; second=i; }
 }
 float height=points[4].attr.w-points[second].attr.w;
 selected[first]=1;
 maximum*=FUN_00e86068;
 second=4;
 ZRecord* start=&points[first];
 for(i=0;i<5;i++) {
  if(!selected[i]) {
   ZVec v=start->pos-points[i].pos;
   float metric=LengthSqr(v);
   if(metric>maximum) { maximum=metric; second=i; }
  }
 }
 selected[second]=1;
 int third=0;
 ZVec edge=start->pos-points[second].pos;
 maximum=0.0f;
 for(i=0;i<5;i++) {
  if(!selected[i]) {
   ZVec v=Cross(points[i].pos-start->pos,edge);
   float metric=LengthSqr(v);
   if(metric>maximum) { maximum=metric; third=i; }
  }
 }
 selected[third]=1;
 second=0;
 start=&points[third];
 maximum=0.0f;
 for(i=0;i<5;i++) {
  if(!selected[i]) {
   ZVec v=start->pos-points[i].pos;
   float metric=LengthSqr(v);
   if(metric>maximum) { maximum=metric; second=i; }
  }
 }
 selected[second]=1;
 if(!selected[4] && height<0.0f && minimum<FUN_00e86060*height*height) {
  float d0=d[0],d1=d[1],d2=d[2],d3=d[3];
  float best=FUN_00e86058;
  first=4;
  height=points[4].attr.w;
  maximum=points[0].attr.w-height;
  float sq0=maximum*maximum;
  maximum=sq0+FUN_00e86050;
  if(maximum>FUN_00e86048*d0) { best=maximum/(d0+FUN_00e86050); first=0; }
  maximum=points[1].attr.w-height;
  float sq1=maximum*maximum;
  maximum=sq1+FUN_00e86050;
  if(maximum>best*d1) { best=maximum/(d1+FUN_00e86050); first=1; }
  maximum=points[2].attr.w-height;
  float sq2=maximum*maximum;
  maximum=sq2+FUN_00e86050;
  if(maximum>best*d2) { best=maximum/(d2+FUN_00e86050); first=2; }
  maximum=points[3].attr.w-height;
  float sq3=maximum*maximum;
  maximum=sq3+FUN_00e86050;
  if(maximum>best*d3) { best=maximum/(d3+FUN_00e86050); first=3; }
  return first;
 }
 for(i=0;i<5;i++) if(!selected[i]) return i;
 return 0;
}
}   // namespace f3m_00a398e0

// @f3 0x00a2d4d0 (community match, verified in this file)
namespace f3m_00a2d4d0 {
namespace Copya2d4d0 {
struct Object {float value00,value04,value08,value0c,value10,value14,value18,value1c,value20;int value24;float value28;int value2c,value30;Object* FUN_00a2d4d0(const Object*);};
// pdb: hkpMoppAabbCastVirtualMachineQueryInt::operator= | hkpMoppAabbCastVirtualMachine.obj | tesv_win, call_gap_sim, low
Object* Object::FUN_00a2d4d0(const Object* source){value00=source->value00;value04=source->value04;value08=source->value08;value0c=source->value0c;value10=source->value10;value14=source->value14;value18=source->value18;value1c=source->value1c;value20=source->value20;value24=source->value24;value28=source->value28;value2c=source->value2c;value30=source->value30;return this;}
}
}   // namespace f3m_00a2d4d0

// @f3 0x00a2d400 (community match, verified in this file)
namespace f3m_00a2d400 {
namespace Transform344 {
struct __declspec(align(16)) Vec{float x,y,z,w;};struct Input{Vec position,rotation;int first,second;};struct Output{Vec position,rotation;int first,second;};struct Child{virtual void v0();virtual void apply(const Output&);float result;};
struct Owner{int unk00;float result;int unk08,unk0c;Vec offset;Child* child;void FUN_00a2d400(const Input&);};void Owner::FUN_00a2d400(const Input& in){float scale=in.rotation.w;Output out;out.first=in.second;out.second=in.first;out.position.x=offset.x*scale+in.position.x;out.position.y=offset.y*scale+in.position.y;out.position.z=offset.z*scale+in.position.z;out.position.w=offset.w*scale+in.position.w;out.rotation.x=-in.rotation.x;out.rotation.y=-in.rotation.y;out.rotation.z=-in.rotation.z;out.rotation.w=in.rotation.w;child->apply(out);result=child->result;}
}
}   // namespace f3m_00a2d400

// @f3 0x00a34a10 (community match, verified in this file)
namespace f3m_00a34a10 {
namespace f3m_00a34a10 {

struct Vector4_a34a10 {
    float x, y, z, w;
};

struct Rotation_a34a10 {
    Vector4_a34a10 col0;
    Vector4_a34a10 col1;
    Vector4_a34a10 col2;
};

struct Transform_a34a10 {
    Rotation_a34a10 rotation;
    Vector4_a34a10 translation;
    void FUN_00925300(const Transform_a34a10& a, const Transform_a34a10& b);
};

struct Shape_a34a10 {
    int unk00; int unk04; int unk08; int unk0c;
    float radius;
};

struct CdBody_a34a10 {
    const Shape_a34a10* shape;
    int unk04;
    const Transform_a34a10* motion;
};

struct Input_a34a10;

struct Solver_a34a10 {
    void hkpGsk_getClosestFeature(const Shape_a34a10* a, const Shape_a34a10* b, const Transform_a34a10& aTb, Vector4_a34a10& normal);
};

// pdb: hkSweptTransformUtil::lerp2 | hkSweptTransformUtil.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkpGskBaseAgent::calcSeparatingNormal)
// pdb params: sweptTrans, t, transformOut
void __cdecl FUN_00a34a10(const CdBody_a34a10& bodyA, const CdBody_a34a10& bodyB, const Input_a34a10& input,
                          Solver_a34a10* solver, Vector4_a34a10& separatingNormal)
{
    const Shape_a34a10* shapeA = bodyA.shape;
    const Shape_a34a10* shapeB = bodyB.shape;

    __declspec(align(16)) Transform_a34a10 aTb;
    aTb.FUN_00925300(*bodyA.motion, *bodyB.motion);

    __declspec(align(16)) Vector4_a34a10 normal;
    solver->hkpGsk_getClosestFeature(shapeA, shapeB, aTb, normal);

    const Rotation_a34a10& r = bodyA.motion->rotation;
    separatingNormal.x = r.col0.x * normal.x + r.col1.x * normal.y + r.col2.x * normal.z;
    separatingNormal.y = r.col0.y * normal.x + r.col1.y * normal.y + r.col2.y * normal.z;
    separatingNormal.z = r.col0.z * normal.x + r.col1.z * normal.y + r.col2.z * normal.z;
    separatingNormal.w = 0.0f;
    separatingNormal.w = normal.w - shapeA->radius - shapeB->radius;
}
}
}   // namespace f3m_00a34a10

// @f3 0x00a3afd0 (community match, verified in this file)
namespace f3m_00a3afd0 {
namespace Small495 {
struct Record {float x,y,z,w,a,b,c,time;};
struct Owner {int unk00;float time;bool active;int unk0c;Record record;void FUN_00a3afd0(const Record*);};
void Owner::FUN_00a3afd0(const Record* p){if(!active || p->time<record.time){active=true;record.x=p->x;record.y=p->y;record.z=p->z;record.w=p->w;record.a=p->a;record.b=p->b;record.c=p->c;record.time=p->time;time=p->time;}}
}

}   // namespace f3m_00a3afd0

// @f3 0x00a2a560 (community match, verified in this file)
#include <new>
extern unsigned long DAT_010f3170;
namespace f3m_00a2a560 {
namespace f3m_00a2a560 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct FreeBlock_a2a560 { FreeBlock_a2a560* next; };

struct ThreadMemory_a2a560 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94;
    FreeBlock_a2a560* free98;
    int count9c;
    void* FUN_008f6800(int size, int tag);
    void* Allocate12()
    {
        FreeBlock_a2a560* block = free98;
        if (block) {
            count9c--;
            free98 = block->next;
            return block;
        }
        return FUN_008f6800(0xc, 0x1f);
    }
};

struct Entry_a2a560 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    int unk18;
    Entry_a2a560() : unk00(0) {}
};

struct Array_a2a560 {
    Entry_a2a560** data;
    int size;
    int capacityAndFlags;
};

void __cdecl FUN_00901e90(Array_a2a560* array, int capacity, int elementSize);
void __cdecl FUN_00901f10(Array_a2a560* array, int elementSize);

// pdb: hkAgent1nMachine_Create | hkpAgent1nMachine.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: agentTrack
void __cdecl FUN_00a2a560(Array_a2a560* array)
{
    array->size = 0;
    int capacity = array->capacityAndFlags & 0x3fffffff;
    if (capacity < 4) {
        int doubled = capacity * 2;
        FUN_00901e90(array, doubled > 4 ? doubled : 4, 4);
    }
    if (array->size == (array->capacityAndFlags & 0x3fffffff))
        FUN_00901f10(array, 4);
    array->size++;
    ThreadMemory_a2a560* memory = (ThreadMemory_a2a560*)DAT_00d9b080(DAT_010f3170);
    Entry_a2a560* entry = new (memory->Allocate12()) Entry_a2a560;
    array->data[0] = entry;
    entry->unk13 = 0x10;
    entry->unk10 = 1;
    entry->unk18 = -1;
    entry->unk14 = -1;
    entry->unk00 = 0x10;
}
}
}   // namespace f3m_00a2a560

// @f3 0x00a26030 (community match, verified in this file)
namespace f3m_00a26030 {
namespace Dispatcha26030 {
struct Object;struct Context;
typedef void*(__cdecl* Callback)(Object*,Object*,Context*,void*);
struct Dispatch {Callback call;int unk04,unk08,unk0c,unk10;};
struct Tables {
int unk000;int unk004;int unk008;int unk00c;int unk010;int unk014;int unk018;int unk01c;int unk020;int unk024;int unk028;int unk02c;int unk030;int unk034;int unk038;int unk03c;int unk040;int unk044;int unk048;int unk04c;int unk050;int unk054;int unk058;int unk05c;int unk060;int unk064;int unk068;int unk06c;int unk070;int unk074;int unk078;int unk07c;int unk080;int unk084;int unk088;int unk08c;int unk090;int unk094;int unk098;int unk09c;int unk0a0;int unk0a4;int unk0a8;int unk0ac;int unk0b0;int unk0b4;int unk0b8;int unk0bc;int unk0c0;int unk0c4;int unk0c8;int unk0cc;int unk0d0;int unk0d4;int unk0d8;int unk0dc;int unk0e0;int unk0e4;int unk0e8;int unk0ec;int unk0f0;int unk0f4;int unk0f8;int unk0fc;int unk100;int unk104;int unk108;int unk10c;int unk110;int unk114;int unk118;int unk11c;int unk120;int unk124;int unk128;int unk12c;int unk130;int unk134;int unk138;int unk13c;int unk140;int unk144;int unk148;int unk14c;int unk150;int unk154;int unk158;int unk15c;int unk160;int unk164;int unk168;int unk16c;int unk170;int unk174;int unk178;int unk17c;int unk180;int unk184;int unk188;int unk18c;int unk190;int unk194;int unk198;int unk19c;
unsigned char first[32][32];unsigned char second[32][32];Dispatch entries[256];};
struct Type {int unk00,unk04,unk08;unsigned index;};struct Object {Type* type;};
struct Context {Tables* tables;int unk04,unk08,unk0c;int alternate;};
struct Input {Object* left;Object* right;Context* context;void* extra;};
struct Header {unsigned char type,unk01,flags;};
struct Output {void* result;int unk04,unk08,unk0c;};
// pdb: hkAgent3Bridge::create | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
Output* hkAgent3Bridge_create(Input* input,Header* header,Output* output){Object* right=input->right;Context* context=input->context;void* extra=input->extra;Object* left=input->left;int l=left->type->index;Tables* tables=context->tables;int r=right->type->index;unsigned index=(context->alternate?tables->second:tables->first)[l][r];Callback callback=tables->entries[index].call;output->result=callback(left,right,context,extra);header->type=6;header->flags=0xff;return output+1;}
}
}   // namespace f3m_00a26030

// @f3 0x00a25c00 (community match, verified in this file)
namespace worker25c {
typedef unsigned long DWORD25C;

struct LockObject25C;

struct TlsState25C {
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
    LockObject25C* unk58;
    int unk5C;
    LockObject25C* FUN_008f6800(int size, int flags);
};

struct LockObject25C {
    LockObject25C* unk00;
    int lockCount;
    int recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long criticalSpinCount;
    int owner;
    int count;
    int userSpinCount;
    LockObject25C* previous;
    LockObject25C* next;
};

struct CriticalSection25C {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void FUN_00908a00();
};

struct Cleanup25C {
    int unk00;
    int unk04;
    void FUN_0098b600();
};

struct Target25C {
    int unk00;
    int unk04;
    Cleanup25C cleanup;
    LockObject25C* unk10;
    void FUN_00a25c00(int spinCount);
};

extern DWORD25C DAT_010f3170;
extern LockObject25C DAT_011692e8;
extern int DAT_01169300;
extern int DAT_01169304;
extern LockObject25C* DAT_01169310;

extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
extern int (__stdcall* const DAT_00d9b1ac)(void*, unsigned long);

static __forceinline LockObject25C* CreateLock25C(int spinCount)
{
        TlsState25C* state = (TlsState25C*)DAT_00d9b080(DAT_010f3170);
        LockObject25C* lock = state->unk58;
        if (lock != 0) {
            state->unk5C--;
            state->unk58 = lock->unk00;
        } else {
            lock = state->FUN_008f6800(4, 0x15);
        }
        if (lock != 0) {
            LockObject25C* current;
            lock->userSpinCount = spinCount;
            lock->previous = 0;
            lock->next = 0;
            ((CriticalSection25C*)&DAT_011692e8)->FUN_00908a00();
            lock->next = DAT_01169310;
            if (lock->next != 0)
                lock->next->previous = lock;
            lock->previous = (LockObject25C*)&DAT_011692e8;
            DAT_01169310 = lock;
            DAT_01169300 = -1;
            DAT_01169304 = -1;
            DAT_00d9b0a0(&DAT_011692e8);
            DAT_00d9b1ac(lock, spinCount);
            lock->owner = -1;
            lock->count = -1;
        } else {
            lock = 0;
        }
        return lock;
}
// pdb: hkpBroadPhase::~hkpBroadPhase | hkpBroadPhase.obj | fnv360_0721_beta, objrun, medium
void Target25C::FUN_00a25c00(int spinCount)
{
    if (!unk10) {
        unk10 = CreateLock25C(spinCount);
        cleanup.FUN_0098b600();
    }
}
}

// @f3 0x00a3b030 (community match, verified in this file)
extern const float DAT_00e7c758;
namespace f3m_00a3b030 {
namespace f3m_00a3b030 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void setSub4(const Vec4& a, const Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    void setNeg4(const Vec4& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
};
struct CdVertex : Vec4 { short getId() const { return *(const short*)&w; } };
struct Transform {
    Vec4 col0, col1, col2, trans;
};
__forceinline void SetTransformedPos(Vec4& r, const Transform& t, const Vec4& v)
{
    float v2=v.z;float v1=v.y;float v0=v.x;
    r.x = t.col0.x * v0 + t.col1.x * v1 + t.col2.x * v2 + t.trans.x;
    r.y = t.col1.y * v1 + t.col0.y * v0 + t.col2.y * v2 + t.trans.y;
    r.z = t.col0.z * v0 + t.col1.z * v1 + t.col2.z * v2 + t.trans.z;
    r.w = 0.0f;
}
__forceinline void SetRotatedInverseDir(Vec4& r, const Transform& t, const Vec4& v)
{
    float v2=v.z;float v1=v.y;float v0=v.x;
    r.x = t.col0.x * v0 + t.col0.y * v1 + t.col0.z * v2;
    r.y = t.col1.y * v1 + t.col1.x * v0 + t.col1.z * v2;
    r.z = t.col2.x * v0 + t.col2.y * v1 + t.col2.z * v2;
    r.w = 0.0f;
}
struct ConvexShape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20();
    virtual int getMaxDim() const;
    virtual void v28(); virtual void v2c();
    virtual void getSupportingVertex(const Vec4& dir, CdVertex& out) const;
    virtual void convertVertexIdsToVertices(const unsigned short* ids, int num, CdVertex* out) const;
};
struct GskCache {
    short m_vertices[4];
    unsigned char m_dimA;
    unsigned char m_dimB;
    unsigned char m_maxDimA : 4;
    unsigned char m_maxDimB : 4;
    unsigned char m_gskFlags;
    void hkpGskCache_init(const ConvexShape* shapeA, const ConvexShape* shapeB, const Transform& aTb);
};

// pdb: hkpGskCache::init | hkpGskCache.obj | fnv360_0822_retail, caller + bridge(call_seq|callee_sim) + skyrim(call_seq), high
void GskCache::hkpGskCache_init(const ConvexShape* shapeA, const ConvexShape* shapeB, const Transform& aTb)
{
    CdVertex vA, vB;
    unsigned short id = 0;
    shapeA->convertVertexIdsToVertices(&id, 1, &vA);
    shapeB->convertVertexIdsToVertices(&id, 1, &vB);
    Vec4 dir;
    CdVertex sA;
    {
        Vec4 pB;
        SetTransformedPos(pB, aTb, vB);
        dir.setSub4(pB, vA);
        shapeA->getSupportingVertex(dir, sA);
        dir.setSub4(pB, sA);
    }
    CdVertex sB;
    {
        Vec4 dirB;
        SetRotatedInverseDir(dirB, aTb, dir);
        dirB.x = -dirB.x; dirB.y = -dirB.y; dirB.z = -dirB.z; dirB.w = DAT_00e7c758;
        shapeB->getSupportingVertex(dirB, sB);
    }
    m_vertices[1] = sB.getId();
    m_vertices[0] = sA.getId();
    m_vertices[2] = 0;
    m_vertices[3] = 0;
    m_dimA = 1;
    m_dimB = 1;
    int a = shapeA->getMaxDim();
    int b = shapeB->getMaxDim();
    m_maxDimA = a > 3 ? 15 : a;
    m_maxDimB = b > 3 ? 15 : b;
    m_gskFlags = 0;
}
}

}   // namespace f3m_00a3b030

// @f3 0x00a288a0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern const char DAT_00e2c5c8[];
namespace f3m_00a288a0 {
// Lists a directory: builds "<path>/*", checks the path is a directory, then walks the entries
// and adds each name (except "." and "..") to the directory list or the file list of the output.
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* name) throw();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index) throw();

namespace N00a288a0
{
struct FindData
{
    unsigned long dwFileAttributes;
    unsigned long ftCreationTime[2];
    unsigned long ftLastAccessTime[2];
    unsigned long ftLastWriteTime[2];
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    // Fake match: the two name buffers are character arrays (260 and 14 characters). They are declared
    // as word arrays of the same total size so that /GS does not add a stack cookie, which the original lacks.
    unsigned int cFileName[65];
    unsigned int cAlternateFileName[4];
};

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* name, FindData* data) throw();
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* find, FindData* data) throw();
extern "C" __declspec(dllimport) int __stdcall FindClose(void* find) throw();

int __cdecl FUN_009233f0(const char* s) throw();
void __cdecl FUN_00901e90(void* array, int count, int elemSize) throw();
void __cdecl FUN_009234e0(char* dst, const char* src, int n) throw();
void __cdecl FUN_00901f10(void* array, int elemSize) throw();
int __cdecl hkString_strCmp(const char* a, const char* b) throw();
char* __cdecl FUN_00923640(const char* s) throw();

struct ThreadMemory
{
    void FUN_008f6d90(void* p, int size, int cls) throw();
};

inline ThreadMemory& GetThreadMemory()
{
    return *(ThreadMemory*)TlsGetValue(DAT_010f3170);
}

template <class T> inline void DeallocateChunk(T*& p, int n, int cls)
{
    GetThreadMemory().FUN_008f6d90(p, n * sizeof(T), cls);
}

template <class T> struct Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~Array()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            DeallocateChunk<T>(m_data, getCapacity(), 0x17);
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    int getSize() const { return m_size; }
    T* begin() { return m_data; }
    T& operator[](int i) { return m_data[i]; }
    void reserve(int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    void pushBack(const T& e)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = e;
        m_size++;
    }
};

struct Listing
{
    Array<char*> m_dirs;
    Array<char*> m_files;
    void addDirectory(const char* name) { m_dirs.pushBack(FUN_00923640(name)); }
    void addFile(const char* name) { m_files.pushBack(FUN_00923640(name)); }
};

extern void (__cdecl* const DAT_010611a0)(const char*, Array<char>&);
// Fake match: this wrapper exists only to mark the call through the pointer as non-throwing, so that
// /EHsc builds no unwind frame for the pattern array, which the original lacks.
inline void ConvertPath(const char* path, Array<char>& buffer) throw()
{
    DAT_010611a0(path, buffer);
}
}
using namespace N00a288a0;

int FUN_00a288a0(const char* basePath, Listing& listingOut)
{
    int len = FUN_009233f0(basePath);
    Array<char> pattern;
    if (len > 0)
    {
        pattern.setSize(len + 3);
        FUN_009234e0(pattern.begin(), basePath, len);
        pattern[len] = 0;
        char* end = &pattern[len];
        if (end[-1] != '/')
            *end++ = '/';
        *end++ = '*';
        *end = 0;
        ConvertPath(pattern.begin(), pattern);
    }
    const char* path = pattern.getSize() ? pattern.begin() : basePath;
    bool isDir = (GetFileAttributesA(path) >> 4) & 1;
    if (!isDir)
        return 1;
    FindData fd;
    void* find = FindFirstFileA(path, &fd);
    bool more = find != (void*)-1;
    while (more)
    {
        if (hkString_strCmp((const char*)fd.cFileName, ".") && hkString_strCmp((const char*)fd.cFileName, DAT_00e2c5c8))
        {
            bool isDirectory = (fd.dwFileAttributes >> 4) & 1;
            if (isDirectory)
                listingOut.addDirectory((const char*)fd.cFileName);
            else
                listingOut.addFile((const char*)fd.cFileName);
        }
        more = FindNextFileA(find, &fd) != 0;
    }
    FindClose(find);
    return 0;
}
}   // namespace f3m_00a288a0

// @f3 0x00a284b0 (community match, verified in this file)
#include <string.h>
extern unsigned int DAT_00e31f14;
extern char DAT_00e31edc[];
extern int DAT_00e857e4[];
extern char DAT_00e8599c[];
extern char* DAT_01064bf8[];
extern const char DAT_00e13194[];
extern const char DAT_00e85918[];
extern const char DAT_00e85818[];
extern const char DAT_00e85898[];
namespace f3m_00a284b0 {

extern "C" int FUN_00c01ef0(const char* a, const char* b);
extern "C" char* FUN_00c07c60(char* dst, const char* src, unsigned int n);
extern "C" void FUN_009231a0(const char* fmt, ...);
int FUN_00a7dee0();


namespace f3m_00a284b0 {
static __declspec(noinline) char* FUN_00a28480(char* p, int c)
{
    if (*p == (char)c)
        return p;
    do {
        if (*p == 0)
            return 0;
        p++;
    } while (*p != (char)c);
    return p;
}


}

// pdb: hkpProcessFlyingColors | hkpSolverCheck.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: flyingColors
bool FUN_00a284b0(int mode)
{
    using namespace f3m_00a284b0;
    bool hi = (DAT_00e31f14 >> 31) & 1;
    for (int i = 0; i < 12; i++) {
        int key = DAT_00e857e4[i];
        char* p = FUN_00a28480(DAT_00e31edc, '.');
        if (!p)
            break;
        if (FUN_00c01ef0(p, DAT_00e13194) && (mode == 1 || mode == 2)) {
            int buf[64];
            char* s = (char*)buf;
            *s = 0;
            FUN_00c07c60(s, DAT_00e8599c,
                strlen(DAT_00e8599c) < 254 - strlen(s) ? strlen(DAT_00e8599c) : 254 - strlen(s));
            FUN_00c07c60(s, DAT_01064bf8[mode],
                strlen(DAT_00e8599c) < 254 - strlen(s) ? strlen(DAT_00e8599c) : 254 - strlen(s));
            FUN_009231a0(s);
        }
        p = FUN_00a28480(p + 1, '.');
        if (!p)
            break;
        p++;
        if (hi) {
            int v = (DAT_00e31f14 & 0x7fffffff) ^ key;
            int t = FUN_00a7dee0();
            if (v > t && v - t < 0x209a5ad) {
                if ((mode == 1 || mode == 2) && i >= 6 && i <= 9) {
                    FUN_009231a0(DAT_00e85918);
                    return false;
                }
                if (mode == 4 || i < 10)
                    return true;
                FUN_009231a0(DAT_00e85818);
                return false;
            }
        } else {
            int h = 0;
            while (*p) {
                p++;
                h = h * 23 + *p;
            }
            if (DAT_00e31f14 == ((h ^ key) & 0x7fffffff)) {
                if ((mode == 1 || mode == 2) && i >= 6 && i <= 9) {
                    FUN_009231a0(DAT_00e85918);
                    return false;
                }
                if (mode == 4 || i < 10)
                    return true;
                FUN_009231a0(DAT_00e85818);
                return false;
            }
        }
    }
    FUN_009231a0(DAT_00e85898);
    return false;
}
}   // namespace f3m_00a284b0

// @f3 0x00a3bb90 (community match, verified in this file)
extern const float* clm_f39c9da5b9f74e4f8b95_input;
extern float clm_f39c9da5b9f74e4f8b95_bits;
extern int clm_f39c9da5b9f74e4f8b95_output;
namespace f3m_00a3bb90 {
// pdb: getMaxPlaneMask3 | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) unsigned short FUN_00a3bb90(const float* p, float bits) {
    unsigned int a = p[0] < 0.0f ? 8 : 0;
    unsigned int b = p[1] < 0.0f ? 4 : 0;
    unsigned int c = p[2] < 0.0f ? 2 : 0;
    unsigned int d = p[3] < 0.0f ? 1 : 0;
    unsigned short mask = a | b | c | d; mask &= 14; mask <<= 4; return mask | ((*(unsigned int*)&bits >> 28) & 8);
}
void clm_f39c9da5b9f74e4f8b95_call() {
    clm_f39c9da5b9f74e4f8b95_output = FUN_00a3bb90(clm_f39c9da5b9f74e4f8b95_input, clm_f39c9da5b9f74e4f8b95_bits);
}
}   // namespace f3m_00a3bb90

// @f3 0x00a27c00 (community match, verified in this file)
extern const unsigned char DAT_01065c10[];
namespace f3m_00a27c00 {

namespace rows_a27c00 {

struct ComponentView { const float& value; ComponentView(const float& f) : value(f) {} };
__forceinline float SumXComponents(ComponentView x, float y, float z) { return x.value+y+z; }
struct __declspec(align(16)) Vector3 {
    float x, y, z;
    __forceinline void SetMul(const Vector3& a, const Vector3& b)
    { x = static_cast<const volatile float&>(a.x)*b.x; y = a.y*b.y; z = a.z*b.z; }
    __forceinline void SetMulSecondRow(const Vector3& body, const Vector3& coefficient)
    {
        x = static_cast<const volatile float&>(coefficient.x)*body.x;
        y = body.y*coefficient.y;
        z = body.z*coefficient.z;
    }    __forceinline void SetSub(const Vector3& a, const Vector3& b)
    { x = a.x-b.x; y = a.y-b.y; z = a.z-b.z; }
    __forceinline void Mul(const Vector3& factor)
    { x = factor.x*x; y = factor.y*y; z = factor.z*z; }
    __forceinline void Add(const Vector3& value)
    { x = value.x+x; y = value.y+y; z = value.z+z; }
    __forceinline float SumX() const { return SumXComponents(ComponentView(x),y,z); }
    __forceinline float SumY() const { return y+x+z; }
};

struct SchemaHeader {
    unsigned int unk00;
    unsigned short bodyA;
    unsigned short bodyB;
    unsigned int unk08;
    unsigned int unk0C;
};

struct Accumulator {
    int unk00, unk04, unk08, unk0C;
    Vector3 linear;
    Vector3 angular;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
};

struct JacobianRow {
    Vector3 linear;
    Vector3 angularA;
    Vector3 angularB;
};

struct RelativeJump {
    int unk00;
    int offset;
};

typedef char HeaderSize[(sizeof(SchemaHeader) == 0x10) ? 1 : -1];
typedef char AccumulatorSize[(sizeof(Accumulator) == 0x80) ? 1 : -1];
typedef char RowSize[(sizeof(JacobianRow) == 0x30) ? 1 : -1];

__forceinline void FormRow(Vector3& contribution, const JacobianRow& row,
                           const Accumulator& bodyA, const Accumulator& bodyB)
{
    Vector3 difference;
    Vector3 angularB;
    contribution.SetMul(bodyA.angular, row.angularA);
    difference.SetSub(bodyA.linear, bodyB.linear);
    angularB.SetMul(bodyB.angular, row.angularB);
    difference.Mul(row.linear);
    contribution.Add(angularB);
    contribution.Add(difference);
}

__forceinline float SecondPairRowY(const JacobianRow& row, const Accumulator& bodyA,
                                   const Accumulator& bodyB)
{
    Vector3 contribution;
    Vector3 difference;
    Vector3 angularB;
    contribution.SetMulSecondRow(bodyA.angular, row.angularA);
    difference.SetSub(bodyA.linear, bodyB.linear);
    angularB.SetMul(bodyB.angular, row.angularB);
    difference.Mul(row.linear);
    contribution.Add(angularB);
    contribution.Add(difference);
    return contribution.SumY();
}
__forceinline float RowXFirst(const JacobianRow& row, const Accumulator& a,
                              const Accumulator& b)
{
    Vector3 contribution;
    FormRow(contribution, row, a, b);
    return contribution.SumX();
}

__forceinline float RowYFirst(const JacobianRow& row, const Accumulator& a,
                              const Accumulator& b)
{
    Vector3 contribution;
    FormRow(contribution, row, a, b);
    return contribution.SumY();
}

__forceinline float ClampPositive(double value)
{
    if (value > 0.0f)
        return 0.0f;
    return value;
}

}

int __cdecl FUN_00a27c00(const void* context,
                         const rows_a27c00::SchemaHeader* header,
                         const rows_a27c00::Accumulator* accumulators,
                         int outputCapacity, float* output)
{
    using namespace rows_a27c00;
    const Accumulator* bodyA = &accumulators[header->bodyA];
    const Accumulator* bodyB = &accumulators[header->bodyB];
    int written = 0;
    const char* cursor = reinterpret_cast<const char*>(header) + sizeof(SchemaHeader);
    int nextSingle = 1;
    int nextPair = 2;

    for (;;) {
        int opcode = *cursor;
        switch (opcode) {
        case 3: case 7: case 8: case 9: case 11:
        case 12: case 13: case 14: case 23: case 24:
        {
            char runOpcode = (char)opcode;
            do {
                cursor += DAT_01065c10[(int)*cursor];
            } while (*cursor == runOpcode);
            break;
        }
        case 2:
            cursor += reinterpret_cast<const RelativeJump*>(cursor)->offset;
            break;
        case 15: case 16: case 17: case 18:
        {
            if (nextSingle > outputCapacity)
                return written;
            ++written;
            ++nextPair;
            ++nextSingle;
            const JacobianRow& row = *reinterpret_cast<const JacobianRow*>(cursor);
            float value = RowXFirst(row, *bodyA, *bodyB);
            *output++ = ClampPositive(value);
            cursor += 0x30;
            break;
        }
        case 19: case 20:
        {
            if (nextPair > outputCapacity)
                return written;
            written += 2;
            nextPair += 2;
            nextSingle += 2;
            const JacobianRow& first = *reinterpret_cast<const JacobianRow*>(cursor);
            float value = RowYFirst(first, *bodyA, *bodyB);
            *output++ = ClampPositive(value);
            const JacobianRow& second = *reinterpret_cast<const JacobianRow*>(cursor + 0x30);
            value = SecondPairRowY(second, *bodyA, *bodyB);
            *output++ = ClampPositive(value);
            cursor += 0x70;
            break;
        }
        case 5:
        {
            if (nextSingle > outputCapacity)
                return written;
            ++written;
            ++nextPair;
            ++nextSingle;
            const JacobianRow& row = *reinterpret_cast<const JacobianRow*>(cursor);
            *output++ = RowYFirst(row, *bodyA, *bodyB);
            cursor += 0x30;
            break;
        }
        case 6:
        {
            if (nextSingle > outputCapacity)
                return written;
            ++written;
            ++nextPair;
            ++nextSingle;
            const JacobianRow& row = *reinterpret_cast<const JacobianRow*>(cursor);
            *output++ = RowYFirst(row, *bodyA, *bodyB);
            cursor += 0x40;
            break;
        }
        case 0: case 1: case 21: case 22:
            return written;
        case 4: case 10:
        default:
            break;
        }
    }
}







}   // namespace f3m_00a27c00

// @f3 0x00a3ba50 (community match, verified in this file)
extern float g_srcA[4];
extern float g_srcB[4];
extern int g_ix;
extern int g_iy;
extern unsigned char g_dst[2];
namespace f3m_00a3ba50 {
struct __declspec(align(16)) V4 { float v[4]; };

/* 4-bit sign code of the four lanes, keeping only the lane bits (0x8..0x1). */
static __forceinline int NegMask(const float* v)
{
    return (((v[0] < 0.0f) ? 8 : 0) | ((v[1] < 0.0f) ? 4 : 0)
          | ((v[2] < 0.0f) ? 2 : 0) | ((v[3] < 0.0f) ? 1 : 0)) & 0xe;
}

// pdb: setEdgeFeatureBitSetFromAxisMap | hkpBoxBoxCollisionDetection.obj | fnv360_0822_debug, objrun, medium
static __declspec(noinline) void FUN_00a3ba50(const V4* a, const V4* b,
                                              int i, int j, unsigned char* out)
{
    V4 A = *a;
    V4 B = *b;
    int na;
    int nb;

    A.v[i] = 1.0f;
    B.v[j] = 1.0f;

    na = NegMask(A.v);
    nb = NegMask(B.v);

    out[0] = (unsigned char)(((na | 1) * 16) | (unsigned char)i);
    unsigned char hi = (unsigned char)(~nb & 0xe);
    out[1] = (unsigned char)((hi << 4) + j);
}


void caller_of_FUN_00a3ba50()
{
    FUN_00a3ba50((const V4*)g_srcA, (const V4*)g_srcB, g_ix, g_iy, g_dst);
}
}   // namespace f3m_00a3ba50

// @f3 0x00a21710 (community match, verified in this file)
namespace f3m_00a21710 {
// 0x00a21710 -- D057A0 node-queue filler.
// Copies every node of a list into one of a node owner's D057A0Queues,
// either at its front or at its back, then releases the owner reference.

struct __declspec(align(16)) D057A0Element
{
    int m_iWords[0x20];             // 0x00  0x80-byte node payload
};

struct D057A0Queue
{
    D057A0Element* m_pNodes;        // 0x00
    int m_iNodeCount;               // 0x04
    int m_iBack;                    // 0x08
    int m_iFront;                   // 0x0c
    int m_iUsed;                    // 0x10

    void SetNodeCount(int iCount);

    void AddFirst(const D057A0Element& node)
    {
        if (m_iUsed >= m_iNodeCount)
        {
            if (m_iNodeCount == 0)
                SetNodeCount(8);
            else
                SetNodeCount(m_iNodeCount * 2);
        }
        if (m_iFront == m_iNodeCount)
            m_iFront = 0;
        m_pNodes[m_iFront] = node;
        ++m_iFront;
        ++m_iUsed;
    }

    void AddLast(const D057A0Element& node)
    {
        if (m_iUsed >= m_iNodeCount)
        {
            if (m_iNodeCount == 0)
                SetNodeCount(8);
            else
                SetNodeCount(m_iNodeCount * 2);
        }
        if (m_iBack == 0)
            m_iBack = m_iNodeCount;
        --m_iBack;
        m_pNodes[m_iBack] = node;
        ++m_iUsed;
    }
};

struct D057A0Owner
{
    char m_unk00[0x14];             // 0x00
    D057A0Queue m_queues[3];        // 0x14
};

struct D057A0ElementList
{
    D057A0Element** m_pNodes;       // 0x00
    int m_iCount;                   // 0x04
};

class D057A0Host
{
public:
    D057A0Owner* FUN_00a214a0(D057A0Element* pNode);
    void FUN_00a214b0(int iIndex, D057A0Owner* pOwner);
    void FUN_00a213f0(D057A0Element* pNode);

    void FUN_00a21710(D057A0ElementList* pList, int iFront, int iIndex);
};

void D057A0Host::FUN_00a21710(D057A0ElementList* pList, int iFront, int iIndex)
{
    D057A0Element node;
    D057A0Owner* pOwner = FUN_00a214a0(&node);

    int i = 0;
    for (; i < pList->m_iCount; ++i)
    {
        if (iFront == 0)
            pOwner->m_queues[iIndex].AddLast(*pList->m_pNodes[i]);
        else
            pOwner->m_queues[iIndex].AddFirst(*pList->m_pNodes[i]);

        FUN_00a214b0(iIndex, pOwner);
    }

    FUN_00a213f0(&node);
}
}   // namespace f3m_00a21710

// @f3 0x00a3e510 (community match, verified in this file)
namespace f3m_00a3e510 {
struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(const float& x) { m_real = x; }
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkQuadReal
{
    float v[4];
};

struct hkMatrix3;
struct hkTransform;


struct __declspec(align(16)) hkVector4
{
    hkQuadReal m_quad;

    __forceinline float& operator()(int i) { return m_quad.v[i]; }
    __forceinline const float& operator()(int i) const { return m_quad.v[i]; }
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& b);
    __forceinline void operator=(const hkVector4& v)
    {
        m_quad.v[0] = v.m_quad.v[0];
        m_quad.v[1] = v.m_quad.v[1];
        m_quad.v[2] = v.m_quad.v[2];
        m_quad.v[3] = v.m_quad.v[3];
    }

    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
    __forceinline void setMul4(const hkSimdReal& rs, const hkVector4& a)
    {
        float r = rs; 
        m_quad.v[0] = r * a.m_quad.v[0];
        m_quad.v[1] = r * a.m_quad.v[1];
        m_quad.v[2] = r * a.m_quad.v[2];
        m_quad.v[3] = r * a.m_quad.v[3];
    }
    __forceinline void addMul4(const hkSimdReal& rs, const hkVector4& a)
    {
        float r = rs; 
        m_quad.v[0] += r * a.m_quad.v[0];
        m_quad.v[1] += r * a.m_quad.v[1];
        m_quad.v[2] += r * a.m_quad.v[2];
        m_quad.v[3] += r * a.m_quad.v[3];
    }
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline float operator()(int r, int c) const { return getColumn(c)(r); }
};
struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_translation;
};
__forceinline void hkVector4::_setRotatedDir(const hkMatrix3& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    m_quad.v[0] = r(0,0)*b0 + r(0,1)*b1 + r(0,2)*b2;
    m_quad.v[1] = r(1,0)*b0 + r(1,1)*b1 + r(1,2)*b2;
    m_quad.v[2] = r(2,0)*b0 + r(2,1)*b1 + r(2,2)*b2;
    m_quad.v[3] = 0;
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkMatrix3& r = t.m_rotation;
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    const float x = r(0,0)*b0 + r(0,1)*b1 + r(0,2)*b2 + t.m_translation(0);
    const float y = r(1,0)*b0 + r(1,1)*b1 + r(1,2)*b2 + t.m_translation(1);
    const float z = r(2,0)*b0 + r(2,1)*b1 + r(2,2)*b2 + t.m_translation(2);
    m_quad.v[0] = x;
    m_quad.v[1] = y;
    m_quad.v[2] = z;
    m_quad.v[3] = 0;
}
struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};
struct CdPoint
{
    hkContactPoint m_contact;
    hkVector4 m_unweldedNormal;
};

struct hkBool
{
    char m_bool;
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = (char)b; }
};

struct GskKey
{
    unsigned char m_type;
    unsigned char unk01;
    unsigned short unk02;
};

struct __declspec(align(16)) GskOut
{
    hkVector4 m_pointA;
    hkVector4 m_pointB;
    hkVector4 m_dir;
    float m_distA;
    float m_distB;
    int m_dim;
};

struct __declspec(align(16)) GskWork
{
    hkVector4 m_points[4];
    void FUN_00a3b580();
};

struct GskCache
{
    int m_data;
};

struct GskAgent
{
    int unk00, unk04, unk08, unk0c, unk10;
    const hkTransform* m_transA;
    const hkTransform* m_transB;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    GskCache m_cache;

    void FUN_009cafa0();
    int FUN_00a3bc00(GskCache* cache);
    // Fake match (the FNV twin declares it the same way): noalias lets the key's slot be reused for float temps.
    __declspec(noalias) int hkpBoxBoxCollisionDetection_findClosestPoint(GskWork* work, GskKey* key, GskOut* out);
    hkBool hkpBoxBoxCollisionDetection_calculateClosestPoint(hkContactPoint& cp);
};

// pdb: hkpBoxBoxCollisionDetection::calculateClosestPoint | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, caller + bridge(call_gap|callee_sim) + skyrim(call_gap), high
hkBool GskAgent::hkpBoxBoxCollisionDetection_calculateClosestPoint(hkContactPoint& cp)
{
    hkBool result = false;
    // Fake match: four dead locals that only shift the compiler's symbol numbering; they set the x87 operand
    // order of the first lanes in the three inlined transform expansions.
    int pad0 = 1;
    int pad1 = 2;
    int pad2 = 3;
    int pad3 = 4;
    GskWork work;
    work.FUN_00a3b580();
    GskKey key;
    key.unk02 = 0;
    FUN_009cafa0();
    if (FUN_00a3bc00(&m_cache) == 0)
    {
        GskOut out;
        if (hkpBoxBoxCollisionDetection_findClosestPoint(&work, &key, &out) == 2)
        {
            result = true;
            CdPoint ccp;
            hkVector4& pos = ccp.m_contact.m_position;
            hkVector4& normal = ccp.m_contact.m_separatingNormal;
            int dim = out.m_dim;
            unsigned char type = key.m_type;
            if (dim <= 2) { pos._setTransformedPos(*m_transB, out.m_pointB); { float factor = -out.m_distA; normal.setMul4(factor, m_transA->m_rotation.getColumn(type)); } }
            else if (dim <= 6) { pos._setTransformedPos(*m_transA, out.m_pointA); { float factor = -out.m_distA; normal.setMul4(factor, m_transB->m_rotation.getColumn(type - 4)); } }
            else { pos._setTransformedPos(*m_transA, out.m_pointA); normal._setRotatedDir(m_transA->m_rotation, out.m_dir); }
            float dist = out.m_distB;
            normal(3) = dist;
            if (type > 2)
            {
                float neg = -dist;
                pos.addMul4(neg, normal);
            }
            cp.m_separatingNormal = normal;
            cp.m_position = pos;
            cp.m_separatingNormal(3) = dist;
        }
        else
        {
            result = false;
        }
    }
    return result;
}
}   // namespace f3m_00a3e510

// @f3 0x00a32540 (community match, verified in this file)
extern float DAT_00dbf91c;
namespace f3m_00a32540 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
struct Transform;
struct __declspec(align(16)) Vec {
    float x, y, z, w;
    __forceinline void setSub(const Vec& a, const Vec& b) {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void operator=(const Vec& other) {
        x = other.x; y = other.y; z = other.z; w = other.w;
    }
    __forceinline void setTP(const Transform&, const Vec&);
};
struct Transform {
    Vec x, y, z, translation;
    __forceinline Transform() {}
    __forceinline Transform(const Transform& other) {
        const Vec first(other.x), second(other.y), third(other.z), fourth(other.translation);
        x = first; y = second; z = third; translation = fourth;
    }
};

__forceinline void Vec::setTP(const Transform& t, const Vec& input) {
    float px = input.x, py = input.y, pz = input.z;
    x = ((t.x.x * px + t.y.x * py) + t.z.x * pz) + t.translation.x;
    y = ((t.x.y * px + t.y.y * py) + t.z.y * pz) + t.translation.y;
    z = ((t.x.z * px + t.y.z * py) + t.z.z * pz) + t.translation.z;
    w = 0.0f;
}

struct SolverOutput { Vec normal, unk10, unk20; };
extern int __cdecl FUN_00a7f6b0(void*, void*, const Transform*, float, Vec*, Vec*, Vec*, int, SolverOutput*);
extern void __cdecl FUN_0096f780(Vec*, Vec*, Vec*, Vec*, Vec*);

__forceinline void xformPoints(const Transform& t, const Vec* in, int n, Vec* out) {
    Transform snapshot = t;
    int index = n - 1;
    do {
        out[index].setTP(snapshot, in[index]);
    } while (--index >= 0);
}

struct Simplex {
    int countA, countB, unk08, unk0c, unk10, status, unk18, unk1c;
    Vec a[8], verticesB[8], result, axis;
    void FUN_00a30ca0();
    void hkpGsk_handlePenetration(void*, void*, const Transform*);
};

// pdb: hkpGsk::handlePenetration | hkpGsk.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void Simplex::hkpGsk_handlePenetration(void* arg1, void* arg2, const Transform* transform) {
    int count = 4;
    if (countB >= 3) {
        if (countB > 3)
            a[3] = a[0];
        else if (countA > 1) {
            a[3] = a[1];
            verticesB[4 + 3] = verticesB[4 + 0];
            verticesB[3] = verticesB[0];
        } else
            count = 3;
        a[1] = a[0];
        a[2] = a[0];
    } else if (countA >= 3) {
        if (countA > 3) {
            verticesB[4 + 3] = verticesB[4 + 0];
            verticesB[3] = verticesB[0];
        } else if (countB > 1) {
            a[3] = a[0];
            verticesB[4 + 3] = verticesB[4 + 1];
            verticesB[3] = verticesB[1];
        } else
            count = 3;
        verticesB[4 + 1] = verticesB[4 + 0];
        verticesB[1] = verticesB[0];
        verticesB[4 + 2] = verticesB[4 + 0];
        verticesB[2] = verticesB[0];
    } else {
        count = 1;
    }

    Vec differences[4];
    SolverOutput output;
    for (int i = 0; i < count; ++i)
        differences[i].setSub(a[i], verticesB[i]);

    int hit = FUN_00a7f6b0(arg1, arg2, transform, DAT_00dbf91c, a, verticesB + 4,
                         differences, count, &output);
    if (count == 1 || hit == 1) {
        countA = 1;
        countB = 1;
        goto finished;
    }

    unsigned tag2 = *(unsigned*)&a[2].w & 0xc0ffffff;
    unsigned tag1 = *(unsigned*)&a[1].w & 0xc0ffffff;
    countA = 3;
    countB = 3;
    if (tag1 == tag2 || ((*(unsigned*)&a[0].w & 0xc0ffffff) == tag2))
        countA = 2;
    if ((*(unsigned*)&a[0].w & 0xc0ffffff) == tag1) {
        --countA;
        a[0] = a[countA];
    }

    tag2 = *(unsigned*)&verticesB[4 + 2].w & 0xc0ffffff;
    tag1 = *(unsigned*)&verticesB[4 + 1].w & 0xc0ffffff;
    if (tag1 == tag2)
        --countB;
    else if ((*(unsigned*)&verticesB[4 + 0].w & 0xc0ffffff) == tag2)
        --countB;
    if (countB >= 2 && ((*(unsigned*)&verticesB[4 + 0].w & 0xc0ffffff) == tag1)) {
        --countB;
        verticesB[4 + 0] = verticesB[4 + countB];
    }

    xformPoints(*transform, &verticesB[4], countB, verticesB);
    if (countA + countB > 4)
        FUN_00a30ca0();
    if (countA == 2 && countB == 2) {
        Vec da, db;
        da.setSub(a[1], a[0]);
        db.setSub(verticesB[1], verticesB[0]);
        FUN_0096f780(a, &da, verticesB, &db, &axis);
    }
finished:
    result = output.normal;
    status = 1;
}
}   // namespace f3m_00a32540

// @f3 0x00a27550 (community match, verified in this file)
#include <math.h>
namespace f3m_00a27550 {
// Havok simple collision response: solve one contact between two motions (x87 build, 16-byte aligned vectors).
// Stand-in types; unknown fields are named by offset.

struct RawVec {
 float x,y,z,w;
 __forceinline float& operator()(int i) {return (&x)[i];}
 __forceinline const float& operator()(int i) const {return (&x)[i];}
};

struct __declspec(align(16)) Vec : RawVec {
 __forceinline void operator=(const Vec& v) {x=v.x;y=v.y;z=v.z;w=v.w;}
 __forceinline void sub(const RawVec& a,const RawVec& b) {x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
 // scale in place: the scalar is copied into a local first
 __forceinline void mul(float input) {float s=input;x*=s;y*=s;z*=s;w*=s;}
 // scaled copy: the scalar is copied into a local first
 __forceinline void setMul(float rs,const RawVec& a) {float r=rs;x=r*a.x;y=r*a.y;z=r*a.z;w=r*a.w;}
 __forceinline void operator=(const RawVec& a) {x=a.x;y=a.y;z=a.z;w=a.w;}
 // linear interpolation a + t*(b-a): the four results are named before they are stored
 __forceinline void blend(const RawVec& a,const RawVec& b,float t) {
  float u=1.0f-t;
  float d0=u*a.x+t*b.x;
  float d1=u*a.y+t*b.y;
  float d2=u*a.z+t*b.z;
  float d3=u*a.w+t*b.w;
  x=d0;y=d1;z=d2;w=d3;
 }
 __forceinline void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
 __forceinline void cross(const RawVec& a,const RawVec& b) {
  float xx=a(1)*b(2)-a(2)*b(1);
  float yy=a(2)*b(0)-a(0)*b(2);
  float zz=a(0)*b(1)-a(1)*b(0);
  set(xx,yy,zz,0.0f);
 }
};

struct Matrix {
 Vec c0,c1,c2;
 __forceinline Vec& column(int i) {return (&c0)[i];}
};

struct __declspec(align(16)) Input {Vec relative; Matrix inertia; float inverseMass;};
struct __declspec(align(16)) Velocity {Vec linear,angular;};
struct __declspec(align(16)) Constraint {
 Matrix basis; Matrix invA; Matrix invB; Vec relA,relB; Matrix jacA,jacB;
 Vec diagonal,rhs,limit,impulse,unk150,unk160;
};
struct Point {Vec position,normal;};
struct Params;
struct Result {float impulse,velocityA,velocityB;};

struct Motion {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void inverseInertia(Matrix&);
 virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
 virtual void setLinear(const RawVec&); virtual void setAngular(const RawVec&);
 int unk04; unsigned char type,unk09,unk0a,unk0b; int unk0c;
 struct RawMatrix {RawVec c0,c1,c2;} rotation; RawVec translation;
 // swept centre of mass: center0.w is the base time, center1.w is 1/dt
 RawVec center0,center1; RawVec orientation0,orientation1;RawVec unk90;RawVec angularDelta;RawVec unkb0;
 RawVec unkc0;   // unkc0.w is the inverse mass
 RawVec linear,angular;
 __forceinline float invMass() const {return unkc0.w;}
 __forceinline float invStep() const {return center1.w;}
 __forceinline const RawVec& linearValue() const {return linear;}
 __forceinline const RawVec& angularValue() const {return angular;}
 __forceinline float fraction(float t) const {return (t-center0.w)*center1.w;}
 __forceinline void center(float time,Vec& out) const {
  float iv=fraction(time);
  out.blend(center0,center1,iv);
 }
 __forceinline void oldVelocity(Velocity& v) const {
  v.linear.sub(center1,center0);
  v.linear.mul(invStep());
  v.angular.setMul(invStep(),angularDelta);
 }
};

struct Manager {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
 virtual void v30(); virtual void v34();
 virtual void begin(const Point&,Input&,Velocity&,Input&,Velocity&);
 virtual void end(const Point&,float,Input&,Velocity&,Input&,Velocity&);
};

void __cdecl FUN_00a7ce70(const Input&,const Input&,const Matrix&,Constraint&);
float __cdecl FUN_00a7da50(Constraint&,Params&,Velocity&,Velocity&);
void __cdecl FUN_00a7d850(const Constraint&,const Velocity&,const Velocity&,Vec&);

inline float S7550_fabs(float r) { return (float)fabs(r); }
inline float S7550_sqrt(float r) { return (float)sqrt(r); }
inline float S7550_sqrtInverse(float r) { return 1.0f/S7550_sqrt(r); }

// a vector perpendicular to n: zero the smallest component, swap and negate the other two
__forceinline void perpendicular(const RawVec& n,Vec& tangent) {
 int least=0,first=1,second=2;
 float ax=S7550_fabs(n(0)),ay=S7550_fabs(n(1)),az=S7550_fabs(n(2));
 if(ay<ax) {first=0;least=1;ax=ay;}
 if(az<ax) {second=least;least=2;}
 tangent.x=tangent.y=tangent.z=tangent.w=0.0f;
 tangent(first)=n(second);
 tangent(second)=-n(first);
}
__forceinline float inverseLength(const Vec& v) {
 float sum=v.x*v.x+v.y*v.y+v.z*v.z;
 return sum ? S7550_sqrtInverse(sum) : 0.0f;
}
__forceinline void normalize(Vec& v) {v.mul(inverseLength(v));}

// pdb: hkpSimpleCollisionResponse::solveSingleContact | hkpSimpleCollisionResponse.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(call_seq), high
void __cdecl hkpSimpleCollisionResponse_solveSingleContact(const Point& point,float time,Params& params,Motion* a,Motion* b,Manager* mgr,Result& result) {
 Input ia,ib;
 {ia.inverseMass=a->invMass();Vec center;a->center(time,center);ia.relative.sub(point.position,center);a->inverseInertia(ia.inertia);}
 {ib.inverseMass=b->invMass();Vec center;b->center(time,center);ib.relative.sub(point.position,center);b->inverseInertia(ib.inertia);}
 Velocity va,vb;va.linear=a->linearValue();va.angular=a->angularValue();vb.linear=b->linearValue();vb.angular=b->angularValue();
 Velocity olda,oldb;a->oldVelocity(olda);b->oldVelocity(oldb);
 Constraint info; Matrix basis; basis.column(0)=point.normal;
 perpendicular(point.normal,basis.column(1));
 normalize(basis.column(1));
 basis.column(2).cross(point.normal,basis.column(1));
 mgr->begin(point,ia,va,ib,vb);
 FUN_00a7ce70(ia,ib,basis,info);
 float imp=FUN_00a7da50(info,params,va,vb);
 result.impulse=imp;
 mgr->end(point,imp,ia,va,ib,vb);
 {Vec pa,pb;FUN_00a7d850(info,olda,vb,pa);FUN_00a7d850(info,va,oldb,pb);result.velocityA=pa.x;result.velocityB=pb.x;}
 if(a->type!=7){a->setLinear(va.linear);a->setAngular(va.angular);}
 if(b->type!=7){b->setLinear(vb.linear);b->setAngular(vb.angular);}
}
}   // namespace f3m_00a27550

// @f3 0x00a24db0 (community match, verified in this file)
typedef unsigned char byte;

extern const char DAT_00e7d35c[];
extern const char DAT_00e7d348[];
extern const char DAT_00e8567c[];
extern const char DAT_00e8566c[];
extern const char DAT_00e85660[];
extern const char DAT_00e0811c[];
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct FlagByte
{
    char value;
    __forceinline FlagByte() {}
    __forceinline FlagByte(bool b) { value = (char)b; }
    __forceinline operator bool() const { return value != 0; }
    __forceinline FlagByte operator==(bool e) const { return (value != 0) == e; }
    __forceinline FlagByte operator!=(bool e) const { return (value != 0) != e; }
    __forceinline FlagByte& operator=(bool b) { value = (char)b; return *this; }
};

template <class T> struct Padded
{
    T m_storage;
    __forceinline Padded() {}
    __forceinline Padded(const T& e) : m_storage(e) {}
    __forceinline T val() const { return m_storage; }
    __forceinline T operator->() const { return m_storage; }
    __forceinline operator T() const { return val(); }
    __forceinline void operator=(const T& e) { m_storage = e; }
};

__forceinline void* getThreadLocal(unsigned long slot) { return DAT_00d9b080(slot); }

struct hkMonitorStream
{
    struct TimerCommand
    {
        const char* m_commandAndMonitor;
        unsigned int m_time0;
        unsigned int unk08;
        __forceinline void setTime();
    };
    struct TimerBeginListCommand
    {
        const char* m_commandAndMonitor;
        unsigned int m_time0;
        unsigned int unk08;
        const char* m_nameOfFirstSplit;
        __forceinline void setTime();
    };
    Padded<char*> m_start;
    Padded<char*> m_end;
    Padded<char*> m_capacity;
    Padded<char*> m_capacityMinus16;
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline FlagByte memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline void setEnd(char* p) { m_end = p; }
    static __forceinline hkMonitorStream& getInstance() { return *(hkMonitorStream*)getThreadLocal(DAT_0116913c); }
};

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

__forceinline void hkMonitorStream::TimerBeginListCommand::setTime()
{
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

template <class T> struct TaskArrayBase
{
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int GetLogicalSize() const { return count; }
    __forceinline int getCapacity() const { return capacityAndFlags & 0x3FFFFFFF; }
    __forceinline T* begin() const { return data; }
    __forceinline T& operator[](int i) const { return data[i]; }
};

template <class T> struct TaskArray : TaskArrayBase<T>
{
    __forceinline TaskArray() { this->data = 0; this->count = 0; this->capacityAndFlags = 0x80000000; }
};

template <class T> __forceinline T maxVal(T x, T y) { return x > y ? x : y; }

struct StepTiming { int unk00[4]; };
struct SolverParams { int unk00[8]; };
struct AccelVec { int unk00[4]; };

struct Context
{
    StepTiming timing;      // 0x00
    SolverParams solver;    // 0x10
    AccelVec gravityStep;   // 0x30
    int unk40[61];          // 0x40..0x130
    FlagByte buildOnSpu;    // 0x134
};

struct Settings
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
    void* collisionInput;   // 0x6c
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    FlagByte skipObservers; // 0xa0
    FlagByte unkA1;
    unsigned short unkA2;
    int minIslandSize;      // 0xa4
    int unkA8, unkAC, unkB0, unkB4;
    FlagByte wantSparseCheck; // 0xb8
    byte unkB9;
    unsigned short unkBA;
    int unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    int unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c;
    Context context;        // 0x190
    __forceinline void* getCollisionInput() { return collisionInput; }
};

struct SceneIsland;
struct JobHeader;
struct TaskOwner;
struct JobQueueEntry;

struct Observer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void apply(const Context& ctx);
};

struct SceneIsland
{
    int unk00, unk04, unk08;
    int schemaSize;         // 0x0c
    int numSolverResults;   // 0x10
    int numSolverElemTemps; // 0x14
    Settings* world;        // 0x18
    int numConstraints;     // 0x1c
    int unk20;
    byte splitCounter;      // 0x24
    bool sparseEnabled : 2; // 0x25
    bool isSparse : 2;
    byte flagBits : 4;
    unsigned short unk26;
    int unk28, unk2c, unk30, unk34;
    TaskArrayBase<Observer*> observers; // 0x38
    int unk44;
    TaskArrayBase<void*> entities;      // 0x48
    __forceinline const TaskArrayBase<void*>& GetEntities() const { return entities; }
    __forceinline Settings* getWorld() { return world; }
};

struct SecondarySettings
{
    int unk00[58];
    unsigned int constraintLimit; // 0xe8
};

struct ConstraintQueryIn { void* bodyA; };

struct TaskOwner
{
    Padded<Settings*> settings;         // 0x00
    Padded<SecondarySettings*> secondary; // 0x04
    void* unk08;                // 0x08
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    ConstraintQueryIn queryIn;  // 0x80
};

struct BuildCollection
{
    Padded<void*> buildTasks;             // 0x00
    Padded<int> numBuildTasks;            // 0x04
    Padded<void*> callbackConstraints;    // 0x08
    Padded<int> numCallbackConstraints;   // 0x0c
    __forceinline BuildCollection() : buildTasks(0), numBuildTasks(0), callbackConstraints(0), numCallbackConstraints(0) {}
};

struct SolveCollection
{
    Padded<void*> firstSolveTask;         // 0x00
    unsigned short numSolveTasks; // 0x04
    __forceinline SolveCollection() : firstSolveTask(0), numSolveTasks(0) {}
};

struct TlsHeap
{
    struct FreeList
    {
        void* m_head;      // +0
        int m_numElem;     // +4
        __forceinline void* get()
        {
            void* p = m_head;
            if (p)
            {
                m_numElem = m_numElem - 1;
                m_head = *(void**)p;
            }
            return p;
        }
    };
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    FreeList m_freeList[17];   // 0x38
    void* __thiscall FUN_008f6800(int row, int memClass);
    static __forceinline TlsHeap& getInstance() { return *(TlsHeap*)getThreadLocal(DAT_010f3170); }
    static __forceinline int constSizeToRow(int size)
    {
        if (size <= 8) return 1;
        else if (size <= 16) return 2;
        else if (size <= 32) return 3;
        else if (size <= 48) return 4;
        else if (size <= 64) return 5;
        else if (size <= 96) return 6;
        else if (size <= 128) return 7;
        else if (size <= 160) return 8;
        else if (size <= 192) return 9;
        else if (size <= 256) return 10;
        else if (size <= 320) return 11;
        else if (size <= 512) return 12;
        else return 13;
    }
    __forceinline void* allocateChunkConstSize(int nbytes, int memClass)
    {
        int row = constSizeToRow(nbytes);
        void* p = m_freeList[row].get();
        if (p)
        {
            return p;
        }
        return FUN_008f6800(row, memClass);
    }
};

struct JobHeader
{
    __forceinline void* operator new(unsigned int nbytes) throw()
    {
        return TlsHeap::getInstance().allocateChunkConstSize(0x80, 0x2c);
    }
    Padded<unsigned int> openJobs;            // 0x00
    Padded<unsigned int> unfinishedJobs;      // 0x04
    Padded<unsigned int> shouldDeactivate;    // 0x08
    unsigned int refCount;            // 0x0c
    unsigned int exportFinishedCount; // 0x10
    void* buffer;                     // 0x14
    void* impulseLimits;              // 0x18
    char exportFinished;          // 0x1c
    char splitRequested;              // 0x1d
    unsigned short unk1e;
    Padded<void*> accumulatorsBase;           // 0x20
    int unk24, unk28, unk2c;
    Padded<void*> schemasBase;                // 0x30
    int unk34, unk38;
    Padded<void*> solverTempBase;             // 0x3c
    void* unk40;
    Padded<int> numSolverResults;             // 0x44
    Padded<int> numSolverElemTemps;           // 0x48
    Padded<const void*> queryIn;              // 0x4c
    Padded<void* const*> allEntities;         // 0x50
    Padded<unsigned short> numAllEntities;    // 0x54
    Padded<unsigned short> entitiesCapacity;  // 0x56
    FlagByte unk58;
    FlagByte unk59;
    unsigned short unk5a;
    TaskArray<void*> splitIslands;    // 0x5c
    BuildCollection tasks;            // 0x68
    SolveCollection solveTasks;       // 0x78
    __forceinline JobHeader() : refCount(1), exportFinishedCount(1), buffer(0), impulseLimits(0) {}
};

struct PacketBase
{
    unsigned short subType;      // 0x00 (low byte) + kind (high byte)
    unsigned short islandIndex;  // 0x02
};

struct DynamicsPacket : PacketBase
{
    SceneIsland* island;   // 0x04
    JobHeader* header;     // 0x08
    int unk0c;
    __forceinline DynamicsPacket(byte st, const DynamicsPacket& src)
    {
        subType = st;
        islandIndex = src.islandIndex;
        island = src.island;
    }
};

struct BroadPacket : DynamicsPacket
{
    unsigned short numIslands;   // 0x10
    __forceinline void* operator new(unsigned int, void* p) { return p; }
    __forceinline BroadPacket(const DynamicsPacket& src, JobHeader* hdr) : DynamicsPacket(0xc, src)
    {
        header = hdr;
        numIslands = 1;
    }
};

struct __declspec(align(16)) FinishPacket : DynamicsPacket
{
    int unk10;
    __forceinline FinishPacket(const DynamicsPacket& src, JobHeader* hdr) : DynamicsPacket(2, src)
    {
        header = hdr;
    }
};

struct AccumulatorsPacket : DynamicsPacket
{
    void* const* entitiesArray;      // 0x10
    unsigned short firstEntityIdx;   // 0x14
    unsigned short numEntities;      // 0x16
};

struct JobQueueEntry : PacketBase
{
    SceneIsland* island;
    JobHeader* header;
    int unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    __forceinline JobQueueEntry() {}
};

struct Queue
{
    int __thiscall FUN_00a21d70(int a, int b, void* c, JobQueueEntry& next, int d);
    void __thiscall hkJobQueue_addJob(JobQueueEntry& next, int a, int b);
    int __thiscall FUN_00a21830(void* a, const void* pkt, JobQueueEntry& next, TaskOwner* owner, int d);
};

struct TaskSingleton
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void* FUN_00a0af50v(int count, int size);
};
extern TaskSingleton* DAT_010f3400;
__forceinline TaskSingleton& getMemorySystem() { return *DAT_010f3400; }

extern int __cdecl hkRigidMotionUtilApplyForcesAndStep(const SolverParams* solver, const StepTiming* timing, const AccelVec* accel,
                                void* const* entities, int numEntities, int offset);
extern int __cdecl FUN_0099a2d0(const void* collisionInput, void* const* entities, int numEntities);
extern int __cdecl FUN_00a0b010(const StepTiming* timing, const SolverParams* solver, const void* queryIn,
                                SceneIsland& island, void* const* entities, int numEntities);
extern void __cdecl FUN_00a23320(SceneIsland* island, void* splitIslands);
extern int __cdecl FUN_00a0af50(SceneIsland* island);
extern void __cdecl FUN_00a0a680(SceneIsland* island, void* buffer, int count, JobHeader* header);
extern void __cdecl createBuildJacobianAndSolveJacobianTaskCollection(SceneIsland* island, FlagByte buildOnSpu, JobHeader* header,
                                 BuildCollection* builds, SolveCollection* solves);

__forceinline int estimateIslandSize(int numEntities, int numConstraints) { return maxVal(numEntities, numConstraints); }
__forceinline FlagByte checkIslandSparse(Settings* world, int size) { return size < world->minIslandSize; }

// Integrate job of the multithreaded physics step: applies the island's observers, allocates the task header,
// decides whether a split check is due, then either steps a constraint-free island directly, solves a small island
// on this thread, or queues the accumulator/build/solve jobs.
//
// The one add "splitRequested + motionJobs" (lea with splitRequested as base) depends on how many locals and
// reference-bound temporaries the compiler has numbered before splitRequested. The named locals world, stepInfo,
// islandEntities and capacity, the initializer lists of the two collection constructors and the padded 16-bit header
// counts are a guess at the original source that puts that count where the original has it; they change no other
// instruction.
// pdb: integrateJob | hkpCpuIntegrateJob.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
int __cdecl integrateJob(TaskOwner& owner, Queue& queue, JobQueueEntry& nextJobOut)
{
    const DynamicsPacket& currentJob = reinterpret_cast<DynamicsPacket&>(nextJobOut);

    {
        hkMonitorStream& stream = hkMonitorStream::getInstance();
        if (stream.memoryAvailable())
        {
            hkMonitorStream::TimerBeginListCommand* ev =
                reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(stream.getEnd());
            ev->m_commandAndMonitor = DAT_00e7d35c;
            ev->m_nameOfFirstSplit = DAT_00e7d348;
            ev->setTime();
            stream.setEnd((char*)(ev + 1));
        }
    }

    SceneIsland* island = currentJob.island;
    Settings* world = owner.settings;
    Context& stepCtx = world->context;
    const StepTiming& stepInfo = stepCtx.timing;
    if (world->skipObservers == false)
    {
        const TaskArrayBase<Observer*>& observers = island->observers;
        for (int j = 0; j < observers.GetLogicalSize(); j++)
        {
            Observer* obs = observers[j];
            if (obs)
            {
                obs->apply(stepCtx);
            }
        }
    }

    JobHeader* header = new JobHeader;

    const TaskArrayBase<void*>& islandEntities = island->GetEntities();
    void* const* entities = islandEntities.begin();
    unsigned int numEntities = islandEntities.GetLogicalSize();
    header->numAllEntities = (unsigned short)numEntities;
    header->allEntities = entities;
    int capacity = islandEntities.getCapacity();
    header->entitiesCapacity = (unsigned short)capacity;
    header->unfinishedJobs = 0;
    header->shouldDeactivate = 1;
    header->buffer = 0;
    header->impulseLimits = 0;
    header->accumulatorsBase = 0;
    header->tasks.buildTasks = 0;
    header->schemasBase = 0;

    int splitRequested = 0;

    island->splitCounter++;
    if (!island->isSparse)
    {
        if (island->sparseEnabled && (island->splitCounter & 7) == 0 && owner.settings->wantSparseCheck)
        {
            splitRequested = 1;
        }
    }
    else
    {
        int islandSize = estimateIslandSize(island->GetEntities().GetLogicalSize(), island->numConstraints);
        FlagByte canBeSparse = checkIslandSparse(owner.settings.val(), islandSize);
        if (!canBeSparse)
        {
            island->isSparse = 0;
            if ((island->splitCounter & 3) == 0)
            {
                splitRequested = 1;
            }
        }
        else
        {
            if ((island->splitCounter & 7) == 0)
            {
                splitRequested = 1;
            }
        }
    }

    if (island->schemaSize == 0)
    {
        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (stream.memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_00e8567c;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        int inactiveFrames = hkRigidMotionUtilApplyForcesAndStep(&stepCtx.solver, &stepInfo, &stepCtx.gravityStep,
                                          island->GetEntities().begin(), island->GetEntities().GetLogicalSize(), 0xd0);
        FUN_0099a2d0(island->getWorld()->getCollisionInput(), island->GetEntities().begin(),
                     island->GetEntities().GetLogicalSize());
        if (inactiveFrames <= 5)
        {
            header->shouldDeactivate = 0;
        }
    }
    else
    {
        int estimatedConstraints = maxVal(island->numConstraints, island->GetEntities().GetLogicalSize());
        if (estimatedConstraints < owner.secondary->constraintLimit)
        {
            {
                hkMonitorStream& stream = hkMonitorStream::getInstance();
                if (stream.memoryAvailable())
                {
                    hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                    ev->m_commandAndMonitor = DAT_00e8566c;
                    ev->setTime();
                    stream.setEnd((char*)(ev + 1));
                }
            }
            int inactiveFrames = FUN_00a0b010(&stepInfo, &stepCtx.solver, &owner.queryIn, *island,
                                              entities, (int)numEntities);
            if (inactiveFrames <= 5)
            {
                header->shouldDeactivate = 0;
            }
        }
        else
        {
            {
                hkMonitorStream& stream = hkMonitorStream::getInstance();
                if (stream.memoryAvailable())
                {
                    hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                    ev->m_commandAndMonitor = DAT_00e85660;
                    ev->setTime();
                    stream.setEnd((char*)(ev + 1));
                }
            }
            {
                int jobCount = FUN_00a0af50(island);
                void* solverBuffer = getMemorySystem().FUN_00a0af50v(jobCount, 0x2c);
                FUN_00a0a680(island, solverBuffer, jobCount, header);
            }
            header->numSolverResults = island->numSolverResults;
            header->numSolverElemTemps = island->numSolverElemTemps;
            header->queryIn = (const void*)&owner.queryIn;
            int motionJobs = (numEntities - 1) / 128 + 1;
            header->unfinishedJobs = splitRequested + motionJobs;
            header->splitRequested = (char)splitRequested;
            header->exportFinished = (char)0;

            AccumulatorsPacket& accJob = reinterpret_cast<AccumulatorsPacket&>(nextJobOut);
            accJob.entitiesArray = entities;
            accJob.subType = 1;
            accJob.header = header;
            accJob.firstEntityIdx = 0;
            accJob.numEntities = (unsigned short)numEntities;
            header->openJobs = (numEntities - 1) / 128 + 2;
            queue.hkJobQueue_addJob(nextJobOut, 0, 0);

            {
                BuildCollection outBuilds;
                SolveCollection outSolves;
                createBuildJacobianAndSolveJacobianTaskCollection(island, stepCtx.buildOnSpu, header, &outBuilds, &outSolves);
                {
                    hkMonitorStream& stream = hkMonitorStream::getInstance();
                    if (stream.memoryAvailable())
                    {
                        hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                        ev->m_commandAndMonitor = DAT_00e0811c;
                        ev->setTime();
                        stream.setEnd((char*)(ev + 1));
                    }
                }
                header->tasks = outBuilds;
                header->solveTasks = outSolves;

                FinishPacket finalizePacket(currentJob, header);
                return queue.FUN_00a21830(owner.unk08, &finalizePacket, nextJobOut, &owner, 0);
            }
        }
    }

    if (splitRequested)
    {
        FUN_00a23320(island, &header->splitIslands);
    }
    {
        hkMonitorStream& stream = hkMonitorStream::getInstance();
        if (stream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
            ev->m_commandAndMonitor = DAT_00e0811c;
            ev->setTime();
            stream.setEnd((char*)(ev + 1));
        }
    }
    header->exportFinished = (char)1;
    new (&nextJobOut) BroadPacket(currentJob, header);
    queue.FUN_00a21d70(1, 0, owner.unk08, nextJobOut, 0);
    return 0;
}

// @f3 0x00a2d530 (community match, verified in this file)
namespace N_A2D530 {
typedef float hkReal_X;
typedef unsigned int hkUint32_X;
struct Scalar { float x; Scalar(float f):x(f){} operator float() const {return x;} };
// Guess: the scalar is built in a named local; each use is one more inline local, which the original's
// x87 operand order of the interpolations below depends on.
inline Scalar ScalarValue(float x) { Scalar r(x); return r; }
// Guess: crossing ratio of the two plane distances, written with named distances (used where the ray start is clipped).
inline Scalar CrossRatio(float l, float h) { const float dl = l; const float dh = h; const float ratio = dl / (dl - dh); Scalar r(ratio); return r; }
struct __declspec(align(16)) hkVector4_X {
    float v[4];
    float& operator()(int i) { return v[i]; }
    const float& operator()(int i) const { return v[i]; }
    // Guess: the copy reads the lanes into named values first (no code difference; it sets the numbering).
    __forceinline void operator=(const hkVector4_X& b) { const float x=b(0); const float y=b(1); const float z=b(2); const float w=b(3); v[0]=x; v[1]=y; v[2]=z; v[3]=w; }
    __forceinline void set(float a,float b,float c,float d) { v[0]=a;v[1]=b;v[2]=c;v[3]=d; }
    __forceinline void setAll3(float f) { v[0]=f;v[1]=f;v[2]=f;v[3]=f; }
    __forceinline void sub4(const hkVector4_X& b) { v[0]-=b(0);v[1]-=b(1);v[2]-=b(2);v[3]-=b(3); }
    __forceinline void setSub4(const hkVector4_X& a,const hkVector4_X& b) {v[0]=a.v[0]-b(0);v[1]=a.v[1]-b(1);v[2]=a.v[2]-b(2);v[3]=a.v[3]-b(3);}
    __forceinline void setAdd4(const hkVector4_X& a,const hkVector4_X& b) {v[0]=a.v[0]+b(0);v[1]=a.v[1]+b(1);v[2]=a.v[2]+b(2);v[3]=a.v[3]+b(3);}
    __forceinline void mul4(float f) { v[0]*=f;v[1]*=f;v[2]*=f;v[3]*=f; }
    __forceinline void mul4(const hkVector4_X& b) {v[0]*=b(0);v[1]*=b(1);v[2]*=b(2);v[3]*=b(3);}
    __forceinline void setMul4(const hkVector4_X& a,const hkVector4_X& b) {v[0]=a.v[0]*b(0);v[1]=a.v[1]*b(1);v[2]=a.v[2]*b(2);v[3]=a.v[3]*b(3);}
    __forceinline void setInterpolate4(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        v[0]=s*a(0)+t*b(0);v[1]=s*a(1)+t*b(1);v[2]=s*a(2)+t*b(2);v[3]=s*a(3)+t*b(3);
    }
    // Guess: lanes computed into named values, then stored (used for the clipped end point and one cut).
    __forceinline void setInterpolate4Stored(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        const float x=s*a(0)+t*b(0); const float y=s*a(1)+t*b(1); const float z=s*a(2)+t*b(2); const float w=s*a(3)+t*b(3);
        v[0]=x; v[1]=y; v[2]=z; v[3]=w;
    }
    // Guess: hit-point interpolations write the t*b product first (parenthesised) in the lanes where the original computes it first.
    __forceinline void setHitInterpolate4Right(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        const float x=s*a(0)+(t*b(0)); const float y=s*a(1)+t*b(1); const float z=s*a(2)+t*b(2); const float w=s*a(3)+t*b(3);
        v[0]=x; v[1]=y; v[2]=z; v[3]=w;
    }
    __forceinline void setHitInterpolate4Left(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        const float x=s*a(0)+(t*b(0)); const float y=s*a(1)+(t*b(1)); const float z=s*a(2)+(t*b(2)); const float w=s*a(3)+(t*b(3));
        v[0]=x; v[1]=y; v[2]=z; v[3]=w;
    }
};
struct VectorPropertyRecord {
    __forceinline VectorPropertyRecord& operator=(const VectorPropertyRecord& o) {return FUN_00a2d4d0(o);}
    hkVector4_X m_kVectorBeforeIndex, SetCenterPosition;
    float m_fValueAtOffset20;
    int m_iIndex;
    float m_kVectorAfterIndex;
    unsigned m_uiPropertyCount;
    unsigned m_kProperties[1];
    __declspec(noinline) VectorPropertyRecord& FUN_00a2d4d0(const VectorPropertyRecord& o) {
        m_kVectorBeforeIndex=o.m_kVectorBeforeIndex; SetCenterPosition=o.SetCenterPosition;
        m_fValueAtOffset20=o.m_fValueAtOffset20; m_iIndex=o.m_iIndex;
        m_kVectorAfterIndex=o.m_kVectorAfterIndex; m_uiPropertyCount=o.m_uiPropertyCount;
        m_kProperties[0]=o.m_kProperties[0]; return *this;
    }
};
struct TwoPointVectorBundles { hkVector4_X m_kPointBundles[2]; };
struct StreamRecord {
    unsigned unk00,unk04,unk08;
    __forceinline void FUN_00923070(void*,int);
    StreamRecord& FUN_00943710(const char*);
    __forceinline void FUN_00943a60();
};
struct ErrorRecord {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int message(int,int,const char*,const char*,int);
};
extern ErrorRecord* DAT_010f3364;
extern const char DAT_00e85ef0[];
extern const char DAT_00e85eb0[];
struct ShapeBuffer { unsigned data[128]; };
struct ShapeRecord;
struct ContainerRecord {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual const ShapeRecord* GetShapeForKey(unsigned,ShapeBuffer&) const;
};
struct ShapeBase0 { virtual void b0(); unsigned b4,b8,bc; };
struct CollShape : ShapeBase0, ContainerRecord { };
struct ShapeRecord {
    unsigned unk00,unk04,unk08;
    int m_type;
    unsigned unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    const CollShape* m_child;
    const CollShape* getShapeCollection() const { return m_child; }
    int getType() const { return m_type; }
};
struct BodyRecord {
    const ShapeRecord* m_pCollisionShape;
    unsigned m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const BodyRecord* m_parent;
    BodyRecord(const BodyRecord* p) {m_parent=p;m_pMotionState=p->m_pMotionState;}
    const ShapeRecord* getShape() const {return m_pCollisionShape;}
    __forceinline void SetCollisionShapeAndKey(const ShapeRecord* p,unsigned k) {m_pCollisionShape=p;m_uiCollisionShapeKey=k;}
};
struct BoolRecord { char value; operator bool() const {return value!=0;} };
struct ShapeSweepParameters;
struct FilterRecord {
    virtual void v0();
    virtual BoolRecord IsCollisionEnabled(const ShapeSweepParameters&,const BodyRecord&,const BodyRecord&,const ContainerRecord&,unsigned) const;
};
struct CollectorRecord { void* vtable; float m_fEarlyOutDistance; float getEarlyOutDistance()const{return m_fEarlyOutDistance;} };
struct DispatcherRecord {
    typedef void (__cdecl* LinearCastFunc)(const BodyRecord&,const BodyRecord&,const ShapeSweepParameters&,CollectorRecord&,CollectorRecord*);
    struct Entry {void* create;void* penetration;void* closest;LinearCastFunc cast;unsigned flags;};
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    Entry m_agent2Funcs[64];
    LinearCastFunc getLinearCastFunc(int a,int b) const {return m_agent2Funcs[m_agent2TypeMap[a][b]].cast;}
};
struct ShapeSweepParameters { DispatcherRecord* m_pCollisionDispatcher; unsigned unk04; const FilterRecord* m_iFilter; };
struct CodeRecord {unsigned unk00,unk04,unk08,unk0c; struct Info {hkVector4_X m_offset;} m_info; const unsigned char* m_data;};
struct MoppPrimitiveQueryContext {
    void* m_pPrimitiveInfoArray;int unk04,unk08,unk0c;
    static int read24(const unsigned char* pc) {return ((pc[0]<<8)+pc[1])*256+pc[2];}
};
struct MoppCastMachine : MoppPrimitiveQueryContext {
    struct MoppCastQueryData {hkVector4_X m_vFrom,m_vTo,SetCenterPosition;const ShapeSweepParameters* m_pCollisionInput;const BodyRecord* m_pFirstCastBody;const BodyRecord* m_pSecondCastBody;};
    const CodeRecord* m_pMoppCode;
    float m_vRayDirectionVector;
    int m_iRayDirectionIndex;
    float m_fFirstRayCastValue,m_fSecondRayCastValue;
    CollectorRecord* m_pPointCollector;
    CollectorRecord* m_pClosestPointCollector;
    const MoppCastQueryData* m_pRayCastInput;
    int m_iCurrentChunkId;
    void FUN_00a2d530(const VectorPropertyRecord*,const unsigned char*,TwoPointVectorBundles*,int);
    // Guess: the early-out fraction is read through an accessor with a named local.
    __forceinline float GetEarlyOut() const { const float f = m_fFirstRayCastValue; return f; }
    __forceinline void AddHit(unsigned key,const unsigned*,unsigned long) {
        const ContainerRecord* shapeContainer=m_pRayCastInput->m_pSecondCastBody->getShape()->getShapeCollection();
        ShapeBuffer shapeBuffer;
        const ShapeRecord* childShape=shapeContainer->GetShapeForKey(key,shapeBuffer);
        if (!m_pRayCastInput->m_pCollisionInput->m_iFilter->IsCollisionEnabled(*m_pRayCastInput->m_pCollisionInput,*m_pRayCastInput->m_pFirstCastBody,*m_pRayCastInput->m_pSecondCastBody,*shapeContainer,key)) return;
        BodyRecord childBodyB(m_pRayCastInput->m_pSecondCastBody);
        childBodyB.SetCollisionShapeAndKey(childShape,key);
        int typeB=childShape->getType();
        DispatcherRecord::LinearCastFunc linCastFunc=m_pRayCastInput->m_pCollisionInput->m_pCollisionDispatcher->getLinearCastFunc(m_iRayDirectionIndex,typeB);
        linCastFunc(*m_pRayCastInput->m_pFirstCastBody,childBodyB,*m_pRayCastInput->m_pCollisionInput,*m_pPointCollector,m_pClosestPointCollector);
        m_fFirstRayCastValue=m_pPointCollector->getEarlyOutDistance();
    }
};
// pdb: hkpMoppAabbCastVirtualMachine::queryRayOnTree | hkpMoppAabbCastVirtualMachine.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: query, PC, fQuery, chunkOffset
void MoppCastMachine::FUN_00a2d530(const VectorPropertyRecord* query, const unsigned char* PC,
                                   TwoPointVectorBundles fQuery[1], int chunkOffset)
{
    VectorPropertyRecord scaledQuery;
    do
    {
        const int command = PC[0];
        int tdir = 999;
        int offsetLB;
        int offsetRB;
        hkReal_X positionl;
        hkReal_X positionh;
        hkReal_X foffsetl;
        hkReal_X foffseth;
        int offsetl;
        int offseth;
        switch (command)
        {
        case 0x13: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x14: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2));
            positionh = (fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2));
            goto do_compareN4;
        }
        case 0x15: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](2));
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x16: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x17: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x18: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x19: {
            foffseth = hkReal_X(PC[1] * 3);
            foffsetl = hkReal_X(PC[2] * 3);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1a: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1b: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1c: {
            foffseth = hkReal_X(PC[1] * 3 - 510);
            foffsetl = hkReal_X(PC[2] * 3 - 510);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x20:
        case 0x21:
        case 0x22:
            tdir = command - 0x20;
            foffsetl = hkReal_X(PC[1]);
            foffseth = foffsetl + 1.0;
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            PC += 3;
            offsetLB = 0;
            offsetRB = PC[-1];
            goto do_compare;
        case 0x23:
        case 0x24:
        case 0x25:
            tdir = command - 0x23;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            offsetLB = (PC[3] << 8) + PC[4];
            PC += 7;
            offsetRB = (PC[-2] << 8) + PC[-1];
            goto do_compare;
        case 0x10:
        case 0x11:
        case 0x12:
            tdir = command - 0x10;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
        do_compareN4:
            PC += 4;
            offsetLB = 0;
            offsetRB = PC[-1];
        do_compare:
            if (positionh < foffsetl && positionl < foffsetl)
            {
                PC += offsetLB;
                continue;
            }
            PC += offsetRB;
            if (positionl > foffseth && positionh > foffseth)
            {
                continue;
            }
            {
                const hkReal_X la = positionl - foffseth;
                const hkReal_X ha = positionl - foffsetl;
                const hkReal_X lb = positionh - foffseth;
                const hkReal_X hb = positionh - foffsetl;
                TwoPointVectorBundles leftFloat;
                leftFloat.m_kPointBundles[0] = fQuery->m_kPointBundles[0];
                leftFloat.m_kPointBundles[1] = fQuery->m_kPointBundles[1];
                if (la < lb)
                {
                    if (la * lb < 0.0)
                    {
                        leftFloat.m_kPointBundles[1].setInterpolate4Stored(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], ScalarValue(la / (la - lb)));
                    }
                    FUN_00a2d530(query, PC - offsetRB + offsetLB, &leftFloat, chunkOffset);
                    if (ha * hb < 0.0)
                    {
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], CrossRatio(ha, hb));
                    }
                    if (GetEarlyOut() < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = GetEarlyOut();
                        const hkReal_X fraction = GetEarlyOut();
                        hkVector4_X hitpoint;
                        hitpoint.setHitInterpolate4Left(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, Scalar(fraction));
                        fQuery->m_kPointBundles[1].setSub4(
                            hitpoint, reinterpret_cast<const hkVector4_X&>(m_pMoppCode->m_info.m_offset));
                        fQuery->m_kPointBundles[1].mul4(Scalar(query->m_kVectorAfterIndex));
                         fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] < foffsetl)
                        {
                            goto end_of_function;
                        }
                    }
                    continue;
                }
                else
                {
                    if (ha * hb < 0.0)
                    {
                        leftFloat.m_kPointBundles[1].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], Scalar(ha / (ha - hb)));
                    }
                    FUN_00a2d530(query, PC, &leftFloat, chunkOffset);
                    if (la * lb < 0.0)
                    {
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], ScalarValue(la / (la - lb)));
                    }
                    if (GetEarlyOut() < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = GetEarlyOut();
                        const hkReal_X fraction = GetEarlyOut();
                        hkVector4_X hitpoint;
                        hitpoint.setHitInterpolate4Right(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, fraction);
                        fQuery->m_kPointBundles[1].setSub4(
                            hitpoint, reinterpret_cast<const hkVector4_X&>(m_pMoppCode->m_info.m_offset));
                        fQuery->m_kPointBundles[1].mul4(ScalarValue(query->m_kVectorAfterIndex));
                        fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] > foffseth)
                        {
                            goto end_of_function;
                        }
                    }
                    PC = PC - offsetRB + offsetLB;
                    continue;
                }
            }
        case 0x29:
        case 0x2a:
        case 0x2b:
            tdir = command - 0x29;
            {
                foffsetl = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 1)) * m_vRayDirectionVector;
                foffseth = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 4)) * m_vRayDirectionVector;
                foffsetl *= query->m_kVectorAfterIndex;
                foffseth *= query->m_kVectorAfterIndex;
                foffsetl -= query->m_kVectorBeforeIndex(tdir);
                foffseth -= query->m_kVectorBeforeIndex(tdir);
                foffsetl -= query->SetCenterPosition(tdir);
                foffseth += query->SetCenterPosition(tdir);
                PC += 7;
            }
            goto doCut;
        case 0x26:
        case 0x27:
        case 0x28:
            tdir = command - 0x26;
            foffsetl = hkReal_X(PC[1]);
            foffseth = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            PC += 3;
        doCut:
            positionl = fQuery->m_kPointBundles[0](tdir);
            positionh = fQuery->m_kPointBundles[1](tdir);
            {
                int sign;
                if (positionl < positionh)
                {
                    if (positionh < foffsetl || positionl > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 0;
                }
                else
                {
                    if (positionl < foffsetl || positionh > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 1;
                }
                const hkVector4_X rayStartPoint = fQuery->m_kPointBundles[0];
                const hkVector4_X rayEndPoint = fQuery->m_kPointBundles[1];
                {
                    const hkReal_X R0 = positionl - foffseth;
                    const hkReal_X R1 = positionh - foffseth;
                    if (R0 * R1 < 0.0)
                    {
                        fQuery->m_kPointBundles[1 - sign].setInterpolate4Stored(rayStartPoint, rayEndPoint, Scalar(R0 / (R0 - R1)));
                    }
                }
                {
                    const hkReal_X L0 = positionl - foffsetl;
                    const hkReal_X L1 = positionh - foffsetl;
                    if (L0 * L1 < 0.0)
                    {
                        const hkReal_X ratio = L0 / (L0 - L1);
                        fQuery->m_kPointBundles[sign].setInterpolate4(rayStartPoint, rayEndPoint, Scalar(ratio));
                    }
                }
            }
            continue;
        case 5:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            continue;
        case 6:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            continue;
        case 7: {
            offseth = PC[1];
            const hkUint32_X offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
        }
            continue;
        case 0xc: {
            const int chunkId = (PC[1] << 8) | PC[2];
            chunkOffset = chunkId;
            PC = m_pMoppCode->m_data + (chunkOffset << 9);
            continue;
        }
        case 0xd:
            PC += 5;
            continue;
        case 1:
        case 2:
        case 3:
        case 4: {
            const hkUint32_X shift = command;
            hkVector4_X extraOffset;
            extraOffset.set(hkReal_X(PC[1]), hkReal_X(PC[2]), hkReal_X(PC[3]), 0.0f);
            hkVector4_X f4;
            const hkReal_X f = hkReal_X(1 << shift);
            f4.setAll3(f);
            fQuery->m_kPointBundles[0].sub4(extraOffset);
            fQuery->m_kPointBundles[1].sub4(extraOffset);
            fQuery->m_kPointBundles[0].mul4(f4);
            fQuery->m_kPointBundles[1].mul4(f4);
            scaledQuery.m_kVectorBeforeIndex.setAdd4(query->m_kVectorBeforeIndex, extraOffset);
            scaledQuery.m_kVectorBeforeIndex.mul4(f4);
            scaledQuery.m_iIndex = query->m_iIndex + shift;
            scaledQuery.m_kVectorAfterIndex = query->m_kVectorAfterIndex * f;
            scaledQuery.SetCenterPosition.setMul4(f4, query->SetCenterPosition);
            scaledQuery.m_fValueAtOffset20 = query->m_fValueAtOffset20 * f;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_kProperties[p] = query->m_kProperties[p];
            }
            scaledQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &scaledQuery;
            PC += 4;
        }
            continue;
        case 0:
            goto end_of_function;
        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;
        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;
        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;
        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_uiPropertyCount;
            {
                hkUint32_X chunkId = chunkOffset;
                hkUint32_X keyRemap = ((chunkId << 8) & m_iCurrentChunkId) | offsetl;
                AddHit(keyRemap, query->m_kProperties, 0);
            }
            goto end_of_function;
        case 9: {
            const hkUint32_X offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 2;
        }
            continue;
        case 0xa: {
            const hkUint32_X offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 3;
        }
            continue;
        case 0xb: {
            const hkUint32_X offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount = offset;
            PC += 5;
        }
            continue;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            hkUint32_X property;
            hkUint32_X value;
            property = PC[0] - 0x60;
            value = PC[1];
            PC += 2;
            scaledQuery.m_kProperties[property] = value;
        propertyCopy:
            const hkUint32_X v = scaledQuery.m_kProperties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_kProperties[0] = v;
        }
            continue;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67: {
            const hkUint32_X property = PC[0] - 0x64;
            const hkUint32_X value = (PC[1] << 8) + PC[2];
            scaledQuery.m_kProperties[property] = value;
            PC += 3;
            goto propertyCopy;
        }
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b: {
            const hkUint32_X property = PC[0] - 0x68;
            const hkUint32_X value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_kProperties[property] = value;
            PC += 5;
            goto propertyCopy;
        }
        default:
            {
                unsigned int assertBuf[128];
                StreamRecord ostr;
                ostr.FUN_00923070(assertBuf, 512);
                ostr.FUN_00943710(DAT_00e85ef0);
                DAT_010f3364->message(3, 0x1298fedd, (const char*)assertBuf,
                    DAT_00e85eb0, 506);
                ostr.FUN_00943a60();
            }
            continue;
        }
    } while (1);
end_of_function:;
}

}

// @f3 0x00a3b260 (community match, verified in this file)
namespace f3m_00a3b260 {
typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    hkReal& operator()(int i) { return (&x)[i]; }
    const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline hkVector4() { }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setAll(hkReal a) { x = a; y = a; z = a; w = a; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline hkRotation() { }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    // Copies through four whole-vector temporaries, then assigns them lane by lane.
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.getColumn(3);
        m_rotation.m_col0 = col0;
        m_rotation.m_col1 = col1;
        m_rotation.m_col2 = col2;
        m_translation = col3;
    }
    const hkVector4& getColumn(int i) const { return (&m_rotation.m_col0)[i]; }
    hkReal operator()(int r, int c) const { return getColumn(c)(r); }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    y = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    z = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    w = 0.0f;
}

namespace hkVector4Util
{
    __forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
    {
        // Work from a copy so that vectorsOut may overlap the transform.
        hkTransform unaliased = t;
        int i = numVectors - 1;
        do
        {
            vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
        } while (--i >= 0);
    }

    __forceinline void mulSigns4(hkVector4& inout, const hkVector4& signs)
    {
        hkUint32* dst = reinterpret_cast<hkUint32*>(&inout);
        const hkUint32* src = reinterpret_cast<const hkUint32*>(&signs);
        dst[0] ^= (src[0] & 0x80000000);
        dst[1] ^= (src[1] & 0x80000000);
        dst[2] ^= (src[2] & 0x80000000);
        dst[3] ^= (src[3] & 0x80000000);
    }
}

struct hkpCdVertex : public hkVector4
{
    int getId() const { return reinterpret_cast<const hkUint32*>(this)[3]; }
};

struct hkpConvexShape
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
    virtual int getNumCollisionSpheres() const;
    virtual void v28();
    virtual void v2c();
    virtual void getSupportingVertex(const hkVector4& direction, hkpCdVertex& supportingVertexOut) const;
    virtual void convertVertexIdsToVertices(const hkUint16* ids, int numIds, hkpCdVertex* verticesOut) const;

    hkUint16 m_memSizeAndFlags;
    hkUint16 m_referenceCount;
    hkUint32 m_userData;
    hkUint32 m_type;
    hkReal m_radius;
};

struct hkpTriangleShape : public hkpConvexShape
{
    hkUint16 m_weldingInfo;
    hkUint8 m_weldingType;
    hkUint8 m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
    hkVector4 m_extrusion;

    const hkVector4* getVertices() const { return &m_vertexA; }
};

struct hkpGskCache
{
    hkUint16 m_vertices[4];
    hkUint8 m_dimA;
    hkUint8 m_dimB;
    hkUint8 m_maxDimA : 4;
    hkUint8 m_maxDimB : 4;
    hkUint8 m_gskFlags;

    void hkpGskCache_init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa);
    void hkpGskCache_initTriangle(const hkpConvexShape* shapeA, const hkpTriangleShape* triangleB, const hkTransform& btoa);
};

// hkpGskCache::initTriangle: seed the cache with the three vertices of the triangle and the vertex of shapeA
// that lies furthest along the triangle normal, turned to face shapeA.
// pdb: hkpGskCache::initTriangle | hkpGskCache.obj | fnv360_0822_retail, call_gap + bridge(call_seq|callee_sim) + skyrim(call_seq), high
void hkpGskCache::hkpGskCache_initTriangle(const hkpConvexShape* shapeA, const hkpTriangleShape* triangleB, const hkTransform& btoa)
{
    if (triangleB->m_isExtruded)
    {
        hkpGskCache_init(shapeA, triangleB, btoa);
        return;
    }

    m_vertices[1] = 0;
    m_vertices[2] = 1;
    m_vertices[3] = 2;

    hkVector4 verticesBinA[3];
    hkVector4Util::transformPoints(btoa, triangleB->getVertices(), 3, verticesBinA);

    // Triangle normal in the space of shapeA.
    hkVector4 edge0;
    edge0.setSub4(verticesBinA[1], verticesBinA[0]);
    hkVector4 edge1;
    edge1.setSub4(verticesBinA[2], verticesBinA[1]);
    hkVector4 normal;
    normal.setCross(edge0, edge1);

    // Take any vertex of shapeA (id 0, read from the slot just written) and turn the normal towards it.
    hkpCdVertex vertexA;
    shapeA->convertVertexIdsToVertices(&m_vertices[1], 1, &vertexA);

    hkVector4 d;
    d.setSub4(vertexA, verticesBinA[0]);
    hkReal dot = normal.dot3(d);
    hkVector4 signs;
    signs.setAll(dot);
    hkVector4Util::mulSigns4(normal, signs);

    // The vertex of shapeA furthest along that direction completes the simplex: one point against a triangle.
    hkpCdVertex support;
    shapeA->getSupportingVertex(normal, support);

    m_vertices[0] = (hkUint16)support.getId();
    m_dimA = 1;
    m_dimB = 3;
    int maxDimA = shapeA->getNumCollisionSpheres();
    if (maxDimA > 3)
    {
        maxDimA = 0xf;
    }
    m_maxDimA = maxDimA;
    m_maxDimB = 3;
    m_gskFlags = 0;
}
}   // namespace f3m_00a3b260

// @f3 0x00a3cc40 (community match, verified in this file)
namespace f3m_00a3cc40 {
// FUN_00a3cc40: edge-edge contact test of a box-box collision detector (Havok, x87 build of the math library).
// The contact's feature bytes give, for each box, the vertex sign index (bits 5-7) and the edge axis (bits 0-3).
// The closest points of the two edges are solved in A's frame (2x2 system, parameters checked to lie strictly
// inside both edges), the normal is the normalised cross product of the edges, oriented away from A's vertex;
// the contact is accepted when the separation along it is within the tolerance.
// Compiled under /MT /O2 /GS /EHsc /Gy (the pack lists /Od, but the target is optimised code).


typedef float hkReal;
typedef hkReal hkSimdReal;
typedef const hkSimdReal& hkSimdRealParameter;

struct hkBool
{
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
};

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return reinterpret_cast<hkReal*>(this)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a)
    {
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void mul4(hkSimdRealParameter r)
    {
        x *= r;
        y *= r;
        z *= r;
        w *= r;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        x = v1.y * v2.z - v1.z * v2.y;
        y = v1.z * v2.x - v1.x * v2.z;
        z = v1.x * v2.y - v1.y * v2.x;
        w = 0.0f;
    }
    __forceinline hkSimdReal dot3(const hkVector4& v) const { return x * v.x + y * v.y + z * v.z; }
    __forceinline hkSimdReal lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline hkSimdReal length3() const { return (hkReal)sqrt(lengthSquared3()); }
    __forceinline hkSimdReal normalizeWithLength3()
    {
        hkReal len = length3();
        hkReal invLen = 1.0f / len;
        mul4(invLen);
        return len;
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline hkReal operator()(int r, int c) const { return (&m_col0)[c](r); }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void setTransformedPos(hkVector4& out, const hkTransform& t, const hkVector4& b)
{
    const hkReal b0 = b.x;
    const hkReal b1 = b.y;
    const hkReal b2 = b.z;
    out.x = t.m_rotation(0, 0) * b0 + t.m_rotation(0, 1) * b1 + t.m_rotation(0, 2) * b2 + t.m_translation.x;
    out.y = t.m_rotation(1, 0) * b0 + t.m_rotation(1, 1) * b1 + t.m_rotation(1, 2) * b2 + t.m_translation.y;
    out.z = t.m_rotation(2, 0) * b0 + t.m_rotation(2, 1) * b1 + t.m_rotation(2, 2) * b2 + t.m_translation.z;
    out.w = 0.0f;
}

struct BoxBoxEdgeContact
{
    hkVector4 m_vContactPosition;          
    hkVector4 unk10;                       
    hkVector4 m_vHitNormal;                
    float unk30;                           
    float m_fClosestPointDistanceSquared;  
    int m_featureA;                        
    int m_featureB;                        
};

extern const hkVector4 DAT_00e860b0[8];
extern const double DAT_00e86158;

static __forceinline const hkVector4& boxVertexSign(int byteOffset)
{
    return *reinterpret_cast<const hkVector4*>(reinterpret_cast<const char*>(DAT_00e860b0) + byteOffset);
}

static __forceinline float hkFabs(const float& r)
{
    return (float)fabs(r);
}

struct BoxBoxCollisionDetection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkTransform m_transform;          
    hkVector4 m_kBoxBasisVector;      
    hkVector4 m_kThirdBasisVector;    
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unkA0;
    float m_fScalar;                  
    float m_minNormalLength;          

    hkBool FUN_00a3cc40(BoxBoxEdgeContact* contact);
};

// pdb: hkpBoxBoxCollisionDetection::isValidEdgeEdge | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun, medium
// pdb params: fpp
hkBool BoxBoxCollisionDetection::FUN_00a3cc40(BoxBoxEdgeContact* contact)
{
    const hkVector4& signA = boxVertexSign(((unsigned char)contact->m_featureA >> 1) & 0x70);
    int axisA = contact->m_featureA & 0xf;
    hkVector4 vertexA;
    vertexA.setMul4(signA, m_kBoxBasisVector);
    int axisB = contact->m_featureB & 0xf;
    hkVector4 vertexB;
    vertexB.setMul4(m_kThirdBasisVector, boxVertexSign(((unsigned char)contact->m_featureB >> 1) & 0x70));
    float edgeLenB = m_kThirdBasisVector(axisB) + m_kThirdBasisVector(axisB);
    hkVector4 edgeB;
    edgeB.setMul4(edgeLenB, (&m_transform.m_rotation.m_col0)[axisB]);
    setTransformedPos(vertexB, m_transform, vertexB);
    hkVector4 diff;
    diff.setSub4(vertexB, vertexA);
    float edgeLenA = (float)(m_kBoxBasisVector(axisA) * -2.0);

    float ab = (float)(edgeB(axisA) * edgeLenA);
    float bb = (float)(m_kThirdBasisVector(axisB) * m_kThirdBasisVector(axisB) * 4.0);
    float aa = edgeLenA * edgeLenA;
    float db = diff.dot3(edgeB);
    float denom = bb * aa - ab * ab;
    float absDenom = hkFabs(denom);
    float da = diff(axisA) * edgeLenA;
    float t = da * bb - db * ab;

    if (t <= (float)(absDenom * 1.1920928955078125e-07) || t >= absDenom * DAT_00e86158)
        return hkBool(false);
    // Guess at the source: the division is written in two identical arms. They merge after register
    // assignment and the test disappears; the block boundary is what keeps ab (live through here) in
    // memory and the edge-B lanes on the FPU stack. With a single plain division ab is held on the FPU
    // stack instead and edgeB.z is reloaded (frame 0x64). The condition itself is unknown.
    if (axisA == axisB)
        t = t / absDenom;
    else
        t = t / absDenom;
    float u = t * ab - db;
    if (u <= bb * 1.1920928955078125e-07 || u >= (float)(bb * DAT_00e86158))
        return hkBool(false);

    vertexA(axisA) = t * edgeLenA + vertexA(axisA);
    hkVector4 edgeA;
    edgeA.setZero4();
    edgeA(axisA) = (float)(edgeLenA * 0.5);

    hkVector4 normal;
    normal.setCross(edgeA, edgeB);
    float length = normal.normalizeWithLength3();
    if (length < m_minNormalLength)
        return hkBool(false);

    if (signA.dot3(normal) < 0.0f)
        normal.setNeg4(normal);

    float dist = normal.dot3(diff);
    if (dist > m_fScalar)
        return hkBool(false);

    contact->m_vContactPosition = vertexA;
    contact->m_vHitNormal.setNeg4(normal);
    contact->m_fClosestPointDistanceSquared = dist;
    return hkBool(true);
}
}   // namespace f3m_00a3cc40

// @f3 0x00a36bd0 (community match, verified in this file)
namespace f3m_00a36bd0 {
// hkGskManifold_convertEdgePoint (Havok 5.5.0, hkpInternal hkpGskManifoldUtil.cpp): a file-local function, so /O2
// gives it a register calling convention (contact point and output in registers, work on the stack). Layouts and
// inlines follow the Havok 5.5 headers (FPU build, HK_DISABLE_VECTOR4_CONSTRUCTORS); the same code is in
// fnv_decomp's hkpgskmanifoldutil.cpp (edgePoint), there through the SSE helpers.
namespace f3h_00a36bd0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUchar;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef int hkBool32;
typedef hkUint16 hkContactPointId;

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkVector4Comparison
{
public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_ZW = 3,
        MASK_Y = 4,
        MASK_YW = 5,
        MASK_YZ = 6,
        MASK_YZW = 7,
        MASK_X = 8,
        MASK_XW = 9,
        MASK_XZ = 10,
        MASK_XZW = 11,
        MASK_XY = 12,
        MASK_XYW = 13,
        MASK_XYZ = 14,
        MASK_XYZW = 15
    };

    hkBool32 anyIsSet(Mask m) const { return m_mask & m; }

    int m_mask;
};

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkSimdReal getSimdAt(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
    {
        hkReal t = hkReal(rt);
        hkReal s = 1.0f - t;
        hkVector4& d = *this;
        d(0) = s * v0(0) + t * v1(0);
        d(1) = s * v0(1) + t * v1(1);
        d(2) = s * v0(2) + t * v1(2);
        d(3) = s * v0(3) + t * v1(3);
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkSimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkVector4Comparison compareLessThanZero4() const
    {
        hkVector4Comparison ret;
        ret.m_mask =
            ((x < 0) ? hkVector4Comparison::MASK_X : 0) |
            ((y < 0) ? hkVector4Comparison::MASK_Y : 0) |
            ((z < 0) ? hkVector4Comparison::MASK_Z : 0) |
            ((w < 0) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
};

namespace hkVector4Util
{
    __forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                                 const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
    {
        dotsOut(0) = a0.dot3(b0);
        dotsOut(1) = a1.dot3(b1);
        dotsOut(2) = a2.dot3(b2);
        dotsOut(3) = 0;
    }
}

class hkpGskManifold
{
public:
    struct ContactPoint
    {
        hkUchar m_dimA;
        hkUchar m_dimB;
        hkContactPointId m_id;
        union
        {
            hkUchar m_vert[4]; // vertex indices into the shared vertex array, times sizeof(hkVector4)
            hkUint32 m_allVerts;
        };
    };
};

// The work data of hkpGskManifoldUtil.cpp (private to that file in the SDK).
struct hkpGskManifoldWork
{
    hkVector4 m_vertices[16];
    hkVector4 m_masterNormal;
    hkPadSpu<hkReal> m_radiusA;
    hkPadSpu<hkReal> m_radiusB;
    hkPadSpu<hkReal> m_tolerance;
    hkPadSpu<hkReal> m_toleranceSquared;

    __forceinline const hkVector4& vertex(int off) const
    {
        return *reinterpret_cast<const hkVector4*>(reinterpret_cast<const char*>(m_vertices) + off);
    }
};

struct hkGskManifoldConvertOut
{
    hkVector4 m_pointA;
    hkVector4 m_delta;
    hkVector4 m_normal;
};

// Edge of A against point of B: returns 1 when the point is off the edge or too far away.
static int FUN_00a36bd0(const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& cp, hkGskManifoldConvertOut& out)
{
    const hkVector4& a = work.vertex(cp.m_vert[0]);
    const hkVector4& b = work.vertex(cp.m_vert[1]);
    const hkVector4& c = work.vertex(cp.m_vert[2]);
    out.m_normal = work.m_masterNormal;
    
    hkVector4 edge; edge.setSub4(b, a);
    hkVector4 first; first.setSub4(b, c);
    hkVector4 second; second.setSub4(c, a);
    hkVector4 area; area.setCross(edge, first);
    hkVector4 weights;
    hkVector4Util::dot3_3vs3(first, edge, second, edge, area, area, weights);
    hkReal squared = edge.lengthSquared3();
    int negative = weights.compareLessThanZero4().anyIsSet(hkVector4Comparison::MASK_XY);
    if (weights(3) > work.m_toleranceSquared * squared || negative)
    {
        return 1;
    }
    out.m_pointA.setInterpolate4(b, a, weights.getSimdAt(0) / (weights.getSimdAt(0) + weights.getSimdAt(1)));
    out.m_delta.setSub4(out.m_pointA, c);
    return 0;
}

// Callers in the same file (the real one is hkGskManifold_convertFeature).
int hkGskManifoldCallerStandIn(const hkpGskManifoldWork& w, const hkpGskManifold::ContactPoint* cp, hkGskManifoldConvertOut* out)
{
    return FUN_00a36bd0(w, cp[0], out[0]) + FUN_00a36bd0(w, cp[1], out[1]);
}

} // namespace f3h_00a36bd0
}   // namespace f3m_00a36bd0

// @f3 0x00a36310 (community match, verified in this file)
namespace f3m_00a36310 {
struct __declspec(align(16)) hkQuadReal
{
    float x, y, z, w;
};

class hkVector4
{
public:
    hkQuadReal m_quad;

    float& operator()(int i) { return (&m_quad.x)[i]; }
    const float& operator()(int i) const { return (&m_quad.x)[i]; }

    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_quad.x = a.m_quad.x - b.m_quad.x;
        m_quad.y = a.m_quad.y - b.m_quad.y;
        m_quad.z = a.m_quad.z - b.m_quad.z;
        m_quad.w = a.m_quad.w - b.m_quad.w;
    }
    void setSubZW(const hkVector4& a, const hkVector4& b)
    {
        m_quad.z = a.m_quad.z - b.m_quad.z;
        m_quad.w = a.m_quad.w - b.m_quad.w;
    }
    void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        m_quad.x = nx;
        m_quad.y = ny;
        m_quad.z = nz;
        m_quad.w = 0.0f;
    }
    float dot3(const hkVector4& a) const
    {
        return m_quad.x * a.m_quad.x + m_quad.y * a.m_quad.y + m_quad.z * a.m_quad.z;
    }
    void setInterpolate4(const hkVector4& v0, const hkVector4& v1, float t)
    {
        const float s = 1.0f - t;
        m_quad.x = s * v0.m_quad.x + t * v1.m_quad.x;
        m_quad.y = s * v0.m_quad.y + t * v1.m_quad.y;
        m_quad.z = s * v0.m_quad.z + t * v1.m_quad.z;
        m_quad.w = s * v0.m_quad.w + t * v1.m_quad.w;
    }
    void operator=(const hkVector4& v)
    {
        m_quad.x = v.m_quad.x;
        m_quad.y = v.m_quad.y;
        m_quad.z = v.m_quad.z;
        m_quad.w = v.m_quad.w;
    }
};

struct GskCache
{
    int unk00;
    unsigned char m_vertices[4];
};

struct GskVerts
{
    hkVector4 verts[16];
    hkVector4 extra;
};

struct GskOut
{
    hkVector4 pointA;
    hkVector4 normal;
    hkVector4 extra;
};


static __declspec(noinline) int FUN_00a36310(const GskCache* cache, GskOut* out, const GskVerts* v)
{
    const hkVector4& A = *(const hkVector4*)((const char*)v + cache->m_vertices[0]);
    const hkVector4& B = *(const hkVector4*)((const char*)v + cache->m_vertices[1]);
    const hkVector4& C = *(const hkVector4*)((const char*)v + cache->m_vertices[2]);
    const hkVector4& D = *(const hkVector4*)((const char*)v + cache->m_vertices[3]);
    hkVector4 p;

    hkVector4 e0; e0.m_quad.x = B.m_quad.x - A.m_quad.x; e0.m_quad.y = B.m_quad.y - A.m_quad.y; e0.setSubZW(B, A);
    hkVector4 e1; e1.setSub4(D, C);
    hkVector4 e2; e2.m_quad.x = A.m_quad.x - C.m_quad.x; e2.m_quad.y = A.m_quad.y - C.m_quad.y; e2.m_quad.z = A.m_quad.z - C.m_quad.z; e2.m_quad.w = A.m_quad.w - C.m_quad.w;
    hkVector4 e3; e3.m_quad.x = B.m_quad.x - D.m_quad.x; e3.m_quad.y = B.m_quad.y - D.m_quad.y; e3.setSubZW(B, D);

    hkVector4 n; n.setCross(e0, e1);
    hkVector4 m1; m1.setCross(e0, n);
    hkVector4 m0; m0.setCross(e1, n);

    out->extra = v->extra;

    hkVector4 d;
    d(0) = m0.dot3(e2);
    d(1) = m1.dot3(e2);
    d(2) = m0.dot3(e3);
    d(3) = m1.dot3(e3);

    int mask = (d(0) < 0.0f ? 8 : 0) | (d(1) < 0.0f ? 4 : 0) | (d(2) < 0.0f ? 2 : 0) | (d(3) < 0.0f ? 1 : 0);
    if (mask != 12 && mask != 3)
        return 1;

    out->pointA.setInterpolate4(A, B, d(0) / (d(0) - d(2)));
    p.setInterpolate4(C, D, d(1) / (d(1) - d(3)));
    out->normal.setSub4(out->pointA, p);
    return 0;
}

volatile int g_in0; volatile int g_in1; volatile int g_in2; volatile int g_out;
void caller_of_FUN_00a36310()
{
    g_out = FUN_00a36310((const GskCache*)g_in0, (GskOut*)g_in1, (const GskVerts*)g_in2);
}
}   // namespace f3m_00a36310

// @f3 0x00a36950 (community match, verified in this file)
namespace f3m_00a36950 {
// hkGskManifold_convertPointEdge (Havok 5.5.0, hkpInternal hkpGskManifoldUtil.cpp): a file-local function, so /O2
// gives it a register calling convention (eax = contact point, edi = output, work on the stack). Layouts and
// inlines follow the Havok 5.5 headers (FPU build, HK_DISABLE_VECTOR4_CONSTRUCTORS); the same code is in
// fnv_decomp's hkpgskmanifoldutil.cpp (pointEdge), there through the SSE helpers.
namespace f3h_00a36950 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUchar;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef int hkBool32;
typedef hkUint16 hkContactPointId;

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkVector4Comparison
{
public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_ZW = 3,
        MASK_Y = 4,
        MASK_YW = 5,
        MASK_YZ = 6,
        MASK_YZW = 7,
        MASK_X = 8,
        MASK_XW = 9,
        MASK_XZ = 10,
        MASK_XZW = 11,
        MASK_XY = 12,
        MASK_XYW = 13,
        MASK_XYZ = 14,
        MASK_XYZW = 15
    };

    hkBool32 anyIsSet(Mask m) const { return m_mask & m; }

    int m_mask;
};

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkSimdReal getSimdAt(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
    {
        hkReal t = hkReal(rt);
        hkReal s = 1.0f - t;
        hkVector4& d = *this;
        d(0) = s * v0(0) + t * v1(0);
        d(1) = s * v0(1) + t * v1(1);
        d(2) = s * v0(2) + t * v1(2);
        d(3) = s * v0(3) + t * v1(3);
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkSimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkVector4Comparison compareLessThanZero4() const
    {
        hkVector4Comparison ret;
        ret.m_mask =
            ((x < 0) ? hkVector4Comparison::MASK_X : 0) |
            ((y < 0) ? hkVector4Comparison::MASK_Y : 0) |
            ((z < 0) ? hkVector4Comparison::MASK_Z : 0) |
            ((w < 0) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
};

namespace hkVector4Util
{
    __forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                                 const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
    {
        dotsOut(0) = a0.dot3(b0);
        dotsOut(1) = a1.dot3(b1);
        dotsOut(2) = a2.dot3(b2);
        dotsOut(3) = 0;
    }
}

class hkpGskManifold
{
public:
    struct ContactPoint
    {
        hkUchar m_dimA;
        hkUchar m_dimB;
        hkContactPointId m_id;
        union
        {
            hkUchar m_vert[4]; // vertex indices into the shared vertex array, times sizeof(hkVector4)
            hkUint32 m_allVerts;
        };
    };
};

// The work data of hkpGskManifoldUtil.cpp (private to that file in the SDK).
struct hkpGskManifoldWork
{
    hkVector4 m_vertices[16];
    hkVector4 m_masterNormal;
    hkPadSpu<hkReal> m_radiusA;
    hkPadSpu<hkReal> m_radiusB;
    hkPadSpu<hkReal> m_tolerance;
    hkPadSpu<hkReal> m_toleranceSquared;

    __forceinline const hkVector4& vertex(int off) const
    {
        return *reinterpret_cast<const hkVector4*>(reinterpret_cast<const char*>(m_vertices) + off);
    }
};

struct hkGskManifoldConvertOut
{
    hkVector4 m_pointA;
    hkVector4 m_delta;
    hkVector4 m_normal;
};

// Point of A against edge of B: returns 1 when the point is off the edge or too far away.
static int FUN_00a36950(const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& cp, hkGskManifoldConvertOut& out)
{
    const hkVector4& a = work.vertex(cp.m_vert[0]);
    const hkVector4& b = work.vertex(cp.m_vert[1]);
    const hkVector4& c = work.vertex(cp.m_vert[2]);
    out.m_pointA = a;
    out.m_normal = work.m_masterNormal;
    hkVector4 edge;
    edge.setSub4(c, b);
    hkVector4 first;
    first.setSub4(c, a);
    hkVector4 second;
    second.setSub4(a, b);
    hkVector4 area;
    area.setCross(edge, first);
    hkVector4 weights;
    hkVector4Util::dot3_3vs3(first, edge, second, edge, area, area, weights);
    hkReal squared = edge.lengthSquared3();
    int negative = weights.compareLessThanZero4().anyIsSet(hkVector4Comparison::MASK_XY);
    if (weights(3) > work.m_toleranceSquared * squared || negative)
    {
        return 1;
    }
    hkVector4 closest;
    closest.setInterpolate4(b, c, weights.getSimdAt(0) / (weights.getSimdAt(0) + weights.getSimdAt(1)));
    out.m_delta.setSub4(a, closest);
    return 0;
}

// Callers in the same file (the real one is hkGskManifold_convertFeature).
int hkGskManifoldCallerStandIn(const hkpGskManifoldWork& w, const hkpGskManifold::ContactPoint* cp, hkGskManifoldConvertOut* out)
{
    return FUN_00a36950(w, cp[0], out[0]) + FUN_00a36950(w, cp[1], out[1]);
}

} // namespace f3h_00a36950
}   // namespace f3m_00a36950

// @f3 0x00a25d10 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a25d10 {
// claim clm_62d6abb583da42379aa0 -- FUN_00a25d10 at 0x00a25d10, 48 bytes
// Shape: deleting-destructor-like member -- run the destructor, then, if (flags & 1),
// return the object's block to the thread-local heap with the recorded size and tag 0x21.


namespace f3m_00a25d10 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A25d10Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct A25d10 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a25ce0();
    A25d10* FUN_00a25d10(unsigned int flags);
};

// pdb: hkpBroadPhase::`scalar deleting destructor' | hkpBroadPhase.obj | fnv360_0822_retail, vtable_prefix, high
A25d10* A25d10::FUN_00a25d10(unsigned int flags)
{
    FUN_00a25ce0();
    if (flags & 1) {
        A25d10Heap* heap = (A25d10Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x21);
    }
    return this;
}
}
}   // namespace f3m_00a25d10

// @f3 0x00a25d40 (community match, verified in this file)
namespace f3m_00a25d40 {
// pdb: hkSingleton<hkTraceStream>::operator= | hkTraceStream.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkTraceStream::dontPrintf)
// pdb params: other
void FUN_00a25d40()
{
}
}   // namespace f3m_00a25d40

// @f3 0x00a35eb0 (community match, verified in this file)
namespace f3m_00a35eb0 {
// hkGskManifold_convertFacePoint of the Havok 5.5.0 SDK (hkpInternal, hkpGskManifoldUtil.obj), under the pack's
// name: a file-static helper that turns one manifold contact point (a face of A, a point of B) into the point on A,
// A minus B, the face normal (flipped to the master normal's side) and the mask of the face edges the point lies
// outside of. Written after the library's debug records (parameters, locals, line table) with the SDK's own headers,
// then preprocessed and cut down mechanically (hkreduce): the declarations below are the SDK headers' text.
// standInCaller_00a35eb0 at the end is a STAND-IN, not game code: the real caller, hkGskManifold_convertFeature in the
// same library object, expands the helper inline, and nothing in the game image calls it; the stand-in only makes the compiler emit the helper with the private register
// convention it has in the library. The helper's bytes were measured not to depend on the stand-in.
namespace f3m_00a35eb0 {

typedef unsigned char	hkUchar;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
typedef hkUint16 hkContactPointId;
namespace hkVector4Util
{
__forceinline void __cdecl dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut);
}
inline void __cdecl hkVector4Util::dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( vectorIn );
	dotsOut(1) = a1.dot3( vectorIn );
	dotsOut(2) = a2.dot3( vectorIn );
	dotsOut(3) = a3.dot3( vectorIn );
}
struct hkpGskManifold
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpGskManifold), HK_MEMORY_CLASS_MANIFOLD); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	struct ContactPoint
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpGskManifold::ContactPoint), HK_MEMORY_CLASS_MANIFOLD); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUchar m_dimA;
		hkUchar m_dimB;
		hkContactPointId m_id;
		union
		{
			hkUchar m_vert[4];
			hkUint32 m_allVerts;
		};
		void zeroVerts(){ m_allVerts = 0; }
	};
	typedef hkUint16 VertexId;
	enum { MAX_POINTS = 4 };
	enum { MAX_VERTICES = MAX_POINTS * 4  };
	__forceinline VertexId getVertexId( const ContactPoint& cp, int vertNr ) const;
	__forceinline void init();
	__forceinline hkpGskManifold();
	__forceinline int getTotalSizeInBytes() const;
	__forceinline VertexId* getVertexIds();
	__forceinline const VertexId* getVertexIds() const;
	hkUchar  m_numVertsA;
	hkUchar  m_numVertsB;
	hkUchar  m_numContactPoints;
	ContactPoint m_contactPoints[ MAX_POINTS ];
	hkUchar m_padding[ MAX_VERTICES * sizeof(VertexId) ];
};
struct hkpGskManifoldWork
{
	hkVector4 m_vertices[16];
	hkVector4 m_masterNormal;
	hkReal m_radiusA;
	hkReal m_radiusB;
	hkReal m_keepContact;
	hkReal m_radiusSumSqrd;
};
struct hkGskManifoldConvertOut
{
	hkVector4 m_pointOnA;
	hkVector4 m_AminusB;
	hkVector4 m_normal;
};
static int FUN_00a35eb0( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& vertA0 = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[0] );
	const hkVector4& vertA1 = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[1] );
	const hkVector4& vertA2 = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[2] );
	const hkVector4& vertB  = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[3] );
	out.m_pointOnA = vertB;
	out.m_AminusB.setSub4( vertA0, vertB );
	hkVector4 edge0; edge0.setSub4( vertA2, vertA1 );
	hkVector4 edge1; edge1.setSub4( vertA0, vertA2 );
	hkVector4 edge2; edge2.setSub4( vertA1, vertA0 );
	hkVector4 normal; normal.setCross( edge0, edge1 );
	normal.normalize3();
	hkVector4 a1; a1.setSub4( vertB, vertA1 );
	hkVector4 a2; a2.setSub4( vertB, vertA2 );
	hkVector4 a0; a0.setSub4( vertB, vertA0 );
	hkVector4 pt0; pt0.setCross( a1, edge0 );
	hkVector4 pt1; pt1.setCross( a2, edge1 );
	hkVector4 pt2; pt2.setCross( a0, edge2 );
	hkVector4 dots; hkVector4Util::dot3_1vs4( normal, pt0, pt1, pt2, work.m_masterNormal, dots );
	const hkReal dist = out.m_AminusB.dot3( normal );
	out.m_pointOnA.setAddMul4( vertB, normal, dist );
	out.m_normal = normal;
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask & hkVector4Comparison::MASK_W )
	{
		out.m_normal.setNeg4( normal );
	}
	return (~mask) & hkVector4Comparison::MASK_XYZ;
}
int standInCaller_00a35eb0( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	return FUN_00a35eb0( work, feature, out );
}

}
}   // namespace f3m_00a35eb0

// @f3 0x00a35aa0 (community match, verified in this file)
namespace f3m_00a35aa0 {
// hkGskManifold_convertPointFace of the Havok 5.5.0 SDK (hkpInternal, hkpGskManifoldUtil.obj), under the pack's
// name: a file-static helper that turns one manifold contact point (a point of A, a face of B) into the point on A,
// A minus B, the face normal (flipped to the master normal's side) and the mask of the face edges the point lies
// outside of. Written after the library's debug records (parameters, locals, line table) with the SDK's own headers,
// then preprocessed and cut down mechanically (hkreduce): the declarations below are the SDK headers' text.
// standInCaller_00a35aa0 at the end is a STAND-IN, not game code: the real caller, hkGskManifold_convertFeature in the
// same library object, expands the helper inline, and nothing in the game image calls it; the stand-in only makes the compiler emit the helper with the private register
// convention it has in the library. The helper's bytes were measured not to depend on the stand-in.
namespace f3m_00a35aa0 {

typedef unsigned char	hkUchar;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
typedef hkUint16 hkContactPointId;
namespace hkVector4Util
{
__forceinline void __cdecl dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut);
}
inline void __cdecl hkVector4Util::dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( vectorIn );
	dotsOut(1) = a1.dot3( vectorIn );
	dotsOut(2) = a2.dot3( vectorIn );
	dotsOut(3) = a3.dot3( vectorIn );
}
struct hkpGskManifold
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpGskManifold), HK_MEMORY_CLASS_MANIFOLD); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	struct ContactPoint
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpGskManifold::ContactPoint), HK_MEMORY_CLASS_MANIFOLD); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MANIFOLD); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUchar m_dimA;
		hkUchar m_dimB;
		hkContactPointId m_id;
		union
		{
			hkUchar m_vert[4];
			hkUint32 m_allVerts;
		};
		void zeroVerts(){ m_allVerts = 0; }
	};
	typedef hkUint16 VertexId;
	enum { MAX_POINTS = 4 };
	enum { MAX_VERTICES = MAX_POINTS * 4  };
	__forceinline VertexId getVertexId( const ContactPoint& cp, int vertNr ) const;
	__forceinline void init();
	__forceinline hkpGskManifold();
	__forceinline int getTotalSizeInBytes() const;
	__forceinline VertexId* getVertexIds();
	__forceinline const VertexId* getVertexIds() const;
	hkUchar  m_numVertsA;
	hkUchar  m_numVertsB;
	hkUchar  m_numContactPoints;
	ContactPoint m_contactPoints[ MAX_POINTS ];
	hkUchar m_padding[ MAX_VERTICES * sizeof(VertexId) ];
};
struct hkpGskManifoldWork
{
	hkVector4 m_vertices[16];
	hkVector4 m_masterNormal;
	hkReal m_radiusA;
	hkReal m_radiusB;
	hkReal m_keepContact;
	hkReal m_radiusSumSqrd;
};
struct hkGskManifoldConvertOut
{
	hkVector4 m_pointOnA;
	hkVector4 m_AminusB;
	hkVector4 m_normal;
};
static int FUN_00a35aa0( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& vertA  = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[0] );
	const hkVector4& vertB0 = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[1] );
	const hkVector4& vertB1 = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[2] );
	const hkVector4& vertB2 = *hkAddByteOffsetConst( &work.m_vertices[0], feature.m_vert[3] );
	out.m_pointOnA = vertA;
	out.m_AminusB.setSub4( vertA, vertB0 );
	hkVector4 edge0; edge0.setSub4( vertB2, vertB1 );
	hkVector4 edge1; edge1.setSub4( vertB0, vertB2 );
	hkVector4 edge2; edge2.setSub4( vertB1, vertB0 );
	hkVector4 normal; normal.setCross( edge0, edge1 );
	normal.normalize3();
	hkVector4 a1; a1.setSub4( vertA, vertB1 );
	hkVector4 a2; a2.setSub4( vertA, vertB2 );
	hkVector4 a0; a0.setSub4( vertA, vertB0 );
	hkVector4 pt0; pt0.setCross( a1, edge0 );
	hkVector4 pt1; pt1.setCross( a2, edge1 );
	hkVector4 pt2; pt2.setCross( a0, edge2 );
	hkVector4 dots; hkVector4Util::dot3_1vs4( normal, pt0, pt1, pt2, work.m_masterNormal, dots );
	out.m_normal = normal;
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask & hkVector4Comparison::MASK_W )
	{
		out.m_normal.setNeg4( normal );
	}
	return (~mask) & hkVector4Comparison::MASK_XYZ;
}
int standInCaller_00a35aa0( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	return FUN_00a35aa0( work, feature, out );
}

}
}   // namespace f3m_00a35aa0

// @f3 0x00a2e9c0 (community match, verified in this file)
#pragma intrinsic(fabs)
namespace f3m_00a2e9c0 {

extern "C" double __cdecl fabs(double);
namespace f3w_a2e9c0 {
__declspec(align(16)) struct hkVec4 {
    float x, y, z, w;
    __forceinline void setSub4(const hkVec4& v0, const hkVec4& v1) {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline float dot3(const hkVec4& a) const {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
};

// pdb: hkGskRecalcContact_pointTriangle | hkpGsk.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkGskCalcSupportDistSquared)
static float __cdecl FUN_00a2e9c0(const hkVec4& support, const hkVec4& newPoint, const hkVec4& oldPoint)
{
    hkVec4 diff0;
    diff0.setSub4(newPoint, oldPoint);
    float dot0 = diff0.dot3(support);
    return (float)(dot0 * ::fabs(dot0));
}

float KeepA2E9C0(const hkVec4& a, const hkVec4& b, const hkVec4& c) {
    return FUN_00a2e9c0(a, b, c) + FUN_00a2e9c0(c, a, b);
}
}
}   // namespace f3m_00a2e9c0

// @f3 0x00a2e7f0 (community match, verified in this file)
namespace f3m_00a2e7f0 {
namespace f3m_00a284b0 { bool __cdecl FUN_00a284b0(int); }
namespace N_A2D530 {
typedef float hkReal_X;
typedef unsigned int hkUint32_X;
struct Scalar { float x; Scalar(float f):x(f){} operator float() const {return x;} };


inline Scalar ScalarValue(float x) { Scalar r(x); return r; }

inline Scalar CrossRatio(float l, float h) { const float dl = l; const float dh = h; const float ratio = dl / (dl - dh); Scalar r(ratio); return r; }
struct __declspec(align(16)) hkVector4_X {
    float v[4];
    float& operator()(int i) { return v[i]; }
    const float& operator()(int i) const { return v[i]; }
    
    __forceinline void operator=(const hkVector4_X& b) { const float x=b(0); const float y=b(1); const float z=b(2); const float w=b(3); v[0]=x; v[1]=y; v[2]=z; v[3]=w; }
    __forceinline void set(float a,float b,float c,float d) { v[0]=a;v[1]=b;v[2]=c;v[3]=d; }
    __forceinline void setAll3(float f) { v[0]=f;v[1]=f;v[2]=f;v[3]=f; }
    __forceinline void sub4(const hkVector4_X& b) { v[0]-=b(0);v[1]-=b(1);v[2]-=b(2);v[3]-=b(3); }
    __forceinline void setSub4(const hkVector4_X& a,const hkVector4_X& b) {v[0]=a.v[0]-b(0);v[1]=a.v[1]-b(1);v[2]=a.v[2]-b(2);v[3]=a.v[3]-b(3);}
    __forceinline void setAdd4(const hkVector4_X& a,const hkVector4_X& b) {v[0]=a.v[0]+b(0);v[1]=a.v[1]+b(1);v[2]=a.v[2]+b(2);v[3]=a.v[3]+b(3);}
    __forceinline void mul4(float f) { v[0]*=f;v[1]*=f;v[2]*=f;v[3]*=f; }
    __forceinline void mul4(const hkVector4_X& b) {v[0]*=b(0);v[1]*=b(1);v[2]*=b(2);v[3]*=b(3);}
    __forceinline void setMul4(const hkVector4_X& a,const hkVector4_X& b) {v[0]=a.v[0]*b(0);v[1]=a.v[1]*b(1);v[2]=a.v[2]*b(2);v[3]=a.v[3]*b(3);}
    __forceinline void setInterpolate4(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        v[0]=s*a(0)+t*b(0);v[1]=s*a(1)+t*b(1);v[2]=s*a(2)+t*b(2);v[3]=s*a(3)+t*b(3);
    }
    
    __forceinline void setInterpolate4Stored(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        const float x=s*a(0)+t*b(0); const float y=s*a(1)+t*b(1); const float z=s*a(2)+t*b(2); const float w=s*a(3)+t*b(3);
        v[0]=x; v[1]=y; v[2]=z; v[3]=w;
    }
    
    __forceinline void setHitInterpolate4Right(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        const float x=s*a(0)+(t*b(0)); const float y=s*a(1)+t*b(1); const float z=s*a(2)+t*b(2); const float w=s*a(3)+t*b(3);
        v[0]=x; v[1]=y; v[2]=z; v[3]=w;
    }
    __forceinline void setHitInterpolate4Left(const hkVector4_X& a,const hkVector4_X& b,const Scalar& fraction) {
        float t=fraction; float s=1.0f-t;
        const float x=s*a(0)+(t*b(0)); const float y=s*a(1)+(t*b(1)); const float z=s*a(2)+(t*b(2)); const float w=s*a(3)+(t*b(3));
        v[0]=x; v[1]=y; v[2]=z; v[3]=w;
    }
};
struct VectorPropertyRecord {
    __forceinline VectorPropertyRecord& operator=(const VectorPropertyRecord& o) {return FUN_00a2d4d0(o);}
    hkVector4_X m_kVectorBeforeIndex, SetCenterPosition;
    float m_fValueAtOffset20;
    int m_iIndex;
    float m_kVectorAfterIndex;
    unsigned m_uiPropertyCount;
    unsigned m_kProperties[1];
    __declspec(noinline) VectorPropertyRecord& FUN_00a2d4d0(const VectorPropertyRecord& o) {
        m_kVectorBeforeIndex=o.m_kVectorBeforeIndex; SetCenterPosition=o.SetCenterPosition;
        m_fValueAtOffset20=o.m_fValueAtOffset20; m_iIndex=o.m_iIndex;
        m_kVectorAfterIndex=o.m_kVectorAfterIndex; m_uiPropertyCount=o.m_uiPropertyCount;
        m_kProperties[0]=o.m_kProperties[0]; return *this;
    }
};
struct TwoPointVectorBundles { hkVector4_X m_kPointBundles[2]; };
struct StreamRecord {
    unsigned unk00,unk04,unk08;
    __forceinline void FUN_00923070(void*,int);
    StreamRecord& FUN_00943710(const char*);
    __forceinline void FUN_00943a60();
};
struct ErrorRecord {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int message(int,int,const char*,const char*,int);
};
extern ErrorRecord* DAT_010f3364;
extern const char DAT_00e85ef0[];
extern const char DAT_00e85eb0[];
struct ShapeBuffer { unsigned data[128]; };
struct ShapeRecord;
struct ContainerRecord {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual const ShapeRecord* GetShapeForKey(unsigned,ShapeBuffer&) const;
};
struct ShapeBase0 { virtual void b0(); unsigned b4,b8,bc; };
struct CollShape : ShapeBase0, ContainerRecord { };
struct ShapeRecord {
    unsigned unk00,unk04,unk08;
    int m_type;
    unsigned unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    const CollShape* m_child;
    const CollShape* getShapeCollection() const { return m_child; }
    int getType() const { return m_type; }
};
struct BodyRecord {
    const ShapeRecord* m_pCollisionShape;
    unsigned m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const BodyRecord* m_parent;
    BodyRecord(const BodyRecord* p) {m_parent=p;m_pMotionState=p->m_pMotionState;}
    const ShapeRecord* getShape() const {return m_pCollisionShape;}
    __forceinline void SetCollisionShapeAndKey(const ShapeRecord* p,unsigned k) {m_pCollisionShape=p;m_uiCollisionShapeKey=k;}
};
struct BoolRecord { char value; operator bool() const {return value!=0;} };
struct ShapeSweepParameters;
struct FilterRecord {
    virtual void v0();
    virtual BoolRecord IsCollisionEnabled(const ShapeSweepParameters&,const BodyRecord&,const BodyRecord&,const ContainerRecord&,unsigned) const;
};
struct CollectorRecord { void* vtable; float m_fEarlyOutDistance; float getEarlyOutDistance()const{return m_fEarlyOutDistance;} };
struct DispatcherRecord {
    typedef void (__cdecl* LinearCastFunc)(const BodyRecord&,const BodyRecord&,const ShapeSweepParameters&,CollectorRecord&,CollectorRecord*);
    struct Entry {void* create;void* penetration;void* closest;LinearCastFunc cast;unsigned flags;};
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    Entry m_agent2Funcs[64];
    LinearCastFunc getLinearCastFunc(int a,int b) const {return m_agent2Funcs[m_agent2TypeMap[a][b]].cast;}
};
struct ShapeSweepParameters { DispatcherRecord* m_pCollisionDispatcher; unsigned unk04; const FilterRecord* m_iFilter; };
struct CodeRecord {unsigned unk00,unk04,unk08,unk0c; struct Info {hkVector4_X m_offset;} m_info; const unsigned char* m_data;};
struct MoppPrimitiveQueryContext {
    void* m_pPrimitiveInfoArray;int unk04,unk08,unk0c;
    static int read24(const unsigned char* pc) {return ((pc[0]<<8)+pc[1])*256+pc[2];}
};
struct MoppCastMachine : MoppPrimitiveQueryContext {
    struct MoppCastQueryData {hkVector4_X m_vFrom,m_vTo,SetCenterPosition;const ShapeSweepParameters* m_pCollisionInput;const BodyRecord* m_pFirstCastBody;const BodyRecord* m_pSecondCastBody;};
    const CodeRecord* m_pMoppCode;
    float m_vRayDirectionVector;
    int m_iRayDirectionIndex;
    float m_fFirstRayCastValue,m_fSecondRayCastValue;
    CollectorRecord* m_pPointCollector;
    CollectorRecord* m_pClosestPointCollector;
    const MoppCastQueryData* m_pRayCastInput;
    int m_iCurrentChunkId;
    void FUN_00a2d530(const VectorPropertyRecord*,const unsigned char*,TwoPointVectorBundles*,int);
    
    __forceinline float GetEarlyOut() const { const float f = m_fFirstRayCastValue; return f; }
    __forceinline void AddHit(unsigned key,const unsigned*,unsigned long) {
        const ContainerRecord* shapeContainer=m_pRayCastInput->m_pSecondCastBody->getShape()->getShapeCollection();
        ShapeBuffer shapeBuffer;
        const ShapeRecord* childShape=shapeContainer->GetShapeForKey(key,shapeBuffer);
        if (!m_pRayCastInput->m_pCollisionInput->m_iFilter->IsCollisionEnabled(*m_pRayCastInput->m_pCollisionInput,*m_pRayCastInput->m_pFirstCastBody,*m_pRayCastInput->m_pSecondCastBody,*shapeContainer,key)) return;
        BodyRecord childBodyB(m_pRayCastInput->m_pSecondCastBody);
        childBodyB.SetCollisionShapeAndKey(childShape,key);
        int typeB=childShape->getType();
        DispatcherRecord::LinearCastFunc linCastFunc=m_pRayCastInput->m_pCollisionInput->m_pCollisionDispatcher->getLinearCastFunc(m_iRayDirectionIndex,typeB);
        linCastFunc(*m_pRayCastInput->m_pFirstCastBody,childBodyB,*m_pRayCastInput->m_pCollisionInput,*m_pPointCollector,m_pClosestPointCollector);
        m_fFirstRayCastValue=m_pPointCollector->getEarlyOutDistance();
    }
};
void MoppCastMachine::FUN_00a2d530(const VectorPropertyRecord* query, const unsigned char* PC,
                                   TwoPointVectorBundles fQuery[1], int chunkOffset)
{
    VectorPropertyRecord scaledQuery;
    do
    {
        const int command = PC[0];
        int tdir = 999;
        int offsetLB;
        int offsetRB;
        hkReal_X positionl;
        hkReal_X positionh;
        hkReal_X foffsetl;
        hkReal_X foffseth;
        int offsetl;
        int offseth;
        switch (command)
        {
        case 0x13: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x14: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2));
            positionh = (fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2));
            goto do_compareN4;
        }
        case 0x15: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](2));
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x16: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x17: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x18: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x19: {
            foffseth = hkReal_X(PC[1] * 3);
            foffsetl = hkReal_X(PC[2] * 3);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1a: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1b: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1c: {
            foffseth = hkReal_X(PC[1] * 3 - 510);
            foffsetl = hkReal_X(PC[2] * 3 - 510);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x20:
        case 0x21:
        case 0x22:
            tdir = command - 0x20;
            foffsetl = hkReal_X(PC[1]);
            foffseth = foffsetl + 1.0;
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            PC += 3;
            offsetLB = 0;
            offsetRB = PC[-1];
            goto do_compare;
        case 0x23:
        case 0x24:
        case 0x25:
            tdir = command - 0x23;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            offsetLB = (PC[3] << 8) + PC[4];
            PC += 7;
            offsetRB = (PC[-2] << 8) + PC[-1];
            goto do_compare;
        case 0x10:
        case 0x11:
        case 0x12:
            tdir = command - 0x10;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
        do_compareN4:
            PC += 4;
            offsetLB = 0;
            offsetRB = PC[-1];
        do_compare:
            if (positionh < foffsetl && positionl < foffsetl)
            {
                PC += offsetLB;
                continue;
            }
            PC += offsetRB;
            if (positionl > foffseth && positionh > foffseth)
            {
                continue;
            }
            {
                const hkReal_X la = positionl - foffseth;
                const hkReal_X ha = positionl - foffsetl;
                const hkReal_X lb = positionh - foffseth;
                const hkReal_X hb = positionh - foffsetl;
                TwoPointVectorBundles leftFloat;
                leftFloat.m_kPointBundles[0] = fQuery->m_kPointBundles[0];
                leftFloat.m_kPointBundles[1] = fQuery->m_kPointBundles[1];
                if (la < lb)
                {
                    if (la * lb < 0.0)
                    {
                        leftFloat.m_kPointBundles[1].setInterpolate4Stored(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], ScalarValue(la / (la - lb)));
                    }
                    FUN_00a2d530(query, PC - offsetRB + offsetLB, &leftFloat, chunkOffset);
                    if (ha * hb < 0.0)
                    {
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], CrossRatio(ha, hb));
                    }
                    if (GetEarlyOut() < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = GetEarlyOut();
                        const hkReal_X fraction = GetEarlyOut();
                        hkVector4_X hitpoint;
                        hitpoint.setHitInterpolate4Left(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, Scalar(fraction));
                        fQuery->m_kPointBundles[1].setSub4(
                            hitpoint, reinterpret_cast<const hkVector4_X&>(m_pMoppCode->m_info.m_offset));
                        fQuery->m_kPointBundles[1].mul4(Scalar(query->m_kVectorAfterIndex));
                         fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] < foffsetl)
                        {
                            goto end_of_function;
                        }
                    }
                    continue;
                }
                else
                {
                    if (ha * hb < 0.0)
                    {
                        leftFloat.m_kPointBundles[1].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], Scalar(ha / (ha - hb)));
                    }
                    FUN_00a2d530(query, PC, &leftFloat, chunkOffset);
                    if (la * lb < 0.0)
                    {
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], ScalarValue(la / (la - lb)));
                    }
                    if (GetEarlyOut() < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = GetEarlyOut();
                        const hkReal_X fraction = GetEarlyOut();
                        hkVector4_X hitpoint;
                        hitpoint.setHitInterpolate4Right(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, fraction);
                        fQuery->m_kPointBundles[1].setSub4(
                            hitpoint, reinterpret_cast<const hkVector4_X&>(m_pMoppCode->m_info.m_offset));
                        fQuery->m_kPointBundles[1].mul4(ScalarValue(query->m_kVectorAfterIndex));
                        fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] > foffseth)
                        {
                            goto end_of_function;
                        }
                    }
                    PC = PC - offsetRB + offsetLB;
                    continue;
                }
            }
        case 0x29:
        case 0x2a:
        case 0x2b:
            tdir = command - 0x29;
            {
                foffsetl = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 1)) * m_vRayDirectionVector;
                foffseth = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 4)) * m_vRayDirectionVector;
                foffsetl *= query->m_kVectorAfterIndex;
                foffseth *= query->m_kVectorAfterIndex;
                foffsetl -= query->m_kVectorBeforeIndex(tdir);
                foffseth -= query->m_kVectorBeforeIndex(tdir);
                foffsetl -= query->SetCenterPosition(tdir);
                foffseth += query->SetCenterPosition(tdir);
                PC += 7;
            }
            goto doCut;
        case 0x26:
        case 0x27:
        case 0x28:
            tdir = command - 0x26;
            foffsetl = hkReal_X(PC[1]);
            foffseth = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            PC += 3;
        doCut:
            positionl = fQuery->m_kPointBundles[0](tdir);
            positionh = fQuery->m_kPointBundles[1](tdir);
            {
                int sign;
                if (positionl < positionh)
                {
                    if (positionh < foffsetl || positionl > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 0;
                }
                else
                {
                    if (positionl < foffsetl || positionh > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 1;
                }
                const hkVector4_X rayStartPoint = fQuery->m_kPointBundles[0];
                const hkVector4_X rayEndPoint = fQuery->m_kPointBundles[1];
                {
                    const hkReal_X R0 = positionl - foffseth;
                    const hkReal_X R1 = positionh - foffseth;
                    if (R0 * R1 < 0.0)
                    {
                        fQuery->m_kPointBundles[1 - sign].setInterpolate4Stored(rayStartPoint, rayEndPoint, Scalar(R0 / (R0 - R1)));
                    }
                }
                {
                    const hkReal_X L0 = positionl - foffsetl;
                    const hkReal_X L1 = positionh - foffsetl;
                    if (L0 * L1 < 0.0)
                    {
                        const hkReal_X ratio = L0 / (L0 - L1);
                        fQuery->m_kPointBundles[sign].setInterpolate4(rayStartPoint, rayEndPoint, Scalar(ratio));
                    }
                }
            }
            continue;
        case 5:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            continue;
        case 6:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            continue;
        case 7: {
            offseth = PC[1];
            const hkUint32_X offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
        }
            continue;
        case 0xc: {
            const int chunkId = (PC[1] << 8) | PC[2];
            chunkOffset = chunkId;
            PC = m_pMoppCode->m_data + (chunkOffset << 9);
            continue;
        }
        case 0xd:
            PC += 5;
            continue;
        case 1:
        case 2:
        case 3:
        case 4: {
            const hkUint32_X shift = command;
            hkVector4_X extraOffset;
            extraOffset.set(hkReal_X(PC[1]), hkReal_X(PC[2]), hkReal_X(PC[3]), 0.0f);
            hkVector4_X f4;
            const hkReal_X f = hkReal_X(1 << shift);
            f4.setAll3(f);
            fQuery->m_kPointBundles[0].sub4(extraOffset);
            fQuery->m_kPointBundles[1].sub4(extraOffset);
            fQuery->m_kPointBundles[0].mul4(f4);
            fQuery->m_kPointBundles[1].mul4(f4);
            scaledQuery.m_kVectorBeforeIndex.setAdd4(query->m_kVectorBeforeIndex, extraOffset);
            scaledQuery.m_kVectorBeforeIndex.mul4(f4);
            scaledQuery.m_iIndex = query->m_iIndex + shift;
            scaledQuery.m_kVectorAfterIndex = query->m_kVectorAfterIndex * f;
            scaledQuery.SetCenterPosition.setMul4(f4, query->SetCenterPosition);
            scaledQuery.m_fValueAtOffset20 = query->m_fValueAtOffset20 * f;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_kProperties[p] = query->m_kProperties[p];
            }
            scaledQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &scaledQuery;
            PC += 4;
        }
            continue;
        case 0:
            goto end_of_function;
        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;
        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;
        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;
        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_uiPropertyCount;
            {
                hkUint32_X chunkId = chunkOffset;
                hkUint32_X keyRemap = ((chunkId << 8) & m_iCurrentChunkId) | offsetl;
                AddHit(keyRemap, query->m_kProperties, 0);
            }
            goto end_of_function;
        case 9: {
            const hkUint32_X offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 2;
        }
            continue;
        case 0xa: {
            const hkUint32_X offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 3;
        }
            continue;
        case 0xb: {
            const hkUint32_X offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount = offset;
            PC += 5;
        }
            continue;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            hkUint32_X property;
            hkUint32_X value;
            property = PC[0] - 0x60;
            value = PC[1];
            PC += 2;
            scaledQuery.m_kProperties[property] = value;
        propertyCopy:
            const hkUint32_X v = scaledQuery.m_kProperties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_kProperties[0] = v;
        }
            continue;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67: {
            const hkUint32_X property = PC[0] - 0x64;
            const hkUint32_X value = (PC[1] << 8) + PC[2];
            scaledQuery.m_kProperties[property] = value;
            PC += 3;
            goto propertyCopy;
        }
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b: {
            const hkUint32_X property = PC[0] - 0x68;
            const hkUint32_X value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_kProperties[property] = value;
            PC += 5;
            goto propertyCopy;
        }
        default:
            {
                unsigned int assertBuf[128];
                StreamRecord ostr;
                ostr.FUN_00923070(assertBuf, 512);
                ostr.FUN_00943710(DAT_00e85ef0);
                DAT_010f3364->message(3, 0x1298fedd, (const char*)assertBuf,
                    DAT_00e85eb0, 506);
                ostr.FUN_00943a60();
            }
            continue;
        }
    } while (1);
end_of_function:;
}

}

extern bool DAT_0116c3ac;
namespace N_A2D530 {
struct MoppLinearCast : MoppCastMachine {
    void FUN_00a2e7f0(const MoppCastQueryData& input, CollectorRecord* collector, CollectorRecord* initialCollector);
};

// pdb: hkpMoppAabbCastVirtualMachine::aabbCast | hkpMoppAabbCastVirtualMachine.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: input, castCollector, startCollector
void MoppLinearCast::FUN_00a2e7f0(const MoppCastQueryData& input, CollectorRecord* collector,
                                  CollectorRecord* initialCollector)
{
    if (!DAT_0116c3ac)
    {
        DAT_0116c3ac = ::f3m_00a284b0::FUN_00a284b0(4);
        if (!DAT_0116c3ac) return;
    }
    m_pRayCastInput = &input;
    m_pMoppCode = reinterpret_cast<const CodeRecord*>(input.m_pSecondCastBody->getShape()->unk10);
    m_pPointCollector = collector;
    m_pClosestPointCollector = initialCollector;
    m_iRayDirectionIndex = input.m_pFirstCastBody->getShape()->getType();
    m_fFirstRayCastValue = 1.0f;
    m_fSecondRayCastValue = m_fFirstRayCastValue;
    const unsigned char* pc = m_pMoppCode->m_data;

    VectorPropertyRecord query;
    query.m_kVectorBeforeIndex(0) = query.m_kVectorBeforeIndex(1) =
        query.m_kVectorBeforeIndex(2) = query.m_kVectorBeforeIndex(3) = 0.0f;
    m_vRayDirectionVector = 1.0f / m_pMoppCode->m_info.m_offset(3);
    query.m_kVectorAfterIndex = float(m_pMoppCode->m_info.m_offset(3) * (1.0 / 65536.0));
    const hkVector4_X& extents = input.SetCenterPosition;
    for (int i = 0; i < 4; ++i)
        query.SetCenterPosition(i) = query.m_kVectorAfterIndex * extents(i);
    float size = extents(0) + extents(1) + extents(2);
    query.m_fValueAtOffset20 = float(size * 3.0);
    TwoPointVectorBundles ray;
    ray.m_kPointBundles[0].setSub4(input.m_vFrom, m_pMoppCode->m_info.m_offset);
    ray.m_kPointBundles[1].setSub4(input.m_vTo, m_pMoppCode->m_info.m_offset);
    ray.m_kPointBundles[0].mul4(query.m_kVectorAfterIndex);
    ray.m_kPointBundles[1].mul4(query.m_kVectorAfterIndex);
    query.m_uiPropertyCount = 0;
    query.m_iIndex = 0;
    query.m_kProperties[0] = 0;
    m_iCurrentChunkId = (*pc != 0x0d) - 1;
    FUN_00a2d530(&query, pc, &ray, 0);
}
}

}   // namespace f3m_00a2e7f0

// @f3 0x00a2e9a0 (community match, verified in this file)
namespace f3m_00a2e9a0 {
// pdb: hkpGsk::print | hkpGsk.obj | tesv_win, objrun_open, low
void __cdecl FUN_00a2e9a0()
{
}
}   // namespace f3m_00a2e9a0

// @f3 0x00a2ea20 (community match, verified in this file)
namespace f3m_00a2ea20 {
// pdb: hkpGsk::codeEnd | hkpGsk.obj | tesv_win, objrun_open, low
void __cdecl FUN_00a2ea20()
{
}
}   // namespace f3m_00a2ea20

// @f3 0x00a25450 (community match, verified in this file)
namespace f3m_00a25450 {
namespace f3m_00a25450 {

typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned int hk_size_t;

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }
    __forceinline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
private:
    char m_bool;
};

template <typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(T v) : m_storage(v) {}
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return m_storage; }
    __forceinline void operator=(T v) { m_storage = v; }
private:
    T m_storage;
};

struct hkpSolverExportNode
{
    int m_numElements;
    hkpSolverExportNode* m_next;
};

struct hkpSolverExportOwner
{
    int unk00, unk04, unk08;
    hkpSolverExportNode* m_exportNode;
};

struct hkpRefCountedCounter
{
    int unk00;
    int m_count;
};

struct hkpTaskNode
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    char unk1c, unk1d;
    hkUint16 m_numJobs;
    hkpTaskNode* m_next;
};

struct hkpBuildJacobianTaskHeader
{
    int m_openJobs;
    int m_numUnfinishedJobsForBroadphase;
    int m_splitCheckState;
    int unk0c, unk10;
    char* m_buffer;
    int m_bufferSize;
    hkBool m_exportFinished;
    hkBool m_solveInSingleThread;
    char unk1e;
    char unk1f;
    hkpSolverExportNode* m_solverExportList;
    int unk24, unk28, unk2c;
    char* m_accumulatorsBase;
    char* m_accumulatorsEnd;
    hkUint16 m_numBuildJacobianJobs;
    hkUint16 m_numIntegrateMotionJobs;
    char* m_schemasBase;
    char* m_solverTempBase;
    int m_numSolverResults;
    int m_numSolverElemTemps;
    int m_numAllEntities;
    int unk50;
    hkUint16 m_numBroadPhaseEntities;
    char unk56;
    char unk57;
    hkBool m_buildAccumulatorsInPlace;
    char unk59;
    char unk5a;
    char unk5b;
    int unk5c, unk60, unk64;
    void* m_allEntities;
    int m_numCreateJacobianTasksJobs;
    int unk70;
    int m_numIslandsAfterSplit;
    void* m_tasks;
    hkUint16 m_numSolveJobs;
    char unk7e;
    char unk7f;
};

struct JobQueueEntry
{
    __declspec(align(16)) unsigned char m_data[128];
};

struct JobQueueEntryInput
{
    hkPadSpu<hkUint32> m_jobThreadType;
    hkPadSpu<hkUint32> m_jobPriority;
    JobQueueEntry m_job;
};

struct hkQueue
{
    JobQueueEntry* m_data;
    int m_capacity;
    int m_head;
    int m_tail;
    int m_elementsInUse;

    void FUN_00a223d0(const JobQueueEntry& element);   // enqueue
};

struct DynamicData
{
    __declspec(align(16)) int m_numActiveJobs;
    int m_numCpuThreadsWaitingForJobs;
    int m_numSpuThreadsWaitingForJobs;
    int m_numMasterThreadsWaitingForJobs;
    hkBool m_dontReleaseSpus;
    hkQueue m_jobQueue[3];
};

struct hkJobQueue;

enum JobCreationStatus
{
    JOB_CREATED,
    NO_JOB_CREATED
};

struct __declspec(align(16)) hkpDynamicsJob
{
    __forceinline void* __cdecl operator new(hk_size_t n, void* p) { return p; }

    __forceinline hkpDynamicsJob(hkUint16 type, const hkpDynamicsJob& src)
    {
        m_jobSubType = type;
        m_islandIndex = src.m_islandIndex;
        m_island = src.m_island;
        m_taskHeader = src.m_taskHeader;
    }

    __forceinline hkpDynamicsJob(hkUint16 type, const hkpDynamicsJob& src, hkpBuildJacobianTaskHeader* taskHeader)
    {
        m_jobSubType = type;
        m_islandIndex = src.m_islandIndex;
        m_island = src.m_island;
        m_taskHeader = taskHeader;
    }

    hkUint16 m_jobSubType;
    hkUint16 m_islandIndex;
    void* m_island;
    hkpBuildJacobianTaskHeader* m_taskHeader;
    int m_unk0c;
};

struct hkpJob3 : public hkpDynamicsJob
{
    __forceinline hkpJob3(const hkpDynamicsJob& src) : hkpDynamicsJob(3, src) {}
};

struct hkpJob4 : public hkpDynamicsJob
{
    __forceinline hkpJob4(const hkpDynamicsJob& src, void* allEntities, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(4, src)
    {
        m_numAllEntities = th.m_numAllEntities;
        m_buildAccumulatorsInPlace = th.m_buildAccumulatorsInPlace;
        m_allEntities = allEntities;
    }
    void* m_allEntities;
    int m_numAllEntities;
    hkBool m_buildAccumulatorsInPlace;
};

struct hkpJob5 : public hkpDynamicsJob
{
    __forceinline hkpJob5(const hkpDynamicsJob& src) : hkpDynamicsJob(5, src) {}
};

struct hkpJob6 : public hkpDynamicsJob
{
    __forceinline hkpJob6(const hkpDynamicsJob& src, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(6, src)
    {
        m_buffer = th.m_buffer;
        m_accumulatorsOffset = int(th.m_accumulatorsBase - m_buffer);
        m_schemasOffset = int(th.m_schemasBase - m_buffer);
        m_solverTempOffset = int(th.m_solverTempBase - m_buffer);
        m_bufferSize = th.m_bufferSize;
        m_numSolverResults = th.m_numSolverResults;
        m_numSolverElemTemps = th.m_numSolverElemTemps;
    }
    char* m_buffer;
    int m_bufferSize;
    int m_accumulatorsOffset;
    int m_schemasOffset;
    int m_solverTempOffset;
    int m_numSolverResults;
    int m_numSolverElemTemps;
};

struct hkpJob7 : public hkpDynamicsJob
{
    __forceinline hkpJob7(const hkpDynamicsJob& src, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(7, src)
    {
        m_accumulators = th.m_accumulatorsBase;
        m_accumulatorsEnd = th.m_accumulatorsEnd;
    }
    char* m_accumulators;
    char* m_accumulatorsEnd;
};

struct hkpJob9;

struct hkpJob8 : public hkpDynamicsJob
{
    __forceinline hkpJob8(const hkpDynamicsJob& src, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(8, src)
    {
        m_task = (hkpTaskNode*)th.m_tasks;
        m_firstTaskIndex = 0;
        m_taskIndex = 0;
    }
    __forceinline hkpJob8(const hkpJob9& src, const hkpBuildJacobianTaskHeader& th);
    __forceinline hkpJob8(const hkpJob8& src) : hkpDynamicsJob(8, src)
    {
        *this = src;
        m_task = src.m_task->m_next;
    }
    int m_firstTaskIndex;
    hkUint32 m_numTasks;
    hkUint32 m_taskIndex;
    hkpTaskNode* m_task;
};

struct hkpJob9 : public hkpDynamicsJob
{
    __forceinline hkpJob9(const hkpJob8& src, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(9, src)
    {
        m_accumulators = th.m_accumulatorsBase;
        m_accumulatorsEnd = th.m_accumulatorsEnd;
        m_taskIndex = src.m_firstTaskIndex;
        m_lastIteration = false;
    }
    char* m_accumulators;
    char* m_accumulatorsEnd;
    int m_taskIndex;
    hkBool m_lastIteration;
};

__forceinline hkpJob8::hkpJob8(const hkpJob9& src, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(8, src)
{
    m_task = (hkpTaskNode*)th.m_tasks;
    m_firstTaskIndex = src.m_taskIndex + 1;
    m_taskIndex = 0;
}

struct hkpJobA : public hkpDynamicsJob
{
    hkpSolverExportOwner* m_owner;
};

struct hkpJobB : public hkpDynamicsJob
{
    __forceinline hkpJobB(const hkpDynamicsJob& src, const hkpBuildJacobianTaskHeader& th) : hkpDynamicsJob(11, src)
    {
        m_tasks = th.m_tasks;
        m_numBroadPhaseEntitiesHigh = 0;
        m_numBroadPhaseEntities = th.m_numBroadPhaseEntities;
        m_buffer = th.m_buffer;
    }
    void* m_tasks;
    int unk14, unk18, unk1c;
    char* m_buffer;
    hkUint16 m_numBroadPhaseEntities;
    hkUint16 m_numBroadPhaseEntitiesHigh;
    int m_numIterations;
};

struct hkpJobC : public hkpDynamicsJob
{
    __forceinline hkpJobC(const hkpDynamicsJob& src, hkpBuildJacobianTaskHeader* taskHeader) : hkpDynamicsJob(12, src, taskHeader)
    {
        m_numJobs = 1;
    }
    hkUint16 m_numJobs;
};

struct hkpJobD : public hkpDynamicsJob
{
    hkpRefCountedCounter* m_counter;
};

struct hkpJobE : public hkpDynamicsJob
{
    __forceinline hkpJobE(const hkpJobD& src) : hkpDynamicsJob(14, src)
    {
        m_islandIndex = src.m_islandIndex;
        m_counter = src.m_counter;
    }
    hkpRefCountedCounter* m_counter;
};

// pdb: spawnBuildJacobiansJobs | hkpDynamicsJobQueueUtils.obj | fnv360_0822_retail, objopen_prop, low
static __declspec(noinline) void FUN_00a25450(hkpBuildJacobianTaskHeader* taskHeader, const hkpDynamicsJob& job, JobQueueEntryInput& newJobCreated)
{
    new (&newJobCreated.m_job) hkpJob4(job, taskHeader->m_allEntities, *taskHeader);
    taskHeader->m_openJobs = taskHeader->m_numCreateJacobianTasksJobs;
    newJobCreated.m_jobPriority = 0;
    newJobCreated.m_jobThreadType = 0;
}

// the helper is file-local; its one caller in this file, so the compiler keeps the private convention
void caller_of_FUN_00a25450(hkpBuildJacobianTaskHeader* taskHeader, const JobQueueEntry& jobIn, JobQueueEntryInput& newJobCreated)
{
    FUN_00a25450(taskHeader, reinterpret_cast<const hkpDynamicsJob&>(jobIn), newJobCreated);
}

}
}   // namespace f3m_00a25450

// @f3 0x00a30440 (community match, verified in this file)
namespace f3m_00a30440 {
// FUN_00a30440 = Havok 5.5.0 hkpGsk::processEdgeTriangle (hkpInternal.lib, hkpGsk.obj; hkpGsk.cpp lines 361-501).
// Written from the SDK headers and the library objects' debug records (hkpGsk.cpp and hkpGsk.h are not shipped);
// reduced from sdk_final.cpp with hktrim.py. checkTriangleBoundaries (game 0x00a2ee70, record lines 143-185)
// precedes the target as in the .cpp: its body is what lets the compiler keep `this` in ecx across the calls.
// See note.txt.
namespace f3m_00a30440 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef unsigned int	hkUint32;

class hkBool
{
	public:
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};

namespace hkMath
{
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline int __cdecl isNegative(hkReal r0)
	{
		return (r0<0)? hkVector4Comparison::MASK_X : 0;
	}
}

class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}

inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

class hkpConvexShape;

class hkpCollideTriangleUtil
{
	public:
		enum
		{
			CLSLS_POINTA_START = 1,
			CLSLS_POINTA_END   = 2,
			CLSLS_POINTB_START = 4,
			CLSLS_POINTB_END   = 8
		};
		struct ClosestLineSegLineSegResult
		{
			                class MustEndWithSemiColon;
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal>  m_distanceSquared;
		};
		static int __cdecl closestLineSegLineSeg( hkVector4Parameter A, hkVector4Parameter dA, hkVector4Parameter B, hkVector4Parameter dB, ClosestLineSegLineSegResult& result );
		struct ClosestPointLineSegResult
		{
			                class MustEndWithSemiColon;
			hkVector4 m_pointOnEdge;
		};
		struct ClosestPointTriangleCache
		{
			                class MustEndWithSemiColon;
			hkReal m_QQ;
			hkReal m_RR;
			hkReal m_QR;
			hkReal m_invTriNormal;
		};
		struct ClosestPointTriangleResult
		{
			                class MustEndWithSemiColon;
			hkVector4			hitDirection;
			hkPadSpu<hkReal>	distance;
		};
		enum ClosestPointTriangleStatus
		{
			HIT_TRIANGLE_FACE = 0,
			HIT_TRIANGLE_EDGE
		};
		struct PointTriangleDistanceCache
		{
			                class MustEndWithSemiColon;
			hkReal m_invEdgeLen[3];
			hkReal m_invNormalLen;
			hkReal m_normalLen;
		};
		static const hkInt8 maskToIndex[];
		static const hkInt8 vertexToEdgeLut[];
};

class hkpGsk
{
	public:
		                class MustEndWithSemiColon;
		enum
		{
			GSK_NONE_NONE = 0,
			GSK_POINT_POINT = 9,
			GSK_POINT_EDGE = 10,
			GSK_EDGE_POINT = 17,
			GSK_POINT_TRIANGLE = 11,
			GSK_TRIANGLE_POINT = 25,
			GSK_EDGE_TRIANGLE = 19,
			GSK_TRIANGLE_EDGE = 26,
			GSK_POINT_TETRA = 12,
			GSK_TETRA_POINT = 33,
			GSK_EDGE_EDGE = 18
		};
		enum NextCase
		{
			NEXT_IS_BREAK = 0,
			NEXT_IS_PENETRATION = 1,
			NEXT_IS_EDGE_EDGE = 2
		};
		enum SupportTypes
		{
			BUILD_NEG_SUPPORT = -8,
			BUILD_NO_SUPPORT = 0,
			BUILD_POS_SUPPORT = 8
		};
		enum SupportState
		{
			SUPPORT_CHANGED = 0,
			DONT_CALL_GET_SUPPORTING_VERTEX_A = 8,
			DONT_CALL_GET_SUPPORTING_VERTEX_B = -8
		};
		enum ReduceDimensionResult
		{
			REDUCE_DIMENSION_OK = 0,
			REDUCE_DIMENSION_PENETRATION = 1
		};
		struct GetClosesetPointInput
		{
			                class MustEndWithSemiColon;
			hkPadSpu<const hkTransform*> m_aTb;
			hkPadSpu<const hkTransform*> m_transformA;
			hkPadSpu<const hkpConvexShape*> m_shapeA;
			hkPadSpu<const hkpConvexShape*> m_shapeB;
			hkPadSpu<hkReal> m_collisionTolerance;
		};
	protected:
		int checkTriangleBoundaries( const hkVector4& point, hkVector4* triangle, SupportTypes stype );
		NextCase FUN_00a30440( hkVector4* vertexA, hkVector4* vertexB, hkPadSpu<int>& dimA, hkPadSpu<int>& dimB, hkBool comingFromEdgeEdge, SupportTypes supportType );
	public:
		hkPadSpu<int> m_dimA;
		hkPadSpu<int> m_dimB;
		hkPadSpu<int> m_maxDimA;
		hkPadSpu<int> m_maxDimB;
		hkPadSpu<hkUint32> m_doNotHandlePenetration;
		hkPadSpu<int> m_featureChange;
		hkpCdVertex m_verticesA[4];
		hkVector4   m_dummy[4];
		hkVector4   m_verticesBinA[4];
		hkpCdVertex m_verticesBinB[4];
		hkVector4 m_support;
		hkpCollideTriangleUtil::ClosestLineSegLineSegResult m_closestLineLineResult;
		hkVector4 m_checkTriangleDots;
		hkPadSpu<int> m_lastDimB;
		SupportState m_supportState;
};

namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
}

namespace hkVector4Util
{
	__forceinline void __cdecl dot3_3vs3( const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut);
}

inline void __cdecl hkVector4Util::dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( b0 );
	dotsOut(1) = a1.dot3( b1 );
	dotsOut(2) = a2.dot3( b2 );
	dotsOut(3) = 0;
}

int hkpGsk::checkTriangleBoundaries( const hkVector4& a, hkVector4* b, SupportTypes checkSupport )
{
	hkVector4 edge0; edge0.setSub4( b[2], b[1] );
	hkVector4 edge1; edge1.setSub4( b[0], b[2] );
	hkVector4 edge2; edge2.setSub4( b[1], b[0] );
	hkVector4 support; support.setCross( edge0, edge1 );
	hkVector4 dots;
	{
		hkVector4 pt0; pt0.setSub4( a, b[1] );
		hkVector4 pt1; pt1.setSub4( a, b[2] );
		hkVector4 pt2; pt2.setSub4( a, b[0] );
		hkVector4 a0; a0.setCross( pt0, edge0 );
		hkVector4 a1; a1.setCross( pt1, edge1 );
		hkVector4 a2; a2.setCross( pt2, edge2 );
		hkVector4Util::dot3_3vs3( a0, support, a1, support, a2, support, dots );
	}
	m_checkTriangleDots = dots;
	int mask = dots.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ );
	if ( checkSupport != BUILD_NO_SUPPORT )
	{
		m_support = support;
		if ( mask == hkVector4Comparison::MASK_XYZ )
		{
			hkVector4 pt0; pt0.setSub4( m_verticesA[0], m_verticesBinA[0] );
			if ( hkMath::isNegative( support.dot3( pt0 ) ) )
			{
				m_support.setNeg4( support );
				hkAlgorithm::swap( b[0], b[1] );
				hkAlgorithm::swap( b[4], b[5] );
				hkAlgorithm::swap( m_checkTriangleDots( 0 ), m_checkTriangleDots( 1 ) );
				m_featureChange = 1;
			}
		}
	}
	return mask;
}

// pdb: hkpGsk::processEdgeTriangle | hkpGsk.obj | tesv_win, call_gap, low
hkpGsk::NextCase hkpGsk::FUN_00a30440( hkVector4* __restrict vertexA, hkVector4* __restrict vertexB, hkPadSpu<int>& dimA, hkPadSpu<int>& dimB, hkBool comingFromEdgeEdge, SupportTypes supportType )
{
	if ( comingFromEdgeEdge )
	{
		hkVector4 edge0; edge0.setSub4( vertexB[1], vertexB[2] );
		hkVector4 edge1; edge1.setSub4( vertexB[0], vertexB[2] );
		hkVector4 normal; normal.setCross( edge0, edge1 );
		hkVector4 diff0; diff0.setSub4( vertexA[0], vertexB[0] );
		hkVector4 diff1; diff1.setSub4( vertexA[1], vertexB[0] );
		hkReal dot0 = normal.dot3( diff0 );
		hkReal dot1 = normal.dot3( diff1 );
		int neg0 = hkMath::isNegative( dot0 );
		int neg1 = hkMath::isNegative( dot1 );
		if ( neg0 != neg1 )
		{
			{
				hkReal a = dot0 / ( dot0 - dot1 );
				hkVector4 pointOnSurface; pointOnSurface.setInterpolate4( vertexA[0], vertexA[1], a );
				int maskT = checkTriangleBoundaries( pointOnSurface, vertexB, BUILD_NO_SUPPORT );
				if ( maskT == 0xe )
				{
					return NEXT_IS_PENETRATION;
				}
			}
checkEdges:
			{
				hkVector4 edgeA; edgeA.setSub4( vertexA[1], vertexA[0] );
				hkpCollideTriangleUtil::ClosestLineSegLineSegResult result0;
				hkpCollideTriangleUtil::ClosestLineSegLineSegResult result1;
				hkpCollideTriangleUtil::closestLineSegLineSeg( vertexA[0], edgeA, vertexB[2], edge0, result0 );
				hkpCollideTriangleUtil::closestLineSegLineSeg( vertexA[0], edgeA, vertexB[2], edge1, result1 );
				int index = ( result0.m_distanceSquared > result1.m_distanceSquared ) ? 1 : 0;
				vertexB[index] = vertexB[2];
				vertexB[index + 4] = vertexB[6];
				dimB = dimB - 1;
				return NEXT_IS_EDGE_EDGE;
			}
		}
		if ( hkMath::fabs( dot0 ) > hkMath::fabs( dot1 ) )
		{
			hkAlgorithm::swap( vertexA[0], vertexA[1] );
			hkAlgorithm::swap( vertexA[4], vertexA[5] );
		}
		int maskT = checkTriangleBoundaries( vertexA[0], vertexB, BUILD_POS_SUPPORT );
		if ( maskT == 0xe )
		{
			dimA = dimA - 1;
			return NEXT_IS_BREAK;
		}
		goto checkEdges;
	}
	{
		hkVector4 oldDots = m_checkTriangleDots;
		{
			hkVector4 va1; va1.setSub4( vertexA[1], vertexB[0] );
			hkReal dot1 = m_support.dot3( va1 );
			hkVector4 va0; va0.setSub4( vertexA[0], vertexB[0] );
			hkReal dot0 = m_support.dot3( va0 );
			if ( hkMath::isNegative( dot0 * dot1 ) )
			{
				hkReal a = dot0 / ( dot0 - dot1 );
				hkVector4 pointOnSurface; pointOnSurface.setInterpolate4( vertexA[0], vertexA[1], a );
				int maskT = checkTriangleBoundaries( pointOnSurface, vertexB, BUILD_NO_SUPPORT );
				if ( maskT == 0xe )
				{
					return NEXT_IS_PENETRATION;
				}
			}
		}
		int maskT = checkTriangleBoundaries( vertexA[1], vertexB, BUILD_NO_SUPPORT );
		if ( maskT == 0xe )
		{
			dimA = dimA - 1;
			vertexA[0] = vertexA[1];
			vertexA[4] = vertexA[5];
			m_supportState = SupportState( supportType );
			return NEXT_IS_BREAK;
		}
		if ( maskT == 6 ) { goto remove_b0; }
		if ( maskT == 0xa ) { goto remove_b1; }
		if ( maskT == 0xc ) { goto remove_b2; }
		if ( maskT == 8 )
		{
			hkReal d0 = m_checkTriangleDots( 1 ) - oldDots( 1 );
			hkReal d1 = m_checkTriangleDots( 2 ) - oldDots( 2 );
			if ( oldDots( 2 ) * d0 > oldDots( 1 ) * d1 )
			{
				goto remove_b2;
			}
			else
			{
				goto remove_b1;
			}
		}
		if ( maskT == 4 )
		{
			hkReal d0 = m_checkTriangleDots( 2 ) - oldDots( 2 );
			hkReal d1 = m_checkTriangleDots( 0 ) - oldDots( 0 );
			if ( oldDots( 0 ) * d0 > oldDots( 2 ) * d1 )
			{
				goto remove_b0;
			}
			else
			{
				goto remove_b2;
			}
		}
		if ( maskT == 2 )
		{
			hkReal d0 = m_checkTriangleDots( 0 ) - oldDots( 0 );
			hkReal d1 = m_checkTriangleDots( 1 ) - oldDots( 1 );
			if ( oldDots( 1 ) * d0 > oldDots( 0 ) * d1 )
			{
				goto remove_b1;
			}
			else
			{
				goto remove_b0;
			}
		}
remove_b0:
		dimB = dimB - 1;
		vertexB[0] = vertexB[2];
		vertexB[4] = vertexB[6];
		return NEXT_IS_EDGE_EDGE;
remove_b1:
		dimB = dimB - 1;
		vertexB[1] = vertexB[2];
		vertexB[5] = vertexB[6];
		return NEXT_IS_EDGE_EDGE;
remove_b2:
		dimB = dimB - 1;
		return NEXT_IS_EDGE_EDGE;
	}
}

}
}   // namespace f3m_00a30440

// @f3 0x00a23aa0 (community match, verified in this file)
#include <float.h>
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d35c[], DAT_00e855fc[], DAT_00e0811c[];
namespace f3m_00a23aa0 {
// Havok 5.5.0, hkpDynamics.lib / hkpCpuBuildJacobiansJob.obj.
// Win32 release subset of the SDK interfaces used by hkCpuBuildJacobiansJob.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace f3m_00a23aa0
{
typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long hkUlong;
typedef hkUint16 hkObjectIndex;

class hkBool
{
public:
    hkBool() {}
    hkBool(bool b) { m_bool = static_cast<char>(b); }
    operator bool() const { return m_bool != 0; }
    hkBool& operator=(bool b)
    {
        m_bool = static_cast<char>(b);
        return *this;
    }
private:
    char m_bool;
};

template<typename E, typename S>
class hkEnum
{
public:
    hkEnum() {}
    hkEnum(E value) { m_storage = static_cast<S>(value); }
    hkBool operator==(E value) const { return m_storage == static_cast<S>(value); }
private:
    S m_storage;
};

template<typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline void operator=(T value) { m_storage = value; }
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return val(); }
private:
    T m_storage;
};

__forceinline hkUlong hkGetByteOffset(const void* base, const void* ptr)
{
    return hkUlong(ptr) - hkUlong(base);
}

__forceinline int hkGetByteOffsetInt(const void* base, const void* ptr)
{
    return static_cast<int>(hkGetByteOffset(base, ptr));
}

template<typename T>
__forceinline T* hkAddByteOffset(T* base, hkUlong offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

class hkMonitorStream
{
public:
    static hkMonitorStream& getInstance()
    {
        return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c));
    }
    __forceinline char* __cdecl getEnd() { return m_end.val(); }
    __forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool __cdecl memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void __cdecl setEnd(char* end) { m_end = end; }

    hkPadSpu<char*> m_start, m_end, m_capacity, m_capacityMinus16;
    hkBool m_isBufferAllocatedOnTheHeap;

    struct Command { const char* m_commandAndMonitor; };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0, m_time1;
        __forceinline void setTime()
        {
            // hkMonitorStream.inl, IA32/MSVC timer.
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
    struct TimerBeginListCommand : public TimerCommand { const char* m_nameOfFirstSplit; };
};

class hkJobQueue
{
public:
    struct JobQueueEntry { __declspec(align(16)) unsigned char m_data[128]; };
    enum ThreadType { THREAD_TYPE_CPU, THREAD_TYPE_CPU_BROADPHASE, THREAD_TYPE_CPU_MASTER, THREAD_TYPE_MAX, THREAD_TYPE_INVALID = -1 };
    enum WaitStatus { WAIT_FOR_NEXT_JOB, DO_NOT_WAIT_FOR_NEXT_JOB };
    enum JobStatus { GOT_NEXT_JOB, NO_JOBS_AVAILABLE, JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF, ALL_JOBS_FINISHED };
    JobStatus FUN_00a21830(ThreadType threadType, const JobQueueEntry* oldJob, JobQueueEntry& jobOut,
                          void* params = 0, WaitStatus waitStatus = WAIT_FOR_NEXT_JOB);
};

class hkTransform;
class hkpWorld;
class hkpSimulationIsland;
class hkpConstraintInstance;
class hkpJacobianSchema;
struct __declspec(align(16)) hkVector4 { hkReal x, y, z, w; };

class hkpVelocityAccumulator
{
public:
    enum hkpAccumulatorType { HK_RIGID_BODY, HK_KEYFRAMED_RIGID_BODY, HK_NO_GRAVITY_RIGID_BODY, HK_END };
    hkEnum<hkpAccumulatorType, unsigned char> m_type;
    hkBool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel, m_angularVel, m_invMasses;
    hkVector4 m_scratch0, m_scratch1, m_scratch2, m_scratch3;
};

struct hkpCollisionInput
{
    struct Aabb32Info { hkVector4 m_bitOffsetLow, m_bitOffsetHigh, m_bitScale; };
    hkPadSpu<class hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
    hkPadSpu<const class hkpShapeCollectionFilter*> m_filter;
    hkPadSpu<const class hkpConvexListFilter*> m_convexListFilter;
    hkPadSpu<int> m_createPredictiveAgents;
    Aabb32Info m_aabb32Info;
};

struct hkStepInfo
{
    hkPadSpu<hkReal> m_startTime, m_endTime, m_deltaTime, m_invDeltaTime;
};

struct hkpProcessCollisionInput : public hkpCollisionInput
{
    hkStepInfo m_stepInfo;
    mutable hkPadSpu<struct hkpCollisionQualityInfo*> m_collisionQualityInfo;
    void* m_dynamicsInfo;
    bool m_enableDeprecatedWelding;
    class hkpCollisionAgentConfig* m_config;
};

class hkpConstraintQueryStepInfo
{
public:
    __declspec(align(16)) hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime, m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime, m_frameInvDeltaTime, m_invNumSteps, m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor, m_virtMassFactor, m_frictionRhsFactor;
};

class hkpConstraintQueryIn : public hkpConstraintQueryStepInfo
{
public:
    __declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
    hkPadSpu<const hkTransform*> m_transformA, m_transformB;
    hkPadSpu<hkReal> m_tau, m_damping;
    hkPadSpu<hkpConstraintInstance*> m_constraintInstance;
    hkPadSpu<void*> m_constraintRuntime;
    hkPadSpu<hkUint32> m_accumulatorAIndex, m_accumulatorBIndex;
    hkPadSpu<void*> m_constraintRuntimeInMainMemory;
};

class hkpConstraintQueryOut
{
public:
    hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};

struct hkpConstraintAtom
{
    enum AtomType { TYPE_CONTACT = 22 };
    hkEnum<AtomType, hkUint16> m_type;
};
struct hkpSimpleContactConstraintAtom;

struct hkpBuildJacobianTaskHeader;
struct hkpBuildJacobianTask
{
    struct AtomInfo
    {
        hkpConstraintAtom* m_atoms;
        hkpConstraintInstance* m_instance;
        void* m_runtime;
        const hkTransform* m_transformA;
        const hkTransform* m_transformB;
        hkUint16 m_atomsSize, m_runtimeSize;
        hkUint16 m_accumulatorIndexA, m_accumulatorIndexB;
    };
    hkpBuildJacobianTask* m_next;
    hkpBuildJacobianTaskHeader* m_taskHeader;
    const hkpVelocityAccumulator* m_accumulators;
    hkpJacobianSchema* m_schemas;
    hkpJacobianSchema* m_schemasOfNextTask;
    int m_numAtomInfos;
    AtomInfo m_atomInfos[144];
};

class hkpDynamicsJob
{
public:
    enum JobType { DYNAMICS_JOB_BUILD_JACOBIANS = 4 };
    typedef hkEnum<JobType, hkObjectIndex> hkpDynamicsJobType;
    __declspec(align(16)) hkpDynamicsJobType m_jobType;
    hkObjectIndex m_islandIndex;
    hkpSimulationIsland* m_island;
    hkpBuildJacobianTaskHeader* m_taskHeader;
};

class hkpBuildJacobiansJob : public hkpDynamicsJob
{
public:
    union
    {
        hkpBuildJacobianTask* m_buildJacobianTask;
        hkpBuildJacobianTask* m_buildJacobianTaskInMainMemory;
    };
    const hkpConstraintQueryIn* m_constraintQueryIn;
    hkBool m_finishSchemasWithGoto;
};

struct hkpMtThreadStructure
{
    hkpWorld* m_world;
    class hkpMultiThreadedSimulation* m_simulation;
    hkJobQueue::ThreadType m_threadType;
    hkpProcessCollisionInput m_collisionInput;
    hkpConstraintQueryIn m_constraintQueryIn;
};

class hkpJacobianSchema
{
public:
    enum SchemaType { SCHEMA_TYPE_END, SCHEMA_TYPE_HEADER, SCHEMA_TYPE_GOTO };
    typedef hkEnum<SchemaType, hkInt8> JointSchemaType;
    static __forceinline void setType(hkpJacobianSchema* schema, JointSchemaType type)
    {
        *reinterpret_cast<hkReal*>(schema) += FLT_EPSILON;
        *reinterpret_cast<JointSchemaType*>(schema) = type;
    }
};

class hkpJacobianGotoSchema
{
public:
    hkUint32 m_padding0;
    hkUint32 m_offset;
    hkUint32 m_padding1[2];
    __forceinline void initOffset(int offset)
    {
        m_offset = offset;
        hkpJacobianSchema::setType(reinterpret_cast<hkpJacobianSchema*>(this), hkpJacobianSchema::SCHEMA_TYPE_GOTO);
    }
};

void __cdecl FUN_00a00ec0(hkpSimpleContactConstraintAtom* atom, const hkpConstraintQueryIn& in, hkBool writeHeaderSchema, hkpConstraintQueryOut& out);
void __cdecl FUN_009fccc0(const hkpConstraintAtom* atoms, int sizeOfAllAtoms, const hkpConstraintQueryIn& in, hkpConstraintQueryOut& out);

__forceinline void __cdecl hkSolverBuildJacobianFromAtoms(const hkpConstraintAtom* atoms, int sizeOfAllAtoms, const hkpConstraintQueryIn& in, hkpConstraintQueryOut& out)
{
    if (atoms->m_type == hkpConstraintAtom::TYPE_CONTACT)
    {
        hkpSimpleContactConstraintAtom* contactAtom = (hkpSimpleContactConstraintAtom*)atoms;
        hkBool writeHeaderSchema = true;
        FUN_00a00ec0(contactAtom, in, writeHeaderSchema, out);
    }
    else
    {
        FUN_009fccc0(atoms, sizeOfAllAtoms, in, out);
    }
}

namespace anon_00a23aa0 {} using namespace anon_00a23aa0; namespace anon_00a23aa0 {
    struct hkBuildJacobiansFromTaskInput
    {
        hkpBuildJacobianTask::AtomInfo* m_atomInfos;
        int m_numAtomInfos;
        const hkpVelocityAccumulator* m_accumulators;
        hkpJacobianSchema* m_schemas;
        hkpJacobianSchema* m_schemasOfNextTask;
        void* m_nextTask;
        hkBool m_finishSchemasWithGoto;
    };
}

static __forceinline void hkCpuBuildJacobiansFromTask(const hkBuildJacobiansFromTaskInput& input, hkpConstraintQueryIn& queryIn)
{
    hkpConstraintQueryOut queryOut;
    queryOut.m_jacobianSchemas = input.m_schemas;
    const hkpBuildJacobianTask::AtomInfo* atomInfos = input.m_atomInfos;
    int numAtomInfos = input.m_numAtomInfos;
    for (int i = 0; i < numAtomInfos;)
    {
        const hkpBuildJacobianTask::AtomInfo& info = atomInfos[i++];
        queryIn.m_transformA = info.m_transformA;
        queryIn.m_transformB = info.m_transformB;
        queryIn.m_bodyA = &input.m_accumulators[info.m_accumulatorIndexA];
        queryIn.m_bodyB = &input.m_accumulators[info.m_accumulatorIndexB];
        queryIn.m_accumulatorAIndex = info.m_accumulatorIndexA;
        queryIn.m_accumulatorBIndex = info.m_accumulatorIndexB;
        queryIn.m_constraintInstance = info.m_instance;
        queryIn.m_constraintRuntime = info.m_runtime;
        queryIn.m_constraintRuntimeInMainMemory = info.m_runtime;
        hkSolverBuildJacobianFromAtoms(info.m_atoms, info.m_atomsSize, queryIn, queryOut);
    }
    if (!input.m_finishSchemasWithGoto)
    {
        hkpJacobianSchema* end = queryOut.m_jacobianSchemas;
        *reinterpret_cast<hkUint32*>(end) = hkpJacobianSchema::SCHEMA_TYPE_END;
        queryOut.m_jacobianSchemas = hkAddByteOffset(end, 16);
    }
    else
    {
        int offset = hkGetByteOffsetInt(queryOut.m_jacobianSchemas.val(), input.m_schemasOfNextTask);
        if (offset > 0)
        {
            hkpJacobianGotoSchema* jump = reinterpret_cast<hkpJacobianGotoSchema*>(queryOut.m_jacobianSchemas.val());
            jump->initOffset(offset);
            queryOut.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>(jump + 1);
        }
    }
}

// pdb: hkCpuBuildJacobiansJob | hkpCpuBuildJacobiansJob.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
hkJobQueue::JobStatus __cdecl hkCpuBuildJacobiansJob(hkpMtThreadStructure& tl, hkJobQueue& jobQueue, hkJobQueue::JobQueueEntry& jobInOut)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = DAT_00e7d35c; // LtIntegrate
            h->m_nameOfFirstSplit = DAT_00e855fc;  // StBuildJacobians
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }
    const hkpBuildJacobiansJob& job = reinterpret_cast<const hkpBuildJacobiansJob&>(jobInOut);
    hkpConstraintQueryIn& queryIn = tl.m_constraintQueryIn;
    hkBuildJacobiansFromTaskInput input;
    {
        hkpBuildJacobianTask* task = job.m_buildJacobianTask;
        input.m_atomInfos = task->m_atomInfos;
        input.m_numAtomInfos = task->m_numAtomInfos;
        input.m_accumulators = task->m_accumulators;
        input.m_schemas = task->m_schemas;
        input.m_schemasOfNextTask = task->m_schemasOfNextTask;
        input.m_nextTask = task->m_next;
        input.m_finishSchemasWithGoto = job.m_finishSchemasWithGoto && task->m_next;
    }
    hkCpuBuildJacobiansFromTask(input, queryIn);
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = DAT_00e0811c; // lt
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }
    return jobQueue.FUN_00a21830(tl.m_threadType, &jobInOut, jobInOut);
}

} // namespace f3m_00a23aa0
}   // namespace f3m_00a23aa0
