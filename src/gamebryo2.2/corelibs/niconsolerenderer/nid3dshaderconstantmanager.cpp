#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiD3DShaderConstantManager
{
    virtual ~NiD3DShaderConstantManager();
    void* __thiscall Destroy(unsigned int flags);
};

extern "C" void __cdecl __Dummy_00b6fef0(void* ptr, unsigned int flags);
void __cdecl FUN_00e989c0();

// @fnv 0x00e98a70
// pdb: SpeedTreeShaderLightingProperty::`scalar deleting destructor' | SpeedTreeShaderProperty.obj | fnv360_0822_retail, objrun_prop, low
void* __thiscall NiD3DShaderConstantManager::Destroy(unsigned int flags)
{
    FUN_00e989c0();
    if (flags & 1)
    {
        __Dummy_00b6fef0(this, 0x88);
    }
    return this;
}
