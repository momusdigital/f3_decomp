#include <windows.h>
// src/f3staging/f3blk_00b80000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b9d300 (community match, verified in this file)
#include <string.h>
struct DeflateState;
struct DeflateStream {
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned int total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned int total_out;
    const char* msg;
    DeflateState* state;
    void* allocator;
    void* deallocator;
    void* opaque;
    int data_type;
    unsigned int adler;
    unsigned int reserved;
};
struct DeflateState {
    DeflateStream* strm;
    int status;
    unsigned char* pending_buf;
    unsigned int pending_buf_size;
    unsigned char* pending_out;
    unsigned int pending;
    int wrap;
    void* gzhead;
    int last_flush;
    unsigned int w_size;
    unsigned int w_bits;
    unsigned int w_mask;
    unsigned char* window;
    unsigned int window_size;
    unsigned short* prev;
    unsigned short* head;
    unsigned int ins_h;
    unsigned int hash_size;
    unsigned int hash_bits;
    unsigned int hash_mask;
    unsigned int hash_shift;
    int block_start;
    unsigned int match_length;
    unsigned int prev_match;
    int match_available;
    unsigned int strstart;
    unsigned int match_start;
    unsigned int lookahead;
    unsigned int prev_length;
    unsigned int max_chain_length;
    unsigned int max_lazy_match;
    int level;
    int strategy;
};
typedef int (__cdecl *CompressFunction)(DeflateState*,int);
struct DeflateConfig {
    unsigned short good_length,max_lazy,nice_length,max_chain;
    CompressFunction function;
};
extern DeflateConfig DAT_00ea43e0[];
extern const char* DAT_00ea44f0;
extern const char* DAT_00ea44fc;
unsigned int __cdecl FUN_00b9f270(unsigned int,const unsigned char*,unsigned int);
unsigned int __cdecl FUN_00b9f650(unsigned int,const unsigned char*,unsigned int);
void __cdecl _tr_align(DeflateState*);
void __cdecl _tr_stored_block(DeflateState*,const char*,unsigned int,int);
// pdb: putShortMSB | deflate.obj | tesv_win, hash, low
static __declspec(noinline) void FUN_00b9d280(DeflateState* state,unsigned int value)
{
    state->pending_buf[state->pending]=(unsigned char)(value>>8);
    ++state->pending;
    state->pending_buf[state->pending]=(unsigned char)value;
    ++state->pending;
}
// pdb: flush_pending | deflate.obj | fnv360_0822_retail, call_gap, low
static __declspec(noinline) void FUN_00b9d2b0(DeflateStream* strm)
{
    unsigned int len=strm->state->pending;
    if(len>strm->avail_out) len=strm->avail_out;
    if(len==0) return;
    memcpy(strm->next_out,strm->state->pending_out,len);
    strm->next_out+=len;
    strm->state->pending_out+=len;
    strm->total_out+=len;
    strm->avail_out-=len;
    strm->state->pending-=len;
    if(strm->state->pending==0) strm->state->pending_out=strm->state->pending_buf;
}
// pdb: deflate | deflate.obj | fnv360_0822_retail, call_gap_sim + skyrim(objrun), high
int __cdecl deflate(DeflateStream* strm,int flush)
{
    DeflateState* s;
    int old_flush;
    if(strm==0 || strm->state==0 || (unsigned int)flush>4) return -2;
    s=strm->state;
    if(strm->next_out==0 || (strm->next_in==0 && strm->avail_in!=0) || (s->status==666 && flush!=4)) {
        strm->msg=DAT_00ea44f0;
        return -2;
    }
    if(strm->avail_out==0) {strm->msg=DAT_00ea44fc;return -5;}
    s->strm=strm;
    old_flush=s->last_flush;
    s->last_flush=flush;
    if(s->status==42) {
        if(s->wrap==2) {
            s->pending_buf[s->pending++]=0x1f;
            s->pending_buf[s->pending++]=0x8b;
            s->pending_buf[s->pending++]=8;
            s->pending_buf[s->pending++]=0;
            s->pending_buf[s->pending++]=0;
            s->pending_buf[s->pending++]=0;
            s->pending_buf[s->pending++]=0;
            s->pending_buf[s->pending++]=0;
            s->pending_buf[s->pending++]=(unsigned char)(s->level==9?2:(s->strategy>=2 || s->level<2?4:0));
            s->pending_buf[s->pending++]=0xff;
            s->status=113;
            strm->adler=FUN_00b9f650(0,0,0);
        } else {
            unsigned int header=(8+((s->w_bits-8)<<4))<<8;
            unsigned int level_flags;
            if(s->strategy>=2 || s->level<2) level_flags=0;
            else if(s->level<6) level_flags=1;
            else if(s->level==6) level_flags=2;
            else level_flags=3;
            header|=level_flags<<6;
            if(s->strstart!=0) header|=0x20;
            header+=31-header%31;
            s->status=113;
            FUN_00b9d280(s,header);
            if(s->strstart!=0) {
                FUN_00b9d280(s,strm->adler>>16);
                FUN_00b9d280(s,strm->adler&0xffff);
            }
            strm->adler=FUN_00b9f270(0,0,0);
        }
    }
    if(s->pending!=0) {
        FUN_00b9d2b0(strm);
        if(strm->avail_out==0) {s->last_flush=-1;return 0;}
    } else if(strm->avail_in==0 && flush<=old_flush && flush!=4) {
        strm->msg=DAT_00ea44fc;
        return -5;
    }
    if(s->status==666 && strm->avail_in!=0) {strm->msg=DAT_00ea44fc;return -5;}
    if(strm->avail_in!=0 || s->lookahead!=0 || (flush!=0 && s->status!=666)) {
        int bstate=DAT_00ea43e0[s->level].function(s,flush);
        if(bstate==2 || bstate==3) s->status=666;
        if(bstate==0 || bstate==2) {
            if(strm->avail_out==0) s->last_flush=-1;
            return 0;
        }
        if(bstate==1) {
            if(flush==1) _tr_align(s);
            else {
                _tr_stored_block(s,0,0,0);
                if(flush==3) {
                    s->head[s->hash_size-1]=0;
                    memset(s->head,0,(s->hash_size-1)*sizeof(*s->head));
                }
            }
            FUN_00b9d2b0(strm);
            if(strm->avail_out==0) {s->last_flush=-1;return 0;}
        }
    }
    if(flush!=4) return 0;
    if(s->wrap<=0) return 1;
    if(s->wrap==2) {
        s->pending_buf[s->pending++]=((unsigned char*)&strm->adler)[0];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->adler)[1];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->adler)[2];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->adler)[3];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->total_in)[0];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->total_in)[1];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->total_in)[2];
        s->pending_buf[s->pending++]=((unsigned char*)&strm->total_in)[3];
    } else {
        FUN_00b9d280(s,strm->adler>>16);
        FUN_00b9d280(s,strm->adler&0xffff);
    }
    FUN_00b9d2b0(strm);
    if(s->wrap>0) s->wrap=-s->wrap;
    return s->pending!=0?0:1;
}

// @f3 0x00b9d230 (community match, verified in this file)
struct Resource412 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28;
    void* child;
};
typedef void (__cdecl* Release412)(void* context, void* resource);
struct Owner412 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    Resource412* resource;
    unsigned int unk20;
    Release412 release;
    void* context;
    unsigned int unk2C, unk30;
    unsigned int ownsResource;
};
// pdb: inflateEnd | inflate.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: strm
int __cdecl FUN_00b9d230(Owner412* owner) {
    if (!owner || !owner->resource || !owner->release)
        return -2;
    Resource412* resource = owner->resource;
    if (resource->child)
        owner->release(owner->context, resource->child);
    if (owner->ownsResource)
        owner->release(owner->context, owner->resource);
    owner->resource = 0;
    return 0;
}

// @f3 0x00b9e650 (community match, verified in this file)
extern int FUN_00ea44f8;
namespace f3m_00b9e650 {

struct F650Blk;

struct F650Obj {
    unsigned char unk00[0x18];
    int f18;
    F650Blk* f1c;
    void* (__cdecl* f20)(void*, unsigned int, unsigned int);
    void (__cdecl* f24)();
    void* f28;
};

struct F650Blk {
    F650Obj* f00;
    int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned char unk10[8];
    int f18;
    unsigned char unk1c[1];
    unsigned char b1d;
    unsigned char unk1e[2];
    unsigned char unk20[4];
    unsigned int f24;
    int f28;
    unsigned int f2c;
    void* f30;
    unsigned char unk34[4];
    void* f38;
    void* f3c;
    unsigned char unk40[4];
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned char unk54[0x28];
    unsigned int f7c;
    unsigned int f80;
    unsigned char unk84[0x160c];
    unsigned int f1690;
    unsigned int f1694;
    unsigned char unk1698[4];
    unsigned int f169c;
};

void* __cdecl FUN_00b9e8a0(void* ctx, unsigned int count, unsigned int size);
void __cdecl FUN_00b9e8c0();
int __cdecl deflateReset(F650Obj* obj);
void __cdecl deflateEnd(F650Obj* obj);

// pdb: deflateInit2_ | deflate.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
int deflateInit2_(F650Obj* obj, int a2, int a3, int a4, int a5, int a6, char* a7, int a8)
{
    int sign = 1;
    unsigned int b;
    if (a7 == 0 || *a7 != '1' || a8 != 0x38) return -6;
    if (obj == 0) return sign - 3;
    obj->f18 = 0;
    if (obj->f20 == 0) {
        obj->f20 = FUN_00b9e8a0;
        obj->f28 = 0;
    }
    if (obj->f24 == 0) obj->f24 = FUN_00b9e8c0;
    if (a2 == -1) a2 = 6;
    if (a4 < 0) {
        sign = 0;
        a4 = -a4;
    } else if (a4 > 15) {
        sign = 2;
        a4 -= 16;
    }
    b = a4;
    if ((unsigned int)(a5 - 1) > 8 || a3 != 8 || (unsigned int)(b - 8) > 7 || (unsigned int)a2 > 9 || (unsigned int)a6 > 3) return -2;
    if (b == 8) b = 9;

    F650Blk* p = (F650Blk*)obj->f20(obj->f28, 1, 0x16b8);
    if (p == 0) return -4;
    obj->f1c = p;
    p->f18 = sign;
    p->f28 = b;
    unsigned int s1 = 1u << b;
    p->f2c = s1 - 1;
    int t = a5 + 7;
    unsigned int s2 = 1u << t;
    p->f48 = t;
    p->f00 = obj;
    p->f44 = s2;
    p->f4c = s2 - 1;
    p->f24 = s1;
    p->f50 = (unsigned int)(t + 2) / 3u;
    p->f30 = obj->f20(obj->f28, s1, 2);
    p->f38 = obj->f20(obj->f28, p->f24, 2);
    p->f3c = obj->f20(obj->f28, p->f44, 2);
    unsigned int s3 = 1u << (a5 + 6);
    p->f1694 = s3;
    unsigned int d = (unsigned int)obj->f20(obj->f28, s3, 4);
    p->f08 = d;
    p->f0c = p->f1694 * 4;
    if (p->f30 != 0 && p->f38 != 0 && p->f3c != 0 && d != 0) {
        unsigned int n = p->f1694;
        p->f169c = d + (n >> 1) * 2;
        p->f1690 = d + n * 2 + n;
        p->f7c = a2;
        p->f80 = a6;
        p->b1d = 8;
        return deflateReset(obj);
    }
    p->f04 = 0x29a;
    obj->f18 = FUN_00ea44f8;
    deflateEnd(obj);
    return -4;
}
}   // namespace f3m_00b9e650

// @f3 0x00b9f7b0 (community match, verified in this file)
namespace f3m_00b9f7b0 {

struct F7CtData {
    unsigned short fc;
    unsigned short dl;
};

struct F7StaticDesc {
    const F7CtData* static_tree;
    const int* extra_bits;
    int extra_base;
    int elems;
    int max_length;
};

struct F7TreeDesc {
    F7CtData* dyn_tree;
    int max_code;
    const F7StaticDesc* stat_desc;
};

struct F7State {
    unsigned char unk00[0xb34];
    unsigned short bl_count[16];
    int heap[573];
    int heap_len;
    int heap_max;
    unsigned char unk1450[0x250];
    unsigned long opt_len;
    unsigned long static_len;
};

// pdb: gen_bitlen | trees.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00b9f7b0(F7State* s, F7TreeDesc* desc)
{
    F7CtData* tree = desc->dyn_tree;
    int max_code = desc->max_code;
    const F7CtData* stree = desc->stat_desc->static_tree;
    const int* extra = desc->stat_desc->extra_bits;
    int base = desc->stat_desc->extra_base;
    int max_length = desc->stat_desc->max_length;
    int h;
    int n, m;
    int bits;
    int xbits;
    unsigned short f;
    int overflow = 0;

    for (bits = 0; bits <= 15; bits++) s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].dl = 0;

    for (h = s->heap_max + 1; h < 573; h++) {
        n = s->heap[h];
        bits = tree[tree[n].dl].dl + 1;
        if (bits > max_length) bits = max_length, overflow++;
        tree[n].dl = (unsigned short)bits;
        if (n > max_code) continue;

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base) xbits = extra[n - base];
        f = tree[n].fc;
        s->opt_len += (unsigned long)f * (unsigned long)(bits + xbits);
        if (stree) s->static_len += (unsigned long)f * (unsigned long)(stree[n].dl + xbits);
    }
    if (overflow == 0) return;

    do {
        bits = max_length - 1;
        while (s->bl_count[bits] == 0) bits--;
        s->bl_count[bits]--;
        s->bl_count[bits + 1] += 2;
        s->bl_count[max_length]--;
        overflow -= 2;
    } while (overflow > 0);

    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code) continue;
            if ((unsigned)tree[m].dl != (unsigned)bits) {
                s->opt_len += (unsigned long)(((long)bits - (long)tree[m].dl) * (long)tree[m].fc);
                tree[m].dl = (unsigned short)bits;
            }
            n--;
        }
    }
}

volatile int g_in_00b9f7b0;
volatile int g_out_00b9f7b0;
void caller_of_FUN_00b9f7b0() {
    F7State* s = (F7State*)g_in_00b9f7b0;
    F7TreeDesc* d = (F7TreeDesc*)g_out_00b9f7b0;
    FUN_00b9f7b0(s, d);
}
}   // namespace f3m_00b9f7b0

// @f3 0x00b9ed90 (community match, verified in this file)
extern unsigned short DAT_00ea4538[];
extern unsigned short DAT_00ea4578[];
extern unsigned short DAT_00ea45b8[];
extern unsigned short DAT_00ea45f8[];
namespace f3m_00b9ed90 {
struct DecodeEntry { unsigned char op, bits; unsigned short val; };
// pdb: inflate_table | inftrees.obj | fnv360_0822_debug, call_seq, medium
// pdb params: type, lens, codes, table, bits, work
int __cdecl FUN_00b9ed90(int type, unsigned short *lens, unsigned codes,
                       DecodeEntry **table, unsigned *bits, unsigned short *work)
{
    unsigned len, sym, min, max, root, curr, drop, left, used, huff, incr, fill, low, mask;
    DecodeEntry here;
    DecodeEntry *next;
    const unsigned short *base, *extra;
    int end;
    unsigned short count[16];
    unsigned short offs[16];
    for (len=0;len<=15;len++) count[len]=0;
    for(sym=0;sym<codes;sym++) count[lens[sym]]++;
    root=*bits;
    for(max=15;max>=1;max--) if(count[max]) break;
    if(root>max) root=max;
    if(max==0) return -1;
    for(min=1;min<=15;min++) if(count[min]) break;
    if(root<min) root=min;
    left=1;
    for(len=1;len<=15;len++) {
        left<<=1;
        left-=count[len];
        if((int)left<0) return -1;
    }
    if((int)left>0 && (type==0 || codes-count[0]!=1)) return -1;
    offs[1]=0;
    for(len=1;len<15;len++) offs[len+1]=offs[len]+count[len];
    for(sym=0;sym<codes;sym++) if(lens[sym]!=0) work[offs[lens[sym]]++]=(unsigned short)sym;
    switch(type) {
    case 0: base=extra=work; end=19; break;
    case 1: base=DAT_00ea4538-257; extra=DAT_00ea4578-257; end=256; break;
    default: base=DAT_00ea45b8; extra=DAT_00ea45f8; end=-1;
    }
    huff=0; sym=0; len=min; next=*table; curr=root; drop=0;
    low=(unsigned)-1; used=1U<<root; mask=used-1;
    if(type==1 && used>=1286) return 1;
    for(;;) {
        here.bits=(unsigned char)(len-drop);
        if((int)work[sym]<end) { here.op=0; here.val=work[sym]; }
        else if((int)work[sym]>end) { here.op=(unsigned char)extra[work[sym]]; here.val=base[work[sym]]; }
        else {here.op=96; here.val=0;}
        incr=1U<<(len-drop);
        fill=1U<<curr;
        do {fill-=incr; next[(huff>>drop)+fill]=here;} while(fill!=0);
        incr=1U<<(len-1);
        while(huff&incr) incr>>=1;
        if(incr!=0) huff=(huff&(incr-1))+incr;
        else huff=0;
        sym++;
        if(--count[len]==0) {if(len==max) break; len=lens[work[sym]];}
        if(len>root && (huff&mask)!=low) {
            if(drop==0) drop=root;
            next+=1U<<curr;
            curr=len-drop;
            left=1U<<curr;
            while(curr+drop<max) {
                left-=count[curr+drop];
                if((int)left<=0) break;
                curr++; left<<=1;
            }
            used+=1U<<curr;
            if(type==1 && used>=1286) return 1;
            low=huff&mask;
            (*table)[low].op=(unsigned char)curr;
            (*table)[low].bits=(unsigned char)root;
            (*table)[low].val=(unsigned short)(next-*table);
        }
    }
    here.op=64; here.bits=(unsigned char)(len-drop); here.val=0;
    while(huff!=0) {
        if(drop!=0 && (huff&mask)!=low) {drop=0;len=root;next=*table;here.bits=(unsigned char)root;}
        next[huff>>drop]=here;
        incr=1U<<(len-1);
        while(huff&incr) incr>>=1;
        if(incr!=0) huff=(huff&(incr-1))+incr;
        else break;
    }
    *table+=used; *bits=root; return 0;
}
}   // namespace f3m_00b9ed90

// @f3 0x00b86a90 (community match, verified in this file)
struct StageReturn {
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
    int m_uiRefCount;
    void FUN_0088fe30();
    void Release() {
        if (--m_uiRefCount == 0)
            FUN_0088fe30();
    }
};

struct StageReturnPtr {
    StageReturn* m_pStage;
    StageReturnPtr() : m_pStage(0) {}
    ~StageReturnPtr() {
        if (m_pStage)
            m_pStage->Release();
    }
    StageReturnPtr& operator=(StageReturn* p) {
        if (m_pStage != p) {
            if (m_pStage)
                m_pStage->Release();
            m_pStage = p;
            if (p)
                ++p->m_uiRefCount;
        }
        return *this;
    }
    StageReturn* operator->() const {
        return m_pStage;
    }
};

class StageDevice {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void SetStageState(unsigned int index, int value);
};

struct StageManager {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    StageReturn** m_pStages;
    StageDevice* FUN_008882e0();
};
extern StageManager* DAT_01091980;

struct StandIn_00b86a90 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    short unk9c;
    unsigned short m_usItemCount;
    void FUN_00b86a90(int a1);
};

void StandIn_00b86a90::FUN_00b86a90(int)
{
    StageReturnPtr current;
    for (unsigned int i = 1; i < m_usItemCount; ++i)
    {
        current = DAT_01091980->m_pStages[i - 1];
        current->unk08 = 0;
        DAT_01091980->FUN_008882e0()->SetStageState(i - 1, 0);
    }
}

// @f3 0x00b9fac0 (community match, verified in this file)
#include <stddef.h>
namespace f3m_00b9fac0 {
// Adapted from zlib 1.2.1 trees.c and deflate.h (Jean-loup Gailly and Mark Adler).
// Macro operations expanded to ordinary C++ blocks; reference source remains unchanged.
typedef unsigned char uch;
typedef unsigned char Byte;
typedef unsigned char Bytef;
typedef unsigned char uchf;
typedef unsigned short ush;
typedef unsigned short ushf;
typedef unsigned long ulg;
typedef unsigned int uInt;
struct z_stream_s;
typedef z_stream_s* z_streamp;
enum { L_CODES=286, D_CODES=30, BL_CODES=19, HEAP_SIZE=573, MAX_BITS=15,
       REP_3_6=16, REPZ_3_10=17, REPZ_11_138=18, Buf_size=16 };
typedef struct ct_data_s {
    union {
        ush  freq;       
        ush  code;       
    } fc;
    union {
        ush  dad;        
        ush  len;        
    } dl;
} ct_data;
typedef struct static_tree_desc_s  static_tree_desc;
typedef struct tree_desc_s {
    ct_data *dyn_tree;           
    int     max_code;            
    static_tree_desc *stat_desc; 
} tree_desc;
typedef ush Pos;
typedef Pos Posf;
typedef unsigned IPos;
typedef struct internal_state {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    
    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        
    Bytef *window;
    ulg window_size;
    Posf *prev;
    Posf *head; 
    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      
    uInt  hash_shift;
    long block_start;
    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              
    uInt prev_length;
    uInt max_chain_length;
    uInt max_lazy_match;
    int level;    
    int strategy; 
    uInt good_match;
    int nice_match; 
    struct ct_data_s dyn_ltree[HEAP_SIZE];   
    struct ct_data_s dyn_dtree[2*D_CODES+1]; 
    struct ct_data_s bl_tree[2*BL_CODES+1];  
    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              
    ush bl_count[MAX_BITS+1];
    int heap[2*L_CODES+1];      
    int heap_len;               
    int heap_max;               
    uch depth[2*L_CODES+1];
    uchf *l_buf;          
    uInt  lit_bufsize;
    uInt last_lit;      
    ushf *d_buf;
    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   
    ush bi_buf;
    int bi_valid;
} deflate_state;
typedef char CheckBitTreeOffset[offsetof(deflate_state,bl_tree)==0xa74?1:-1];
typedef char CheckBitBufferOffset[offsetof(deflate_state,bi_buf)==0x16b0?1:-1];

// pdb: send_tree | trees.obj | fnv360_0721_beta, call_seq, medium
static void FUN_00b9fac0(deflate_state* s, ct_data* tree, int max_code)
{
    int n;                     
    int prevlen = -1;          
    int curlen;                
    int nextlen = tree[0].dl.len; 
    int count = 0;             
    int max_count = 7;         
    int min_count = 4;         

      
    if (nextlen == 0) max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].dl.len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do { { int len = s->bl_tree[curlen].dl.len;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[curlen].fc.code;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[curlen].fc.code) << s->bi_valid;
    s->bi_valid += len;
  }
}; } while (--count != 0);

        } else if (curlen != 0) {
            if (curlen != prevlen) {
                { int len = s->bl_tree[curlen].dl.len;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[curlen].fc.code;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[curlen].fc.code) << s->bi_valid;
    s->bi_valid += len;
  }
}; count--;
            }
            { int len = s->bl_tree[REP_3_6].dl.len;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[REP_3_6].fc.code;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[REP_3_6].fc.code) << s->bi_valid;
    s->bi_valid += len;
  }
}; { int len = 2;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = count-3;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (count-3) << s->bi_valid;
    s->bi_valid += len;
  }
};

        } else if (count <= 10) {
            { int len = s->bl_tree[REPZ_3_10].dl.len;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[REPZ_3_10].fc.code;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[REPZ_3_10].fc.code) << s->bi_valid;
    s->bi_valid += len;
  }
}; { int len = 3;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = count-3;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (count-3) << s->bi_valid;
    s->bi_valid += len;
  }
};

        } else {
            { int len = s->bl_tree[REPZ_11_138].dl.len;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[REPZ_11_138].fc.code;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[REPZ_11_138].fc.code) << s->bi_valid;
    s->bi_valid += len;
  }
}; { int len = 7;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = count-11;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (count-11) << s->bi_valid;
    s->bi_valid += len;
  }
};
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}
static const unsigned char bl_order[19] = {16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15};

