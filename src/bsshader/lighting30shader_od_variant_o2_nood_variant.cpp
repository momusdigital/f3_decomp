#include "f3_common.h"
// src/bsshader/lighting30shader_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/bsshader/lighting30shader_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsshader/lighting30shader_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/lighting30shader.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "lighting30shader_lighting30_factory_types.h"
#include "lighting30shader_packet.h"

struct S00bbe6b0_Mat
{
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};

struct __declspec(align(16)) S00bbe6b0_MatA16 : S00bbe6b0_Mat
{
};

__forceinline S00bbe6b0_Mat* S00bbe6b0_Identity(S00bbe6b0_Mat* m)
{
    m->_12 = m->_13 = m->_14 = m->_21 = m->_23 = m->_24 = m->_31 = m->_32 = m->_34 = m->_41 = m->_42 = m->_43 = 0.0f;
    m->_11 = m->_22 = m->_33 = m->_44 = 1.0f;
    return m;
}

struct S00bbe6b0_Setting
{
    int unk00;
    int unk04;
    bool bEnabled;
};

struct S00bbe6b0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00bbe6b0_Mat world;
};

struct S00bbe6b0_NodeRef
{
    char* base;
};

struct S00bbe6b0_Pair
{
    S00bbe6b0_Node* first;
    S00bbe6b0_Node* second;
};

struct S00bbe6b0_Src
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char count;
    unsigned char unk0a;
    unsigned char unk0b;
    S00bbe6b0_Pair* pair;
};

struct S00bbe6b0_Cam
{
    int unk00;
};

extern S00bbe6b0_Setting* DAT_01201098;
extern S00bbe6b0_Setting* DAT_012010b8;
extern S00bbe6b0_Mat DAT_01201170;
extern float DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f4754;
extern S00bbe6b0_Mat DAT_012012b0;

void FUN_00b799a0(S00bbe6b0_Mat* m, void* out);
S00bbe6b0_Mat* __stdcall FUN_00ee6de0(S00bbe6b0_Mat* out, const S00bbe6b0_Mat* a, const S00bbe6b0_Mat* b);
S00bbe6b0_Mat* __stdcall FUN_00ee6dd4(S00bbe6b0_Mat* out, const S00bbe6b0_Mat* in);
void* FUN_00ec44d0(void* dst, const void* src, unsigned int n);

struct S00bbe6b0_Renderer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    char* m_18;
    void FUN_00bbe6b0(S00bbe6b0_Src* src, unsigned int id, int flag, void* out);
};

// @f3 0x00b40d30 (community match, verified in this file)
union Matrix1918 { S00bbe6b0_Mat named; float m[4][4]; };
__forceinline Matrix1918* Identity1918(Matrix1918* m)
{
    float (*v)[4] = m->m;
    v[0][1] = v[0][2] = v[0][3] = v[1][0] = v[1][2] = v[1][3] = v[2][0] = v[2][1] = v[2][3] = v[3][0] = v[3][1] = v[3][2] = 0.0f;
    v[0][0] = v[1][1] = v[2][2] = v[3][3] = 1.0f;
    return m;
}
extern S00bbe6b0_Setting* DAT_01176e38;
extern S00bbe6b0_Setting* DAT_01176e58;
extern S00bbe6b0_Mat DAT_01176f10;
extern float DAT_0108f04c;
extern float DAT_0108f050;
extern float DAT_0108f054;
extern S00bbe6b0_Mat DAT_01177050;
void FUN_00873cd0(S00bbe6b0_Mat* m, void* out);
S00bbe6b0_Mat* __stdcall FUN_00c2082c(S00bbe6b0_Mat* out, const S00bbe6b0_Mat* a, const S00bbe6b0_Mat* b);
S00bbe6b0_Mat* __stdcall FUN_00c2083e(S00bbe6b0_Mat* out, const S00bbe6b0_Mat* in);
void* FUN_00bffa60(void* dst, const void* src, unsigned int n);
// pdb: Lighting30Shader::SetupGeometryConstants_ObjToCubemap | Lighting30Shader.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apRenderPass, auiCurrentPass, apSkin, aWorldTransform
void S00bbe6b0_Renderer::FUN_00bbe6b0(S00bbe6b0_Src* src, unsigned int id, int flag, void* out)
{
    __declspec(align(16)) Matrix1918 mat;
    __declspec(align(16)) Matrix1918 world;
    __declspec(align(16)) Matrix1918 res;

    if (DAT_01176e38->bEnabled)
    {
        S00bbe6b0_Pair* pair = src->pair;
        if (!pair || (src->count > 0 && *((unsigned char*)pair->first + 0xed)) || (id >= 0x1bd && id <= 0x1c3) ||
            (id >= 0x2d8 && id <= 0x2ef))
        {
            mat.named = *(S00bbe6b0_Mat*)(m_18 + 0x940);
            FUN_00c2083e(&mat.named, &mat.named);
            DAT_01176f10._11 = mat.named._11;
            DAT_01176f10._12 = mat.named._12;
            DAT_01176f10._13 = mat.named._13;
            DAT_01176f10._14 = mat.named._14;
            DAT_01176f10._21 = mat.named._21;
            DAT_01176f10._22 = mat.named._22;
            DAT_01176f10._23 = mat.named._23;
            DAT_01176f10._24 = mat.named._24;
            DAT_01176f10._31 = mat.named._31;
            DAT_01176f10._32 = mat.named._32;
            DAT_01176f10._33 = mat.named._33;
            DAT_01176f10._34 = mat.named._34;
            DAT_01176f10._41 = mat.named._41;
            DAT_01176f10._42 = mat.named._42;
            DAT_01176f10._43 = mat.named._43;
            DAT_01176f10._44 = mat.named._44;
        }
        else
        {
            if (src->count > 0)
            {
                Identity1918(&world);
                Identity1918(&mat);
                if (!flag)
                    FUN_00873cd0(&world.named, out);
                world.named._41 = *(volatile float*)&world.named._41 + DAT_0108f04c;
                world.named._42 = *(volatile float*)&world.named._42 + DAT_0108f050;
                world.named._43 = *(volatile float*)&world.named._43 + DAT_0108f054;
                FUN_00c2082c(&res.named, &world.named, &(id - 0x1c4 <= 3 ? pair->first : pair->second)->world);
                mat = res;
                FUN_00c2083e(&mat.named, &mat.named);
                FUN_00bffa60(&DAT_01176f10, &mat, 0x40);
            }
        }
    }
    if (DAT_01176e58->bEnabled && flag)
    {
        Identity1918(&mat);
        FUN_00bffa60(&DAT_01177050, &mat, 0x40);
    }
}

