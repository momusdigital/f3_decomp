#include "f3_common.h"
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpConvexTranslateShape.h"

#include <xmmintrin.h>

struct __declspec(align(16)) hkVector4DD60
{
    __m128 m_vComponents;
    void setAdd4(const hkVector4DD60& a, const hkVector4DD60& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
};

// @f3 0x009b4ae0 (community match, verified in this file)
namespace f3m_009b4ae0 {
namespace f3m_009b4ae0 {

struct __declspec(align(16)) KeyBuffer
{
    unsigned short m_key;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct Initialiser
{
    int __thiscall init(const void* a, KeyBuffer* buf, int zero);
};

typedef int (__cdecl* Handler)(const void* a, void* b, void* c, KeyBuffer* buf);

struct Table
{
    Handler m_handlers[101];
    int FUN_009b4ae0(const void* a, void* b, void* c) const;
};

}

int f3m_009b4ae0::Table::FUN_009b4ae0(const void* a, void* b, void* c) const
{
    f3m_009b4ae0::KeyBuffer buf;
    int result = ((f3m_009b4ae0::Initialiser*)c)->init(a, &buf, 0);
    if (result == 0)
    {
        unsigned short key = buf.m_key;
        do
        {
            if (key <= 100)
            {
                result = m_handlers[key](a, b, c, &buf);
                key = buf.m_key;
            }
        } while (result == 0);
    }
    else
    {
        result = 1;
    }
    return result;
}
}   // namespace f3m_009b4ae0


#include <string.h>
struct __declspec(align(16)) MyVec
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};

struct __declspec(align(16)) MyTransform
{
    MyVec col0;
    MyVec col1;
    MyVec col2;
    MyVec col3;
};
