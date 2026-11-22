#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" const char* const g_011f444c_arg1;

// @fnv 0x00a5fc00
// pdb: bhkConstraint::GetRTTI | MissileProjectile.obj | fnv360_0822_retail, objrun_open, low
const char* const* __cdecl FUN_00a5fc00()
{
    return &g_011f444c_arg1;
}

struct RgbaColor
{
    bool __thiscall FUN_004a4cc0(RgbaColor const&) const;
};
struct Helper
{
    char _0[4];
    RgbaColor _4;
};
bool __cdecl AreFloatsEqual(Helper const*, Helper const*);
// Returns false if AreFloatsEqual(a, b) is false, otherwise returns the result of a->_4.FUN_004a4cc0(b->_4).
// @fnv 0x00a299c0
// pdb: NiColorKey::Equal | NiColorKey.obj | tesv_win, hash, low
bool __cdecl CompareHelpers(Helper const* apLeft, Helper const* apRight)
{
    if (!AreFloatsEqual(apLeft, apRight))
        return false;
    return apLeft->_4.FUN_004a4cc0(apRight->_4);
}

struct RendererData
{
    virtual ~RendererData();
};
struct NiTexture
{
    int _00[9];
    RendererData* m_pTextureRendererData;
    int _28[2];
    void* Destroy(unsigned int);
};
void __fastcall NiTexture_RemoveTextureFromList(void*);
void __fastcall DestroyFogProperty(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109b944;
// @fnv 0x00a60120
// pdb: NiTexture::`scalar deleting destructor' | NiSourceTexture.obj | tesv_win, vtable_prefix, medium
void* NiTexture::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109b944;
    delete m_pTextureRendererData;
    NiTexture_RemoveTextureFromList(this);
    DestroyFogProperty(this);
    if (flags & 1)
        _delete(this, 0x30);
    return this;
}
