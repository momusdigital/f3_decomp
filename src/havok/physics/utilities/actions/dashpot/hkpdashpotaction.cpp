#include "f3_common.h"
// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/dashpot/hkpdashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpDashpotAction.h"

#include <xmmintrin.h>
struct FUN_00d4d980_Class : hkpDashpotAction
{
    FUN_00d4d980_Class* FUN_00d4d980(int entityA, int entityB, int name);
};
// Calls FUN_00cf4d80, sets m_fSpringStrength and m_fMotorDamping from globals, sets the vtable pointer, zeroes both m_kPoint entries and returns this.
// @f3 0x009da570 (community match, verified in this file)
extern float FUN_00dbe8fc;
extern float FUN_00db75c8;
extern int FUN_00e80268;
struct DashBaseCall7
{
    void FUN_00979e40(int entityA, int entityB, int name);
};
// pdb: hkpDashpotAction::hkpDashpotAction | hkpDashpotAction.obj | fnv360_0822_retail, call_seq, high
// pdb params: entityA, entityB, userData
FUN_00d4d980_Class* FUN_00d4d980_Class::FUN_00d4d980(int entityA, int entityB, int name)
{
    reinterpret_cast<DashBaseCall7*>(this)->FUN_00979e40(entityA, entityB, name);
    m_fSpringStrength = FUN_00dbe8fc;
    *reinterpret_cast<int**>(this) = &FUN_00e80268;
    m_fMotorDamping = FUN_00db75c8;
    m_kPoint[0].w = 0.0f;
    m_kPoint[0].z = 0.0f;
    m_kPoint[0].y = 0.0f;
    m_kPoint[0].x = 0.0f;
    m_kPoint[1].w = 0.0f;
    m_kPoint[1].z = 0.0f;
    m_kPoint[1].y = 0.0f;
    m_kPoint[1].x = 0.0f;
    return this;
}


// FUN_00d4d9d0 - hkpDashpotAction clone-style factory (Havok)

__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

unsigned long g_tlsIdx = 0;