void SendAllTrees(deflate_state* s, int lcodes, int dcodes, int blcodes)
{
    int rank;                    

    ;
    ;
    ;
    { int len = 5;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = lcodes-257;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (lcodes-257) << s->bi_valid;
    s->bi_valid += len;
  }
}; 
    { int len = 5;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = dcodes-1;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (dcodes-1) << s->bi_valid;
    s->bi_valid += len;
  }
};
    { int len = 4;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = blcodes-4;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (blcodes-4) << s->bi_valid;
    s->bi_valid += len;
  }
}; 
    for (rank = 0; rank < blcodes; rank++) {
        ;
        { int len = 3;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[bl_order[rank]].dl.len;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[bl_order[rank]].dl.len) << s->bi_valid;
    s->bi_valid += len;
  }
};
    }
    ;

    FUN_00b9fac0(s, (ct_data *)s->dyn_ltree, lcodes-1); 
    ;

    FUN_00b9fac0(s, (ct_data *)s->dyn_dtree, dcodes-1); 
    ;
}
}   // namespace f3m_00b9fac0

// @f3 0x00b9e8d0 (community match, verified in this file)
namespace f3m_00b9e8d0 {
/* zlib inflate_fast: decode literals/lengths/distances from a bit buffer. */

typedef struct {
    unsigned char op;           /* operation, extra bits, table bits */
    unsigned char bits;         /* bits in this part of the code */
    unsigned short val;         /* offset in table or code value */
} code;

enum inflate_mode {
    HEAD, FLAGS, TIME, OS, EXLEN, EXTRA, NAME, COMMENT, HCRC, DICTID, DICT,
        TYPE, STORED, COPY_, COPY, TABLE, LENLENS, CODELENS,
            LEN, LENEXT, DIST, DISTEXT, MATCH, LIT,
    CHECK, LENGTH, DONE, BAD, MEM, SYNC
};

struct inflate_state {
    int mode;                   /* 0x00 current inflate mode */
    int last;                   /* 0x04 */
    int wrap;                   /* 0x08 */
    int havedict;               /* 0x0c */
    int flags;                  /* 0x10 */
    unsigned long check;        /* 0x14 */
    unsigned long total;        /* 0x18 */
    unsigned wbits;             /* 0x1c */
    unsigned wsize;             /* 0x20 */
    unsigned whave;             /* 0x24 */
    unsigned wnext;             /* 0x28 */
    unsigned char *window;      /* 0x2c */
    unsigned long hold;         /* 0x30 */
    unsigned bits;              /* 0x34 */
    unsigned length;            /* 0x38 */
    unsigned offset;            /* 0x3c */
    unsigned extra;             /* 0x40 */
    code *lencode;              /* 0x44 */
    code *distcode;             /* 0x48 */
    unsigned lenbits;           /* 0x4c */
    unsigned distbits;          /* 0x50 */
};

typedef struct z_stream_s {
    unsigned char *next_in;     /* 0x00 next input byte */
    unsigned avail_in;          /* 0x04 number of bytes available at next_in */
    unsigned long total_in;     /* 0x08 total nb of input bytes read so far */
    unsigned char *next_out;    /* 0x0c next output byte should be put there */
    unsigned avail_out;         /* 0x10 remaining free space at next_out */
    unsigned long total_out;    /* 0x14 total nb of bytes output so far */
    char *msg;                  /* 0x18 last error message */
    inflate_state *state;       /* 0x1c not visible by applications */
} z_stream;

// pdb: inflate_fast | inffast.obj | fnv360_0822_retail, strset, low
// pdb params: strm, start
void __cdecl FUN_00b9e8d0(z_stream *strm, unsigned start)
{
    inflate_state *state;
    unsigned char *in;          /* local strm->next_in */
    unsigned char *last;        /* while in < last, enough input available */
    unsigned char *out;         /* local strm->next_out */
    unsigned char *beg;         /* inflate()'s initial strm->next_out */
    unsigned char *end;         /* while out < end, enough space available */
    unsigned wsize;             /* window size or zero if not using window */
    unsigned whave;             /* valid bytes in the window */
    unsigned wnext;             /* window write index */
    unsigned char *window;      /* allocated sliding window, if wsize != 0 */
    unsigned long hold;         /* local strm->hold */
    unsigned bits;              /* local strm->bits */
    code *lcode;                /* local strm->lencode */
    code *dcode;                /* local strm->distcode */
    unsigned lmask;             /* mask for first level of length codes */
    unsigned dmask;             /* mask for first level of distance codes */
    code here;                  /* retrieved table entry */
    unsigned op;                /* code bits, operation, extra bits, or */
                                /*  window position, window bytes to copy */
    unsigned len;               /* match length, unused bytes */
    unsigned dist;              /* match distance */
    unsigned char *from;        /* where to copy match from */

    /* copy state to local variables */
    state = strm->state;
    in = strm->next_in - 1;
    last = in + (strm->avail_in - 5);
    out = strm->next_out - 1;
    beg = out - (start - strm->avail_out);
    end = out + (strm->avail_out - 257);
    wsize = state->wsize;
    whave = state->whave;
    wnext = state->wnext;
    window = state->window;
    hold = state->hold;
    bits = state->bits;
    lcode = state->lencode;
    dcode = state->distcode;
    lmask = (1U << state->lenbits) - 1;
    dmask = (1U << state->distbits) - 1;

    /* decode literals and length/distances until end-of-block or not enough
       input data or output space */
    do {
        if (bits < 15) {
            hold += (unsigned long)(*++in) << bits;
            bits += 8;
            hold += (unsigned long)(*++in) << bits;
            bits += 8;
        }
        here = lcode[hold & lmask];
      dolen:
        op = (unsigned)(here.bits);
        hold >>= op;
        bits -= op;
        op = (unsigned)(here.op);
        if (op == 0) {                          /* literal */
            *++out = (unsigned char)(here.val);
        }
        else if (op & 16) {                     /* length base */
            len = (unsigned)(here.val);
            op &= 15;                           /* number of extra bits */
            if (op) {
                if (bits < op) {
                    hold += (unsigned long)(*++in) << bits;
                    bits += 8;
                }
                len += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
            }
            if (bits < 15) {
                hold += (unsigned long)(*++in) << bits;
                bits += 8;
                hold += (unsigned long)(*++in) << bits;
                bits += 8;
            }
            here = dcode[hold & dmask];
          dodist:
            op = (unsigned)(here.bits);
            hold >>= op;
            bits -= op;
            op = (unsigned)(here.op);
            if (op & 16) {                      /* distance base */
                dist = (unsigned)(here.val);
                op &= 15;                       /* number of extra bits */
                if (bits < op) {
                    hold += (unsigned long)(*++in) << bits;
                    bits += 8;
                    if (bits < op) {
                        hold += (unsigned long)(*++in) << bits;
                        bits += 8;
                    }
                }
                dist += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
                op = (unsigned)(out - beg);     /* max distance in output */
                if (dist > op) {                /* see if copy from window */
                    op = dist - op;             /* distance back in window */
                    if (op > whave) {
                        strm->msg = (char *)"invalid distance too far back";
                        state->mode = BAD;
                        break;
                    }
                    from = window - 1;
                    if (wnext == 0) {           /* very common case */
                        from += wsize - op;
                        if (op < len) {         /* some from window */
                            len -= op;
                            do {
                                *++out = *++from;
                            } while (--op);
                            from = out - dist;  /* rest from output */
                        }
                    }
                    else if (wnext < op) {      /* wrap around window */
                        from += wsize + wnext - op;
                        op -= wnext;
                        if (op < len) {         /* some from end of window */
                            len -= op;
                            do {
                                *++out = *++from;
                            } while (--op);
                            from = window - 1;
                            if (wnext < len) {  /* some from start of window */
                                op = wnext;
                                len -= op;
                                do {
                                    *++out = *++from;
                                } while (--op);
                                from = out - dist;      /* rest from output */
                            }
                        }
                    }
                    else {                      /* contiguous in window */
                        from += wnext - op;
                        if (op < len) {         /* some from window */
                            len -= op;
                            do {
                                *++out = *++from;
                            } while (--op);
                            from = out - dist;  /* rest from output */
                        }
                    }
                    while (len > 2) {
                        *++out = *++from;
                        *++out = *++from;
                        *++out = *++from;
                        len -= 3;
                    }
                    if (len) {
                        *++out = *++from;
                        if (len > 1)
                            *++out = *++from;
                    }
                }
                else {
                    from = out - dist;          /* copy direct from output */
                    do {                        /* minimum length is three */
                        *++out = *++from;
                        *++out = *++from;
                        *++out = *++from;
                        len -= 3;
                    } while (len > 2);
                    if (len) {
                        *++out = *++from;
                        if (len > 1)
                            *++out = *++from;
                    }
                }
            }
            else if ((op & 64) == 0) {          /* second level distance */
                here = dcode[here.val + (hold & ((1U << op) - 1))];
                goto dodist;
            }
            else {
                strm->msg = (char *)"invalid distance code";
                state->mode = BAD;
                break;
            }
        }
        else if ((op & 64) == 0) {              /* second level length */
            here = lcode[here.val + (hold & ((1U << op) - 1))];
            goto dolen;
        }
        else if (op & 32) {                     /* end-of-block */
            state->mode = TYPE;
            break;
        }
        else {
            strm->msg = (char *)"invalid literal/length code";
            state->mode = BAD;
            break;
        }
    } while (in < last && out < end);

    /* return unused bytes (on entry, bits < 8, so in won't go too far back) */
    len = bits >> 3;
    in -= len;
    bits -= len << 3;
    hold &= (1U << bits) - 1;

    /* update state and return */
    strm->next_in = in + 1;
    strm->next_out = out + 1;
    strm->avail_in = (unsigned)(in < last ? 5 + (last - in) : 5 - (in - last));
    strm->avail_out = (unsigned)(out < end ?
                                 257 + (end - out) : 257 - (out - end));
    state->hold = hold;
    state->bits = bits;
}
}   // namespace f3m_00b9e8d0

// @f3 0x00b8d170 (community match, verified in this file)
struct PassStage_b8d170 {
    unsigned int unk00;
    unsigned int unk04;
    void* texture;
};
struct PassEntry_b8d170 {
    unsigned char unk00[0x24];
    PassStage_b8d170** stages;
};
struct PassSource_b8d170 {
    void* first;
    void* data;
};
class PassContext_b8d170 {
public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3c();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void vfunc4c();
    virtual void vfunc50();
    virtual void vfunc54();
    virtual void vfunc58();
    virtual void vfunc5c();
    virtual void vfunc60();
    virtual void vfunc64();
    virtual void vfunc68();
    virtual void vfunc6c();
    virtual void vfunc70();
    virtual void vfunc74();
    virtual void vfunc78();
    virtual void vfunc7c();
    virtual void vfunc80();
    virtual void vfunc84();
    virtual void vfunc88();
    virtual void vfunc8c();
    virtual void vfunc90();
    virtual void vfunc94();
    virtual void vfunc98();
    virtual void vfunc9c();
    virtual void vfunca0();
    virtual void vfunca4();
    virtual void vfunca8();
    virtual void vfuncac();
    virtual void vfuncb0();
    virtual void vfuncb4();
    virtual void vfuncb8();
    virtual void vfuncbc();
    virtual void vfuncc0();
    virtual void vfuncc4();
    virtual void vfuncc8();
    virtual void vfunccc();
    virtual void vfuncd0();
    virtual void vfuncd4();
    virtual void vfuncd8();
    virtual void vfuncdc();
    virtual void vfunce0();
    virtual void vfunce4();
    virtual void vfunce8();
    virtual void vfuncec();
    virtual void vfuncf0();
    virtual void* GetTexture(int index, int flags);
    unsigned char unk04[0x80];
    unsigned int color84;
    unsigned int color88;
    unsigned int color8c;
    unsigned int color90;
    unsigned char unk94[0x18];
    PassSource_b8d170* sourceAC;
    PassSource_b8d170* sourceB0;
    void** sourceB4;
    unsigned char unkB8[0x30];
    float scaleE8;
    float scaleEC;
};
struct Point3_b8d170 {
    float x, y, z;
    Point3_b8d170 operator-(const Point3_b8d170& other) const
    {
        Point3_b8d170 result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }
};
struct PassGeom_b8d170 {
    unsigned char unk00[0x20];
    Point3_b8d170* position;
};
struct PassEffect_b8d170 {
    unsigned char unk00[0x58];
    float parameter58;
    float FUN_00b857e0();
    float GetParameter() { return FUN_00b857e0(); }
};
struct PassRootNode_b8d170 {
    unsigned char unk00[0x30];
    PassEffect_b8d170* effect;
};
struct PassRoot_b8d170 {
    unsigned char unk00[0x08];
    PassRootNode_b8d170* root;
};
class PassShader_b8d170 {
public:
    PassEntry_b8d170* FUN_00b8d170(int kind, PassContext_b8d170* context);
    void FUN_00b40410(PassContext_b8d170* context, PassEntry_b8d170* pass);
    void FUN_00b40340(PassContext_b8d170* context, PassEntry_b8d170* pass);
    void FUN_00b8cf10(PassEntry_b8d170* pass, PassContext_b8d170* context, int count);
    void FUN_00b8d000(PassEntry_b8d170* pass);
    void FUN_00b8d030(PassEntry_b8d170* pass, PassContext_b8d170* context, int kind);
    void FUN_00b8d0c0(PassEntry_b8d170* pass, PassContext_b8d170* context);
    void FUN_00b8d120(PassEntry_b8d170* pass, PassContext_b8d170* context, int extra);
    void FUN_00b3ec50(PassEntry_b8d170* pass, int first);
};
void __cdecl FUN_00afb5f0();
extern PassEntry_b8d170* DAT_01176c60;
extern PassEntry_b8d170* DAT_01176c64;
extern PassEntry_b8d170* DAT_01176c68;
extern PassEntry_b8d170* DAT_01176c6c;
extern PassEntry_b8d170* DAT_01176c70;
extern PassEntry_b8d170* DAT_01176c74;
extern PassEntry_b8d170* DAT_01176c78;
extern PassEntry_b8d170* DAT_01176c7c;
extern PassEntry_b8d170* DAT_01176c80;
extern PassEntry_b8d170* DAT_01176c84;
extern PassEntry_b8d170* DAT_01176c88;
extern PassEntry_b8d170* DAT_01176c8c;
extern PassEntry_b8d170* DAT_01176c90;
extern PassEntry_b8d170* DAT_01176c94;
extern PassEntry_b8d170* DAT_01176c98;
extern PassEntry_b8d170* DAT_01176c9c;
extern PassEntry_b8d170* DAT_01176ca0;
extern PassEntry_b8d170* DAT_01176ca4;
extern PassEntry_b8d170* DAT_01176ca8;
extern PassEntry_b8d170* DAT_01176cac;
extern PassEntry_b8d170* DAT_01176cb0;
extern PassEntry_b8d170* DAT_01176cb4;
extern PassEntry_b8d170* DAT_01176cb8;
extern PassEntry_b8d170* DAT_01176cbc;
extern PassEntry_b8d170* DAT_01176cc0;
extern PassEntry_b8d170* DAT_01176cc4;
extern PassEntry_b8d170* DAT_01176cc8;
extern PassEntry_b8d170* DAT_01176ccc;
extern PassEntry_b8d170* DAT_01176cd0;
extern PassEntry_b8d170* DAT_01176cd4;
extern PassEntry_b8d170* DAT_01176cd8;
extern PassEntry_b8d170* DAT_01176cdc;
extern PassEntry_b8d170* DAT_01176ce0;
extern PassEntry_b8d170* DAT_01176ce4;
extern PassEntry_b8d170* DAT_01176ce8;
extern PassEntry_b8d170* DAT_01176cec;
extern PassEntry_b8d170* DAT_01176cf4;
extern PassEntry_b8d170* DAT_01176cf8;
extern PassEntry_b8d170* DAT_01176cfc;
extern PassEntry_b8d170* DAT_01176d00;
extern PassEntry_b8d170* DAT_01176d04;
extern PassEntry_b8d170* DAT_01176d08;
extern PassEntry_b8d170* DAT_01176d0c;
extern PassEntry_b8d170* DAT_01176d10;
extern PassEntry_b8d170* DAT_01176d14;
extern PassEntry_b8d170* DAT_01176d18;
extern PassEntry_b8d170* DAT_01176d1c;
extern PassEntry_b8d170* DAT_01176d20;
extern PassEntry_b8d170* DAT_01176d24;
extern PassEntry_b8d170* DAT_01176d28;
extern PassEntry_b8d170* DAT_01176d2c;
extern PassEntry_b8d170* DAT_01176d30;
extern PassEntry_b8d170* DAT_01176d34;
extern PassEntry_b8d170* DAT_01176d38;
extern PassEntry_b8d170* DAT_01176d3c;
extern PassEntry_b8d170* DAT_01176d40;
extern PassEntry_b8d170* DAT_01176d44;
extern PassEntry_b8d170* DAT_01176d48;
extern PassEntry_b8d170* DAT_01176d4c;
extern PassEntry_b8d170* DAT_01176d50;
extern PassEntry_b8d170* DAT_01176d54;
extern PassEntry_b8d170* DAT_01176d58;
extern PassEntry_b8d170* DAT_01176d5c;
extern PassEntry_b8d170* DAT_01176d60;
extern PassEntry_b8d170* DAT_01176d64;
extern PassEntry_b8d170* DAT_01176d68;
extern PassEntry_b8d170* DAT_01176d6c;
extern PassEntry_b8d170* DAT_01176d70;
extern PassEntry_b8d170* DAT_01176d74;
extern PassEntry_b8d170* DAT_01176d78;
extern PassEntry_b8d170* DAT_01176d7c;
extern PassEntry_b8d170* DAT_01176d80;
extern PassEntry_b8d170* DAT_01176d84;
extern PassEntry_b8d170* DAT_01176d88;
extern PassEntry_b8d170* DAT_01176d8c;
extern PassEntry_b8d170* DAT_01176d90;
extern PassEntry_b8d170* DAT_01176d94;
extern PassEntry_b8d170* DAT_01176d98;
extern PassEntry_b8d170* DAT_01176d9c;
extern PassEntry_b8d170* DAT_01176da0;
extern PassEntry_b8d170* DAT_01176da8;
extern PassEntry_b8d170* DAT_01176db0;
extern PassEntry_b8d170* DAT_01176db4;
extern PassEntry_b8d170* DAT_01176db8;
extern PassEntry_b8d170* DAT_01176dbc;
extern PassEntry_b8d170* DAT_01176dc0;
extern PassEntry_b8d170* DAT_01176dc4;
extern PassEntry_b8d170* DAT_01176dc8;
extern PassEntry_b8d170* DAT_01176dcc;
extern PassEntry_b8d170* DAT_01176dd0;
extern PassEntry_b8d170* DAT_01176dd4;
extern PassEntry_b8d170* DAT_01176dd8;
extern PassEntry_b8d170* DAT_01176ddc;
extern PassEntry_b8d170* DAT_01176de0;
extern PassEntry_b8d170* DAT_01176de4;
extern PassEntry_b8d170* DAT_01176de8;
extern PassEntry_b8d170* DAT_01176dec;
extern PassEntry_b8d170* DAT_01176df0;
extern PassEntry_b8d170* DAT_01176df4;
extern PassEntry_b8d170* DAT_01176df8;
extern PassEntry_b8d170* DAT_01176dfc;
extern PassEntry_b8d170* DAT_01176e00;
extern PassEntry_b8d170* DAT_01176e04;
extern PassEntry_b8d170* DAT_01176e08;
extern PassEntry_b8d170* DAT_01176e0c;
extern PassEntry_b8d170* DAT_01176e10;
extern PassEntry_b8d170* DAT_01176e14;
extern PassEntry_b8d170* DAT_01176e18;
extern PassEntry_b8d170* DAT_01176e1c;
extern unsigned int DAT_011778f0;
extern unsigned int DAT_011778f4;
extern unsigned int DAT_011778f8;
extern unsigned int DAT_011778fc;
extern float DAT_01177930;
extern float DAT_01177934;
extern void* DAT_0116f320;
extern void* DAT_0116f300;
extern PassGeom_b8d170** DAT_0116efd0;
extern Point3_b8d170 DAT_0108edc8;
extern Point3_b8d170 DAT_0108f04c;
extern float DAT_01177100;
extern float DAT_01177104;
extern float DAT_01177108;
extern PassRoot_b8d170* DAT_0116ef9c;
extern float DAT_01177124;
extern float DAT_01177128;
extern float DAT_0117712c;

