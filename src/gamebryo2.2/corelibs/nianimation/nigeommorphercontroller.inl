#include "f3_common.h"
#include "nigeommorphercontroller_decls.h"
// @fnv 0x00a3b460
// pdb: NiGeomMorpherController::AllocateInterpArray | NiGeomMorpherController.obj | fnv360_0822_retail, objrun, medium
void NiGeomMorpherController::ClearInterpolatorArray()
{
    delete[] m_pInterpolatorItems;
    m_pInterpolatorItems = 0;
    if (m_spMorphTargetData && m_spMorphTargetData->m_uiNumTargets > 0)
        m_pInterpolatorItems = new InterpItem[m_spMorphTargetData->m_uiNumTargets];
}
