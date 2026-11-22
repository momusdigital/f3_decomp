#include "f3_common.h"
// src/fallout_shared/tesobjectcell_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectcell.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";

void* __cdecl _memmove(void* dst, const void* src, unsigned int count);
void* __cdecl _fnv_zlib_memset(void* ptr, int value, unsigned int count);

struct FUN_00bb39e0_shell
{
    int m_00;
    int m_04;
    void* m_08;
    void FUN_00bb39e0(const void* src, unsigned int count);
};

// @fnv 0x00bb39e0
// pdb: STLSPData::SetLeafMaps | SpeedTreeLeafShaderProperty.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: CSpeedTreeRT::SGeometry::~SGeometry)
// pdb params: apLeafMaps, aiCount
void FUN_00bb39e0_shell::FUN_00bb39e0(const void* src, unsigned int count)
{
    if (src && m_08)
    {
        if (count)
        {
            if (count >= 192)
                count = 192;
            _memmove(m_08, src, count * 4);
            if (count < 192)
                _fnv_zlib_memset((char*)m_08 + count * 4, 0, (192 - count) * 4);
        }
    }
}