// pdb: Lighting30Shader::UpdatePass | Lighting30Shader_Update.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: aePassEnum, apL30Prop
PassEntry_b8d170* PassShader_b8d170::FUN_00b8d170(int kind, PassContext_b8d170* context)
{
    PassEntry_b8d170* pass = 0;
    switch (kind)
    {
    case 10:
        pass = DAT_01176c64;
        break;
    case 11:
        pass = DAT_01176c68;
        break;
    case 12:
        pass = DAT_01176c6c;
        break;
    case 13:
        pass = DAT_01176c70;
        break;
    case 14:
        pass = DAT_01176c74;
        FUN_00b40410(context, pass);
        break;
    case 15:
        pass = DAT_01176c78;
        FUN_00b40410(context, pass);
        break;
    case 376:
        pass = DAT_01176c60;
        break;
    case 383:
        pass = DAT_01176c7c;
        break;
    case 384:
        pass = DAT_01176c80;
        break;
    case 385:
        pass = DAT_01176c84;
        DAT_011778f0 = context->color84;
        DAT_011778f4 = context->color88;
        DAT_011778f8 = context->color8c;
        DAT_011778fc = context->color90;
        pass->stages[4]->texture = DAT_0116f320;
        pass->stages[5]->texture = *context->sourceB4;
        break;
    case 386:
        pass = DAT_01176c88;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 387:
        pass = DAT_01176c8c;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 388:
        pass = DAT_01176c90;
        {
            const bool withVertexColor = false;
            pass->stages[4]->texture = context->sourceAC->data;
            pass->stages[5]->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassStage_b8d170* stage = pass->stages[6];
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 389:
        pass = DAT_01176c94;
        {
            const bool withVertexColor = true;
            pass->stages[4]->texture = context->sourceAC->data;
            pass->stages[5]->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassStage_b8d170* stage = pass->stages[6];
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 390:
        pass = DAT_01176c98;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 391:
        pass = DAT_01176c9c;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 392:
        pass = DAT_01176ca0;
        break;
    case 393:
        pass = DAT_01176ca4;
        break;
    case 394:
        pass = DAT_01176ca8;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 395:
        pass = DAT_01176cac;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 396:
        pass = DAT_01176cb0;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 397:
        pass = DAT_01176cb4;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 398:
        pass = DAT_01176cb8;
        break;
    case 399:
        pass = DAT_01176cbc;
        break;
    case 400:
        pass = DAT_01176cc0;
        DAT_011778f0 = context->color84;
        DAT_011778f4 = context->color88;
        DAT_011778f8 = context->color8c;
        DAT_011778fc = context->color90;
        pass->stages[4]->texture = DAT_0116f320;
        pass->stages[5]->texture = *context->sourceB4;
        break;
    case 401:
        pass = DAT_01176cc4;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 402:
        pass = DAT_01176cc8;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 403:
        pass = DAT_01176ccc;
        {
            const bool withVertexColor = false;
            pass->stages[4]->texture = context->sourceAC->data;
            pass->stages[5]->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassStage_b8d170* stage = pass->stages[6];
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 404:
        pass = DAT_01176cd0;
        {
            const bool withVertexColor = true;
            pass->stages[4]->texture = context->sourceAC->data;
            pass->stages[5]->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassStage_b8d170* stage = pass->stages[6];
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 405:
        pass = DAT_01176cd4;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 406:
        pass = DAT_01176cd8;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 407:
        pass = DAT_01176cdc;
        break;
    case 408:
        pass = DAT_01176ce0;
        break;
    case 409:
        pass = DAT_01176ce4;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 410:
        pass = DAT_01176ce8;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8cf10(pass, context, 4);
        break;
    case 411:
        pass = DAT_01176cec;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 412:
        pass = DAT_01176cb4;
        pass->stages[6]->texture = *context->sourceB4;
        break;
    case 413:
        pass = DAT_01176cf4;
        FUN_00b8d000(pass);
        break;
    case 414:
        pass = DAT_01176cf8;
        FUN_00b8d000(pass);
        break;
    case 415:
        pass = DAT_01176cfc;
        DAT_011778f0 = context->color84;
        DAT_011778f4 = context->color88;
        DAT_011778f8 = context->color8c;
        DAT_011778fc = context->color90;
        pass->stages[4]->texture = DAT_0116f320;
        pass->stages[5]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 416:
        pass = DAT_01176d00;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 417:
        pass = DAT_01176d04;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 418:
        pass = DAT_01176d08;
        FUN_00b8d000(pass);
        pass->stages[4]->texture = context->sourceAC->data;
        pass->stages[5]->texture = context->sourceB0->data;
        break;
    case 419:
        pass = DAT_01176d0c;
        FUN_00b8d000(pass);
        pass->stages[4]->texture = context->sourceAC->data;
        pass->stages[5]->texture = context->sourceB0->data;
        {
            PassStage_b8d170* stage = pass->stages[6];
            stage->texture = context->GetTexture(2, 0);
        }
        break;
    case 420:
        pass = DAT_01176d10;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 421:
        pass = DAT_01176d14;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 422:
        pass = DAT_01176d18;
        FUN_00b8d000(pass);
        break;
    case 423:
        pass = DAT_01176d1c;
        FUN_00b8d000(pass);
        break;
    case 424:
        pass = DAT_01176d20;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 425:
        pass = DAT_01176d24;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 426:
        pass = DAT_01176d28;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 427:
        pass = DAT_01176d2c;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 428:
        pass = DAT_01176d30;
        FUN_00b8d000(pass);
        break;
    case 429:
        pass = DAT_01176d34;
        FUN_00b8d000(pass);
        break;
    case 430:
        pass = DAT_01176d38;
        DAT_011778f0 = context->color84;
        DAT_011778f4 = context->color88;
        DAT_011778f8 = context->color8c;
        DAT_011778fc = context->color90;
        pass->stages[4]->texture = DAT_0116f320;
        pass->stages[5]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 431:
        pass = DAT_01176d3c;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 432:
        pass = DAT_01176d40;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 433:
        pass = DAT_01176d44;
        FUN_00b8d000(pass);
        pass->stages[4]->texture = context->sourceAC->data;
        pass->stages[5]->texture = context->sourceB0->data;
        break;
    case 434:
        pass = DAT_01176d48;
        FUN_00b8d000(pass);
        pass->stages[4]->texture = context->sourceAC->data;
        pass->stages[5]->texture = context->sourceB0->data;
        {
            PassStage_b8d170* stage = pass->stages[6];
            stage->texture = context->GetTexture(2, 0);
        }
        break;
    case 435:
        pass = DAT_01176d4c;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 436:
        pass = DAT_01176d50;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 437:
        pass = DAT_01176d54;
        FUN_00b8d000(pass);
        break;
    case 438:
        pass = DAT_01176d58;
        FUN_00b8d000(pass);
        break;
    case 439:
        pass = DAT_01176d5c;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 440:
        pass = DAT_01176d60;
        DAT_01177930 = context->scaleE8;
        DAT_01177934 = context->scaleEC;
        FUN_00b8d000(pass);
        FUN_00b8cf10(pass, context, 4);
        break;
    case 441:
        pass = DAT_01176d64;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 442:
        pass = DAT_01176d68;
        pass->stages[6]->texture = *context->sourceB4;
        FUN_00b8d000(pass);
        break;
    case 445:
        pass = DAT_01176d74;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        break;
    case 446:
        pass = DAT_01176d78;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        break;
    case 447:
        pass = DAT_01176d7c;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        break;
    case 448:
        pass = DAT_01176d80;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        break;
    case 449:
        pass = DAT_01176d84;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        break;
    case 450:
        pass = DAT_01176d88;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        break;
    case 451:
        pass = DAT_01176d8c;
        FUN_00b8d030(pass, context, kind);
        FUN_00b8d0c0(pass, context);
        FUN_00b8d120(pass, context, 0);
        {
            PassGeom_b8d170* geom = *DAT_0116efd0;
            Point3_b8d170* position = geom->position ? geom->position : &DAT_0108edc8;
            Point3_b8d170 relative = *position - DAT_0108f04c;
            DAT_01177100 = relative.x;
            DAT_01177104 = relative.y;
            DAT_01177108 = relative.z;
        }
        break;
    case 730:
        pass = DAT_01176e00;
        break;
    case 731:
        pass = DAT_01176e04;
        break;
    case 736:
        pass = DAT_01176e08;
        break;
    case 737:
        pass = DAT_01176e0c;
        break;
    case 742:
        pass = DAT_01176e10;
        break;
    case 743:
        pass = DAT_01176e14;
        break;
    case 748:
        pass = DAT_01176e18;
        break;
    case 749:
        pass = DAT_01176e1c;
        break;
    case 452:
        pass = DAT_01176d90;
        break;
    case 453:
        pass = DAT_01176d94;
        break;
    case 454:
        pass = DAT_01176d98;
        break;
    case 455:
        pass = DAT_01176d9c;
        break;
    case 480:
        pass = DAT_01176df8;
        FUN_00b40340(context, pass);
        break;
    case 481:
        pass = DAT_01176dfc;
        FUN_00b40340(context, pass);
        break;
    case 467:
        pass = DAT_01176dc4;
        break;
    case 468:
        pass = DAT_01176dc8;
        break;
    case 469:
        pass = DAT_01176dcc;
        break;
    case 470:
        pass = DAT_01176dd0;
        break;
    case 456:
        pass = DAT_01176da0;
        pass->stages[0]->texture = context->sourceAC->first;
        FUN_00b3ec50(pass, 1);
        break;
    case 458:
        pass = DAT_01176da8;
        pass->stages[0]->texture = context->sourceAC->first;
        FUN_00b3ec50(pass, 1);
        break;
    case 460:
        pass = DAT_01176db0;
        {
            void* texture = context->sourceB0->first;
            if (!texture)
                texture = DAT_0116f300;
            pass->stages[0]->texture = texture;
        }
        FUN_00b3ec50(pass, 1);
        break;
    case 462:
        pass = DAT_01176db4;
        {
            void* texture = context->sourceB0->first;
            if (!texture)
                texture = DAT_0116f300;
            pass->stages[0]->texture = texture;
        }
        FUN_00b3ec50(pass, 1);
        break;
    case 464:
        pass = DAT_01176db8;
        {
            void* texture = context->sourceB0->first;
            if (!texture)
                texture = DAT_0116f300;
            pass->stages[0]->texture = texture;
        }
        FUN_00b3ec50(pass, 1);
        break;
    case 465:
        pass = DAT_01176dbc;
        FUN_00b3ec50(pass, 0);
        break;
    case 466:
        pass = DAT_01176dc0;
        FUN_00b3ec50(pass, 0);
        break;
    case 443:
        pass = DAT_01176d6c;
        FUN_00b3ec50(pass, 1);
        break;
    case 444:
        pass = DAT_01176d70;
        FUN_00b3ec50(pass, 1);
        break;
    case 471:
        pass = DAT_01176dd4;
        FUN_00b3ec50(pass, 0);
        break;
    case 472:
        pass = DAT_01176dd8;
        FUN_00b3ec50(pass, 0);
        break;
    case 473:
        pass = DAT_01176ddc;
        FUN_00b3ec50(pass, 0);
        FUN_00afb5f0();
        break;
    case 474:
        pass = DAT_01176de0;
        FUN_00b3ec50(pass, 0);
        FUN_00afb5f0();
        break;
    case 475:
        pass = DAT_01176de4;
        FUN_00b3ec50(pass, 0);
        DAT_01177124 = DAT_0116ef9c->root->effect->GetParameter();
        DAT_01177128 = DAT_0116ef9c->root->effect->parameter58;
        DAT_0117712c = 0.0f;
        FUN_00afb5f0();
        break;
    case 476:
        pass = DAT_01176de8;
        FUN_00b3ec50(pass, 0);
        DAT_01177124 = DAT_0116ef9c->root->effect->GetParameter();
        DAT_01177128 = DAT_0116ef9c->root->effect->parameter58;
        DAT_0117712c = 0.0f;
        break;
    case 477:
        pass = DAT_01176dec;
        FUN_00b3ec50(pass, 0);
        break;
    case 478:
        pass = DAT_01176df0;
        FUN_00b3ec50(pass, 0);
        break;
    case 479:
        pass = DAT_01176df4;
        FUN_00b3ec50(pass, 0);
        break;
    }
    return pass;
}

// @f3 0x00b9dbf0 (community match, verified in this file)
namespace f3m_00b9dbf0 {
void __cdecl FUN_00ba0ec0(DeflateState*, char*, unsigned long, int);

static int ReadInput(DeflateStream* strm, unsigned char* buf, unsigned size)
{
    unsigned len = strm->avail_in;
    if (len > size) len = size;
    if (len == 0) return 0;
    strm->avail_in -= len;
    if (strm->state->wrap == 1)
        strm->adler = FUN_00b9f270(strm->adler, strm->next_in, len);
    else if (strm->state->wrap == 2)
        strm->adler = FUN_00b9f650(strm->adler, strm->next_in, len);
    memcpy(buf, strm->next_in, len);
    strm->next_in += len;
    strm->total_in += len;
    return (int)len;
}

// pdb: fill_window | deflate.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) void fill_window(DeflateState* s)
{
    unsigned n, m;
    unsigned short* p;
    unsigned more;
    unsigned wsize = s->w_size;
    do {
        more = s->window_size - s->lookahead - s->strstart;
        if (s->strstart >= wsize + (s->w_size - 262)) {
            memcpy(s->window, s->window + wsize, wsize);
            s->match_start -= wsize;
            s->strstart -= wsize;
            s->block_start -= (long)wsize;
            n = s->hash_size;
            p = &s->head[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m-wsize : 0);
            } while (--n);
            n = wsize;
            p = &s->prev[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m-wsize : 0);
            } while (--n);
            more += wsize;
        }
        if (s->strm->avail_in == 0) return;
        n = ReadInput(s->strm, s->window + s->strstart + s->lookahead, more);
        s->lookahead += n;
        if (s->lookahead >= 3) {
            s->ins_h = s->window[s->strstart];
            s->ins_h = ((s->ins_h << s->hash_shift) ^ s->window[s->strstart+1]) & s->hash_mask;
        }
    } while (s->lookahead < 262 && s->strm->avail_in != 0);
}

static __forceinline void FlushPendingInline(DeflateStream* strm)
{
    unsigned len = strm->state->pending;
    if (len > strm->avail_out) len = strm->avail_out;
    if (len == 0) return;
    memcpy(strm->next_out, strm->state->pending_out, len);
    strm->next_out += len;
    strm->state->pending_out += len;
    strm->total_out += len;
    strm->avail_out -= len;
    strm->state->pending -= len;
    if (strm->state->pending == 0)
        strm->state->pending_out = strm->state->pending_buf;
}

// pdb: deflate_stored | deflate.obj | fnv360_0822_retail, objrun, medium
int __cdecl FUN_00b9dbf0(DeflateState* s, int flush)
{
    unsigned long max_block_size = 0xffff;
    unsigned long max_start;
    if (max_block_size > s->pending_buf_size - 5)
        max_block_size = s->pending_buf_size - 5;
    for (;;) {
        if (s->lookahead <= 1) {
            fill_window(s);
            if (s->lookahead == 0 && flush == 0) return 0;
            if (s->lookahead == 0) break;
        }
        s->strstart += s->lookahead;
        s->lookahead = 0;
        max_start = s->block_start + max_block_size;
        if (s->strstart == 0 || (unsigned long)s->strstart >= max_start) {
            s->lookahead = (unsigned)(s->strstart-max_start);
            s->strstart = (unsigned)max_start;
            FUN_00ba0ec0(s, s->block_start >= 0L ? (char*)&s->window[(unsigned)s->block_start] : 0,
                         (unsigned long)((long)s->strstart-s->block_start), 0);
            s->block_start = s->strstart;
            FlushPendingInline(s->strm);
            if (s->strm->avail_out == 0) return 0;
        }
        if (s->strstart - (unsigned)s->block_start >= s->w_size - 262) {
            FUN_00ba0ec0(s, s->block_start >= 0L ? (char*)&s->window[(unsigned)s->block_start] : 0,
                         (unsigned long)((long)s->strstart-s->block_start), 0);
            s->block_start = s->strstart;
            FlushPendingInline(s->strm);
            if (s->strm->avail_out == 0) return 0;
        }
    }
    FUN_00ba0ec0(s, s->block_start >= 0L ? (char*)&s->window[(unsigned)s->block_start] : 0,
                 (unsigned long)((long)s->strstart-s->block_start), flush == 4);
    s->block_start = s->strstart;
    FUN_00b9d2b0(s->strm);
    if (s->strm->avail_out == 0) return flush == 4 ? 2 : 0;
    return flush == 4 ? 3 : 1;
}
}   // namespace f3m_00b9dbf0

// @f3 0x00b9d850 (community match, verified in this file)
namespace f3m_00b9d850 {
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.1, November 17th, 2003

  Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu


  The data format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 in the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (deflate format) and rfc1952.txt (gzip format).
*/

// Adapted from zlib 1.2.1 trees.c, Copyright (C) 1995-2003 Jean-loup Gailly.
// Altered for the FO3 contribution: C++ declarations and explicit macro expansions.
// Original source and license retained in the local FNV reference checkout.
typedef unsigned char uch; typedef unsigned char Byte; typedef unsigned char Bytef; typedef unsigned char uchf;
typedef unsigned short ush; typedef unsigned short ushf; typedef unsigned short Posf; typedef unsigned int uInt; typedef unsigned int IPos;
typedef unsigned long ulg; typedef int intf; typedef void* z_streamp;
typedef struct ct_data_s { union { ush freq; ush code; } fc; union { ush dad; ush len; } dl; } ct_data;
typedef struct static_tree_desc_s static_tree_desc;
typedef struct tree_desc_s { ct_data* dyn_tree; int max_code; static_tree_desc* stat_desc; } tree_desc;
struct static_tree_desc_s {
    const ct_data *static_tree;  
    const intf *extra_bits;      
    int     extra_base;          
    int     elems;               
    int     max_length;          
};
typedef struct internal_state {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    

    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        

    Bytef *window;

    ulg window_size;

    Posf *prev;

    Posf *head; 

    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      

    uInt  hash_shift;

    long block_start;

    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              

    uInt prev_length;

    uInt max_chain_length;

    uInt max_lazy_match;

    int level;    
    int strategy; 

    uInt good_match;

    int nice_match; 

    struct ct_data_s dyn_ltree[573];   
    struct ct_data_s dyn_dtree[2*30+1]; 
    struct ct_data_s bl_tree[2*19+1];  

    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              

    ush bl_count[15+1];

    int heap[2*286+1];      
    int heap_len;               
    int heap_max;               

    uch depth[2*286+1];

    uchf *l_buf;          

    uInt  lit_bufsize;

    uInt last_lit;      

    ushf *d_buf;

    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   

    ush bi_buf;
    
    int bi_valid;

} deflate_state;

// pdb: longest_match | deflate.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_seq), high
static uInt longest_match(deflate_state *s, IPos cur_match)                             
{
    unsigned chain_length = s->max_chain_length;
    register Bytef *scan = s->window + s->strstart; 
    register Bytef *match;                       
    register int len;                           
    int best_len = s->prev_length;              
    int nice_match = s->nice_match;             
    IPos limit = s->strstart > (IPos)((s)->w_size-(258+3+1)) ?
        s->strstart - (IPos)((s)->w_size-(258+3+1)) : 0;

    Posf *prev = s->prev;
    uInt wmask = s->w_mask;

    register Bytef *strend = s->window + s->strstart + 258;
    register Byte scan_end1  = scan[best_len-1];
    register Byte scan_end   = scan[best_len];


    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }

    if ((uInt)nice_match > s->lookahead) nice_match = s->lookahead;


    do {
        match = s->window + cur_match;

        if (match[best_len]   != scan_end  ||
            match[best_len-1] != scan_end1 ||
            *match            != *scan     ||
            *++match          != scan[1])      continue;

        scan += 2, match++;

        do {
        } while (*++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 scan < strend);


        len = 258 - (int)(strend - scan);
        scan = strend - 258;

        if (len > best_len) {
            s->match_start = cur_match;
            best_len = len;
            if (len >= nice_match) break;

            scan_end1  = scan[best_len-1];
            scan_end   = scan[best_len];

        }
    } while ((cur_match = prev[cur_match & wmask]) > limit
             && --chain_length != 0);

    if ((uInt)best_len <= s->lookahead) return (uInt)best_len;
    return s->lookahead;
}


deflate_state* volatile input_state_0140;
IPos volatile input_match_0140;
unsigned EmitLongestMatch0140() { return longest_match(input_state_0140,input_match_0140); }
}   // namespace f3m_00b9d850

// @f3 0x00b9f270 (community match, verified in this file)
namespace f3m_00b9f270 {
// Altered adaptation of zlib 1.2.1 adler32.c: macros expanded for Fallout 3 contribution.
// Original adler32.c copyright (C) 1995-2003 Mark Adler.
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.1, November 17th, 2003

  Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu


  The data format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 in the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (deflate format) and rfc1952.txt (gzip format).
*/

namespace fo3_00b9f270 {
// pdb: adler32 | adler32.obj | fnv360_0822_debug, call_seq, medium
// pdb params: adler, buf, len
unsigned long __cdecl FUN_00b9f270(unsigned long adler, const unsigned char* buf, unsigned int len)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;
    int k;
    if (buf == 0) return 1L;
    while (len > 0) {
        k = len < 5552 ? (int)len : 5552;
        len -= k;
        while (k >= 16) {
            { s1 += buf[0]; s2 += s1; }
            { s1 += buf[1]; s2 += s1; }
            { s1 += buf[2]; s2 += s1; }
            { s1 += buf[3]; s2 += s1; }
            { s1 += buf[4]; s2 += s1; }
            { s1 += buf[5]; s2 += s1; }
            { s1 += buf[6]; s2 += s1; }
            { s1 += buf[7]; s2 += s1; }
            { s1 += buf[8]; s2 += s1; }
            { s1 += buf[9]; s2 += s1; }
            { s1 += buf[10]; s2 += s1; }
            { s1 += buf[11]; s2 += s1; }
            { s1 += buf[12]; s2 += s1; }
            { s1 += buf[13]; s2 += s1; }
            { s1 += buf[14]; s2 += s1; }
            { s1 += buf[15]; s2 += s1; }
            buf += 16;
            k -= 16;
        }
        if (k != 0) do {
            s1 += *buf++;
            s2 += s1;
        } while (--k);
        s1 %= 65521UL;
        s2 %= 65521UL;
    }
    return (s2 << 16) | s1;
}
}
}   // namespace f3m_00b9f270

// @f3 0x00b82f60 (community match, verified in this file)
namespace f3_00b82f60 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
inline unsigned int NiAtomicIncrement(unsigned int& value) {
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int NiAtomicSubtract(unsigned int& value) {
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}
class NiRefObject {
public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount() { NiAtomicIncrement(m_uiRefCount); }
    void DecRefCount() { if (NiAtomicSubtract(m_uiRefCount) == 0) DeleteThis(); }
};

struct StageReturn
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    void FUN_0088fe30();
    void Release60()
    {
        if (--m_60 == 0)
            FUN_0088fe30();
    }
};
void FUN_0088ff50(StageReturn*& sr);
class Sub30
{
  public:
    void FUN_008905a0(int a, int b, int c);
};
Sub30* FUN_00890750();
void FUN_00b62c70(StageReturn* sr, int a, int b, int c, int d);
class NIPtr
{
  public:
    NiRefObject* m_pObject;
    NIPtr() : m_pObject(0)
    {}
    NIPtr& operator=(NiRefObject* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class ObjC
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    unsigned int m_18;
    unsigned int GetM18()
    {
        return m_18;
    }
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    Sub30* m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    NIPtr m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    NIPtr m_5c;
    int m_60;
    int m_64;
    void FUN_00888c10();
    void FUN_00888d30(int a, StageReturn* sr);
};
class ObjPtr
{
  public:
    ObjC* m_pObject;
    ObjPtr() : m_pObject(0)
    {}
    ~ObjPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_64 == 0)
                m_pObject->FUN_00888c10();
        }
    }
    ObjPtr& operator=(ObjC* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_64 == 0)
                    m_pObject->FUN_00888c10();
            }
            m_pObject = p;
            if (m_pObject)
                m_pObject->m_64++;
        }
        return *this;
    }
    ObjC* operator->() const
    {
        return m_pObject;
    }
};
class SRPtr
{
  public:
    StageReturn* m_pObject;
    SRPtr() : m_pObject(0)
    {}
    ~SRPtr()
    {
        if (m_pObject)
            m_pObject->Release60();
    }
};

extern ObjC* DAT_01174500;
extern ObjC* DAT_01174504;
extern ObjC* DAT_01174508;
extern ObjC* DAT_0117450c;
extern ObjC* DAT_01174510;
extern NiRefObject* DAT_01173cec;
extern NiRefObject* DAT_01173cf0;
extern NiRefObject* DAT_01173cf4;
extern NiRefObject* DAT_01173cf8;
extern NiRefObject* DAT_01173cfc;
extern NiRefObject* DAT_011739b4;
extern NiRefObject* DAT_011739b8;
extern NiRefObject* DAT_011739bc;
extern int DAT_01173188;
extern int DAT_011725a8;
extern int DAT_0117318c;
extern int DAT_011725ac;
extern int DAT_01173190;
extern int DAT_011725b0;
extern int DAT_01173194;
extern int DAT_011725b4;
extern int DAT_01173198;
extern int DAT_011725b8;

