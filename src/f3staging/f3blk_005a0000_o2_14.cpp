#include <string.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005acde0 (community match, verified in this file)
namespace f3m_005acde0 {
class TESPackageLocation
{
public:
    signed char type;
    int value;
    int ref;

    void SetType(int t);
    int GetValue();
    void SetValue(int v);
    int GetRef();
    void SetRef(int v);
    int GetTypeOneRef();
    void SetTypeOneRef(int v);
    int GetTypeFourRef();
    void SetTypeFourRef(int v);
    int GetTypeFiveRef();
    void SetTypeFiveRef(int v);

    void PackageLocation_Copy(TESPackageLocation* src, bool force);
};

void TESPackageLocation::SetType(int t)
{
    if (type == t)
        return;
    type = (signed char)t;
    switch (t)
    {
    case 1:
        value = 0;
        ref = 0;
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        ref = 0;
        break;
    }
}

int TESPackageLocation::GetValue()
{
    if (type == -1 || type == 1)
        return 0;
    return value;
}

void TESPackageLocation::SetValue(int v)
{
    if (type == -1 || type == 1)
        return;
    value = v;
}

int TESPackageLocation::GetRef()
{
    if (type == 0)
        return ref;
    return 0;
}

void TESPackageLocation::SetRef(int v)
{
    ref = v;
    type = 0;
}

int TESPackageLocation::GetTypeOneRef()
{
    if (type == 1)
        return ref;
    return 0;
}

void TESPackageLocation::SetTypeOneRef(int v)
{
    ref = v;
    type = 1;
}

int TESPackageLocation::GetTypeFourRef()
{
    if (type == 4)
        return ref;
    return 0;
}

void TESPackageLocation::SetTypeFourRef(int v)
{
    ref = v;
    type = 4;
}

int TESPackageLocation::GetTypeFiveRef()
{
    if (type == 5)
        return ref;
    return 0;
}

void TESPackageLocation::SetTypeFiveRef(int v)
{
    ref = v;
    type = 5;
}

// pdb: PackageLocation::Copy | PackageLocation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap) + skyrim(call_gap_sim), high
void TESPackageLocation::PackageLocation_Copy(TESPackageLocation* src, bool force)
{
    if (!src)
        return;
    if (!force && src->type == -1)
        return;
    SetType(src->type);
    switch (type)
    {
    case 0:
        SetValue(src->GetValue());
        SetRef(src->GetRef());
        break;
    case 1:
        SetTypeOneRef(src->GetTypeOneRef());
        break;
    case 4:
        SetValue(src->GetValue());
        SetTypeFourRef(src->GetTypeFourRef());
        break;
    case 5:
        SetValue(src->GetValue());
        SetTypeFiveRef(src->GetTypeFiveRef());
        break;
    case 2:
    case 3:
    case 7:
        SetValue(src->GetValue());
        break;
    case 6:
        SetValue(src->GetValue());
        break;
    }
}
}   // namespace f3m_005acde0
