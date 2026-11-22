// src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaWaveletCompressedAnimation.h"

// Computes an offset from a and the first two bytes of b: ((a - b[1]) * b[0] + 7) / 8 + b[1] * 4.
// @fnv 0x00e51da0
// pdb: hkCalcQuantizedSize | hkaQuantizeReal.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: nValues, desc
int __cdecl FUN_00e51da0(int aiValue, const char* apBytes)
{
    unsigned char x = (unsigned char)apBytes[1];
    unsigned char y = (unsigned char)apBytes[0];
    return ((aiValue - x) * y + 7) / 8 + x * 4;
}

struct FUN_00e2f8b0_Obj
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

    int FUN_00e2f8b0();
};
// @fnv 0x00e2f8b0
// pdb: BSTempEffectSimpleDecal::Get3D | BSTempEffectSimpleDecal.obj | fnv360_0822_retail, vtable, medium
int FUN_00e2f8b0_Obj::FUN_00e2f8b0()
{
    return unk28;
}

class FUN_00e2f860 {
public:
    hkUint16 m_maxIterations;
    hkUint16 m_firstFreeIndex;
    hkUint16 m_flags;
    hkUint16 m_pad06;
    hkReal m_fScalar;
    volatile unsigned char m_enabled;
    hkReal m_offset;
    hkReal m_linearTolerance;
    hkReal m_angularTolerance;
    hkReal m_linearLimit;
    hkReal m_fAngularLimit;

    FUN_00e2f860();
};

// Initializes solver parameters such as m_maxIterations, m_fScalar, and tolerance values to their default values.
// @f3 0x0050d260 (community match, verified in this file)
namespace f3m_0050d260 {
struct SolverSettingsView50d260
{
    float value00;
    float value04;
    float value08;
    float value0C;
    float value10;
    float value14;
    float value18;
    unsigned char flag1C;
    int index20;
};
}

// pdb: DecalData::DecalData | DecalData.obj | fnv360_0822_retail, call_dedup, high
FUN_00e2f860::FUN_00e2f860()
{
    f3m_0050d260::SolverSettingsView50d260* self = reinterpret_cast<f3m_0050d260::SolverSettingsView50d260*>(this);
    self->value08 = 8.0f;
    self->flag1C = 4;
    self->index20 = -1;
    self->value0C = 32.0f;
    self->value04 = 32.0f;
    self->value00 = 8.0f;
    self->value18 = 1.0f;
    self->value10 = 32.0f;
    self->value14 = 4.0f;
}


class ObjE2F8 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Process(float fTime, int iA, int iB, int iC, int iD, int iE);
    int unk04, unk08, unk0C;
    int m_iFirst;
    int m_iSecond;

    void FUN_00e2f8e0(float fTime, int iB, int iD, int iE);
};

// @f3 0x00584760 (community match, verified in this file)
void __cdecl FUN_005845b0(ObjE2F8* self, float time, int first, int second, int fourth, int fifth);

// pdb: GamePlayFormulas::GetActorSwimWalkSpeed | GamePlayFormulas.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: CombatFormulas::CalcHandToHandDamage)
// pdb params: apActor, pWeap, pArmor, abNoWeapon, abIsNpc, abOverEncumbered
void __cdecl FUN_00e2f8e0(ObjE2F8* self, float time, int second, int fourth, int fifth)
{
    FUN_005845b0(self, time, 0, second, fourth, fifth);
}


struct e2f910_Cls
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* dest, int value, int count);
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual int vf40(int value);

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
    int m_iDofCount;
};

struct e2f910_Stream
{
    e2f910_Cls* ctrl;
};

volatile int g_e2f910_a2 = 0;
volatile int g_e2f910_a4 = 0;
e2f910_Stream* volatile g_e2f910_stream = 0;

struct hkBoolE2FA {
    char m_cBooleanValue;
    hkBoolE2FA() {}
};