class FUN_00b78980_shell
{
  public:
    void FUN_00b82f60();
};
// @fnv 0x00c01020
// pdb: ShadowLightShader::PresetRenderNormalsPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void FUN_00b78980_shell::FUN_00b82f60()
{
    ObjPtr pObj;
    SRPtr sr;

    if (pObj.m_pObject != DAT_01174500)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00888c10();
        }
        pObj.m_pObject = DAT_01174500;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    if (pObj->GetM18() < 1)
    {
        FUN_0088ff50(sr.m_pObject);
        FUN_00b62c70(sr.m_pObject, 0, 1, 2, 1);
        pObj->FUN_00888d30(pObj->m_14, sr.m_pObject);
    }
    pObj->m_5c = DAT_01173cec;
    pObj->m_44 = DAT_011739b4;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(7, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(23, 4, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(14, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(168, 15, 1);
    DAT_01173188 = 16384;
    DAT_011725a8 = 131072;
    if (pObj.m_pObject != DAT_01174504)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00888c10();
        }
        pObj.m_pObject = DAT_01174504;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    if (pObj->GetM18() < 1)
    {
        FUN_0088ff50(sr.m_pObject);
        FUN_00b62c70(sr.m_pObject, 0, 1, 2, 1);
        pObj->FUN_00888d30(pObj->m_14, sr.m_pObject);
    }
    pObj->m_5c = DAT_01173cf0;
    pObj->m_44 = DAT_011739b4;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(7, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(23, 4, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(14, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(168, 15, 1);
    DAT_0117318c = 34816;
    DAT_011725ac = 131072;
    if (pObj.m_pObject != DAT_01174508)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00888c10();
        }
        pObj.m_pObject = DAT_01174508;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    if (pObj->GetM18() < 1)
    {
        FUN_0088ff50(sr.m_pObject);
        FUN_00b62c70(sr.m_pObject, 0, 1, 2, 1);
        pObj->FUN_00888d30(pObj->m_14, sr.m_pObject);
    }
    pObj->m_5c = DAT_01173cf4;
    pObj->m_44 = DAT_011739b8;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(27, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(19, 5, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(20, 6, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(7, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(23, 4, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(14, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(168, 15, 1);
    DAT_01173190 = 82944;
    DAT_011725b0 = 131072;
    if (pObj.m_pObject != DAT_0117450c)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00888c10();
        }
        pObj.m_pObject = DAT_0117450c;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    pObj->m_5c = DAT_01173cf8;
    pObj->m_44 = DAT_011739bc;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(7, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(14, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(168, 15, 1);
    DAT_01173194 = 0;
    DAT_011725b4 = 0;
    if (pObj.m_pObject != DAT_01174510)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00888c10();
        }
        pObj.m_pObject = DAT_01174510;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    pObj->m_5c = DAT_01173cfc;
    pObj->m_44 = DAT_011739bc;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(7, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(14, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00890750();
    pObj->m_30->FUN_008905a0(168, 15, 1);
    DAT_01173198 = 2048;
    DAT_011725b8 = 0;
}
}  // namespace f3_00b82f60

// @f3 0x00b83700 (community match, verified in this file)
namespace fo3_b83700 {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void FUN_008905a0(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00890750();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    int references;
    void FUN_0088fe30();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            FUN_0088fe30();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00888c10();
    void FUN_00888d30(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* const& GetState()
    {
        if (!state)
            state = FUN_00890750();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00888c10();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00888c10();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern float DAT_011761d8;
extern RefObject* DAT_011739c0;
extern ShaderPass* DAT_01174514;
extern RefObject* DAT_01173d00;
extern unsigned int DAT_0117319c, DAT_011725bc;
extern ShaderPass* DAT_01174518;
extern RefObject* DAT_01173d04;
extern unsigned int DAT_011731a0, DAT_011725c0;
extern ShaderPass* DAT_0117451c;
extern RefObject* DAT_01173d08;
extern unsigned int DAT_011731a4, DAT_011725c4;
// Returns the 32-bit value read from the address of the float parameter as an unsigned integer.
// @fnv 0x00c017c0
inline unsigned int FloatBits(float value)
{
    return *(unsigned int*)&value;
}
// pdb: ShadowLightShader::PresetDepthPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void FUN_00b83700()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_01174514;
    pass->vertexShader = DAT_01173d00;
    pass->pixelShader = DAT_011739c0;
    pass->GetState()->FUN_008905a0(27, 0, 1);
    pass->GetState()->FUN_008905a0(15, 0, 1);
    pass->GetState()->FUN_008905a0(7, 1, 1);
    pass->GetState()->FUN_008905a0(23, 4, 1);
    pass->GetState()->FUN_008905a0(14, 1, 1);
    pass->GetState()->FUN_008905a0(195, FloatBits(DAT_011761d8), 1);
    DAT_0117319c = 540672;
    DAT_011725bc = 0;
    pass = DAT_01174518;
    pass->vertexShader = DAT_01173d04;
    pass->pixelShader = DAT_011739c0;
    pass->GetState()->FUN_008905a0(27, 0, 1);
    pass->GetState()->FUN_008905a0(15, 0, 1);
    pass->GetState()->FUN_008905a0(7, 1, 1);
    pass->GetState()->FUN_008905a0(23, 4, 1);
    pass->GetState()->FUN_008905a0(14, 1, 1);
    pass->GetState()->FUN_008905a0(195, FloatBits(DAT_011761d8), 1);
    DAT_011731a0 = 559104;
    DAT_011725c0 = 0;
    pass = DAT_0117451c;
    pass->vertexShader = DAT_01173d08;
    pass->pixelShader = DAT_011739c0;
    pass->GetState()->FUN_008905a0(27, 0, 1);
    pass->GetState()->FUN_008905a0(15, 0, 1);
    pass->GetState()->FUN_008905a0(7, 1, 1);
    pass->GetState()->FUN_008905a0(23, 4, 1);
    pass->GetState()->FUN_008905a0(14, 1, 1);
    pass->GetState()->FUN_008905a0(195, FloatBits(DAT_011761d8), 1);
    DAT_011731a4 = 540672;
    DAT_011725c4 = 0;
}
}

// @f3 0x00b84ba0 (community match, verified in this file)
namespace task0232 {
struct Callee_00b8a790 { int FUN_00b23bc0(int flag, float x, float y, float z, float w); };
class NiCamera
{
  public:
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    float field6c;
    float field70;
    unsigned int field74;
    float field78;
    float field7c;
    unsigned int field80;
    float field84;
    float field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
    unsigned int fieldc0;
    unsigned int fieldc4;
    unsigned int fieldc8;
    unsigned int fieldcc;
    unsigned int fieldd0;
    unsigned int fieldd4;
    unsigned int fieldd8;
    unsigned int fielddc;
    unsigned int fielde0;
    unsigned int fielde4;
    unsigned int fielde8;
    float fieldec;
    float fieldf0;
};
extern NiCamera* DAT_0116ef6c;
extern float DAT_01178188;
extern "C" NiPoint3 DAT_01176270;
extern "C" float DAT_0116f200;
extern "C" float DAT_011760b0;
struct ShaderPair66
{
    void* field00;
    void* field04;
    Callee_00b8a790* first;
    Callee_00b8a790* second;
};
struct Shader66
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18;
    ShaderPair66* shaders;
    unsigned int field20, field24, field28, field2c, field30, field34, field38;
    unsigned int field3c, field40, field44, field48, field4c, field50, field54;
    unsigned int field58, field5c, field60, field64;
    float center, radius, parameter;
    int mode;
    float distance;
    bool FUN_00b84ba0(int unused);
};
class Point3
{
  public:
    float x, y, z;
    Point3()
    {}
    Point3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Point3 operator-() const
    {
        return Point3(-x, -y, -z);
    }
    float operator*(const Point3& pt) const
    {
        return y * pt.y + x * pt.x + z * pt.z;
    }
};
// Calls FUN_00b23bc0(0-2) on both shader entries from fields of DAT_0116ef6c and mode, FUN_00b23bc0(3) on the second if DAT_0116f200 > 0, and sets DAT_011760b0 to 3.0f.
// @fnv 0x00bd66c0
// pdb: ImageSpaceEffectDepthOfField::UpdateParams | ImageSpaceEffectDepthOfField.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apParam
bool Shader66::FUN_00b84ba0(int unused)
{
    float nearClip = DAT_0116ef6c->fieldec;
    float farClip = DAT_0116ef6c->fieldf0;
    float range = farClip - nearClip;
    float product = nearClip * farClip;
    float firstFlag = (mode == 1 || mode == 0) ? 1.0f : 0.0f;
    float secondFlag = (mode == 2 || mode == 0) ? 1.0f : 0.0f;
    Callee_00b8a790* shader = shaders->first;
    float low = center - radius;
    float high = radius + center;
    shader->FUN_00b23bc0(0, low, high, center, DAT_01178188);
    shader->FUN_00b23bc0(1, parameter, firstFlag, secondFlag, 0.0f);
    shader->FUN_00b23bc0(2, -100000000.0f, nearClip, range, product);
    shader = shaders->second;
    shader->FUN_00b23bc0(0, low, high, center, DAT_01178188);
    shader->FUN_00b23bc0(1, parameter, firstFlag, secondFlag, 0.0f);
    shader->FUN_00b23bc0(2, -100000000.0f, nearClip, range, product);
    Point3 kUp;
    kUp.x = DAT_0116ef6c->field6c;
    kUp.y = DAT_0116ef6c->field78;
    kUp.z = DAT_0116ef6c->field84;
    Point3 kRight;
    kRight.x = DAT_0116ef6c->field70;
    kRight.y = DAT_0116ef6c->field7c;
    kRight.z = DAT_0116ef6c->field88;
    Point3 kPos = *(const Point3*)&DAT_01176270;
    float scale = DAT_0116f200;
    if (scale > 0.0f)
    {
        const float& ratio = distance / (30.0 * scale);
        shader->FUN_00b23bc0(3, kRight * kPos, -kUp * kPos, ratio, 0.0f);
    }
    DAT_011760b0 = 3.0f;
    return true;
}

}

// @f3 0x00b9daa0 (community match, verified in this file)
namespace f3m_00b9daa0 {
static __declspec(noinline) void fill_window(DeflateState* s)
{
    register unsigned n, m;
    register unsigned short* p;
    unsigned more;
    unsigned wsize = s->w_size;
    do {
        more = (unsigned)(s->window_size - (unsigned long)s->lookahead - (unsigned long)s->strstart);
        if (s->strstart >= wsize + (s->w_size - 262)) {
            memcpy(s->window, s->window + wsize, wsize);
            s->match_start -= wsize;
            s->strstart -= wsize;
            s->block_start -= (long)wsize;
            n = s->hash_size;
            p = &s->head[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : 0);
            } while (--n);
            n = wsize;
            p = &s->prev[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : 0);
            } while (--n);
            more += wsize;
        }
        if (s->strm->avail_in == 0) return;
        {
            unsigned len = s->strm->avail_in;
            if (len > more) len = more;
            if (len == 0) return;
            s->strm->avail_in -= len;
            if (s->strm->state->wrap == 1)
                s->strm->adler = FUN_00b9f270(s->strm->adler, s->strm->next_in, len);
            else if (s->strm->state->wrap == 2)
                s->strm->adler = FUN_00b9f650(s->strm->adler, s->strm->next_in, len);
            memcpy(s->window + s->strstart + s->lookahead, s->strm->next_in, len);
            s->strm->next_in += len;
            s->strm->total_in += len;
            n = len;
        }
        s->lookahead += n;
        if (s->lookahead >= 3) {
            s->ins_h = s->window[s->strstart];
            s->ins_h = ((s->ins_h << s->hash_shift) ^ s->window[s->strstart + 1]) & s->hash_mask;
        }
    } while (s->lookahead < 262 && s->strm->avail_in != 0);
}
}   // namespace f3m_00b9daa0

// @f3 0x00b83b60 (community match, verified in this file)
namespace f3_0230 {
struct ShaderMap0230 {
    virtual void unused();
    virtual void DeleteThis();
    long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() { if (!InterlockedDecrement(&references)) DeleteThis(); }
};

class FNVConfigMap
{
  public:
    void FUN_008905a0(unsigned int id, unsigned int value, unsigned int enabled);
};
FNVConfigMap* __cdecl FUN_00890750();
struct FNVConfigObject
{
    unsigned int unk00;
    unsigned int unk04;
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
    FNVConfigMap* m_pConfig;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ::NiPointer<ShaderMap0230> m_spAlpha;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ::NiPointer<ShaderMap0230> m_spBeta;
    unsigned int unk60;
    unsigned int m_uiReferences;
    void FUN_00888c10();
    void IncRefCount()
    {
        ++m_uiReferences;
    }
    void DecRefCount()
    {
        if (--m_uiReferences == 0)
            FUN_00888c10();
    }
};
extern NiPointer<FNVConfigObject> DAT_01174520;
extern NiPointer<FNVConfigObject> DAT_01174524;
extern ShaderMap0230* DAT_01173d0c;
extern ShaderMap0230* DAT_01173d10;
extern ShaderMap0230* DAT_011739c4;
extern unsigned int DAT_011731a8;
extern unsigned int DAT_011731ac;
extern unsigned int DAT_011725c8;
extern unsigned int DAT_011725cc;
extern const float DAT_011761d8;

// Assigns shader constant maps and config values to two FNVConfigObject instances and sets four global constants.
// @fnv 0x00c01c20
// pdb: ShadowLightShader::PresetVelocityPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void __cdecl FUN_00b83b60()
{
    NiPointer<FNVConfigObject> p;
    NiPointer<FNVConfigObject> unused;
    p = DAT_01174520;
    p->m_spBeta = DAT_01173d0c;
    p->m_spAlpha = DAT_011739c4;
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(27, 0, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(15, 0, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(7, 1, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(23, 4, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(14, 1, 1);
    union FNVBits
    {
        float f;
        unsigned int u;
    } floatBits;
    floatBits.f = DAT_011761d8;
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(195, floatBits.u, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00890750();
    p->m_pConfig->FUN_008905a0(22, 1, 1);
    DAT_011731a8 = 0x384000;
    DAT_011725c8 = 0;
    p = DAT_01174524;
    {
        p->m_spBeta = DAT_01173d10;
        p->m_spAlpha = DAT_011739c4;
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(27, 0, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(15, 0, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(7, 1, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(23, 4, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(14, 1, 1);
        union FNVBits
        {
            float f;
            unsigned int u;
        } floatBits;
        floatBits.f = DAT_011761d8;
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(195, floatBits.u, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00890750();
        p->m_pConfig->FUN_008905a0(22, 1, 1);
    }
    DAT_011731ac = 0x389800;
    DAT_011725cc = 0;
}
}  // namespace fnv_00c01c20

// @f3 0x00b85180 (community match, verified in this file)
namespace f3m_00b85180 {
namespace fo3_b85180 {
class ImageSpaceEffectParam
{
  public:
    virtual ~ImageSpaceEffectParam();
};

template <class T> class NiTPrimitiveArray
{
  public:
    void* m_vptr;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    T& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    void FUN_005b3880(unsigned int i, const T& val);
};

struct FUN_00b850f0
{
    virtual ~FUN_00b850f0();
    int unk04, unk08, unk0C, unk10, unk14;
    NiTPrimitiveArray<ImageSpaceEffectParam*> m_Array;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78;
};

struct FUN_00b22590
{
    int unk00, unk04, unk08, unk0C;
    ~FUN_00b22590();
};

struct FUN_00b85180 : FUN_00b850f0
{
    FUN_00b22590 m_kTexture;
    FUN_00b22590 m_akTextures[3];
    virtual ~FUN_00b85180();
};

// Deletes the effect parameter objects stored in m_Array at indices 2, 1, 0, 0 and 3, clearing each slot to null.
// @fnv 0x00bd6fc0
// pdb: ImageSpaceEffectDepthOfField::~ImageSpaceEffectDepthOfField | ImageSpaceEffectDepthOfField.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
FUN_00b85180::~FUN_00b85180()
{
    if (m_Array.GetAt(2))
    {
        delete m_Array.GetAt(2);
        m_Array.FUN_005b3880(2, 0);
    }
    if (m_Array.GetAt(1))
    {
        delete m_Array.GetAt(1);
        m_Array.FUN_005b3880(1, 0);
    }
    if (m_Array.GetAt(0))
    {
        delete m_Array.GetAt(0);
        m_Array.FUN_005b3880(0, 0);
    }
    if (m_Array.GetAt(0))
    {
        delete m_Array.GetAt(0);
        m_Array.FUN_005b3880(0, 0);
    }
    if (m_Array.GetAt(3))
    {
        delete m_Array.GetAt(3);
        m_Array.FUN_005b3880(3, 0);
    }
}

}
}   // namespace f3m_00b85180

// @f3 0x00b9e140 (community match, verified in this file)
// Adapted from published zlib 1.2.1 deflate.c for f3decomp.
// Altered C++ version: macros expanded, K&R declarations modernized, helper symbols bound.
// Original authors Jean-loup Gailly and Mark Adler; https://github.com/madler/zlib/tree/v1.2.1
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.1, November 17th, 2003

  Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu


  The data format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 in the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (deflate format) and rfc1952.txt (gzip format).
*/
#include <string.h>
typedef unsigned char Byte;
typedef unsigned char Bytef;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef char charf;
typedef void* voidpf;
typedef unsigned char uch;
typedef uch uchf;
typedef unsigned short ush;
typedef ush ushf;
typedef unsigned long ulg;
typedef voidpf (*alloc_func)(voidpf,uInt,uInt);
typedef void (*free_func)(voidpf,voidpf);
struct internal_state;
typedef struct z_stream_s {
    Bytef    *next_in;  
    uInt     avail_in;  
    uLong    total_in;  
    Bytef    *next_out; 
    uInt     avail_out; 
    uLong    total_out; 
    char     *msg;      
    struct internal_state  *state; 
    alloc_func zalloc;  
    free_func  zfree;   
    voidpf     opaque;  
    int     data_type;  
    uLong   adler;      
    uLong   reserved;   
} z_stream;
typedef z_stream  *z_streamp;
typedef struct ct_data_s {
    union {
        ush  freq;       
        ush  code;       
    } fc;
    union {
        ush  dad;        
        ush  len;        
    } dl;
}  ct_data;
typedef struct static_tree_desc_s  static_tree_desc;
typedef struct tree_desc_s {
    ct_data *dyn_tree;           
    int     max_code;            
    static_tree_desc *stat_desc; 
}  tree_desc;
typedef ush Pos;
typedef Pos  Posf;
typedef unsigned IPos;
typedef struct internal_state {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    
    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        
    Bytef *window;
    ulg window_size;
    Posf *prev;
    Posf *head; 
    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      
    uInt  hash_shift;
    long block_start;
    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              
    uInt prev_length;
    uInt max_chain_length;
    uInt max_lazy_match;
    int level;    
    int strategy; 
    uInt good_match;
    int nice_match; 
    struct ct_data_s dyn_ltree[(2*(256+1+29)+1)];   
    struct ct_data_s dyn_dtree[2*30+1]; 
    struct ct_data_s bl_tree[2*19+1];  
    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              
    ush bl_count[15+1];
    int heap[2*(256+1+29)+1];      
    int heap_len;               
    int heap_max;               
    uch depth[2*(256+1+29)+1];
    uchf *l_buf;          
    uInt  lit_bufsize;
    uInt last_lit;      
    ushf *d_buf;
    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   
    ush bi_buf;
    int bi_valid;
}  deflate_state;
enum block_state { need_more, block_done, finish_started, finish_done };
extern const uch DAT_00ea6e80[];
extern const uch DAT_00ea6c80[];
void FUN_00ba0ec0(deflate_state*,charf*,ulg,int);
uLong FUN_00b9f270(uLong,const Bytef*,uInt);
uLong FUN_00b9f650(uLong,const Bytef*,uInt);

static void FUN_00b9d2b0(z_streamp strm)
{
    unsigned len = strm->state->pending;
    if (len > strm->avail_out) len = strm->avail_out;
    if (len == 0) return;
    memcpy(strm->next_out, strm->state->pending_out, len);
    strm->next_out  += len;
    strm->state->pending_out  += len;
    strm->total_out += len;
    strm->avail_out  -= len;
    strm->state->pending -= len;
    if (strm->state->pending == 0) {
        strm->state->pending_out = strm->state->pending_buf;
    }
}

static int ReadDeflateBuffer(z_streamp strm, Bytef* buf, unsigned size)
{
    unsigned len = strm->avail_in;
    if (len > size) len = size;
    if (len == 0) return 0;
    strm->avail_in  -= len;
    if (strm->state->wrap == 1) {
        strm->adler = FUN_00b9f270(strm->adler, strm->next_in, len);
    }
    else if (strm->state->wrap == 2) {
        strm->adler = FUN_00b9f650(strm->adler, strm->next_in, len);
    }
    memcpy(buf, strm->next_in, len);
    strm->next_in  += len;
    strm->total_in += len;
    return (int)len;
}

static uInt longest_match(deflate_state* s, IPos cur_match)
{
    unsigned chain_length = s->max_chain_length;
    register Bytef *scan = s->window + s->strstart; 
    register Bytef *match;                       
    register int len;                           
    int best_len = s->prev_length;              
    int nice_match = s->nice_match;             
    IPos limit = s->strstart > (IPos)((s)->w_size-(258+3+1)) ?
        s->strstart - (IPos)((s)->w_size-(258+3+1)) : 0;
    Posf *prev = s->prev;
    uInt wmask = s->w_mask;
    register Bytef *strend = s->window + s->strstart + 258;
    register Byte scan_end1  = scan[best_len-1];
    register Byte scan_end   = scan[best_len];
    ;
    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }
    if ((uInt)nice_match > s->lookahead) nice_match = s->lookahead;
    ;
    do {
        ;
        match = s->window + cur_match;
        if (match[best_len]   != scan_end  ||
            match[best_len-1] != scan_end1 ||
            *match            != *scan     ||
            *++match          != scan[1])      continue;
        scan += 2, match++;
        ;
        do {
        } while (*++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 scan < strend);
        ;
        len = 258 - (int)(strend - scan);
        scan = strend - 258;
        if (len > best_len) {
            s->match_start = cur_match;
            best_len = len;
            if (len >= nice_match) break;
            scan_end1  = scan[best_len-1];
            scan_end   = scan[best_len];
        }
    } while ((cur_match = prev[cur_match & wmask]) > limit
             && --chain_length != 0);
    if ((uInt)best_len <= s->lookahead) return (uInt)best_len;
    return s->lookahead;
}

// pdb: longest_match_fast | deflate.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_seq), high
static uInt longest_match_fast(deflate_state* s, IPos cur_match)
{
    register Bytef *scan = s->window + s->strstart; 
    register Bytef *match;                       
    register int len;                           
    register Bytef *strend = s->window + s->strstart + 258;
    match = s->window + cur_match;
    if (match[0] != scan[0] || match[1] != scan[1]) return 3-1;
    scan += 2, match += 2;
    do {
    } while (*++scan == *++match && *++scan == *++match &&
             *++scan == *++match && *++scan == *++match &&
             *++scan == *++match && *++scan == *++match &&
             *++scan == *++match && *++scan == *++match &&
             scan < strend);
    len = 258 - (int)(strend - scan);
    if (len < 3) return 3 - 1;
    s->match_start = cur_match;
    return (uInt)len <= s->lookahead ? (uInt)len : s->lookahead;
}

static void fill_window(deflate_state* s)
{
    register unsigned n, m;
    register Posf *p;
    unsigned more;    
    uInt wsize = s->w_size;
    do {
        more = (unsigned)(s->window_size -(ulg)s->lookahead -(ulg)s->strstart);
        if (sizeof(int) <= 2) {
            if (more == 0 && s->strstart == 0 && s->lookahead == 0) {
                more = wsize;
            } else if (more == (unsigned)(-1)) {
                more--;
            }
        }
        if (s->strstart >= wsize+((s)->w_size-(258+3+1))) {
            memcpy(s->window, s->window+wsize, (unsigned)wsize);
            s->match_start -= wsize;
            s->strstart    -= wsize; 
            s->block_start -= (long) wsize;
            n = s->hash_size;
            p = &s->head[n];
            do {
                m = *--p;
                *p = (Pos)(m >= wsize ? m-wsize : 0);
            } while (--n);
            n = wsize;
            p = &s->prev[n];
            do {
                m = *--p;
                *p = (Pos)(m >= wsize ? m-wsize : 0);
            } while (--n);
            more += wsize;
        }
        if (s->strm->avail_in == 0) return;
        ;
        n = ReadDeflateBuffer(s->strm, s->window + s->strstart + s->lookahead, more);
        s->lookahead += n;
        if (s->lookahead >= 3) {
            s->ins_h = s->window[s->strstart];
            (s->ins_h = (((s->ins_h)<<s->hash_shift) ^ (s->window[s->strstart+1])) & s->hash_mask);
        }
    } while (s->lookahead < (258+3+1) && s->strm->avail_in != 0);
}

// pdb: deflate_slow | deflate.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
block_state deflate_slow(deflate_state* s, int flush)
{
    IPos hash_head = 0;    
    int bflush;              
    for (;;) {
        if (s->lookahead < (258+3+1)) {
            fill_window(s);
            if (s->lookahead < (258+3+1) && flush == 0) {
                return need_more;
            }
            if (s->lookahead == 0) break; 
        }
        if (s->lookahead >= 3) {
            ((s->ins_h = (((s->ins_h)<<s->hash_shift) ^ (s->window[(s->strstart) + (3-1)])) & s->hash_mask), hash_head = s->prev[(s->strstart) & s->w_mask] = s->head[s->ins_h], s->head[s->ins_h] = (Pos)(s->strstart));
        }
        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = 3-1;
        if (hash_head != 0 && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= ((s)->w_size-(258+3+1))) {
            if (s->strategy < 2) {
                s->match_length = longest_match (s, hash_head);
            } else if (s->strategy == 3 && s->strstart - hash_head == 1) {
                s->match_length = longest_match_fast (s, hash_head);
            }
            if (s->match_length <= 5 && (s->strategy == 1
                || (s->match_length == 3 &&
                    s->strstart - s->match_start > 4096)
                )) {
                s->match_length = 3-1;
            }
        }
        if (s->prev_length >= 3 && s->match_length <= s->prev_length) {
            uInt max_insert = s->strstart + s->lookahead - 3;
            { uch len = (s->prev_length - 3); ush dist = (s->strstart -1 - s->prev_match); s->d_buf[s->last_lit] = dist; s->l_buf[s->last_lit++] = len; dist--; s->dyn_ltree[DAT_00ea6e80[len]+256+1].fc.freq++; s->dyn_dtree[((dist) < 256 ? (int)DAT_00ea6c80[dist] : (int)DAT_00ea6c80[256+((dist)>>7)])].fc.freq++; bflush = (s->last_lit == s->lit_bufsize-1); };
            s->lookahead -= s->prev_length-1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    ((s->ins_h = (((s->ins_h)<<s->hash_shift) ^ (s->window[(s->strstart) + (3-1)])) & s->hash_mask), hash_head = s->prev[(s->strstart) & s->w_mask] = s->head[s->ins_h], s->head[s->ins_h] = (Pos)(s->strstart));
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = 3-1;
            s->strstart++;
            if (bflush) { { FUN_00ba0ec0(s, (s->block_start >= 0L ? (charf *)&s->window[(unsigned)s->block_start] : (charf *)0), (ulg)((long)s->strstart - s->block_start), (0)); s->block_start = s->strstart; FUN_00b9d2b0(s->strm); ; }; if (s->strm->avail_out == 0) return (0) ? finish_started : need_more; };
        } else if (s->match_available) {
            { uch cc = (s->window[s->strstart-1]); s->d_buf[s->last_lit] = 0; s->l_buf[s->last_lit++] = cc; s->dyn_ltree[cc].fc.freq++; bflush = (s->last_lit == s->lit_bufsize-1); };
            if (bflush) {
                { FUN_00ba0ec0(s, (s->block_start >= 0L ? (charf *)&s->window[(unsigned)s->block_start] : (charf *)0), (ulg)((long)s->strstart - s->block_start), (0)); s->block_start = s->strstart; FUN_00b9d2b0(s->strm); ; };
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0) return need_more;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        { uch cc = (s->window[s->strstart-1]); s->d_buf[s->last_lit] = 0; s->l_buf[s->last_lit++] = cc; s->dyn_ltree[cc].fc.freq++; bflush = (s->last_lit == s->lit_bufsize-1); };
        s->match_available = 0;
    }
    { { FUN_00ba0ec0(s, (s->block_start >= 0L ? (charf *)&s->window[(unsigned)s->block_start] : (charf *)0), (ulg)((long)s->strstart - s->block_start), (flush == 4)); s->block_start = s->strstart; FUN_00b9d2b0(s->strm); ; }; if (s->strm->avail_out == 0) return (flush == 4) ? finish_started : need_more; };
    return flush == 4 ? finish_done : block_done;
}

// @f3 0x00b9ddd0 (community match, verified in this file)
namespace f3m_00b9ddd0 {
// Adapted from zlib 1.2.1 deflate_fast, Copyright 1995-2003 Jean-loup Gailly.
// Uses the claim pack's zlib state, tables and complete static helper bodies.
// pdb: deflate_fast | deflate.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
block_state deflate_fast(deflate_state* s, int flush)
{
    IPos hash_head = 0;
    int bflush;
    for (;;) {
        if (s->lookahead < 262) {
            fill_window(s);
            if (s->lookahead < 262 && flush == 0) return need_more;
            if (s->lookahead == 0) break;
        }
        if (s->lookahead >= 3) {
            ((s->ins_h = ((s->ins_h << s->hash_shift) ^ s->window[s->strstart + 2]) & s->hash_mask), hash_head = s->prev[s->strstart & s->w_mask] = s->head[s->ins_h], s->head[s->ins_h] = (Pos)s->strstart);
        }
        if (hash_head != 0 && s->strstart - hash_head <= s->w_size - 262) {
            if (s->strategy < 2) {
                s->match_length = longest_match(s, hash_head);
            } else if (s->strategy == 3 && s->strstart - hash_head == 1) {
                s->match_length = longest_match_fast(s, hash_head);
            }
        }
        if (s->match_length >= 3) {
            {
                uch len = s->match_length - 3;
                ush dist = s->strstart - s->match_start;
                s->d_buf[s->last_lit] = dist;
                s->l_buf[s->last_lit++] = len;
                dist--;
                s->dyn_ltree[DAT_00ea6e80[len] + 256 + 1].fc.freq++;
                s->dyn_dtree[dist < 256 ? (int)DAT_00ea6c80[dist] : (int)DAT_00ea6c80[256 + (dist >> 7)]].fc.freq++;
                bflush = s->last_lit == s->lit_bufsize - 1;
            }
            s->lookahead -= s->match_length;
            if (s->match_length <= s->max_lazy_match && s->lookahead >= 3) {
                s->match_length--;
                do {
                    s->strstart++;
                    ((s->ins_h = ((s->ins_h << s->hash_shift) ^ s->window[s->strstart + 2]) & s->hash_mask), hash_head = s->prev[s->strstart & s->w_mask] = s->head[s->ins_h], s->head[s->ins_h] = (Pos)s->strstart);
                } while (--s->match_length != 0);
                s->strstart++;
            } else {
                s->strstart += s->match_length;
                s->match_length = 0;
                s->ins_h = s->window[s->strstart];
                s->ins_h = ((s->ins_h << s->hash_shift) ^ s->window[s->strstart + 1]) & s->hash_mask;
            }
        } else {
            {
                uch cc = s->window[s->strstart];
                s->d_buf[s->last_lit] = 0;
                s->l_buf[s->last_lit++] = cc;
                s->dyn_ltree[cc].fc.freq++;
                bflush = s->last_lit == s->lit_bufsize - 1;
            }
            s->lookahead--;
            s->strstart++;
        }
        if (bflush) {
            FUN_00ba0ec0(s, s->block_start >= 0L ? (charf*)&s->window[(unsigned)s->block_start] : (charf*)0, (ulg)((long)s->strstart - s->block_start), 0);
            s->block_start = s->strstart;
            FUN_00b9d2b0(s->strm);
            if (s->strm->avail_out == 0) return 0 ? finish_started : need_more;
        }
    }
    FUN_00ba0ec0(s, s->block_start >= 0L ? (charf*)&s->window[(unsigned)s->block_start] : (charf*)0, (ulg)((long)s->strstart - s->block_start), (flush == 4));
            s->block_start = s->strstart;
            FUN_00b9d2b0(s->strm);
            if (s->strm->avail_out == 0) return (flush == 4) ? finish_started : need_more;
    return flush == 4 ? finish_done : block_done;
}
}   // namespace f3m_00b9ddd0

// @f3 0x00b9ffd0 (community match, verified in this file)
// zlib1.2.1 send_all_trees, Copyright 1995-2003 Jean-loup Gailly.
namespace f3m_00b9fac0 {
// pdb: send_all_trees | trees.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: compress_block)
static __declspec(noinline) void FUN_00b9ffd0(deflate_state* s, int lcodes, int dcodes, int blcodes)
{
    int rank;                    

    { int len = 5;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = lcodes-257;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (lcodes-257) << s->bi_valid;
    s->bi_valid += len;
  }
}; 
    { int len = 5;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = dcodes-1;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (dcodes-1) << s->bi_valid;
    s->bi_valid += len;
  }
};
    { int len = 4;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = blcodes-4;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (blcodes-4) << s->bi_valid;
    s->bi_valid += len;
  }
}; 
    for (rank = 0; rank < blcodes; rank++) {
        { int len = 3;
  if (s->bi_valid > (int)Buf_size - len) {
    int val = s->bl_tree[bl_order[rank]].dl.len;
    s->bi_buf |= (val << s->bi_valid);
    { {s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);} {s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);} }
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);
    s->bi_valid += len - Buf_size;
  } else {
    s->bi_buf |= (s->bl_tree[bl_order[rank]].dl.len) << s->bi_valid;
    s->bi_valid += len;
  }
};
    }

    FUN_00b9fac0(s, (ct_data *)s->dyn_ltree, lcodes-1); 

    FUN_00b9fac0(s, (ct_data *)s->dyn_dtree, dcodes-1); 
}
void EmitHeader0572(deflate_state* s,int literals,int distances,int lengths) { FUN_00b9ffd0(s,literals,distances,lengths); }
}

// @f3 0x00b86390 (community match, verified in this file)
namespace f3_0571 {
typedef f3_00b82f60::NiRefObject NiRefObject;
struct RenderColor
{
    float r, g, b, a;
};
struct RenderSettings
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
    unsigned int flags;
    RenderColor clearColor;
};
extern RenderSettings DAT_011781a0;
extern RenderColor DAT_01067b80;
extern bool DAT_0116f216;
struct NiRenderTargetGroup;
struct BSRenderedTexture : NiRefObject
{
    NiRenderTargetGroup* FUN_00aee520();
    void IncRefCount()
    {
        volatile long* p = (volatile long*)&m_uiRefCount;
        InterlockedIncrement(p);
    }
};
struct TextureInput
{
    BSRenderedTexture* FUN_00b22300() const;
};
struct RenderGeometry;
struct RenderPrimary
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void SetGeometry(RenderGeometry*);
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void SetMode(int);
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void SetSettings(RenderSettings*);
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
    void FUN_00b86290();
};
struct RenderSecondary
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
    TextureInput** textures;
    void FUN_00b86390(RenderGeometry*, int, RenderSettings*, bool);
};
struct RenderEffect : RenderPrimary, RenderSecondary
{
};
struct RenderGeometry
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
    RenderPrimary* owner;
};
struct RenderDevice
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void SetClearColor(const RenderColor*);
    virtual void slot0b0();
    virtual void GetClearColor(RenderColor*);
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual NiRenderTargetGroup* GetCurrentGroup();
    virtual NiRenderTargetGroup* GetDefaultGroup();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void ApplyColor(const RenderColor*);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int state;
    int unk204;
    unsigned char apply;
};
extern RenderDevice* DAT_0108f048;
extern RenderDevice* DAT_0116f2f8;
extern RenderColor DAT_00f73210;
struct RenderManager
{
    BSRenderedTexture* texture;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    RenderColor color;
};
extern RenderManager* DAT_0116ef9c;
void __cdecl FUN_00aeec20(unsigned int, int);
void __cdecl FUN_00aeec60(unsigned int, NiRenderTargetGroup*);
NiRenderTargetGroup* __cdecl FUN_00aee280();
void __cdecl FUN_00aeeb20();
struct FUN_00b2aec0
{
    int mode, geometry, enabled, unknown;
    ~FUN_00b2aec0();
};
FUN_00b2aec0 __cdecl FUN_00b2b020(RenderGeometry*, int, int, int, int);
void __cdecl FUN_00b0f230(void*, unsigned short, int, int, int);

// Sets up the geometry's owner, settings and mode, applies clear color and render target, runs the 0x2f6 pass, and restores the previous clear color.
// @fnv 0x00c03d80
// pdb: ImageSpaceShader::Render | ImageSpaceShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apGeometry, apRenderer, apParam, abEndFrame
void RenderSecondary::FUN_00b86390(RenderGeometry* geometry, int unused, RenderSettings* apSettings,
                                              bool restore)
{
    RenderSettings* settings = apSettings ? apSettings : &DAT_011781a0;
    NiPointer<BSRenderedTexture> texture(textures[0]->FUN_00b22300());
    RenderEffect* effect = static_cast<RenderEffect*>(this);
    geometry->owner = effect;
    effect->SetGeometry(geometry);
    effect->SetSettings(settings);
    effect->FUN_00b86290();
    unsigned int flags = settings->flags;
    RenderColor oldClearColor = {0, 0, 0, 0};
    if (!texture.m_pObject && DAT_0116f216)
    {
        flags = 1;
        reinterpret_cast<RenderDevice*>(DAT_0116f2f8)->GetClearColor(&oldClearColor);
        reinterpret_cast<RenderDevice*>(DAT_0116f2f8)->SetClearColor(reinterpret_cast<RenderColor*>(&DAT_00f73210));
    }
    else if (flags & 1)
    {
        reinterpret_cast<RenderDevice*>(DAT_0116f2f8)->GetClearColor(&oldClearColor);
        reinterpret_cast<RenderDevice*>(DAT_0116f2f8)->SetClearColor(&settings->clearColor);
    }
    if (texture.m_pObject)
    {
        if (DAT_0108f048->state == 0)
            FUN_00aeec60(flags, texture->FUN_00aee520());
    }
    else
    {
        if (DAT_0108f048->state == 0)
            FUN_00aeec20(flags, 0);
    }
    RenderColor* color = texture.m_pObject == DAT_0116ef9c->texture ? &DAT_0116ef9c->color : 0;
    if (!texture.m_pObject && DAT_0116f216)
    {
        RenderDevice* device = DAT_0108f048;
        if (device->GetCurrentGroup() == DAT_0108f048->GetDefaultGroup())
            color = &DAT_01067b80;
    }
    if ((DAT_0108f048->state == 1 || DAT_0108f048->state == 2) && DAT_0108f048->apply == 1)
        DAT_0108f048->ApplyColor(color);
    effect->SetMode(0x2f6);
    FUN_00b2aec0 pass = FUN_00b2b020(geometry, 0x2f6, 1, 0, 0);
    FUN_00b0f230(&pass, 0x2f6, 0, 0, 0);
    if (texture.m_pObject && restore)
    {
        NiRenderTargetGroup* group = DAT_0108f048->GetCurrentGroup();
        if (FUN_00aee280() != group)
            FUN_00aeeb20();
    }
    if (settings->flags & 1)
        reinterpret_cast<RenderDevice*>(DAT_0116f2f8)->SetClearColor(&oldClearColor);
}
}  // namespace fnv_00c03d80

// @f3 0x00b88770 (community match, verified in this file)
namespace f3_00b88770 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct AtomicObject
{
    virtual void GetType();
    virtual void DeleteThis();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refCount))
            DeleteThis();
    }
};
struct AtomicRef
{
    AtomicObject* ptr;
    __forceinline void Assign(AtomicObject* value)
    {
        if (ptr != value)
        {
            if (ptr)
                ptr->DecRefCount();
            ptr = value;
            if (ptr)
                ptr->IncRefCount();
        }
    }
};
struct Texture
{
    void FUN_0088f050(unsigned int);
    void FUN_0088f0b0(unsigned int);
};
struct TextureSet
{
    unsigned int unk00;
    Texture* primary;
    Texture* secondary;
};
struct RenderStateMap
{
    void FUN_008905a0(unsigned int, unsigned int, bool);
};
RenderStateMap* FUN_00890750();
struct Pass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    TextureSet* textures;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateMap* states;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    AtomicRef pixel;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    AtomicRef vertex;
    unsigned int unk60;
    unsigned int refCount;

    void FUN_00888c10();
    void FUN_008866f0(AtomicObject* value);
    void FUN_00886650(AtomicObject* value);
    __forceinline void SetState(unsigned int state, unsigned int value, bool save)
    {
        if (!states)
            states = FUN_00890750();
        states->FUN_008905a0(state, value, save);
    }
    __forceinline void SetFloat(unsigned int state, float value)
    {
        union FloatBits
        {
            float value;
            unsigned int bits;
        } converted;
        converted.value = value;
        SetState(state, converted.bits, true);
    }
    void FUN_00b02820(unsigned int, unsigned int, unsigned int);
};
struct PassRef
{
    Pass* ptr;
    PassRef() : ptr(0)
    {}
    ~PassRef()
    {
        Pass* previous = ptr;
        if (previous && !--previous->refCount)
            previous->FUN_00888c10();
    }
    __declspec(noinline) PassRef& operator=(const PassRef& other)
    {
        Assign(other);
        return *this;
    }
    __forceinline PassRef& Assign(const PassRef& other)
    {
        if (ptr != other.ptr)
        {
            if (ptr && !--ptr->refCount)
                ptr->FUN_00888c10();
            ptr = other.ptr;
            if (ptr)
                ++ptr->refCount;
        }
        return *this;
    }
    Pass* operator->() const
    {
        return ptr;
    }
    operator Pass*() const
    {
        return ptr;
    }
};
struct StageReturn
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;

    unsigned int refCount;
    void FUN_0088fe30();
};
struct StageRef
{
    StageReturn* ptr;
    StageRef() : ptr(0)
    {}
    ~StageRef()
    {
        if (ptr && !--ptr->refCount)
            ptr->FUN_0088fe30();
    }
};
void FUN_00b88360(Pass*, char);
__declspec(noinline) unsigned char FUN_00b88310(char a, char b, char c, char d, char e, char f, char g, char h)
{
    return (unsigned char)(a | (b << 1) | (c << 2) | (d << 3) | (e << 4) | (f << 5) | (g << 6) | (h << 7));
}
struct PassManager
{
    void FUN_00b88430();
    void FUN_00b88770();
};
extern float DAT_011761d8;
extern int DAT_0116efa0;
extern PassRef DAT_01176c60;
extern PassRef DAT_01176c64;
extern PassRef DAT_01176c68;
extern PassRef DAT_01176c6c;
extern PassRef DAT_01176c70;
extern PassRef DAT_01176c74;
extern PassRef DAT_01176c78;
extern PassRef DAT_01176dc4;
extern PassRef DAT_01176dc8;
extern PassRef DAT_01176dcc;
extern PassRef DAT_01176dd0;
extern PassRef DAT_01176c7c;
extern PassRef DAT_01176c80;
extern PassRef DAT_01176c84;
extern PassRef DAT_01176c88;
extern PassRef DAT_01176c8c;
extern PassRef DAT_01176c90;
extern PassRef DAT_01176c94;
extern PassRef DAT_01176c98;
extern PassRef DAT_01176c9c;
extern PassRef DAT_01176ca0;
extern PassRef DAT_01176ca4;
extern PassRef DAT_01176ca8;
extern PassRef DAT_01176cac;
extern PassRef DAT_01176cb0;
extern PassRef DAT_01176cb4;
extern PassRef DAT_01176cb8;
extern PassRef DAT_01176cbc;
extern PassRef DAT_01176cc0;
extern PassRef DAT_01176cc4;
extern PassRef DAT_01176cc8;
extern PassRef DAT_01176ccc;
extern PassRef DAT_01176cd0;
extern PassRef DAT_01176cd4;
extern PassRef DAT_01176cd8;
extern PassRef DAT_01176cdc;
extern PassRef DAT_01176ce0;
extern PassRef DAT_01176ce4;
extern PassRef DAT_01176ce8;
extern PassRef DAT_01176cec;
extern PassRef DAT_01176cf0;
extern PassRef DAT_01176cf4;
extern PassRef DAT_01176cf8;
extern PassRef DAT_01176cfc;
extern PassRef DAT_01176d00;
extern PassRef DAT_01176d04;
extern PassRef DAT_01176d08;
extern PassRef DAT_01176d0c;
extern PassRef DAT_01176d10;
extern PassRef DAT_01176d14;
extern PassRef DAT_01176d18;
extern PassRef DAT_01176d1c;
extern PassRef DAT_01176d20;
extern PassRef DAT_01176d24;
extern PassRef DAT_01176d28;
extern PassRef DAT_01176d2c;
extern PassRef DAT_01176d30;
extern PassRef DAT_01176d34;
extern PassRef DAT_01176d38;
extern PassRef DAT_01176d3c;
extern PassRef DAT_01176d40;
extern PassRef DAT_01176d44;
extern PassRef DAT_01176d48;
extern PassRef DAT_01176d4c;
extern PassRef DAT_01176d50;
extern PassRef DAT_01176d54;
extern PassRef DAT_01176d58;
extern PassRef DAT_01176d5c;
extern PassRef DAT_01176d60;
extern PassRef DAT_01176d64;
extern PassRef DAT_01176d68;
extern PassRef DAT_01176d74;
extern PassRef DAT_01176d78;
extern PassRef DAT_01176d7c;
extern PassRef DAT_01176d80;
extern PassRef DAT_01176d84;
extern PassRef DAT_01176d88;
extern PassRef DAT_01176d8c;
extern PassRef DAT_01176e00;
extern PassRef DAT_01176e04;
extern PassRef DAT_01176e08;
extern PassRef DAT_01176e0c;
extern PassRef DAT_01176e10;
extern PassRef DAT_01176e14;
extern PassRef DAT_01176e18;
extern PassRef DAT_01176e1c;
extern PassRef DAT_01176d90;
extern PassRef DAT_01176d94;
extern PassRef DAT_01176d98;
extern PassRef DAT_01176d9c;
extern PassRef DAT_01176db0;
extern PassRef DAT_01176db4;
extern PassRef DAT_01176db8;
extern PassRef DAT_01176dbc;
extern PassRef DAT_01176dc0;
extern PassRef DAT_01176d6c;
extern PassRef DAT_01176d70;
extern PassRef DAT_01176dd4;
extern PassRef DAT_01176dd8;
extern PassRef DAT_01176ddc;
extern PassRef DAT_01176de0;
extern PassRef DAT_01176de4;
extern PassRef DAT_01176de8;
extern PassRef DAT_01176df8;
extern PassRef DAT_01176dfc;
extern PassRef DAT_01176da0;
extern PassRef DAT_01176da4;
extern PassRef DAT_01176da8;
extern PassRef DAT_01176dac;
extern PassRef DAT_01176dec;
extern PassRef DAT_01176df0;
extern PassRef DAT_01176df4;
extern AtomicObject* DAT_01176c3c;
extern AtomicObject* DAT_01176a98;
extern AtomicObject* DAT_01176c40;
extern AtomicObject* DAT_01176a9c;
extern AtomicObject* DAT_01176c44;
extern AtomicObject* DAT_01176c48;
extern AtomicObject* DAT_01176c4c;
extern AtomicObject* DAT_01176aa0;
extern AtomicObject* DAT_01176c50;
extern AtomicObject* DAT_01176aa4;
extern AtomicObject* DAT_01176c54;
extern AtomicObject* DAT_01176aa8;
extern AtomicObject* DAT_01176c58;
extern AtomicObject* DAT_01176aac;
extern AtomicObject* DAT_01176b78;
extern AtomicObject* DAT_011769e8;
extern AtomicObject* DAT_01176b80;
extern AtomicObject* DAT_01176b84;
extern AtomicObject* DAT_011769f0;
extern AtomicObject* DAT_011769f8;
extern AtomicObject* DAT_01176b7c;
extern AtomicObject* DAT_011769fc;
extern AtomicObject* DAT_01176a08;
extern AtomicObject* DAT_01176a10;
extern AtomicObject* DAT_01176b8c;
extern AtomicObject* DAT_01176b88;
extern AtomicObject* DAT_011769ec;
extern AtomicObject* DAT_011769f4;
extern AtomicObject* DAT_01176a00;
extern AtomicObject* DAT_01176a04;
extern AtomicObject* DAT_01176a0c;
extern AtomicObject* DAT_01176a14;
extern AtomicObject* DAT_01176b90;
extern AtomicObject* DAT_01176a18;
extern AtomicObject* DAT_01176b98;
extern AtomicObject* DAT_01176b9c;
extern AtomicObject* DAT_01176a20;
extern AtomicObject* DAT_01176a28;
extern AtomicObject* DAT_01176b94;
extern AtomicObject* DAT_01176a2c;
extern AtomicObject* DAT_01176a38;
extern AtomicObject* DAT_01176a40;
extern AtomicObject* DAT_01176ba4;
extern AtomicObject* DAT_01176ba0;
extern AtomicObject* DAT_01176a1c;
extern AtomicObject* DAT_01176a24;
extern AtomicObject* DAT_01176a30;
extern AtomicObject* DAT_01176a34;
extern AtomicObject* DAT_01176a3c;
extern AtomicObject* DAT_01176a44;
extern AtomicObject* DAT_01176ba8;
extern AtomicObject* DAT_01176a48;
extern AtomicObject* DAT_01176a4c;
extern AtomicObject* DAT_01176bac;
extern AtomicObject* DAT_01176bb0;
extern AtomicObject* DAT_01176bb4;
extern AtomicObject* DAT_01176bb8;
extern AtomicObject* DAT_01176a50;
extern AtomicObject* DAT_01176bbc;
extern AtomicObject* DAT_01176a54;
extern AtomicObject* DAT_01176bc0;
extern AtomicObject* DAT_01176bc4;
extern AtomicObject* DAT_01176a58;
extern AtomicObject* DAT_01176bc8;
extern AtomicObject* DAT_01176bcc;
extern AtomicObject* DAT_01176bd0;
extern AtomicObject* DAT_01176bd4;
extern AtomicObject* DAT_01176bd8;
extern AtomicObject* DAT_01176bdc;
extern AtomicObject* DAT_01176a5c;
extern AtomicObject* DAT_01176be0;
extern AtomicObject* DAT_01176be4;
extern AtomicObject* DAT_01176be8;
extern AtomicObject* DAT_01176bfc;
extern AtomicObject* DAT_01176a68;
extern AtomicObject* DAT_01176c00;
extern AtomicObject* DAT_01176a6c;
extern AtomicObject* DAT_01176c04;
extern AtomicObject* DAT_01176a70;
extern AtomicObject* DAT_01176c08;
extern AtomicObject* DAT_01176a74;
extern AtomicObject* DAT_01176c0c;
extern AtomicObject* DAT_01176a78;
extern AtomicObject* DAT_01176a7c;
extern AtomicObject* DAT_01176c10;
extern AtomicObject* DAT_01176a80;
extern AtomicObject* DAT_01176c14;
extern AtomicObject* DAT_01176c18;
extern AtomicObject* DAT_01176c1c;
extern AtomicObject* DAT_01176c20;
extern AtomicObject* DAT_01176a84;
extern AtomicObject* DAT_01176c24;
extern AtomicObject* DAT_01176c34;
extern AtomicObject* DAT_01176a90;
extern AtomicObject* DAT_01176c38;
extern AtomicObject* DAT_01176a94;
extern AtomicObject* DAT_01176bec;
extern AtomicObject* DAT_01176a60;
extern AtomicObject* DAT_01176bf0;
extern AtomicObject* DAT_01176bf4;
extern AtomicObject* DAT_01176bf8;
extern AtomicObject* DAT_01176c28;
extern AtomicObject* DAT_01176a88;
extern AtomicObject* DAT_01176c2c;
extern AtomicObject* DAT_01176c30;
extern AtomicObject* DAT_01176a8c;
extern unsigned int DAT_011767c8;
extern unsigned int DAT_01176608;
extern unsigned int DAT_011767cc;
extern unsigned int DAT_0117660c;
extern unsigned int DAT_011767d0;
extern unsigned int DAT_01176610;
extern unsigned int DAT_011767d4;
extern unsigned int DAT_01176614;
extern unsigned int DAT_011767d8;
extern unsigned int DAT_01176618;
extern unsigned int DAT_011767dc;
extern unsigned int DAT_0117661c;
extern unsigned int DAT_011767e0;
extern unsigned int DAT_01176620;
extern unsigned int DAT_0117692c;
extern unsigned int DAT_0117676c;
extern unsigned int DAT_01176930;
extern unsigned int DAT_01176770;
extern unsigned int DAT_01176934;
extern unsigned int DAT_01176774;
extern unsigned int DAT_01176938;
extern unsigned int DAT_01176778;
extern unsigned int DAT_011767e4;
extern unsigned int DAT_01176624;
extern unsigned int DAT_011767e8;
extern unsigned int DAT_01176628;
extern unsigned int DAT_011767ec;
extern unsigned int DAT_0117662c;
extern unsigned int DAT_011767f0;
extern unsigned int DAT_01176630;
extern unsigned int DAT_011767f4;
extern unsigned int DAT_01176634;
extern unsigned int DAT_011767f8;
extern unsigned int DAT_01176638;
extern unsigned int DAT_011767fc;
extern unsigned int DAT_0117663c;
extern unsigned int DAT_01176800;
extern unsigned int DAT_01176640;
extern unsigned int DAT_01176804;
extern unsigned int DAT_01176644;
extern unsigned int DAT_01176808;
extern unsigned int DAT_01176648;
extern unsigned int DAT_0117680c;
extern unsigned int DAT_0117664c;
extern unsigned int DAT_01176810;
extern unsigned int DAT_01176650;
extern unsigned int DAT_01176814;
extern unsigned int DAT_01176654;
extern unsigned int DAT_01176818;
extern unsigned int DAT_01176658;
extern unsigned int DAT_0117681c;
extern unsigned int DAT_0117665c;
extern unsigned int DAT_01176820;
extern unsigned int DAT_01176660;
extern unsigned int DAT_01176824;
extern unsigned int DAT_01176664;
extern unsigned int DAT_01176828;
extern unsigned int DAT_01176668;
extern unsigned int DAT_0117682c;
extern unsigned int DAT_0117666c;
extern unsigned int DAT_01176830;
extern unsigned int DAT_01176670;
extern unsigned int DAT_01176834;
extern unsigned int DAT_01176674;
extern unsigned int DAT_01176838;
extern unsigned int DAT_01176678;
extern unsigned int DAT_0117683c;
extern unsigned int DAT_0117667c;
extern unsigned int DAT_01176840;
extern unsigned int DAT_01176680;
extern unsigned int DAT_01176844;
extern unsigned int DAT_01176684;
extern unsigned int DAT_01176848;
extern unsigned int DAT_01176688;
extern unsigned int DAT_0117684c;
extern unsigned int DAT_0117668c;
extern unsigned int DAT_01176850;
extern unsigned int DAT_01176690;
extern unsigned int DAT_01176854;
extern unsigned int DAT_01176694;
extern unsigned int DAT_01176858;
extern unsigned int DAT_01176698;
extern unsigned int DAT_0117685c;
extern unsigned int DAT_0117669c;
extern unsigned int DAT_01176860;
extern unsigned int DAT_011766a0;
extern unsigned int DAT_01176864;
extern unsigned int DAT_011766a4;
extern unsigned int DAT_01176868;
extern unsigned int DAT_011766a8;
extern unsigned int DAT_0117686c;
extern unsigned int DAT_011766ac;
extern unsigned int DAT_01176870;
extern unsigned int DAT_011766b0;
extern unsigned int DAT_01176874;
extern unsigned int DAT_011766b4;
extern unsigned int DAT_01176878;
extern unsigned int DAT_011766b8;
extern unsigned int DAT_0117687c;
extern unsigned int DAT_011766bc;
extern unsigned int DAT_01176880;
extern unsigned int DAT_011766c0;
extern unsigned int DAT_01176884;
extern unsigned int DAT_011766c4;
extern unsigned int DAT_01176888;
extern unsigned int DAT_011766c8;
extern unsigned int DAT_0117688c;
extern unsigned int DAT_011766cc;
extern unsigned int DAT_01176890;
extern unsigned int DAT_011766d0;
extern unsigned int DAT_01176894;
extern unsigned int DAT_011766d4;
extern unsigned int DAT_01176898;
extern unsigned int DAT_011766d8;
extern unsigned int DAT_0117689c;
extern unsigned int DAT_011766dc;
extern unsigned int DAT_011768a0;
extern unsigned int DAT_011766e0;
extern unsigned int DAT_011768a4;
extern unsigned int DAT_011766e4;
extern unsigned int DAT_011768a8;
extern unsigned int DAT_011766e8;
extern unsigned int DAT_011768ac;
extern unsigned int DAT_011766ec;
extern unsigned int DAT_011768b0;
extern unsigned int DAT_011766f0;
extern unsigned int DAT_011768b4;
extern unsigned int DAT_011766f4;
extern unsigned int DAT_011768b8;
extern unsigned int DAT_011766f8;
extern unsigned int DAT_011768bc;
extern unsigned int DAT_011766fc;
extern unsigned int DAT_011768c0;
extern unsigned int DAT_01176700;
extern unsigned int DAT_011768c4;
extern unsigned int DAT_01176704;
extern unsigned int DAT_011768c8;
extern unsigned int DAT_01176708;
extern unsigned int DAT_011768cc;
extern unsigned int DAT_0117670c;
extern unsigned int DAT_011768d0;
extern unsigned int DAT_01176710;
extern unsigned int DAT_011768dc;
extern unsigned int DAT_0117671c;
extern unsigned int DAT_011768e0;
extern unsigned int DAT_01176720;
extern unsigned int DAT_011768e4;
extern unsigned int DAT_01176724;
extern unsigned int DAT_011768e8;
extern unsigned int DAT_01176728;
extern unsigned int DAT_011768ec;
extern unsigned int DAT_0117672c;
extern unsigned int DAT_011768f0;
extern unsigned int DAT_01176730;
extern unsigned int DAT_011768f4;
extern unsigned int DAT_01176734;
extern unsigned int DAT_01176968;
extern unsigned int DAT_011767a8;
extern unsigned int DAT_0117696c;
extern unsigned int DAT_011767ac;
extern unsigned int DAT_01176970;
extern unsigned int DAT_011767b0;
extern unsigned int DAT_01176974;
extern unsigned int DAT_011767b4;
extern unsigned int DAT_01176978;
extern unsigned int DAT_011767b8;
extern unsigned int DAT_0117697c;
extern unsigned int DAT_011767bc;
extern unsigned int DAT_01176980;
extern unsigned int DAT_011767c0;
extern unsigned int DAT_01176984;
extern unsigned int DAT_011767c4;
extern unsigned int DAT_011768f8;
extern unsigned int DAT_01176738;
extern unsigned int DAT_011768fc;
extern unsigned int DAT_0117673c;
extern unsigned int DAT_01176900;
extern unsigned int DAT_01176740;
extern unsigned int DAT_01176904;
extern unsigned int DAT_01176744;
extern unsigned int DAT_01176918;
extern unsigned int DAT_01176758;
extern unsigned int DAT_0117691c;
extern unsigned int DAT_0117675c;
extern unsigned int DAT_01176920;
extern unsigned int DAT_01176760;
extern unsigned int DAT_01176924;
extern unsigned int DAT_01176764;
extern unsigned int DAT_01176928;
extern unsigned int DAT_01176768;
extern unsigned int DAT_011768d4;
extern unsigned int DAT_01176714;
extern unsigned int DAT_011768d8;
extern unsigned int DAT_01176718;
extern unsigned int DAT_0117693c;
extern unsigned int DAT_0117677c;
extern unsigned int DAT_01176940;
extern unsigned int DAT_01176780;
extern unsigned int DAT_01176944;
extern unsigned int DAT_01176784;
extern unsigned int DAT_01176948;
extern unsigned int DAT_01176788;
extern unsigned int DAT_0117694c;
extern unsigned int DAT_0117678c;
extern unsigned int DAT_01176950;
extern unsigned int DAT_01176790;
extern unsigned int DAT_01176960;
extern unsigned int DAT_011767a0;
extern unsigned int DAT_01176964;
extern unsigned int DAT_011767a4;
extern unsigned int DAT_01176908;
extern unsigned int DAT_01176748;
extern unsigned int DAT_0117690c;
extern unsigned int DAT_0117674c;
extern unsigned int DAT_01176910;
extern unsigned int DAT_01176750;
extern unsigned int DAT_01176914;
extern unsigned int DAT_01176754;
extern unsigned int DAT_01176954;
extern unsigned int DAT_01176794;
extern unsigned int DAT_01176958;
extern unsigned int DAT_01176798;
extern unsigned int DAT_0117695c;
extern unsigned int DAT_0117679c;

// pdb: Lighting30Shader::PresetStages | Lighting30Shader_Preset.obj | fnv360_0822_retail, uconst, low
void PassManager::FUN_00b88770()
{
    PassRef kIter;
    StageRef y;
    float r = DAT_011761d8;
    kIter.Assign(DAT_01176c60);
    FUN_00b88360(kIter, 0);
    kIter->vertex.Assign(DAT_01176c3c);
    kIter->pixel.Assign(DAT_01176a98);
    kIter->SetState(0x16, 1, 1);
    kIter->SetState(0xa8, 0, 1);
    DAT_011767c8 = 0x8a;
    DAT_01176608 = 0;

    kIter.Assign(DAT_01176c64);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c3c);
    kIter->pixel.Assign(DAT_01176a98);
    kIter->SetState(0xa8, 0, 1);
    DAT_011767cc = 2;
    DAT_0117660c = 0;

    kIter.Assign(DAT_01176c68);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c40);
    kIter->pixel.Assign(DAT_01176a9c);
    kIter->SetState(0xa8, 0, 1);
    DAT_011767d0 = 0x24;
    DAT_01176610 = 0;

    kIter.Assign(DAT_01176c6c);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c44);
    kIter->pixel.Assign(DAT_01176a98);
    kIter->SetState(0xa8, 0, 1);
    DAT_011767d4 = 2;
    DAT_01176614 = 0;

    kIter.Assign(DAT_01176c70);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c48);
    kIter->pixel.Assign(DAT_01176a9c);
    kIter->SetState(0xa8, 0, 1);
    DAT_011767d8 = 0x24;
    DAT_01176618 = 0;

    kIter.Assign(DAT_01176c74);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c4c);
    kIter->pixel.Assign(DAT_01176aa0);
    kIter->SetState(0xa8, 0, 1);
    kIter->SetState(0xf, 1, 1);
    kIter->SetState(0x19, 5, 1);
    kIter->SetState(0x18, 0, 1);
    float a = r + r;
    kIter->SetFloat(0xc3, a);
    DAT_011767dc = 2;
    DAT_0117661c = 0;

    kIter.Assign(DAT_01176c78);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c50);
    kIter->pixel.Assign(DAT_01176aa4);
    kIter->SetState(0xa8, 0, 1);
    kIter->SetState(0xf, 1, 1);
    kIter->SetState(0x19, 5, 1);
    kIter->SetState(0x18, 0, 1);
    kIter->SetFloat(0xc3, a);
    DAT_011767e0 = 0x24;
    DAT_01176620 = 0;

    kIter.Assign(DAT_01176dc4);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c54);
    kIter->pixel.Assign(DAT_01176aa8);
    kIter->SetState(0xa8, 3, 1);
    DAT_0117692c = 2;
    DAT_0117676c = 0x12;

    kIter.Assign(DAT_01176dc8);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c44);
    kIter->pixel.Assign(DAT_01176aa8);
    kIter->SetState(0xa8, 3, 1);
    DAT_01176930 = 2;
    DAT_01176770 = 0x12;

    kIter.Assign(DAT_01176dcc);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c58);
    kIter->pixel.Assign(DAT_01176aac);
    kIter->SetState(0xa8, 3, 1);
    DAT_01176934 = 0x24;
    DAT_01176774 = 0x12;

    kIter.Assign(DAT_01176dd0);
    FUN_00b88360(kIter, 1);
    kIter->vertex.Assign(DAT_01176c48);
    kIter->pixel.Assign(DAT_01176aac);
    kIter->SetState(0xa8, 3, 1);
    DAT_01176938 = 0x24;
    DAT_01176778 = 0x12;

    kIter.Assign(DAT_01176c7c);
    FUN_00b88360(kIter, 3);
    kIter->vertex.Assign(DAT_01176b78);
    kIter->pixel.Assign(DAT_011769e8);
    DAT_011767e4 = 0x10002;
    DAT_01176624 = 0x412;

    kIter.Assign(DAT_01176c80);
    FUN_00b88360(kIter, 3);
    kIter->vertex.Assign(DAT_01176b80);
    kIter->pixel.Assign(DAT_011769e8);
    DAT_011767e8 = 0x10024;
    DAT_01176628 = 0x412;

    kIter.Assign(DAT_01176c84);
    FUN_00b88360(kIter, 0x33);
    kIter->vertex.Assign(DAT_01176b84);
    kIter->pixel.Assign(DAT_011769f0);
    DAT_011767ec = 0x10002;
    DAT_0117662c = 0x41e;

    kIter.Assign(DAT_01176c88);
    FUN_00b88360(kIter, 0x13);
    kIter->vertex.Assign(DAT_01176b78);
    kIter->pixel.Assign(DAT_011769f8);
    DAT_011767f0 = 0x10002;
    DAT_01176630 = 0x416;

    kIter.Assign(DAT_01176c8c);
    FUN_00b88360(kIter, 0x13);
    kIter->vertex.Assign(DAT_01176b7c);
    kIter->pixel.Assign(DAT_011769fc);
    DAT_011767f4 = 0x10002;
    DAT_01176634 = 0x496;

    kIter.Assign(DAT_01176c90);
    FUN_00b88360(kIter, 0x33);
    kIter->vertex.Assign(DAT_01176b78);
    kIter->FUN_00886650(DAT_01176a08);
    DAT_011767f8 = 0x10002;
    DAT_01176638 = 0x416;

    kIter.Assign(DAT_01176c94);
    FUN_00b88360(kIter, 0x73);
    kIter->FUN_008866f0(DAT_01176b80);
    kIter->FUN_00886650(DAT_01176a08);
    DAT_011767fc = 0x10024;
    DAT_0117663c = 0x416;

    kIter.Assign(DAT_01176c98);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b78);
    kIter->FUN_00886650(DAT_01176a10);
    DAT_01176800 = 0x10002;
    DAT_01176640 = 0x432;

    kIter.Assign(DAT_01176c9c);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b80);
    kIter->FUN_00886650(DAT_01176a10);
    DAT_01176804 = 0x10024;
    DAT_01176644 = 0x432;

    kIter.Assign(DAT_01176ca0);
    FUN_00b88360(kIter, 3);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_011769e8);
    DAT_01176808 = 0x10002;
    DAT_01176648 = 0x412;

    kIter.Assign(DAT_01176ca4);
    FUN_00b88360(kIter, 3);
    kIter->FUN_008866f0(DAT_01176b8c);
    kIter->FUN_00886650(DAT_011769e8);
    DAT_0117680c = 0x10024;
    DAT_0117664c = 0x412;

    kIter.Assign(DAT_01176ca8);
    FUN_00b88360(kIter, 0x13);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_011769f8);
    DAT_01176810 = 0x1000a;
    DAT_01176650 = 0x416;

    kIter.Assign(DAT_01176cac);
    FUN_00b88360(kIter, 0x13);
    kIter->FUN_008866f0(DAT_01176b88);
    kIter->FUN_00886650(DAT_011769fc);
    DAT_01176814 = 0x1000a;
    DAT_01176654 = 0x496;

    kIter.Assign(DAT_01176cb0);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_01176a10);
    DAT_01176818 = 0x10002;
    DAT_01176658 = 0x432;

    kIter.Assign(DAT_01176cb4);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b8c);
    kIter->FUN_00886650(DAT_01176a10);
    DAT_0117681c = 0x10024;
    DAT_0117665c = 0x432;

    kIter.Assign(DAT_01176cb8);
    FUN_00b88360(kIter, 3);
    kIter->FUN_008866f0(DAT_01176b78);
    kIter->FUN_00886650(DAT_011769ec);
    DAT_01176820 = 0x10002;
    DAT_01176660 = 0x416;

    kIter.Assign(DAT_01176cbc);
    FUN_00b88360(kIter, 3);
    kIter->FUN_008866f0(DAT_01176b80);
    kIter->FUN_00886650(DAT_011769ec);
    DAT_01176824 = 0x10024;
    DAT_01176664 = 0x416;

    kIter.Assign(DAT_01176cc0);
    FUN_00b88360(kIter, 0x33);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_011769f4);
    DAT_01176828 = 0x10002;
    DAT_01176668 = 0x41e;

    kIter.Assign(DAT_01176cc4);
    FUN_00b88360(kIter, 0x13);
    kIter->FUN_008866f0(DAT_01176b78);
    kIter->FUN_00886650(DAT_01176a00);
    DAT_0117682c = 0x10002;
    DAT_0117666c = 0x416;

    kIter.Assign(DAT_01176cc8);
    FUN_00b88360(kIter, 0x13);
    kIter->FUN_008866f0(DAT_01176b7c);
    kIter->FUN_00886650(DAT_01176a04);
    DAT_01176830 = 0x10002;
    DAT_01176670 = 0x496;

    kIter.Assign(DAT_01176ccc);
    FUN_00b88360(kIter, 0x33);
    kIter->FUN_008866f0(DAT_01176b78);
    kIter->FUN_00886650(DAT_01176a0c);
    DAT_01176834 = 0x10002;
    DAT_01176674 = 0x416;

    kIter.Assign(DAT_01176cd0);
    FUN_00b88360(kIter, 0x73);
    kIter->FUN_008866f0(DAT_01176b80);
    kIter->FUN_00886650(DAT_01176a0c);
    DAT_01176838 = 0x10024;
    DAT_01176678 = 0x416;

    kIter.Assign(DAT_01176cd4);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b78);
    kIter->FUN_00886650(DAT_01176a14);
    DAT_0117683c = 0x10002;
    DAT_0117667c = 0x436;

    kIter.Assign(DAT_01176cd8);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b80);
    kIter->FUN_00886650(DAT_01176a14);
    DAT_01176840 = 0x10024;
    DAT_01176680 = 0x436;

    kIter.Assign(DAT_01176cdc);
    FUN_00b88360(kIter, 3);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_011769ec);
    DAT_01176844 = 0x10002;
    DAT_01176684 = 0x416;

    kIter.Assign(DAT_01176ce0);
    FUN_00b88360(kIter, 3);
    kIter->FUN_008866f0(DAT_01176b8c);
    kIter->FUN_00886650(DAT_011769ec);
    DAT_01176848 = 0x10024;
    DAT_01176688 = 0x416;

    kIter.Assign(DAT_01176ce4);
    FUN_00b88360(kIter, 0x13);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_01176a00);
    DAT_0117684c = 0x1000a;
    DAT_0117668c = 0x416;

    kIter.Assign(DAT_01176ce8);
    FUN_00b88360(kIter, 0x13);
    kIter->FUN_008866f0(DAT_01176b88);
    kIter->FUN_00886650(DAT_01176a04);
    DAT_01176850 = 0x1000a;
    DAT_01176690 = 0x496;

    kIter.Assign(DAT_01176cec);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_01176a14);
    DAT_01176854 = 0x10002;
    DAT_01176694 = 0x436;

    kIter.Assign(DAT_01176cf0);
    FUN_00b88360(kIter, 0x43);
    kIter->FUN_008866f0(DAT_01176b8c);
    kIter->FUN_00886650(DAT_01176a14);
    DAT_01176858 = 0x10024;
    DAT_01176698 = 0x436;

    kIter.Assign(DAT_01176cf4);
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a18);
    DAT_0117685c = 0x14002;
    DAT_0117669c = 0x412;

    kIter.Assign(DAT_01176cf8);
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176b98);
    kIter->FUN_00886650(DAT_01176a18);
    DAT_01176860 = 0x14024;
    DAT_011766a0 = 0x412;

    kIter.Assign(DAT_01176cfc);
    FUN_00b88360(kIter, 0x3f);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a20);
    DAT_01176864 = 0x14002;
    DAT_011766a4 = 0x41e;

    kIter.Assign(DAT_01176d00);
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a28);
    DAT_01176868 = 0x14002;
    DAT_011766a8 = 0x416;

    kIter.Assign(DAT_01176d04);
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176b94);
    kIter->FUN_00886650(DAT_01176a2c);
    DAT_0117686c = 0x14002;
    DAT_011766ac = 0x496;

    kIter.Assign(DAT_01176d08);
    FUN_00b88360(kIter, 0x3f);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a38);
    DAT_01176870 = 0x14002;
    DAT_011766b0 = 0x416;

    kIter.Assign(DAT_01176d0c);
    FUN_00b88360(kIter, 0x7f);
    kIter->FUN_008866f0(DAT_01176b98);
    kIter->FUN_00886650(DAT_01176a38);
    DAT_01176874 = 0x14024;
    DAT_011766b4 = 0x416;

    kIter.Assign(DAT_01176d10);
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a40);
    DAT_01176878 = 0x14002;
    DAT_011766b8 = 0x432;

    kIter.Assign(DAT_01176d14);
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176b98);
    kIter->FUN_00886650(DAT_01176a40);
    DAT_0117687c = 0x14024;
    DAT_011766bc = 0x432;

    kIter.Assign(DAT_01176d18);
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a18);
    DAT_01176880 = 0x14002;
    DAT_011766c0 = 0x412;

    kIter.Assign(DAT_01176d1c);
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176ba4);
    kIter->FUN_00886650(DAT_01176a18);
    DAT_01176884 = 0x14024;
    DAT_011766c4 = 0x412;

    kIter.Assign(DAT_01176d20);
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a28);
    DAT_01176888 = 0x14002;
    DAT_011766c8 = 0x416;

    kIter.Assign(DAT_01176d24);
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176ba0);
    kIter->FUN_00886650(DAT_01176a2c);
    DAT_0117688c = 0x14002;
    DAT_011766cc = 0x496;

    kIter.Assign(DAT_01176d28);
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a40);
    DAT_01176890 = 0x14002;
    DAT_011766d0 = 0x432;

    kIter.Assign(DAT_01176d2c);
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176ba4);
    kIter->FUN_00886650(DAT_01176a40);
    DAT_01176894 = 0x14024;
    DAT_011766d4 = 0x432;

    kIter.Assign(DAT_01176d30);
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a1c);
    DAT_01176898 = 0x14002;
    DAT_011766d8 = 0x416;

    kIter.Assign(DAT_01176d34);
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176b98);
    kIter->FUN_00886650(DAT_01176a1c);
    DAT_0117689c = 0x14024;
    DAT_011766dc = 0x416;

    kIter.Assign(DAT_01176d38);
    FUN_00b88360(kIter, 0x3f);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a24);
    DAT_011768a0 = 0x14002;
    DAT_011766e0 = 0x41e;

    kIter.Assign(DAT_01176d3c);
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a30);
    DAT_011768a4 = 0x14002;
    DAT_011766e4 = 0x416;

    kIter.Assign(DAT_01176d40);
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176b94);
    kIter->FUN_00886650(DAT_01176a34);
    DAT_011768a8 = 0x14002;
    DAT_011766e8 = 0x496;

    kIter.Assign(DAT_01176d44);
    FUN_00b88360(kIter, 0x3f);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a3c);
    DAT_011768ac = 0x14002;
    DAT_011766ec = 0x416;

    kIter.Assign(DAT_01176d48);
    FUN_00b88360(kIter, 0x7f);
    kIter->FUN_008866f0(DAT_01176b98);
    kIter->FUN_00886650(DAT_01176a3c);
    DAT_011768b0 = 0x14024;
    DAT_011766f0 = 0x416;

    kIter.Assign(DAT_01176d4c);
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176b90);
    kIter->FUN_00886650(DAT_01176a44);
    DAT_011768b4 = 0x14002;
    DAT_011766f4 = 0x436;

    kIter = DAT_01176d50;
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176b98);
    kIter->FUN_00886650(DAT_01176a44);
    DAT_011768b8 = 0x14024;
    DAT_011766f8 = 0x436;

    kIter = DAT_01176d54;
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a1c);
    DAT_011768bc = 0x14002;
    DAT_011766fc = 0x416;

    kIter = DAT_01176d58;
    FUN_00b88360(kIter, 0xf);
    kIter->FUN_008866f0(DAT_01176ba4);
    kIter->FUN_00886650(DAT_01176a1c);
    DAT_011768c0 = 0x14024;
    DAT_01176700 = 0x416;

    kIter = DAT_01176d5c;
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a30);
    DAT_011768c4 = 0x14002;
    DAT_01176704 = 0x416;

    kIter = DAT_01176d60;
    FUN_00b88360(kIter, 0x1f);
    kIter->FUN_008866f0(DAT_01176ba0);
    kIter->FUN_00886650(DAT_01176a34);
    DAT_011768c8 = 0x14002;
    DAT_01176708 = 0x496;

    kIter = DAT_01176d64;
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176b9c);
    kIter->FUN_00886650(DAT_01176a44);
    DAT_011768cc = 0x14002;
    DAT_0117670c = 0x436;

    kIter = DAT_01176d68;
    FUN_00b88360(kIter, 0x4f);
    kIter->FUN_008866f0(DAT_01176ba4);
    kIter->FUN_00886650(DAT_01176a44);
    DAT_011768d0 = 0x14024;
    DAT_01176710 = 0x436;

    kIter = DAT_01176d74;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176ba8);
    kIter->FUN_00886650(DAT_01176a48);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768dc = 0x30082;
    DAT_0117671c = 0x110;

    kIter = DAT_01176d78;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176ba8);
    kIter->FUN_00886650(DAT_01176a4c);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768e0 = 0x30082;
    DAT_01176720 = 0x110;

    kIter = DAT_01176d7c;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176bac);
    kIter->FUN_00886650(DAT_01176a48);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768e4 = 0x30082;
    DAT_01176724 = 0x110;

    kIter = DAT_01176d80;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176bac);
    kIter->FUN_00886650(DAT_01176a4c);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768e8 = 0x30082;
    DAT_01176728 = 0x110;

    kIter = DAT_01176d84;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176bb0);
    kIter->FUN_00886650(DAT_01176a48);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768ec = 0x38024;
    DAT_0117672c = 0x110;

    kIter = DAT_01176d88;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176bb4);
    kIter->FUN_00886650(DAT_01176a48);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768f0 = 0x38024;
    DAT_01176730 = 0x110;

    kIter = DAT_01176d8c;
    FUN_00b88360(kIter, 0xb);
    kIter->textures->primary->FUN_0088f050(0);
    kIter->FUN_008866f0(DAT_01176bb8);
    kIter->FUN_00886650(DAT_01176a50);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(2, 2, 0);
    DAT_011768f4 = 0x32082;
    DAT_01176734 = 0x510;

    kIter = DAT_01176e00;
    kIter->FUN_008866f0(DAT_01176bbc);
    kIter->FUN_00886650(DAT_01176a54);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176968 = 0x8a;
    DAT_011767a8 = 0x200;

    kIter = DAT_01176e04;
    kIter->FUN_008866f0(DAT_01176bc0);
    kIter->FUN_00886650(DAT_01176a54);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_0117696c = 0x34;
    DAT_011767ac = 0x200;

    kIter = DAT_01176e08;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176bc4);
    kIter->FUN_00886650(DAT_01176a58);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176970 = 0x8a;
    DAT_011767b0 = 0x200;

    kIter = DAT_01176e0c;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176bc8);
    kIter->FUN_00886650(DAT_01176a58);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176974 = 0x34;
    DAT_011767b4 = 0x200;

    kIter = DAT_01176e10;
    kIter->FUN_008866f0(DAT_01176bcc);
    kIter->FUN_00886650(DAT_01176a54);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176978 = 0x8a;
    DAT_011767b8 = 0x200;

    kIter = DAT_01176e14;
    kIter->FUN_008866f0(DAT_01176bd0);
    kIter->FUN_00886650(DAT_01176a54);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_0117697c = 0x34;
    DAT_011767bc = 0x200;

    kIter = DAT_01176e18;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176bd4);
    kIter->FUN_00886650(DAT_01176a58);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176980 = 0x8a;
    DAT_011767c0 = 0x200;

    kIter = DAT_01176e1c;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176bd8);
    kIter->FUN_00886650(DAT_01176a58);
    kIter->SetState(0xa8, 3, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176984 = 0x34;
    DAT_011767c4 = 0x200;

    kIter = DAT_01176d90;
    FUN_00b88360(kIter, 5);
    kIter->textures->secondary->FUN_0088f050(0);
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        kIter->textures->secondary->FUN_0088f0b0(0);
    kIter->FUN_008866f0(DAT_01176bdc);
    kIter->FUN_00886650(DAT_01176a5c);
    kIter->SetState(0xe, 0, 1);
    kIter->SetFloat(0xc3, r);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(9, 1, 0);
    kIter->SetState(0x98, 0x3f, 1);
    DAT_011768f8 = 0x10082;
    DAT_01176738 = 0x410;

    kIter = DAT_01176d94;
    FUN_00b88360(kIter, 5);
    kIter->textures->secondary->FUN_0088f050(0);
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        kIter->textures->secondary->FUN_0088f0b0(0);
    kIter->FUN_008866f0(DAT_01176be0);
    kIter->FUN_00886650(DAT_01176a5c);
    kIter->SetState(0xe, 0, 1);
    kIter->SetFloat(0xc3, r);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(9, 1, 0);
    kIter->SetState(0x98, 0x3f, 1);
    DAT_011768fc = 0x10082;
    DAT_0117673c = 0x410;

    kIter = DAT_01176d98;
    FUN_00b88360(kIter, 5);
    kIter->textures->secondary->FUN_0088f050(0);
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        kIter->textures->secondary->FUN_0088f0b0(0);
    kIter->FUN_008866f0(DAT_01176be4);
    kIter->FUN_00886650(DAT_01176a5c);
    kIter->SetState(0xe, 0, 1);
    kIter->SetFloat(0xc3, r);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(9, 1, 0);
    kIter->SetState(0x98, 0x3f, 1);
    DAT_01176900 = 0x100a4;
    DAT_01176740 = 0x410;

    kIter = DAT_01176d9c;
    FUN_00b88360(kIter, 5);
    kIter->textures->secondary->FUN_0088f050(0);
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        kIter->textures->secondary->FUN_0088f0b0(0);
    kIter->FUN_008866f0(DAT_01176be8);
    kIter->FUN_00886650(DAT_01176a5c);
    kIter->SetState(0xe, 0, 1);
    kIter->SetFloat(0xc3, r);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(9, 1, 0);
    kIter->SetState(0x98, 0x3f, 1);
    DAT_01176904 = 0x100a4;
    DAT_01176744 = 0x410;

    kIter = DAT_01176db0;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176bfc);
    kIter->FUN_00886650(DAT_01176a68);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_01176918 = 0xa;
    DAT_01176758 = 0x40;

    kIter = DAT_01176db4;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176c00);
    kIter->FUN_00886650(DAT_01176a6c);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_0117691c = 0x34;
    DAT_0117675c = 0x40;

    kIter = DAT_01176db8;
    FUN_00b88360(kIter, 1);
    kIter->FUN_008866f0(DAT_01176c04);
    kIter->FUN_00886650(DAT_01176a70);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(5, 6, 0);
    kIter->SetState(0xa8, 0xf, 1);
    kIter->SetState(0xe, 0, 1);
    DAT_01176920 = 0x140a;
    DAT_01176760 = 0x40;

    kIter = DAT_01176dbc;
    kIter->FUN_008866f0(DAT_01176c08);
    kIter->FUN_00886650(DAT_01176a74);
    kIter->SetState(7, 0, 1);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_01176924 = 2;
    DAT_01176764 = 0;

    kIter = DAT_01176dc0;
    kIter->FUN_008866f0(DAT_01176c0c);
    kIter->FUN_00886650(DAT_01176a78);
    kIter->SetState(7, 0, 1);
    kIter->SetState(0xe, 0, 1);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_01176928 = 0x24;
    DAT_01176768 = 0;

    kIter = DAT_01176d6c;
    FUN_00b88360(kIter, FUN_00b88310(1, 0, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176b78);
    kIter->FUN_00886650(DAT_01176a7c);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_011768d4 = 0x10002;
    DAT_01176714 = 0x12;

    kIter = DAT_01176d70;
    FUN_00b88360(kIter, FUN_00b88310(1, 0, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176b84);
    kIter->FUN_00886650(DAT_01176a7c);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_011768d8 = 0x10002;
    DAT_01176718 = 0x12;

    kIter = DAT_01176dd4;
    kIter->FUN_008866f0(DAT_01176c10);
    kIter->FUN_00886650(DAT_01176a80);
    DAT_0117693c = 0x80a;
    DAT_0117677c = 0;

    kIter = DAT_01176dd8;
    kIter->FUN_008866f0(DAT_01176c14);
    kIter->FUN_00886650(DAT_01176a80);
    DAT_01176940 = 0x80a;
    DAT_01176780 = 0;

    kIter = DAT_01176ddc;
    kIter->FUN_008866f0(DAT_01176c18);
    kIter->FUN_00886650(DAT_01176a80);
    DAT_01176944 = 0x834;
    DAT_01176784 = 0;

    kIter = DAT_01176de0;
    kIter->FUN_008866f0(DAT_01176c1c);
    kIter->FUN_00886650(DAT_01176a80);
    DAT_01176948 = 0x834;
    DAT_01176788 = 0;

    kIter = DAT_01176de4;
    kIter->FUN_008866f0(DAT_01176c20);
    kIter->FUN_00886650(DAT_01176a84);
    kIter->SetFloat(0xc3, r);
    kIter->SetState(0x16, 1, 1);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_0117694c = 0xb0a;
    DAT_0117678c = 0;

    kIter = DAT_01176de8;
    kIter->FUN_008866f0(DAT_01176c24);
    kIter->FUN_00886650(DAT_01176a84);
    kIter->SetFloat(0xc3, r);
    kIter->SetState(0x16, 1, 1);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_01176950 = 0xb74;
    DAT_01176790 = 0;

    kIter = DAT_01176df8;
    FUN_00b88360(kIter, FUN_00b88310(1, 1, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176c34);
    kIter->FUN_00886650(DAT_01176a90);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(5, 6, 0);
    kIter->SetState(0xab, 1, 1);
    kIter->SetState(0xe, 0, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176960 = 0;
    DAT_011767a0 = 0;

    kIter = DAT_01176dfc;
    FUN_00b88360(kIter, FUN_00b88310(1, 1, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176c38);
    kIter->FUN_00886650(DAT_01176a94);
    kIter->SetState(0xab, 1, 1);
    kIter->SetState(0x1b, 1, 1);
    kIter->FUN_00b02820(5, 6, 0);
    kIter->SetState(0xe, 0, 1);
    kIter->SetFloat(0xc3, r);
    DAT_01176964 = 0;
    DAT_011767a4 = 0;

    kIter = DAT_01176da0;
    FUN_00b88360(kIter, FUN_00b88310(1, 1, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176bec);
    kIter->FUN_00886650(DAT_01176a60);
    DAT_01176908 = 0xa;
    DAT_01176748 = 0x400;

    kIter = DAT_01176da4;
    FUN_00b88360(kIter, FUN_00b88310(1, 1, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176bf0);
    kIter->FUN_00886650(DAT_01176a60);
    DAT_0117690c = 0xa;
    DAT_0117674c = 0x400;

    kIter = DAT_01176da8;
    FUN_00b88360(kIter, FUN_00b88310(1, 1, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176bf4);
    kIter->FUN_00886650(DAT_01176a60);
    DAT_01176910 = 0x34;
    DAT_01176750 = 0x400;

    kIter = DAT_01176dac;
    FUN_00b88360(kIter, FUN_00b88310(1, 1, 0, 0, 0, 0, 0, 0));
    kIter->FUN_008866f0(DAT_01176bf8);
    kIter->FUN_00886650(DAT_01176a60);
    DAT_01176914 = 0x34;
    DAT_01176754 = 0x400;

    kIter = DAT_01176dec;
    kIter->FUN_008866f0(DAT_01176c28);
    kIter->FUN_00886650(DAT_01176a88);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_01176954 = 0xa;
    DAT_01176794 = 0;

    kIter = DAT_01176df0;
    kIter->FUN_008866f0(DAT_01176c2c);
    kIter->FUN_00886650(DAT_01176a88);
    DAT_01176958 = 0x34;
    DAT_01176798 = 0;

    kIter = DAT_01176df4;
    kIter->FUN_008866f0(DAT_01176c30);
    kIter->FUN_00886650(DAT_01176a8c);
    kIter->SetState(0x17, 8, 1);
    kIter->SetState(0xa8, 0xf, 1);
    DAT_0117695c = 2;
    DAT_0117679c = 0;

    FUN_00b88430();
}
}

// @f3 0x00b82b20 (community match, verified in this file)
namespace fo3_b82b20 {
struct GraphicsResource
{
    virtual void UnknownMethod();
    virtual void ReleaseSelf();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseSelf();
    }
};
struct GraphicsManager
{
    void FUN_008905a0(unsigned int setting, unsigned int mode, unsigned int enabled);
};
struct RefSlot
{
    GraphicsResource* m_pObject;
    RefSlot& operator=(GraphicsResource* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct GraphicsSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int device14;
    unsigned int version18;
    unsigned int GetVersion() const
    {
        return version18;
    }
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    GraphicsManager* manager30;
    unsigned int unk34, unk38, unk3c, unk40;
    RefSlot material44;
    unsigned int unk48, unk4c, unk50, unk54, unk58;
    RefSlot material5c;
    unsigned int unk60;
    unsigned int strongCount64;
    void FUN_00888d30(unsigned int device, unsigned int value);
    void FUN_00888c10();
};
struct TemporaryResource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int strongCount60;
    void FUN_0088fe30();
    void DecRefCount()
    {
        if (--strongCount60 == 0)
            FUN_0088fe30();
    }
};
struct ScopedSystem
{
    GraphicsSystem* ptr;
    ScopedSystem() : ptr(0)
    {}
    explicit ScopedSystem(GraphicsSystem* p) : ptr(p)
    {
        if (ptr)
            ++ptr->strongCount64;
    }
    ~ScopedSystem()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00888c10();
    }
    void reset(GraphicsSystem* p)
    {
        if (p != ptr)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    void resetFromGlobal(GraphicsSystem* const& p)
    {
        if (ptr != p)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
};
struct ScopedTemporary
{
    TemporaryResource* ptr;
    ScopedTemporary() : ptr(0)
    {}
    ~ScopedTemporary()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};
extern GraphicsSystem* DAT_011746b8;
extern GraphicsSystem* DAT_011746bc;
extern GraphicsResource* DAT_01173d38;
extern GraphicsResource* DAT_01173d3c;
extern GraphicsResource* DAT_011739ec;
extern int DAT_01172760, DAT_01173340, DAT_01172764, DAT_01173344;
extern "C" void __cdecl FUN_0088ff50(ScopedTemporary* out);
extern "C" void __cdecl FUN_00b62c70(TemporaryResource* res, unsigned int a, unsigned int b, unsigned int c,
                                           unsigned int d);
extern "C" GraphicsManager* __cdecl FUN_00890750();
// @fnv 0x00c00be0
// pdb: ShadowLightShader::PresetTextureEffectPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, objrun, medium
void __cdecl FUN_00b82b20()
{
    ScopedSystem systemScope;
    ScopedTemporary temporary;
    systemScope.reset(DAT_011746b8);
    if (systemScope->GetVersion() < 2)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        systemScope->FUN_00888d30(systemScope->device14, (unsigned int)temporary.ptr);
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        systemScope->FUN_00888d30(systemScope->device14, (unsigned int)temporary.ptr);
    }
    systemScope->material5c = DAT_01173d38;
    systemScope->material44 = DAT_011739ec;
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x1b, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x13, 5, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x14, 6, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0xab, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0xf, 0, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(7, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x17, 3, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0xe, 0, 1);
    DAT_01172760 = DAT_01173340 = 0;
    systemScope.resetFromGlobal(DAT_011746bc);
    if (systemScope->GetVersion() < 2)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        systemScope->FUN_00888d30(systemScope->device14, (unsigned int)temporary.ptr);
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        systemScope->FUN_00888d30(systemScope->device14, (unsigned int)temporary.ptr);
    }
    systemScope->material5c = DAT_01173d3c;
    systemScope->material44 = DAT_011739ec;
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x1b, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x13, 5, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x14, 6, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0xab, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0xf, 0, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(7, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0x17, 3, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00890750();
    systemScope->manager30->FUN_008905a0(0xe, 0, 1);
    DAT_01172764 = DAT_01173344 = 0;
}

}

// @f3 0x00b83ea0 (community match, verified in this file)
#include <windows.h>
namespace fo3_b83ea0 {

class NiD3DShaderConstantMap;
struct RefObject226 {
    virtual ~RefObject226();
    virtual void Release();
    unsigned int refs;
    void IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&refs)); }
    void DecRefCount() { if (InterlockedDecrement(reinterpret_cast<volatile long*>(&refs)) == 0) Release(); }
};
struct ShaderPointer226 {
    NiD3DShaderConstantMap* m_pObject;
    ~ShaderPointer226();
    ShaderPointer226& operator=(NiD3DShaderConstantMap* object) {
        if (m_pObject != object) {
            if (m_pObject) reinterpret_cast<RefObject226*>(m_pObject)->DecRefCount();
            m_pObject = object;
            if (m_pObject) reinterpret_cast<RefObject226*>(m_pObject)->IncRefCount();
        }
        return *this;
    }
};

// VC2005 compatibility: namespace-local primary for existing specialization.
template <class T> class NiPointer;
class D3DRenderStateGroup
{
  public:
    void FUN_008905a0(unsigned int state, unsigned int value, bool save);
};

D3DRenderStateGroup* FUN_00890750();

class NiD3DPass
{
  public:
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
    D3DRenderStateGroup* m_spRenderStateGroup;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    ShaderPointer226 m_spSecondShaderConstantMap;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    ShaderPointer226 m_spFirstShaderConstantMap;
    int unk60;
    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            FUN_00888c10();
    }
    void FUN_00888c10();

    D3DRenderStateGroup* GetRenderStateGroup()
    {
        if (!m_spRenderStateGroup)
            m_spRenderStateGroup = FUN_00890750();
        return m_spRenderStateGroup;
    }
};

template <> class NiPointer<NiD3DPass>
{
  public:
    NiD3DPass* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    NiPointer(NiD3DPass* object) : m_pObject(object)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiD3DPass* operator->() const
    {
        return m_pObject;
    }
    operator NiD3DPass*() const
    {
        return m_pObject;
    }
    NiPointer& operator=(const NiPointer& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

class StageReturn
{
  public:
    int unk00;
    void ReturnToPool();
};

class DummyStage
{
  public:
    StageReturn* m_pObject;
    DummyStage() : m_pObject(0)
    {}
    __forceinline ~DummyStage()
    {
        if (m_pObject)
        {
            m_pObject->ReturnToPool();
        }
    }
};

extern NiPointer<NiD3DPass> DAT_01174528;
extern NiPointer<NiD3DPass> DAT_0117452c;
extern NiPointer<NiD3DPass> DAT_01174530;

extern NiD3DShaderConstantMap* DAT_01173d2c;
extern NiD3DShaderConstantMap* DAT_01173d30;
extern NiD3DShaderConstantMap* DAT_01173d34;

extern NiD3DShaderConstantMap* DAT_011739e4;
extern NiD3DShaderConstantMap* DAT_011739e8;

extern unsigned int DAT_011731b0;
extern unsigned int DAT_011731b4;
extern unsigned int DAT_011731b8;

extern unsigned int DAT_011725d0;
extern unsigned int DAT_011725d4;
extern unsigned int DAT_011725d8;

// @fnv 0x00c01f60
// pdb: ShadowLightShader::PresetLocalMapPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, objrun, medium
void FUN_00b83ea0()
{
    NiPointer<NiD3DPass> spRenderPass;
    DummyStage spStage;

    spRenderPass = DAT_01174528;
    spRenderPass->m_spFirstShaderConstantMap = DAT_01173d2c;
    spRenderPass->m_spSecondShaderConstantMap = DAT_011739e4;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 4, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 1, true);
    DAT_011731b0 = 0x4000;
    DAT_011725d0 = 0;

    spRenderPass = DAT_0117452c;
    spRenderPass->m_spFirstShaderConstantMap = DAT_01173d30;
    spRenderPass->m_spSecondShaderConstantMap = DAT_011739e4;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 4, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 1, true);
    DAT_011731b4 = 0x8800;
    DAT_011725d4 = 0;

    spRenderPass = DAT_01174530;
    spRenderPass->m_spFirstShaderConstantMap = DAT_01173d34;
    spRenderPass->m_spSecondShaderConstantMap = DAT_011739e8;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 8, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 1, true);
    DAT_011731b8 = 0;
    DAT_011725d8 = 0;
}
}

