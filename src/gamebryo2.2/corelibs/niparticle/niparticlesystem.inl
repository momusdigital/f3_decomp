#include "f3_common.h"
#include "niparticlesystem_match.h"
inline NiPSysModifier* NiParticleFindModifier(NiParticleModifierOwner* owner, const char* const& name)
{
    NiParticleModifierNode* position = owner->head;
    while (position) {
        NiPSysModifier* modifier = NiParticleGetNext(position);
        if (modifier && modifier->name == name)
            return modifier;
    }
    return 0;
}
// @fnv 0x00C31400
// pdb: NiPSysModifierCtlr::GetModifierPointerFromName | NiPSysModifierCtlr.obj | fnv360_0822_retail, call_seq, high
// pdb: NiPSysModifierCtlr::GetModifierPointerFromName | NiPSysModifierCtlr.obj | fnv360_0822_retail, call_seq, high (was: FindModifier)
void NiParticleSystem::NiPSysModifierCtlr_GetModifierPointerFromName()
{
    result = NiParticleFindModifier(owner, name);
}