namespace fnv_00e300b0 {

struct BitDesc {
    unsigned char bits;
    unsigned char preserved;
};

int __cdecl FUN_00e51da0(int a, const char* b);
void* __cdecl FUN_00c85750(void);
int __cdecl DecodeBlock(unsigned char* data, int* qp, unsigned char* block, int nbytes);
void __cdecl DecodeQuantizedBlock(unsigned char* block, BitDesc* desc, float* out, int n);
void __cdecl FUN_00e51140(float* out, int n);

}  // namespace fnv_00e300b0

// Swaps the byte order of a float by reinterpreting its bits as a 32-bit integer and reversing the four bytes.
// @f3 0x0061dbe0 (community match, verified in this file)
// FUN_0061dbe0 (51 bytes, symbol ?FUN_0061dbe0@@YAXIAAI000@Z): __cdecl void taking an unsigned value and FOUR unsigned
// references - the forward-compression digits 0 in that mangling repeat the reference parameter type, so earlier reports
// about a "zero-length array" are a misreading. Their body just splits the value into four byte fields:
//   mov eax,[esp+arg_0] ; mov ecx,eax ; shr ecx,18h ; mov [edx],ecx          (edx = arg_4)
//   mov ecx,eax ; shr ecx,10h ; and ecx,0FFh ; mov [edx],ecx                 (edx = arg_8)
//   movzx ecx,ah ; mov [edx],ecx                                             (edx = arg_C)  - the high byte, taken directly
//   movzx eax,al ; mov [ecx],eax                                             (ecx = arg_10) - the low byte
// pdb: WritePrivateProfileString | XSettingsFile.obj | fnv360_0822_retail, callee_sim, low
// pdb params: apAppName, apKeyName, apString, apFileName
void FUN_0061dbe0(unsigned int value, unsigned int& top, unsigned int& upperMiddle, unsigned int& lowerMiddle, unsigned int& bottom) {
    top = value >> 24;                       // ORIG: mov ecx,eax ; shr ecx,18h ; mov [edx],ecx ??
    upperMiddle = (value >> 16) & 0xFFu;     // ORIG: mov ecx,eax ; shr ecx,10h ; and ecx,0FFh ; mov [edx],ecx ??
    lowerMiddle = (value >> 8) & 0xFFu;      // ORIG: movzx ecx,ah - VC8 takes the second byte straight from AH ??
    bottom = value & 0xFFu;                  // ORIG: movzx eax,al ?? then plain retn (cdecl, five arguments, caller cleans up)
}


// @fnv 0x00e2f9d0
unsigned short volatile g_in; unsigned short g_out;

#include <xmmintrin.h>

// Companion quad-writer variant (scalar-load broadcast form) that shares the
// module with FUN_00e2fbc0; TU order matters for VC9's codegen state.
struct DestWrapPre { float* p; DestWrapPre(float* q) : p(q) {} };

struct DestWrap { float* p; DestWrap(float* q) : p(q) {} };

extern "C" void __cdecl _ReadWriteBarrier(void);
struct SwapCountsE2 {
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    float n;
    SwapCountsE2() : a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), n(0.0f) {}
};