// @f3 0x00b9f3b0 (community match, verified in this file)
extern const unsigned long DAT_00ea4638[8][256];
namespace f3m_00b9f3b0 {
namespace crc1408 {
// pdb: crc32_big | crc32.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: crc32_little)
static __declspec(noinline) unsigned long FUN_00b9f3b0(unsigned long crc,const unsigned char* buf,unsigned len){
unsigned int c;const unsigned int* buf4;
c=(unsigned int)crc;c=~c;
while(len && ((int)buf&3)){c=DAT_00ea4638[0][(c ^ *buf++)&0xff]^(c>>8);len--;}
buf4=(const unsigned int*)buf;
while(len>=32){
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
len-=32;
}
while(len>=4){c ^= *buf4++; c = DAT_00ea4638[3][c & 0xff] ^ DAT_00ea4638[2][(c >> 8) & 0xff] ^ DAT_00ea4638[1][(c >> 16) & 0xff] ^ DAT_00ea4638[0][c >> 24];
len-=4;}
buf=(const unsigned char*)buf4;
if(len)do{c=DAT_00ea4638[0][(c ^ *buf++)&0xff]^(c>>8);}while(--len);
c=~c;return (unsigned long)c;
}
volatile unsigned long inputCrc;const unsigned char* volatile inputBuffer;volatile unsigned inputLength;volatile unsigned long outputCrc;
void Emit(){outputCrc=FUN_00b9f3b0(inputCrc,inputBuffer,inputLength);}
}
}   // namespace f3m_00b9f3b0

