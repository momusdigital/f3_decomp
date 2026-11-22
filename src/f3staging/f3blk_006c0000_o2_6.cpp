#include <string.h>
#include <string.h>
#include <intrin.h>
// src/f3staging/f3blk_006c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d3530 (community match, verified in this file)
namespace f3m_006d3530 {


namespace f3m_006d3530 {
struct TypeInfo
{
    unsigned char size;
    unsigned char unk01;
    unsigned char unk02;
};
extern TypeInfo DAT_00f6cfb8[];

struct PackedID
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    PackedID() : b0(0), b1(0), b2(0) {}
};

struct Raw12
{
    int unk00;
    int unk04;
    int unk08;
};

struct Record4
{
    PackedID id;
    unsigned char p03;
    unsigned char p04;
    unsigned char p05;
    unsigned char p06;
    unsigned char p07;
    unsigned char p08;
    unsigned char p09;
    unsigned char p0A;
    unsigned char p0B;
    unsigned char p0C;
    unsigned char p0D;
    unsigned char p0E;
    unsigned char p0F;
    unsigned char p10;
    unsigned char p11;
    unsigned char p12;
    unsigned char p13;
    unsigned char p14;
    unsigned char p15;
    unsigned char p16;
    unsigned char p17;
    unsigned char p18;
    unsigned char p19;
    unsigned char p1A;
    unsigned char p1B;
    unsigned char p1C;
    unsigned char p1D;
    unsigned char p1E;
    unsigned char p1F;
    unsigned char p20;
    unsigned char p21;
    unsigned char p22;
    unsigned char p23;
};

struct Record5
{
    PackedID first;
    unsigned char p03;
    unsigned char p04;
    unsigned char p05;
    unsigned char p06;
    unsigned char p07;
    unsigned char p08;
    unsigned char p09;
    unsigned char p0A;
    unsigned char p0B;
    unsigned char p0C;
    unsigned char p0D;
    unsigned char p0E;
    unsigned char p0F;
    unsigned char p10;
    unsigned char p11;
    unsigned char p12;
    unsigned char p13;
    unsigned char p14;
    unsigned char p15;
    unsigned char p16;
    unsigned char p17;
    unsigned char p18;
    unsigned char p19;
    unsigned char p1A;
    unsigned char p1B;
    PackedID second;
};

struct Record6
{
    PackedID first;
    unsigned char p03;
    unsigned char p04;
    unsigned char p05;
    unsigned char p06;
    unsigned char p07;
    unsigned char p08;
    unsigned char p09;
    unsigned char p0A;
    unsigned char p0B;
    unsigned char p0C;
    unsigned char p0D;
    unsigned char p0E;
    unsigned char p0F;
    unsigned char p10;
    unsigned char p11;
    unsigned char p12;
    unsigned char p13;
    unsigned char p14;
    unsigned char p15;
    unsigned char p16;
    unsigned char p17;
    unsigned char p18;
    unsigned char p19;
    unsigned char p1A;
    PackedID second;
    unsigned char q1E;
    unsigned char q1F;
    unsigned char q20;
    unsigned char q21;
    unsigned char q22;
    unsigned char q23;
};

struct Value
{
    unsigned int first;
    unsigned int second;
    unsigned int unk08;
    unsigned int value;

    void FUN_006d3000(const Raw12* raw);
    void FUN_006d3040(const Raw12* raw);
    void FUN_006d3080(const Record4* record);
    void FUN_006d30d0(const Record5* record);
    void FUN_006d3130(const Record6* record);
    void SetRaw(unsigned int v) { second = 0; unk08 = 0; first = 0; value = v; }
};

// pdb: BGSSaveLoadInitialData::LoadInitialDataStruct | BGSSaveLoadInitialData.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apBuffer, aeType, apInitialDataBuffer
int __cdecl FUN_006d3530(const void* src, int type, Value* out)
{
    unsigned int size = DAT_00f6cfb8[type].size;
    switch (type) {
    case 1: {
        Raw12 raw;
        memcpy(&raw, src, size);
        out->FUN_006d3000(&raw);
        return DAT_00f6cfb8[type].size + 1;
    }
    case 2: {
        Raw12 raw;
        memcpy(&raw, src, size);
        out->FUN_006d3040(&raw);
        return DAT_00f6cfb8[type].size + 1;
    }
    case 3: {
        unsigned int value;
        memcpy(&value, src, size);
        out->SetRaw(value);
        return DAT_00f6cfb8[type].size + 1;
    }
    case 4: {
        Record4 record;
        memcpy(&record, src, size);
        out->FUN_006d3080(&record);
        return DAT_00f6cfb8[type].size + 1;
    }
    case 5: {
        Record5 record;
        memcpy(&record, src, size);
        out->FUN_006d30d0(&record);
        return DAT_00f6cfb8[type].size + 1;
    }
    case 6: {
        Record6 record;
        memcpy(&record, src, size);
        out->FUN_006d3130(&record);
        break;
    }
    }
    return DAT_00f6cfb8[type].size + 1;
}
}
}   // namespace f3m_006d3530
