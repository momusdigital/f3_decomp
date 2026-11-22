// gamebryo2.2/corelibs/nianimation/niinterpolator.cpp: NiInterpolator, NiKeyBasedInterpolator (4 functions)
#include "f3_common.h"
#include "niinterpolator_decls.h"

// @fnv 0x00a56ff0
NiInterpolator::NiInterpolator() : m_fLastTime(DAT_01015f5c)
{
    m_pVTable = NiInterpolator_VTable;
}

struct FUN_00a57030_shell : public NiInterpolator
{
    void NiInterpolator_GetActiveTimeRange(float*, float*);
};

// @fnv 0x00a57030
// pdb: NiInterpolator::GetActiveTimeRange | NiInterpolator.obj | fnv360_0822_retail, objrun, high
// pdb params: fBeginKeyTime, fEndKeyTime
// pdb: NiInterpolator::GetActiveTimeRange | NiInterpolator.obj | fnv360_0822_retail, objrun, high (was: GetKeyTimeRange)
void FUN_00a57030_shell::NiInterpolator_GetActiveTimeRange(float* fBeginKeyTime, float* fEndKeyTime)
{
    *fBeginKeyTime = 0.0f;
    *fEndKeyTime = 0.0f;
}

extern void* NiInterpolator_VTable[];

template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    char _0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    char _1[2];
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};

// Reconstructed: 26-byte stdcall wrapper that grabs an object from a
// factory-like helper and calls one virtual on it (vtable slot 0xD0).
class NiAnimTarget
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
};

extern "C" void* __cdecl NiObject_Clone();

// @fnv 0x00a57050
NiAnimTarget* __stdcall FUN_00a57050(int a, int b)
{
    NiAnimTarget* p = (NiAnimTarget*)NiObject_Clone();
    p->v52();
    return p;
}

// @fnv 0x00a57020
// pdb: MagicTarget::CheckAbsorb | MagicTarget.obj | fnv360_0721_beta, objrun_sim, low
// pdb params: apCaster, apSpell, apActiveEffect, abReducedChance
char __stdcall FUN_00a57020(int a, int b, int c)
{
    return 0;
}

void __cdecl operator delete(void*, unsigned int);