// @f3 0x00b9e8c0 (community match, verified in this file)
namespace f3m_00b9e8c0 {
extern "C" void __cdecl FUN_00c064b8(unsigned int size);
// pdb: zcfree | zutil.obj | tesv_win, objrun_open, low
void __cdecl FUN_00b9e8c0(void* ctx, unsigned int size) {
    FUN_00c064b8(size);
}
}   // namespace f3m_00b9e8c0

// @f3 0x00b9e8a0 (community match, verified in this file)
namespace f3m_00b9e8a0 {
extern "C" void* __cdecl FUN_00c063f5(unsigned int bytes);
// pdb: zcalloc | zutil.obj | tesv_win, caller_sim, low
void* __cdecl FUN_00b9e8a0(void* ctx, unsigned int count, unsigned int size) {
    return FUN_00c063f5(count * size);
}
}   // namespace f3m_00b9e8a0

// @f3 0x00b9f650 (community match, verified in this file)
namespace f3m_00b9f650 {
// pdb: crc32 | crc32.obj | fnv360_0822_retail, call_gap, low
// pdb params: crc, buf, len
unsigned int __cdecl FUN_00b9f650(unsigned int crc,const unsigned char* buf,unsigned int len)
{
    if (buf == 0) return 0;
    return f3m_00b9f3b0::crc1408::FUN_00b9f3b0(crc, buf, len);
}
}   // namespace f3m_00b9f650

