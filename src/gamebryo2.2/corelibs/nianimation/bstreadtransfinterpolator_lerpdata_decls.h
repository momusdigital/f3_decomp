// gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator_lerpdata_decls.h: BSTreadTransfInterpolator's lerp data, shared by the unit's variants
#ifndef BSTREADTRANSFINTERPOLATOR_LERPDATA_DECLS_H
#define BSTREADTRANSFINTERPOLATOR_LERPDATA_DECLS_H
// NiFloatData's key fields (FNV360_PDB).
struct LerpData_00a43560
{
    void* unk00;
    unsigned int unk04;
    int m_uiNumKeys;  // src: FNV360_PDB NiFloatData +0x8
    void* m_pkKeys;  // src: FNV360_PDB NiFloatData +0xC
    void* m_eType;  // src: FNV360_PDB NiFloatData +0x10
    unsigned char m_ucKeySize;  // src: FNV360_PDB NiFloatData +0x14
};
struct TreadTransf_00a43560
{
    unsigned char unk00[0x20];
    LerpData_00a43560* spLerpData;  // src: FNV360_PDB BSTreadTransfInterpolator +0x20
};
#endif
