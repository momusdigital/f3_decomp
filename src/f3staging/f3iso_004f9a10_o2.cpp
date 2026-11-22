#include <new>
// src/f3staging/f3iso_004f9a10_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x004f9a10 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004f9a10 (community match, verified in this file)
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager _g_memoryManager;
class CF4840Saver
{
  public:
    void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    virtual void DeleteThis(bool bFree);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
extern __declspec(thread) int g_iF4A30AllocTag;
struct F4A30AllocTagScope
{
    int m_iSaved;

    F4A30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iF4A30AllocTag;
        g_iF4A30AllocTag = aiAllocationTag;
    }
    ~F4A30AllocTagScope()
    {
        g_iF4A30AllocTag = m_iSaved;
    }
};
struct SaverSized60_Layout_004f9a10 : CF4840Saver
{
    int unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
};
struct SaverSized80_Layout_004f9a10 : SaverSized60_Layout_004f9a10
{
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
};
struct SaverSized144_Layout_004f9a10 : SaverSized80_Layout_004f9a10
{
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC;
    int unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C;
    int unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C;
    int unk130, unk134, unk138, unk13C;
    int unk140;
};
struct SaverSized148_Layout_004f9a10 : SaverSized144_Layout_004f9a10
{
    int unk144;
};
struct SaverSized1A8_Layout_004f9a10 : SaverSized148_Layout_004f9a10
{
    int unk148, unk14C;
    int unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C;
    int unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C;
    int unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4;
};
struct SaverSized1B0_Layout_004f9a10 : SaverSized148_Layout_004f9a10
{
    int unk148, unk14C;
    int unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C;
    int unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C;
    int unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4;
    int unk1A8, unk1AC;
};

struct Saver3A_Layout_004f9a10 : SaverSized60_Layout_004f9a10
{
    Saver3A_Layout_004f9a10();
};
struct Saver16_Layout_004f9a10 : SaverSized80_Layout_004f9a10
{
    Saver16_Layout_004f9a10();
};
struct Saver3B_Layout_004f9a10 : SaverSized1B0_Layout_004f9a10
{
    Saver3B_Layout_004f9a10(void* pvParam);
};
struct Saver3C_Layout_004f9a10 : SaverSized1A8_Layout_004f9a10
{
    Saver3C_Layout_004f9a10(void* pvParam);
};
struct Saver3D_Layout_004f9a10 : SaverSized148_Layout_004f9a10
{
    Saver3D_Layout_004f9a10(void* pvParam);
};
struct Saver3E_Layout_004f9a10 : SaverSized144_Layout_004f9a10
{
    Saver3E_Layout_004f9a10(void* pvParam);
};
struct Saver3F_Layout_004f9a10 : SaverSized144_Layout_004f9a10
{
    Saver3F_Layout_004f9a10(void* pvParam);
};
struct Saver40_Layout_004f9a10 : SaverSized148_Layout_004f9a10
{
    Saver40_Layout_004f9a10(void* pvParam);
};

// pdb: TESObjectREFR::CreateReference | TESObjectREFR.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
CF4840Saver* __cdecl TESObjectREFR_CreateReference(unsigned int uiType, void* pvParam)
{
    F4A30AllocTagScope kScope(0x31);
    CF4840Saver* pkResult = 0;
    switch ((unsigned char)uiType)
    {
    case 0x3a:
        pkResult = new Saver3A_Layout_004f9a10;
        break;
    case 0x16:
        pkResult = new Saver16_Layout_004f9a10;
        break;
    case 0x3b:
        pkResult = new Saver3B_Layout_004f9a10(pvParam);
        break;
    case 0x3c:
        pkResult = new Saver3C_Layout_004f9a10(pvParam);
        break;
    case 0x3d:
        pkResult = new Saver3D_Layout_004f9a10(pvParam);
        break;
    case 0x3e:
        pkResult = new Saver3E_Layout_004f9a10(pvParam);
        break;
    case 0x3f:
        pkResult = new Saver3F_Layout_004f9a10(pvParam);
        break;
    case 0x40:
        pkResult = new Saver40_Layout_004f9a10(pvParam);
        break;
    }
    return pkResult;
}
