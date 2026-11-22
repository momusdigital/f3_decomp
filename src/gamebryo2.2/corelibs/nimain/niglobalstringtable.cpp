// gamebryo2.2/corelibs/nimain/niglobalstringtable.cpp: NiGlobalStringTable, NiPlaybackFile (1 function)
#include "f3_common.h"
#include "niglobalstringtable_decls.h"

#pragma optimize("", off)

#pragma intrinsic(strlen)
#pragma optimize("gt", on)
#pragma optimize("y", on)
// Looks up or allocates a reference-counted copy of s in the global string table under a critical section and returns the string pointer.
// @f3 0x008242a0 (community match, verified in this file)
// pdb: NiGlobalStringTable::AddString | NiGlobalStringTable.obj | fnv360_0721_beta, udata, medium, conflict (skyrim: BSFixedString::BSFixedString)
// pdb params: pcString
__pragma(intrinsic(strlen))

char* NiGlobalStringTable::AddString(const char* s)
{
    if (!s)
        return 0;

    unsigned len = strlen(s);
    EnterCriticalSection((char*)DAT_011f42c0 + 0x2080);
    char* result = DAT_011f42c0->FUN_00a5b300(s, len);
    if (result)
    {
        InterlockedIncrement((long*)(result - 8));
        LeaveCriticalSection((char*)DAT_011f42c0 + 0x2080);
        return result;
    }
    unsigned tlsIndex = _tls_index;

    char* pTlsData = ((char**)__readfsdword(0x2c))[tlsIndex];
    volatile unsigned uiOldTlsValue = *(unsigned*)(pTlsData + 0x298);
    *(unsigned*)(pTlsData + 0x298) = 8;
    unsigned uiAllocSize = len + 9;
    unsigned uiRemainder = uiAllocSize & 3;
    if (uiRemainder)
        uiAllocSize += 4 - uiRemainder;
    unsigned* allocation = (unsigned*)_NiMalloc(uiAllocSize);
    result = (char*)(allocation + 2);
    allocation[0] = 1;
    allocation[1] = len;
    char* handle = result;
    fnv_zlib_memcpy(result, s, len + 1);
    DAT_011f42c0->FUN_00a5b5a0(&handle, len);
    LeaveCriticalSection((char*)DAT_011f42c0 + 0x2080);
    *(unsigned*)(pTlsData + 0x298) = uiOldTlsValue;
    return result;
}

#pragma optimize("", off)

#pragma function(strlen, strcpy)
