#include <new>
// src/f3staging/f3iso_0042dba0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0042dba0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0042dba0 (community match, verified in this file)
extern char DAT_01090a78[];
namespace f3m_0042dba0 {
struct F0042dba0_Mem
{
    void FUN_0086ba60(void* pMemory);
};

struct F0042dba0_Str
{
    int unk00;
    union
    {
        char* m_pcData;
        char m_acBuf[16];
    };
    unsigned int m_uiLength;
    unsigned int m_uiCapacity;
};

// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> > | TESObject.obj | fnv360_0822_retail, call_gap, low
F0042dba0_Str* __fastcall FUN_0042dba0(F0042dba0_Str* p)
{
    if (p->m_uiCapacity >= 0x10)
    {
        ((F0042dba0_Mem*)DAT_01090a78)->FUN_0086ba60(p->m_pcData);
    }
    p->m_uiCapacity = 0xF;
    p->m_uiLength = 0;
    p->m_acBuf[0] = 0;
    return 0;
}
}   // namespace f3m_0042dba0
