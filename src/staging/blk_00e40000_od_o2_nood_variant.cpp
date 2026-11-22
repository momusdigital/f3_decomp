// staging/blk_00e40000_od_o2_nood_variant.cpp: Cls, TreeDecoder (3 functions)
#include "f3_common.h"
#include "fnv_asm_helpers.h"
// src/staging/blk_00e40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct FloatLess
{
	bool operator()(const float& a, const float& b) const { return a < b; }
};

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" int _mm_movemask_ps(__m128);

static inline __m128 Dot3_e4b570(__m128 p)
{
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

// stand-in for the local object whose method is called
struct LocalObj {
    int m_unk00;
    int m_unk01;
    int m_unk02;
    int m_unk03;
    int m_unk04;
    int m_unk05;
    int m_unk06;
    int m_unk07;
    int m_unk08;
    int m_unk09;
    int m_unk10;
    int m_unk11;
    int m_unk12;
    int m_unk13;
    int m_unk14;
    int m_unk15;
    int m_unk16;
    int m_unk17;
    int m_unk18;
    int m_unk19;
    char* SetupAndProcessShape(char* buf, void* a1, int a2, int a3, int a4);
};

// @fnv 0x00e5cf00
// pdb: hkMoppEarlyExitObbVirtualMachine_queryObb | hkpMoppMachine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: code, BvToWorld, extent, radius
int __cdecl FUN_00e5cf00(void* a1, int a2, int a3, int a4)
{
    __declspec(align(16)) LocalObj obj;
    char buf;
    return obj.SetupAndProcessShape(&buf, a1, a2, a3, a4)[0] != 0;
}

struct __declspec(align(16)) Vec4E5 { float x, y, z, w; };
struct TmpE5CF40 { Vec4E5 a, b; void FUN_00e64f00(int a, int b, int c); };
// @fnv 0x00e5cf40
// pdb: hkMoppSphereVirtualMachine_querySphere | hkpMoppMachine.obj | fnv360_0822_retail, objrun, medium
// pdb params: code, sphere, primitives_out
void __cdecl FUN_00e5cf40(int a, int b, int c)
{
    TmpE5CF40 tmp;
    tmp.FUN_00e64f00(a, b, c);
}

struct __declspec(align(16)) FUN_00e5d010_Block {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    void __thiscall FUN_00dd1da0(int first,int second,int third);
};
// @fnv 0x00e5d010
// pdb: hkMoppObbVirtualMachine_queryAabb | hkpMoppMachine.obj | fnv360_0822_retail, objrun, medium
// pdb params: code, aabb, primitives_out
extern "C" void __cdecl FUN_00e5d010(int first,int second,int third)
{
    FUN_00e5d010_Block instance;
    instance.FUN_00dd1da0(first,second,third);
}

#include <math.h>
extern "C" __m128 _mm_and_ps(__m128,__m128);
extern "C" void _ReadWriteBarrier();
extern "C" void _mm_store_ss(float*,__m128);


extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C" void _ReadWriteBarrier();
static __forceinline int readPacked(const unsigned char* q) {int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}
static __forceinline int readUpper(const unsigned char* q) {return ((q[0]<<8)+q[1]<<8)+q[2];}
struct P1 { union { struct { int f0; int f4; int xyz[3]; int f14; }; int fields[6]; }; };
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);


struct V4 { union { __m128 m; float f[4]; };
 __forceinline void setAdd(const V4& a,const V4& b){m=_mm_add_ps(a.m,b.m);}
 __forceinline void setSub(const V4& a,const V4& b){m=_mm_sub_ps(a.m,b.m);}
 __forceinline void setMin(const V4& a,const V4& b){m=_mm_min_ps(a.m,b.m);}
 __forceinline void sub(const V4& a){m=_mm_sub_ps(m,a.m);}
 __forceinline void add(const V4& a){m=_mm_add_ps(m,a.m);}
 __forceinline void abs(const __m128& mask){m=_mm_and_ps(m,mask);}
 __forceinline float lengthSquared3() const {
  __m128 square=_mm_mul_ps(m,m); float r;
  _mm_store_ss(&r,_mm_add_ss(_mm_shuffle_ps(square,square,0xaa),_mm_add_ss(_mm_shuffle_ps(square,square,0x55),square)));
  return r;
 }
};
struct F8 { V4 lower, upper; };
struct BoundsRef { F8* p; F8* operator->() const { return p; } operator F8*() const { return p; } }; 
struct Vec { int* base; int count; int cap; };
extern void* FUN_00c85750();
extern void ResizeAudioStream(void* a, void* b, int c);
static const __declspec(align(16)) unsigned int AbsMask[4] = { 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff };


