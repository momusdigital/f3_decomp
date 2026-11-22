#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D54270Bool
{
    char m_cBooleanValue;

    D54270Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct D54270Object
{
    virtual D54270Bool hkStdioStreamWriter_seekTellSupported() const;
};

// @fnv 0x00d54270
// pdb: hkStdioStreamWriter::seekTellSupported | hkStdioStreamWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
D54270Bool D54270Object::hkStdioStreamWriter_seekTellSupported() const
{
    return true;
}

// @fnv 0x00d54280
// pdb: hkpConvexListShape::getFirstKey | hkpConvexListShape.obj | fnv360_0822_retail, objrun_sim, low
int __cdecl FUN_00d54280()
{
    return 0;
}
