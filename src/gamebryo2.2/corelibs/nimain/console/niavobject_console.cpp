// gamebryo2.2/corelibs/nimain/console/niavobject_console.cpp: NiAVObject (1 function)
#include "niavobject_console_decls.h"
// @fnv 0x00a68c60
// pdb: NiLight::LinkObject | NiLight.obj | fnv360_0822_debug, objrun_prop, low, conflict (skyrim: NiAVObject::UpdateWorldData)
// pdb params: stream
void NiAVObject::UpdateWorldData(NiUpdateData& aUpdateData)
{
    NiCollisionObject* pCollisionObject = collision;
    if (pCollisionObject)
        pCollisionObject->Unk_24(aUpdateData);
    else
        UpdateWorldLoc();
}