struct Query {
  void FUN_00e65ee0(P1*, unsigned char*);
  __forceinline int classify(P1* state, unsigned char* stream, int offset, F8* bounds) {
    float r2 = center[3] * center[3];
    V4 sum, extent, outside;
    sum.setAdd(bounds->upper,bounds->lower);
    extent.setSub(bounds->upper,bounds->lower);
    sum.sub(*(const V4*)center);
    sum.abs(*(const __m128*)AbsMask);
    outside.setMin(sum,extent);
    outside.sub(sum);
    float near2=outside.lengthSquared3();
    if(near2>r2) return 0;
    extent.add(sum);
    float far2=extent.lengthSquared3();
    if(far2<r2){FUN_00e65ee0(state,stream+offset);return 1;}
    return 2;
  }
  __forceinline int classifyLocal(P1* state, unsigned char* stream, int offset, F8* bounds) {
    float r2 = center[3] * center[3];
    V4 sum, extent, outside;
    sum.setAdd(bounds->upper,bounds->lower);
    extent.setSub(bounds->upper,bounds->lower);
    sum.sub(*(const V4*)center);
    sum.abs(*(const __m128*)AbsMask);
    outside.setMin(sum,extent);
    outside.sub(sum);
    float near2=outside.lengthSquared3();
    if(near2>r2) return 0;
    extent.add(sum);
    float far2=extent.lengthSquared3();
    if(far2<r2){FUN_00e65ee0(state,stream+offset);return 1;}
    return 2;
  }
  Vec* results; int unk24; int unk28; int unk2c;
  float center[4];
};
struct Cls {
  Vec* vec;
  int unk04; int unk08; int unk0c;
  float scale;
  int unk14; int unk18; int unk1c;
  Query query;
  __forceinline void scan(P1* cur, unsigned char* p, int& offset, F8* const bounds) {
    int code;
      code = p[offset];
      while (code >= 38 && 43 >= code) {
        if (code >= 41) {
          bounds->lower.f[code - 41] = (float)readPacked(p+offset+1) * scale;
          bounds->upper.f[code - 41] = (float)((((p[offset+4] << 8) + p[offset+5]) << 8) + p[offset+6]) * scale;
          offset += 7;
        } else {
          bounds->lower.f[code - 38] = (float)((p[offset+1] << cur->f14) + cur->fields[code - 36]) * scale;
          bounds->upper.f[code - 38] = (float)((p[offset+2] << cur->f14) + cur->fields[code - 36]) * scale;
          offset += 3;
        }
        code = p[offset];
      }

  }
  __forceinline void scanRight(P1* cur, unsigned char* p, int& offset, F8* const bounds) {
    int code;
      code = p[offset];
      while (code >= 38 && 43 >= code) {
        if (code >= 41) {
          bounds->lower.f[code - 41] = (float)readPacked(p+offset+1) * scale;
          bounds->upper.f[code - 41] = (float)readUpper(p+offset+4)*scale;
          offset += 7;
        } else {
          bounds->lower.f[code - 38] = (float)((p[offset+1] << cur->f14) + cur->fields[code - 36]) * scale;
          bounds->upper.f[code - 38] = (float)((p[offset+2] << cur->f14) + cur->fields[code - 36]) * scale;
          offset += 3;
        }
        code = p[offset];
      }

  }
  void FUN_00e5f070(P1* a1, unsigned char* p, F8* a3);
  __forceinline void interpret(P1* a1, unsigned char* p, F8* const& a3);
};

extern "C" void _ReadWriteBarrier();
__forceinline int rightPacked(const unsigned char* q){return ((q[0]<<8)+q[1]<<8)+q[2];}
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadWriteBarrier();
static __forceinline int read24(const unsigned char* q) {_ReadWriteBarrier(); int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);
struct IntegerOrigin { int x,y,z; int& operator[](int i) { return (&x)[i]; }
    int volatileAt(int i) const { return reinterpret_cast<const volatile int*>(&x)[i]; } };
