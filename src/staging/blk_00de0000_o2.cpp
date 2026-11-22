#include "f3_common.h"
// src/staging/blk_00de0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00cb0c00_class
{
    void __thiscall FUN_00cb0c00();
};

struct hkReferencedObject
{
    void removeReference();
};

extern int DAT_010cc2fc;

extern "C" void* DAT_010305a8;
extern "C" void* DAT_010e222c;

struct FUN_00cb0a70_class
{
    void __thiscall FUN_00cb0a70(int);
};

namespace fnv_00dfd970 {
struct hkReferencedObject
{
    void removeReference();
};

}  // namespace fnv_00dfd970

extern int DAT_010d3cc0;

// @fnv 0x00dfde30
// pdb: hkStringMap<hkTypeInfo const *,hkContainerHeapAllocator>::isValid | hkBuiltinTypeRegistry.obj | fnv360_0822_debug, objrun_open, low
// pdb params: i
void FUN_00dfde30(void* apObject)
{
    if (apObject)
    {
        *(unsigned short*)((char*)apObject + 6) = 1;
        *(int**)(char*)apObject = &DAT_010d3cc0;
    }
}

extern int DAT_010cc2fc;

extern int DAT_010cc2fc;

struct FUN_00cb0a70
{
    void __thiscall m_00cb0a70(int);
};

extern int DAT_010cc2fc;

namespace fnv_00dffbe0 {
struct FUN_00cb0a70_class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    void FUN_00cb0a70(int a);
};

extern int DAT_010cc2fc;

}  // namespace fnv_00dffbe0

extern int DAT_010df89c;

extern int DAT_010dff44;

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dfc230
// pdb: cleanupLoadedObjecthkpDefaultConvexListFilter | hkpCollideReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfc230(void** p)
{
    ((VTable0*)(*(void***)(p)))[0](p, 0);
}

// @fnv 0x00dfc250
void __cdecl FUN_00dfc250(void** p)
{
    void(__thiscall * fn)(void*, int) = *(void(__thiscall**)(void*, int)) * p;
    fn(p, 0);
}

extern int DAT_010e00cc;

extern int DAT_010e00dc;

// @fnv 0x00dfc380
// pdb: cleanupLoadedObjecthkpBoxShape | hkpCollideReflections.obj | tesv_win, objopen_prop, low
void __cdecl FUN_00dfc380(void** p)
{
    (**(void(__thiscall**)(void*, int))(*p))(p, 0);
}

extern int DAT_010e04ac;

// @fnv 0x00dfc500
// pdb: cleanupLoadedObjecthkpConvexVerticesConnectivity | hkpCollideReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfc500(void* p)
{
    ((void(__thiscall*)(void*, int)) * (void**)*(void**)p)(p, 0);
}

extern int DAT_010e0654;

extern int DAT_0102e368;

extern int DAT_010d0a64;

// @fnv 0x00dfc700
// pdb: cleanupLoadedObjecthkpSerializedDisplayMarker | hkpSerializedDisplayMarkerClass.obj | fnv360_0721_beta, objrun_open, low
void __cdecl FUN_00dfc700(void* p)
{
    ((void(__thiscall*)(void*, int))(*(void**)*(void**)p))(p, 0);
}

extern int DAT_010d0aac;

extern int DAT_010e11ec;

extern int DAT_010da04c;

// @fnv 0x00dfcad0
void __cdecl FUN_00dfcad0(void** p)
{
    ((void(__thiscall*)(void*, int))(**(void***)(p)))(p, 0);
}

extern int DAT_010d0b3c;

extern void* DAT_010d37e4;

extern int DAT_010d0be4;

typedef int(__thiscall* VFunc0)(void*, int);
// @fnv 0x00dfcd10
// pdb: cleanupLoadedObjecthkpBoxMotion | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
int __cdecl FUN_00dfcd10(void* self)
{
    return ((VFunc0*)*(void**)self)[0](self, 0);
}

extern int DAT_010c91ec;

extern int DAT_010d0cd4;

struct FUN_00dfd7a0_vt
{
    virtual void v0(int);
    virtual void v1(int);
};
// @fnv 0x00dfd7a0
void __cdecl FUN_00dfd7a0(FUN_00dfd7a0_vt* p)
{
    p->v0(0);
}

struct FUN_00dfd940_vt
{
    virtual void __thiscall FUN_00dfd940(int);
};
// @fnv 0x00dfd940
void __cdecl FUN_00dfd940(FUN_00dfd940_vt* p)
{
    p->FUN_00dfd940(0);
}

extern int DAT_010e351c;

extern "C" void* DAT_010e352c;

extern int DAT_010e3e5c;

extern int DAT_010e5474;

struct FUN_00dfe430_class
{
    virtual int __thiscall FUN_00cb0a70(int a);
};
// @fnv 0x00dfe430
// pdb: cleanupLoadedObjecthkpLinearParametricCurve | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
int __cdecl FUN_00dfe430(FUN_00dfe430_class* p)
{
    return p->FUN_00cb0a70(0);
}

extern int DAT_010e56d4;

extern int DAT_010e57a4;

struct FUN_00dfe670_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dfe670
// pdb: cleanupLoadedObjecthkpSingleShapeContainer | hkpCollideReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfe670(FUN_00dfe670_vt* p)
{
    p->m_iWordAt00(0);
}

extern int DAT_010e58c8;

extern int DAT_010e59ac;

// @fnv 0x00dfeaa0
void __cdecl FUN_00dfeaa0(void** p)
{
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(p))[0])(p, 0);
}

extern int DAT_010e5b68;

extern int DAT_010e5b4c;

extern int DAT_010e5bfc;

extern int DAT_010e5d94;

extern int DAT_010e5da8;

// @fnv 0x00dfecb0
void __cdecl FUN_00dfecb0(int* p)
{
    ((void(__thiscall*)(void*, int))(*(int*)p[0]))(p, 0);
}

extern int DAT_010e5e9c;

extern int DAT_010e60c4;

extern int DAT_010e62a4;

extern int DAT_010e6394;

extern int DAT_010e66fc;

extern int DAT_010e676c;

extern int DAT_010cc2fc;

typedef void(__thiscall* VTableFn)(void*, int);
// @fnv 0x00dff3c0
void __cdecl FUN_00dff3c0(void* p)
{
    ((VTableFn*)*(void**)p)[0](p, 0);
}

extern int DAT_010e75cc;

extern int DAT_010e75dc;

extern int DAT_010e75ec;

typedef int(__thiscall* Vfn)(void*, int);

extern int DAT_010e7c24;

extern int DAT_010cc0d8;

extern int DAT_010d3838;

extern int DAT_010cb798;

extern void* DAT_010e80b4;

struct FUN_00de87c0_class
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    void SwapFields();
};

struct FUN_00de8550_t
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
// @f3 0x00619570 (community match, verified in this file)
struct FUN_00620d30_cls
{
    bool bEnabled;
    void __thiscall FUN_00620d30(FUN_00de8550_t* pObject);
};
extern FUN_00620d30_cls* DAT_01075b24;

// pdb: Interface::ToggleSafeZone | Interface.obj | fnv360_0822_retail, call_gap, low
// pdb params: abForceSetTo
void __cdecl FUN_00de8550(FUN_00de8550_t* pObject, int iValue)
{
    if (DAT_01075b24 && DAT_01075b24->bEnabled)
        DAT_01075b24->FUN_00620d30(pObject);
}


typedef void(__thiscall* Vfn0)(void*, int);
// @fnv 0x00df6460
// pdb: cleanupLoadedObjecthkpRagdollLimitsData | hkpRagdollLimitsDataClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00df6460(void** p)
{
    ((Vfn0) * (void**)*p)(p, 0);
}

typedef int(__thiscall* VFunc_00dfb270)(void*, int);
// @fnv 0x00dfb270
int __cdecl FUN_00dfb270(void* p)
{
    return ((VFunc_00dfb270*)*(void**)p)[0](p, 0);
}

typedef void(__thiscall* VFunc00dfb3f0)(void*, int);
// @fnv 0x00dfb3f0
// pdb: finishLoadedObjecthkpRackAndPinionConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfb3f0(void** p)
{
    ((VFunc00dfb3f0) * ((void***)p)[0])(p, 0);
}

struct FUN_00dfb450_vt
{
    virtual void m0(int);
};
// @fnv 0x00dfb450
void __cdecl FUN_00dfb450(FUN_00dfb450_vt* p)
{
    p->m0(0);
}

struct FUN_00dfb890_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfb890
// pdb: cleanupLoadedObjecthkpPoweredChainData | hkpDynamicshkpPoweredChainDataReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00dfb890(FUN_00dfb890_vt* p)
{
    p->v0(0);
}

typedef void(__thiscall* VTable0_00dfba70)(void*, int);
// @fnv 0x00dfba70
void __cdecl FUN_00dfba70(void* p)
{
    ((VTable0_00dfba70**)(void**)p)[0][0](p, 0);
}

typedef void(__thiscall* VFn0)(void*, int);
// @fnv 0x00dfbb30
void __cdecl FUN_00dfbb30(void* p)
{
    VFn0 f = (VFn0) * (void**)*(void**)p;
    f(p, 0);
}

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
// @fnv 0x00dfbc20
// pdb: cleanupLoadedObjecthkpSerializedSubTrack1nInfo | hkpUtilitiesReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfbc20(S_00d49310_Lock* self)
{
    self->S_00d49310_Lock::~S_00d49310_Lock();
}

struct S_00dfb720_Elem
{
    ~S_00dfb720_Elem();
};

// @fnv 0x00dfbca0
// pdb: hkMemoryAllocator::_bufFree<hkpConstraintChainInstance *> | hkpPoweredChainMapperClass.obj | fnv360_0822_debug, objrun_open, low
// pdb params: p, numElem
void __cdecl FUN_00dfbca0(S_00dfb720_Elem* p)
{
    p->S_00dfb720_Elem::~S_00dfb720_Elem();
}

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dfbcd0
// pdb: cleanupLoadedObjecthkpBallSocketChainDataConstraintInfo | hkpBallSocketChainDataClass.obj | fnv360_0822_debug, objopen_prop, low
void __cdecl FUN_00dfbcd0(void* p)
{
    ((VTable0*)*(void**)p)[0](p, 0);
}

typedef void(__thiscall* VFunc1)(void*, int);
// @fnv 0x00dfbdd0
// pdb: cleanupLoadedObjecthkpBallSocketChainData | hkpDynamicsReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00dfbdd0(void* p)
{
    ((VFunc1*)*(void**)p)[0](p, 0);
}

struct FUN_00dfc040_vt
{
    virtual void __thiscall FUN_00dfc040(int);
};
// @fnv 0x00dfc040
// pdb: cleanupLoadedObjecthkpSimpleMeshShape | hkpSimpleMeshShapeClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dfc040(FUN_00dfc040_vt* p)
{
    p->FUN_00dfc040(0);
}

typedef void(__thiscall* V00dfc790)(void*, int);
// @fnv 0x00dfc790
void __cdecl FUN_00dfc790(void** p)
{
    ((V00dfc790)(*(void**)*p))(p, 0);
}

// @fnv 0x00dfc7f0
void __cdecl FUN_00dfc7f0(int* p)
{
    int* vt = (int*)(*(void**)p);
    ((void(__thiscall*)(void*, int))(*vt))((void*)p, 0);
}

// @fnv 0x00dfc8d0
void __cdecl FUN_00dfc8d0(void** p)
{
    void** vt = (void**)*p;
    reinterpret_cast<VTable0>(vt[0])(p, 0);
}

typedef void(__thiscall* Vfn_00dfcb60)(void*, int);
// @fnv 0x00dfcb60
// pdb: cleanupLoadedObjecthkpConstrainedSystemFilter | hkpConstrainedSystemFilterClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dfcb60(void* p)
{
    Vfn_00dfcb60 fn = ((Vfn_00dfcb60*)*(void**)p)[0];
    fn(p, 0);
}

struct FUN_00dfcc30_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfcc30
// pdb: cleanupLoadedObjecthkpRigidBody | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfcc30(FUN_00dfcc30_vt* p)
{
    p->v0(0);
}

struct FUN_00dfce00_vt
{
    virtual void __thiscall v0(int);
};
// @fnv 0x00dfce00
// pdb: cleanupLoadedObjecthkpCharacterMotion | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfce00(FUN_00dfce00_vt* p)
{
    p->v0(0);
}

struct FUN_00dfcf00_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dfcf00
// pdb: cleanupLoadedObjecthkpMaxSizeMotion | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfcf00(FUN_00dfcf00_vt* p)
{
    p->m_iWordAt00(0);
}

struct FUN_00dfd240_vt
{
    virtual void __thiscall FUN_00dfd240(int);
};
// @fnv 0x00dfd240
// pdb: cleanupLoadedObjecthkpWorld | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfd240(FUN_00dfd240_vt* p)
{
    p->FUN_00dfd240(0);
}

typedef void(__thiscall* Vfn_00dfd620)(void*, int);
// @fnv 0x00dfd620
void __cdecl FUN_00dfd620(void* p)
{
    ((Vfn_00dfd620*)*(void**)p)[0](p, 0);
}

// @fnv 0x00dfda70
void __cdecl FUN_00dfda70(void* p)
{
    void(__thiscall * fn)(void*, int) = ((void(__thiscall*)(void*, int)) * (*(void***)p));
    fn(p, 0);
}

// @fnv 0x00dfdb00
// pdb: cleanupLoadedObjecthkpLinearParametricCurve | hkpLinearParametricCurveClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dfdb00(void* p)
{
    ((VFunc0*)*(void**)p)[0](p, 0);
}

struct FUN_00dfdb20_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfdb20
// pdb: cleanupLoadedObjecthkpCallbackConstraintMotor | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfdb20(FUN_00dfdb20_vt* p)
{
    p->v0(0);
}

namespace fnv_00dfdfa0 {
struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
}  // namespace fnv_00dfdfa0

typedef void(__thiscall* Vfn_00dfe270)(void*, int);
// @fnv 0x00dfe270
void __cdecl FUN_00dfe270(void* p)
{
    Vfn_00dfe270 fn = *(Vfn_00dfe270*)*(void**)p;
    fn(p, 0);
}

// @fnv 0x00dfe2b0
void __cdecl FUN_00dfe2b0(void* p)
{
    ((void(__thiscall*)(void*, int)) * (*(void***)p))(p, 0);
}

struct FUN_00dfe320_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dfe320
void __cdecl FUN_00dfe320(FUN_00dfe320_vt* p)
{
    p->m_iWordAt00(0);
}

extern int DAT_010e56d4;

struct FUN_00dfe4e0_vt
{
    virtual void m0(int);
};
// @fnv 0x00dfe4e0
// pdb: cleanupLoadedObjecthkpPointToPlaneConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfe4e0(FUN_00dfe4e0_vt* p)
{
    p->m0(0);
}

// @fnv 0x00dfe590
// pdb: cleanupLoadedObjecthkpPrismaticConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfe590(void* p)
{
    void(__thiscall * fn)(void*, int);
    fn = (void(__thiscall*)(void*, int)) * ((void**)*((void**)p));
    fn(p, 0);
}

// @fnv 0x00dfeb40
void __cdecl FUN_00dfeb40(void* p)
{
    void(__thiscall * fn)(void*, int);
    fn = *reinterpret_cast<void(__thiscall**)(void*, int)>(*reinterpret_cast<void**>(p));
    fn(p, 0);
}

// @fnv 0x00dfebb0
void __cdecl FUN_00dfebb0(void** p)
{
    ((void(__thiscall*)(void*, int))(**(void****)p))(p, 0);
}

typedef void(__thiscall* Vfn0)(void*, int);
// @fnv 0x00dfebf0
// pdb: finishLoadedObjecthkpShapeInfo | hkpCollideReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfebf0(void* p)
{
    ((Vfn0*)*(void**)p)[0](p, 0);
}

struct FUN_00dfec30_vt
{
    virtual void m0(int);
};
// @fnv 0x00dfec30
// pdb: cleanupLoadedObjecthkpRemoveTerminalsMoppModifier | hkpRemoveTerminalsMoppModifierClass.obj | fnv360_1110_retail, objrun, medium
void __cdecl FUN_00dfec30(FUN_00dfec30_vt* p)
{
    p->m0(0);
}

struct FUN_00dfecf0_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfecf0
// pdb: cleanupLoadedObjecthkpGroupFilter | hkpGroupFilterClass.obj | fnv360_0721_beta, objrun_open, low
void __cdecl FUN_00dfecf0(FUN_00dfecf0_vt* p)
{
    p->v0(0);
}

struct FUN_00dfede0_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfede0
// pdb: cleanupLoadedObjecthkpGroupFilter | hkpGroupFilterClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dfede0(FUN_00dfede0_vt* p)
{
    p->v0(0);
}

typedef int(__thiscall* Vfn_00dfeec0)(void*, int);
// @fnv 0x00dfeec0
int __cdecl FUN_00dfeec0(void* p)
{
    return ((Vfn_00dfeec0*)*(void**)p)[0](p, 0);
}

struct FUN_00dfef00_vt
{
    virtual void __thiscall m0(int);
};
// @fnv 0x00dfef00
// pdb: cleanupLoadedObjecthkpConvexVerticesConnectivity | hkpConvexVerticesConnectivityClass.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: cleanupLoadedObjecthkpMoppBvTreeShape)
void __cdecl FUN_00dfef00(FUN_00dfef00_vt* p)
{
    p->m0(0);
}

