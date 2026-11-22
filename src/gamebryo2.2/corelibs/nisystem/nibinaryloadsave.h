#include "f3_common.h"
#include "nibinaryloadsave_decls.h"
// @fnv 0x00a29580
// pdb: NiBoolKey::LoadBinary | NiBoolKey.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: stream
void BooleanKey::LoadBinary(NiStream& stream)
{
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &m_fTime);
    unsigned char value;
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &value);
    m_bValue = value != 0;
}
