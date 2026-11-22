#include "nitcollection_decls.h"
// pdb: NiTObjectArray<NiPointer<NiShaderConstantMapEntry> >::NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > | NiXenonFragmentShader.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: NiTNewInterface<class NiPointer<class NiGeometry> >::Allocate)
// pdb params: uiMaxSize, uiGrowBy
template <>
// @fnv 0x00c1d740
NiPointer<NiGeometry>* NiTNewInterface<NiPointer<NiGeometry> >::Allocate(unsigned int count)
{
    return reinterpret_cast<NiPointer<NiGeometry>*>(new NiPointer<NiTexture>[count]);
}