struct FUN_00dff1d0_vt
{
    virtual void m0(int);
};
// @fnv 0x00dff1d0
// pdb: cleanupLoadedObjecthkpCollisionFilterList | hkpCollisionFilterListClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dff1d0(FUN_00dff1d0_vt* p)
{
    p->m0(0);
}

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dff300
void __cdecl FUN_00dff300(void** p)
{
    ((VTable0)(*(void**)*p))(p, 0);
}

struct FUN_00dff370_vt
{
    virtual void __thiscall FUN_00dff370(int);
};
// @fnv 0x00dff370
void __cdecl FUN_00dff370(FUN_00dff370_vt* p)
{
    p->FUN_00dff370(0);
}

typedef void(__thiscall* VTable0)(void*, int);

typedef void(__thiscall* VTable0)(void*, int);

extern int DAT_010cc2fc;

typedef void(__thiscall* VTblFn0)(void*, int);

typedef void(__thiscall* VTableFn)(void*, int);

typedef void(__thiscall* Vfn0)(void*, int);

extern int DAT_0102e388;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00de10e0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    void* m_p08;
    int m_0c;
    int m_10;

    FUN_00de10e0_cls* FUN_00de10e0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

extern float DAT_01017d00;

struct FUN_00de3050
{
    float m_iWordAt00;
    FUN_00de3050();
};

// @fnv 0x00de3050
// pdb: hkpConvexRadiusBuilder::hkpConvexRadiusBuilderEnvironment::hkpConvexRadiusBuilderEnvironment | hkpConvexRadiusBuilder.obj | fnv360_0822_retail, objrun_prop, low
FUN_00de3050::FUN_00de3050() : m_iWordAt00(DAT_01017d00)
{}

extern int DAT_010d8214;

class FUN_00de3060
{
  public:
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int m_0c;

    FUN_00de3060(const unsigned int* src);
};

// Initializes the object: sets m_06 to 1, points m_00 at DAT_010d8214, copies *src into m_08 and zeroes m_0c.
// @fnv 0x00de3060
// pdb: hkpConvexRadiusBuilder::hkpConvexRadiusBuilder | hkpConvexRadiusBuilder.obj | fnv360_0822_retail, uvref, medium
// pdb params: env
FUN_00de3060::FUN_00de3060(const unsigned int* src)
{
    m_06 = 1;
    m_00 = (void*)&DAT_010d8214;
    m_08 = *src;
    m_0c = 0;
}

class FUN_00de3090_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_00de3090();
};

// @fnv 0x00de3090
// pdb: hkpConvexRadiusBuilder::resetCurrentRawGeometry | hkpConvexRadiusBuilder.obj | fnv360_0822_debug, objrun, medium
void FUN_00de3090_cls::FUN_00de3090()
{
    m_0c = 0;
}

namespace fnv_00de43e0 {
class BDE43E0Allocator
{
  public:
    virtual void vfn00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct BDE43E0Memory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BDE43E0Allocator* m_pHeapAllocator;

    BDE43E0Allocator& heap()
    {
        return *m_pHeapAllocator;
    }
};

BDE43E0Memory* __cdecl FUN_00c85750();

class BDE43E0ReferencedObject
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        BDE43E0ReferencedObject* pkObject =
            static_cast<BDE43E0ReferencedObject*>(FUN_00c85750()->heap().AllocateMemoryBlock(uiSize));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObject;
    }
    static void operator delete(void* pvMem);

    BDE43E0ReferencedObject() throw() : m_sReferenceCount(1)
    {}
    virtual ~BDE43E0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

template <class T> struct BDE43E0Array
{
    BDE43E0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class BDE43E0Shape : public BDE43E0ReferencedObject
{
  public:
    BDE43E0Shape() throw()
    {}
    virtual ~BDE43E0Shape();

    BDE43E0Array<void*> m_kChildList;
};

}  // namespace fnv_00de43e0

struct Quad16
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};

class FUN_00de48a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    Quad16 GetQuad16();
};

// @fnv 0x00de48a0
Quad16 FUN_00de48a0_cls::GetQuad16()
{
    Quad16 r;
    r.x = m_60;
    r.y = m_64;
    r.z = m_68;
    r.w = m_6c;
    return r;
}

// CopyStatsTo
// thiscall member of a game object class: copies the 16 bytes of the
// trailing "m_stats" block (this+0x70..0x7c) into the caller's output
// buffer and returns. One stack argument (the output pointer), callee-cleared.

struct StatsBlock
{
    int m_iStat00;
    int m_iStat04;
    int m_iStat08;
    int m_iStat0c;
};

struct GameObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    StatsBlock m_stats;

    void CopyStatsTo(int* __restrict pOut);
};

// @fnv 0x00de48c0
void GameObject::CopyStatsTo(int* __restrict pOut)
{
    pOut[0] = m_stats.m_iStat00;
    pOut[1] = m_stats.m_iStat04;
    pOut[2] = m_stats.m_iStat08;
    pOut[3] = m_stats.m_iStat0c;
}

class FNVFloatGetter_cls
{
  public:
    int unk00;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    float m_90;
    float FUN_00de48e0();
};

// @fnv 0x00de48e0
// pdb: hkDisplaySemiCircle::getThetaMin | hkDisplaySemiCircle.obj | fnv360_0822_retail, objrun_open, low
float FNVFloatGetter_cls::FUN_00de48e0()
{
    return m_90;
}

struct FUN_00de48f0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    float m_94;
    float FUN_00de48f0();
};

// @fnv 0x00de48f0
// pdb: hkDisplaySemiCircle::getThetaMax | hkDisplaySemiCircle.obj | fnv360_0822_retail, objrun_open, low
float FUN_00de48f0_cls::FUN_00de48f0()
{
    return m_94;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    float value;
    float FUN_00de4900();
};
// @fnv 0x00de4900
// pdb: hkDisplaySemiCircle::getRadius | hkDisplaySemiCircle.obj | fnv360_0822_retail, objrun_open, low
float CpuObject::FUN_00de4900()
{
    return value;
}

struct FUN_00de4910_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int FUN_00de4910();
};

// @fnv 0x00de4910
// pdb: TESWorldSpace::GetMusicType | TESWorldSpace.obj | fnv360_0822_retail, call_seq, medium
int FUN_00de4910_cls::FUN_00de4910()
{
    return m_9c;
}

// CopyVec4ToBuffer: copies the 16-byte vector stored at this+0x80 into the
// 4-int block pointed to by the stack parameter.

struct Vec4
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_w;
};

struct FUN_00de4920_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    Vec4 m_v80;
    void CopyVec4ToBuffer(int* volatile pOut);
};

// Copies the four components of m_v80 into the four ints pointed to by pOut, reading the last two as one 64-bit value.
// @fnv 0x00de4920
// pdb: hkDisplaySemiCircle::getCenter | hkDisplaySemiCircle.obj | fnv360_0822_retail, objopen_prop, medium
void FUN_00de4920_cls::CopyVec4ToBuffer(int* volatile pOut)
{
    int* out = pOut;
    out[0] = m_v80.m_uiX;
    out[1] = m_v80.m_uiY;
    __int64 tail = *(__int64*)&m_v80.m_uiZ;
    int* t = (int*)&tail;
    out[2] = t[0];
    out[3] = t[1];
}

namespace fnv_00de4e00 {
struct CpuObject
{
    char* FUN_00de4e00();
};
// @fnv 0x00de4e00
// pdb: ProcessLists::GetAliveActorList | ProcessLists.obj | fnv360_0822_retail, call_seq, low
char* CpuObject::FUN_00de4e00()
{
    return reinterpret_cast<char*>(this) + 128;
}
}  // namespace fnv_00de4e00

struct FUN_00de4e10_cls
{
    int unk00;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;

    char* FUN_00de4e10();
};

// @fnv 0x00de4e10
// pdb: hkDisplayPlane::getExtents | hkDisplayPlane.obj | fnv360_0822_retail, objrun_open, low
char* FUN_00de4e10_cls::FUN_00de4e10()
{
    return (char*)this + 0x90;
}

struct FUN_00de5320_vec4
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_w;
};

class FUN_00de5320_cls
{
  public:
    FUN_00de5320_vec4 GetVec4At70();
};

// @fnv 0x00de5320
FUN_00de5320_vec4 FUN_00de5320_cls::GetVec4At70()
{
    FUN_00de5320_vec4* src = (FUN_00de5320_vec4*)((char*)this + 0x70);
    return *src;
}

namespace fnv_00de5340 {
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    float value;
    float FUN_00de5340();
};
// @fnv 0x00de5340
// pdb: TESObjectTREE::GetRustleSpeed | TESObjectTREE.obj | fnv360_0822_retail, vtable, medium
float CpuObject::FUN_00de5340()
{
    return value;
}
}  // namespace fnv_00de5340

struct FUN_00de5350_cls
{
    int unk00;
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
    int unk80;
    float m_84;
    float FUN_00de5350();
};
// @fnv 0x00de5350
// pdb: TESObjectTREE::GetRockSpeed | TESObjectTREE.obj | fnv360_0822_retail, vtable, low
float FUN_00de5350_cls::FUN_00de5350()
{
    return m_84;
}

class FUN_00de5360_cls
{
  public:
    void* FUN_00de5360();
};

// @fnv 0x00de5360
// pdb: DistantLODShaderProperty::GetClampNI | DistantLODShaderProperty.obj | fnv360_0822_debug, objrun_open, low
void* FUN_00de5360_cls::FUN_00de5360()
{
    return *(void**)((char*)this + 0x80);
}

extern void* DAT_01269ce8;

// @fnv 0x00de8150
int __cdecl FUN_00de8150()
{
    return reinterpret_cast<int>(&DAT_01269ce8);
}

extern int DAT_01269d18;

// @fnv 0x00de8170
int* __cdecl FUN_00de8170()
{
    return &DAT_01269d18;
}

extern int DAT_01269d48;

// @fnv 0x00de8190
void* FUN_00de8190()
{
    return &DAT_01269d48;
}

extern int g_unk01269d78;

// @fnv 0x00de81d0
// pdb: getVtablehkpConvexVerticesConnectivity | hkpConvexVerticesConnectivityClass.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00de81d0()
{
    return &g_unk01269d78;
}

struct CpuOpaque;
extern CpuOpaque DAT_01269da8;
// @fnv 0x00de81f0
CpuOpaque* __cdecl FUN_00de81f0()
{
    return &DAT_01269da8;
}

extern int DAT_01269dd8;

// @fnv 0x00de8210
void* __cdecl FUN_00de8210()
{
    return &DAT_01269dd8;
}

extern int g_unk01269e08;

// @fnv 0x00de8230
int* FUN_00de8230()
{
    return &g_unk01269e08;
}

struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00de8250
GlobalObject* __cdecl FUN_00de8250()
{
    return &g_global;
}

struct CpuOpaque;
extern CpuOpaque DAT_01269e68;
// @fnv 0x00de8270
CpuOpaque* __cdecl FUN_00de8270()
{
    return &DAT_01269e68;
}

extern int g_unk01269e98;

// @fnv 0x00de8290
void* __cdecl FUN_00de8290()
{
    return &g_unk01269e98;
}

extern int g_unk01269ec8;

