#include "f3_common.h"
#include "nicontrollersequence_decls.h"
// @fnv 0x00a5d3f0
// pdb: NiObject::CreateSharedClone | NiObject.obj | fnv360_0822_retail, call_seq, high
// pdb params: kCloning
NiControllerSequence__IDTag& NiControllerSequence__IDTag::operator=(const NiControllerSequence__IDTag& rhs)
{
    ShaderBufferRecord* result;
    NiTStringPointerMap<ShaderBufferRecord*>* map = *(NiTStringPointerMap<ShaderBufferRecord*>**)&rhs;
    if (map->GetAt((const char*)this, result))
        return *(NiControllerSequence__IDTag*)result;
    return Clone(rhs);
}
