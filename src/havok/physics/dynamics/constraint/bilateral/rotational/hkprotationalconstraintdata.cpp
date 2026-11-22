#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/rotational/hkprotationalconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/rotational/hkprotationalconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpRotationalConstraintData.h"

// Writes 3 and 0x18 into out[1] and out[0] when flag is set, otherwise writes 0 into both.
// @fnv 0x00e3b520
void __stdcall FUN_00e3b520(char flag, int* out)
{
    if (flag)
    {
        out[1] = 3;
        out[0] = 0x18;
    }
    else
    {
        out[1] = 0;
        out[0] = 0;
    }
}

void* __cdecl FUN_00d21a60(void*, int, int);
struct FUN_00e3b500_cls : public hkpRotationalConstraintData
{
    void __thiscall FUN_00e3b500(int arg);
};
// @fnv 0x00e3b500
void __thiscall FUN_00e3b500_cls::FUN_00e3b500(int arg)
{
    FUN_00d21a60(&m_kBridgeAtoms, m_kBridgeAtoms.getSizeOfAllAtoms(), arg);
}

// Returns the constant value 16.
// @fnv 0x00e3b5b0
// pdb: hkpRotationalConstraintData::getType | hkpRotationalConstraintData.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00e3b5b0()
{
    return 16;
}

struct hkBool_ret
{
    char m_cBooleanValue;
    hkBool_ret()
    {}
    hkBool_ret(bool b) : m_cBooleanValue(b)
    {}
};

struct RotationHelper
{
    hkBool_ret __thiscall IsOrthonormal(float eps);
};

struct hkpRotationalConstraintDataHelper : public hkpRotationalConstraintData
{
    hkBool_ret __thiscall FUN_00e3b550();
};

// @fnv 0x00e3b550
// pdb: hkpRotationalConstraintData::isValid | hkpRotationalConstraintData.obj | fnv360_0822_retail, objrun_open, low
hkBool_ret __thiscall hkpRotationalConstraintDataHelper::FUN_00e3b550()
{
    float eps = 0.001f;
    return ((RotationHelper*)&m_kBridgeAtoms.m_kLocalRotations.m_kRotationA)->IsOrthonormal(eps).m_cBooleanValue &&
           ((RotationHelper*)&m_kBridgeAtoms.m_kLocalRotations.m_kRotationB)->IsOrthonormal(eps).m_cBooleanValue;
}

// @f3twin 0x00a71120 of 0x009e1b00
// pdb: hkpRotationalConstraintData::getRuntimeInfo | hkpRotationalConstraintData.obj | tesv_win, objrun_open, low
void __stdcall F3_FUN_00a71120(char flag, int* out)
{
    if (flag)
    {
        out[1] = 3;
        out[0] = 0x18;
    }
    else
    {
        out[1] = 0;
        out[0] = 0;
    }
}