struct DecodeState {
    int baseID; int property; IntegerOrigin origin; int shift;
    int& propertyAt(int i) { return (&property)[i]; }
};
struct __declspec(align(16)) BoundsPair { __m128 minimum; __m128 maximum;
    BoundsPair& operator=(const BoundsPair& b) { minimum=b.minimum; maximum=b.maximum; return *this; }
};
struct OutputArray { int* data; int size; int capacity; };
struct AllocatorContext { int unk00; int unk04; int unk08; int unk0C; void* allocator; };
void ResizeAudioStream(void*, void*, int);
struct __declspec(align(16)) PlanePacket { __m128 x,y,z,w; };
struct CullMachine {
    int unk00; int unk04; int unk08; int unk0C; int count; int unk14; int unk18; int unk1C;
    PlanePacket planes[8];
    PlanePacket absolutePlanes[8];
    void FUN_00e66600(DecodeState*, const unsigned char*);
    void FUN_00e66290(DecodeState*, const unsigned char*);
    __forceinline int classify(DecodeState* state, const unsigned char* code, const BoundsPair& bounds) {
        int allInside = 15;
        const PlanePacket* p=planes;
        const PlanePacket* q=absolutePlanes;
        __m128 center = _mm_add_ps(bounds.maximum, bounds.minimum);
        __m128 extent = _mm_sub_ps(bounds.maximum, bounds.minimum);
        for (int n=count; --n >= 0; ++p, ++q) {
            __m128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(q->x.m128_f32),_mm_shuffle_ps(extent,extent,0)),
                           _mm_mul_ps(_mm_load_ps(q->y.m128_f32),_mm_shuffle_ps(extent,extent,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(q->z.m128_f32),_mm_shuffle_ps(extent,extent,0xaa)),_mm_load_ps(q->w.m128_f32)));
            __m128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(p->x.m128_f32),_mm_shuffle_ps(center,center,0)),
                           _mm_mul_ps(_mm_load_ps(p->y.m128_f32),_mm_shuffle_ps(center,center,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(p->z.m128_f32),_mm_shuffle_ps(center,center,0xaa)),_mm_load_ps(p->w.m128_f32)));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance,radius),_mm_setzero_ps())) != 15) return 0;
            allInside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance,radius),_mm_setzero_ps()));
        }
        if (allInside == 15) {
            FUN_00e66600(state,code);
            FUN_00e66290(state,code);
            return 1;
        }
        return 2;
    }
    __forceinline int classifyB(DecodeState* state, const unsigned char* code, const BoundsPair& bounds) {
        const __m128& lower=bounds.minimum;
        int allInside = 15;
        int n=count;
        const PlanePacket* p=planes;
        const PlanePacket* q=absolutePlanes;
        __m128 center = _mm_add_ps(bounds.maximum, lower);
        __m128 extent = _mm_sub_ps(bounds.maximum, lower);
        for (; --n >= 0; ++p, ++q) {
            __m128 px=p->x;
            __m128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(q->x,_mm_shuffle_ps(extent,extent,0)),
                           _mm_mul_ps(q->y,_mm_shuffle_ps(extent,extent,0x55))),
                _mm_add_ps(_mm_mul_ps(q->z,_mm_shuffle_ps(extent,extent,0xaa)),q->w));
            __m128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(center,center,0),px),
                           _mm_mul_ps(_mm_load_ps(p->y.m128_f32),_mm_shuffle_ps(center,center,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(p->z.m128_f32),_mm_shuffle_ps(center,center,0xaa)),_mm_load_ps(p->w.m128_f32)));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance,radius),_mm_setzero_ps())) != 15) return 0;
            allInside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance,radius),_mm_setzero_ps()));
        }
        if (allInside == 15) {
            FUN_00e66600(state,code);
            FUN_00e66290(state,code);
            return 1;
        }
        return 2;
    }
};
struct TreeDecoder {
    OutputArray* output;
    int unk04; int unk08; int unk0C; float scale; int unk14; int unk18; int unk1C;
    CullMachine cull;
    void FUN_00e5e430(DecodeState*, const unsigned char*, BoundsPair*);
    __forceinline void emit(int value) {
        OutputArray* a = output;
        AllocatorContext* context = (AllocatorContext*)FUN_00c85750();
        if (a->size == (a->capacity & 0x3fffffff)) ResizeAudioStream(context->allocator,a,4);
        int* destination = &a->data[a->size]; ++a->size; *destination = value;
    }
    __forceinline void readBounds(DecodeState* state, const unsigned char* code, int& offset, BoundsPair& bounds, const float& scalar) {
        int op = code[offset];
        while (op >= 0x26 && op <= 0x2b) {
            if (op >= 0x29) {
                bounds.minimum.m128_f32[op-0x29] = read24(code+offset+1)*scalar;
                bounds.maximum.m128_f32[op-0x29] = int(((code[offset+4]<<8)+code[offset+5]<<8)+code[offset+6])*scalar;
                offset += 7;
            } else {
                bounds.minimum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+1]<<state->shift))*scalar;
                bounds.maximum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+2]<<state->shift))*scalar;
                offset += 3;
            }
            op = code[offset];
        }
    }    __forceinline void readBoundsRight(DecodeState* state, const unsigned char* code, int& offset, BoundsPair& bounds) {
        int op = code[offset];
        while (op >= 0x26 && op <= 0x2b) {
            if (op >= 0x29) {
                bounds.minimum.m128_f32[op-0x29] = read24(code+offset+1)*scale;
                bounds.maximum.m128_f32[op-0x29] = (int)rightPacked(code+offset+4)*scale;
                offset += 7;
            } else {
                bounds.minimum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+1]<<state->shift))*scale;
                bounds.maximum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+2]<<state->shift))*scale;
                offset += 3;
            }
            op = code[offset];
        }
    }

};

extern "C" __m128 _mm_and_ps(__m128, __m128);
