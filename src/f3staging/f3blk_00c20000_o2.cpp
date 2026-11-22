// src/f3staging/f3blk_00c20000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00c22390 (community match, verified in this file)
extern char* g_dat_0117a5e8;
namespace f3m_00c22390 {

class T {
public:
    void FUN_00555790(int);
    void FUN_005b3880(int, char**);
};

extern "C" void __stdcall FUN_00825b40(void*);
extern "C" char* __cdecl FUN_00847b50(char*);

// pdb: NiRenderTargetGroup::GetViewerStrings | NiRenderTargetGroup.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void __stdcall FUN_00c22390(void* p)
{
    FUN_00825b40(p);
    char* s = FUN_00847b50(g_dat_0117a5e8);
    unsigned int edi = *((unsigned short*)((char*)p + 0xa));
    unsigned int ecxv = *((unsigned short*)((char*)p + 0x8));
    if (edi >= ecxv) {
        unsigned int edx = *((unsigned short*)((char*)p + 0xe));
        ((T*)p)->FUN_00555790(edx + edi);
    }
    ((T*)p)->FUN_005b3880(edi, &s);
}
}   // namespace f3m_00c22390

// @f3 0x00c22400 (community match, verified in this file)
extern void* DAT_00eb9d64;
namespace f3m_00c22400 {
struct DispatchTransitionA233 {
    void** dispatch;
    void FUN_00825830();
    void FUN_00c22400();
};
// pdb: NiShaderDeclaration::~NiShaderDeclaration | NiShaderDeclaration.obj | fnv360_0822_retail, objopen_prop, low
void DispatchTransitionA233::FUN_00c22400() {
    dispatch=&DAT_00eb9d64;
    FUN_00825830();
}
}   // namespace f3m_00c22400
