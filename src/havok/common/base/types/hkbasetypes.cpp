// src/havok/common/base/types/hkbasetypes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/hkbasetypes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned char DAT_010c7948;
extern unsigned char DAT_010c7b48;
extern unsigned char DAT_010c7d48;
extern unsigned char str_010c7d44;

struct FUN_00ca9360_cls
{
    unsigned char m_00;
    FUN_00ca9360_cls* FUN_00ca9360(const float* key);
};

// Binary-searches a sorted float table for the value at key and stores the resulting index in m_00, or 0 if below the first entry.
// @f3 0x0090aba0 (community match, verified in this file)
extern int DAT_00e35180;
extern int DAT_00e35380;
extern int DAT_00e35580;
// pdb: hkUFloat8::operator= | hkBaseTypes.obj | fnv360_0822_retail, uconst, high
// pdb params: fv
FUN_00ca9360_cls* FUN_00ca9360_cls::FUN_00ca9360(const float* key)
{
    FUN_00ca9360_cls* pResult = this;
    int iKey = *(const int*)key;
    unsigned lo = (unsigned)&DAT_00e35180;
    unsigned hi = (unsigned)&DAT_00e35580;
    unsigned mid;

    if (iKey > 0x4358cccd)
        lo = (unsigned)&DAT_00e35380;
    else
        hi = (unsigned)&DAT_00e35380;

    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;

    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        mid += 4;
    pResult->m_00 = (unsigned char)(((int)(mid - (unsigned)&DAT_00e35180)) >> 2);
    return pResult;
}

