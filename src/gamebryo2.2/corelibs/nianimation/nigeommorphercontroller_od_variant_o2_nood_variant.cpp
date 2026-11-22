#include "f3_common.h"
// src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp
// NiGeomMorpherController: morph-target interpolator management.
#include "nigeommorphercontroller.h"

#include <string.h>
#include <stdio.h>
char* FUN_00a7d330(char*);
char* FUN_00a7d510(const char*, unsigned int);
void* NiMalloc(unsigned int);
extern char* DAT_011f3728;
extern NiRTTI DAT_011f3e58, DAT_011f3738;
struct StrArr
{
    int u00;
    char** data;
    unsigned short capacity, size, filled, grow;
    void SetSize(unsigned int);
    __declspec(noinline) void SetAt(unsigned int, char*&);
    __forceinline void append(char*& value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + grow);
        SetAt(index, value);
    }
};
void StrArr::SetAt(unsigned int index, char*& value)
{
    if (index >= size)
    {
        size = (unsigned short)(index + 1);
        if (value)
            ++filled;
    }
    else if (value)
    {
        if (!data[index])
            ++filled;
    }
    else if (data[index])
        filled += 0xffff;
    data[index] = value;
}
struct InterpolatorView : NiInterpolator
{
    virtual const NiRTTI* GetRTTI() const;
    __forceinline bool IsKindOfType(const NiRTTI* wanted)
    {
        const NiRTTI* rtti = GetRTTI();
        while (rtti)
        {
            if (rtti == wanted)
                return true;
            rtti = rtti->m_pkBaseRTTI;
        }
        return false;
    }
};
struct BlendValueView : InterpolatorView
{
    int u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    float value;
};
struct FloatValueView : InterpolatorView
{
    float value;
};
struct MorphViewer : NiGeomMorpherController
{
    void FUN_00a3b700(StrArr*);
};
// @f3 0x008b56f0 (community match, verified in this file)
extern char* DAT_01091f78;
extern NiRTTI DAT_010926a8, DAT_01091f90;

// pdb: NiGeomMorpherController::GetViewerStrings | NiGeomMorpherController.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void MorphViewer::FUN_00a3b700(StrArr* array)
{
    union HeaderScratch
    {
        char* text;
        unsigned int count;
    } header;
    {
        header.text = FUN_00a7d330(DAT_01091f78);
        array->append(header.text);
        header.text = FUN_00a7d510("NumTargets",
                                   m_spMorphTargetData.m_pObject ? m_spMorphTargetData.m_pObject->m_uiNumTargets : 0);
        array->append(header.text);
        header.text =
            FUN_00a7d510("NumVertsPerTarget",
                         m_spMorphTargetData.m_pObject ? m_spMorphTargetData.m_pObject->m_uiNumVertsPerTarget : 0);
        array->append(header.text);
    }
    header.count = m_spMorphTargetData.m_pObject ? m_spMorphTargetData.m_pObject->m_uiNumTargets : 0;
    float value;
    unsigned int i = 0;
    if (i < header.count)
    {
        unsigned int offset = 0;
        do
        {
            NiMorphData::MorphTarget* target =
                i < m_spMorphTargetData.m_pObject->m_uiNumTargets
                    ? reinterpret_cast<NiMorphData::MorphTarget*>(
                          reinterpret_cast<char*>(m_spMorphTargetData.m_pObject->m_pMorphTargets) + offset)
                    : 0;
            InterpolatorView* interpolator = (InterpolatorView*)GetInterpolator(i);
            char buffer[256];
            if (interpolator)
            {
                BlendValueView* blend =
                    interpolator->IsKindOfType(&DAT_010926a8) ? static_cast<BlendValueView*>(interpolator) : 0;
                FloatValueView* scalar =
                    interpolator->IsKindOfType(&DAT_01091f90) ? static_cast<FloatValueView*>(interpolator) : 0;
                if (blend)
                {
                    value = blend->value;
                    sprintf(buffer, "%d %s = %0.2f", i, static_cast<const char*>(target->GetName()), (double)value);
                }
                else if (scalar)
                {
                    value = scalar->value;
                    sprintf(buffer, "%d %s = %0.2f", i, static_cast<const char*>(target->GetName()), (double)value);
                }
                else
                    goto no_val;
            }
            else
            {
            no_val:
                sprintf(buffer, "%d %s", i, static_cast<const char*>(target->GetName()));
            }
            unsigned int bytes = strlen(buffer) + 3;
            char* copy = static_cast<char*>(NiMalloc(bytes));
            strcpy_s(copy, bytes, buffer);
            unsigned int index = array->size;
            if (index >= array->capacity)
                array->SetSize(index + array->grow);
            if (index >= array->size)
            {
                array->size = index + 1;
                if (copy)
                    ++array->filled;
            }
            else if (copy)
            {
                if (!array->data[index])
                    ++array->filled;
            }
            else if (array->data[index])
                array->filled += 0xffff;
            array->data[index] = copy;
            ++i;
            offset += sizeof(NiMorphData::MorphTarget);
        } while (i < header.count);
    }
}