// @f3 0x00b9bd50 (community match, verified in this file)
namespace f3m_00b9bd50 {
int __cdecl inflateInit2_(z_streamp strm,int windowBits,const char* version,int stream_size);
// pdb: inflateInit_ | inflate.obj | fnv360_0822_retail, call_gap, low
// pdb params: strm, version, stream_size
int __cdecl FUN_00b9bd50(z_streamp strm,const char* version,int stream_size)
{
    return inflateInit2_(strm,15,version,stream_size);
}
}   // namespace f3m_00b9bd50

// @f3 0x00b9e870 (community match, verified in this file)
namespace f3m_00b9e870 {
struct F650Obj;
int __cdecl deflateInit2_(F650Obj* obj,int a2,int a3,int a4,int a5,int a6,char* a7,int a8);
// pdb: deflateInit_ | deflate.obj | fnv360_0822_retail, call_gap, low
// pdb params: strm, level, version, stream_size
int __cdecl FUN_00b9e870(z_streamp strm,int level,char* version,int stream_size)
{
    return deflateInit2_((F650Obj*)strm,level,8,15,8,0,version,stream_size);
}
}   // namespace f3m_00b9e870

// @f3 0x00b9f670 (community match, verified in this file)
namespace f3m_00b9f670 {
// pdb: init_block | trees.obj | tesv_win, call_seq, medium
static __declspec(noinline) void FUN_00b9f670(int unused0, int unused1, unsigned char* s)
{
    unsigned short* p;
    int n;
    // dyn_ltree: 286 literal/length entries, 4 bytes each, frequency in the first word
    for (n = 0; n < 0x11e; n++)
    {
        p = (unsigned short*)(s + 0x8c + n * 4);
        *p = 0;
    }
    // dyn_dtree: 30 distance entries
    for (n = 0; n < 0x1e; n++)
    {
        p = (unsigned short*)(s + 0x980 + n * 4);
        *p = 0;
    }
    // bl_tree: 19 bit-length entries
    for (n = 0; n < 0x13; n++)
    {
        p = (unsigned short*)(s + 0xa74 + n * 4);
        *p = 0;
    }
    // opt_len, static_len, last_lit and matches are cleared; dyn_ltree[END_BLOCK] starts at 1
    *(unsigned int*)(s + 0x16a4) = 0;
    *(unsigned int*)(s + 0x16a0) = 0;
    *(unsigned int*)(s + 0x16a8) = 0;
    *(unsigned int*)(s + 0x1698) = 0;
    *(unsigned short*)(s + 0x48c) = 1;
}

volatile int g_in_00b9f670;
volatile unsigned char g_obj_00b9f670[0x1000];
void caller_of_FUN_00b9f670()
{
    FUN_00b9f670(g_in_00b9f670, g_in_00b9f670, (unsigned char*)g_obj_00b9f670);
}
}   // namespace f3m_00b9f670