#include <string.h>
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
typedef void* (__stdcall* S00e306d0_TlsFn)(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010eb358[];
extern const char str_010c41f8[];

static volatile unsigned int s00e306d0_sink;

struct S00e306d0_Stream {
    int unk00;
    char* m_curr;
    int unk08;
    char* m_kRayEnd;

    void timerBegin() {
        char* p = m_curr;
        if (p < m_kRayEnd) {
            *(const char**)p = str_010eb358;
            _ReadWriteBarrier();
            unsigned int tb = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&tb;
            if (0) memmove(&tb, &tb, 4);
            p += 12;
            m_curr = p;
        }
    }

    void timerEnd() {
        char* p = m_curr;
        if (p < m_kRayEnd) {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            unsigned int te = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&te;
            if (0) memmove(&te, &te, 4);
            p += 12;
            m_curr = p;
        }
    }
};

#include <windows.h>
namespace fnv_00e307b0 {
extern DWORD DAT_0126835c;

struct hkBoolR {
    char m_cBooleanValue;
    hkBoolR(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

}  // namespace fnv_00e307b0

struct hkDmaRefE2FA {
    const void* m_ptr;
    int m_iElementCount;
    unsigned char m_offset;

    void set(const void* p, int size)
    {
        m_offset = (unsigned char)((unsigned int)p & 0xf);
        m_ptr = p;
        m_iElementCount = size;
    }
};

struct InfoE2FB {
    InfoE2FB() : m_iFirstValue(0), m_uiLogicalSize(0), m_bFlag(false) {}
    int m_iFirstValue;
    int m_uiLogicalSize;
    unsigned char m_bFlag;
};

struct ChunkRetry {
    const void* data;
    unsigned int size;
    unsigned char misalignment;
    void setStart(const void* p) {
        unsigned long bits = (unsigned long)p;
        misalignment = (unsigned char)(bits & 15);
        bits &= ~15UL;
        data = (const void*)bits;
    }
    void finish() { size = (size + misalignment + 15) & ~15U; }
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned __int64 __rdtsc();

extern "C" unsigned long DAT_0126835c;
extern "C" void _ReadWriteBarrier();

class hkStackAllocator {public:char* m_pTileTemplate;};

class NineIntegerRecord {public:hkStackAllocator m_aiEntries;};

extern "C" NineIntegerRecord* __cdecl FUN_00c85750();

struct Chunk {const hkUint8* data;unsigned int size;hkUint8 offset;const hkUint8* bytes() const {return data+offset;}};

struct Quantization {hkUint8 bitWidth,preserved;float scale,offset;};

struct PackedFormat {unsigned int bits,value,rawCount;};

int __cdecl FUN_00e51da0(int,const Quantization*);

unsigned int __cdecl DecodeBlock(const float*,const PackedFormat*,float*,unsigned int);

void __cdecl DecodeQuantizedBlock(const float*,const Quantization*,float*,int);

void __cdecl FUN_00e51140(float*,int);

struct TrackStatistics {

    unsigned int staticTranslations, staticRotations, staticScales;

    unsigned int dynamicTranslations, dynamicRotations, dynamicScales;

    unsigned int totalStatic;

    unsigned int selectedTranslations, selectedRotations, selectedScales;

    unsigned int selectedFloats, totalDynamic, totalFloats;

    float weight;

    __forceinline void Reset() {

        staticTranslations = 0;

        staticRotations = 0;

        staticScales = 0;

        dynamicTranslations = 0;

        dynamicRotations = 0;

        dynamicScales = 0;

        totalStatic = 0;

        selectedTranslations = 0;

        selectedRotations = 0;

        selectedScales = 0;

        selectedFloats = 0;

        totalDynamic = 0;

        totalFloats = 0;

        weight = 0.0f;

    }

};

void __cdecl AnalyzeTrackWithZeroCount(const hkUint16*,const hkUint16*,unsigned int,unsigned int,TrackStatistics*);

struct hkBoolE30 {
    char m_cBooleanValue;
    hkBoolE30() {}
};

struct TrackAnalysisE30 {
    int staticTranslations;
    int staticRotations;
    int staticScales;
    int staticFloats;
    int dynamicTranslations;
    int dynamicRotations;
    int dynamicScales;
    int translationDOFs;
    int rotationDOFs;
    int scaleDOFs;
    int floatDOFs;
    int transformTracks;
    int floatTracks;
    float tolerance;
    void clear() {
        staticTranslations = 0;
        staticRotations = 0;
        staticScales = 0;
        staticFloats = 0;
        dynamicTranslations = 0;
        dynamicRotations = 0;
        dynamicScales = 0;
        translationDOFs = 0;
        rotationDOFs = 0;
        scaleDOFs = 0;
        floatDOFs = 0;
        transformTracks = 0;
        floatTracks = 0;
        tolerance = 0.0f;
    }
};
void __cdecl AnalyzeTrackWithZeroCount(const unsigned short*, const unsigned short*, int, int, TrackAnalysisE30*);
