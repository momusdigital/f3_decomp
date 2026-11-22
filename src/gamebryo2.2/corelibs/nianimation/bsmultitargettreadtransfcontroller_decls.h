// gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller_decls.h: declares TreadEntry, BSMultiTargetTreadTransfController
class NiInterpolator;
struct TreadEntry
{
    char data[0x34];
};
class BSMultiTargetTreadTransfController
{
    char padding[0x34];
    TreadEntry* entries;

  public:
    struct LinkAVObj
    {
        unsigned short usBlendIdx;  // src: FNV360_PDB +0x0
        void* pTarget;  // src: FNV360_PDB +0x4 (NiAVObject*)
        void* pLink;  // src: FNV360_PDB +0x8 (BSTreadTransfInterpolator::LinkInfo*)
    };
    unsigned short usNumInterps;  // src: FNV360_PDB +0x38
    LinkAVObj** pLinksA;  // src: FNV360_PDB +0x3C
    unsigned short usNumLinks;  // src: FNV360_PDB +0x40

    NiInterpolator* GetInterpolator(unsigned short index);
};
extern unsigned int DAT_011f36a0;
extern char DAT_00a2d8a0;
extern char DAT_00a2de70;
void __cdecl FUN_00aa2080(void*, void*);
class GlobalObject_00a2e180
{
  public:
    GlobalObject_00a2e180();
};