// @f3 0x00b9e5c0 (community match, verified in this file)
namespace f3m_00b9e5c0 {
unsigned int __cdecl FUN_00b9f270(unsigned int,const unsigned char*,unsigned int);
unsigned int __cdecl FUN_00b9f650(unsigned int,const unsigned char*,unsigned int);
void __cdecl _tr_init(DeflateState* s);
void __cdecl FUN_00b9d7d0(void);

// pdb: deflateReset | deflate.obj | fnv360_0822_retail, call_gap + skyrim(call_seq), high
int __cdecl deflateReset(DeflateStream* strm)
{
    DeflateState* s;
    if (strm == 0 || strm->state == 0 || strm->allocator == 0 || strm->deallocator == 0)
        return -2;
    s = strm->state;
    strm->total_in = strm->total_out = 0;
    strm->msg = 0;
    strm->data_type = 2;
    s->pending_out = s->pending_buf;
    s->pending = 0;
    if (s->wrap < 0) s->wrap = -s->wrap;
    s->status = s->wrap ? 42 : 113;
    strm->adler = (s->wrap == 2) ? FUN_00b9f650(0u, (const unsigned char*)0, 0u)
                                 : FUN_00b9f270(0u, (const unsigned char*)0, 0u);
    s->last_flush = 0;
    _tr_init(s);
    FUN_00b9d7d0();
    return 0;
}
}   // namespace f3m_00b9e5c0

// @f3 0x00b85090 (community match, verified in this file)
extern void* DAT_00ea3378[];
extern void* DAT_00ea3374[];
namespace f3m_00b85090 {
void** Allocate(unsigned int count);
struct EffectBase {
    void** methods;
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54;
    void FUN_00b22930();
    EffectBase() { FUN_00b22930(); methods=DAT_00ea3378; }
    ~EffectBase();
};
struct EffectArray {
    void** methods;
    void** data;
    unsigned short capacity, size, effectiveSize, growBy;
    EffectArray(unsigned int maxSize = 0, unsigned int grow = 1) {
        capacity = (unsigned short)maxSize;
        growBy = (unsigned short)grow;
        size = 0;
        effectiveSize = 0;
        if (capacity > 0)
            data = Allocate(capacity);
        else
            data = 0;
        methods = DAT_00ea3374;
    }
    ~EffectArray();
};
struct FUN_00b85090 : EffectBase {
    EffectArray effects;
    FUN_00b85090();
};
FUN_00b85090::FUN_00b85090()
{
}
}   // namespace f3m_00b85090

// @f3 0x00b9f9d0 (community match, verified in this file)
namespace f3m_00b9f9d0 {
namespace f3m_00b9f9d0 {
typedef unsigned char Byte;
typedef unsigned short ush;
typedef unsigned long ulg;
typedef unsigned int uInt;
typedef ush Pos;
typedef unsigned IPos;

typedef struct ct_data_s
{
    union { ush freq; ush code; } fc;
    union { ush dad; ush len; } dl;
} ct_data;


typedef struct internal_state
{
    void* strm;
    int status;
    Byte* pending_buf;
    ulg pending_buf_size;
    Byte* pending_out;
    int pending;
    int wrap;
    Byte method;
    int last_flush;
    uInt w_size;
    uInt w_bits;
    uInt w_mask;
    Byte* window;
    ulg window_size;
    Pos* prev;
    Pos* head;
    uInt ins_h;
    uInt hash_size;
    uInt hash_bits;
    uInt hash_mask;
    uInt hash_shift;
    long block_start;
    uInt match_length;
    IPos prev_match;
    int match_available;
    uInt strstart;
    uInt match_start;
    uInt lookahead;
    uInt prev_length;
    uInt max_chain_length;
    uInt max_lazy_match;
    int level;
    int strategy;
    uInt good_match;
    int nice_match;
    ct_data dyn_ltree[2 * 286 + 1];
    ct_data dyn_dtree[2 * 30 + 1];
    ct_data bl_tree[2 * 19 + 1];
} deflate_state;
}

// pdb: scan_tree | trees.obj | fnv360_0721_beta, objrun, medium
static __declspec(noinline) void FUN_00b9f9d0(f3m_00b9f9d0::deflate_state* s, f3m_00b9f9d0::ct_data* tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].dl.len;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0) max_count = 138, min_count = 3;
    tree[max_code + 1].dl.len = (f3m_00b9f9d0::ush)0xffff;

    for (n = 0; n <= max_code; n++)
    {
        curlen = nextlen;
        nextlen = tree[n + 1].dl.len;
        if (++count < max_count && curlen == nextlen)
        {
            continue;
        }
        else if (count < min_count)
        {
            s->bl_tree[curlen].fc.freq += count;
        }
        else if (curlen != 0)
        {
            if (curlen != prevlen) s->bl_tree[curlen].fc.freq++;
            s->bl_tree[16].fc.freq++;
        }
        else if (count <= 10)
        {
            s->bl_tree[17].fc.freq++;
        }
        else
        {
            s->bl_tree[18].fc.freq++;
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0)
        {
            max_count = 138, min_count = 3;
        }
        else if (curlen == nextlen)
        {
            max_count = 6, min_count = 3;
        }
        else
        {
            max_count = 7, min_count = 4;
        }
    }
}

f3m_00b9f9d0::deflate_state* volatile g_s_00b9f9d0;
f3m_00b9f9d0::ct_data* volatile g_tree_00b9f9d0;
volatile int g_max_00b9f9d0;
void caller_of_FUN_00b9f9d0()
{
    FUN_00b9f9d0(g_s_00b9f9d0, g_tree_00b9f9d0, g_max_00b9f9d0);
}
}   // namespace f3m_00b9f9d0

// @f3 0x00b9bd70 (community match, verified in this file)
#include <string.h>
namespace f3m_00b9bd70 {

namespace f3m_00b9bd70 {
typedef void* (*alloc_func)(void* opaque, unsigned items, unsigned size);
typedef void (*free_func)(void* opaque, void* address);

struct inflate_state
{
    int mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned long check;
    unsigned long total;
    unsigned wbits;
    unsigned wsize;
    unsigned whave;
    unsigned write;
    unsigned char* window;
};

struct z_stream
{
    unsigned char* next_in;
    unsigned avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned avail_out;
    unsigned long total_out;
    char* msg;
    inflate_state* state;
    alloc_func zalloc;
    free_func zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};
}

// pdb: updatewindow | inflate.obj | fnv360_0822_debug, call_seq + bridge(call_gap|call_gap) + skyrim(call_dedup), high
static __declspec(noinline) int updatewindow(f3m_00b9bd70::z_stream* strm, unsigned out)
{
    f3m_00b9bd70::inflate_state* state;
    unsigned copy, dist;

    state = strm->state;

    if (state->window == 0)
    {
        state->window = (unsigned char*)(*strm->zalloc)(strm->opaque, 1U << state->wbits, sizeof(unsigned char));
        if (state->window == 0) return 1;
    }

    if (state->wsize == 0)
    {
        state->wsize = 1U << state->wbits;
        state->write = 0;
        state->whave = 0;
    }

    copy = out - strm->avail_out;
    if (copy >= state->wsize)
    {
        memcpy(state->window, strm->next_out - state->wsize, state->wsize);
        state->write = 0;
        state->whave = state->wsize;
    }
    else
    {
        dist = state->wsize - state->write;
        if (dist > copy) dist = copy;
        memcpy(state->window + state->write, strm->next_out - copy, dist);
        copy -= dist;
        if (copy)
        {
            memcpy(state->window, strm->next_out - copy, copy);
            state->write = copy;
            state->whave = state->wsize;
        }
        else
        {
            state->write += dist;
            if (state->write == state->wsize) state->write = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}

f3m_00b9bd70::z_stream* volatile g_strm_00b9bd70;
volatile unsigned g_out_00b9bd70;
volatile int g_ret_00b9bd70;
void caller_of_FUN_00b9bd70()
{
    g_ret_00b9bd70 = updatewindow(g_strm_00b9bd70, g_out_00b9bd70);
}
}   // namespace f3m_00b9bd70

// @f3 0x00b87e10 (community match, verified in this file)
namespace f3m_00b87e10 {

struct C1 { void FUN_00b223d0(int size); };
struct C2 { void FUN_005b3880(int a, int* value); };

struct Obj00b87e10 {
    void FUN_00b87e10(int a);
};

// pdb: ImageSpaceEffectBloom::BorrowTextures | ImageSpaceEffectBloom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pParam
void Obj00b87e10::FUN_00b87e10(int a) {
    C1* local = (C1*)((char*)this + 0x5c);
    local->FUN_00b223d0(0x19);
    C2* p2 = (C2*)((char*)this + 0x28);
    p2->FUN_005b3880(2, (int*)&local);
    local = (C1*)((char*)this + 0x6c);
    local->FUN_00b223d0(0x19);
    p2->FUN_005b3880(3, (int*)&local);
}
}   // namespace f3m_00b87e10

// @f3 0x00b9bc10 (community match, verified in this file)
namespace f3m_00b9bc10 {

// pdb: inflateReset | inflate.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
int __cdecl inflateReset(void* arg0) {
    void* edx = arg0;
    void* eax = 0;
    if (edx != 0) {
        eax = *(void**)((char*)edx + 0x1c);
        if (eax != 0) {
            *(unsigned int*)((char*)eax + 0x18) = 0;
            *(unsigned int*)((char*)edx + 0x14) = 0;
            *(unsigned int*)((char*)edx + 0x08) = 0;
            *(unsigned int*)((char*)edx + 0x18) = 0;
            *(unsigned int*)((char*)eax + 0x00) = 0;
            *(unsigned int*)((char*)eax + 0x04) = 0;
            *(unsigned int*)((char*)eax + 0x0c) = 0;
            *(unsigned int*)((char*)eax + 0x20) = 0;
            *(unsigned int*)((char*)eax + 0x24) = 0;
            *(unsigned int*)((char*)eax + 0x30) = 0;
            *(unsigned int*)((char*)eax + 0x34) = 0;
            void* p = (char*)eax + 0x528;
            *(void**)((char*)eax + 0x64) = p;
            *(void**)((char*)eax + 0x48) = p;
            *(void**)((char*)eax + 0x44) = p;
            return 0;
        }
    }
    return -2;
}
}   // namespace f3m_00b9bc10

// @f3 0x00b85a10 (community match, verified in this file)
struct FeatureState {
    unsigned int unk00;
    unsigned int unk04;
    bool enabled;
};
extern FeatureState* DAT_0117495c[];
extern FeatureState* DAT_011749b4[];
extern unsigned int DAT_01172a00[];
extern unsigned int DAT_01171e20[];
// pdb: ShadowLightShader::EnableConstantsForPass_1x | ShadowLightShader_Update_1x.obj | fnv360_0822_retail, call_gap, medium
// pdb params: auiPassEnum
void __cdecl FUN_00b85a10(unsigned int index)
{
    unsigned int i = 2;
    FeatureState** state = DAT_0117495c;
    unsigned int remaining = 11;
    do {
        if (state[-1])
            state[-1]->enabled = (DAT_01172a00[index] & (1u << (i-1))) != 0;
        if (state[0])
            state[0]->enabled = (DAT_01172a00[index] & (1u << i)) != 0;
        i += 2;
        state += 2;
    } while (--remaining);
    i = 2;
    state = DAT_011749b4;
    remaining = 11;
    do {
        if (state[-1])
            state[-1]->enabled = (DAT_01171e20[index] & (1u << (i-1))) != 0;
        if (state[0])
            state[0]->enabled = (DAT_01171e20[index] & (1u << i)) != 0;
        i += 2;
        state += 2;
    } while (--remaining);
}

// @f3 0x00b9d7d0 (community match, verified in this file)
namespace f3m_00b9d7d0 {
struct DeflateStateEx : DeflateState
{
    unsigned int good_match;
    int nice_match;
};

// pdb: lm_init | deflate.obj | tesv_win, call_gap, low
static __declspec(noinline) void FUN_00b9d7d0(int a, int b, int c, DeflateStateEx* s)
{
    s->window_size = s->w_size * 2;
    ((*(s->head - 1 + (s->hash_size)))) = 0;
    memset(s->head, 0, s->hash_size * 2 - 2);
    s->max_lazy_match = ((DAT_00ea43e0)[s->level]).max_lazy;
    s->good_match = DAT_00ea43e0[s->level].good_length;
    s->nice_match = ((*(DAT_00ea43e0 + (s->level)))).nice_length;
    unsigned int cnt;
    cnt = (*(s->level + DAT_00ea43e0)).max_chain;
    s->max_chain_length = cnt;
    s->strstart = 0;
    s->block_start = 0;
    s->match_length = s->prev_length = 2;
    s->lookahead = 0;
    s->match_available = 0;
    s->ins_h = 0;
}

volatile int g_a;
volatile int g_b;
volatile int g_c;
DeflateStateEx* volatile g_s;

void __cdecl caller_of_FUN_00b9d7d0()
{
    FUN_00b9d7d0(g_a, g_b, g_c, g_s);
}

}   // namespace f3m_00b9d7d0

// @f3 0x00b9d710 (community match, verified in this file)
namespace f3m_00b9d710 {
namespace f3m_00b9d710 {
struct Inner_b9d710 {
    int unk00;
    int magic04;
    void* p08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void* p30;
    int unk34;
    void* p38;
    void* p3c;
};

struct State_b9d710 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    Inner_b9d710* inner1c;
    int unk20;
    void (__cdecl* free24)(void* ctx, void* ptr);
    void* ctx28;
};
}

// pdb: deflateEnd | deflate.obj | fnv360_0721_beta, call_seq + skyrim(call_seq), high
int __cdecl deflateEnd(f3m_00b9d710::State_b9d710* s)
{
    if (!s || !s->inner1c)
        return -2;
    int magic = s->inner1c->magic04;
    if (magic != 0x2a && magic != 0x71 && magic != 0x29a)
        return -2;
    if (s->inner1c->p08)
        s->free24(s->ctx28, s->inner1c->p08);
    if (s->inner1c->p3c)
        s->free24(s->ctx28, s->inner1c->p3c);
    if (s->inner1c->p38)
        s->free24(s->ctx28, s->inner1c->p38);
    if (s->inner1c->p30)
        s->free24(s->ctx28, s->inner1c->p30);
    s->free24(s->ctx28, s->inner1c);
    s->inner1c = 0;
    return magic == 0x71 ? -3 : 0;
}
}   // namespace f3m_00b9d710

// @f3 0x00b9bc60 (community match, verified in this file)
namespace f3m_00b9bc60 {
namespace c4_00b9bc60 {

typedef void* (__cdecl* alloc_func)(void* opaque, unsigned int items, unsigned int size);
typedef void (__cdecl* free_func)(void* opaque, void* address);

struct code
{
    unsigned char op;
    unsigned char bits;
    unsigned short val;
};

struct inflate_state
{
    int mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned long check;
    unsigned long total;
    unsigned int wbits;
    unsigned int wsize;
    unsigned int whave;
    unsigned int write;
    unsigned char* window;
    unsigned long hold;
    unsigned int bits;
    unsigned int length;
    unsigned int offset;
    unsigned int extra;
    const code* lencode;
    const code* distcode;
    unsigned int lenbits;
    unsigned int distbits;
    unsigned int ncode;
    unsigned int nlen;
    unsigned int ndist;
    unsigned int have;
    code* next;
    unsigned short lens[320];
    unsigned short work[288];
    code codes[1440];
};

struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char* msg;
    inflate_state* state;
    alloc_func zalloc;
    free_func zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

void* __cdecl FUN_00b9e8a0(void* opaque, unsigned int items, unsigned int size);
void __cdecl FUN_00b9e8c0(void* opaque, void* address);
int __cdecl inflateReset(z_stream* strm);

// pdb: inflateInit2_ | inflate.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
int __cdecl inflateInit2_(z_stream* strm, int windowBits, const char* version, int stream_size)
{
    inflate_state* state;

    if (version == 0 || version[0] != '1' || stream_size != (int)sizeof(z_stream))
        return -6;
    if (strm == 0)
        return -2;
    strm->msg = 0;
    if (strm->zalloc == 0)
    {
        strm->zalloc = FUN_00b9e8a0;
        strm->opaque = 0;
    }
    if (strm->zfree == 0)
        strm->zfree = FUN_00b9e8c0;
    state = strm->state;
    if (state == 0)
    {
        state = (inflate_state*)strm->zalloc(strm->opaque, 1, sizeof(inflate_state));
        if (state == 0)
            return -4;
        strm->state = state;
        strm->reserved = 1;
    }
    else
    {
        strm->reserved = 0;
    }
    if (windowBits < 0)
    {
        state->wrap = 0;
        windowBits = -windowBits;
    }
    else
    {
        state->wrap = (windowBits >> 4) + 1;
        if (windowBits < 48)
            windowBits &= 15;
    }
    if (windowBits < 8 || windowBits > 15)
    {
        if (strm->reserved)
            strm->zfree(strm->opaque, state);
        strm->state = 0;
        return -2;
    }
    state->wbits = (unsigned int)windowBits;
    state->window = 0;
    return inflateReset(strm);
}

}
}   // namespace f3m_00b9bc60

// @f3 0x00b84e60 (community match, verified in this file)
namespace f3m_00b84e60 {
namespace f3m_00b84e60 {
struct NiTexture4e60;
NiTexture4e60* __cdecl FUN_00ada4a0();

struct ImageSpaceTexture4e60 {
    int unk00, unk04, unk08, unk0c;
    void FUN_00b223d0(unsigned int type);
    void FUN_00b22530();
    void FUN_00b22380(NiTexture4e60* texture);
};

template <class T> struct NiTPrimitiveArray4e60 {
    void* m_vptr;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_005b3880(unsigned int i, const T& val);
};

struct Params4e60 { unsigned char unk00, unk01, unk02, enabled; };

struct Effect4e60 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    NiTPrimitiveArray4e60<ImageSpaceTexture4e60*> textures;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    Params4e60* params;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
    ImageSpaceTexture4e60 tex7c;
    ImageSpaceTexture4e60 tex8c;
    ImageSpaceTexture4e60 tex9c;
    ImageSpaceTexture4e60 texac;
    void FUN_00b84e60(void* unused);
};

// pdb: ImageSpaceEffectDepthOfField::BorrowTextures | ImageSpaceEffectDepthOfField.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: pParam
void Effect4e60::FUN_00b84e60(void* unused)
{
    ImageSpaceTexture4e60* tex = &tex8c;
    tex8c.FUN_00b223d0(0x24);
    textures.FUN_005b3880(2, tex);
    tex = &tex9c;
    tex9c.FUN_00b223d0(0x25);
    textures.FUN_005b3880(3, tex);
    if (params->enabled) {
        tex = &tex7c;
        textures.FUN_005b3880(5, tex);
    } else {
        tex7c.FUN_00b22530();
        tex = 0;
        textures.FUN_005b3880(5, tex);
    }
    tex = &texac;
    texac.FUN_00b22380(FUN_00ada4a0());
    textures.FUN_005b3880(4, tex);
}
}
}   // namespace f3m_00b84e60

// @f3 0x00b84fc0 (community match, verified in this file)
namespace f3m_00b84fc0 {
namespace Resize402 {
extern "C" void* __cdecl FUN_0089e810(unsigned int);
extern "C" void __cdecl FUN_0089e890(void*);
struct Array {
 int unk00; unsigned char* data;
 unsigned short capacity,size,count;
 void FUN_00b84fc0(unsigned int);
};
// pdb: NiTArray<bool,NiTMallocInterface<bool> >::SetSize | ImageSpaceEffectDepthOfField.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: uiMaxSize
void Array::FUN_00b84fc0(unsigned int desired) {
 if(desired==capacity) return;
 if(desired<size) {
  for(unsigned short i=static_cast<unsigned short>(desired);i<size;++i) {
   if(data[i]) { data[i]=0; --count; }
  }
  size=static_cast<unsigned short>(desired);
 }
 unsigned char* old=data;
 capacity=static_cast<unsigned short>(desired);
 if(desired>0u) {
  unsigned int cap=capacity;
  data=static_cast<unsigned char*>(FUN_0089e810(cap));
  for(unsigned short i=0;i<size;++i) data[i]=old[i];
  for(unsigned short i=size;i<capacity;++i) data[i]=0;
 } else data=0;
 FUN_0089e890(old);
}
}
}   // namespace f3m_00b84fc0

// @f3 0x00b9f6e0 (community match, verified in this file)
namespace f3m_00b9f6e0 {
namespace ns_b9f6e0 {
struct ct_data
{
    unsigned short Freq;
    unsigned short Dad;
};
struct deflate_state
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int heap[573];
    int heap_len;
    int heap_max;
    unsigned char depth[573];
};
// pdb: pqdownheap | trees.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00b9f6e0(deflate_state* s, ct_data* tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;
    while (j <= s->heap_len)
    {
        if (j < s->heap_len &&
            (tree[s->heap[j + 1]].Freq < tree[s->heap[j]].Freq ||
             (tree[s->heap[j + 1]].Freq == tree[s->heap[j]].Freq && s->depth[s->heap[j + 1]] <= s->depth[s->heap[j]])))
        {
            j++;
        }
        if (tree[v].Freq < tree[s->heap[j]].Freq ||
            (tree[v].Freq == tree[s->heap[j]].Freq && s->depth[v] <= s->depth[s->heap[j]]))
            break;
        s->heap[k] = s->heap[j];
        k = j;
        j <<= 1;
    }
    s->heap[k] = v;
}
volatile int g_in_b9f6e0;
void caller_of_FUN_00b9f6e0()
{
    FUN_00b9f6e0((deflate_state*)g_in_b9f6e0, (ct_data*)g_in_b9f6e0, g_in_b9f6e0);
}
}
}   // namespace f3m_00b9f6e0

// @f3 0x00b8e5a0 (community match, verified in this file)
namespace f3m_00b8e5a0 {
namespace f3m_00b8e5a0 {
struct Obj {
    int FUN_0083c190(int a);
    int FUN_00b8e5a0(int a);
};
// pdb: TallGrassTriStrips::CreateClone | TallGrassTriStrips.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: arCloneData
int Obj::FUN_00b8e5a0(int a)
{
    return FUN_0083c190(a);
}
}
}   // namespace f3m_00b8e5a0
