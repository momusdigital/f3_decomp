#include "f3_common.h"
#include "nitpool_decls.h"
// pdb: NiTPool<NiPSysUpdateTask,NiTNewInterface<NiPSysUpdateTask> >::CreateNewObjects | NiPSysUpdateTask.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: uiSize
template<>
// @fnv 0x00e7f160
void ObjectPool<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >::AddPoolBlock(unsigned int n) {
 ObjectPoolBlock<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >* p = new ObjectPoolBlock<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >(n);
 for (unsigned int i=0; i<n; ++i) freeObjects.Add(p->GetAt(i));
 p->next = containers;
 containers = p;
}
