#include <new>
// src/f3staging/f3iso_00852f40_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00852f40 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00852f40 (community match, verified in this file)
extern void* DAT_0109053c;
namespace f3m_00852f40 {
namespace Viewer00852f40 {
struct StrArr
{
    void* m_pData;
    void* m_pAllocator;
    unsigned short m_usCapacity;
    unsigned short m_usSize;
    unsigned short m_usReserved;
    unsigned short m_usGrowBy;

    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
struct Obj
{
    void FUN_00846510(StrArr*);
};
char* __cdecl FUN_00847b50(void*);
char* __cdecl FUN_00847ce0(char const*, unsigned short);
char* __cdecl FUN_00847e20(char const*, void*);

struct ScreenElementsData : Obj {
    unsigned char geometry[0x58];
    void* m_akPolygon;
    void* m_ausPIndexer;
    unsigned short m_usMaxPQuantity, m_usPGrowBy, m_usPQuantity, m_usMaxVQuantity, m_usVGrowBy, m_usMaxIQuantity, m_usIGrowBy;
    void FUN_00852f40(void* pkStrings);
};
namespace anon_00852f40 {} using namespace anon_00852f40; namespace anon_00852f40 {
inline void AddViewerString(StrArr* strings, char* value)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->FUN_00555790(index + strings->m_usGrowBy);
    strings->FUN_005b3880(index, value);
}
}

// pdb: NiScreenElementsData::GetViewerStrings | NiScreenElementsData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void ScreenElementsData::FUN_00852f40(void* pkStrings)
{
    StrArr* strings = static_cast<StrArr*>(pkStrings);

    FUN_00846510(strings);

    AddViewerString(strings, FUN_00847b50(DAT_0109053c));

    AddViewerString(strings, FUN_00847e20("m_akPolygon", this->m_akPolygon));

    AddViewerString(strings, FUN_00847e20("m_ausPIndexer", this->m_ausPIndexer));

    AddViewerString(strings, FUN_00847ce0("m_usMaxPQuantity", this->m_usMaxPQuantity));

    AddViewerString(strings, FUN_00847ce0("m_usPGrowBy", this->m_usPGrowBy));

    AddViewerString(strings, FUN_00847ce0("m_usPQuantity", this->m_usPQuantity));

    AddViewerString(strings, FUN_00847ce0("m_usMaxVQuantity", this->m_usMaxVQuantity));

    AddViewerString(strings, FUN_00847ce0("m_usVGrowBy", this->m_usVGrowBy));

    AddViewerString(strings, FUN_00847ce0("m_usMaxIQuantity", this->m_usMaxIQuantity));

    AddViewerString(strings, FUN_00847ce0("m_usIGrowBy", this->m_usIGrowBy));
}

}
}   // namespace f3m_00852f40
