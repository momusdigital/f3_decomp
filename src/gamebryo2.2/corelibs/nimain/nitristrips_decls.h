// gamebryo2.2/corelibs/nimain/nitristrips_decls.h: declares NiParticles, NiTriStrips
class NiParticles
{
  public:
    NiParticles();
    unsigned int* vtable;
};
class NiTriStrips : public NiParticles
{
  public:
    unsigned char unk04[0xB4];
    void* m_spModelData;  // src: FNV360_PDB NiGeometry +0xB8
    NiTriStrips();
};
extern unsigned int DAT_0109ed94;
