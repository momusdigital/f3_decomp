// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00a981d0_Base
{
    S_00a981d0_Base() throw();
    virtual ~S_00a981d0_Base() throw();
    int unk04;
};
struct S_00a981d0_Mem
{
    S_00a981d0_Mem() throw();
    char b[0x44];
};
struct S_00a981d0_Mid : S_00a981d0_Base
{
    int unk08, unk0c, unk10;
    S_00a981d0_Mem m14;
    unsigned char c58, c59, c5a, c5b;
    int unk5c, u60, u64, u68, u6c, u70, u74, u78, u7c, u80, u84, u88, u8c;
    __forceinline S_00a981d0_Mid() throw()
    {
        c58 = 0xff;
        c59 = 0xff;
        c5a = 0xff;
        c5b = 0;
        u60 = 0;
        u64 = 0;
        u68 = 0;
        u6c = 0;
        u70 = 0;
        u74 = 0;
        u78 = 0;
        u7c = 0;
        u80 = 0;
        u84 = 0;
        u88 = 0;
        u8c = 0;
    }
    virtual ~S_00a981d0_Mid() throw();
};
struct S_00a981d0_P
{
    int v;
    S_00a981d0_P()
    {
        v = 0;
    }
};
struct FUN_00a981d0 : S_00a981d0_Mid
{
    S_00a981d0_P u90;
    FUN_00a981d0() throw();
    virtual ~FUN_00a981d0() throw();
};
// Initializes the three base integer fields unk08, unk0c and unk10 to zero.
// @fnv 0x00a981d0
// pdb: NiPersistentSrcTextureRendererData::NiPersistentSrcTextureRendererData | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, caller_sim, high
FUN_00a981d0::FUN_00a981d0() throw()
{
    unk08 = 0;
    unk0c = 0;
    unk10 = 0;
}
