#ifndef FNV_IMAGESPACESHADERBLUR_H
#define FNV_IMAGESPACESHADERBLUR_H
#include "f3_common.h"
#include "imagespaceshaderblur_blur_reload_support.h"

class ImageSpaceBlurShader : public ImageSpaceEffectShader
{
  public:
    virtual void SetupShader();
};
// @fnv 0x00b8e330
// pdb: ImageSpaceShaderBrightPassBlur3::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceBlurShader::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "3";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR3T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "3";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR3";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

class ImageSpaceShaderVariant4 : public ImageSpaceEffectShader
{
  public:
    ImageSpaceShaderVariant4();
    virtual void SetupShader();
};
// @fnv 0x00b8e460
// pdb: ImageSpaceShaderBrightPassBlur3::`scalar deleting destructor' | ImageSpaceManager.obj | fnv360_0721_beta, objrun, medium
ImageSpaceShaderVariant4::ImageSpaceShaderVariant4()
{
    pTextures.SetSize(3);
}
// @fnv 0x00b8e4d0
// pdb: ImageSpaceShaderBrightPassBlur5::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceShaderVariant4::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "5";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR5T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "5";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR5";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

class ImageSpaceShaderVariant5 : public ImageSpaceEffectShader
{
  public:
    ImageSpaceShaderVariant5();
    virtual void SetupShader();
};
// @fnv 0x00b8e600
// pdb: ImageSpaceShaderBrightPassBlur5::`scalar deleting destructor' | ImageSpaceManager.obj | fnv360_0721_beta, objrun, medium
ImageSpaceShaderVariant5::ImageSpaceShaderVariant5()
{
    pTextures.SetSize(3);
}
// @fnv 0x00b8e670
// pdb: ImageSpaceShaderBrightPassBlur7::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceShaderVariant5::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "7";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR7T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "7";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR7";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

class ImageSpaceShaderVariant6 : public ImageSpaceEffectShader
{
  public:
    ImageSpaceShaderVariant6();
    virtual void SetupShader();
};
// @fnv 0x00b8e7a0
// pdb: ImageSpaceShaderBrightPassBlur7::`scalar deleting destructor' | ImageSpaceManager.obj | fnv360_0721_beta, objrun, medium
ImageSpaceShaderVariant6::ImageSpaceShaderVariant6()
{
    pTextures.SetSize(3);
}
// @fnv 0x00b8e810
// pdb: ImageSpaceShaderBrightPassBlur9::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceShaderVariant6::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "9";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR9T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "9";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR9";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

class ImageSpaceShaderVariant1 : public ImageSpaceEffectShader
{
  public:
    ImageSpaceShaderVariant1();
    virtual void SetupShader();
};
// @fnv 0x00b8e940
// pdb: ImageSpaceShaderBrightPassBlur9::`scalar deleting destructor' | ImageSpaceManager.obj | fnv360_0721_beta, objrun, medium
ImageSpaceShaderVariant1::ImageSpaceShaderVariant1()
{
    pTextures.SetSize(3);
}
// @fnv 0x00b8e9b0
// pdb: ImageSpaceShaderBrightPassBlur11::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceShaderVariant1::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "11";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR11T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "11";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR11";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

class ImageSpaceShaderVariant2 : public ImageSpaceEffectShader
{
  public:
    ImageSpaceShaderVariant2();
    virtual void SetupShader();
};
// @fnv 0x00b8eae0
// pdb: ImageSpaceShaderBrightPassBlur11::`scalar deleting destructor' | ImageSpaceManager.obj | fnv360_0721_beta, objrun, medium
ImageSpaceShaderVariant2::ImageSpaceShaderVariant2()
{
    pTextures.SetSize(3);
}
// @fnv 0x00b8eb50
// pdb: ImageSpaceShaderBrightPassBlur13::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceShaderVariant2::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "13";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR13T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "13";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR13";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

class ImageSpaceShaderVariant3 : public ImageSpaceEffectShader
{
  public:
    ImageSpaceShaderVariant3();
    virtual void SetupShader();
};
// @fnv 0x00b8ec80
// pdb: ImageSpaceShaderBrightPassBlur13::`scalar deleting destructor' | ImageSpaceManager.obj | fnv360_0721_beta, objrun, medium
ImageSpaceShaderVariant3::ImageSpaceShaderVariant3()
{
    pTextures.SetSize(3);
}
// @fnv 0x00b8ecf0
// pdb: ImageSpaceShaderBrightPassBlur15::ReloadShaders | ImageSpaceManager.obj | fnv360_0822_retail, ustr, medium
void ImageSpaceShaderVariant3::SetupShader()
{
    BSShaderManager::BSShaderMacro vertexShader;
    vertexShader.pcPath = "imagespace\\1x\\v\\base.v.hlsl";
    vertexShader.kMacros[0].Name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].Definition, 0, 68);
    BSShaderManager::BSShaderMacro pixelShader;
    const char* shaderName;
    if (INISettingCollection::Display::bDoTestHDR.uValue.b)
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2_TEST.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "15";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR15T";
    }
    else
    {
        BSShaderManager::BSShaderMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\blur2.p.hlsl";
        shader.kMacros[0].Name = "BRIGHTPASS";
        shader.kMacros[0].Definition = "";
        shader.kMacros[1].Name = "TEXTAP";
        shader.kMacros[1].Definition = "15";
        shader.kMacros[2].Name = 0;
        fnv_zlib_memset(&shader.kMacros[2].Definition, 0, 52);
        pixelShader = shader;
        shaderName = "BPBLUR15";
    }
    InitShaders(vertexShader, pixelShader, shaderName, "vs_1_1", "ps_2_a");
    SetupPasses();
}

#endif
