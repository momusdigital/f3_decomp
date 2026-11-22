// BSCoreDefines.h: BSIntToType and BSEndian, the byte-order helpers of BSCore.
// Names and signatures: FNV360_PDB (BSEndian(char*, BSIntToType<2|4|8>), bscore/xenon/bscoredefines_xenon.h) and
// TESV_MAP (?BSEndian@@YAXPADU?$BSIntToType@$03@@@Z). On PC the swap is inlined: each call reads, swaps and stores
// its value before the next call reads (an assignment written in place lets VC8 interleave the loads).
#ifndef F3_BSCOREDEFINES_H
#define F3_BSCOREDEFINES_H
#include <stdlib.h>

template <int N> struct BSIntToType
{
};

inline void BSEndian(char* apData, BSIntToType<2>)
{
    *(unsigned short*)apData = _byteswap_ushort(*(unsigned short*)apData);
}

inline void BSEndian(char* apData, BSIntToType<4>)
{
    *(unsigned long*)apData = _byteswap_ulong(*(unsigned long*)apData);
}
#endif
