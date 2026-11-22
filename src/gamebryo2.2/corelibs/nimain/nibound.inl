#include "f3_common.h"
#include "nibound_decls.h"
// @fnv 0x00a7fdd0
// pdb: NiBound::Update | NiSkinData.obj | tesv_win, call_seq, medium
void NiBound::Update(const NiBound& bound,const NiTransform& transform)
{
    m_kCenter = transform.m_kTranslation + (transform.m_kOrientation * bound.m_kCenter) * transform.m_fScale;
    m_fBoundRadius = bound.m_fBoundRadius * transform.m_fScale;
}