// @fnv 0x00de82b0
void* __cdecl FUN_00de82b0()
{
    return &g_unk01269ec8;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269ef8;
// @fnv 0x00de82d0
// pdb: LowProcess::GetTarget | HighProcess.obj | fnv360_0822_retail, vtable, high
GlobalObjectO2_00d472a0* __cdecl FUN_00de82d0()
{
    return &g_01269ef8;
}

extern int DAT_01269f28;

// @fnv 0x00de82f0
// pdb: BSMultiBound::GetRTTI | BSMultiBound.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
void* __cdecl BSMultiBound_GetRTTI()
{
    return &DAT_01269f28;
}

extern int g_unkGlobal01269f58;

// @fnv 0x00de8310
// pdb: BSMultiBoundRoom::GetRTTI | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
void* __cdecl FUN_00de8310()
{
    return &g_unkGlobal01269f58;
}

extern int DAT_01269f88;

// @fnv 0x00de8330
// pdb: MessageHandler::GetWarningFileName | MessageHandler.obj | fnv360_0822_retail, call_gap_sim, low
void* __cdecl FUN_00de8330()
{
    return &DAT_01269f88;
}

// FUN_00de8350 : a one-line function - getter
extern int g_target_00de8350;
// @fnv 0x00de8350
void* FUN_00de8350()
{
    return &g_target_00de8350;
}

extern int DAT_0126a018;

// @fnv 0x00de8390
// pdb: BSXFlags::GetRTTI | BSXFlags.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00de8390()
{
    return &DAT_0126a018;
}

extern int DAT_0126a048;
// @fnv 0x00de83b0
// pdb: BSReference::GetRTTI | BSStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
int* BSReference_GetRTTI()
{
    return &DAT_0126a048;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126a078;
// @fnv 0x00de83d0
// pdb: BSNodeReferences::GetRTTI | BSStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
CpuOpaque* __cdecl BSNodeReferences_GetRTTI()
{
    return &DAT_0126a078;
}

extern int DAT_0126a0a8;

// @fnv 0x00de83f0
// pdb: BSValueNode::GetRTTI | BSValueNode.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00de83f0()
{
    return &DAT_0126a0a8;
}

extern int DAT_0126a0d8;

// @fnv 0x00de8410
// pdb: BSRangeNode::GetRTTI | BSRangeNode.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
void* __cdecl BSRangeNode_GetRTTI()
{
    return &DAT_0126a0d8;
}

extern int DAT_0126a108;
// @fnv 0x00de8430
// pdb: BSMultiBoundNode::GetRTTI | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00de8430()
{
    return &DAT_0126a108;
}

extern int DAT_0126a138;

// @fnv 0x00de8450
// pdb: BSWindModifier::GetRTTI | BSWindModifier.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
void* __cdecl BSWindModifier_GetRTTI()
{
    return &DAT_0126a138;
}

extern int DAT_0126a168;

// @fnv 0x00de8470
// pdb: BSBlastNode::GetRTTI | BSBlastNode.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00de8470()
{
    return &DAT_0126a168;
}

extern int DAT_0126a198;

// @fnv 0x00de8490
// pdb: BSDebrisNode::GetRTTI | BSDebrisNode.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00de8490()
{
    return &DAT_0126a198;
}

extern int DAT_0126a1c8;

// @fnv 0x00de84b0
// pdb: BSDamageStage::GetRTTI | BSDamageStage1.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00de84b0()
{
    return &DAT_0126a1c8;
}

extern FUN_00de87c0_class DAT_0126a1f8;

// @fnv 0x00de84d0
// pdb: BSMultiBoundShape::GetRTTI | BSMultiBoundShape.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
FUN_00de87c0_class* __cdecl BSMultiBoundShape_GetRTTI()
{
    return &DAT_0126a1f8;
}

// FUN_00de84f0 : returns the address of a global data object.
// Original: mov eax, offset DAT_0126a228 ; ret
extern int DAT_0126a228;

// @fnv 0x00de84f0
// pdb: BSPortalSharedNode::GetRTTI | BSPortal.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00de84f0()
{
    return &DAT_0126a228;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126a258;
// @fnv 0x00de8510
// pdb: BSParticleSystemManager::GetRTTI | BSParticleSystemManager.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
CpuOpaque* __cdecl BSParticleSystemManager_GetRTTI()
{
    return &DAT_0126a258;
}

extern int g_0126a288;

// @fnv 0x00de8530
// pdb: BSSceneGraph::GetRTTI | BSSceneGraph.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
int* __cdecl BSSceneGraph_GetRTTI()
{
    return &g_0126a288;
}

extern int DAT_0126a378;

// @fnv 0x00de8750
// pdb: NiBSBoneLODController::GetRTTI | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00de8750()
{
    return &DAT_0126a378;
}

extern int g_unk126a3a8;

// @fnv 0x00de8770
// pdb: BSFurnitureMarker::GetRTTI | BSFurnitureMarker.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00de8770()
{
    return &g_unk126a3a8;
}

class FUN_00de8780_cls
{
  public:
    float m_fValues[16];

    unsigned char* HasNoNaNOrInf(unsigned char* pResult);
};

// Checks all 16 floats for NaN or infinity via exponent bits and writes 0 to pResult if any is found, otherwise 1.
// @f3 0x0096c3c0 (community match, verified in this file)
unsigned char* FUN_00de8780_cls::HasNoNaNOrInf(unsigned char* pResult)
{
    for (int i = 0; i < 12; ++i)
    {
        float f = m_fValues[i];
        unsigned int bits = *(unsigned int*)&f;
        if ((bits & 0x7f800000) == 0x7f800000)
        {
            *pResult = 0;
            return pResult;
        }
    }
    *pResult = 1;
    return pResult;
}


struct JacRow
{
    float x;
    float y;
    float z;
    float w;
};
struct JacBlock
{
    int unk00;
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
    JacRow rows[6];
};

// @fnv 0x00df06a0
// pdb: hkPoweredChain_DisableMotorInMatrixRow_ThisConstraint | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: motorsState, isNotLastRow, mtxDiag, mtxNextOffdiag
void __cdecl ResetJacobianRows(unsigned char* flags, bool both, JacBlock* pJacA, JacBlock* pJacB)
{
    if (*flags)
    {
        if (*flags & 3)
        {
            for (int i = 0; i < 6; i++)
                pJacA->rows[i].x = 0.0f;
            pJacA->rows[3].x = 1.0f;
            if (both)
            {
                for (int i = 0; i < 6; i++)
                    pJacB->rows[i].x = 0.0f;
            }
        }
        if (*flags & 0xc)
        {
            for (int i = 0; i < 6; i++)
                pJacA->rows[i].y = 0.0f;
            pJacA->rows[4].y = 1.0f;
            if (both)
            {
                for (int i = 0; i < 6; i++)
                    pJacB->rows[i].y = 0.0f;
            }
        }
        if (*flags & 0x30)
        {
            for (int i = 0; i < 6; i++)
                pJacA->rows[i].z = 0.0f;
            pJacA->rows[5].z = 1.0f;
            if (both)
            {
                for (int i = 0; i < 6; i++)
                    pJacB->rows[i].z = 0.0f;
            }
        }
    }
}

struct DF25D0State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char m_ucFlags;
};

struct DF25D0Owner
{
    int unk00;
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
    DF25D0State* m_pkState;
};

void __cdecl FUN_00cb3c80(void* pkItem, DF25D0Owner* pkOwner);

// @f3 0x00a7ccf0 (community match, verified in this file)
// pdb: addConstraintToCriticalLockedIsland | hkpPhysicsCommandMachine.obj | tesv_win, call_seq, medium
static __declspec(noinline) void __cdecl SetOwnerStateFlags(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType)
{
    FUN_00cb3c80(pkItem, pkOwner);
    (*(DF25D0State**)((char*)pkOwner + 0x28))->m_ucFlags |= m_ucEntryType;
}


// Caller so the file-static helper is emitted with its register calling convention.
void DF25D0Attach(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType)
{
    SetOwnerStateFlags(pkItem, pkOwner, m_ucEntryType);
    SetOwnerStateFlags(pkOwner, pkOwner, m_ucEntryType);
}

struct Handler_cls
{
    void __thiscall Handle(int value);
};

extern int g_0126a430;

// @fnv 0x00df6490
// pdb: BSBound::GetRTTI | BSBound.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00df6490()
{
    return &g_0126a430;
}

extern int DAT_0126a478;

// @fnv 0x00df64b0
// pdb: BSPSysMultiTargetEmitterCtlr::GetRTTI | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00df64b0()
{
    return &DAT_0126a478;
}

extern "C" int DAT_0126a4a8;

// @fnv 0x00df64c0
// pdb: BSScissorTriShape::GetRTTI | BSScissorTriShape.obj | fnv360_0822_retail, udata, medium, conflict (skyrim: BSLODTriShape::GetRTTI)
extern "C" void* __cdecl FUN_00df64c0()
{
    return &DAT_0126a4a8;
}

struct FUN_00df7a60_class
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int unk14;
    int unk18;
    void* m_p1c;

    void __thiscall TESForm_SetTemporary();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* value, long increment);

// @f3 0x004553b0 (community match, verified in this file)
struct C004552a0
{
    void __thiscall TESForm_RemoveFromDataStructures();
};
struct C006dcd50
{
    void __thiscall FUN_006dcd50(void* p, int v);
};
struct C006ce6f0
{
    void __thiscall FUN_006ce6f0(void* p);
};
extern C006dcd50* DAT_01079ca4;
extern C006ce6f0* DAT_01079858;

// pdb: TESForm::SetTemporary | TESForm.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim) + skyrim(call_gap_sim), high
void __thiscall FUN_00df7a60_class::TESForm_SetTemporary()
{
    ((C004552a0*)this)->TESForm_RemoveFromDataStructures();
    if (DAT_01079ca4)
        DAT_01079ca4->FUN_006dcd50(this, 0);
    if (DAT_01079858)
        DAT_01079858->FUN_006ce6f0(this);
    unk08 |= 0x4000;
}


extern float DAT_010dbb3c;
extern float DAT_0104da48;
struct ParserContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, result44;
    int __thiscall FUN_00e63af0(int, void*, float*);
};
struct FloatPair
{
    float first, second;
    int __thiscall TraverseNode(ParserContext*, int, int*, ParserContext**);
    int __thiscall FUN_00dfb040(ParserContext*, int, int*, ParserContext**);
};
// Initialises first/second from constants, calls ctx->FUN_00e63af0 and, if it returns 1, delegates to TraverseNode; otherwise returns 2.
// @fnv 0x00dfb040
// pdb: hkpWingedEdge::findVisibilityBoundaryEdges | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, callee_sim, low, conflict (skyrim: hkWingedEdge::findVisibilityBoundaryEdges)
// pdb params: initialTriangle, pointOfView, chainLength, edgeChain
int __thiscall FloatPair::FUN_00dfb040(ParserContext* ctx, int input, int* outA, ParserContext** outB)
{
    double initial = DAT_010dbb3c;
    *outB = 0;
    *outA = 0;
    first = (float)initial;
    second = DAT_0104da48;
    ctx->result44 = ctx->FUN_00e63af0(input, this, &second);
    if (ctx->result44 == 1)
        return TraverseNode(ctx, input, outA, outB);
    return 2;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126a5f8;
// @fnv 0x00dfb260
// pdb: BSNiNode::GetRTTI | BSNiNode.obj | fnv360_0822_retail, vtable + skyrim(objopen_prop), high
CpuOpaque* __cdecl BSNiNode_GetRTTI()
{
    return &DAT_0126a5f8;
}

extern int g_unk0126aa18;

// @fnv 0x00dfb280
// pdb: BSPSysStripUpdateModifier::GetRTTI | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00dfb280()
{
    return &g_unk0126aa18;
}

extern int DAT_0126aac0;

// @fnv 0x00dfb360
// pdb: BSPSysSimpleColorModifier::GetRTTI | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00dfb360()
{
    return &DAT_0126aac0;
}

extern int DAT_0126aaf0;

// @fnv 0x00dfb380
// pdb: BSMultiBoundCapsule::GetRTTI | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00dfb380()
{
    return &DAT_0126aaf0;
}

extern int DAT_0126abe0;

// @fnv 0x00dfb3c0
// pdb: BSMasterParticleSystem::GetRTTI | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00dfb3c0(void)
{
    return &DAT_0126abe0;
}

extern unsigned char DAT_0126ac10;

// @fnv 0x00dfb420
// pdb: BSWArray::GetRTTI | BSWArray.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00dfb420()
{
    return &DAT_0126ac10;
}

extern "C" int DAT_0126ac58;
// @fnv 0x00dfb480
// pdb: BSPSysArrayEmitter::GetRTTI | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00dfb480(void)
{
    return &DAT_0126ac58;
}

extern int DAT_0126acd0;

// @fnv 0x00dfb4d0
// pdb: BSParentVelocityModifier::GetRTTI | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_00dfb4d0()
{
    return reinterpret_cast<int>(&DAT_0126acd0);
}

extern int DAT_0126ad00;
// @fnv 0x00dfb4f0
// pdb: BSDecalPlacementVectorExtraData::GetRTTI | BSDecalPVExtraData.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
void* __cdecl BSDecalPlacementVectorExtraData_GetRTTI()
{
    return &DAT_0126ad00;
}

extern int DAT_0126ad30;

// @fnv 0x00dfb510
// pdb: BSTextureData::GetRTTI | BSTextureData.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00dfb510()
{
    return &DAT_0126ad30;
}

extern void* DAT_0126ad60;

// @fnv 0x00dfb540
// pdb: NiParticles::IsParticlesGeom | NiParticleSystem.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: NiParticleSystem::GetRTTI)
int __cdecl FUN_00dfb540()
{
    return reinterpret_cast<int>(&DAT_0126ad60);
}

class DFB550Object
{
  public:
    virtual ~DFB550Object();
};

// @fnv 0x00dfb550
void FUN_00dfb550(DFB550Object* pkObject)
{
    pkObject->~DFB550Object();
}

extern int DAT_0126ad90;

// @fnv 0x00dfb560
// pdb: NiPSysEmitterCtlr::GetRTTI | NiPSysEmitterCtlr.obj | fnv360_0822_retail, objrun, medium
int* __cdecl FUN_00dfb560()
{
    return &DAT_0126ad90;
}

inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

struct DFB570FinishFlag
{
    int m_bFinishing;
};

class DFB570Object
{
  public:
    DFB570Object(DFB570FinishFlag flag)
    {
        if (flag.m_bFinishing)
            finishInit();
    }

    virtual void vfunc00();

    void finishInit();
};

extern int DAT_010ddc5c;

// @fnv 0x00dfb590
// pdb: NiPSysMeshEmitter::GetRTTI | NiPSysMeshEmitter.obj | fnv360_0822_retail, objrun_sim, low
void* __cdecl FUN_00dfb590()
{
    return &DAT_010ddc5c;
}

extern int DAT_0126add8;

// @fnv 0x00dfb860
// pdb: NiPSysCylinderEmitter::GetRTTI | NiPSysCylinderEmitter.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00dfb860()
{
    return &DAT_0126add8;
}

extern unsigned char g_fnvDat0126ae08;

// @fnv 0x00dfb880
// pdb: NiPSysSphereEmitter::GetRTTI | NiPSysSphereEmitter.obj | fnv360_0822_retail, udata + bridge(vtable|objopen_prop) + skyrim(objrun_open), high
void* NiPSysSphereEmitter_GetRTTI()
{
    return &g_fnvDat0126ae08;
}

// NiPSysBoxEmitter_GetRTTI : a one-line function - getter
extern int g_target_00dfb8a0;
// @fnv 0x00dfb8a0
// pdb: NiPSysBoxEmitter::GetRTTI | NiPSysBoxEmitter.obj | fnv360_0822_retail, udata + bridge(vtable|objopen_prop) + skyrim(objrun_open), high
void* NiPSysBoxEmitter_GetRTTI()
{
    return &g_target_00dfb8a0;
}

// ResetVTable -- installs a fixed vtable on an object and, when the second
// argument is set, runs the object's update step afterwards.

extern int DAT_010de0ec;  // vtable that gets installed

extern int DAT_010de0ec;

// @fnv 0x00dfb8d0
// pdb: NiPSysMeshUpdateModifier::GetRTTI | NiPSysMeshUpdateModifier.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: BSPSysHavokUpdateModifier::GetRTTI)
void* FUN_00dfb8d0()
{
    return &DAT_010de0ec;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126ae80;
// @fnv 0x00dfb920
// pdb: NiPSysRotationModifier::GetRTTI | NiPSysRotationModifier.obj | fnv360_0822_retail, objrun_sim, low
CpuOpaque* __cdecl FUN_00dfb920()
{
    return &DAT_0126ae80;
}

extern int DAT_0126aeb0;

// @fnv 0x00dfb940
// pdb: NiMeshParticleSystem::GetRTTI | NiMeshParticleSystem.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: NiPSysEmitter::GetRTTI)
void* __cdecl FUN_00dfb940()
{
    return &DAT_0126aeb0;
}

extern int DAT_0126aee0;

// @fnv 0x00dfb970
// pdb: NiPSysEmitter::GetRTTI | NiPSysEmitter.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00dfb970()
{
    return &DAT_0126aee0;
}

struct FUN_00ce5370_cls
{
    void __thiscall FUN_00ce5370();
};

// @fnv 0x00dfb980
// pdb: hkArrayBase<hkpSimulationIsland *>::_insertAt | hkpSaveContactPointsUtil.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: cleanupLoadedObjecthkpSerializedTrack1nInfo)
// pdb params: alloc, index, p, numtoinsert
void __cdecl FUN_00dfb980(FUN_00ce5370_cls* p)
{
    p->FUN_00ce5370();
}

extern int DAT_0126af10;

// @fnv 0x00dfb990
// pdb: NiPSysGravityModifier::GetRTTI | NiPSysGravityModifier.obj | fnv360_0721_retail, objrun_open, low
int* __cdecl FUN_00dfb990()
{
    return &DAT_0126af10;
}

// FUN_00dfb9a0 : __cdecl, 13 bytes
//   mov ecx, dword ptr [esp + 4]
//   mov eax, dword ptr [ecx]
//   mov edx, dword ptr [eax]
//   push 0
//   call edx
//   ret
// Calls vtable slot 0 of the object passed in, with the argument 0.

struct FUN_00dfb9a0_cls
{
    virtual int v00(int a);
};

// @fnv 0x00dfb9a0
int __cdecl FUN_00dfb9a0(FUN_00dfb9a0_cls* pObj)
{
    return pObj->v00(0);
}

extern int DAT_0126af40;
// @fnv 0x00dfb9b0
// pdb: NiPSysSpawnModifier::GetRTTI | NiPSysSpawnModifier.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00dfb9b0(void)
{
    return &DAT_0126af40;
}

extern int DAT_0126af88;
// @fnv 0x00dfba40
// pdb: NiPSysData::GetRTTI | NiPSysData.obj | fnv360_0822_retail, objrun_sim, low, conflict (bridge: NiParticlesData::GetActiveVertexCount)
int* FUN_00dfba40()
{
    return &DAT_0126af88;
}

extern int g_unk0126afb8;

// @fnv 0x00dfbaa0
// pdb: BSStripParticleSystem::GetRTTI | BSStripParticleSystem.obj | fnv360_0822_retail, objrun_open, medium
void* __cdecl FUN_00dfbaa0()
{
    return &g_unk0126afb8;
}

namespace fnv_00dfbac0 {
struct FreeAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct FreeHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FreeAllocator* m_pAllocator;
};

FreeHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00dfbac0

struct CpuOpaque;
extern CpuOpaque DAT_0126b000;
// @fnv 0x00dfbb20
// pdb: BSStripPSysData::GetRTTI | BSStripPSysData.obj | fnv360_0822_retail, objrun + bridge(vtable|objrun) + skyrim(objrun_open), high
CpuOpaque* __cdecl BSStripPSysData_GetRTTI()
{
    return &DAT_0126b000;
}

extern int DAT_0126b030;

// @fnv 0x00dfbb40
// pdb: NiPSysModifier::GetRTTI | NiPSysModifier.obj | fnv360_1110_retail, objrun + skyrim(objrun_open), high
void* __cdecl NiPSysModifier_GetRTTI()
{
    return &DAT_0126b030;
}

// FUN_00dfbb50 : installs the class vtable into the object and, when the
// second argument is non-zero, tail-calls the routine at FUN_00e35050 with
// the object as 'this'.

extern int DAT_010de90c;

extern int DAT_010de90c;

// @fnv 0x00dfbb70
// pdb: NiPSysVolumeEmitter::GetRTTI | NiPSysVolumeEmitter.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* __cdecl NiPSysVolumeEmitter_GetRTTI()
{
    return &DAT_010de90c;
}

extern "C" int DAT_0126b078;

// @fnv 0x00dfbc10
// pdb: NiPSysModifierCtlr::GetRTTI | NiPSysModifierCtlr.obj | fnv360_0822_retail, udata, high
extern "C" void* __cdecl FUN_00dfbc10()
{
    return &DAT_0126b078;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126b0a8;
// @fnv 0x00dfbc50
// pdb: NiPSysUpdateTask::GetRTTI | NiPSysUpdateTask.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
CpuOpaque* __cdecl NiPSysUpdateTask_GetRTTI()
{
    return &DAT_0126b0a8;
}

extern int DAT_0126b0d8;

// @fnv 0x00dfbc60
// pdb: NiPSysVortexFieldModifier::GetRTTI | NiPSysVortexFieldModifier.obj | fnv360_0822_retail, objrun, medium
int* __cdecl FUN_00dfbc60()
{
    return &DAT_0126b0d8;
}

namespace fnv_00dfbcc0 {
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00dfbcc0
// pdb: NiPSysUpdateCtlr::GetRTTI | NiPSysUpdateCtlr.obj | fnv360_0822_retail, objrun_open, low
GlobalObject* __cdecl FUN_00dfbcc0()
{
    return &g_global;
}
}  // namespace fnv_00dfbcc0

extern int DAT_0126b138;

// @fnv 0x00dfbce0
// pdb: NiPSysTurbulenceFieldModifier::GetRTTI | NiPSysTurbulenceFieldModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(objrun_open), high
void* __cdecl NiPSysTurbulenceFieldModifier_GetRTTI()
{
    return &DAT_0126b138;
}

// InitVTable : __cdecl initializer for an object with several vtable slots.
// The first vtable is installed, a flag byte at +9 is cleared when the flag is
// set, then the second vtable is installed along with two secondary vtables
// at +0x24 and +0x1c. Finally the flag byte is set to 2 when the flag is set.

extern int DAT_010dec04;
extern int DAT_010dec3c;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;

extern int DAT_010dec3c;

// @fnv 0x00dfbd30
// pdb: NiPSysSphericalCollider::GetRTTI | NiPSysSphericalCollider.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(objrun_sim), high
void* __cdecl NiPSysSphericalCollider_GetRTTI()
{
    return &DAT_010dec3c;
}

extern int DAT_0126b180;

// @fnv 0x00dfbdc0
// pdb: NiPSysResetOnLoopCtlr::GetRTTI | NiPSysResetOnLoopCtlr.obj | fnv360_0822_retail, objrun, medium
void* __cdecl FUN_00dfbdc0()
{
    return &DAT_0126b180;
}

extern int DAT_0126b1b0;

// @fnv 0x00dfbde0
// pdb: NiPSysRadialFieldModifier::GetRTTI | NiPSysRadialFieldModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* __cdecl NiPSysRadialFieldModifier_GetRTTI()
{
    return &DAT_0126b1b0;
}

extern int DAT_0126b1f8;

// @fnv 0x00dfbe90
// pdb: NiPSysPositionModifier::GetRTTI | NiPSysPositionModifier.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00dfbe90()
{
    return &DAT_0126b1f8;
}

extern unsigned char DAT_0126b228;

// @fnv 0x00dfbeb0
// pdb: NiPSysPlanarCollider::GetRTTI | NiPSysPlanarCollider.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(objrun_open), high
void* __cdecl NiPSysPlanarCollider_GetRTTI()
{
    return &DAT_0126b228;
}

extern int DAT_0126b258;

// @fnv 0x00dfbed0
void* __cdecl FUN_00dfbed0()
{
    return &DAT_0126b258;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126b288;
// @fnv 0x00dfbef0
// pdb: NiPSysAirFieldAirFrictionCtlr::GetRTTI | NiPSysAirFieldAirFrictionCtlr.obj | fnv360_0721_retail, objopen_prop, low, conflict (skyrim: NiPSysInitialRotSpeedCtlr::GetRTTI)
CpuOpaque* __cdecl FUN_00dfbef0()
{
    return &DAT_0126b288;
}

extern int DAT_0126b2b8;

// @fnv 0x00dfbf20
void* __cdecl FUN_00dfbf20()
{
    return &DAT_0126b2b8;
}

struct FUN_00dfbf30_class
{
    virtual void m0(int);
};

// @fnv 0x00dfbf30
void __cdecl FUN_00dfbf30(void* p)
{
    ((FUN_00dfbf30_class*)p)->m0(0);
}

extern int DAT_0126b2e8;

// @fnv 0x00dfbf40
// pdb: NiPSysInitialRotAngleCtlr::GetRTTI | NiPSysInitialRotAngleCtlr.obj | fnv360_0822_retail, objopen_prop, low
int* __cdecl FUN_00dfbf40()
{
    return &DAT_0126b2e8;
}

// @fnv 0x00dfbf60
// pdb: NiPSysGrowFadeModifier::GetRTTI | NiPSysGrowFadeModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
int* __cdecl NiPSysGrowFadeModifier_GetRTTI()
{
    return &DAT_010df89c;
}

extern int DAT_0126b330;

// @fnv 0x00dfc030
// pdb: NiPSysGravityStrengthCtlr::GetRTTI | NiPSysGravityStrengthCtlr.obj | fnv360_0721_retail, objopen_prop, low
void* __cdecl FUN_00dfc030()
{
    return &DAT_0126b330;
}

// FUN_00dfc050 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfc050;

// @fnv 0x00dfc050
// pdb: NiPSysGravityFieldModifier::GetRTTI | NiPSysGravityFieldModifier.obj | fnv360_0822_retail, objrun_prop, low
void* __cdecl FUN_00dfc050()
{
    return &g_target_FUN_00dfc050;
}

// FUN_00dfc070 : a one-line function - getter
extern int g_target_00dfc070;
// @fnv 0x00dfc070
void* FUN_00dfc070()
{
    return &g_target_00dfc070;
}

extern int DAT_0126b3a8;

// @fnv 0x00dfc100
// pdb: NiPSysFieldMagnitudeCtlr::GetRTTI | NiPSysFieldMagnitudeCtlr.obj | tesv_win, objrun_open, low
int* __cdecl FUN_00dfc100()
{
    return &DAT_0126b3a8;
}

struct S_00dfc110_vt
{
    virtual void m0(int);
};

void __thiscall S_00dfc110_vt::m0(int)
{}

// @fnv 0x00dfc110
// pdb: cleanupLoadedObjecthkpMultiRayShape | hkpMultiRayShapeClass.obj | fnv360_0721_beta, objrun_open, low
void __cdecl FUN_00dfc110(void* p)
{
    ((S_00dfc110_vt*)p)->m0(0);
}

extern int g_0126b3d8;

// @fnv 0x00dfc120
// pdb: NiPSysFieldAttenuationCtlr::GetRTTI | NiPSysFieldAttenuationCtlr.obj | fnv360_0721_retail, objrun_open, low
int* __cdecl FUN_00dfc120()
{
    return &g_0126b3d8;
}

extern int DAT_010dff44;

// @fnv 0x00dfc140
int* __cdecl FUN_00dfc140()
{
    return &DAT_010dff44;
}

namespace fnv_00dfc150 {
struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

struct BufferBase
{
    virtual ~BufferBase()
    {}
};

}  // namespace fnv_00dfc150

extern unsigned char DAT_0126b420;

// @fnv 0x00dfc220
// pdb: NiPSysEmitterPlanarAngleVarCtlr::GetRTTI | NiPSysEmitterPlanarAngleVarCtlr.obj | tesv_win, objrun_open, low
void* __cdecl FUN_00dfc220()
{
    return &DAT_0126b420;
}

namespace fnv_00dfc240 {
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00dfc240
GlobalObject* __cdecl FUN_00dfc240()
{
    return &g_global;
}
}  // namespace fnv_00dfc240

extern char DAT_0126b498;
// @fnv 0x00dfc260
char* __cdecl FUN_00dfc260()
{
    return &DAT_0126b498;
}

extern int DAT_010e00cc;

// @fnv 0x00dfc290
void* FUN_00dfc290()
{
    return &DAT_010e00cc;
}

extern int DAT_010e00dc;

// @fnv 0x00dfc2b0
// pdb: NiBoolData::GetRTTI | NiPSysEmitterCtlr.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: NiPSysEmitterDeclinationVarCtlr::GetRTTI)
int* __cdecl FUN_00dfc2b0()
{
    return &DAT_010e00dc;
}

// FUN_00dfc360: cdecl no-arg getter returning the address of a global.
extern int DAT_0126b528;

// @fnv 0x00dfc360
// pdb: NiPSysEmitterCtlr::GetRTTI | NiPSysEmitterCtlr.obj | fnv360_0822_debug, objrun_open, low
int* __cdecl FUN_00dfc360()
{
    return &DAT_0126b528;
}

extern int g_unk0126b4e0;

// @fnv 0x00dfc370
// pdb: NiPSysEmitterCtlrData::GetRTTI | NiPSysEmitterCtlrData.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* __cdecl NiPSysEmitterCtlrData_GetRTTI()
{
    return &g_unk0126b4e0;
}

extern void* DAT_0126b558;

// @fnv 0x00dfc390
// pdb: NiPSysDragModifier::GetRTTI | NiPSysDragModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* NiPSysDragModifier_GetRTTI()
{
    return &DAT_0126b558;
}

struct FUN_00e05c20_class
{
    void __thiscall FUN_00e05c20();
};

// @fnv 0x00dfc3a0
// pdb: cleanupLoadedObjecthkpBallSocketChainData | hkpBallSocketChainDataClass.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: cleanupLoadedObjecthkpGenericConstraintDataScheme)
void __cdecl FUN_00dfc3a0(FUN_00e05c20_class* p)
{
    p->FUN_00e05c20();
}

// NiPSysDragFieldModifier_GetRTTI : a one-line function - getter
extern int g_target_00dfc440;
// @fnv 0x00dfc440
// pdb: NiPSysDragFieldModifier::GetRTTI | NiPSysDragFieldModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(objrun_open), high
void* NiPSysDragFieldModifier_GetRTTI()
{
    return &g_target_00dfc440;
}

class VirtualDispatchObj
{
  public:
    virtual void Invoke0(int arg);
};

// @fnv 0x00dfc450
// pdb: cleanupLoadedObjecthkpConvexPieceStreamData | hkpConvexPieceStreamDataClass.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: cleanupLoadedObjecthkpConvexTranslateShape)
void __cdecl FUN_00dfc450(VirtualDispatchObj* p)
{
    p->Invoke0(0);
}

extern void* DAT_0126b588;

// @fnv 0x00dfc460
// pdb: NiPSysColliderManager::GetRTTI | NiPSysColliderManager.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00dfc460()
{
    return reinterpret_cast<int>(&DAT_0126b588);
}

extern int DAT_010e04ac;

// @fnv 0x00dfc480
// pdb: NiPSysBoundUpdateModifier::GetRTTI | NiPSysBoundUpdateModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* __cdecl NiPSysBoundUpdateModifier_GetRTTI()
{
    return &DAT_010e04ac;
}

extern int g_unk0126b678;

// @fnv 0x00dfc4d0
// pdb: NiPSysBombModifier::GetRTTI | NiPSysBombModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* __cdecl NiPSysBombModifier_GetRTTI()
{
    return &g_unk0126b678;
}

extern int DAT_0126b648;

// @fnv 0x00dfc4f0
// pdb: NiPSysAgeDeathModifier::GetRTTI | NiPSysAgeDeathModifier.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
int* __cdecl NiPSysAgeDeathModifier_GetRTTI()
{
    return &DAT_0126b648;
}

extern int DAT_0126b600;

// @fnv 0x00dfc510
// pdb: NiPSysAirFieldModifier::GetRTTI | NiPSysAirFieldModifier.obj | fnv360_0822_retail, objrun, medium
int* __cdecl FUN_00dfc510()
{
    return &DAT_0126b600;
}

extern int DAT_010e0654;

// @fnv 0x00dfc530
// pdb: NiPSysAirFieldModifier::GetRTTI | NiPSysAirFieldModifier.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: NiPSysAirFieldInheritVelocityCtlr::GetRTTI)
int* __cdecl FUN_00dfc530()
{
    return &DAT_010e0654;
}

extern int DAT_0126b6a8;

// @fnv 0x00dfc590
// pdb: NiMeshPSysData::GetRTTI | NiMeshPSysData.obj | fnv360_0822_retail, objrun_prop + bridge(vtable|objrun_prop) + skyrim(objrun), high
int* __cdecl NiMeshPSysData_GetRTTI(void)
{
    return &DAT_0126b6a8;
}

// FUN_00dfc5b0 : a one-line function - getter
extern int g_target_00dfc5b0;
// @fnv 0x00dfc5b0
// pdb: NiPSysFieldModifier::GetRTTI | NiPSysFieldModifier.obj | fnv360_0822_retail, objrun, low
void* FUN_00dfc5b0()
{
    return &g_target_00dfc5b0;
}

extern int DAT_0126b708;

// @fnv 0x00dfc5d0
// pdb: NiPSysCollider::GetRTTI | NiPSysCollider.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(objrun_open), high
int* __cdecl NiPSysCollider_GetRTTI()
{
    return &DAT_0126b708;
}

extern int DAT_0126b738;

// @fnv 0x00dfc5f0
// pdb: NiPSysModifierBoolCtlr::GetRTTI | NiPSysModifierBoolCtlr.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* __cdecl NiPSysModifierBoolCtlr_GetRTTI()
{
    return &DAT_0126b738;
}

struct FUN_00dfc600_vt
{
    virtual void __thiscall m0(int);
};
// @fnv 0x00dfc600
// pdb: cleanupLoadedObjecthkpSerializedDisplayMarkerList | hkpSerializedDisplayMarkerListClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dfc600(FUN_00dfc600_vt* p)
{
    p->m0(0);
}

extern unsigned char DAT_0126b768;

// @fnv 0x00dfc610
// pdb: NiPSysModifierFloatCtlr::GetRTTI | NiPSysModifierFloatCtlr.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00dfc610()
{
    return &DAT_0126b768;
}

extern int DAT_0102e368;

// @fnv 0x00dfc630
// pdb: BSFadeNode::GetRTTI | BSFadeNode.obj | fnv360_0822_retail, objrun_prop, low
int* __cdecl FUN_00dfc630()
{
    return &DAT_0102e368;
}

extern int DAT_0126b7b0;

// @fnv 0x00dfc660
// pdb: DistantLODShaderProperty::GetRTTI | DistantLODShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl DistantLODShaderProperty_GetRTTI()
{
    return &DAT_0126b7b0;
}

// TallGrassShaderProperty_GetRTTI : a one-line function - getter
extern int g_target_00dfc680;
// @fnv 0x00dfc680
// pdb: TallGrassShaderProperty::GetRTTI | TallGrassShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* TallGrassShaderProperty_GetRTTI()
{
    return &g_target_00dfc680;
}

struct FUN_00dfc690_vt
{
    virtual void m0(int);
};

// @fnv 0x00dfc690
void __cdecl FUN_00dfc690(FUN_00dfc690_vt* p)
{
    p->m0(0);
}

extern int DAT_0126b810;

// @fnv 0x00dfc6a0
// pdb: ShadowSceneNode::GetRTTI | ShadowSceneNode.obj | fnv360_0822_retail, udata, medium, conflict (skyrim: BSShaderAccumulator::FinishAccumulating_ScreenSplatter)
void* __cdecl FUN_00dfc6a0()
{
    return &DAT_0126b810;
}

extern int DAT_010d0a64;

// @fnv 0x00dfc6d0
// pdb: BSShaderAccumulator::GetRTTI | BSShaderAccumulator.obj | fnv360_0822_retail, udata, high
int* __cdecl BSShaderAccumulator_GetRTTI()
{
    return &DAT_010d0a64;
}

extern char DAT_0126b858;

// @fnv 0x00dfc6f0
// pdb: BSShaderPPLightingProperty::GetRTTI | BSShaderPPLightingProperty.obj | fnv360_0822_retail, objrun_open, low
void* FUN_00dfc6f0()
{
    return &DAT_0126b858;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126b888;
// @fnv 0x00dfc710
// pdb: BSShaderProperty::GetBaseTexture | WaterShaderProperty.obj | fnv360_0721_beta, objrun, low
GlobalObjectO2_00d472a0* __cdecl FUN_00dfc710()
{
    return &g_0126b888;
}

extern int DAT_010d0aac;

// @fnv 0x00dfc740
// pdb: BSShaderNoLightingProperty::GetRTTI | BSShaderNoLightingProperty.obj | fnv360_0822_retail, objrun, medium
int* __cdecl FUN_00dfc740()
{
    return &DAT_010d0aac;
}

extern int g_unk0126b8d0;

// @fnv 0x00dfc760
// pdb: BSShaderLightingProperty::GetRTTI | BSShaderLightingProperty.obj | fnv360_0721_beta, udata + bridge(udata|objrun_prop), high
int* __cdecl BSShaderLightingProperty_GetRTTI()
{
    return &g_unk0126b8d0;
}

namespace fnv_00dfc770 {
struct Handler_cls
{
    void __thiscall Handle(int value);
};

}  // namespace fnv_00dfc770

extern int g_0126b900;

// @fnv 0x00dfc7c0
// pdb: ShadowLightShader::GetRTTI | ShadowLightShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl ShadowLightShader_GetRTTI()
{
    return &g_0126b900;
}

extern int DAT_0126b948;

// @fnv 0x00dfc7e0
// pdb: BSShaderBloodSplatter::GetRTTI | BSShaderBloodSplatter.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl BSShaderBloodSplatter_GetRTTI()
{
    return &DAT_0126b948;
}

extern int DAT_0126b978;

// @fnv 0x00dfc800
// pdb: BSShaderBloodSplatterProperty::GetRTTI | BSShaderBloodSplatterProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl BSShaderBloodSplatterProperty_GetRTTI()
{
    return &DAT_0126b978;
}

class SpawnedMid
{
  public:
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SpawnedMid()
    {
        *(volatile int*)&m_8c = 0;
        *(volatile int*)&m_90 = 0;
        *(volatile int*)&m_94 = (int)0x80000000;
        *(volatile int*)&m_98 = 0;
        *(volatile int*)&m_9c = 0;
        *(volatile int*)&m_a0 = (int)0x80000000;
    }
};

extern int DAT_0126b9c0;

// @fnv 0x00dfc8c0
// pdb: WaterShader::GetRTTI | WaterShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl WaterShader_GetRTTI()
{
    return &DAT_0126b9c0;
}

extern int g_unk0126b9f0;

// @fnv 0x00dfc8e0
// pdb: BSBatchRenderer::GetRTTI | BSBatchRenderer.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl BSBatchRenderer_GetRTTI()
{
    return &g_unk0126b9f0;
}

extern int DAT_010e11ec;
// @fnv 0x00dfc910
// pdb: SkyShader::GetRTTI | SkyShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl SkyShader_GetRTTI()
{
    return &DAT_010e11ec;
}

extern int g_0126ba38;

// @fnv 0x00dfc930
// pdb: ParticleShader::GetRTTI | ParticleShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl ParticleShader_GetRTTI()
{
    return &g_0126ba38;
}

struct FUN_00dfc940_class
{
    virtual void m0(int);
};

// @fnv 0x00dfc940
void __cdecl FUN_00dfc940(FUN_00dfc940_class* p)
{
    p->m0(0);
}

extern int DAT_0126ba68;

// @fnv 0x00dfc950
// pdb: ParticleShaderProperty::GetRTTI | ParticleShaderProperty.obj | fnv360_0822_retail, objrun, medium
void* __cdecl FUN_00dfc950()
{
    return &DAT_0126ba68;
}

extern int DAT_010d0af4;

struct S_00dfc970_Flag
{
    char v;
    S_00dfc970_Flag(char c)
    {
        v = c;
    }
    S_00dfc970_Flag(const S_00dfc970_Flag& o)
    {
        v = o.v;
    }
};

extern int DAT_010d0af4;

// @fnv 0x00dfc9a0
// pdb: SpeedTreeBillboardShaderProperty::GetRTTI | SpeedTreeBillboardShaderProperty.obj | fnv360_0822_retail, objopen_prop, low
int* __cdecl FUN_00dfc9a0()
{
    return &DAT_010d0af4;
}

extern int DAT_0126bab0;

// @fnv 0x00dfc9c0
// pdb: BSShaderProperty::GetRTTI | BSShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl BSShaderProperty_GetRTTI()
{
    return &DAT_0126bab0;
}

class DFC9D0Object
{
  public:
    virtual ~DFC9D0Object();
};

// @fnv 0x00dfc9d0
void FUN_00dfc9d0(DFC9D0Object* pkObject)
{
    pkObject->~DFC9D0Object();
}

extern int DAT_0126bae0;

// @fnv 0x00dfc9e0
// pdb: TallGrassShader::GetRTTI | TallGrassShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl TallGrassShader_GetRTTI()
{
    return &DAT_0126bae0;
}

extern int DAT_010cb71c;

// @fnv 0x00dfca30
// pdb: SkyShaderProperty::GetRTTI | SkyShaderProperty.obj | fnv360_0822_retail, udata, high
void* __cdecl SkyShaderProperty_GetRTTI()
{
    return &DAT_010cb71c;
}

extern int DAT_0126bb28;

// @fnv 0x00dfca50
// pdb: PrecipitationShader::GetRTTI | PrecipitationShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl PrecipitationShader_GetRTTI()
{
    return &DAT_0126bb28;
}

class DFCA60Object
{
  public:
    virtual ~DFCA60Object();
};

// @fnv 0x00dfca60
void FUN_00dfca60(DFCA60Object* pkObject)
{
    pkObject->~DFCA60Object();
}

extern char g_unk0126bb58;

// @fnv 0x00dfca70
// pdb: PrecipitationShaderProperty::GetRTTI | PrecipitationShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl PrecipitationShaderProperty_GetRTTI()
{
    return &g_unk0126bb58;
}

extern int DAT_010da04c;

// @fnv 0x00dfcaa0
// pdb: SpeedTreeLeafShader::GetRTTI | SpeedTreeLeafShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl SpeedTreeLeafShader_GetRTTI()
{
    return &DAT_010da04c;
}

extern int DAT_0126bba0;

// @fnv 0x00dfcac0
// pdb: SpeedTreeLeafShaderProperty::GetRTTI | SpeedTreeLeafShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl SpeedTreeLeafShaderProperty_GetRTTI()
{
    return &DAT_0126bba0;
}

extern void* DAT_0126bbd0;

// @fnv 0x00dfcae0
// pdb: SpeedTreeShaderPPLightingProperty::GetRTTI | SpeedTreeShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int __cdecl SpeedTreeShaderPPLightingProperty_GetRTTI()
{
    return reinterpret_cast<int>(&DAT_0126bbd0);
}

extern int DAT_010d0b3c;
// @fnv 0x00dfcb10
// pdb: SpeedTreeShaderLightingProperty::GetRTTI | SpeedTreeShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl SpeedTreeShaderLightingProperty_GetRTTI()
{
    return &DAT_010d0b3c;
}

extern int DAT_0126bc18;
// @fnv 0x00dfcb30
// pdb: SpeedTreeBranchShaderProperty::GetRTTI | SpeedTreeBranchShaderProperty.obj | fnv360_0822_retail, udata, medium
void* __cdecl FUN_00dfcb30()
{
    return &DAT_0126bc18;
}

namespace fnv_00dfcb40 {
struct Handler_cls
{
    void __thiscall Handle(int value);
};

}  // namespace fnv_00dfcb40

extern int DAT_0126bc48;
// @fnv 0x00dfcb90
// pdb: GeometryDecalShaderProperty::GetRTTI | GeometryDecalShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl GeometryDecalShaderProperty_GetRTTI()
{
    return &DAT_0126bc48;
}

extern int DAT_0126bc90;

// @fnv 0x00dfcbb0
// pdb: Lighting30ShaderProperty::GetRTTI | Lighting30ShaderProperty.obj | fnv360_0822_retail, objrun_sim, low
int* __cdecl FUN_00dfcbb0()
{
    return &DAT_0126bc90;
}

// Stand-in for the object whose virtual slot 0 is invoked with argument 0.
struct FUN_00dfcbc0_vt
{
    virtual void m0(int a);
};

// Calls the first virtual of the object passed in as the only argument.
// @fnv 0x00dfcbc0
// pdb: cleanupLoadedObjecthkpEntity | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfcbc0(FUN_00dfcbc0_vt* pObject)
{
    pObject->m0(0);
}

extern int DAT_0126bcc0;

// @fnv 0x00dfcbd0
// pdb: BSDistantTreeShader::GetRTTI | BSDistantTreeShader.obj | fnv360_0822_retail, udata + bridge(udata|udata) + skyrim(udata), high
void* __cdecl BSDistantTreeShader_GetRTTI()
{
    return &DAT_0126bcc0;
}

extern void* DAT_010d37e4;
// @fnv 0x00dfcc00
// pdb: BSDistantTreeShaderProperty::GetRTTI | BSDistantTreeShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void** __cdecl BSDistantTreeShaderProperty_GetRTTI()
{
    return &DAT_010d37e4;
}

// TileShaderProperty_GetRTTI : a one-line function - getter
extern int g_target_00dfcc20;
// @fnv 0x00dfcc20
// pdb: TileShaderProperty::GetRTTI | TileShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* TileShaderProperty_GetRTTI()
{
    return &g_target_00dfcc20;
}

struct S_00dfcc40_Obj
{
    int unk00;
};
extern S_00dfcc40_Obj DAT_0126bd38;
// @fnv 0x00dfcc40
// pdb: BSFogProperty::GetRTTI | BSFogProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
S_00dfcc40_Obj* __cdecl BSFogProperty_GetRTTI()
{
    return &DAT_0126bd38;
}

// Lighting30Shader_GetRTTI : a one-line function - getter
extern int g_target_00dfcc70;
// @fnv 0x00dfcc70
// pdb: Lighting30Shader::GetRTTI | Lighting30Shader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* Lighting30Shader_GetRTTI()
{
    return &g_target_00dfcc70;
}

extern int DAT_0126bd80;

// @fnv 0x00dfcc90
// pdb: BoltShader::GetRTTI | BoltShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl BoltShader_GetRTTI()
{
    return &DAT_0126bd80;
}

// Forwarder: takes the object pointer, calls its first virtual slot with a
// literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00dfcca0
// pdb: cleanupLoadedObjecthkpThinBoxMotion | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
int __cdecl FUN_00dfcca0(VtblForwarder* p)
{
    return p->v0(0);
}

// FUN_00dfccb0 : a one-line function - getter
extern int g_target_00dfccb0;
// @fnv 0x00dfccb0
// pdb: BoltShaderProperty::GetRTTI | BoltShaderProperty.obj | fnv360_0822_retail, objrun_sim, low
void* FUN_00dfccb0()
{
    return &g_target_00dfccb0;
}

extern int DAT_010d0be4;

// @fnv 0x00dfcce0
// pdb: BSClearZNode::GetRTTI | BSClearZNode.obj | fnv360_0822_retail, udata + bridge(udata|udata) + skyrim(udata), high
void* __cdecl BSClearZNode_GetRTTI()
{
    return &DAT_010d0be4;
}

extern int DAT_0126bdf8;

// @fnv 0x00dfcd00
void* __cdecl FUN_00dfcd00()
{
    return &DAT_0126bdf8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126be28;
// @fnv 0x00dfcd20
// pdb: BSMaterialEmittanceMultController::GetRTTI | BSMaterialEmittanceMultController.obj | fnv360_0721_retail, objrun_open, low
CpuOpaque* __cdecl FUN_00dfcd20()
{
    return &DAT_0126be28;
}

extern int DAT_010c91ec;

// @fnv 0x00dfcd50
// pdb: BSRefractionFirePeriodController::GetRTTI | BSRefractionFirePeriodController.obj | fnv360_0822_retail, objrun_open, low
int* FUN_00dfcd50()
{
    return &DAT_010c91ec;
}

extern int DAT_0126be70;

// @fnv 0x00dfcd70
int* __cdecl FUN_00dfcd70()
{
    return &DAT_0126be70;
}

extern int DAT_0126bea0;

// @fnv 0x00dfcda0
// pdb: VolumetricFogShaderProperty::GetRTTI | VolumetricFogShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl VolumetricFogShaderProperty_GetRTTI()
{
    return &DAT_0126bea0;
}

extern char DAT_0126bed0;

// @fnv 0x00dfcdd0
// pdb: HairShaderProperty::GetRTTI | HairShaderProperty.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl HairShaderProperty_GetRTTI()
{
    return &DAT_0126bed0;
}

extern int DAT_0126bf00;

// @fnv 0x00dfce30
// pdb: BeamShader::GetRTTI | BeamShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl BeamShader_GetRTTI()
{
    return &DAT_0126bf00;
}

extern int DAT_0126bf48;

// @fnv 0x00dfce50
// pdb: VolumetricFogShader::GetRTTI | VolumetricFogShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl VolumetricFogShader_GetRTTI()
{
    return &DAT_0126bf48;
}

namespace fnv_00dfce60 {
// Forwarder: takes the object pointer from the stack, then calls its first
// virtual slot with a literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00dfce60
// pdb: cleanupLoadedObjecthkpFixedRigidMotion | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
int __cdecl FUN_00dfce60(VtblForwarder* p)
{
    return p->v0(0);
}
}  // namespace fnv_00dfce60

extern int DAT_0126bf78;

// @fnv 0x00dfce70
// pdb: BSShaderNoLighting::GetRTTI | BSShaderNoLighting.obj | fnv360_0822_retail, objrun, medium
void* __cdecl FUN_00dfce70()
{
    return &DAT_0126bf78;
}

extern int DAT_010d0cd4;
// @fnv 0x00dfcea0
// pdb: TileShader::GetRTTI | TileShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int* __cdecl TileShader_GetRTTI()
{
    return &DAT_010d0cd4;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126bfc0;
// @fnv 0x00dfcec0
// pdb: GeometryDecalShader::GetRTTI | GeometryDecalShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
CpuOpaque* __cdecl GeometryDecalShader_GetRTTI()
{
    return &DAT_0126bfc0;
}

extern int DAT_0126bff0;

// @fnv 0x00dfcef0
// pdb: ParallaxShader::GetRTTI | ParallaxShader.obj | fnv360_0822_retail, objrun, medium
void* __cdecl FUN_00dfcef0()
{
    return &DAT_0126bff0;
}

extern int DAT_0126c020;

// @fnv 0x00dfcf10
// pdb: SkinShader::GetRTTI | SkinShader.obj | fnv360_0822_retail, objrun, medium
void* __cdecl FUN_00dfcf10()
{
    return &DAT_0126c020;
}

extern "C" void* DAT_010305a8;

extern int DAT_0126c068;

// @fnv 0x00dfd0c0
// pdb: HairShader::GetRTTI | HairShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* HairShader_GetRTTI()
{
    return &DAT_0126c068;
}

struct FUN_00dfd0d0_cls
{
    virtual void Call(int a);
};

// @fnv 0x00dfd0d0
// pdb: cleanupLoadedObjecthkpSimulation | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void FUN_00dfd0d0(FUN_00dfd0d0_cls* pTarget)
{
    pTarget->Call(0);
}

extern int DAT_0126c098;

// @fnv 0x00dfd0e0
// pdb: SpeedTreeFrondShader::GetRTTI | SpeedTreeFrondShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* SpeedTreeFrondShader_GetRTTI()
{
    return &DAT_0126c098;
}

extern "C" void* DAT_010e222c;

// @fnv 0x00dfd120
// pdb: SpeedTreeBranchShader::GetRTTI | SpeedTreeBranchShader.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
void* __cdecl SpeedTreeBranchShader_GetRTTI()
{
    return &DAT_010e222c;
}

namespace fnv_00dfd130 {
extern int DAT_0102e388;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00dfd130_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    int m_0c;
    void* m_pData;
    int m_14;
    int m_uiItemCount;

    FUN_00dfd130_cls* FUN_00dfd130(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00dfd130

extern unsigned char DAT_0126c0e0;
// @fnv 0x00dfd1b0
// pdb: DistantLODShader::GetRTTI | DistantLODShader.obj | fnv360_0822_retail, objrun_sim, low
unsigned char* __cdecl FUN_00dfd1b0()
{
    return &DAT_0126c0e0;
}

// @fnv 0x00dfd1c0
// pdb: cleanupLoadedObjecthkpPhysicsSystem | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfd1c0(void* p)
{
    (*(void(__thiscall**)(void*, int)) * (int*)p)(p, 0);
}

extern int DAT_0126c110;

// @fnv 0x00dfd1d0
// pdb: BSCubeMapCamera::GetRTTI | BSCubeMapCamera.obj | fnv360_0822_retail, udata + bridge(udata|udata) + skyrim(udata), high
void* __cdecl BSCubeMapCamera_GetRTTI()
{
    return &DAT_0126c110;
}

extern int DAT_0126c158;

// @fnv 0x00dfd230
// pdb: TallGrassTriStrips::GetRTTI | TallGrassTriStrips.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00dfd230()
{
    return &DAT_0126c158;
}

// FUN_00dfd250 : a one-line function - getter
extern int g_target_00dfd250;
// @fnv 0x00dfd250
// pdb: TallGrassTriShape::GetRTTI | TallGrassTriShape.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: TallGrassTriShape::GetWorldBound)
void* FUN_00dfd250()
{
    return &g_target_00dfd250;
}

extern int DAT_0126c1d0;

// @fnv 0x00dfd2a0
// pdb: Random::Name | RobertDavies_Random.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00dfd2a0()
{
    return &DAT_0126c1d0;
}

extern int DAT_0126c200;

// @fnv 0x00dfd2c0
// pdb: Uniform::Name | RobertDavies_Random.obj | fnv360_0822_retail, vtable, medium
int* __cdecl FUN_00dfd2c0()
{
    return &DAT_0126c200;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c230;
// @fnv 0x00dfd2d0
// pdb: Normal::Name | RobertDavies_Random.obj | fnv360_0822_retail, vtable, medium
GlobalObjectO2_00d472a0* __cdecl FUN_00dfd2d0()
{
    return &g_0126c230;
}

struct FUN_00dfd2e0_Class
{
    virtual void VF00(int value);
};

// @fnv 0x00dfd2e0
// pdb: cleanupLoadedObjecthkpPointToPathConstraintData | hkpPointToPathConstraintDataClass.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: finishLoadedObjecthkpCogWheelConstraintData)
void __cdecl FUN_00dfd2e0(FUN_00dfd2e0_Class* param_1)
{
    param_1->VF00(0);
}

// FUN_00dfd2f0 : a one-line function - getter
extern int g_target_00dfd2f0;
// @fnv 0x00dfd2f0
// pdb: PosGen::Name | RobertDavies_Random.obj | fnv360_0822_retail, vtable, medium
void* FUN_00dfd2f0()
{
    return &g_target_00dfd2f0;
}

// FUN_00dfd4e0 : a one-line function - getter
extern int g_target_00dfd4e0;
// @fnv 0x00dfd4e0
void* FUN_00dfd4e0()
{
    return &g_target_00dfd4e0;
}

extern int DAT_0126c2d8;

// @fnv 0x00dfd500
// pdb: Tile3D::GetTypeName | Tile.obj | fnv360_0822_retail, objrun, medium
void* __cdecl FUN_00dfd500()
{
    return &DAT_0126c2d8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126c308;
// @fnv 0x00dfd540
// pdb: DebugTextExtraData::GetRTTI | DebugText.obj | fnv360_0721_beta, vtable, medium
CpuOpaque* __cdecl FUN_00dfd540()
{
    return &DAT_0126c308;
}

extern int DAT_0126c338;

// @fnv 0x00dfd560
// pdb: __sys_nerr | syserr.obj | fnv360_0822_retail, call_dedup, low
int* __cdecl FUN_00dfd560()
{
    return &DAT_0126c338;
}

extern int DAT_0126c368;

// @fnv 0x00dfd590
// pdb: __sys_errlist | syserr.obj | fnv360_0822_retail, call_dedup, low
int* __cdecl FUN_00dfd590()
{
    return &DAT_0126c368;
}

namespace fnv_00dfd5a0 {
struct SpawnedAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750();

}  // namespace fnv_00dfd5a0

extern int DAT_0126c398;

// @fnv 0x00dfd5f0
// pdb: __daylight | timeset.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: _set_daylight)
int __cdecl FUN_00dfd5f0()
{
    return reinterpret_cast<int>(&DAT_0126c398);
}

// FUN_00dfd650 : a one-line function - getter
extern int g_target_00dfd650;
// @fnv 0x00dfd650
// pdb: __dstbias | timeset.obj | fnv360_0822_retail, udata, medium, conflict (skyrim: _set_dstbias)
void* FUN_00dfd650()
{
    return &g_target_00dfd650;
}

extern int DAT_0126c410;

// @fnv 0x00dfd790
// pdb: __timezone | timeset.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: _set_timezone)
int* __cdecl FUN_00dfd790()
{
    return &DAT_0126c410;
}

extern int DAT_0126c440;

// @fnv 0x00dfd7b0
// pdb: __tzname | timeset.obj | tesv_win, call_gap, low
void* __cdecl FUN_00dfd7b0()
{
    return &DAT_0126c440;
}

extern int DAT_0126c488;

// @fnv 0x00dfd930
// pdb: NiRenderedCubeMap::GetRTTI | NiRenderedCubeMap.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00dfd930()
{
    return &DAT_0126c488;
}

extern int DAT_0126c4b8;

// @fnv 0x00dfd950
// pdb: NiRenderTargetGroup::GetRTTI | NiRenderTargetGroup.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00dfd950()
{
    return &DAT_0126c4b8;
}

extern int DAT_0126c500;

// @fnv 0x00dfda40
// pdb: NiSCMExtraData::GetRTTI | NiSCMExtraData.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* NiSCMExtraData_GetRTTI()
{
    return &DAT_0126c500;
}

extern int DAT_0126c530;

// @fnv 0x00dfdaa0
int* __cdecl FUN_00dfdaa0()
{
    return &DAT_0126c530;
}

extern int DAT_010e351c;

extern "C" void* DAT_010e352c;

struct CpuOpaque;

struct FUN_00dfde10_vtable
{
    virtual void __thiscall slot0(int value)
    {}
};

// @fnv 0x00dfde10
void __cdecl FUN_00dfde10(void* p)
{
    reinterpret_cast<FUN_00dfde10_vtable*>(p)->slot0(0);
}

extern int DAT_010d3cc0;

struct CpuOpaque;

struct CpuOpaque;

class DFDF50Object
{
  public:
    virtual ~DFDF50Object();
};

// @fnv 0x00dfdf50
void __cdecl FUN_00dfdf50(DFDF50Object* pkObject)
{
    pkObject->~DFDF50Object();
}

extern int DAT_010e3e5c;

namespace fnv_00dfdfe0 {
struct EngineHeap
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual void Unknown3();
    virtual void Free(void* memory, unsigned int bytes);
};
struct EngineMemoryManager
{
    void* unknown00;
    void* unknown04;
    void* unknown08;
    void* unknown0C;
    EngineHeap* heap;
};
EngineMemoryManager* __cdecl FUN_00c85750();
struct ArrayEntry
{
    unsigned int index;
    unsigned int value;
};
struct ArrayBase
{
    virtual void UnknownVirtual();
    unsigned int unknown04;
    ~ArrayBase()
    {}
};
struct ArrayStorage
{
    ArrayEntry* entries;
    int length;
    int allocationFlags;
    __forceinline void Reset(EngineHeap* heap)
    {
        ArrayEntry* current = entries;
        if (length > 0)
        {
            int remaining = length;
            do
            {
                reinterpret_cast<FUN_00cb0c00_class*>(current)->FUN_00cb0c00();
                ++current;
            } while (--remaining != 0);
        }
        length = 0;
        if (!(allocationFlags & 0x80000000))
            heap->Free(entries, (allocationFlags & 0x3fffffff) * sizeof(ArrayEntry));
        entries = 0;
        allocationFlags = 0x80000000;
    }
};
}  // namespace fnv_00dfdfe0

namespace fnv_00dfe210 {
struct FUN_00dfe210_allocator
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void Free(void* data, unsigned int size);
};

struct FUN_00dfe210_manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dfe210_allocator* unk10;
};

extern FUN_00dfe210_manager* __cdecl FUN_00c85750();

}  // namespace fnv_00dfe210

extern int DAT_010e5474;

// @fnv 0x00dfe470
// pdb: cleanupLoadedObjecthkpPointToPathConstraintData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfe470(FUN_00dfe430_class* p)
{
    p->FUN_00cb0a70(0);
}

extern int DAT_010e57a4;

struct CpuOpaque;

extern int DAT_010e58c8;

struct FUN_00dfe6e0_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00dfe6e0
// pdb: cleanupLoadedObjecthkpShapeInfo | hkpCollideReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dfe6e0(FUN_00dfe6e0_Class* param_1)
{
    param_1->vf00(0);
}

extern int DAT_010e59ac;

struct FUN_00dfe970_class
{
    virtual void __thiscall m_iWordAt00(int);
};

// @fnv 0x00dfe970
void __cdecl FUN_00dfe970(FUN_00dfe970_class* p)
{
    p->m_iWordAt00(0);
}

extern int DAT_010dec04;
extern int DAT_010e5ae4;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;

extern int DAT_010e5ae4;

extern int DAT_010e5b68;

namespace fnv_00dfeb80 {
struct FnvCpu_FUN_00dfeb80_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00dfeb80_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00dfeb80_CpuAllocator* allocator;
};
FnvCpu_FUN_00dfeb80_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00dfeb80

extern int DAT_010e5b4c;

extern int DAT_010e5bfc;

class DFEC50Object
{
  public:
    virtual ~DFEC50Object();
};

// @fnv 0x00dfec50
void __cdecl FUN_00dfec50(DFEC50Object* pkObject)
{
    pkObject->~DFEC50Object();
}

// FUN_00dfec80: cdecl, returns the address of a global data symbol.
extern int DAT_010e5d94;

extern int DAT_010e5da8;

extern int DAT_010e5e9c;

extern int DAT_010e60c4;

extern int DAT_010e62a4;

extern int DAT_010e6394;

namespace fnv_00dfef20 {
extern unsigned char DAT_010c925c;
extern unsigned char DAT_010debf4;
extern unsigned char DAT_010debe4;

}  // namespace fnv_00dfef20

extern int DAT_010debf4;

class DFEF80Object
{
  public:
    virtual ~DFEF80Object();
};

// @fnv 0x00dfef80
// pdb: cleanupLoadedObjecthkpSphereShape | hkpCollideReflections.obj | tesv_win, objrun_open, low
void FUN_00dfef80(DFEF80Object* pkObject)
{
    pkObject->~DFEF80Object();
}

// FUN_00dfefd0 : cdecl, 13 bytes
// Calls slot 0 of the object's vtable with the argument 0 and returns the result.

struct FUN_00dfefd0_cls
{
    virtual int v00(int a);
};

// @fnv 0x00dfefd0
int __cdecl FUN_00dfefd0(FUN_00dfefd0_cls* pObj)
{
    return pObj->v00(0);
}

extern int DAT_010e66fc;

struct FUN_00dff0b0_class
{
    virtual void m0(int);
};

// @fnv 0x00dff0b0
// pdb: cleanupLoadedObjecthkpConvexPieceMeshShape | hkpConvexPieceMeshShapeClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00dff0b0(FUN_00dff0b0_class* p)
{
    p->m0(0);
}

extern int DAT_010e676c;

struct FUN_00dff120_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00dff120
void __cdecl FUN_00dff120(FUN_00dff120_Class* param_1)
{
    param_1->vf00(0);
}

struct FUN_00dff190_cls
{
    virtual void m_v00(int arg);
};

// @fnv 0x00dff190
void __cdecl FUN_00dff190(FUN_00dff190_cls* pObject)
{
    pObject->m_v00(0);
}

struct FUN_00dff250_class
{
    virtual void m0(int);
};

// @fnv 0x00dff250
void __cdecl FUN_00dff250(FUN_00dff250_class* p)
{
    p->m0(0);
}

struct DFF2E0FinishFlag
{
    int m_bFinishing;
};

class DFF2E0Object
{
  public:
    DFF2E0Object(DFF2E0FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

namespace fnv_00dff3e0 {
inline void* operator new(unsigned int, void* where) throw()
{
    return where;
}

class SpawnPrimaryBase
{
  public:
    virtual void v0();
    int m_i04;
};

class SpawnSecondaryBase0
{
  public:
    virtual void v0();
};

class SpawnSecondaryBase1
{
  public:
    virtual void v0();
};

class SpawnSecondaryBase2
{
  public:
    virtual void v0();
};

class SpawnSecondaryBase3
{
  public:
    virtual void v0();
};

class SpawnedObject : public SpawnPrimaryBase,
                      public SpawnSecondaryBase0,
                      public SpawnSecondaryBase1,
                      public SpawnSecondaryBase2,
                      public SpawnSecondaryBase3
{
  public:
    __forceinline SpawnedObject()
    {}
    virtual void v0();
};

// If p is non-null, placement-constructs a SpawnedObject at p.
// @fnv 0x00dff3e0
void __cdecl ConstructSpawnedObject(void* apMemory)
{
    if (apMemory != 0)
    {
        new (apMemory) SpawnedObject();
    }
}
}  // namespace fnv_00dff3e0

struct CpuOpaque;

namespace fnv_00dff470 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct SpawnedBase0
{
    virtual ~SpawnedBase0()
    {}
    unsigned short m_uSize;
    unsigned short m_u06;
};

struct SpawnedBase1
{
    virtual ~SpawnedBase1()
    {}
};

struct SpawnedBase2
{
    virtual ~SpawnedBase2()
    {}
};

struct SpawnedBase3
{
    virtual ~SpawnedBase3()
    {}
};

struct SpawnedBase4
{
    virtual ~SpawnedBase4()
    {}
};

}  // namespace fnv_00dff470

struct DFF520FinishFlag
{
    int m_bFinishing;
};

class DFF520Object
{
  public:
    DFF520Object(DFF520FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

struct CpuOpaque;

struct CpuOpaque;

extern int DAT_010e75cc;

extern int DAT_010e75dc;

extern int DAT_010e75ec;

struct DFFA90FinishFlag
{
    int m_bFinishing;
};

class DFFA90ReferencedObject
{
  public:
    DFFA90ReferencedObject(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DFFA90ListenerA
{
  public:
    DFFA90ListenerA(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerA();
};

class DFFA90ListenerB
{
  public:
    DFFA90ListenerB(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerB();
};

class DFFA90ListenerC
{
  public:
    DFFA90ListenerC(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerC();
};

class DFFA90ListenerD
{
  public:
    DFFA90ListenerD(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerD();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class DFFA90ListenerE
{
  public:
    DFFA90ListenerE(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerE();
};

namespace fnv_00dffb80 {
// Forwarder: calls a handler object with one int argument, but only if the
// handler pointer is non-null.
struct Handler_cls
{
    void __thiscall Handle(int value);
};

}  // namespace fnv_00dffb80

struct CpuOpaque;

extern int DAT_010e7c24;

extern int DAT_010cc0d8;

namespace fnv_00dffde0 {
struct SpawnedObject
{
    virtual void Vt0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned short unk11C;
    short m_11E;
    SpawnedObject(int flag)
    {
        if (flag != 0)
        {
            float one = 1.0f;
            m_11E = (short)(*(int*)&one >> 16);
        }
    }
};

struct SpawnedDerived : SpawnedObject
{
    virtual void Vt1();
    SpawnedDerived(int flag) : SpawnedObject(flag)
    {}
};

inline void* operator new(unsigned int, void* where)
{
    return where;
}

// Placement-constructs a SpawnedDerived at p when p is non-null, forwarding flag to the constructor.
// @fnv 0x00dffde0
void ConstructSpawnedDerived(SpawnedObject* apObject, int flag)
{
    if (apObject != 0)
    {
        new (apObject) SpawnedDerived(flag);
    }
}
}  // namespace fnv_00dffde0

extern int DAT_010d3838;

extern void* DAT_010c6d54;

namespace fnv_00dffeb0 {
// FUN_00dffeb0
//
// Returns the address of the shared virtual table located at 0x010C6D54
// (its entries point at the implementation functions 0x00DE10B0, 0x00C90350,
// ... ).  The original code is simply:
//
//     mov eax, offset DAT_010c6d54
//     ret
//
// so the global is declared as an extern and its address is returned.

extern int DAT_010c6d54;

}  // namespace fnv_00dffeb0

extern int DAT_010cb798;

extern int DAT_010da004;

struct SpawnedSub
{
    int unk00;
    int unk04;
    unsigned int unk08;
    void __thiscall Notify(unsigned int value);
};

struct SpawnedObject
{
    int* vptr;
    int unk04;
    int unk08;
    SpawnedSub m_0c;
};

// Sets the object's vtable pointer and, when flag is non-zero, notifies the sub-object with its stored value.
// @fnv 0x00dfff20
void __cdecl InitSpawnedObject(SpawnedObject* pObject, int iNotifyFlag)
{
    if (pObject != 0)
    {
        pObject->vptr = &DAT_010da004;
        SpawnedSub* sub = &pObject->m_0c;
        if (iNotifyFlag != 0)
            sub->Notify(sub->unk08);
    }
}

extern int DAT_010da004;

extern void* DAT_010e80b4;

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
extern "C" __m128 _mm_setzero_ps(void);

class hkVector4_de1210
{
  public:
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4_de1210& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

class hkMatrix3_de1210
{
  public:
    hkVector4_de1210 m_kColumn0;
    hkVector4_de1210 m_kColumn1;
    hkVector4_de1210 m_kColumn2;
    __forceinline void setIdentity()
    {
        hkVector4_de1210 zero;
        zero.setZero();
        const float one = 1.0f;
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn0(0) = one;
        m_kColumn1(1) = one;
        m_kColumn2(2) = one;
    }
};

class hkReferencedObject_de1210
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObject_de1210()
    {
        m_sReferenceCount = 1;
    }
};

class Base_de1210 : public hkReferencedObject_de1210
{
  public:
    int m_iUnk08;
    hkMatrix3_de1210 m_kRotationMatrix;
    hkVector4_de1210 m_kVec40;
    int m_iUnk50;

    Base_de1210()
    {
        m_iUnk08 = 0;
        m_iUnk50 = 3;
        m_kRotationMatrix.setIdentity();
        m_kVec40.setZero();
    }
    virtual void v00();
};

struct DE1FC0Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct DE1FC0Rotation
{
    DE1FC0Vector4 m_kColumn0;
    DE1FC0Vector4 m_kColumn1;
    DE1FC0Vector4 m_kColumn2;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

class DE1FC0ReferencedObject
{
  public:
    DE1FC0ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfunc00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DE1FC0Transform : public DE1FC0ReferencedObject
{
  public:
    DE1FC0Transform()
    {
        m_ulUserData = 0;
        m_type = 2;
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }

    int m_ulUserData;
    int unk0C;
    DE1FC0Rotation m_rotation;
    DE1FC0Vector4 m_vTranslation;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};

// Return a copy of the stored 4-float value.

struct DE5300Vector4
{
    float x;
    float y;
    float z;
    float w;
};

class DE5300Object
{
  public:
    int unk00;
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
    DE5300Vector4 m_kValue;

    DE5300Vector4 GetValue() const;
};

// @fnv 0x00de5300
DE5300Vector4 DE5300Object::GetValue() const
{
    return m_kValue;
}

struct DE5450Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void operator=(const DE5450Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct DE5450Transform
{
    DE5450Vector4 m_kColumn0;
    DE5450Vector4 m_kColumn1;
    DE5450Vector4 m_kColumn2;
    DE5450Vector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};

class DE5450ReferencedObject
{
  public:
    DE5450ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DE5450Shape : public DE5450ReferencedObject
{
  public:
    DE5450Shape() : m_ulUserData(0), m_type(4)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE5450Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};

struct FourFloatVector
{
    float x, y, z, w;
};
struct Matrix64
{
    FourFloatVector a, b, c, d;
};
struct Input
{
    int count;
    float a, b;
    FourFloatVector vector;
    unsigned* values;
    void* source;
    Matrix64* matrices;
    float scale;
    unsigned flags;
};
struct Header
{
    union
    {
        float epsilon;
        unsigned char type;
    };
    unsigned short count, pad06;
    unsigned flags, unk0c, size;
    float scale, a, b;
};
// @f3 0x00a7cbc0 (community match, verified in this file)
void FUN_00a7bcf0(int, FourFloatVector*, Matrix64*, void*, void*, void*, void*, void*, int);
// pdb: hkPoweredChainBuildJacobian | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: params, in, out
void WriteInputHeader(Input* input, void*, Header** ppCursor)
{
    float a = input->a;
    float b = input->b;
    int count = input->count;
    unsigned* values = input->values;
    Matrix64* matrices = input->matrices;
    unsigned flags = input->flags;
    Header* header = *ppCursor;
    header->flags = flags;
    header->epsilon += 1.1920928955078125e-7;
    unsigned short shortCount = (unsigned short)count;
    header->a = a;
    header->b = b;
    header->size = (shortCount * 0x534 + 0x53) & ~15;
    header->type = 0x1c;
    header->count = shortCount;
    unsigned* dst = (unsigned*)((char*)header + 0x40 + shortCount * 0x4f0);
    for (int i = 0; i < count + 1; ++i)
        *dst++ = *values++;
    Matrix64* matrixDst = (Matrix64*)((char*)header + 0x44 + header->count * 0x4f4);
    for (int j = 0; j < count; ++j)
        *matrixDst++ = *matrices++;
    header->scale = input->scale;
    header->flags = input->flags;
    FUN_00a7bcf0(input->count, &input->vector, input->matrices, (char*)*ppCursor + 0x20,
                 (char*)*ppCursor + 0x20 + count * 0x90, (char*)header + 0x40 + header->count * 0x4f0, input->source,
                 (char*)header + 0x20 + header->count * 0xf0, count * 0x3c0);
    *ppCursor = (Header*)((char*)*ppCursor + header->size);
}


// which resets the runtime caches and re-links the embedded collidable to its owner.
struct DF6500FinishFlag
{
    int m_bFinishing;
};
struct DF6500Collidable
{
    int m_pCollisionShape;
    char m_type;
    signed char m_iOwnerOffset;
    short m_pad06;
    int m_unk08;
    void SetOwnerPointer(void* owner)
    {
        m_iOwnerOffset = (signed char)((unsigned int)owner - (unsigned int)this);
    }
};
struct DF6500Object
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    DF6500Collidable m_kCollidable;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    short m_unk40;
    short m_unk42;
    int m_unk44;
    int m_unk48;

    DF6500Object(DF6500FinishFlag flag)
    {
        if (flag.m_bFinishing)
        {
            m_unk40 = 0;
            m_unk42 = 0;
            m_unk44 = 0;
            m_unk48 = 0;
            m_unk30 = 0;
            m_unk20 = 1;
            m_kCollidable.SetOwnerPointer(this);
        }
    }
};

struct BDFCA00FinishFlag
{
    int m_bFinishing;
};
struct BDFCA00UpdateFlag
{
    BDFCA00UpdateFlag(char cValue) : m_cValue(cValue)
    {}
    BDFCA00UpdateFlag(const BDFCA00UpdateFlag& kOther) : m_cValue(kOther.m_cValue)
    {}

    char m_cValue;
};
class BDFCA00Object
{
  public:
    __forceinline BDFCA00Object(BDFCA00FinishFlag kFlag)
    {
        if (kFlag.m_bFinishing && m_bModifierActive)
        {
            Recalculate(BDFCA00UpdateFlag(1));
        }
    }
    virtual ~BDFCA00Object();

    void Recalculate(BDFCA00UpdateFlag kFlag);

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    short unk114;
    bool m_bModifierActive;
};

struct FnvCpu_FUN_00de1150_CpuObject
{
    char* FUN_00de1150();
};
// @fnv 0x00de1150
// pdb: hkDisplayAABB::getMinExtent | hkDisplayAABB.obj | fnv360_0822_retail, objrun_open, low
char* FnvCpu_FUN_00de1150_CpuObject::FUN_00de1150()
{
    return reinterpret_cast<char*>(this) + 96;
}

struct FnvCpu_FUN_00de1160_CpuObject
{
    char* FUN_00de1160();
};
// @fnv 0x00de1160
// pdb: hkDisplayAABB::getMaxExtent | hkDisplayAABB.obj | fnv360_0822_retail, objrun_open, low
char* FnvCpu_FUN_00de1160_CpuObject::FUN_00de1160()
{
    return reinterpret_cast<char*>(this) + 112;
}

struct FnvCpu_FUN_00de4de0_CpuObject
{
    char* FUN_00de4de0();
};
// @fnv 0x00de4de0
// pdb: hkDisplayPlane::getNormal | hkDisplayPlane.obj | fnv360_0822_retail, objrun_open, low
char* FnvCpu_FUN_00de4de0_CpuObject::FUN_00de4de0()
{
    return reinterpret_cast<char*>(this) + 96;
}

// @fnv 0x00de4df0
// pdb: hkDisplayPlane::getCenter | hkDisplayPlane.obj | fnv360_0822_retail, objrun_open, low
void* __fastcall FUN_00de4df0(char* self, int)
{
    return self + 0x70;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned long DAT_0126835c;

struct FnvCpu_FUN_00dfee80_CpuInterface
{
    virtual void Invoke(int value);
};
// @fnv 0x00dfee80
void __cdecl FUN_00dfee80(FnvCpu_FUN_00dfee80_CpuInterface* object)
{
    object->Invoke(0);
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269fe8;

// @fnv 0x00de8370
GlobalObjectO2_00d472a0* __cdecl FUN_00de8370()
{
    return &g_01269fe8;
}

struct cls_d530
{
    int unk00;
    float m_04;
};

extern "C" cls_d530* d530_target(void);

// @fnv 0x00def530
// pdb: hkSolverExportWriteResult64 | hkpSolverExport.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkSolverExportWriteRhs)
static __declspec(noinline) void FUN_00def530(float value, cls_d530* target)
{
    target->m_04 = value;
}

void d530_caller(cls_d530* self, float f)
{
    FUN_00def530(f, d530_target());
}

struct d540_cls
{
    float unk00;
    float unk04;
};
extern "C" d540_cls* d540_target(void);
// @fnv 0x00def540
// pdb: hkSolverExportWriteResult128 | hkpSolverExport.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkSolverExportWriteResult64)
static __declspec(noinline) void FUN_00def540(float a, float b, d540_cls* t)
{
    t->unk00 = a;
    t->unk04 = b;
}
void d540_caller(float fa, float fb)
{
    FUN_00def540(fa, fb, d540_target());
}

struct def550_vec4
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
};

extern "C" def550_vec4* def550_target(void);

// @fnv 0x00def550
// pdb: hkSolverExportWriteResult128 | hkpSolverExport.obj | tesv_win, hash, low
static __declspec(noinline) void SetVec4(float afX, float afY, float afZ, float afW, def550_vec4* apVec)
{
    apVec->m_iWordAt00 = afX;
    apVec->m_iWordAt04 = afY;
    apVec->m_8 = afZ;
    apVec->m_iThirdValue = afW;
}

void def550_caller(float a, float b, float c, float d)
{
    SetVec4(a, b, c, d, def550_target());
}

extern unsigned long DAT_0126835c;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};

static inline void TimerMark(const char* name)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct Key
{
    unsigned char m_type;
    unsigned char m_slot;
};

struct Job
{
    unsigned char m_type;
    unsigned char m_slot;
    unsigned char m_gap[0x16];
    int m_18;
    unsigned char m_gap2[0xc];
    int m_28;
    int m_2c;
};

void __cdecl FUN_00df6e00(Job* job, int a, int b, int c);

struct Scheduler
{
    int ProcessCallback(Key* key, int b, int a);
};

// Records a timer mark, calls FUN_00df6e00 with job's m_18, m_28 and m_2c, records a second mark, then calls self->ProcessCallback with the job.
// @fnv 0x00df6f80
void __cdecl FUN_00df6f80(Scheduler* self, Job* job)
{
    TimerMark("TtCollQueryPairGetClosestPoints");
    FUN_00df6e00(job, job->m_18, job->m_28, job->m_2c);
    TimerMark("Et");
    self->ProcessCallback((Key*)job, (int)job, 0);
}

extern double DAT_010229b8;

extern "C" unsigned int df9ae0_val(void);

// @fnv 0x00df9ae0
static __declspec(noinline) float FUN_00df9ae0(unsigned int state)
{
    unsigned int t = 0x3039u - state * 0x3e39b193u;
    t &= 0x7fffffffu;
    return (float)((double)(int)t * DAT_010229b8);
}

volatile float df9ae0_sink;
void q_call_df9ae0(void)
{
    df9ae0_sink = FUN_00df9ae0(df9ae0_val());
}

static int g_w1 = 1;
static int g_ws = 3;
static float g_wv = 1.0f;

// in-file stand-in for the random-float helper: must kill eax+ecx and
// preserve edx so the out pointer's private-convention home is edx
static __declspec(noinline) float FUN_00df9ae0(void)
{
    g_w1 = (g_w1 * 3) << (g_ws & 31);
    return g_wv;
}

// Calls FUN_00df9ae0, computes (t + a) * (b - a), and stores the result into out[0], out[1], and out[2].
// @fnv 0x00df9b20
// pdb: randomVector | hkpConvexPenetrationUtil.obj | tesv_win, caller_sim, low
static __declspec(noinline) void WriteFloatToVector(float a, float b, float* out)
{
    float t = FUN_00df9ae0();
    a = (t + a) * (b - a);
    out[0] = a;
    out[1] = a;
    out[2] = a;
}

void dummy_caller(void)
{
    WriteFloatToVector(g_wv, g_wv, &g_wv);
}

AudioHolder* __cdecl FUN_00c85750() throw();

struct ElemDFB5A0
{
    int unk00;
    FUN_00cb0c00_class m_04;
    void FUN_00cb0c00()
    {
        m_04.FUN_00cb0c00();
    }
};

void __cdecl ResizeAudioStream(AudioAllocator* alloc, void* array, int sizeOfElement);

struct Pair_de30
{
    void* m_uiFilterValue;
    int m_key;
    Pair_de30(void* value, int key) : m_uiFilterValue(value), m_key(key)
    {}
};

template <class T> struct hkArray_de30
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        AudioHolder* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
};

namespace fnv_00df2640 {
void __cdecl ResizeAudioStream(AudioAllocator* pAllocator, void* pArray, unsigned int auiNewSize);

}  // namespace fnv_00df2640

__declspec(align(16)) struct FNVQuad
{
    unsigned int m_u0;
    unsigned int m_u1;
    unsigned int m_u2;
    unsigned int m_u3;
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);

class hkVector4
{
  public:
    __m128 m_vComponents;
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void _setMul3(const class hkMatrix3& m, const hkVector4& v);
    __forceinline void _setRotatedInverseDir(const class hkMatrix3& m, const hkVector4& v);
};
class hkMatrix3
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
};

struct OutRef
{
    hkVector4* p;
    hkVector4* operator->() const
    {
        return p;
    }
};

struct ArrDF8800
{
    ~ArrDF8800()
    {
        AudioAllocator* pkAllocator = FUN_00c85750()->m_pAllocator;
        int iCapacityAndFlags = m_iCapacityAndFlags;
        m_uiLogicalSize = 0;
        if ((iCapacityAndFlags & 0x80000000) == 0)
            pkAllocator->FreeArray(m_ppGeometries, (iCapacityAndFlags & 0x3fffffff) * 4);
        m_ppGeometries = 0;
        m_iCapacityAndFlags = 0x80000000;
    }
    void** m_ppGeometries;    // 0x00
    int m_uiLogicalSize;              // 0x04
    int m_iCapacityAndFlags;  // 0x08
};

struct CollDF8800
{
    CollDF8800(ArrDF8800& kArray, int iFlags) throw();
    virtual ~CollDF8800()
    {}
    ArrDF8800* m_pkArray;  // 0x04
    int m_iFlags;          // 0x08
};

struct DFB0B0_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float distance;
    int unk44;
    int unk48;
    int unk4c;
};

struct DFB0B0_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int numEntries;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    int unke50;
    int unke54;
    int unke58;
    int unke5c;
    int unke60;
    int unke64;
    int unke68;
    int unke6c;
    int unke70;
    int unke74;
    int unke78;
    int unke7c;
    int unke80;
    int unke84;
    int unke88;
    int unke8c;
    int unke90;
    int unke94;
    int unke98;
    int unke9c;
    int unkea0;
    int unkea4;
    int unkea8;
    int unkeac;
    int unkeb0;
    int unkeb4;
    int unkeb8;
    int unkebc;
    int unkec0;
    int unkec4;
    int unkec8;
    int unkecc;
    int unked0;
    int unked4;
    int unked8;
    int unkedc;
    int unkee0;
    int unkee4;
    int unkee8;
    int unkeec;
    int unkef0;
    int unkef4;
    int unkef8;
    int unkefc;
    int unkf00;
    int unkf04;
    int unkf08;
    int unkf0c;
    int unkf10;
    int unkf14;
    int unkf18;
    int unkf1c;
    int unkf20;
    int unkf24;
    int unkf28;
    int unkf2c;
    int unkf30;
    int unkf34;
    int unkf38;
    int unkf3c;
    int unkf40;
    int unkf44;
    int unkf48;
    int unkf4c;
    int unkf50;
    int unkf54;
    int unkf58;
    int unkf5c;
    int unkf60;
    int unkf64;
    int unkf68;
    int unkf6c;
    DFB0B0_Entry entries;
    DFB0B0_Entry* GetNearestEntry();
};

// Scans the entries array and returns a pointer to the DFB0B0_Entry with the smallest distance value.
// @fnv 0x00dfb0b0
// pdb: hkpWingedEdge::findTriangleOnNearestPlane | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, objrun_prop, low
DFB0B0_Entry* DFB0B0_Owner::GetNearestEntry()
{
    DFB0B0_Entry* e = &entries;
    DFB0B0_Entry* best = e;
    float bestDist = e->distance;
    int i = numEntries - 2;
    __assume(i >= 0);
    for (; i >= 0; i--)
    {
        e++;
        float d = e->distance;
        if (d < bestDist)
        {
            bestDist = d;
            best = e;
        }
    }
    return best;
}

// Calls FUN_00c905b0 on m_pSub if set, clears m_pSub, then calls FUN_00cb0c00 on p.
// @f3 0x007985d0 (community match, verified in this file)
namespace f3m_007985d0 {
namespace c_007985d0 {

struct Thing
{
    int FUN_004bcca0();
};

struct Table
{
    int unk00;
    int unk04;
    int unk08;
    Thing* entries[1];
};

struct Owner
{
    int unk00[0x27];
    Table* table;
    int unkA0[0x14];
    Thing* current;
    void FUN_007985d0();
};

// pdb: CombatController::CheckCurrentWeapon | CombatController.obj | fnv360_0822_retail, caller_sim, low
void Owner::FUN_007985d0()
{
    if (current && table->entries[current->FUN_004bcca0()] != current)
        current = 0;
}

}
}   // namespace f3m_007985d0


AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00de10b0_cls
{
    virtual ~FUN_00de10b0_cls();
    unsigned short m_uSize;
    unsigned short m_u06;

    static void operator delete(void* apMemory) throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, ((FUN_00de10b0_cls*)apMemory)->m_uSize);
    }
};

// Empty virtual destructor; the class operator delete frees the object through the allocator using m_uSize.
// @fnv 0x00de10b0
FUN_00de10b0_cls::~FUN_00de10b0_cls()
{}

// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void FUN_00de3040();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void FUN_00de3040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00de3040
    virtual void FUN_00de3040();
};

Derived::Derived()
{}

namespace fnv_00dfed30 {
// Declares a Heap interface with four unnamed virtual methods and a virtual release(void*, unsigned int).
// @fnv 0x00dfed30
struct Heap
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void release(void*, unsigned int);
};
struct Manager
{
    int unk00, unk04, unk08, unk0c;
    Heap* volatile heap;
};
extern "C" Manager* __cdecl FUN_00c85750();
extern "C" int DAT_0102e388;
}  // namespace fnv_00dfed30

namespace fnv_00dff440 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk (multiple inheritance, second base at +8).
struct PrimaryBase
{
    virtual void FUN_00dff440();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00dff440();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff440
    virtual void FUN_00dff440();
};

Derived::Derived()
{}
}  // namespace fnv_00dff440

// 00dff450: compiler-generated thiscall adjustor thunk (sub ecx,0xc; jmp DestroySelf).
// Reproduce via MI dual-slot override: the override lands in both the primary vftable
// and the secondary vftable (which sits at offset 0xc), so VC9 emits the adjustor thunk.
struct AdjPrim
{
    virtual void FUN_00dff450();
    int p04;
    int p08;
};

struct AdjSec
{
    virtual void FUN_00dff450();
};

struct AdjDerived : AdjPrim, AdjSec
{
// @fnv 0x00dff450
    virtual void FUN_00dff450();
};

static AdjDerived g_adjThunk;

namespace fnv_00dff460 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk (second base of multiple inheritance).
struct PrimaryBase
{
    virtual void FUN_00dff460();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00dff460();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff460
    virtual void FUN_00dff460();
};

Derived::Derived()
{}
}  // namespace fnv_00dff460

struct S00de9bd0_Edge
{
    int edge;
    union
    {
        float fraction;
        unsigned fractionBits;
    };
    S00de9bd0_Edge()
    {}
    S00de9bd0_Edge(int e, float f) : edge(e), fraction(f)
    {}
};
static inline void S00de9bd0_swap(S00de9bd0_Edge& a, S00de9bd0_Edge& b)
{
    S00de9bd0_Edge t = a;
    a = b;
    b = t;
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
struct VelocityVector
{
    union
    {
        __m128 q;
        float lanes[4];
    };
    __forceinline void subtract(const VelocityVector& x, const VelocityVector& y)
    {
        q = _mm_sub_ps(x.q, y.q);
    }
    __forceinline void add(const VelocityVector& x)
    {
        q = _mm_add_ps(q, x.q);
    }
    __forceinline void cross(const VelocityVector& x, const VelocityVector& y)
    {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(x.q, x.q, 0xc9), _mm_shuffle_ps(y.q, y.q, 0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(x.q, x.q, 0xd2), _mm_shuffle_ps(y.q, y.q, 0xc9));
        q = _mm_sub_ps(positive, negative);
    }
    __forceinline float dot(const VelocityVector& x) const
    {
        __m128 terms = _mm_mul_ps(q, x.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_cvtss_f32(_mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), xy));
    }
};
struct VelocityBody
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    VelocityVector linear;
    VelocityVector angular;
    __forceinline void pointVelocity(const VelocityVector& position, const VelocityVector& center,
                                     VelocityVector& result) const
    {
        VelocityVector arm;
        arm.subtract(position, center);
        result.cross(angular, arm);
        result.add(linear);
    }
};

extern "C"
{
    void _ReadWriteBarrier();
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_rcp_ps(__m128);
    __m128 _mm_add_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

struct V4
{
    __m128 q;
    __forceinline void setMul4(const V4& a, const V4& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    __forceinline void mul4(const V4& a)
    {
        q = _mm_mul_ps(q, a.q);
    }
    __forceinline void mul4(__m128 s)
    {
        q = _mm_mul_ps(q, s);
    }
    __forceinline void add4(const V4& a)
    {
        q = _mm_add_ps(q, a.q);
    }
    __forceinline void setMax4(const V4& a, const V4& b)
    {
        q = _mm_max_ps(a.q, b.q);
    }
    __forceinline void setReciprocal4(const V4& d)
    {
        __m128 r = _mm_rcp_ps(d.q);
        q = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, d.q), r));
    }
    __forceinline __m128 getW() const
    {
        return _mm_shuffle_ps(q, q, 0xff);
    }
    __forceinline float horizontalAdd3() const
    {
        __m128 s = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
        float out;
        _mm_store_ss(&out, s);
        return out;
    }
};

extern "C" void _ReadWriteBarrier();

struct EnumU8
{
    unsigned char m_kStorage;
    EnumU8()
    {}
    EnumU8(int value) : m_kStorage((unsigned char)value)
    {}
    EnumU8& operator=(int value)
    {
        m_kStorage = (unsigned char)value;
        return *this;
    }
};

struct JobBase
{
    unsigned char m_type, m_b1;
    EnumU8 m_b2;
    unsigned char m_b3;
    unsigned short m_w4;
    short m_w6;
    int m_8, m_iThirdValue, m_10;
    int* m_p14;
    int m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40;

    __forceinline JobBase(unsigned char type, int value)
        : m_type(type), m_b1(3), m_b2(2), m_w4(0x50), m_w6(-1), m_10(value)
    {
        m_18 = 0;
        m_b2 = 1;
    }
    __forceinline void initHead(unsigned char type)
    {
        m_type = type;
        m_b1 = 3;
        m_b2 = 2;
        m_w4 = 0x50;
        m_w6 = -1;
    }
    __forceinline JobBase(unsigned char type, int value, int a54, int a44)
    {
        _ReadWriteBarrier();
        initHead(type);
        m_1c = a54;
        m_10 = value;
        m_24 = a44;
        m_18 = 0;
        m_b2 = 1;
    }
};

struct JobA : JobBase
{
    __forceinline JobA(int* counter) : JobBase(3, 0)
    {
        m_30 = 0;
        m_p14 = counter;
    }
};

struct JobValues
{
    int first, second;
    JobValues(int a, int b) : first(a), second(b)
    {}
};

struct JobB : JobBase
{
    __forceinline JobB(int a54, int* counter, int a44, int a48, int a60, int a5c) : JobBase(1, a5c, a54, a44)
    {
        m_p14 = counter;
        m_20 = 0x40;
        m_28 = a48;
        m_34 = a60;
        *counter = a48 == 0 ? 1 : (a48 - 1) / 64 + 1;
        m_38 = 0;
        m_3c = 0;
        m_40 = 0;
        m_2c = 0;
        m_30 = 0;
    }
};

class SolBool
{
    char value;

  public:
    inline SolBool()
    {}
    inline SolBool(bool b)
    {
        value = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return value != 0;
    }
    inline SolBool& operator=(bool b)
    {
        value = static_cast<char>(b);
        return *this;
    }
};
typedef __m128 Bndm128;
struct __declspec(align(16)) BndBounds
{
    unsigned short minimum[3];
    unsigned short idHigh;
    unsigned short maximum[3];
    unsigned short idLow;
    void operator=(const BndBounds& v)
    {
        *(Bndm128*)this = *(const Bndm128*)&v;
    }
};

extern "C" void _ReadWriteBarrier(void);
// Today's tree (blk_00de0000_o2.cpp) has no windows.h; declare the Win32 pieces the
// way the unit itself does (see the TlsGetValue profile macro users in the file).
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);

extern unsigned long DAT_0126835c;

typedef void*(__stdcall* PFN_TlsGetValue)(unsigned long dwTlsIndex);

extern "C" void _mm_store_ps(float*, __m128);
struct PulleyObjectBase
{
    int* vtable;
    unsigned short unk04;
    volatile unsigned short referenceCount;
    volatile unsigned int userData;

    PulleyObjectBase()
    {
        referenceCount = 1;
        userData = 0;
    }
};

template <class T> class SuspensionArray
{
  public:
    ~SuspensionArray() throw()
    {
        AudioHolder* holder = FUN_00c85750();
        AudioAllocator& allocator = *holder->m_pAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            allocator.FreeArray(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class SuspensionObject
{
  public:
    ~SuspensionObject() throw()
    {
        m_ppVirtualMethodTable = &DAT_0102e388;
    }
    int* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

extern "C" void _mm_store_ps(float*, __m128);

typedef __m128 S00df8440_V;

// same layout as the unit's FUN_00df3110; its constructor is only declared here, so this function is compiled
// without knowing what that constructor clobbers (the original was compiled before it)
struct S00df8440_BuilderBase
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int m_iArrayLength;
    S00df8440_BuilderBase();
};

struct __declspec(align(16)) S00df8440_Builder : S00df8440_BuilderBase
{
    void FUN_00df3160();
};

namespace SimpleQuad {
struct __declspec(intrin_type) __declspec(align(16)) __m128
{
    float x, y, z, w;
};
extern "C" __m128 _mm_setzero_ps();
extern "C"
{
    __m128 _mm_set_ps1(float);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_rcp_ps(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_cmpeq_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_or_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    void _mm_store_ss(float*, __m128);
    extern const __m128 DAT_010c7170;
    extern const __m128 DAT_010c4c10;
}
struct __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int x, y, z, w;
};
extern "C"
{
    __m128i _mm_setzero_si128();
    __m128i _mm_unpacklo_epi16(__m128i, __m128i);
    __m128i _mm_unpackhi_epi16(__m128i, __m128i);
    __m128i _mm_slli_epi32(__m128i, int);
    __m128i _mm_srli_epi32(__m128i, int);
    __m128 _mm_cvtepi32_ps(__m128i);
}
class ByteAnswer
{
    char value;

  public:
    __forceinline ByteAnswer()
    {}
    __forceinline ByteAnswer(bool b) : value((char)b)
    {}
    __forceinline operator bool() const
    {
        return value != 0;
    }
};
class ScalarValue
{
    __m128 value;

  public:
    __forceinline ScalarValue()
    {}
    __forceinline ScalarValue(__m128 v) : value(v)
    {}
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline operator float() const
    {
        float r;
        _mm_store_ss(&r, value);
        return r;
    }
};
class PVec;
class MaskCell
{
    union
    {
        __m128 bits;
    };

  public:
    __forceinline operator const __m128&() const
    {
        return bits;
    }
    __forceinline void operator=(const __m128& x)
    {
        bits = x;
    }
};
class PMask
{
    MaskCell value;
    friend class PVec;

  public:
    enum Bits
    {
        None = 0,
        X = 1,
        Y = 2,
        Z = 4,
        W = 8,
        XYZ = 7
    };
    __forceinline int tracked(Bits m, int& out) const
    {
        out = _mm_movemask_ps(value);
        return (out & m) == m;
    }
    __forceinline void both(const PMask& a, const PMask& b)
    {
        value = _mm_and_ps(a.value, b.value);
    }
    __forceinline void pick(const PMask& a, const PMask& b, const PMask& m)
    {
        value = _mm_or_ps(_mm_and_ps(m.value, b.value), _mm_andnot_ps(m.value, a.value));
    }
    __forceinline int all(const Bits& m) const
    {
        return (_mm_movemask_ps(value) & m) == m;
    }
};
class PVec
{
    __m128 value;

  public:
    __forceinline void operator=(const PVec& v)
    {
        value = v.value;
    }
    __forceinline void operator=(const __m128& v)
    {
        value = v;
    }
    __forceinline __m128& quad()
    {
        return value;
    }
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline float& at(int i)
    {
        return ((float*)&value)[i];
    }
    __forceinline const float& at(int i) const
    {
        return ((const float*)&value)[i];
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void uniform(float x)
    {
        value = _mm_set_ps1(x);
    }
    __forceinline void sub(const PVec& a, const PVec& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void sub(const PVec& a)
    {
        value = _mm_sub_ps(value, a.value);
    }
    __forceinline void add(const PVec& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void mul(const PVec& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void mul(const PVec& a, const PVec& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void min(const PVec& a, const PVec& b)
    {
        value = _mm_min_ps(a.quad(), b.quad());
    }
    __forceinline void max(const PVec& a, const PVec& b)
    {
        value = _mm_max_ps(a.quad(), b.quad());
    }
    __forceinline void broadcast(const PVec& a, int lane)
    {
        if (lane == 0)
            value = _mm_shuffle_ps(a.value, a.value, 0);
        else if (lane == 1)
            value = _mm_shuffle_ps(a.value, a.value, 85);
        else if (lane == 2)
            value = _mm_shuffle_ps(a.value, a.value, 170);
        else if (lane == 3)
            value = _mm_shuffle_ps(a.value, a.value, 255);
    }
    __forceinline void pick(const PVec& a, const PVec& b, const PMask& m)
    {
        value = _mm_or_ps(_mm_and_ps(m.value, b.value), _mm_andnot_ps(m.value, a.value));
    }
    __forceinline PMask equal(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmpeq_ps(value, a.value);
        return r;
    }
    __forceinline PMask ge(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmple_ps(a.value, value);
        return r;
    }
    __forceinline PMask le(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmple_ps(value, a.value);
        return r;
    }
    __forceinline PMask lt(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmplt_ps(value, a.value);
        return r;
    }
    __forceinline PMask gt(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmplt_ps(a.value, value);
        return r;
    }
    __forceinline ScalarValue dot3(const PVec& a) const
    {
        __m128 p = _mm_mul_ps(value, a.value);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 85), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 170), xy);
    }
    __forceinline ScalarValue invLength() const
    {
        __m128 half = _mm_set_ss(.5f), three = _mm_set_ss(3.f), z = _mm_set_ss(0.f);
        __m128 l = dot3(*this).quad(), eq = _mm_cmpeq_ss(l, z), r = _mm_rsqrt_ss(l);
        __m128 n = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(l, r), r)));
        return _mm_andnot_ps(eq, n);
    }
    __forceinline ScalarValue normalize()
    {
        __m128 l = dot3(*this).quad();
        __m128 r = invLength().broadcast();
        value = _mm_mul_ps(r, value);
        return _mm_mul_ss(l, r);
    }
    __forceinline void inverse3(const PVec& a)
    {
        __m128 b = _mm_shuffle_ps(a.value, _mm_unpackhi_ps(a.value, DAT_010c7170), 196);
        __m128 r = _mm_rcp_ps(b);
        value = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, b), r));
    }
    __forceinline void xyz0(const PVec& a)
    {
        value = _mm_and_ps(a.value, DAT_010c4c10);
    }
    __forceinline void addMul(const PVec& origin, const PVec& scale, const PVec& v)
    {
        value = _mm_add_ps(origin.value, _mm_mul_ps(scale.value, v.value));
    }
};
class PInts
{
    __m128i value;

  public:
    __forceinline void zero()
    {
        value = _mm_setzero_si128();
    }
    __forceinline void first(const PInts& a, const PInts& b)
    {
        value = _mm_unpacklo_epi16(a.value, b.value);
    }
    __forceinline void second(const PInts& a, const PInts& b)
    {
        value = _mm_unpackhi_epi16(a.value, b.value);
    }
    __forceinline void toFloat(PVec& out) const
    {
        const __m128 factor = {1.0e16f, 1.0e16f, 1.0e16f, 1.0e16f};
        __m128i v = value;
        {
            __m128i high = _mm_srli_epi32(v, 16);
            __m128i low = _mm_srli_epi32(_mm_slli_epi32(v, 16), 16);
            __m128 h = _mm_mul_ps(_mm_cvtepi32_ps(high), factor);
            __m128 l = _mm_cvtepi32_ps(low);
            out.quad() = _mm_add_ps(h, l);
        }
    }
};
struct PEntry
{
    union Id
    {
        unsigned value;
        unsigned short halves[2];
        __forceinline const unsigned& get() const
        {
            return value;
        }
    };
    __declspec(align(16)) unsigned short lo[3];
    unsigned short firstId;
    unsigned short hi[3];
    unsigned short secondId;
    __forceinline Id id() const
    {
        Id r;
        r.halves[0] = firstId;
        r.halves[1] = secondId;
        return r;
    }
};
class PNode
{
  public:
    int children;
    union
    {
        int bounds;
        struct
        {
            unsigned short lower, upper;
        };
    };
    __forceinline PNode() : children(0x7fffffff), bounds(0)
    {}
    __forceinline ~PNode()
    {}
    __forceinline int leaf() const
    {
        return ~(children >> 31);
    }
    __forceinline int empty() const
    {
        return ~(children ^ 0x7fffffff);
    }
    __forceinline int axis() const
    {
        return children & 3;
    }
    __forceinline unsigned short min() const
    {
        return lower;
    }
    __forceinline unsigned short max() const
    {
        return upper;
    }
    __forceinline unsigned id() const
    {
        return children & 0x7fffffff;
    }
    __forceinline unsigned count() const
    {
        return bounds;
    }
    __forceinline PNode* left() const
    {
        return (PNode*)((unsigned)this + (children & 0x7ffffffc));
    }
    __forceinline PNode* right() const
    {
        return left() + 1;
    }
};
struct PCollector
{
    virtual ~PCollector()
    {}
    virtual ByteAnswer process(unsigned) = 0;
    virtual ByteAnswer finish() = 0;
    virtual float fraction() = 0;
};
struct PState
{
    __declspec(align(16)) const PNode* node;
    float nearD, farD;
    unsigned unused;
    __forceinline void set(const PNode* n, float a, float b)
    {
        node = n;
        nearD = a;
        farD = b;
    }
};
}
using namespace SimpleQuad;
struct LeafCursor
{
    const PEntry* leaves;
    int mask;
    LeafCursor(const PEntry* p) : leaves(p)
    {}
};

// @f3twin 0x00a6abc0 of 0x005010f0
struct F3Twin_00a6abc0 : public FUN_00de4910_cls { int F3_FUN_00a6abc0() ; };
// pdb: hkDisplaySemiCircle::getNumSegments | hkDisplaySemiCircle.obj | fnv360_0822_retail, objrun_open, low
int F3Twin_00a6abc0::F3_FUN_00a6abc0() 
{
    return m_9c;
}

// @f3 0x00a66dc0 (community match, verified in this file)
extern int DAT_010f3170;
extern int DAT_010f323c;
extern int DAT_00d9b080;
namespace f3m_00a66dc0 {
namespace f3m_00a66dc0 {
namespace na66dc0 {
typedef void* (__stdcall* TlsGetValueFn)(unsigned long index);
struct Heap { void FUN_008f6d90(void* p, int bytes, int type); };
struct Elem { virtual ~Elem(); };
struct ElemArray
{
    Elem** data;
    int count;
    int capacityAndFlags;
    ElemArray* FUN_00a655a0();
};
// 0x00a655a0: file-local initialiser; its body is here so the compiler knows it keeps ecx
__declspec(noinline) ElemArray* ElemArray::FUN_00a655a0()
{
    *(int*)&data = 8;
    count = 8;
    return this;
}
struct Collector
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    void FUN_00a655b0(ElemArray* arr);
    void FUN_00a66d50(void* arg, ElemArray* arr);
};
struct World { void FUN_00909150(ElemArray* arr, int a2, void* a3, int zero, void* a1); };
}
void FUN_00a66dc0(void* a1, int a2, void* a3)
{
    na66dc0::ElemArray arr;
    arr.FUN_00a655a0();
    na66dc0::Collector collector;
    collector.FUN_00a655b0(&arr);
    arr.data = 0;
    arr.count = 0;
    arr.capacityAndFlags = 0x80000000;
    collector.FUN_00a66d50(a1, &arr);
    (*(na66dc0::World**)&DAT_010f323c)->FUN_00909150(&arr, a2, a3, 0, a1);
    while (arr.count != 0)
    {
        na66dc0::Elem* e = arr.data[0];
        if (e)
            delete e;
        arr.data[0] = arr.data[--arr.count];
    }
    if (!(arr.capacityAndFlags & 0x80000000))
    {
        const int allocated = arr.capacityAndFlags & 0x3fffffff;
        na66dc0::Heap* heap = (na66dc0::Heap*)(*(na66dc0::TlsGetValueFn*)&DAT_00d9b080)(*(unsigned long*)&DAT_010f3170);
        heap->FUN_008f6d90(arr.data, allocated * 4, 0x17);
    }
}
}
}   // namespace f3m_00a66dc0

// @f3 0x00a66d50 (community match, verified in this file)
namespace f3m_00a66d50 {
namespace collector_a66d50 {
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    void set(float a, float b, float c, float d) {
        x = a; y = b; z = c; w = d;
    }
};
struct Transform {
    Vector4 rotation[3];
    Vector4 translation;
    void setIdentity() {
        rotation[0].y = 0;
        rotation[0].z = 0;
        rotation[0].w = 0;
        rotation[1].x = 0;
        rotation[1].z = 0;
        rotation[1].w = 0;
        rotation[2].x = 0;
        rotation[2].y = 0;
        rotation[2].w = 0;
        rotation[0].x = 1;
        rotation[1].y = 1;
        rotation[2].z = 1;
        translation.x = translation.y = translation.z = translation.w = 0;
    }
};
struct Points {
    void** data;
    int size;
    int capacityFlags;
};
struct Shape;
struct Collector {
    int fields[4];
    int count;
    void FUN_00a65740(Shape* shape, const Transform& transform, Points& output);
    void FUN_00a66d50(Shape* shape, Points& output);
};
__declspec(noinline) void __fastcall FUN_00a655e0(Collector* collector) { collector->count = 0; }
// pdb: hkpShapeDisplayBuilder::buildDisplayGeometries | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: shape, displayGeometries
void Collector::FUN_00a66d50(Shape* shape, Points& output) {
    Transform transform;
    transform.setIdentity();
    FUN_00a655e0(this);
    output.size = 0;
    FUN_00a65740(shape, transform, output);
}
}
}   // namespace f3m_00a66d50
