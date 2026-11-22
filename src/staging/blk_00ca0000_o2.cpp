#include "f3_common.h"
// SSE_DECLARATIONS_DEFER_TO_SDK
#include <windows.h>
// src/staging/blk_00ca0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void __cdecl FUN_00ca3570(void);

void __cdecl _delete(void* p, int);

struct FUN_00ca3980_class
{
    FUN_00ca3980_class* __thiscall FUN_00ca3980(int);
};

// Calls FUN_00ca3570, then if bit 0 of a is set frees this with size 0x30, and returns this.
// @fnv 0x00ca3980
// pdb: NiBlendInterpolator::`scalar deleting destructor' | NiBlendInterpolator.obj | tesv_win, vtable_prefix, medium
FUN_00ca3980_class* __thiscall FUN_00ca3980_class::FUN_00ca3980(int aiFlags)
{
    FUN_00ca3570();
    if (aiFlags & 1)
        _delete(this, 0x30);
    return this;
}

extern "C" void NiFreeAlias(void*);

struct FUN_00ca5310_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_p;
};

// Returns element 0x24 of the float array at m_p when a and m_p are non-null, otherwise 1.0f.
// @fnv 0x00ca5310
// pdb: bhkPackedNiTriStripsShape::GetScale | bhkPackedNiTriStripsShape.obj | fnv360_0822_retail, objrun_prop, low
float __fastcall GetField24Float(struct FUN_00ca5310_class* pClass)
{
    float result;
    if (pClass && pClass->m_p)
        result = ((float*)pClass->m_p)[0x24];
    else
        result = 1.0f;
    return result;
}

struct FUN_00ca6590_t
{
    int __thiscall FUN_00ca6590();
    FUN_00ca6590_t* __thiscall FUN_00ca6650(int flags);
};
void __cdecl _delete(void* p, unsigned int size);

// Calls FUN_00ca6590, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00ca6650
// pdb: bhkEntity::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00ca6590_t* __thiscall FUN_00ca6590_t::FUN_00ca6650(int flags)
{
    FUN_00ca6590();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_00ca9840_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void SetFieldValue(float v);
};

// @fnv 0x00ca9840
// pdb: hkMalleableConstraintCinfo::SetStrength | bhkMalleableConstraint.obj | fnv360_0721_beta, objrun_open, low
// pdb params: afStrength
void FUN_00ca9840_Class::SetFieldValue(float afValue)
{
    if (m_iWordAt04)
        *(float*)((char*)m_iWordAt04 + 0x1c) = afValue;
}

extern int DAT_010c8288;

extern "C" int __cdecl hkString_strLen(int);

// @fnv 0x00cb0f10
// pdb: hkString::toUpper | hkString.obj | tesv_win, objrun_prop, low
char ToUpperAscii(char acChar)
{
    char r = acChar;
    if (acChar >= 'a' && acChar <= 'z')
        r = acChar - 0x20;
    return r;
}

// @fnv 0x00cb0f30
// pdb: hkString::toLower | hkString.obj | tesv_win, call_dedup, low
char ToLowerAscii(char acChar)
{
    if (acChar >= 'A' && acChar <= 'Z')
        acChar += ' ';
    return acChar;
}

void __cdecl FUN_00cc9640();
extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00cb9b60_class
{
    FUN_00cb9b60_class* DestroyIfFlagged(int flag);
};

// Calls FUN_00cc9640, deletes this with size 0x10 when flag has bit 0 set, and returns this.
// @fnv 0x00cb9b60
// pdb: bhkConstraint::`scalar deleting destructor' | MissileProjectile.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00cb9b60_class* FUN_00cb9b60_class::DestroyIfFlagged(int aiFlags)
{
    FUN_00cc9640();
    if (aiFlags & 1)
        operator delete(this, 0x10);
    return this;
}

namespace fnv_00cbc720 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern void* NiFreeAlias(void*);
extern int DAT_010c91a8;

struct NiTMapBase
{
    int m_data;
    int m_auiShapeKeys;
    void* m_alloc;
    void RemoveAll();
    void FUN_00cbc720();
};

// @fnv 0x00cbc720
void NiTMapBase::FUN_00cbc720()
{
    m_data = (int)&DAT_010c91a8;
    ((NiTMapBaseStub*)this)->RemoveAll();
    NiFreeAlias(m_alloc);
}
}  // namespace fnv_00cbc720

struct FUN_00cbc8f0_cls
{
    void FUN_00cbc8f0(int arg);
};

// Scans the byte buffer at this+0xc backwards from this+0x10-1 and stops at the last index whose byte equals arg.
// @fnv 0x00cbc8f0
// pdb: hkpSimpleContactConstraintData::getContactPointIdAt | hkpCharacterRigidBody.obj | tesv_win, hash, low
void FUN_00cbc8f0_cls::FUN_00cbc8f0(int aiValue)
{
    int count = *(int*)((char*)this + 0x10) - 1;
    if (count >= 0)
    {
        const unsigned char* data = (const unsigned char*)(*(int*)((char*)this + 0xc));
        int val;
        do
        {
            val = data[count];
            if (val == aiValue)
                break;
            --count;
        } while (count >= 0);
    }
}

extern int DAT_010c7310;

void __cdecl FUN_00ca4490();
struct MemoryManager
{
    void __thiscall Deallocate(void* p);
};
extern MemoryManager _g_memoryManager;
struct FUN_00ca4a90_Class
{
    FUN_00ca4a90_Class* __thiscall FUN_00ca4a90(int flags);
};
// Calls FUN_00ca4490, then if flags bit 0 is set and this is non-null, deallocates the block preceding this via _g_memoryManager, and returns this.
// @fnv 0x00ca4a90
// pdb: bhkWorld::`scalar deleting destructor' | bhkWorld.obj | fnv360_0822_retail, objrun_prop, low
FUN_00ca4a90_Class* __thiscall FUN_00ca4a90_Class::FUN_00ca4a90(int flags)
{
    FUN_00ca4490();
    if ((flags & 1) && this)
        _g_memoryManager.Deallocate((char*)this - *(unsigned char*)((char*)this - 1));
    return this;
}

struct bhkRefObject
{
    int __thiscall Initialize();
};
extern int DAT_01030bf4;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268324;

namespace fnv_00cbc550 {
extern int DAT_01268118;
extern int DAT_01268154;
extern int DAT_0126841c;
extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_0108f1bc;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;

struct bhkRefObject
{
    int m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    char m_3c;
    bhkRefObject* Initialize();
};

struct FUN_00cbc550_cls : public bhkRefObject
{
    FUN_00cbc550_cls* __thiscall FUN_00cbc550();
};

// @fnv 0x00cbc550
// pdb: bhkLiquidAction::bhkLiquidAction | bhkLiquidAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
FUN_00cbc550_cls* __thiscall FUN_00cbc550_cls::FUN_00cbc550()
{
    Initialize();
    m_vtbl = (int)&DAT_0102016c;
    m_iThirdValue = 0;
    ++DAT_01268154;
    m_vtbl = (int)&DAT_0102009c;
    ++DAT_01268118;
    m_f14 = 0.0f;
    m_f18 = 0.0f;
    m_10 = 0;
    m_f1c = 0.0f;
    m_vtbl = (int)&DAT_0108f1bc;
    m_f20 = 0.0f;
    m_24 = _NiPoint3_ZERO;
    m_28 = _DAT_011f4270;
    m_2c = _DAT_011f4274;
    m_30 = _NiPoint3_ZERO;
    m_34 = _DAT_011f4270;
    m_38 = _DAT_011f4274;
    m_3c = 1;
    ++DAT_0126841c;
    return this;
}
}  // namespace fnv_00cbc550

namespace fnv_00cbc8b0 {
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern void NiFree(void*);
extern int DAT_010c91a8;
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00cbc8b0 : NiTMapBaseStub
{
    void* m_vtbl;
    void* m_field;
    void* m_p;
    FUN_00cbc8b0* __thiscall FUN_00cbc8b1(int flags);
};
// Sets the vtable, calls RemoveAll, frees m_p, and if flags has bit 0 set deallocates this via g_memoryManager; returns this.
// @fnv 0x00cbc8b0
// pdb: NiTMapBase<DFALL<NiTMapItem<TESObjectCELL *,bool> >,TESObjectCELL *,bool>::`scalar deleting destructor' | BGSSceneInfo.obj | fnv360_0822_retail, vtable, medium
FUN_00cbc8b0* __thiscall FUN_00cbc8b0::FUN_00cbc8b1(int flags)
{
    m_vtbl = &DAT_010c91a8;
    RemoveAll();
    NiFree(m_p);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00cbc8b0

void __cdecl RegisterStaticCollisionAgent(void*);
void __cdecl FUN_00d41f00(void*, int, int);
void __cdecl RegisterScriptHandlers(void*);
void __cdecl FUN_00d40910(void*);
void __cdecl FUN_00d40130(void*);
void __cdecl FUN_00d3fd00(void*);
void __cdecl FUN_00d3ef70(void*);
void __cdecl FUN_00d3dca0(void*);
void __cdecl FUN_00d3cef0(void*);
void __cdecl RegisterHandlers(void*);
void __cdecl FUN_00d3abc0(void*);
void __cdecl FUN_00d39840(void*);
void __cdecl FUN_00d389f0(void*);
void __cdecl FUN_00d377d0(void*);
void __cdecl FUN_00d2e760(void*);

// @f3 0x00943530 (community match, verified in this file)
// pdb: hkpAgentRegisterUtil::_registerTerminalAgents | hkpAgentRegisterUtil.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dis
void __cdecl FUN_00cbfcb0(void* pObject)
{
    RegisterStaticCollisionAgent(pObject);
    FUN_00d41f00(pObject, 1, 1);
    RegisterScriptHandlers(pObject);
    FUN_00d40910(pObject);
    FUN_00d40130(pObject);
    FUN_00d3fd00(pObject);
    FUN_00d3ef70(pObject);
    FUN_00d3dca0(pObject);
    FUN_00d3cef0(pObject);
    RegisterHandlers(pObject);
    FUN_00d3abc0(pObject);
    FUN_00d39840(pObject);
    FUN_00d389f0(pObject);
    FUN_00d377d0(pObject);
    FUN_00d2e760(pObject);
}


struct FUN_00ca5540_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_p;
    int GetEntryValue(int i);
};

// @f3 0x00911780 (community match, verified in this file)
// pdb: bhkPackedNiTriStripsShape::QSubMaterial | bhkPackedNiTriStripsShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: aiKey
int FUN_00ca5540_Class::GetEntryValue(int i)
{
    unsigned char* p = (unsigned char*)(this ? *(unsigned int*)((char*)this + 8) : 0);
    unsigned int uiIndex = (unsigned int)i >> 24;
    unsigned int value;
    if (i != -1 && (int)uiIndex < (int)*(unsigned short*)(*(unsigned int*)(p + 0x84) + 0x10))
    {
        p = *(unsigned char**)(*(unsigned int*)(p + 0x84) + 0x24);
        value = *(unsigned int*)(p + uiIndex * 12 + 8);
    }
    else
    {
        value = *(unsigned int*)((char*)this + 0x10);
    }
    return value & 0x1f;
}


extern void(__cdecl* DAT_010c8d08)(void*);

struct FUN_00ca2020_Class
{
    void FUN_00ca2020();
};

struct FUN_00ca20e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void ClearAndFreeEntries();
};

// @fnv 0x00ca20e0
// pdb: bhkRagdollPenetrationUtil::Clear | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, medium
void FUN_00ca20e0_Class::ClearAndFreeEntries()
{
    unsigned int i;
    for (i = 0; i < (unsigned int)m_iThirdValue; i++)
    {
        FUN_00ca2020_Class* p = *(FUN_00ca2020_Class**)(m_8 + i * 4);
        if (p)
        {
            p->FUN_00ca2020();
            _g_memoryManager.Deallocate(p);
        }
    }
    void** arr = (void**)((char*)this + 4);
    int* pCount = (int*)((char*)this + 8);
    if (*pCount)
    {
        void* vtbl = arr[0];
        ((void(__thiscall*)(void**, void*)) * (void**)((char*)vtbl + 8))(arr, (void*)*pCount);
        arr[1] = 0;
        arr[3] = 0;
        arr[2] = 0;
    }
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
}

extern int(__stdcall* DAT_00fdf1c4)(void*);
extern void(__stdcall* DAT_00fdf1c0)(void*);

struct FUN_00ca47a0_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    FUN_00ca47a0_Class* __thiscall AssignFrom(FUN_00ca47a0_Class* other);
};

// @fnv 0x00ca47a0
// pdb: NiPointer<NiTriStripsData>::operator= | BSTreeModel.obj | fnv360_0721_beta, call_dedup, low
// pdb params: ptr
FUN_00ca47a0_Class* __thiscall FUN_00ca47a0_Class::AssignFrom(FUN_00ca47a0_Class* other)
{
    void* p = m_iWordAt00;
    if (p != other->m_iWordAt00)
    {
        if (p)
        {
            if (!DAT_00fdf1c4((char*)p + 4))
            {
                (*(void(__thiscall**)(void*))(*(int*)p + 4))(p);
            }
        }
        m_iWordAt00 = other->m_iWordAt00;
        if (m_iWordAt00)
        {
            DAT_00fdf1c0((char*)m_iWordAt00 + 4);
        }
    }
    m_iWordAt04 = other->m_iWordAt04;
    return this;
}

struct FUN_00ca5340_class
{
    int __thiscall FUN_00ca5290();
    FUN_00ca5340_class* __thiscall FUN_00ca5340(int flags);
};

// Calls FUN_00ca5290, and if flags has bit 0 set, frees this with size 0x14; returns this.
// @fnv 0x00ca5340
// pdb: bhkWorldObject::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00ca5340_class* FUN_00ca5340_class::FUN_00ca5340(int flags)
{
    FUN_00ca5290();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

extern int _data_011c16bc;
extern int DAT_010c44e4;
extern int DAT_010c761c;
extern int DAT_012682d8;
extern int DAT_012686d0;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vptr;
    char m_iWordAt04[8];
    int m_iThirdValue;
    int m_10;

    S_00cb79d0_Base();
};

struct bhkPackedNiTriStripsShape : public S_00cb79d0_Base
{
    bhkPackedNiTriStripsShape()
    {
        int count = 1;
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        DAT_012680f8 += count;
        m_vptr = &DAT_010c44e4;
        DAT_012686d0 += count;
        m_vptr = &DAT_010c761c;
        DAT_012682d8 += count;
    }
};

// Allocates and constructs a new bhkPackedNiTriStripsShape and returns it.
// @fnv 0x00ca53b0
// pdb: bhkNiTriStripsShape::CreateObject | bhkNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bhkPackedNiTriStripsShape* CreatePackedNiTriStripsShape()
{
    return new bhkPackedNiTriStripsShape;
}

struct NiStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54(NiStream*);
};
struct HC1Base
{
    bool FUN_00aa0ad0(NiStream*);
    bool FUN_00ca54c0(NiStream*);
};
// @fnv 0x00ca54c0
// pdb: bhkExtendedMeshShape::RegisterStreamables | bhkExtendedMeshShape.obj | fnv360_0721_retail, objopen_prop, low
// pdb params: arStream
bool HC1Base::FUN_00ca54c0(NiStream* stream)
{
    NiStream* s = this ? *(NiStream**)((char*)this + 8) : 0;
    (*(NiStream**)((char*)s + 0x84))->v54(stream);
    return FUN_00aa0ad0(stream);
}

// Returns the float at offset 0x80 of the object stored at p+8, or 1.0f if p or that object is null.
// @fnv 0x00ca6620
// pdb: bhkNiTriStripsShape::GetScale | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_prop, medium
float __fastcall FUN_00ca6620(void* p, int)
{
    float v;
    if (p && *(void**)((char*)p + 8))
        v = *(float*)((char*)*(void**)((char*)p + 8) + 0x80);
    else
        v = 1.0f;
    return v;
}

// @fnv 0x00ca98e0
// pdb: MagicSystem::GetChameleonMinRefraction | MagicSystem.obj | fnv360_0822_retail, call_seq, medium
float __cdecl FUN_00ca98e0()
{
    return 3.402820018375656e+38;
}

extern int DAT_0102e388;
// @fnv 0x00ca9900
void __fastcall FUN_00ca9900(int* p)
{
    *p = (int)&DAT_0102e388;
}

void __cdecl _delete(void* p, int size);

struct FUN_00ca9920_class
{
    void __thiscall FUN_00ca9860();
    FUN_00ca9920_class* __thiscall FUN_00ca9920(int flags);
};

// @fnv 0x00ca9920
// pdb: BSFaceGenModelExtraData::`scalar deleting destructor' | BSFaceGenModel.obj | fnv360_0822_retail, vtable, high
FUN_00ca9920_class* __thiscall FUN_00ca9920_class::FUN_00ca9920(int flags)
{
    FUN_00ca9860();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_00ca99f0 {
extern int _data_011c16bc;
extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size) throw();
};

struct S_00cb79d0_Base : public A51BF0Base
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;

    S_00cb79d0_Base();
};

struct bhkConstraint : public S_00cb79d0_Base
{
    int m_iThirdValue;

    bhkConstraint()
    {
        *(int**)this = &DAT_0108febc;
        m_iThirdValue = 0;
        DAT_01268188 += 1;
        *(int**)this = &DAT_010c81ac;
        DAT_0126830c += 1;
    }
};

// Allocates and constructs a new bhkConstraint, returning the pointer.
// @fnv 0x00ca99f0
// pdb: hkMalleableConstraintCinfo::ApplyScale | bhkMalleableConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: afScale, apInfo
bhkConstraint* FUN_00ca99f0()
{
    return new bhkConstraint;
}
}  // namespace fnv_00ca99f0

namespace fnv_00caa1c0 {
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

extern int _data_011c16bc;
extern char DAT_0108febc[];
extern char DAT_010c5ce4[];
extern int DAT_01268188;
extern int DAT_01268318;

struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;

    S_00cb79d0_Base();
};

struct bhkConstraint : public S_00cb79d0_Base
{
    bhkConstraint() : S_00cb79d0_Base()
    {
        m_vtbl = DAT_0108febc;
        m_iThirdValue = 0;
        ++DAT_01268188;
        m_vtbl = DAT_010c5ce4;
        ++DAT_01268318;
    }
};

// Allocates and constructs a new bhkConstraint object, returning the pointer.
// @fnv 0x00caa1c0
bhkConstraint* __cdecl FUN_00caa1c0()
{
    return new bhkConstraint();
}
}  // namespace fnv_00caa1c0

struct NiStream;
struct FUN_00cac980_Holder
{
    void* hkpCharacterProxy_getShapePhantom();
};
struct BaseThunk
{
    bool FUN_00a81fe0(NiStream&);
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cac980_Holder* m_8;
};
struct FUN_00cac070_Stub : BaseThunk
{
    void FUN_00cac070(NiStream&);
};
// @f3 0x0092ab00 (community match, verified in this file)
// pdb: bhkCharacterProxy::RegisterStreamables | bhkCharacterProxy.obj | fnv360_0721_beta, objrun, medium
// pdb params: arStream
void FUN_00cac070_Stub::FUN_00cac070(NiStream& stream) {
    if (this && m_8) {
        void* resolved=m_8->hkpCharacterProxy_getShapePhantom();
        if (resolved) {
            void* object=*(void**)((char*)resolved + 0xc);
            if (object) ((void(__thiscall*)(void*, NiStream&))(*(void***)object)[21])(object, stream);
        }
    }
    FUN_00a81fe0(stream);
}


struct FUN_00cac920_Class
{
    char pad[0x30];
    void* m_30;
    char pad2[0x24];
    float m_58;
    float m_5c;
    void __thiscall FUN_00cac920(void* body);
};

// Computes pos as m_5c + m_58 and passes it with body to the phantom's method at m_30.
// @f3 0x006fbf40 (community match, verified in this file)
extern int DAT_0108d0a0;
float __cdecl FUN_005a1980();
namespace f3m_006fbf40 {
struct ScaledValueView6fbf40
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual bool Slot35C();
    void FUN_006f6120(int kind, float value);
};
}

// pdb: Actor::GetShouldCheckMagicNode | Actor_Magic.obj | fnv360_0822_debug, callee_sim, low
void FUN_00cac920_Class::FUN_00cac920(void* encodedValue)
{
    f3m_006fbf40::ScaledValueView6fbf40* self = reinterpret_cast<f3m_006fbf40::ScaledValueView6fbf40*>(this);
    if (self->Slot35C() && DAT_0108d0a0 == 0) {
        float& value = reinterpret_cast<float&>(encodedValue);
        value *= FUN_005a1980();
        self->FUN_006f6120(0xc, value);
    }
}


extern int DAT_010c8b0c;
extern int DAT_01268648;
struct FUN_00cb99a0_class
{
    void __thiscall FUN_00cb99a0(int a);
};
struct FUN_00cb9b30_class : FUN_00cb99a0_class
{
    int m_vtbl;
    FUN_00cb9b30_class(int a);
};
// @fnv 0x00cb9b30
// pdb: bhkBallAndSocketConstraint::bhkBallAndSocketConstraint | bhkRagdollTemplate.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arInfo
FUN_00cb9b30_class::FUN_00cb9b30_class(int aiValue)
{
    FUN_00cb99a0_class::FUN_00cb99a0(aiValue);
    m_vtbl = (int)&DAT_010c8b0c;
    DAT_01268648++;
}

struct FUN_00cc66b0
{
    virtual ~FUN_00cc66b0();
};

struct FUN_00cb9c10_class : FUN_00cc66b0
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c10_class* __thiscall FUN_00cb9c10(int flags);
};

// Calls the base destructor and, when flags has bit 0 set, frees this with size 0x10; returns this.
// @fnv 0x00cb9c10
// pdb: bhkHingeConstraint::`scalar deleting destructor' | MissileProjectile.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00cb9c10_class* FUN_00cb9c10_class::FUN_00cb9c10(int flags)
{
    this->FUN_00cc66b0::~FUN_00cc66b0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

struct MemoryManagerReallocateHelper
{
    void* __thiscall Reallocate(void* p, unsigned int size);
};

struct FUN_00cb9cc0_class
{
    void* __thiscall ReallocateArray(void* p, unsigned int count);
};

// @fnv 0x00cb9cc0
// pdb: BSSimpleArray<BGSBodyPart *,1024>::_Reallocate | HitData.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* FUN_00cb9cc0_class::ReallocateArray(void* pBuffer, unsigned int count)
{
    return ((MemoryManagerReallocateHelper*)&_g_memoryManager)->Reallocate(pBuffer, count * 4);
}

// Sets each of the n ints pointed to by p to 0, skipping null p and advancing the pointer.
// @fnv 0x00cb9d50
void __stdcall FUN_00cb9d50(int* paiValues, unsigned int n)
{
    while (n > 0)
    {
        if (paiValues)
            *paiValues = 0;
        ++paiValues;
        --n;
    }
}

extern void(__stdcall* DAT_010c8d1c)(void*);

void __cdecl FUN_00cba1d0();

struct FUN_00cba6d0_class
{
    FUN_00cba6d0_class* __thiscall FUN_00cba6d0(int flags);
};

// @fnv 0x00cba6d0
// pdb: NiPSysAirFieldAirFrictionCtlr::`scalar deleting destructor' | NiPSysAirFieldAirFrictionCtlr.obj | fnv360_0822_retail, objrun_prop, low
FUN_00cba6d0_class* __thiscall FUN_00cba6d0_class::FUN_00cba6d0(int flags)
{
    FUN_00cba1d0();
    if (flags & 1)
        _delete(this, 0x40);
    return this;
}

namespace fnv_00cbdae0 {
extern int _data_011c16bc;
extern int DAT_0108febc;
extern int DAT_0108fddc;
extern int DAT_01268188;
extern int DAT_01268434;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;

    S_00cb79d0_Base();
};

struct bhkConstraint : S_00cb79d0_Base
{
    int m_iThirdValue;

    bhkConstraint();
};

bhkConstraint::bhkConstraint() : S_00cb79d0_Base()
{
    *(void**)this = &DAT_0108febc;
    m_iThirdValue = 0;
    ++DAT_01268188;
    *(void**)this = &DAT_0108fddc;
    ++DAT_01268434;
}

// Allocates and constructs a new bhkConstraint object, returning the pointer.
// @fnv 0x00cbdae0
// pdb: bhkHingeConstraint::CreateObject | bhkHingeConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
bhkConstraint* __cdecl FUN_00cbdae0()
{
    return new bhkConstraint();
}
}  // namespace fnv_00cbdae0

extern float g_fCA0CD0StepTime;
extern float DAT_011ac39c;

__int64 CA0CD0GetPerformanceCounter();

class CA0CD0World
{
  public:
    void Reset();
};

struct CA0CD0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA0CD0World* m_pkWorld;
    int unk14;
    int unk18;
    int unk1C;
    bool m_bValueAt0C;
};

class CA0CD0Manager
{
  public:
    int unk00;
    int unk04;
    CA0CD0Entry** m_ppkEntries;
    unsigned int m_uiCount;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __int64 m_i64StartTime;
    __int64 m_i64Duration;

    void ResetEntries();
};

// @fnv 0x00ca0cd0
// pdb: bhkRagdollPenetrationUtil::ResetSystems | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, medium
void CA0CD0Manager::ResetEntries()
{
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        m_ppkEntries[i]->m_bValueAt0C = true;
        m_ppkEntries[i]->m_pkWorld->Reset();
    }
    float fStepMilliseconds = g_fCA0CD0StepTime * 1000.0;
    m_i64StartTime = CA0CD0GetPerformanceCounter();
    m_i64Duration = (__int64)(DAT_011ac39c * fStepMilliseconds);
}

extern int DAT_010c7310;
extern void(__stdcall* DAT_010c7318)(void*);

extern MemoryManager _g_memoryManager;

struct SubObject04
{
    virtual ~SubObject04();
    virtual void Slot1();
    virtual void Free(void* apPtr);
    int unk04;
    int unk08;
    int unk0c;

    SubObject04();
};

struct Flag18
{
    unsigned char m_v;
    Flag18()
    {
        m_v = 0;
    }
    ~Flag18();
};

SubObject04::SubObject04()
{
    unk04 = 0;
    unk08 = 0;
    unk0c = 0;
}

struct GuardBase04
{
    GuardBase04()
    {}
    ~GuardBase04();
};

struct FUN_00ca0dc0_cls : GuardBase04
{
    virtual ~FUN_00ca0dc0_cls();
    SubObject04 m_sub04;
    int unk14;
    unsigned char m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;

    FUN_00ca0dc0_cls();
};

// Constructor that zeroes m_18 through m_2c and frees m_sub04's unk04 pointer if set, resetting its fields.
// @fnv 0x00ca0dc0
// pdb: bhkRagdollPenetrationUtil::bhkRagdollPenetrationUtil | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, low
FUN_00ca0dc0_cls::FUN_00ca0dc0_cls() : m_sub04()
{
    SubObject04* pSubObject = &m_sub04;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    if (pSubObject->unk04 != 0)
    {
        pSubObject->Free((void*)pSubObject->unk04);
        pSubObject->unk04 = 0;
        pSubObject->unk0c = 0;
        pSubObject->unk08 = 0;
    }
    m_28 = 0;
    m_2c = 0;
}

// BSSimpleArray-style container of pointer-sized elements.
class CA0E60Array
{
  public:
    void** m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    virtual ~CA0E60Array();
    virtual void** Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void** pBuffer);

    void FUN_00cb9ce0(unsigned int uiNewAlloc, unsigned int uiCopyCount);

    __forceinline void SetSize(unsigned int uiSize)
    {
        if (uiSize == 0)
        {
            if (m_pBuffer)
            {
                Free(m_pBuffer);
                m_pBuffer = 0;
                m_uiCapacity = 0;
                m_uiSize = 0;
            }
        }
        else if (uiSize > m_uiCapacity)
        {
            if (m_uiCapacity == 0)
                m_pBuffer = Allocate(uiSize);
            else
                FUN_00cb9ce0(uiSize, m_uiSize);
            m_uiCapacity = uiSize;
            m_uiSize = uiSize;
        }
        else if (uiSize < m_uiSize)
        {
            m_uiSize = uiSize;
            if (uiSize <= m_uiCapacity >> 2)
            {
                FUN_00cb9ce0(uiSize, uiSize);
                m_uiCapacity = uiSize;
            }
        }
        else
        {
            m_uiSize = uiSize;
        }
    }

    void CopyTo(CA0E60Array& kDest) const;
};

// Resizes the destination array to this array's size and copies each element pointer into it.
// @fnv 0x00ca0e60
// pdb: BSSimpleArray<unsigned int,1024>::CopyTo<1024> | PathingRequestCoveredMove.obj | fnv360_0822_retail, call_seq, low
// pdb params: aDestArray
void CA0E60Array::CopyTo(CA0E60Array& kDest) const
{
    kDest.SetSize(m_uiSize);
    for (unsigned int i = 0; i < m_uiSize; i++)
        kDest.m_pBuffer[i] = m_pBuffer[i];
}

struct CA1080_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};

struct CA1080_Holder
{
    int unk00;
    int unk04;
    int unk08;
    CA1080_Shape* shape;
};

struct CA1080_Entry
{
    CA1080_Holder* holder;
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
};

struct CA1080_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    CA1080_Entry* entries;
    unsigned short entryCount;
    unsigned short unkb2;
    CA1080_Holder** holders;
    int holderCount;
};

struct CA1080_NodeList
{
    CA1080_Node** data;
    int count;
    CA1080_Node* GetAt(int i) const
    {
        return data[i];
    }
};

struct CA1080_PtrArray
{
    virtual void v00();
    virtual void** Allocate(unsigned int count);
    virtual void v08();
    virtual void** Reallocate(void** data, unsigned int count);

    void** data;
    unsigned int size;
    unsigned int capacity;

    void Add(void* item)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                {
                    data = Reallocate(data, newCap);
                }
                else
                {
                    data = Allocate(newCap);
                    capacity = newCap;
                }
                capacity = newCap;
            }
        }
        size++;
        data[size - 1] = item;
    }
};

// For each node in list, adds node->m_0c to out when its entries are not all type 11 and its holders are not all non-type-11.
// @f3 0x00918100 (community match, verified in this file)
struct ShapeView1080
{
    void** table;
    int GetType() { return ((int (__thiscall*)(ShapeView1080*))table[4])(this); }
};
struct HolderView1080
{
    int unk00;
    int unk04;
    int unk08;
    ShapeView1080* shape;
};
struct EntryView1080
{
    HolderView1080* holder;
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
};
struct NodeView1080
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    EntryView1080* entries;
    unsigned short entryCount;
    unsigned short unk9e;
    HolderView1080** holders;
    int holderCount;
};
inline NodeView1080* NodeAt1080(CA1080_NodeList* list,int index)
{
    return reinterpret_cast<NodeView1080*>(list->GetAt(index));
}
// pdb: bhkRagdollPenetrationUtil::FindLeaves | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arRigidBodies, arLeaves
void __stdcall CollectMixedTypeNodes(CA1080_NodeList* list, CA1080_PtrArray* out)
{
    for (int i = 0; i < list->count; i++)
    {
        bool bAllEntriesType11 = true;
        for (int j = 0; j < NodeAt1080(list,i)->entryCount && bAllEntriesType11; j++)
        {
            bAllEntriesType11 = NodeAt1080(list,i)->entries[j].holder->shape->GetType() == 11;
        }
        bool other = false;
        for (int k = 0; k < NodeAt1080(list,i)->holderCount && !other; k++)
        {
            other = NodeAt1080(list,i)->holders[k]->shape->GetType() != 11;
        }
        if (!bAllEntriesType11 && !other)
        {
            NodeView1080* node = NodeAt1080(list,i);
            out->Add(node ? node->m_0c : 0);
        }
    }
}


struct FNVTaskAllocator
{
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void Free(void* memory, unsigned int byteCount);
};
struct FNVTaskMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FNVTaskAllocator* allocator;
};
extern "C" FNVTaskMemoryRouter* __cdecl FUN_00c85750();

extern __declspec(thread) int g_iCA2020AllocTag;

struct CA2020AllocTagScope
{
    int m_iSaved;

    CA2020AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA2020AllocTag;
        g_iCA2020AllocTag = aiAllocationTag;
    }
    ~CA2020AllocTagScope()
    {
        g_iCA2020AllocTag = m_iSaved;
    }
};

// Destructor: deletes m_pkFirst and m_pkSecond, removes references from m_pkShape and m_pkBody, under an alloc-tag scope of 0x10.
// @f3 0x0057b4d0 (community match, verified in this file)
namespace f3m_0057b4d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);

struct RefObj57B
{
    unsigned int m_uiRefCount;
    virtual ~RefObj57B();
    virtual void DeleteThis();
    inline void IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
    inline void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

template <class T>
class Ptr57B
{
public:
    T* m_pObject;
    Ptr57B& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const { return m_pObject; }
};

struct Owner57B
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b();
    virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39();
    virtual void Detach(RefObj57B* pkObject);          // slot 0x3a -> +0xe8
};

struct Link57B
{
    int unk00;
    Owner57B* m_pkOwner;      // +4
    Ptr57B<RefObj57B> m_spObject;   // +8
};

struct Part57B { void FUN_00576930(); void FUN_00576050(); };
struct Node57B { void FUN_00580ae0(); };

struct Holder57B
{
    char m_00[0x24];
    Link57B* m_pkLink;   // +0x24
    Node57B* m_pkNode28; // +0x28
    Part57B* m_pkPart;   // +0x2c
    Node57B* m_pkNode30; // +0x30
    Node57B* m_pkNode34; // +0x34
    void FUN_0057b4d0();
};

// pdb: Sky::UnloadAllTextures | Sky.obj | fnv360_0822_retail, call_dedup, low
void Holder57B::FUN_0057b4d0()
{
    if (m_pkPart)
    {
        m_pkPart->FUN_00576930();
        m_pkPart->FUN_00576050();
    }
    if (m_pkNode30)
        m_pkNode30->FUN_00580ae0();
    if (m_pkNode34)
        m_pkNode34->FUN_00580ae0();
    if (m_pkNode28)
        m_pkNode28->FUN_00580ae0();
    Link57B* pkLink = m_pkLink;
    if (pkLink)
    {
        Owner57B* pkOwner = pkLink->m_pkOwner;
        if (pkOwner)
            pkOwner->Detach(pkLink->m_spObject);
        pkLink->m_spObject = 0;
    }
}
}   // namespace f3m_0057b4d0


struct FUN_00a5d3d0_class
{
    void __thiscall FUN_00a5d3d0();
};

struct FUN_00ca3570_class : FUN_00a5d3d0_class
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;

    void __thiscall FUN_00ca3570();
};

extern "C" char DAT_010c740c[];
extern MemoryManager _g_memoryManager;

// @fnv 0x00ca3570
// pdb: hkPackedNiTriStripsData::~hkPackedNiTriStripsData | hkPackedNiTriStripsShape.obj | fnv360_1110_retail, objrun_open, low
void __thiscall FUN_00ca3570_class::FUN_00ca3570()
{
    m_vtbl = DAT_010c740c;

    if (unk14)
        _g_memoryManager.Deallocate(unk14);

    if (unk18)
        _g_memoryManager.Deallocate(unk18);

    if (unk24)
        _g_memoryManager.Deallocate(unk24);

    if (unk20)
        _g_memoryManager.Deallocate(unk20);

    FUN_00a5d3d0_class::FUN_00a5d3d0();
}

struct Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int* m_pValues;
};

struct Owner
{
    int unk00[29];
    Table* m_pTable;

    int GetValueByIndex(unsigned int a1);
};

// Extracts a 24-bit-shifted index from a1, bounds-checks it against m_pTable->unk10, and returns the value at that index times 3 from m_pValues.
// @fnv 0x00ca3670
// pdb: hkPackedNiTriStripsShape::getCollisionFilterInfo | hkPackedNiTriStripsShape.obj | fnv360_1110_retail, objrun_open, low
// pdb params: aKey
int Owner::GetValueByIndex(unsigned int a1)
{
    Table* pSearchEntries = m_pTable;
    int iIndex = (int)(a1 >> 24);
    if (iIndex >= (int)pSearchEntries->unk10)
    {
        return 0;
    }
    return pSearchEntries->m_pValues[iIndex * 3];
}

namespace fnv_00ca40f0 {
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

struct FUN_00ca40f0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00ca3b90();

    FUN_00ca40f0_cls* FUN_00ca40f0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00ca40f0

void __cdecl FUN_00aa10f0(void*) throw(...);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct __declspec(novtable) CombinedBase
{
    virtual ~CombinedBase() throw(...);
    unsigned int unknown_04, unknown_08, unknown_0c, unknown_10, unknown_14;
};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        FUN_00aa10f0(data);
    }
    void* data;
};
struct __declspec(novtable) FUN_00ca4490 : CombinedBase
{
    struct ResourceMemberLayout
    {
        void* vtable;
        void* data;
        ~ResourceMemberLayout() throw(...);
    } resource;
    virtual ~FUN_00ca4490() throw(...);
};
// @f3 0x00554c10 (community match, verified in this file)
struct DtorCallHelper
{
    void FUN_00554a50();
};

struct FUN_00553f10
{
    virtual ~FUN_00553f10();
};

struct MidDtorBase : FUN_00553f10
{
    virtual ~MidDtorBase() {}
};

FUN_00ca4490::ResourceMemberLayout::~ResourceMemberLayout() throw(...)
{
    ((ResourceMember*)this)->ResourceMember::~ResourceMember();
}

__forceinline CombinedBase::~CombinedBase() throw(...)
{
    ((MidDtorBase*)this)->MidDtorBase::~MidDtorBase();
}

// pdb: TESIdleManager::~TESIdleManager | TESIdleManager.obj | fnv360_0822_retail, call_dedup, low
FUN_00ca4490::~FUN_00ca4490() throw(...)
{
    ((DtorCallHelper*)this)->FUN_00554a50();
}


struct FUN_00ca4780_tableEntry
{
    unsigned int m_iIndex;
    void* m_pIntegerData;
};

struct FUN_00ca4780_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    FUN_00ca4780_tableEntry* m_pTable;
    void* FUN_00ca4780(unsigned int a1);
};

// @fnv 0x00ca4780
void* FUN_00ca4780_cls::FUN_00ca4780(unsigned int a1)
{
    FUN_00ca4780_tableEntry* pSearchEntries = m_pTable;
    unsigned int iIndex = a1 >> 20;
    return pSearchEntries[iIndex].m_pIntegerData;
}

struct S_00ca49a0_Obj
{
    long m_refs;
    virtual void vfn0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_refs))
            DeleteThis();
    }
};

struct S_00ca49a0_Ptr
{
    S_00ca49a0_Obj* m_p;
    S_00ca49a0_Ptr(S_00ca49a0_Obj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    S_00ca49a0_Ptr(const S_00ca49a0_Ptr& o)
    {
        m_p = o.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00ca49a0_Ptr()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00ca49a0_Ptr& operator=(const S_00ca49a0_Ptr& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct S_00ca49a0_Elem
{
    S_00ca49a0_Ptr obj;
    int unk04;
    S_00ca49a0_Elem(int v = 0) : obj(0)
    {
        unk04 = v;
    }
    bool operator==(const S_00ca49a0_Elem& o) const
    {
        return obj.m_p == o.obj.m_p && unk04 == o.unk04;
    }
    bool operator!=(const S_00ca49a0_Elem& o) const
    {
        return !(*this == o);
    }
};

struct S_00ca49a0_Array
{
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    int unk08;
    unsigned int m_uiESize;
    unsigned int m_uiCount;
    void FUN_00ca49a0(unsigned int idx, const S_00ca49a0_Elem& e);
};

// Stores element e at index idx, growing m_uiESize and adjusting m_uiCount when the slot's empty/non-empty state changes.
// @fnv 0x00ca49a0
// pdb: NiTLargeArray<hkNiTriStripsData,NiTMallocInterface<hkNiTriStripsData> >::SetAt | hkNiTriStripsShape.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: uiIndex, element
void S_00ca49a0_Array::FUN_00ca49a0(unsigned int uiIndex, const S_00ca49a0_Elem& arElem)
{
    if (uiIndex >= m_uiESize)
    {
        m_uiESize = uiIndex + 1;
        if ((arElem != S_00ca49a0_Elem(0)))
            m_uiCount++;
    }
    else
    {
        if ((arElem != S_00ca49a0_Elem(0)))
        {
            if (m_pBase[uiIndex] == S_00ca49a0_Elem(0))
                m_uiCount++;
        }
        else if (m_pBase[uiIndex] != S_00ca49a0_Elem(0))
        {
            m_uiCount--;
        }
    }
    m_pBase[uiIndex] = arElem;
}

struct HandlePage
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    unsigned short m_40;
};

struct HandleSlot
{
    HandlePage* m_pHandlePage;
    int m_04;
};

struct HandleOwner
{
    bool __thiscall IsDegenerate(unsigned int handle);
};

class HandleManager
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    HandleSlot* m_88;
    int m_8C;
    int m_90;

    int __thiscall FUN_00ca4ac0(int handle);
};

// @fnv 0x00ca4ac0
// pdb: hkNiTriStripsShape::getNextKey | hkNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: aOldKey
int HandleManager::FUN_00ca4ac0(int handle)
{
    unsigned int cur = (unsigned int)handle;
    for (;;)
    {
        cur++;
        unsigned int page = cur >> 0x14;
        int lo = (int)(cur & 0xfffff);
        int iPageCount = (int)m_88[page].m_pHandlePage->m_40;
        if (lo >= iPageCount)
        {
            cur = (page + 1) << 0x14;
        }
        int iPageIndex = (int)(cur >> 0x14);
        if (iPageIndex >= m_90)
        {
            return -1;
        }
        HandleOwner* owner = (HandleOwner*)((char*)this - 0x10);
        if (!owner->IsDegenerate(cur))
        {
            return (int)cur;
        }
    }
}

struct RefEntryObject
{
    virtual void Unknown();
    virtual void Release();
    volatile long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};
struct RecordEntry
{
    NiPointer<RefEntryObject> object;
    unsigned int value;
    RecordEntry() : object(), value(0)
    {}
};
struct RecordArray
{
    void* vtable;
    RecordEntry* records;
    unsigned int capacity;
    unsigned int count;
    unsigned int elementSize;
    void ClearRecords();
};
// Resets every record in the array to a default RecordEntry, then sets count and elementSize to zero.
// @fnv 0x00ca4b20
// pdb: NiTLargeArray<hkNiTriStripsData,NiTMallocInterface<hkNiTriStripsData> >::RemoveAll | hkNiTriStripsShape.obj | fnv360_0822_retail, call_seq, medium
void RecordArray::ClearRecords()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        records[i] = RecordEntry();
    }
    count = 0;
    elementSize = 0;
}

class FUN_00ca4d20_cls;
class FNVSub3Blob
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVSub4
{
  public:
    void Attach(void* p);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVEntry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};
class FNVSub2
{
  public:
    void Reset();
    void Grow(void* p);
    void Store(unsigned int index, FNVEntry* entry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    void* m_14;
};
class FNVArg
{
  public:
    unsigned int unk00;
    float m_04;
    FNVSub2 m_08;
    FNVSub4 m_20;
};
class FUN_00ca4d20_cls
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    FNVSub3Blob m_80;
    float m_90;
    unsigned int unk94;
    FNVEntry* m_98;
    unsigned int unk9c;
    int m_a0;
    void CopyEntriesToArg(FNVArg* a1);
};

// Copies m_90 into the arg's m_04, resets and fills its m_08 sub-list from m_98 entries, and attaches m_80 to its m_20 sub-object.
// @f3 0x00910c50 (community match, verified in this file)
// pdb: hkNiTriStripsShape::CopyCinfo | hkNiTriStripsShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void FUN_00ca4d20_cls::CopyEntriesToArg(FNVArg* a1)
{
    FNVSub2* s = &a1->m_08;
    a1->m_04 = m_90;
    s->Reset();
    *(float*)&a1->m_20.unk00 = *(float*)&m_80.unk00;
    *(float*)&a1->m_20.unk04 = *(float*)&m_80.unk04;
    *(float*)&a1->m_20.unk08 = *(float*)&m_80.unk08;
    *(float*)&a1->m_20.unk0c = *(float*)&m_80.unk0c;
    for (int i = 0; i < m_a0; ++i)
    {
        FNVEntry* e = &m_98[i];
        unsigned int idx = s->m_0c;
        if (idx >= s->m_08)
            s->Grow((char*)s->m_14 + idx);
        s->Store(idx, e);
    }
}


struct S_00ca4e10_Out
{
    int unk00;
    void* unk04;
};

struct S_00ca4e10_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual char* v10();
};

struct S_00ca4e10_Cls
{
    int unk00;
    int unk04;
    S_00ca4e10_Obj* unk08;
    void FUN_00c84e20(S_00ca4e10_Out* out);
    char* bhkBvTreeShape_CopyCinfo(S_00ca4e10_Out* out);
};

// Calls FUN_00c84e20 on out, then stores the object's v10() result minus 0x10 (or null) into out->unk04 and returns it.
// @f3 0x00910dc0 (community match, verified in this file)
struct S_00ca4e10_Obj_V14 : S_00ca4e10_Obj
{
    virtual char* v14();
};

struct S_008f75b0_Cls
{
    void FUN_008f75b0(S_00ca4e10_Out* out);
};

// pdb: bhkBvTreeShape::CopyCinfo | bhkBvTreeShape.obj | fnv360_0822_retail, objrun + bridge(caller_sim|call_seq) + skyrim(objopen_prop), high
char* S_00ca4e10_Cls::bhkBvTreeShape_CopyCinfo(S_00ca4e10_Out* out)
{
    ((S_008f75b0_Cls*)this)->FUN_008f75b0(out);
    char* r;
    char* p;
    S_00ca4e10_Obj* o;
    if (this && (o = unk08) != 0 && (p = ((S_00ca4e10_Obj_V14*)o)->v14()) != 0)
        r = p - 0x10;
    else
        r = 0;
    out->unk04 = r;
    return r;
}


extern int DAT_012682d8;
struct FUN_00cd2de0
{
    virtual ~FUN_00cd2de0();
};
struct FUN_00ca5290 : FUN_00cd2de0
{
    virtual ~FUN_00ca5290();
    void FUN_00c876a0();
};
// Calls FUN_00c876a0 then decrements the global counter DAT_012682d8.
// @fnv 0x00ca5290
// pdb: bhkBvTreeShape::GetShapeCollection | TESObjectREFR.obj | tesv_win, objopen_prop, low
FUN_00ca5290::~FUN_00ca5290()
{
    FUN_00c876a0();
    --DAT_012682d8;
}

extern int DAT_012682dc;

// @fnv 0x00ca5300
// pdb: bhkRefObject::GetRTTI | bhkRefObject.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
int* __cdecl bhkRefObject_GetRTTI()
{
    return &DAT_012682dc;
}

struct MatchData
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int value84;
};
struct MatchObject
{
    int unk00;
    int unk04;
    MatchData* data;
    bool __thiscall FUN_00c84dc0(MatchObject* rhs);
    bool __thiscall Equals(MatchObject* rhs);
};
// Calls FUN_00c84dc0(rhs); if it returns true, also compares value84 of this->data and rhs->data and returns that result.
// @fnv 0x00ca54f0
// pdb: bhkPackedNiTriStripsShape::IsEqual | bhkPackedNiTriStripsShape.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: bhkExtendedMeshShape::IsEqual)
// pdb params: apObject
bool __thiscall MatchObject::Equals(MatchObject* rhs)
{
    bool result = FUN_00c84dc0(rhs);
    if (result)
    {
        MatchData* right = rhs ? rhs->data : 0;
        MatchData* left = this ? this->data : 0;
        result = left->value84 == right->value84;
    }
    return result;
}

struct S_00ca59d0_Bin
{
    int unk00;
    unsigned int unk04;
    unsigned int(__cdecl* unk08)(S_00ca59d0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* unk0C)(S_00ca59d0_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* buf, unsigned int bytes, unsigned int* compSize, unsigned int n)
    {
        unk04 += unk0C(this, buf, bytes, compSize, n);
    }
};
template <class T> inline void S_00ca59d0_Save(S_00ca59d0_Bin& bin, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    bin.Write(p, n * sizeof(T), &uiSize, 1);
}
struct S_00ca59d0_Stream
{
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
    virtual void v12(int link);
    int unk4;
    int unk8;
    int unkC;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    S_00ca59d0_Bin* unk250;
};
struct S_00ca59d0_Vec4
{
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};
struct S_00ca59d0_Member
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00ca59d0_Vec4 unk90;
    float unkA0;
};
struct S_00ca59d0_Self
{
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
    virtual void v41(int out);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(int* out);
    int unk04;
    S_00ca59d0_Member* unk08;
    void bhkShape_SaveBinary(S_00ca59d0_Stream* s);
    void FUN_00ca59d0(S_00ca59d0_Stream* s);
};
// @fnv 0x00ca59d0
// pdb: bhkPackedNiTriStripsShape::SaveBinary | bhkPackedNiTriStripsShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arStream
void S_00ca59d0_Self::FUN_00ca59d0(S_00ca59d0_Stream* pStream)
{
    int out;
    v45(&out);
    S_00ca59d0_Member* m = unk08;
    bhkShape_SaveBinary(pStream);
    float f = m->unkA0;
    S_00ca59d0_Save(*pStream->unk250, &f, 1);
    S_00ca59d0_Save(*pStream->unk250, &m->unk90, 1);
    pStream->v12(m->unk84);
    v41(out);
}

struct TlsBlock_t
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
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct PoolFree_t
{
    void Free(void* p);
};

extern PoolFree_t DAT_011f6238;

// FUN_00ca6600 : a one-line function - getter
extern int g_target_00ca6600;
// @fnv 0x00ca6600
// pdb: bhkLimitedHingeConstraint::GetRTTI | WeaponObject.obj | fnv360_0721_beta, objrun_open, low
void* FUN_00ca6600()
{
    return &g_target_00ca6600;
}

extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012682e4;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};

struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        DAT_012682e4 += 1;
    }
};

// Allocates and constructs a SpawnedObject, returning the new instance.
// @fnv 0x00ca6670
// pdb: bhkNiTriStripsShape::CopyCinfo | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInfo
SpawnedObject* FUN_00ca6670()
{
    return new SpawnedObject();
}

struct S_00ca6810_Callable
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54(int arg);
};

struct S_00ca6810_Entry
{
    S_00ca6810_Callable* callable;
    int unk04;
};

struct S_00ca6810_Inner
{
    void* unk00;
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_00ca6810_Entry* unk98;
    int unk9c;
    int unkA0;
};

extern S_00ca6810_Callable* DAT_012682f0;

struct S_00ca6810_Class
{
    void* unk00;
    int unk04;
    S_00ca6810_Inner* unk08;

    void __thiscall FUN_00aa0ad0(int arg);
    void __thiscall FUN_00ca6810(int arg);
};

// Calls slot54(arg) on each callable in unk08->unk98 up to unk08->unkA0 entries, then calls FUN_00aa0ad0(arg).
// @fnv 0x00ca6810
// pdb: bhkNiTriStripsShape::RegisterStreamables | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arStream
void S_00ca6810_Class::FUN_00ca6810(int aiValue)
{
    int count;

    if (this != 0 && this->unk08 != 0)
        count = this->unk08->unkA0;
    else
        count = 0;

    for (int i = 0; i < count; ++i)
    {
        S_00ca6810_Callable** slot;

        if (this != 0 && this->unk08 != 0)
        {
            S_00ca6810_Entry& entry = this->unk08->unk98[i];
            slot = &entry.callable;
        }
        else
        {
            slot = &DAT_012682f0;
        }

        S_00ca6810_Callable* callable = *slot;
        if (callable != 0)
            callable->slot54(aiValue);
    }

    this->FUN_00aa0ad0(aiValue);
}

struct S_00ca6880_Node
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
};

struct S_00ca6880_Class
{
    int unk00;
    int unk04;
    S_00ca6880_Node* unk08;
    char __thiscall FUN_00c84dc0(S_00ca6880_Class* arg);
    char __thiscall IsEquivalent(S_00ca6880_Class* arg);
};

static inline int Val(S_00ca6880_Class* o)
{
    if (o && o->unk08)
        return o->unk08->unka0;
    return 0;
}
// Calls FUN_00c84dc0 on arg; if it returns true, returns whether Val(this) equals Val(arg).
// @fnv 0x00ca6880
// pdb: bhkNiTriStripsShape::IsEqual | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_sim, low, conflict (bridge: bhkPackedNiTriStripsShape::IsEqual)
// pdb params: apObject
char S_00ca6880_Class::IsEquivalent(S_00ca6880_Class* pOther)
{
    char r = FUN_00c84dc0(pOther);
    if (r)
    {
        r = Val(this) == Val(pOther);
    }
    return r;
}

namespace fnv_00ca68d0 {
// GetFieldValue: thiscall, one stack arg (table index selector)
struct FUN_00ca68d0_rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct FUN_00ca68d0_entry
{
    FUN_00ca68d0_rec* m_pAssociatedRecord;
    unsigned int m_04;
};

struct FUN_00ca68d0_owner
{
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
    FUN_00ca68d0_entry* m_98;
};

extern FUN_00ca68d0_entry DAT_012682f0;

class FUN_00ca68d0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00ca68d0_owner* m_08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int GetFieldValue(unsigned int a1);
};

// @fnv 0x00ca68d0
unsigned int FUN_00ca68d0_cls::GetFieldValue(unsigned int auiIndex)
{
    if (auiIndex == 0xffffffff)
    {
        return m_10 & 0x1f;
    }
    FUN_00ca68d0_entry* e;
    if (this != 0 && m_08 != 0)
    {
        e = m_08->m_98 + (auiIndex >> 20);
    }
    else
    {
        e = &DAT_012682f0;
    }
    FUN_00ca68d0_rec* rec = e->m_pAssociatedRecord;
    if (rec != 0)
    {
        return (rec->m_0c >> 6) & 0x1f;
    }
    return 0;
}
}  // namespace fnv_00ca68d0

namespace fnv_00ca6920 {
struct S_00ca6920_Rec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
};

struct S_00ca6920_RecB
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
};

struct S_00ca6920_Ent
{
    S_00ca6920_Rec* rec;
    int unk04;
};

struct S_00ca6920_Mgr
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_00ca6920_Ent* unk98;
};

extern S_00ca6920_Ent DAT_012682f0;

struct S_00ca6920_Cls
{
    int unk00;
    int unk04;
    S_00ca6920_Mgr* unk08;
    int unk0c;
    unsigned unk10;
    unsigned char GetFlag(unsigned id, unsigned mask);
};

// @fnv 0x00ca6920
unsigned char S_00ca6920_Cls::GetFlag(unsigned id, unsigned mask)
{
    if (id == 0xffffffff)
        return (unk10 & mask) != 0;
    S_00ca6920_Ent* pEntry;
    if (this && unk08)
        pEntry = unk08->unk98 + (id >> 20);
    else
        pEntry = &DAT_012682f0;
    unsigned char r = 0;
    S_00ca6920_Rec* rec = pEntry->rec;
    if (rec)
    {
        switch (mask)
        {
        case 0x20:
            r = (((S_00ca6920_RecB*)rec)->unk0c >> 5) & 1;
            break;
        case 0x40:
            r = (rec->unk0c >> 11) & 1;
            break;
        }
    }
    return r;
}
}  // namespace fnv_00ca6920

extern __declspec(thread) int g_threadAllocationContext;
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
extern int DAT_010c771c;
extern int DAT_012682e4;

struct AllocationContextGuard
{
    int previous;
    AllocationContextGuard()
    {
        previous = g_threadAllocationContext;
        g_threadAllocationContext = 16;
    }
    ~AllocationContextGuard()
    {
        g_threadAllocationContext = previous;
    }
};

struct FNVShape : S_00cb79d0_Base
{
    FNVShape()
    {
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_vptr = &DAT_010c44e4;
        ++DAT_012686d0;
        m_vptr = &DAT_010c771c;
        ++DAT_012682e4;
    }
};

namespace fnv_00ca6a80 {
struct TlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock g_tls;

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};

struct FUN_00aa3e40_alloc
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern FUN_00aa3e40_alloc DAT_011f6238;

struct FUN_00ca4bc0_obj
{
    static void* operator new(unsigned int size)
    {
        unsigned char* a = (unsigned char*)DAT_011f6238.FUN_00aa3e40(size);
        unsigned char pad = (unsigned char)(0x10 - ((unsigned int)a & 0xf));
        a += pad;
        a[-1] = pad;
        return a;
    }
    static void operator delete(void*)
    {}
    FUN_00ca4bc0_obj(int arg);
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
};

}  // namespace fnv_00ca6a80

struct S_00ca7310_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
    S_00ca7310_Arr() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000)
    {}
};
struct S_00ca7310_Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00ca7310_Root()
    {
        unk00 = 0;
    }
};
struct S_00ca7310_Vec
{
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    S_00ca7310_Vec()
    {
        unk10 = 0.0f;
        unk14 = 0.0f;
        unk18 = 0.0f;
        unk1C = 0.0f;
    }
};
struct FUN_00ca7310 : S_00ca7310_Root
{
    S_00ca7310_Vec vec;
    int unk20;
    S_00ca7310_Arr unk24;
    S_00ca7310_Arr unk30;
    S_00ca7310_Arr unk3C;
    S_00ca7310_Arr unk48;
    S_00ca7310_Arr unk54;
    S_00ca7310_Arr unk60;
    S_00ca7310_Arr unk6C;
    S_00ca7310_Arr unk78;
    S_00ca7310_Arr unk84;
    S_00ca7310_Arr unk90;
    S_00ca7310_Arr unk9C;
    S_00ca7310_Arr unkA8;
    FUN_00ca7310();
};
// @fnv 0x00ca7310
// pdb: hkpMeshShapeCinfo::hkpMeshShapeCinfo | bhkNiTriStripsShape.obj | fnv360_0822_retail, call_gap, medium
FUN_00ca7310::FUN_00ca7310()
{}

struct MotionByte
{
    void FUN_00ca9360(const float*);
};
struct MotionInstance
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void SetMass(float);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void SetInertia(const float*);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void SetGridPosition(const void*);
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
    MotionByte linearDamping;
    MotionByte angularDamping;
};
struct MotionStorage
{
    MotionInstance* FUN_00ca9270(const void*, const void*);
    MotionInstance* FUN_00d1e690(const void*, const void*);
    MotionInstance* FUN_00d21930(const void*, const void*);
    MotionInstance* FUN_00d1dfa0(const void*, const void*);
    MotionInstance* FUN_00ca9240(const void*, const void*);
    MotionInstance* InitFixedRigidMotion(const void*, const void*);
};
float FUN_00c9e0f0(float, float);
float FUN_00c98210(float, float);
// Selects a motion instance from storage by type, sets inertia, center and mass unless type is 4, then applies linear and angular damping.
// @f3 0x0090c9b0 (community match, verified in this file)
struct MotionStore2
{
    MotionInstance* FUN_0090d8a0(const void*, const void*);
    MotionInstance* FUN_0090d8d0(const void*, const void*);
    MotionInstance* FUN_0099d980(const void*, const void*);
    MotionInstance* FUN_0099e6d0(const void*, const void*);
    MotionInstance* FUN_0099d2a0(const void*, const void*);
    MotionInstance* FUN_0099e130(const void*, const void*);
    MotionInstance* FUN_0099e700(const void*, const void*);
    MotionInstance* FUN_0090d900(const void*, const void*);
};
struct MotionByte2
{
    void FUN_0090aba0(const float*);
};
// pdb: hkpRigidBody::createDynamicRigidMotion | hkpRigidBody.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: motionType, position, rotation, mass, inertiaLocal, centreOfMassLocal, maxLinearVelocity, maxAngularVelocity, motionBufferOut
void FUN_00ca8240(int type, const void* position, const void* rotation, float mass, const float* inertia,
                  const void* center, float linearDamping, float angularDamping, MotionStorage* storage)
{
    MotionInstance* motion;
    MotionStore2* st = (MotionStore2*)storage;
    switch (type)
    {
    case 2:
        motion = storage ? st->FUN_0090d8a0(position, rotation) : 0;
        break;
    case 4:
        motion = storage ? st->FUN_0099d980(position, rotation) : 0;
        break;
    case 8:
        motion = storage ? st->FUN_0099e700(position, rotation) : 0;
        break;
    case 3:
        motion = storage ? st->FUN_0090d8d0(position, rotation) : 0;
        break;
    case 5:
        motion = storage ? st->FUN_0099e6d0(position, rotation) : 0;
        break;
    case 1: {
        float x = inertia[0], y = inertia[5], z = inertia[10];
        float fMinInertia = FUN_00c9e0f0(x, FUN_00c9e0f0(y, z));
        if ((double)0.8f * FUN_00c98210(x, FUN_00c98210(y, z)) < fMinInertia)
            motion = storage ? st->FUN_0090d8a0(position, rotation) : 0;
        else
            motion = storage ? st->FUN_0099d980(position, rotation) : 0;
        break;
    }
    case 6:
        angularDamping = linearDamping = 1000000.0f;
        motion = storage ? st->FUN_0099d2a0(position, rotation) : 0;
        break;
    case 9:
        motion = storage ? st->FUN_0090d900(position, rotation) : 0;
        break;
    case 7:
    default:
        motion = storage ? st->FUN_0099e130(position, rotation) : 0;
        break;
    }
    do { do {
    if (type != 6)
    {
        motion->SetInertia(inertia);
        motion->SetGridPosition(center);
        motion->SetMass(mass);
    }
    ((MotionByte2*)&motion->linearDamping)->FUN_0090aba0(&linearDamping);
    ((MotionByte2*)&motion->angularDamping)->FUN_0090aba0(&angularDamping);
    } while (0); } while (0);
}


struct Ctx
{
    void* pThis;
    int a1;
    char a2;
};
struct Obj
{
    virtual void v0();
    virtual void v1(Ctx*);
};
struct C
{
    char pad[0x8c];
    Obj** m8c;
    int m90;
    void NotifyAll(int a1, char a2);
};
// Iterates m8c backwards from m90-1 and calls v1 on each non-null entry with a context holding a1, this and a2.
// @f3 0x0091a580 (community match, verified in this file)
namespace task1482 { struct Layout { char pad[0x80]; Obj** items; int count; }; }
// pdb: hkpPhantom::fireCollidableRemoved | bhkAvoidBox.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: collidable, collidableWasAdded
void C::NotifyAll(int value,char flag) {
 Ctx ctx;
 ctx.a1=value;
 ctx.pThis=this;
 ctx.a2=flag;
 task1482::Layout* self=(task1482::Layout*)this;
 for(int i=self->count-1;i>=0;--i) {
  if(self->items[i]) {
   Obj* p=self->items[i];
   p->v1(&ctx);
  }
 }
}


extern int DAT_0126830c;

extern int DAT_01268310;

// @fnv 0x00ca9910
// pdb: WeaponObject::GetRTTI | WeaponObject.obj | fnv360_0822_retail, objrun_prop, low
int __cdecl FUN_00ca9910()
{
    return reinterpret_cast<int>(&DAT_01268310);
}

struct S_00ca9940_Child
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual unsigned int vfn_20();
};
struct S_00ca9940_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ca9940_Child* m_pChildObject;
};

// If o and its child are non-null and f is not 1.0, dispatches on the child's vfn_20 result to call FUN_00cc96b0 or FUN_00cbd9e0 with f.
// @f3 0x0091b810 (community match, verified in this file)
struct S_00ca9940_Child2
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual unsigned int vfn_10();
};
void __cdecl FUN_0094cda0(float f, S_00ca9940_Child* c);
void __cdecl FUN_00930d80(float f, S_00ca9940_Child* c);

// pdb: hkMalleableConstraintCinfo::ApplyScale | bhkMalleableConstraint.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: bhkMalleableConstraint::`scalar deleting destructor')
// pdb params: afScale, apInfo
void __cdecl FUN_00ca9940(float afValue, S_00ca9940_Obj* pObj)
{
    S_00ca9940_Child* c;
    if (pObj && (c = pObj->m_pChildObject) != 0 && afValue != 1.0f)
    {
        switch (reinterpret_cast<S_00ca9940_Child2*>(c)->vfn_10())
        {
        case 0:
            FUN_0094cda0(afValue, pObj->m_pChildObject);
            break;
        case 1: {
            S_00ca9940_Child* p = pObj->m_pChildObject;
            FUN_00930d80(afValue, p);
        }
        break;
        case 2: {
            S_00ca9940_Child* q = pObj->m_pChildObject;
            FUN_00930d80(afValue, q);
        }
        break;
        case 7: {
            S_00ca9940_Child* r = pObj->m_pChildObject;
            FUN_00930d80(afValue, r);
        }
        break;
        }
    }
}


struct FUN_00ca9aa0;
struct State
{
    unsigned int value;
    State() : value(0)
    {}
};
struct BaseOwner
{
    virtual void Act();
    unsigned short unk04;
    unsigned short unk06;
    State unk08;
    BaseOwner() : unk06(1), unk08()
    {}
};
struct InternalPart
{
    unsigned short mode;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    InternalPart() : mode(1)
    {}
    ~InternalPart();
};
void __fastcall FUN_00d21ce0(InternalPart* part, unsigned int command, FUN_00ca9aa0* parent);
struct FUN_00ca9aa0 : BaseOwner
{
    virtual void Act();
    unsigned int unk0c;
    InternalPart part;
    float value;
    FUN_00ca9aa0();
};
// Constructor: initializes unk0c to 0, calls FUN_00d21ce0 on part with command 1, and sets value to 0.01f.
// @fnv 0x00ca9aa0
FUN_00ca9aa0::FUN_00ca9aa0() : BaseOwner(), part()
{
    unk0c = 0;
    FUN_00d21ce0(&part, 1, this);
    value = 0.01f;
}

namespace fnv_00ca9b10 {
struct FnvCpu_FUN_00ca9b10_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00ca9b10_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ca9b10_CpuAllocator* allocator;
};
FnvCpu_FUN_00ca9b10_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00ca9b10

class BCA9D50BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCA9D50BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCA9D50BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCA9D50Stream
{
  public:
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
    unsigned int m_uiFileVersion;
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
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCA9D50BinaryStream* m_pUnderlyingStream;
    BCA9D50BinaryStream* m_pBackingStream;
};

template <class T>
inline void BCA9D50BinaryStreamSave(BCA9D50BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCA9D50SaveBinary(BCA9D50Stream& kStream, const T& value)
{
    BCA9D50BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BCA9D50Object;

void __cdecl FUN_00cf4bc0(BCA9D50Stream& kStream, BCA9D50Object* pkObject);

struct BCA9D50Data
{
    int unk00;
    int unk04;
    int unk08;
    BCA9D50Object* m_pPointer;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
};

class BCA9D50Base
{
  public:
    void SaveBinary(BCA9D50Stream& kStream);
};

class BCA9D50Wrapper : public BCA9D50Base
{
  public:
    int unk00;
    BCA9D50Data* m_pUserData;

    void FUN_00ca9d50(BCA9D50Stream& kStream);
};

// @fnv 0x00ca9d50
// pdb: hkMalleableConstraintCinfo::SaveBinary | bhkMalleableConstraint.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream
void BCA9D50Wrapper::FUN_00ca9d50(BCA9D50Stream& kStream)
{
    BCA9D50Base::SaveBinary(kStream);
    BCA9D50Data* pkData = m_pUserData;
    FUN_00cf4bc0(kStream, pkData->m_pPointer);
    BCA9D50SaveBinary(kStream, pkData->m_fValue);
}

namespace fnv_00ca9da0 {
struct TlsBlock_t
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
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct SlotAllocator
{
    virtual void vSlot00();
    virtual void* vSlot04(unsigned int size);
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual void vSlot10(unsigned int a, unsigned int b);
};

struct AllocHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SlotAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

struct SpawnedBase
{
    virtual void vSlot00()
    {}
    unsigned short m_size04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SpawnedBase();
};

struct SpawnedObject : SpawnedBase
{
    SpawnedObject() : SpawnedBase()
    {}
    void* operator new(unsigned int size) throw()
    {
        AllocHolder* holder = FUN_00c85750();
        void* p = holder->m_pAllocator->vSlot04(size);
        ((SpawnedBase*)p)->m_size04 = (unsigned short)size;
        return p;
    }
};

struct FUN_00ca9da0_cls
{
    int unk00;
    int m_04;
    int EnsureSpawnedObject();
};

// Allocates a SpawnedObject into m_04 if it is null, then returns 0x20.
// @fnv 0x00ca9da0
int FUN_00ca9da0_cls::EnsureSpawnedObject()
{
    TlsGuard_t guard;
    if (this->m_04 == 0)
    {
        SpawnedObject* p = new SpawnedObject();
        this->m_04 = (int)p;
    }
    return 0x20;
}
}  // namespace fnv_00ca9da0

struct FUN_00ca9b40_Obj
{
    void __thiscall FUN_00ca9b40(int value);
};

struct FUN_00ca9e50_Obj
{
    int unk00;
    FUN_00ca9b40_Obj* unk04;

    void __thiscall FUN_00ca9e50(int value);
};

// @fnv 0x00ca9e50
// pdb: TESUseItemPackageData::InitLoadGame | PackageDataUseItem.obj | fnv360_0822_retail, vtable, medium
// pdb params: apLoadGameBuffer
void __thiscall FUN_00ca9e50_Obj::FUN_00ca9e50(int value)
{
    if (this->unk04 != 0)
    {
        this->unk04->FUN_00ca9b40(value);
    }
}

namespace fnv_00ca9f40 {
struct TlsBlock_t
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
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct S_ca9f40_Pool
{
    void* FUN_00aa3e40(unsigned int n);
};
extern S_ca9f40_Pool DAT_011f6238;
extern int DAT_010c8288;
struct S_ca9f40_Base
{
    int unk04;
};
struct S_ca9f40_Counters
{
    int* unk00;
    S_ca9f40_Base base;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
};
}  // namespace fnv_00ca9f40

extern int DAT_01268318;

class PolyBase
{
  public:
    virtual ~PolyBase();
};

class FUN_00caa140_cls : public PolyBase
{
  public:
    virtual ~FUN_00caa140_cls();
    void FUN_00c876a0();
};

// @fnv 0x00caa140
FUN_00caa140_cls::~FUN_00caa140_cls()
{
    FUN_00c876a0();
    --DAT_01268318;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject20_b9537
{
    char m00[0x14];
    SpawnedObject20_b9537();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

// Allocates and constructs a SpawnedObject20_b9537 via its custom operator new and returns the pointer.
// @fnv 0x00caae30
SpawnedObject20_b9537* CreateSpawnedObject20()
{
    return new SpawnedObject20_b9537();
}

// Packs four bytes into an unsigned int, shifting in d first, then a, b and c, and returns it.
// @fnv 0x00cabb00
// pdb: hkColor::rgbFromChars | hkColor.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: red, green, blue, alpha
unsigned int __cdecl PackBytesBigEndian(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    unsigned int result = d;
    result = (result << 8) + a;
    result = (result << 8) + b;
    result = (result << 8) + c;
    return result;
}

void __fastcall NiStream_ReadLinkID(int a);

struct S_00cac0b0_Arg
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(int value);
};

struct S_00cac0b0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_00cac0b0_Obj
{
    int unk00;
    int unk04;
    S_00cac0b0_Inner* unk08;
    S_00cac0b0_Inner* hkpCharacterProxy_getShapePhantom();
};

struct S_00cac0b0_cls
{
    int unk00;
    int unk04;
    S_00cac0b0_Obj* unk08;
    void FUN_00cac0b0(S_00cac0b0_Arg* a);
    void bhkSerializable_SaveBinary(S_00cac0b0_Arg* a);
};

// @f3 0x0092ab40 (community match, verified in this file)
// pdb: bhkCharacterProxy::SaveBinary | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void S_00cac0b0_cls::FUN_00cac0b0(S_00cac0b0_Arg* a)
{
    S_00cac0b0_Inner* node = 0;
    if (this && unk08)
        node = unk08->hkpCharacterProxy_getShapePhantom();
    a->v0c(node ? node->unk0c : 0);
    bhkSerializable_SaveBinary(a);
}


struct FUN_00cac110_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void FUN_00cac110();
};

// @fnv 0x00cac110
// pdb: BSShaderProperty::CopyTo | BSShaderProperty.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: pDest
void __thiscall FUN_00cac110_Class::FUN_00cac110()
{
    this->FUN_00cac110();
}

namespace fnv_00cac250 {
struct FUN_00cac250_tls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int m_2b4;
};
extern __declspec(thread) FUN_00cac250_tls g_tls;

struct FUN_00cac250_obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    FUN_00cac250_obj();
    static void* __cdecl operator new(unsigned int size);
};

struct TlsGuard_b9283
{
    int m_saved;
    TlsGuard_b9283()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsGuard_b9283()
    {
        g_tls.m_2b4 = m_saved;
    }
};

extern "C" void __cdecl FUN_00c876f0(void);
extern "C" void __cdecl FUN_00c87700(void);

}  // namespace fnv_00cac250

namespace fnv_00cb0ad0 {
struct CB0AD0Allocator;

struct CB0AD0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CB0AD0Allocator* m_pStreamAllocator;
};

extern "C" CB0AD0MemoryRouter& __cdecl FUN_00c85750();
char* AllocateWithHeader(CB0AD0Allocator* pkHeap, int iSize);
void CopyIfNonEmpty(char* pcDst, const char* pcSrc, int iCount);

static inline char* CB0AD0AllocateChars(int iCount)
{
    CB0AD0Allocator* pkHeap = FUN_00c85750().m_pStreamAllocator;
    return AllocateWithHeader(pkHeap, iCount);
}

// @fnv 0x00cb0ad0
static __declspec(noinline) char* FUN_00cb0ad0(const char* pcSrc, int iMaxChars)
{
    int iLen = hkString_strLen((int)pcSrc);
    if (iLen > iMaxChars)
        iLen = iMaxChars;
    char* pcCopy = CB0AD0AllocateChars(iLen + 1);
    CopyIfNonEmpty(pcCopy, pcSrc, iLen);
    pcCopy[iLen] = 0;
    return pcCopy;
}

}  // namespace fnv_00cb0ad0

// Rect-like record used by InitRect and its helper.
struct FUN_00cb0ed0_rect
{
    volatile int m_fMinimumU;
    volatile int m_fMinimumV;
    volatile int m_fMaximumU;
    volatile int m_fMaximumV;
    volatile bool m_bValueAt0C;
};

void __cdecl ResizeBuffer(FUN_00cb0ed0_rect* pRect, int aFlag);

// Resets the rect: clears its flag (calling ResizeBuffer if set), then sets its four bounds from nLeft and nSize.
// @fnv 0x00cb0ed0
// pdb: bhkPoseArray::bhkPoseArray | bhkPoseArray.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkMonitorStream::setStaticBuffer)
// pdb params: auiNumBones, apBoneNameA, auiNumPose, apPoseA
void __cdecl InitRect(FUN_00cb0ed0_rect* pRect, int nLeft, int nSize)
{
    if (pRect->m_bValueAt0C)
    {
        ResizeBuffer(pRect, 0);
    }
    pRect->m_bValueAt0C = false;
    pRect->m_fMinimumU = nLeft;
    pRect->m_fMinimumV = nLeft;
    pRect->m_fMaximumU = nLeft + nSize;
    pRect->m_fMaximumV = nLeft + nSize - 0x20;
}

// File-static helper (reconstructed separately at its own address).
static __declspec(noinline) char CB1030ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}

// Exported elsewhere through a function pointer, which keeps the helper's cdecl stack arguments.
char(__cdecl* g_pfnCB1030ToLower)(char) = CB1030ToLower;

// @fnv 0x00cb1030
// pdb: hkString::strNcasecmp | hkString.obj | fnv360_0822_retail, objrun, medium
// pdb params: a, b, n
int __cdecl CompareCaseInsensitive(const char* pcA, const char* pcB, int n)
{
    int i = 0;
    while ((pcA[i] || pcB[i]) && i < n)
    {
        char cA = CB1030ToLower(pcA[i]);
        char cCharB = CB1030ToLower(pcB[i]);
        if (cA < cCharB)
            return -1;
        if (cA > cCharB)
            return 1;
        ++i;
    }
    return 0;
}

// FUN_00cb75d0 : default constructor of the object whose first member holds
// the class table pointer.  The constructor clears three trailing dword
// members, sets a byte flag to 1 and installs the table pointer last.

extern int DAT_010c88b8;

struct FUN_00cb75d0_cls
{
    void* m_pVTable;
    int m_iValue04;
    unsigned char m_bValue08;
    int m_iValue0c;
    int m_iValue10;

    FUN_00cb75d0_cls();
};

// @fnv 0x00cb75d0
// pdb: TESArrowTargetListener::TESArrowTargetListener | TESArrowTargetListener.obj | fnv360_0822_retail, uvref, low, conflict (skyrim: TESObjectREFRSync::ClearSyncControllerFrom3D)
FUN_00cb75d0_cls::FUN_00cb75d0_cls()
{
    m_iValue0c = 0;
    m_iValue10 = 0;
    m_iValue04 = 0;
    m_bValue08 = 1;
    m_pVTable = (void*)&DAT_010c88b8;
}

static float DAT_010c8ae4 = 0.016f;
extern double DAT_010241b0;

struct S_00cb9770_Foo
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual float V41(float value);

    int unk04;
    unsigned short unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
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
    float unk50;

    void __thiscall FUN_00cb9290();
    bool GetActive()
    {
        return ((this->unk08 >> 3) & 1) != 0;
    }
    void __thiscall UpdateActiveState(float* param);
};

// @fnv 0x00cb9770
// pdb: bhkForceController::Update | bhkForceController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: UpdateData
void __thiscall S_00cb9770_Foo::UpdateActiveState(float* pfValue)
{
    this->unk50 = DAT_010c8ae4;

    if (this->GetActive() && this->unk2c != 0)
    {
        if (this->unk20 != DAT_010241b0)
        {
            float fDiff = *pfValue - this->unk20;
            this->unk50 = fDiff;
            if (fDiff < 0.0f)
                this->unk50 = DAT_010c8ae4;
        }
        float fResult = this->V41(*pfValue);
        this->FUN_00cb9290();
        if (fResult == this->unk18)
            this->unk08 &= 0xfff7;
    }
}

extern int DAT_01268188;
extern int DAT_0108febc;
struct FUN_00c87c30
{
    void* vtable;
    int unk04;
    int unk08;
    FUN_00c87c30();
};
struct InitializedField
{
    int value;
    InitializedField() : value(0)
    {}
    ~InitializedField();
};
struct FUN_00cb99a0 : FUN_00c87c30
{
    InitializedField unk0c;
    FUN_00cb99a0(char* source);
    void SpawnAndAttach(char* source);
};
// Sets the vtable, initializes unk0c, calls SpawnAndAttach with source+4 (or null), and increments DAT_01268188.
// @fnv 0x00cb99a0
// pdb: bhkConstraint::bhkConstraint | bhkRagdollTemplate.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
FUN_00cb99a0::FUN_00cb99a0(char* source) : FUN_00c87c30(), unk0c()
{
    vtable = &DAT_0108febc;
    SpawnAndAttach(source ? source + 4 : 0);
    ++DAT_01268188;
}

extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_01268324;

struct S_cb9a90_Base
{
    int unk04;
    int unk08;
    S_cb9a90_Base();
    virtual ~S_cb9a90_Base();
};

struct S_cb9a90_A : S_cb9a90_Base
{
    int unk0c;
    int unk10;
    S_cb9a90_A()
    {
        unk0c = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
};

struct S_cb9a90_B : S_cb9a90_A
{
    S_cb9a90_B()
    {
        DAT_01268274++;
    }
};

struct S_cb9a90_C : S_cb9a90_B
{
    S_cb9a90_C()
    {
        DAT_01268250++;
    }
};

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126864c;

// @fnv 0x00cb9b50
GlobalObjectO2_00a7b610* __cdecl FUN_00cb9b50()
{
    return &g_0126864c;
}

struct CB9B80Header
{
    int unk00;
};

struct CB9B80BaseInfo
{
    int unk00;
};

struct CB9B80Info : CB9B80Header, CB9B80BaseInfo
{
};

class CB9B80RefObject
{
  public:
    CB9B80RefObject();
    virtual ~CB9B80RefObject();

    int unk04;
    int unk08;
};

class CB9B80SerializableObject : public CB9B80RefObject
{
  public:
    CB9B80SerializableObject() : m_pkWorld(0)
    {}

    void* m_pkWorld;
};

class CB9B80WorldObject : public CB9B80SerializableObject
{
  public:
    CB9B80WorldObject()
    {
        ++ms_uiCount;
    }
    virtual ~CB9B80WorldObject();

    static unsigned int ms_uiCount;
};

class FUN_00cb9b80 : public CB9B80WorldObject
{
  public:
    FUN_00cb9b80(CB9B80Info* pkInfo);
    virtual ~FUN_00cb9b80();

    void Init(CB9B80BaseInfo* pkInfo);

    static unsigned int ms_uiCount;
};

// Initializes the object from pkInfo and increments the static instance count.
// @fnv 0x00cb9b80
// pdb: bhkMalleableConstraint::bhkMalleableConstraint | bhkRagdollTemplate.obj | fnv360_0822_retail, call_gap, low
// pdb params: arInfo
FUN_00cb9b80::FUN_00cb9b80(CB9B80Info* pkInfo)
{
    Init(pkInfo);
    ++ms_uiCount;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268610;
// @fnv 0x00cb9c00
// pdb: hkPackedNiTriStripsData::GetRTTI | hkPackedNiTriStripsShape.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(udata), high
CpuOpaque* __cdecl hkPackedNiTriStripsData_GetRTTI()
{
    return &DAT_01268610;
}

class FUN_00cb9c70_item
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
    virtual void v21(int a1);
};

class FUN_00cb9c70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb9c70_item** m_ppItems;
    unsigned int m_uiCount;
    bool Check(int a1);
    bool FUN_00cb9c70(int a1);
};

// Calls Check(a1); if it returns true, calls v21(a1) on each of the m_uiCount items in m_ppItems and returns the Check result.
// @fnv 0x00cb9c70
// pdb: bhkRagdollTemplate::RegisterStreamables | bhkRagdollTemplate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arStream
bool FUN_00cb9c70_cls::FUN_00cb9c70(int aiValue)
{
    bool result = Check(aiValue);
    if (result)
    {
        unsigned int count = m_uiCount;
        for (unsigned int i = 0; i < count; i++)
        {
            m_ppItems[i]->v21(aiValue);
        }
    }
    return result;
}

namespace fnv_00cb9cb0 {

extern int DAT_011f6238;

}  // namespace fnv_00cb9cb0

struct RefCountedStandIn
{
    virtual void Unk0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

struct ArgStandIn
{
    RefCountedStandIn* FUN_00a63430();
};

class FUN_00cb9ee0_cls
{
  public:
    void AssignRefCountedArray(ArgStandIn* arg);
    void FUN_00a7b3b0(ArgStandIn* arg);

    char unk00[0x10];
    RefCountedStandIn** m_10;
    unsigned int m_14;
};

// Calls FUN_00a7b3b0, then for each of m_14 slots swaps in arg->FUN_00a63430(), releasing the old ref and retaining the new one.
// @fnv 0x00cb9ee0
// pdb: bhkRagdollTemplate::LinkObject | bhkRagdollTemplate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arStream
void FUN_00cb9ee0_cls::AssignRefCountedArray(ArgStandIn* arg)
{
    FUN_00a7b3b0(arg);
    for (unsigned int i = 0; i < m_14; i++)
    {
        RefCountedStandIn** slot = &m_10[i];
        RefCountedStandIn* pNew = arg->FUN_00a63430();
        RefCountedStandIn* old = *slot;
        if (old != pNew)
        {
            if (old != 0)
            {
                if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                {
                    old->DeleteThis();
                }
            }
            *slot = pNew;
            if (pNew != 0)
            {
                InterlockedIncrement(&pNew->m_uiRefCount);
            }
        }
    }
}

class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCB9F60Stream
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void SaveLinkID(void* pkObject);

  public:
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
    unsigned int m_uiFileVersion;
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
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCB9F60BinaryStream* m_pUnderlyingStream;
    BCB9F60BinaryStream* m_pBackingStream;
};

template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BCB9F60ExtraData
{
  public:
    void SaveBinary(BCB9F60Stream& kStream);
};

class BCB9F60LinkData : public BCB9F60ExtraData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppkObjects;
    unsigned int m_uiCount;

    void FUN_00cb9f60(BCB9F60Stream& kStream);
};

// Saves the base extra data, writes m_uiCount, then saves each link ID from m_ppkObjects.
// @fnv 0x00cb9f60
// pdb: bhkExtraData::SaveBinary | bhkExtraData.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: bhkRagdollTemplate::SaveBinary)
// pdb params: arStream
void BCB9F60LinkData::FUN_00cb9f60(BCB9F60Stream& kStream)
{
    BCB9F60ExtraData::SaveBinary(kStream);
    unsigned int ItemUpdateArray = m_uiCount;
    BCB9F60SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        kStream.SaveLinkID(m_ppkObjects[i]);
}

// Releases the resource held by the object and resets it to its empty state.
typedef void(__stdcall* FreeFn)(void*);

class FUN_00cba0d0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    long m_04;
};

// For each of count items, decrements the reference count and calls v1() when it reaches zero.
// @fnv 0x00cba0d0
// pdb: BSSimpleArray<NiPointer<NiNode>,1024>::_DestructItems | TaskQueueInterface.obj | fnv360_0822_retail, call_dedup, low, conflict (bridge: BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024>::~BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024>)
// pdb params: apFirstAddr, aiCount
void __stdcall ReleaseItems(FUN_00cba0d0_cls** items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_00cba0d0_cls* p = items[i];
        if (p != 0 && InterlockedDecrement(&p->m_04) == 0)
        {
            p->v1();
        }
    }
}

extern void* DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);
void* __cdecl FUN_00a5b690(int flag);

class CBaseOwner
{
  public:
    virtual void unk00();
    unsigned int unk04;
    CBaseOwner();
    ~CBaseOwner();
};

class CSlot08
{
  public:
    void* p;
    CSlot08(void* v)
    {
        p = v;
    }
    ~CSlot08();
};

class CSubA
{
  public:
    virtual void unkA00();
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0c;
    CSubA()
    {
        unkA04 = 0;
        unkA08 = 0;
        unkA0c = 0;
    }
    ~CSubA();
};

class CSubB
{
  public:
    virtual void unkB00();
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0c;
    CSubB()
    {
        unkB04 = 0;
        unkB08 = 0;
        unkB0c = 0;
    }
    ~CSubB();
};

class FUN_00cba110 : public CBaseOwner
{
  public:
    CSlot08 m_08;
    CSubA m_0c;
    CSubB m_1c;
    FUN_00cba110();
};

// @fnv 0x00cba110
FUN_00cba110::FUN_00cba110() : m_08(DAT_0109b220)
{
    void* p = m_08.p;
    if (p != 0)
    {
        m_08.p = FUN_00a5b690(0);
        if (p != DAT_0109b220)
        {
            DAT_00fdf1c4((char*)p - 8);
        }
    }
}

extern int DAT_01268400;

// @fnv 0x00cba1c0
void* __cdecl FUN_00cba1c0()
{
    return &DAT_01268400;
}

namespace fnv_00cbc5e0 {
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

struct FUN_00cbc550
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    static void* __cdecl operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    FUN_00cbc550();
};
// Allocates and constructs a new FUN_00cbc550 object, returning its pointer.
// @fnv 0x00cbc5e0
// pdb: bhkLiquidAction::CreateObject | bhkLiquidAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00cbc550* __cdecl CreateFUN_00cbc550()
{
    return new FUN_00cbc550;
}
}  // namespace fnv_00cbc5e0

namespace fnv_00cbc7b0 {
struct FUN_00aa3e40_class
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};

extern FUN_00aa3e40_class DAT_011f6238;

struct FUN_00cbc7b0_cls
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall PushItem(void** pItem);
};

// @fnv 0x00cbc7b0
// pdb: BSSimpleList<TESRegionData *>::AddHead | TESRegionDataList.obj | fnv360_0721_beta, objrun, high
// pdb params: item
void FUN_00cbc7b0_cls::PushItem(void** pItem)
{
    void* item = *pItem;
    if (item)
    {
        if (m_iWordAt00)
        {
            void** n = (void**)DAT_011f6238.FUN_00aa3e40(8);
            if (n)
            {
                n[0] = m_iWordAt00;
                n[1] = 0;
            }
            else
            {
                n = 0;
            }
            n[1] = m_iWordAt04;
            m_iWordAt04 = n;
            item = *pItem;
        }
        m_iWordAt00 = item;
    }
}
}  // namespace fnv_00cbc7b0

// FUN_00cbd960 registers the 0x00cbd7a0 comparison helper in the global
// callback slot at 0x01268430, which is later called indirectly with two
// arguments (see the indirect call through 0x01268430).
extern void(__cdecl* DAT_01268430)(void*, void*);

void __cdecl InsertIntoContext(void* pList, void* pContext);

// @fnv 0x00cbd960
// pdb: hkpFixedBufferCdPointCollector::registerDefaultAddCdPointFunction | hkpFixedBufferCdPointCollector.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkpHingeConstraintData::setMaxLinearImpulse)
void __cdecl FUN_00cbd960(void)
{
    DAT_01268430 = &InsertIntoContext;
}

extern int DAT_01268434;

struct PrimaryBase
{
    virtual ~PrimaryBase();
};

struct HolderBase
{
    void Release();
};

struct bhkOrientHingedBodyAction : PrimaryBase // src: F3_EXE vtable 0x00e36e14 (old: FUN_00cbd970)
{
    int unk04;
    virtual ~bhkOrientHingedBodyAction();
};

// Releases the holder and decrements the global counter DAT_01268434.
// @fnv 0x00cbd970
bhkOrientHingedBodyAction::~bhkOrientHingedBodyAction()
{
    ((HolderBase*)this)->Release();
    DAT_01268434--;
}

namespace fnv_00cbdcb0 {
struct CBDCB0Allocator
{
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CBDCB0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBDCB0Allocator* m_pStreamAllocator;

    CBDCB0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CBDCB0MemoryRouter& __cdecl FUN_00c85750();

extern __declspec(thread) int g_CBDCB0AllocTag;

struct CBDCB0AllocTagScope
{
    int m_iSaved;

    CBDCB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CBDCB0AllocTag;
        g_CBDCB0AllocTag = aiAllocationTag;
    }
    ~CBDCB0AllocTagScope()
    {
        g_CBDCB0AllocTag = m_iSaved;
    }
};

class CBDCB0Child
{
  public:
    CBDCB0Child();
    virtual ~CBDCB0Child();

    static void* operator new(unsigned int uiSize)
    {
        void* p = FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        static_cast<CBDCB0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
};

}  // namespace fnv_00cbdcb0

struct WriteStream
{
    void* unk00;
    unsigned int transferred;
    void* unk08;
    int(__cdecl* write)(WriteStream*, const void*, unsigned int, unsigned int*, int);
};
struct BufferOwner
{
    void* unk00;
    unsigned char* buffer;
    void __thiscall FUN_00c8a280(void*);
    void __thiscall WriteToStream(void*);
};
// Calls FUN_00c8a280 on source, then writes two 64-byte blocks from buffer+0x20 and buffer+0x60 to the stream at source+0x250, accumulating transferred bytes.
// @fnv 0x00cbdf10
// pdb: hkHingeConstraintCinfo::SaveBinary | bhkHingeConstraint.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arStream
void BufferOwner::WriteToStream(void* source)
{
    FUN_00c8a280(source);
    unsigned char* data = buffer;
    WriteStream* __restrict stream = *(WriteStream**)((unsigned char*)source + 0x250);
    unsigned int length = 64;
    stream->transferred += stream->write(stream, data + 0x20, 64, &length, 1);
    stream = *(WriteStream**)((unsigned char*)source + 0x250);
    length = 64;
    stream->transferred += stream->write(stream, data + 0x60, 64, &length, 1);
}

extern "C" void _ReadWriteBarrier(void);

void* __cdecl PackBytesBigEndian(int, int, int, int);
struct FUN_00cbe890_cls
{
    int m_auiShapeKeys[7];
    unsigned char m_1c;
    unsigned char __thiscall FUN_00cbe890(void* a);
};
// @f3 0x0091a280 (community match, verified in this file)
struct NativeView1474 {
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
    unsigned char disabled;
    unsigned char FUN_008f9b20(void* a);
};
void* FUN_00921850(int,int,int,int);
struct NotifyTarget { void FUN_008d5730(void*,void*); };
// pdb: bhkAvoidBox::Add | bhkAvoidBox.obj | fnv360_0822_debug, objrun_open, low
// pdb params: apWorld
unsigned char FUN_00cbe890_cls::FUN_00cbe890(void* a) {
    NativeView1474* self=reinterpret_cast<NativeView1474*>(this);
    unsigned char r = 0;
    if (self->disabled == 0) {
        unsigned char b = self->FUN_008f9b20(a);
        if (b) {
            void* p = FUN_00921850(0x1e,0x82,0,0x14);
            ((NotifyTarget*)a)->FUN_008d5730(this,p);
        }
        r = b;
    }
    return r;
}


namespace fnv_00cbf2d0 {
// FUN_00cbf2d0 : cdecl one-arg entry point.  When the argument is non null the
// game allocator is fetched from the global allocator holder and its virtual
// slot 2 is asked to release/store the block with a fixed 0x1c0 byte size.

struct AllocClass
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned int size);
};

struct HolderClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocClass* m_pAllocator;
};

HolderClass* FUN_00c85750();

}  // namespace fnv_00cbf2d0

namespace fnv_00cbf2f0 {
__declspec(thread) int fnvThreadMemoryBase;
__forceinline int& threadMemoryMode()
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(&fnvThreadMemoryBase) + 0x2b4);
}
struct MemoryContextScope
{
    int savedMode;
    __forceinline explicit MemoryContextScope(int n)
    {
        savedMode = threadMemoryMode();
        threadMemoryMode() = n;
    }
    __forceinline ~MemoryContextScope()
    {
        threadMemoryMode() = savedMode;
    }
};
struct ResourceOne
{
    void __thiscall FUN_00d055c0();
};
struct ResourceDisposer
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void dispose(ResourceOne*, int);
};
struct ResourceService
{
    int unk00, unk04, unk08, unk0c;
    ResourceDisposer* disposer;
};
extern "C" ResourceService* __cdecl FUN_00c85750();
}  // namespace fnv_00cbf2f0

namespace fnv_00cbf3c0 {
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

AllocHolder* FUN_00c85750();

}  // namespace fnv_00cbf3c0

// Release the per-body lists: destroy every inner array, then free the outer array.

struct CBF490Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct CBF490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBF490Allocator* m_pStreamAllocator;

    CBF490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CBF490MemoryRouter& __cdecl CBF490GetMemoryRouter() throw();

template <class T> inline void CBF490Deallocate(CBF490Allocator& alloc, T* p, int numElem)
{
    alloc.ReturnMemory(p, numElem * sizeof(T));
}

template <class T> __forceinline void CBF490Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <class T> struct CBF490Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~CBF490Array() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline void ClearAndRelease() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        CBF490Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            CBF490Deallocate(alloc, m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class CBF490Lists
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CBF490Array<CBF490Array<int> > m_kLists;

    void ClearLists();
};

// Clears the m_kLists array by destroying its elements and releasing its storage.
// @fnv 0x00cbf490
void CBF490Lists::ClearLists()
{
    m_kLists.ClearAndRelease();
}

class hkBool
{
  public:
    hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetKind();
};

struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};

struct PassEntry
{
    PropHolder* pHolder;
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
};

struct ShaderData
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unkb2;
    PropHolder** ppExtra;
    int iExtraCount;
};

struct ShaderProp
{
    int unk00;
    int unk04;
    ShaderData* pData;
};

struct CastResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShaderProp* pShader;
};

struct RttiObject
{
    CastResult* DynamicCast(const void* type);
};

struct GeomNode;

struct ChildNode
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    GeomNode** ppChildren;
    unsigned short unka4;
    unsigned short usChildCount;
};

struct GeomNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ChildNode* GetAsNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RttiObject* pProp;
};

struct GeomArray
{
    virtual void v00();
    virtual GeomNode** Allocate(unsigned int count);
    GeomNode** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    void Grow(unsigned int newCap, unsigned int size);

    __forceinline void Add(GeomNode* p)
    {
        if (uiSize == uiCapacity)
        {
            if (uiCapacity == 0)
            {
                pData = Allocate(4);
                uiCapacity = 4;
            }
            else
            {
                unsigned int newCap = uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2;
                Grow(newCap, uiSize);
                uiCapacity = newCap;
            }
        }
        pData[++uiSize - 1] = p;
    }
};

struct GeomCollector
{
    void CollectShaderNodes(GeomNode* pObj, GeomArray* pArray);
};

// Recursively collects GeomNodes whose shader has all passes of kind 11 and at least one extra of another kind into pArray, then descends into child nodes.
// @f3 0x00917f90 (community match, verified in this file)
namespace Native1501 {
struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int GetKind();
};
struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};
struct PassEntry
{
    PropHolder* pHolder;
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
};
struct ShaderData
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unk9e;
    PropHolder** ppExtra;
    int iExtraCount;
};
struct ShaderProp { int unk00, unk04; ShaderData* pData; };
struct CastResult { int unk00, unk04, unk08, unk0c; ShaderProp* pShader; };
CastResult* __cdecl FUN_00424fe0(GeomNode* object);
}
// pdb: bhkRagdollPenetrationUtil::FindSystems | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apObject, arRoots
void GeomCollector::CollectShaderNodes(GeomNode* pObj, GeomArray* pArray)
{
    if (!pObj)
        return;
    Native1501::CastResult* pCastResult = Native1501::FUN_00424fe0(pObj);
    if (pCastResult && pCastResult->pShader)
    {
        Native1501::ShaderData* pData = pCastResult->pShader->pData;
        if (pData)
        {
            bool bAllPassesKind11 = true;
            for (int i = 0; i < pData->usPassCount; i++)
            {
                if (!bAllPassesKind11)
                    break;
                Native1501::TypedObj* pPassObj = pData->pPasses[i].pHolder->pObj;
                bAllPassesKind11 = pPassObj->GetKind() == 11;
            }
            bool bAnyExtraOtherKind = false;
            for (int j = 0; j < pData->iExtraCount; j++)
            {
                if (bAnyExtraOtherKind)
                    break;
                bAnyExtraOtherKind = pData->ppExtra[j]->pObj->GetKind() != 11;
            }
            if (bAllPassesKind11 && bAnyExtraOtherKind)
                pArray->Add(pObj);
        }
    }
    ChildNode* pChildNode = pObj->GetAsNode();
    if (pChildNode)
    {
        for (unsigned int k = 0; k < pChildNode->usChildCount; k++)
            CollectShaderNodes(pChildNode->ppChildren[k], pArray);
    }
}


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObjectCA3
{
  public:
    virtual ~NiRefObjectCA3();
    virtual void DeleteThis();

    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerCA3
{
  public:
    ~NiPointerCA3()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerCA3& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }

    T* m_pObject;
};
class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:
    virtual ~BaseCA3()
    {}

    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
class FUN_00ca3b90 : public BaseCA3
{
  public:
    virtual ~FUN_00ca3b90();

    NiPointerCA3<NiRefObjectCA3> m_pReferencedObject;
};
// Destructor that releases the held reference by assigning null to the NiPointer, decrementing the object's ref count.
// @fnv 0x00ca3b90
FUN_00ca3b90::~FUN_00ca3b90()
{
    m_pReferencedObject = 0;
}
// The pack prelude keeps only the declaration of this file-static helper (used by a
// neighbouring function's function-pointer table); provide its body so the unit links.

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct RefCounted
{
    virtual ~RefCounted();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct PtrEntry
{
    NiPointer<RefCounted> m_pReferencedObject;
    int m_iValue;
    PtrEntry() : m_pReferencedObject(0), m_iValue(0)
    {}
    bool operator==(const PtrEntry& other) const
    {
        return m_pReferencedObject == other.m_pReferencedObject && m_iValue == other.m_iValue;
    }
    bool operator!=(const PtrEntry& other) const
    {
        return !(*this == other);
    }
};

struct PtrEntryArray
{
    virtual ~PtrEntryArray();
    PtrEntry* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};

// Resizes the array to uiMaxSize: clears and shrinks the size if smaller, reallocates the buffer, copies existing entries and default-initialises the rest.
// @fnv 0x00ca47f0
// pdb: NiTLargeArray<hkNiTriStripsData,NiTMallocInterface<hkNiTriStripsData> >::SetSize | hkNiTriStripsShape.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: uiMaxSize
void PtrEntryArray::Resize(unsigned int uiNewMaxSize)
{
    if (uiNewMaxSize == m_uiMaxSize)
        return;

    unsigned int i;
    if (uiNewMaxSize < m_uiSize)
    {
        for (i = uiNewMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != PtrEntry())
            {
                m_pBase[i] = PtrEntry();
                m_uiESize--;
            }
        }
        m_uiSize = uiNewMaxSize;
    }

    PtrEntry* pOldEntries = m_pBase;
    m_uiMaxSize = uiNewMaxSize;
    if (uiNewMaxSize > 0)
    {
        m_pBase = (PtrEntry*)NiMalloc(sizeof(PtrEntry) * m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
            m_pBase[i] = pOldEntries[i];
        for (i = m_uiSize; i < m_uiMaxSize; i++)
            m_pBase[i] = PtrEntry();
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pOldEntries);
}

// Prelude helper whose body the unit prelude omits.
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCA56B0AllocTag;
struct CA56B0AllocTagScope
{
    int m_iSaved;

    CA56B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA56B0AllocTag;
        g_iCA56B0AllocTag = aiAllocationTag;
    }
    ~CA56B0AllocTagScope()
    {
        g_iCA56B0AllocTag = m_iSaved;
    }
};
class CA56B0RefObject
{
  public:
    CA56B0RefObject();
    virtual ~CA56B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CA56B0Shape : public CA56B0RefObject
{
  public:
    CA56B0Shape() : m_pUserData(0), m_pkExtra(0)
    {
        ++ms_iCount;
    }
    virtual ~CA56B0Shape();

    void* m_pUserData;
    void* m_pkExtra;

    static int ms_iCount;
};
class CA56B0MidShape : public CA56B0Shape
{
  public:
    CA56B0MidShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0MidShape();

    static int ms_iCount;
};
class CA56B0ListShape : public CA56B0MidShape
{
  public:
    CA56B0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0ListShape();

    static int ms_iCount;
};

struct ReadBin
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadBin*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        position += read(this, data, bytes, sizes, n);
    }
};
template <class T> inline void Load(ReadBin& bin, T* data, unsigned int n)
{
    unsigned int size = sizeof(T);
    bin.Read(data, n * sizeof(T), &size, 1);
}
struct ReadStream
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
    ReadBin* binary;
    void NiStream_ReadLinkID();
};
struct ReadData
{
    int unk00, unk04;
    int value08;
    int unk0c;
    float vector10[4];
};
struct CA5940
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual ReadData* GetData(char* out);
    void FUN_00c84d00(ReadStream* stream);
    void ReadDataFromStream(ReadStream* stream);
};
// Reads a value and a 4-float vector from the stream into the object's ReadData, then calls NiStream_ReadLinkID.
// @f3 0x0094f620 (community match, verified in this file)
// pdb: bhkExtendedMeshShape::LoadBinary | bhkExtendedMeshShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void CA5940::ReadDataFromStream(ReadStream* stream)
{
    char temporary;
    ReadData* data = GetData(&temporary);
    FUN_00c84d00(stream);
    if (data)
    {
        Load(*stream->binary, &data->value08, 1);
        unsigned int size2 = 4;
        stream->binary->Read(data->vector10, 16, &size2, 1);
        stream->NiStream_ReadLinkID();
    }
}


extern __declspec(thread) int g_CA6E60AllocTag;
struct CA6E60AllocTagScope
{
    int m_iSaved;

    CA6E60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CA6E60AllocTag;
        g_CA6E60AllocTag = aiAllocationTag;
    }
    ~CA6E60AllocTagScope()
    {
        g_CA6E60AllocTag = m_iSaved;
    }
};
class CA6E60Buffer
{
  public:
    virtual ~CA6E60Buffer()
    {
        NiFreeAlias(m_pResource);
    }

    void* m_pResource;
};
class CA6E60Data
{
  public:
    static void operator delete(void* pvMem)
    {
        unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
        _g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
    }

    int unk00;
    int unk04;
    CA6E60Buffer m_kBuffer;
};

struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    void AppendReference(char*& value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};
extern char* DAT_012682e8;
char* __cdecl FUN_00a7d330(char*);
char* __cdecl FUN_00a7d510(const char*, unsigned int);
char* __cdecl FUN_00a7d4d0(const char*, int);
struct PartValue
{
    int value;
    void AppendToViewerStrings(StrArr* output);
};
struct DiagnosticShape : S_00ca6810_Class
{
    void FUN_00cd2fd0(StrArr* output);
    void AppendSubpartDiagnostics(StrArr* output);
    unsigned int Count() const
    {
        return this && unk08 ? (unsigned int)unk08->unkA0 : 0;
    }
    S_00ca6810_Entry& Part(unsigned int index) const
    {
        if (this && unk08)
            return unk08->unk98[index];
        return *reinterpret_cast<S_00ca6810_Entry*>(&DAT_012682f0);
    }
};
// Appends a name, a Subparts count, then MATERIAL and value entries for up to the first 5 parts and the last 3 parts when the count exceeds 5.
// @f3 0x00912040 (community match, verified in this file)
namespace q58
{
    struct Entry
    {
        void* f0;
        int f4;
        unsigned int f8;
    };
    struct Inner
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0c;
        unsigned short m_count;
        unsigned short unk12;
        int unk14;
        int unk18;
        int unk1c;
        int unk20;
        Entry* m_entries;
    };
    struct Sub
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
        int unk70;
        int unk74;
        int unk78;
        int unk7c;
        int unk80;
        Inner* m_84;
    };
    extern const char* DAT_00f79fb0[];
    struct Flag58
    {
        bool b;
    };
    char* __cdecl FUN_00a7d370(const char* s, Flag58 b);
    char* __cdecl FUN_00a7d5e0(const char* s, const char* v);
}
using namespace q58;
    // pdb: bhkNiTriStripsShape::GetViewerStrings | bhkNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
    // pdb params: apStrings
    void DiagnosticShape::AppendSubpartDiagnostics(StrArr* output)
    {
        FUN_00cd2fd0(output);
        {
            char* name = FUN_00a7d330(DAT_012682e8);
            output->AppendReference(name);
        }
        Sub* sub = this ? (Sub*)unk08 : 0;
        unsigned int count = sub->m_84->m_count;
        {
            char* text = FUN_00a7d510("Subparts", count);
            output->AppendReference(text);
        }
        if (count > 5)
            count = 5;
        for (unsigned int i = 0; i < count; ++i)
        {
            output->Append(FUN_00a7d510("Part", i));
            PartValue value;
            value.value = (int)sub->m_84->m_entries[i].f0;
            value.AppendToViewerStrings(output);
            const char* matName = DAT_00f79fb0[sub->m_84->m_entries[i].f8 & 0x1f];
            output->Append(FUN_00a7d5e0("MATERIAL", matName));
            Flag58 platform;
            platform.b = (sub->m_84->m_entries[i].f8 >> 5) & 1;
            output->Append(FUN_00a7d370("PLATFORM", platform));
            Flag58 stairs;
            stairs.b = (sub->m_84->m_entries[i].f8 >> 6) & 1;
            output->Append(FUN_00a7d370("STAIRS", stairs));
        }
    }


struct LockFlag_t
{
    bool m_kPointB;
    LockFlag_t(bool b) : m_kPointB(b)
    {}
    LockFlag_t(const LockFlag_t& o) : m_kPointB(o.m_kPointB)
    {}
};

struct CAC300Allocator
{
    virtual void fn00();
    virtual void* Alloc(unsigned int size);
};

struct hkReferencedObject
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;

    hkReferencedObject(int arg);
    void removeReference();

    static void* operator new(unsigned int size)
    {
        FNVTaskMemoryRouter* router = FUN_00c85750();
        hkReferencedObject* p = (hkReferencedObject*)((CAC300Allocator*)router->allocator)->Alloc(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};

struct CAC300Owner
{
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
    virtual void SetObject(hkReferencedObject* obj);
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
    virtual void Apply(int arg);

    void FUN_00cac300(int arg);
};

// Prelude helper whose body the unit prelude omits.
// Factory: create a new 0x40-byte object.
class BA2D0Object
{
  public:
    BA2D0Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};
// Allocates and constructs a new BA2D0Object, returning the pointer.
// @fnv 0x00cba2d0
BA2D0Object* CreateBA2D0Object()
{
    return new BA2D0Object;
}

// Prelude helper whose body the unit prelude omits.
// NiTMap destructor: remove all entries, then the base map frees its hash table.
void __cdecl CBC740NiFree(void* pvMem);
class CBC740MapBase
{
  public:
    virtual ~CBC740MapBase()
    {
        RemoveAll();
        CBC740NiFree(m_ppkHashTable);
    }
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00cbc740 : public CBC740MapBase
{
  public:
    virtual ~FUN_00cbc740();
};
// Destructor that calls RemoveAll to clear the map's entries.
// @fnv 0x00cbc740
// pdb: NiTMap<unsigned int,TESFile *>::~NiTMap<unsigned int,TESFile *> | TESFile.obj | fnv360_0822_debug, call_seq, high
FUN_00cbc740::~FUN_00cbc740()
{
    RemoveAll();
}

namespace fnv_00cbdf80 {
class NiPoint3
{
  public:
    float x, y, z;
    char* FUN_00a59af0(const char* label);
};
struct StrArr
{
    void* vtable;
    char** entries;
    unsigned short capacity, size, used, growBy;
    void SetSize(unsigned int count);
    void SetAt(unsigned int index, char*& value);
    void Add(char*& value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        SetAt(index, value);
    }
};
}  // namespace fnv_00cbdf80

extern __declspec(thread) int g_iCBEA40AllocTag;
struct BCBEA40AllocTagScope
{
    int m_iSaved;

    BCBEA40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCBEA40AllocTag;
        g_iCBEA40AllocTag = aiAllocationTag;
    }
    ~BCBEA40AllocTagScope()
    {
        g_iCBEA40AllocTag = m_iSaved;
    }
};
class BCBEA40StringArray
{
  public:
    virtual ~BCBEA40StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
char* __cdecl FUN_00a7d330(const char* pcString);

namespace fnv_00cbf540 {
struct hkMemoryAllocatorStub
{
    virtual void v00();
    virtual void* allocate(int nbytes);
    virtual void v08();
    virtual void v0c();
    virtual void deallocate(void* p, int nbytes);
};

struct hkThreadMemoryStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorStub* m_pThreadAllocator;
    void* allocateChunk(int nbytes)
    {
        return m_pThreadAllocator->allocate(nbytes);
    }
    void deallocateChunk(void* p, int nbytes)
    {
        m_pThreadAllocator->deallocate(p, nbytes);
    }
};

hkThreadMemoryStub* FUN_00c85750();

inline void* hkAllocateChunkStub(int nbytes)
{
    return FUN_00c85750()->allocateChunk(nbytes);
}

inline void hkDeallocateChunkStub(void* p, int nbytes)
{
    FUN_00c85750()->deallocateChunk(p, nbytes);
}

extern __declspec(thread) int g_tlsScopeValue;

struct TlsScopeGuard
{
    int m_saved;
    TlsScopeGuard()
    {
        m_saved = g_tlsScopeValue;
        g_tlsScopeValue = 0x10;
    }
    ~TlsScopeGuard()
    {
        g_tlsScopeValue = m_saved;
    }
};

struct hkPtrArrayStub
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~hkPtrArrayStub()
    {
        hkThreadMemoryStub* mem = FUN_00c85750();
        hkMemoryAllocatorStub* alloc = mem->m_pThreadAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(void*));
    }
};

struct CinfoA
{
    int m_iWordAt00;
    int unk04;
    int unk08;
    int unk0c;
    hkPtrArrayStub m_ppData;
    int unk1c;
    CinfoA();
};

struct ObjB
{
    int unk000;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk006;
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

    static void* operator new(unsigned int nbytes)
    {
        ObjB* b = (ObjB*)hkAllocateChunkStub(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00c85750()->deallocateChunk(p, ((ObjB*)p)->m_usMemSizeAndFlags);
    }
    ObjB(CinfoA* info);
};

struct CinfoCBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    CinfoCBase();
};

struct CinfoC : CinfoCBase
{
    CinfoC()
    {
        m_18 = 10;
    }
    ~CinfoC();
};

struct ObjD
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
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;

    static void* operator new(unsigned int nbytes)
    {
        return hkAllocateChunkStub(nbytes);
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkDeallocateChunkStub(p, nbytes);
    }
    ObjD(CinfoC* info);
};

}  // namespace fnv_00cbf540

// Registers a batch of classes with the registry while it is temporarily locked.
class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
class CBFC10Registry
{
  public:
    void Set(CBFC10Bool bLocked);
};
void __cdecl CBFC10RegisterA(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterB(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterC(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterD(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterE(CBFC10Registry* pkRegistry);
// @fnv 0x00cbfc10
// pdb: hkpAgentRegisterUtil::_registerBvTreeAgents | hkpAgentRegisterUtil.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dis
void __cdecl RegisterAll(CBFC10Registry* pkRegistry)
{
    pkRegistry->Set(false);
    CBFC10RegisterA(pkRegistry);
    CBFC10RegisterB(pkRegistry);
    CBFC10RegisterC(pkRegistry);
    CBFC10RegisterD(pkRegistry);
    CBFC10RegisterE(pkRegistry);
    pkRegistry->Set(true);
}

extern unsigned int DAT_011b1730;
extern unsigned int DAT_011b1734;

struct FUN_00ca3dc0_cls
{
    int unk00;
    int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned short m_10;
    unsigned short unk12;
    void* m_14;
    void* m_18;
    int unk1C;
    void* m_20;
    void* m_24;
    void __thiscall FUN_00ca3dc0(S_00ca59d0_Stream* s);
};

// Serializes m_08, m_0c, a flag for m_20, m_10 and their buffers to the stream via S_00ca59d0_Save and Write.
// @fnv 0x00ca3dc0
// pdb: hkPackedNiTriStripsData::SaveBinary | hkPackedNiTriStripsShape.obj | fnv360_1110_retail, objrun_open, low
// pdb params: arStream
void __thiscall FUN_00ca3dc0_cls::FUN_00ca3dc0(S_00ca59d0_Stream* pStream)
{
    S_00ca59d0_Save(*pStream->unk250, &m_08, 1);
    pStream->unk250->Write(m_14, m_08 * 8, &DAT_011b1734, 4);
    S_00ca59d0_Save(*pStream->unk250, &m_0c, 1);
    bool v = m_20 != 0;
    S_00ca59d0_Save(*pStream->unk250, &v, 1);
    if (!v)
    {
        pStream->unk250->Write(m_18, m_0c * 12, &DAT_011b1730, 1);
    }
    else
    {
        unsigned int cs = 2;
        pStream->unk250->Write(m_20, m_0c * 6, &cs, 1);
    }
    S_00ca59d0_Save(*pStream->unk250, &m_10, 1);
    pStream->unk250->Write(m_24, m_10 * 12, &DAT_011b1730, 1);
}

struct SArr046
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char*& value);
    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};

struct InnerEntry046
{
    void* f0;
    int f4;
    void* f8;
};
struct Inner046
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m_uiItemCount;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    InnerEntry046* m_entries;
};
struct SubObj046
{
    int unk00[0x21];
    Inner046* m_84;
};

extern int DAT_012682dc;
char* __cdecl FUN_00a7d330(char* a);
char* __cdecl FUN_00a7d510(const char* s, unsigned int n);
char* __cdecl FUN_00a7d4d0(const char* s, int n);

struct ThisCls046
{
    int unk00;
    int unk04;
    SubObj046* m_8;
    void FUN_00cd2fd0(SArr046* arr);
    void AppendSubpartNames(SArr046* arr);
};

// @f3 0x00ab0910 (community match, verified in this file)
struct StringArrayF3
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00555790(unsigned int size);
    void FUN_005b3880(unsigned int index, char*& value);

    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_00555790(index + m_usGrowBy);
        FUN_005b3880(index, value);
    }

    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_00555790(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};

struct MarkF3
{
    float x, y, z;
    unsigned short heading;
    unsigned char number;
    unsigned char unk0f;

    char* FUN_00823dc0(const char* label);
};

struct MarkListF3
{
    int unk00, unk04, unk08, unk0c;
    MarkF3* marks;
    int unk14;
    unsigned short count;

    void FUN_00845ca0(StringArrayF3* strings);
};

extern char* DAT_0116da64;
char* __cdecl FUN_00847b50(const char* name);
char* __cdecl FUN_00847d80(const char* format, unsigned int value);
char* __cdecl FUN_00847dd0(const char* format, float value);

// pdb: BSFurnitureMarker::GetViewerStrings | BSFurnitureMarker.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void ThisCls046::AppendSubpartNames(SArr046* arrRaw)
{
    MarkListF3* self = reinterpret_cast<MarkListF3*>(this);
    StringArrayF3* strings = reinterpret_cast<StringArrayF3*>(arrRaw);
    self->FUN_00845ca0(strings);
    strings->AppendReference(FUN_00847b50(DAT_0116da64));
    unsigned int count = self->count;
    strings->AppendReference(FUN_00847d80("iMarks", count));
    for (unsigned int i = 0; i < count; ++i)
    {
        strings->Append(FUN_00847d80("Mark", i));
        MarkF3& mark = self->marks[i];
        unsigned int markNumber = mark.number;
        strings->Append(FUN_00847d80(" Number", markNumber));
        strings->Append(mark.FUN_00823dc0(" Pos"));
        strings->Append(FUN_00847dd0(" Heading", (float)(mark.heading / 1000.0)));
    }
}


struct LinkedObject
{
    int unk00[2];
    int m_iValue;  // +0x08
};

struct LinkStream
{
    LinkedObject* FUN_00a63430();
};

struct LandTextureParameters
{
    int unk00[18];
    int m_iValue;  // +0x48
};

class LinkBase
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
    virtual LandTextureParameters* GetHavokData(char& rcFlag);  // +0xb4
    void FUN_00c87670(LinkStream& kStream);                     // base LinkObject
};

class LinkWrapper : public LinkBase
{
  public:
    void CopyHavokValueFromStream(LinkStream& kStream);
};

// @f3 0x008f9a10 (community match, verified in this file)
namespace task1464 {
struct Stream { LinkedObject* FUN_0082a280(); };
struct Base { void FUN_008f7ec0(LinkStream&); };
struct Data { int unk00; int value; };
}
void LinkWrapper::CopyHavokValueFromStream(LinkStream& stream) {
 LinkedObject* object=((task1464::Stream*)&stream)->FUN_0082a280();
 char flag;
 task1464::Data* data=(task1464::Data*)GetHavokData(flag);
 if(data && object) data->value=object->m_iValue;
 ((task1464::Base*)this)->FUN_008f7ec0(stream);
}


struct FUN_00cb9d80_child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(void* context);
};

typedef int(__cdecl* FUN_00cb9d80_read_fn)(void* stream, void* data, unsigned int size, void* result, int flag);

struct FUN_00cb9d80_stream
{
    int unk00;
    int position;
    int unk08;
    FUN_00cb9d80_read_fn read;
};

struct FUN_00a641f0_class
{
    void __thiscall NiStream_SaveFixedString(void* object);
};

void __stdcall FUN_00a89af0(void* context);

struct FUN_00cb9d80_class
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0c;
    FUN_00cb9d80_child** unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    void __thiscall ReadFromStream(void* context);
};

// @fnv 0x00cb9d80
// pdb: bhkRagdollTemplateData::SaveBinary | bhkRagdollTemplate.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void __thiscall FUN_00cb9d80_class::ReadFromStream(void* context)
{
    FUN_00a89af0(context);
    unsigned int count = unk14;
    ((FUN_00a641f0_class*)context)->NiStream_SaveFixedString(&unk08);

    unsigned int size = 4;

    FUN_00cb9d80_stream* stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk2c, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk30, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk34, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk38, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk3c, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &count, size, &temp, 1);
    }

    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int value = unk20[i];
        stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
        {
            int temp = size;
            stream->position += stream->read(stream, &value, size, &temp, 1);
        }
    }

    for (unsigned int i = 0; i < count; ++i)
    {
        unk10[i]->v0c(context);
    }
}

struct StandInBinaryStream
{
    int m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(StandInBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinaryStreamLoad(StandInBinaryStream& kIs, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kIs.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct StandInStream : public NiStream
{
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
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    StandInBinaryStream* m_pkIStream;

    void NiStream_LoadFixedString(void* pLinkID);
};

template <class T> inline void StreamRead(StandInStream& kStream, T& val)
{
    BinaryStreamLoad(*kStream.m_pkIStream, &val, 1);
}

struct MemoryManager_t
{
    void* FUN_00aa3e40(unsigned int size);
};

struct BaseCinfo
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;

    __forceinline void* operator new(size_t size) throw()
    {
        return ((MemoryManager_t*)&DAT_011f6238)->FUN_00aa3e40(size);
    }
    __forceinline void operator delete(void*)
    {}

    __forceinline BaseCinfo() : m_iWordAt04(0), m_8(1), m_iThirdValue(0), m_10(0)
    {}

    virtual void v00();
    virtual void v04();
    virtual void LoadBinary(NiStream& kStream);
};

struct Cinfo_13 : public BaseCinfo
{
    __forceinline Cinfo_13()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_0 : public BaseCinfo
{
    __forceinline Cinfo_0()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_1 : public BaseCinfo
{
    __forceinline Cinfo_1()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_2 : public BaseCinfo
{
    __forceinline Cinfo_2()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_7 : public BaseCinfo
{
    __forceinline Cinfo_7()
    {}
    virtual void LoadBinary(NiStream& kStream);
};

struct RagdollBase
{
    virtual ~RagdollBase();
    void ReadGroup(NiStream& kStream);
};

class bhkRagdollTemplateData : public RagdollBase
{
  public:
    int unk04;
    void* m_kName;
    CA0E60Array m_kArray1;
    CA0E60Array m_kArray2;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;

    void FUN_00cba340(StandInStream& kStream);
};

// Loads the ragdoll template data: name link, five ints, a count, type array, then allocates and loads a Cinfo per type.
// @f3 0x0092d670 (community match, verified in this file)
#include <new>
struct StreamFix_f3
{
    void FUN_0082bee0(void* pLinkID);
};
struct PoolFix_f3
{
    void* FUN_0086b930(unsigned int size);
};
namespace q63 {
struct QCinfoBase
{
    int m_04;
    int m_8;
    int m_0c;
    int m_10;

    __forceinline QCinfoBase() : m_04(0), m_0c(0), m_10(0)
    {
        m_8 = 1;
    }

    virtual void v00();
    virtual void v04();
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_13 : public QCinfoBase { __forceinline Cinfo_13() {} virtual void LoadBinary(NiStream& kStream); };
struct Cinfo_0 : public QCinfoBase { __forceinline Cinfo_0() {} virtual void LoadBinary(NiStream& kStream); };
struct Cinfo_1 : public QCinfoBase { __forceinline Cinfo_1() {} virtual void LoadBinary(NiStream& kStream); };
struct Cinfo_2 : public QCinfoBase { __forceinline Cinfo_2() {} virtual void LoadBinary(NiStream& kStream); };
struct Cinfo_7 : public QCinfoBase { __forceinline Cinfo_7() {} virtual void LoadBinary(NiStream& kStream); };
}
template <class T> static __forceinline T* NewCinfo_f3()
{
    void* mem = ((PoolFix_f3*)&DAT_01090a78)->FUN_0086b930(sizeof(T));
    return mem ? ::new (mem) T() : 0;
}

static __forceinline void ReadCinfoArray1919(bhkRagdollTemplateData* self, const unsigned& ItemUpdateArray, StandInStream& kStream)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiType = ((unsigned int*)self->m_kArray2.m_pBuffer)[i];
        q63::QCinfoBase* pCinfo = 0;
        switch (uiType)
        {
        case 13:
            pCinfo = NewCinfo_f3<q63::Cinfo_13>();
            self->m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        case 0:
            self->m_kArray1.m_pBuffer[i] = NewCinfo_f3<q63::Cinfo_0>();
            break;
        case 1:
            pCinfo = NewCinfo_f3<q63::Cinfo_1>();
            self->m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        case 2:
            self->m_kArray1.m_pBuffer[i] = NewCinfo_f3<q63::Cinfo_2>();
            break;
        case 7:
            pCinfo = NewCinfo_f3<q63::Cinfo_7>();
            self->m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        }
        q63::QCinfoBase* pObj = (q63::QCinfoBase*)self->m_kArray1.m_pBuffer[i];
        pObj->LoadBinary(kStream);
    }
}

// pdb: bhkRagdollTemplateData::LoadBinary | bhkRagdollTemplate.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void bhkRagdollTemplateData::FUN_00cba340(StandInStream& kStream)
{
    RagdollBase::ReadGroup(kStream);
    ((StreamFix_f3*)&kStream)->FUN_0082bee0(&m_kName);

    StreamRead(kStream, m_2c);
    StreamRead(kStream, m_30);
    StreamRead(kStream, m_34);
    StreamRead(kStream, m_38);
    StreamRead(kStream, m_3c);

    unsigned int ItemUpdateArray = 0;
    StreamRead(kStream, ItemUpdateArray);

    m_kArray1.SetSize(ItemUpdateArray);
    m_kArray2.SetSize(ItemUpdateArray);

    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiType;
        StreamRead(kStream, uiType);
        ((unsigned int*)m_kArray2.m_pBuffer)[i] = uiType;
    }

    ReadCinfoArray1919(this,ItemUpdateArray,kStream);
}


struct WalkPlacement
{
};
inline void* operator new(unsigned int, WalkPlacement, void* p)
{
    return p;
}
struct WalkRTTI
{
    const char* name;
    WalkRTTI* parent;
};
extern WalkRTTI DAT_01267b70, DAT_0126817c;
extern int DAT_0126818c;
struct WalkObject
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    struct WalkBody* body;
    struct WalkType* fallback;
    WalkObject* FUN_00653290(const WalkRTTI*);
    __forceinline WalkObject* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&DAT_0126818c) ? this : 0;
    }
    bool IsKind(const void* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline WalkObject* KindCast(WalkObject* item)
{
    if (!item)
        return 0;
    return item->IsKind(&DAT_0126818c) ? item : 0;
}
struct WalkType
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct WalkBody
{
    int unk, unkCur, unkValue;
    WalkType* type;
};
struct WalkLink
{
    WalkObject* item;
    WalkLink* next;
    WalkObject* GetItem()
    {
        return item;
    }
    WalkLink* Next()
    {
        return next;
    }
};
struct WalkLeaf
{
    int unk, unkCur;
    void* object;
    int unk0c, uNewnk;
    WalkLink links;
};
class NiAVObject;
class NiRTTI;
class GarbageCollectorObjectPtr
{
  public:
    WalkObject* object;
    int high;
};
GarbageCollectorObjectPtr* __cdecl FUN_00c85ef0(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
struct WalkAlloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Free(void*, int) throw();
};
struct WalkRouter
{
    int unk, unkCur, unkValue, unk0c;
    WalkAlloc* heap;
    WalkAlloc& Heap()
    {
        return *heap;
    }
};

void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> __forceinline void WalkDestruct(T* ptr, int count)
{
    for (int i = 0; i < count; ++i)
        ptr[i].~T();
}
template <class T> inline void WalkDeallocate(WalkAlloc& alloc, T* ptr, int count)
{
    alloc.Free(ptr, count * int(sizeof(T)));
}
struct WalkArray
{
    void** data;
    int size;
    int capacity;
    WalkArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~WalkArray()
    {
        WalkAlloc& alloc = ((WalkRouter*)FUN_00c85750())->Heap();
        ClearAndRelease(alloc);
    }
    void ClearAndRelease(WalkAlloc& alloc)
    {
        WalkDestruct(data, size);
        size = 0;
        if ((capacity & 0x80000000) == 0)
            WalkDeallocate(alloc, data, capacity & 0x3fffffff);
        data = 0;
        capacity = 0x80000000;
    }

    __forceinline void Add(void* const& value)
    {
        FNVTaskAllocator* alloc = FUN_00c85750()->allocator;
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(alloc, this, 4);
        *new (WalkPlacement(), &data[size]) void* = value;
        ++size;
    }
};
inline WalkObject* GetRoot(void* obj)
{
    GarbageCollectorObjectPtr temp;
    return FUN_00c85ef0(&temp, (NiAVObject*)obj, (const NiRTTI*)&DAT_01267b70)->object;
}
// @f3 0x00918270 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
extern WalkRTTI DAT_010f2c30, DAT_010f31e4, DAT_010f31fc;
struct LeafType918
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual int GetType();
};
struct LeafBody918
{
    int unk00, unk04, unk08;
    LeafType918* type;
};
struct LeafObject918
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    LeafBody918* body;
    LeafType918** fallback;
    __forceinline LeafObject918* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&DAT_010f31fc) ? this : 0;
    }
    bool IsKind(const WalkRTTI* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline LeafObject918* KindCast918(LeafObject918* item)
{
    if (!item)
        return 0;
    return item->IsKind(&DAT_010f31fc) ? item : 0;
}
struct LeafLookup918
{
    LeafObject918* item;
    int unk04;
};
struct LeafOwner918
{
    LeafLookup918* FUN_00477900(LeafLookup918* out, const void* key);
};
inline LeafObject918* FindRoot918(LeafOwner918* owner)
{
    if (owner)
    {
        LeafLookup918 result;
        return owner->FUN_00477900(&result, &DAT_010f2c30)->item;
    }
    return 0;
}
LeafObject918* __cdecl FUN_00424d50(const WalkRTTI*, LeafObject918*);
void __cdecl FUN_00901f10(void*, int);
struct LeafHeap918
{
    void FUN_008f6d90(void* memory, int size, int tag);
};
struct LeafArray918
{
    void** data;
    int size;
    int capacity;
    LeafArray918() : data(0), size(0), capacity(0x80000000)
    {
    }
    ~LeafArray918()
    {
        if (!(capacity & 0x80000000))
        {
            int allocated = capacity & 0x3fffffff;
            LeafHeap918* heap = (LeafHeap918*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, allocated * 4, 0x17);
        }
    }
    void Add(void* const& value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[size] = value;
        ++size;
    }
};
struct LeafLink918
{
    LeafObject918* item;
    LeafLink918* next;
    LeafObject918* GetItem()
    {
        return item;
    }
    LeafLink918* Next()
    {
        return next;
    }
};
struct LeafNode918
{
    int unk00, unk04;
    LeafOwner918* object;
    int unk0c, unk10;
    LeafLink918 links;
};
// pdb: bhkRagdollPenetrationUtil::AddToArrays | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: apRB, arRigidBodies, arConstraints
// pdb: bhkRagdollPenetrationUtil::AddToArrays | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_seq, high (was: CollectLeafObjects)
void __stdcall bhkRagdollPenetrationUtil_AddToArrays(WalkLeaf* leafIn, WalkArray* outObjectsIn, WalkArray* outBodiesIn)
{
    LeafNode918* leaf = (LeafNode918*)leafIn;
    LeafArray918* outObjects = (LeafArray918*)outObjectsIn;
    LeafArray918* outBodies = (LeafArray918*)outBodiesIn;
    if (!leaf)
        return;
    __int64 rootValue = (int)FindRoot918(leaf->object);
    LeafObject918* cast = FUN_00424d50(&DAT_010f31e4, (LeafObject918*)rootValue);
    LeafLink918* link = &leaf->links;
    bool found = false;
    LeafArray918 bodyArray;
    for (; link && (link->GetItem() != 0) && !found; link = link->Next())
    {
        LeafObject918* item = link->item;
        LeafObject918* body = item->AsItem();
        if (body)
        {
            LeafType918* type = body->body ? body->body->type : (body->fallback ? *body->fallback : 0);
            if (type->GetType() == 12)
                found = true;
            else
                bodyArray.Add((void*)body->body);
        }
    }
    if ((!cast || bodyArray.size > 0) && !found)
    {
        outObjects->Add(leaf->object);
        for (int index = 0; index < bodyArray.size; ++index)
            outBodies->Add(bodyArray.data[index]);
    }
}


struct TlsBlock_ca57
{
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_ca57 g_tls;
struct TlsFlagGuard_ca57
{
    unsigned int m_saved;
    TlsFlagGuard_ca57()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 16;
    }
    ~TlsFlagGuard_ca57()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class Pool_ca57
{
  public:
    void* __thiscall FUN_00aa3e40(unsigned int);
};
class Node_ca57
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Node_ca57();
    static void operator delete(void*) throw()
    {}
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->FUN_00aa3e40(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
};

int __cdecl FUN_00c84ec0(int param_1);
// @fnv 0x00ca6610
// pdb: NiBlendTransformInterpolator::CreateCloneInPlace | NiBlendTransformInterpolator.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(call_seq), high
int __cdecl NiBlendTransformInterpolator_CreateCloneInPlace(int param_1)
{
    return FUN_00c84ec0(param_1);
}

struct FNVHeapAllocator : FNVTaskAllocator
{
    template <typename T> void _bufFree(void* p, int numElem)
    {
        Free(p, numElem * sizeof(T));
    }
};

struct FNVHeapRouter : FNVTaskMemoryRouter
{
    FNVHeapAllocator& heap()
    {
        return *(FNVHeapAllocator*)allocator;
    }
};

template <typename T> struct FNVArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(FNVHeapAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~FNVArray()
    {
        _clearAndDeallocate(((FNVHeapRouter*)FUN_00c85750())->heap());
    }
};

struct RNG_cabbd0
{
    int unk00;
    unsigned int m_uiState;

    unsigned int Next()
    {
        m_uiState = m_uiState * 1664525 + 1013904223;
        return m_uiState;
    }
};

struct SomeClass
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
};

// @fnv 0x00cac900
// pdb: BGSExplosion::GetData | BGSExplosion.obj | fnv360_0822_retail, call_gap, low
int* __fastcall FUN_00cac900(SomeClass* pThis)
{
    return (int*)((char*)pThis + 0x74);
}

struct FnvCpu_FUN_00cac950_CpuObject
{
    char* hkpCharacterProxy_getLinearVelocity();
};
// @fnv 0x00cac950
// pdb: hkpCharacterProxy::getLinearVelocity | hkpCharacterProxy.obj | fnv360_0822_retail, objrun + bridge(call_dedup|call_gap) + skyrim(objrun), high
char* FnvCpu_FUN_00cac950_CpuObject::hkpCharacterProxy_getLinearVelocity()
{
    return reinterpret_cast<char*>(this) + 16;
}

struct FUN_00CAFEC0_This
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
    void** unk60;
    int unk64;
    float unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
};
struct FUN_00CAFEC0_Class
{
    float __thiscall GetTableValue(int param_2, int param_3);
};
// Reads a float from the table at unk60 using an index computed from param_2, param_3, unk64 and unk10, and adds unk68.
// @fnv 0x00cafec0
// pdb: hkBSHeightFieldShape::getHeightAtImpl | hkBSHeightFieldShape.obj | fnv360_0721_beta, objrun_open, low, conflict (skyrim: hkpCompressedSampledHeightFieldShape::getHeightAtImpl)
// pdb params: aX, aZ
float FUN_00CAFEC0_Class::GetTableValue(int param_2, int param_3)
{
    int v0_64 = ((FUN_00CAFEC0_This*)this)->unk64;
    int v0_10 = ((FUN_00CAFEC0_This*)this)->unk10;

    int diff = v0_64 - param_3;
    int product = diff * v0_10;
    int index = product + param_2;

    float* pfTable = (float*)((FUN_00CAFEC0_This*)this)->unk60;
    float val = pfTable[2 + index * 3];

    return val + ((FUN_00CAFEC0_This*)this)->unk68;
}

int __cdecl FUN_00ec6cc4(char*, const char*, char*);
// @fnv 0x00cb0f80
// pdb: hkString::sprintf | hkString.obj | fnv360_0822_retail, call_seq, medium
// pdb params: buf, fmt
void __cdecl FUN_00cb0f80(char* a, const char* b, char* c)
{
    FUN_00ec6cc4(a, b, (char*)&c);
}

extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);

// @fnv 0x00cb0fd0
// pdb: hkString::strNcmp | hkString.obj | fnv360_0822_retail, call_gap + skyrim(call_seq), high
int __cdecl hkString_strNcmp(const char* s1, const char* s2, unsigned int count)
{
    return FUN_00ec8a19(s1, s2, count);
}

namespace fnv_00cb0fe0 {
__declspec(noinline) char ToLowerAscii(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}

char(__cdecl* g_pfnCB0FE0ToLower)(char) = ToLowerAscii;

// @fnv 0x00cb0fe0
// pdb: hkString::strCasecmp | hkString.obj | fnv360_0822_retail, call_seq, high
// pdb params: a, b
// pdb: hkString::strCasecmp | hkString.obj | fnv360_0822_retail, call_seq, high (was: CompareStringsCaseInsensitive)
int hkString_strCasecmp(const char* pStringA, const char* pStringB)
{
    int off = (int)(pStringA - pStringB);
    for (;;)
    {
        if (pStringB[off] == 0)
        {
            if (*pStringB == 0)
            {
                return 0;
            }
        }
        char x = ToLowerAscii(pStringB[off]);
        char y = ToLowerAscii(*pStringB);
        if (x < y)
        {
            return -1;
        }
        if (x > y)
        {
            return 1;
        }
        pStringB++;
    }
}
}  // namespace fnv_00cb0fe0

void __cdecl FUN_00c87f60(void);
// @fnv 0x00cb75f0
// pdb: BSRotAccumTransfInterpolator::IsEqual | BSRotAccumTransfInterpolator.obj | fnv360_0822_retail, caller_sim + bridge(vtable|objrun) + skyrim(caller_sim), high
void __cdecl BSRotAccumTransfInterpolator_IsEqual(void)
{
    FUN_00c87f60();
}

void __cdecl FUN_00c87f80();
// @fnv 0x00cb7600
// pdb: BSMultiBound::GetViewerStrings | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void __cdecl FUN_00cb7600()
{
    FUN_00c87f80();
}

bool __cdecl FUN_00c87fb0(int param_1, int param_2);
// @fnv 0x00cb7630
// pdb: BSMaterialEmittanceMultController::LoadBinary | BSMaterialEmittanceMultController.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
bool __cdecl FUN_00cb7630(int param_1, int param_2)
{
    return FUN_00c87fb0(param_1, param_2);
}

extern int DAT_012683e8;

struct FUN_00c86720
{
    virtual ~FUN_00c86720();
};

struct FUN_00cb83f0 : FUN_00c86720
{
    void FUN_00c876a0();
    virtual ~FUN_00cb83f0();
};

// @fnv 0x00cb83f0
// pdb: bhkMultiSphereShape::~bhkMultiSphereShape | bhkMultiSphereShape.obj | fnv360_0822_retail, call_seq, high
FUN_00cb83f0::~FUN_00cb83f0()
{
    FUN_00c876a0();
    --DAT_012683e8;
}

struct CpuOpaque;
extern CpuOpaque DAT_012683ec;
// @fnv 0x00cb8460
CpuOpaque* __cdecl FUN_00cb8460()
{
    return &DAT_012683ec;
}

void __cdecl FUN_00c86800();
// @fnv 0x00cb8470
// pdb: NiFloatsExtraDataPoint3Controller::LinkObject | NiFloatsExtraDataPoint3Controller.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
void __cdecl FUN_00cb8470()
{
    FUN_00c86800();
}

extern "C" void __cdecl FUN_00aa1460(void* self, int size);

struct FUN_00cb8480_class
{
    void FUN_00cb83f0();
    FUN_00cb8480_class* FUN_00cb8480(char flag);
};

// @fnv 0x00cb8480
// pdb: BSFaceGenModel::`scalar deleting destructor' | BSFaceGenModel.obj | fnv360_0822_retail, vtable, high
FUN_00cb8480_class* FUN_00cb8480_class::FUN_00cb8480(char flag)
{
    FUN_00cb83f0();
    if (flag & 1)
    {
        FUN_00aa1460(this, 0x10);
    }
    return this;
}

struct FUN_00d2acf0
{
    void* vtable;
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    unsigned int unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34;
    unsigned int unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54;
    unsigned int unk58, unk5C;

    FUN_00d2acf0(void* source, void* start, void* end, float nearValue, float farValue, int flags);
    void FUN_00c905b0();

    static void* operator new(unsigned int bytes)
    {
        FNVTaskMemoryRouter* router = FUN_00c85750();
        FUN_00d2acf0* object = (FUN_00d2acf0*)((CAC300Allocator*)router->allocator)->Alloc(bytes);
        object->memorySizeAndFlags = (unsigned short)bytes;
        return object;
    }
    static void operator delete(void* object);
};

struct FUN_00cb88d0_owner : CAC300Owner
{
    void __thiscall CreateShapeAndApply(void* parameters);
};

// Allocates a FUN_00d2acf0 from the parameters block, sets it as the object, calls FUN_00c905b0, then applies the parameters.
// @f3 0x0092c440 (community match, verified in this file)
namespace F3HingeAttach {
struct Heap { void* FUN_008f6d30(unsigned, int); };
extern unsigned DAT_010f3170;
extern Heap* (__stdcall* DAT_00d9b080)(unsigned);
void __cdecl FUN_008f90f0(void*);
struct Vec4 { float x, y, z, w; };
struct Input {
    unsigned unk00;
    void* source;
    unsigned unk08, unk0c;
    Vec4 start, end;
    float nearValue, farValue;
};
struct FUN_009ae1a0;
struct Vtable { void (__thiscall* Destroy)(FUN_009ae1a0*, int); };
struct FUN_009ae1a0 {
    Vtable* table;
    unsigned short size;
    short refs;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    FUN_009ae1a0(void*, const Vec4&, const Vec4&, float, float, int);
    static void* operator new(unsigned bytes) {
        Heap* heap=DAT_00d9b080(DAT_010f3170);
        FUN_009ae1a0* object=static_cast<FUN_009ae1a0*>(heap->FUN_008f6d30(bytes,0x29));
        object->size=static_cast<unsigned short>(bytes);
        return object;
    }
    static void operator delete(void* p) { FUN_008f90f0(p); }
    void Release() {
        if (size) {
            --refs;
            short left=refs;
            if (!left) {
                table->Destroy(this,1);
            }
        }
    }
};
}
// pdb: bhkOrientHingedBodyAction::Init | bhkOrientHingedBodyAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void FUN_00cb88d0_owner::CreateShapeAndApply(void* parameters)
{
    if (!parameters)
        return;
    F3HingeAttach::Input* input=static_cast<F3HingeAttach::Input*>(parameters);
    F3HingeAttach::FUN_009ae1a0* shape=new F3HingeAttach::FUN_009ae1a0(
        input->source,input->start,input->end,input->nearValue,input->farValue,0);
    SetObject(reinterpret_cast<hkReferencedObject*>(shape));
    shape->Release();
    Apply(reinterpret_cast<int>(parameters));
}


char* __cdecl FUN_00a7d330(GlobalObjectO2_00a7b610* p);

struct CpuOpaque;
extern CpuOpaque DAT_012683f4;
// @fnv 0x00cb9250
// pdb: getVtablehkBaseObject | hkReferencedObject.obj | tesv_win, objrun_open, low
CpuOpaque* __cdecl FUN_00cb9250()
{
    return &DAT_012683f4;
}

void __cdecl FUN_00a7b3d0();

// @fnv 0x00cb9920
// pdb: CombatProcedureUseCombatItem::InitLoadGame | CombatProcedureUseCombatItem.obj | fnv360_0822_retail, vtable, medium
// pdb params: apLoadGameBuffer
void __cdecl FUN_00cb9920()
{
    FUN_00a7b3d0();
}

class CBADDynamicArray : public CA0E60Array
{
  public:
    void FUN_00cb9d50(void** elements, unsigned int count);
    void ReleaseItems(void** elements, unsigned int count);
    void FUN_00cbadf0(unsigned int requestedSize, bool compact);
};

// @fnv 0x00cbadf0
// pdb: BSSimpleArray<NiPointer<ObstacleUndoData>,1024>::SetSize | NavMesh_LoadSave.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiNewSize, abFreeMemory
void CBADDynamicArray::FUN_00cbadf0(unsigned int requestedSize, bool compact)
{
    if (requestedSize == 0)
    {
        if (m_pBuffer != 0)
        {
            ReleaseItems(m_pBuffer, m_uiSize);
            if (compact)
            {
                Free(m_pBuffer);
                m_pBuffer = 0;
                m_uiCapacity = 0;
            }
            m_uiSize = 0;
        }
        return;
    }

    if (requestedSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(requestedSize);
        }
        else
        {
            FUN_00cb9ce0(requestedSize, m_uiSize);
        }
        unsigned int oldSize = m_uiSize;
        m_uiCapacity = requestedSize;
        FUN_00cb9d50(m_pBuffer + oldSize, requestedSize - oldSize);
        m_uiSize = requestedSize;
    }
    else if (requestedSize < m_uiSize)
    {
        ReleaseItems(m_pBuffer + requestedSize, m_uiSize - requestedSize);
        m_uiSize = requestedSize;
        if (compact && requestedSize <= m_uiCapacity / 4)
        {
            FUN_00cb9ce0(requestedSize, requestedSize);
            m_uiCapacity = requestedSize;
        }
    }
    else
    {
        unsigned int oldSize = m_uiSize;
        FUN_00cb9d50(m_pBuffer + oldSize, requestedSize - oldSize);
        m_uiSize = requestedSize;
    }
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01268408;

// @fnv 0x00cbaf80
// pdb: bhkNiTriStripsShape::GetRTTI | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_open, low
GlobalObjectO2_00a7b610* __cdecl FUN_00cbaf80()
{
    return &g_01268408;
}

struct FUN_00cbaf90_Obj
{
    void FUN_00cbaf90();
};
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct FUN_00cbb130_Class : FUN_00cbaf90_Obj
{
    unsigned int __thiscall FUN_00cbb130(unsigned char flag);
};
// @fnv 0x00cbb130
// pdb: ReferenceObstacleArray::`scalar deleting destructor' | NavMeshObstacleManager.obj | fnv360_0822_retail, vtable, medium
unsigned int __thiscall FUN_00cbb130_Class::FUN_00cbb130(unsigned char flag)
{
    FUN_00cbaf90();
    if ((flag & 1) != 0)
    {
        FUN_00aa1460(this, 0x1c);
    }
    return reinterpret_cast<unsigned int>(this);
}

void __cdecl ClearLists();

// @fnv 0x00cbf530
// pdb: BSBlendTreadTransfInterpolator::RegisterStreamables | BSBlendTreadTransfInterpolator.obj | fnv360_0822_retail, objrun_prop, high
// pdb params: arStream
void __cdecl FUN_00cbf530()
{
    ClearLists();
}

struct HeapAllocator
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern HeapAllocator g_heapAllocator;

struct RefStub
{
    void IncRefCount();
    void DecRefCount();
};

struct RefHolder
{
    RefStub* object;
    RefHolder()
    {}
    ~RefHolder()
    {
        if (object)
            object->DecRefCount();
    }
};

struct ThreadLocalData
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
    int heapIndex;
};
extern __declspec(thread) ThreadLocalData g_threadLocalData;

struct HeapIndexGuard
{
    int saved;
    HeapIndexGuard(int index)
    {
        saved = g_threadLocalData.heapIndex;
        g_threadLocalData.heapIndex = index;
    }
    ~HeapIndexGuard()
    {
        g_threadLocalData.heapIndex = saved;
    }
};

extern int DAT_010c7600;

struct ShapePrefix
{
    int unk00;
    float unk04;
    ShapePrefix() : unk00(0), unk04(0.0f)
    {}
};

struct ShapeStrips
{
    void* vtbl;
    void* pBase;
    unsigned int maxSize;
    unsigned int size;
    unsigned int eSize;
    unsigned int growBy;

    ShapeStrips(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        maxSize = uiMaxSize;
        growBy = uiGrowBy;
        size = 0;
        eSize = 0;
        if (uiMaxSize > 0)
            pBase = g_heapAllocator.Allocate(uiMaxSize);
        else
            pBase = 0;
        vtbl = &DAT_010c7600;
    }
};

struct ShapeVector
{
    float x;
    float y;
    float z;
    float w;
    ShapeVector()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};

struct ShapeData : ShapePrefix
{
    ShapeStrips strips;
    ShapeVector scale;

    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_heapAllocator.Allocate(size + 16);
        unsigned char off = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += off;
        p[-1] = off;
        return p;
    }
    static void operator delete(void* p)
    {
        if (p)
        {
            unsigned char off = ((unsigned char*)p)[-1];
            g_heapAllocator.Deallocate((char*)p - off);
        }
    }

    ShapeData()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
    void SetScale()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
};
struct ShapeOwnerTarget
{
    void CopyEntriesToArg(ShapeData* data);
};

struct MyObj
{
    int unk00;
    int unk04;
    ShapeOwnerTarget* unk08;
    ShapeData* unk0c;

    void FUN_00c84e20(ShapeData* data);
    ShapeData* GetOrCreateShapeData(bool* created);
};

// Creates a ShapeData on first call, copies entries from unk08 or resets scale, and returns the stored ShapeData pointer.
// @f3 0x00912ac0 (community match, verified in this file)
// pdb: bhkPlaneShape::CopyCinfo | bhkPlaneShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
ShapeData* MyObj::GetOrCreateShapeData(bool* created)
{
    if (!unk0c)
    {
        ShapeData* data = new ShapeData;
        unk0c = data;
        if (unk08)
        {
            FUN_00c84e20(data);
            if (unk08)
                unk08->CopyEntriesToArg(data);
            else
                data->SetScale();
        }
        *created = true;
    }
    else
        *created = false;
    return unk0c;
}


struct NiPoint3
{
    float x;
    float y;
    float z;
};

extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;
extern __declspec(thread) int tls_memContext;
void* __cdecl FUN_00aa13e0(unsigned int size);
void __cdecl _delete(void* p, int size);

struct ScopedMemContext_ca9e60
{
    int m_iOld;
    ScopedMemContext_ca9e60(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext_ca9e60()
    {
        tls_memContext = m_iOld;
    }
};

struct Holder_ca9e60
{
    void* p;
    Holder_ca9e60(void* q) : p(q)
    {}
    ~Holder_ca9e60()
    {
        if (p)
            _delete(p, 0x10);
    }
};

void __cdecl DispatchToTarget();
// @fnv 0x00caa1b0
// pdb: BSMaterialEmittanceMultController::IsEqual | BSMaterialEmittanceMultController.obj | fnv360_0822_retail, caller_sim, high
// pdb params: pkObject
void __cdecl FUN_00caa1b0()
{
    DispatchToTarget();
}

struct CA0F0Result
{
    int unk00;
    int unk04;
    int m_8;
};
struct CA0F0Object : BaseThunk
{
    int __thiscall GetResultValue();
};
// @f3 0x0092ac20 (community match, verified in this file)
// pdb: bhkCharacterProxy::GethkWorld | bhkCharacterProxy.obj | fnv360_0721_beta, objrun, medium
int CA0F0Object::GetResultValue() {
    int value = 0;
    if (this && m_8) {
        CA0F0Result* result = (CA0F0Result*)m_8->hkpCharacterProxy_getShapePhantom();
        if (result)
            value = result->m_8;
    }
    return value;
}


struct RefCountedCAC4B0
{
    int unk00;
    long m_iRefCount;
};
struct ShapeHolderCAC4B0
{
    int unk00;
    int unk04;
    int unk08;
    RefCountedCAC4B0* m_pkShape;
};
struct WorldObjectCAC4B0
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
    void* m_pkUserData;
    ShapeHolderCAC4B0* hkpCharacterProxy_getShapePhantom();
};
struct RefObjectCAC4B0
{
    void UpdateReference(bool bAdd);
    int unk00;
    int unk04;
    WorldObjectCAC4B0* m_pkHavokObject;
    WorldObjectCAC4B0* GetHavokObject()
    {
        return this ? m_pkHavokObject : 0;
    }
};
struct ShapeRefCAC4B0 : public RefObjectCAC4B0
{
    void FUN_00cac4b0(bool bAdd);
};

// If bAdd, calls DAT_00fdf1c0 on the shape's refcount, else FUN_00cac410(); sets the Havok object's user data to this or null, then calls UpdateReference(bAdd).
// @f3 0x0092ab80 (community match, verified in this file)
// pdb: bhkCharacterProxy::AddbhkRefs | bhkCharacterProxy.obj | fnv360_0721_beta, objrun, low, conflict (bridge: bhkCharacterProxy::Link)
void ShapeRefCAC4B0::FUN_00cac4b0(bool bAdd)
{
    WorldObjectCAC4B0* pkObject = GetHavokObject();
    if (bAdd)
    {
        WorldObjectCAC4B0* pkHavok = GetHavokObject();
        if (pkHavok)
        {
            ShapeHolderCAC4B0* pkHolder = pkHavok->hkpCharacterProxy_getShapePhantom();
            if (pkHolder && pkHolder->m_pkShape)
                InterlockedIncrement(&pkHolder->m_pkShape->m_iRefCount);
        }
    }
    else
    {
        WorldObjectCAC4B0* pkHavok = GetHavokObject();
        if (pkHavok)
        {
            ShapeHolderCAC4B0* pkHolder = pkHavok->hkpCharacterProxy_getShapePhantom();
            if (pkHolder)
            {
                RefCountedCAC4B0* pkShape = pkHolder->m_pkShape;
                if (pkShape && !InterlockedDecrement(&pkShape->m_iRefCount))
                    ((void(__thiscall*)(void*))(*(void***)pkShape)[1])(pkShape);
            }
        }
    }
    if (pkObject)
        pkObject->m_pkUserData = bAdd ? this : 0;
    RefObjectCAC4B0::UpdateReference(bAdd);
}


extern __declspec(thread) unsigned int t_uiMemContextC5E0;
inline unsigned int GetMemContextC5E0()
{
    return t_uiMemContextC5E0;
}
inline void SetMemContextC5E0(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC5E0 = m_uiGeometryShaderFlags;
}
class AutoMemContextC5E0
{
  public:
    AutoMemContextC5E0(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC5E0();
        SetMemContextC5E0(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC5E0()
    {
        SetMemContextC5E0(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorC5E0
{
  public:
    virtual ~hkMemoryAllocatorC5E0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterC5E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC5E0& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocatorC5E0* m_pStreamAllocator;
};

namespace fnv_00cac6b0 {
// ---- FUN_00cac6b0 candidate ----

struct NiRTTI
{
    char* m_pcName;
};

extern float DAT_01267e30;

class NiPoint3
{
  public:
    float x, y, z;
    char* FUN_00a59af0(const char* pcString);
};

static const char kCac6b0Pos[] = "Pos";
static const char kCac6b0Vel[] = "Vel";

}  // namespace fnv_00cac6b0

extern "C" int DAT_0126834c;
struct CAFBase
{
    virtual ~CAFBase();
};
struct FUN_00caff80 : CAFBase
{
    virtual ~FUN_00caff80();
    void FUN_00c876a0();
};
// @fnv 0x00caff80
// pdb: bhkCapsuleShape::~bhkCapsuleShape | bhkCapsuleShape.obj | fnv360_0822_retail, call_seq, medium
FUN_00caff80::~FUN_00caff80()
{
    FUN_00c876a0();
    --DAT_0126834c;
}

// FUN_00cb0aa0: allocator-backed string dup. Takes the source string in the
// caller's edi (private convention derived for this static noinline helper):
// length via hkString_strLen (+1 for the NUL), block allocated through the task
// memory router's allocator, contents filled by FUN_00cb1090.

struct FNVTaskMemoryRouter;

extern "C" int __cdecl hkString_strLen(int);
extern "C" FNVTaskMemoryRouter* __cdecl FUN_00c85750();
extern "C" void* __cdecl AllocateWithHeader(void* allocator, unsigned int count);
extern "C" void __cdecl FUN_00cb1090(void* block, int value);

struct CbobRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};

// Allocates a block of hkString_strLen(s) + 1 units from the router's allocator, fills it from s via FUN_00cb1090, and returns it.
// @fnv 0x00cb0aa0
static __declspec(noinline) void* FUN_00cb0aa0(char* s)
{
    unsigned int count = (unsigned int)(hkString_strLen((int)s) + 1);
    CbobRouter* router = (CbobRouter*)FUN_00c85750();
    void* block = AllocateWithHeader(router->allocator, count);
    FUN_00cb1090(block, (int)s);
    return block;
}

namespace fnv_00cb1200 {
__declspec(noinline) char ToLowerAscii(char c)
{
    if ((unsigned char)(c - 'A') <= 'Z' - 'A')
        c += 'a' - 'A';
    return c;
}

// Converts every character in pcString to its lowercase ASCII equivalent in place and returns pcString.
// @fnv 0x00cb1200
// pdb: hkString::strLwr | hkString.obj | tesv_win, caller_sim, low
char* FUN_00cb1200(char* pcString)
{
    if (*pcString)
    {
        char* pc = pcString;
        do
        {
            *pc = ToLowerAscii(*pc);
            pc++;
        } while (*pc);
    }
    return pcString;
}
}  // namespace fnv_00cb1200

namespace fnv_00cb1230 {
char __declspec(noinline) ToUpperAscii(char c)
{
    if ((unsigned char)(c - 'a') <= 25u)
        c -= 32;
    return c;
}

// Converts every character of the null-terminated string s to uppercase in place and returns s.
// @fnv 0x00cb1230
// pdb: hkString::strUpr | hkString.obj | tesv_win, objrun, medium
char* __cdecl MakeUpperAscii(char* apString)
{
    if (*apString)
    {
        char* p = apString;
        do
        {
            *p = ToUpperAscii(*p);
            ++p;
        } while (*p);
    }
    return apString;
}
}  // namespace fnv_00cb1230

void __cdecl FUN_00c65820(void);
// @fnv 0x00cb7620
// pdb: BSMultiBoundRoom::IsEqual | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable, high
// pdb params: pkObject
void __cdecl FUN_00cb7620(void)
{
    FUN_00c65820();
}

extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_010c8914;
extern int DAT_01268118;
extern int DAT_01268154;

struct S00cb84f0_Obj : FUN_00c87c30
{
    int unk0c;
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    S00cb84f0_Obj()
    {
        *(void**)this = (void*)&DAT_0102016c;
        unk0c = 0;
        DAT_01268154 += 1;
        *(void**)this = (void*)&DAT_0102009c;
        DAT_01268118 += 1;
        *(void**)this = (void*)&DAT_010c8914;
    }
};

// Allocates a new S00cb84f0_Obj instance and returns its pointer, or null if allocation fails.
// @fnv 0x00cb84f0
void* __cdecl FUN_00cb84f0()
{
    S00cb84f0_Obj* p = new S00cb84f0_Obj;
    if (p)
    {
        return p;
    }
    return 0;
}

void __cdecl FUN_00a6d290(void);
struct FUN_00aa4060_Class
{
    void __thiscall FUN_00aa4060(void* p);
};
struct FUN_00cb9260_Class
{
    int __thiscall FUN_00cb9260(unsigned char flags);
};
// Calls FUN_00a6d290, then if flags bit 0 is set and this is non-null passes the block before this to FUN_00aa4060; returns this.
// @fnv 0x00cb9260
int __thiscall FUN_00cb9260_Class::FUN_00cb9260(unsigned char flags)
{
    unsigned char* object = reinterpret_cast<unsigned char*>(this);
    int result = reinterpret_cast<int>(this);

    FUN_00a6d290();

    if ((flags & 1) != 0 && object != 0)
    {
        unsigned int size = *(object - 1);
        void* p = object - size;
        reinterpret_cast<FUN_00aa4060_Class*>(&DAT_011f6238)->FUN_00aa4060(p);
    }

    return result;
}

extern "C" void __cdecl FUN_00a7b330();
// @fnv 0x00cb9910
// pdb: NiBoolTimelineInterpolator::LinkObject | NiBoolTimelineInterpolator.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
void __cdecl FUN_00cb9910()
{
    FUN_00a7b330();
}

struct FUN_00cbadb0_Dispatch
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
};
struct FUN_00cbadb0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
    virtual ~FUN_00cbadb0_Obj();

    void* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void ReleaseItems(void* items, unsigned int count);
};
// Destructor that releases the m_items array via ReleaseItems and releaseItem, then nulls m_items and the two counters.
// @fnv 0x00cbadb0
FUN_00cbadb0_Obj::~FUN_00cbadb0_Obj()
{
    if (m_items)
    {
        ReleaseItems(m_items, m_uiItemCount);
        reinterpret_cast<FUN_00cbadb0_Dispatch*>(this)->releaseItem(m_items);
        m_items = 0;
        m_pRayCursor = 0;
        m_uiItemCount = 0;
    }
}

extern int DAT_010c8d28;
struct FUN_00cbaec0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* data);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;
    void __thiscall ReleaseItems(void* data, unsigned int size);
    FUN_00cbaec0_Obj* __thiscall ReleaseAndDestroy(unsigned char flags);
};
// Releases the held items, optionally deallocates this object when flags bit 0 is set, and returns this.
// @fnv 0x00cbaec0
// pdb: BSSimpleArray<NavMeshPtr,1024>::`scalar deleting destructor' | ExtraDataList.obj | fnv360_0822_retail, vtable, medium
FUN_00cbaec0_Obj* __thiscall FUN_00cbaec0_Obj::ReleaseAndDestroy(unsigned char flags)
{
    void* oldData = m_pData;
    *reinterpret_cast<int**>(this) = &DAT_010c8d28;
    if (oldData)
    {
        ReleaseItems(oldData, m_uiSize);
        vf08(m_pData);
        m_pData = 0;
        m_uiReservedSize = 0;
        m_uiSize = 0;
    }
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

struct ArrayCBAF90
{
    virtual __forceinline ~ArrayCBAF90()
    {
        RemoveAll();
    }
    virtual void v04();
    virtual void Deallocate(void* pvBase);
    void ReleaseItems(void* pvBase, unsigned int ItemUpdateArray);
    __forceinline void RemoveAll()
    {
        if (m_pBase)
        {
            ReleaseItems(m_pBase, m_uiSize);
            Deallocate(m_pBase);
            m_pBase = 0;
            m_uiAllocated = 0;
            m_uiSize = 0;
        }
    }
    void* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiAllocated;
};
struct ObjectCBAF90
{
    virtual ~ObjectCBAF90();
    int unk04;
    int unk08;
};
struct FUN_00cbaf90 : public ObjectCBAF90
{
    virtual ~FUN_00cbaf90();
    ArrayCBAF90 m_kArray;
};

// Destructor that releases all items in m_kArray by calling RemoveAll.
// @fnv 0x00cbaf90
// pdb: bhkRagdollTemplate::~bhkRagdollTemplate | bhkRagdollTemplate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
FUN_00cbaf90::~FUN_00cbaf90()
{
    m_kArray.RemoveAll();
}

struct CBB050Array
{
    void FUN_00cbadf0(unsigned int count, bool enabled);
};
struct CBB050Object
{
    int unk00;
    int unk04;
    int unk08;
    CBB050Array array;
    void FUN_00a7b4a0(ReadStream* stream);
    void FUN_00cbb050(ReadStream* stream);
};
// Calls FUN_00a7b4a0, loads a count from the stream, passes it to the array's FUN_00cbadf0, then calls stream->NiStream_ReadLinkID count times.
// @fnv 0x00cbb050
// pdb: bhkRagdollTemplate::LoadBinary | bhkRagdollTemplate.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void CBB050Object::FUN_00cbb050(ReadStream* stream)
{
    FUN_00a7b4a0(stream);
    unsigned int count = 0;
    Load(*stream->binary, &count, 1);
    array.FUN_00cbadf0(count, true);
    for (unsigned int i = 0; i < count; ++i)
        stream->NiStream_ReadLinkID();
}

void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_011f49e0;

struct FUN_00cbaf20_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    FUN_00cbaf20_class();
    void AssignFixedString(const NiFixedString& name);
};

// Allocates a FUN_00cbaf20_class instance and assigns it the fixed string stored at DAT_011f49e0.
// @fnv 0x00cbb0c0
FUN_00cbaf20_class* CreateNamedObject()
{
    FUN_00cbaf20_class* obj = new FUN_00cbaf20_class();
    obj->AssignFixedString(*(const NiFixedString*)&DAT_011f49e0);
    return obj;
}

struct FUN_00cbf6b0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall EnsureObjectsCreated(int v);
};

extern int(__stdcall* DAT_00fdf1d0)();

// @f3 0x0054e950 (community match, verified in this file)
struct Layout_5450_e950 {
    char pad[0x12c];
    unsigned char unk12c;
    unsigned char first;
    unsigned char second;
    unsigned char third;
    void FUN_0054b150(int v);
    void FUN_00454330(void* value, unsigned int size);
};

// pdb: TESCreature::SaveGame | TESCreature.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiFlags
void FUN_00cbf6b0_class::EnsureObjectsCreated(int flags)
{
    Layout_5450_e950* self = (Layout_5450_e950*)this;
    self->FUN_0054b150(flags);
    if (flags & 0x200) {
        self->FUN_00454330(&self->first, 1);
        self->FUN_00454330(&self->second, 1);
        self->FUN_00454330(&self->third, 1);
    }
}


extern int DAT_010c925c;

struct FUN_00cbf6e0_cls
{
    void* m_ppVirtualMethodTable;
    FUN_00cbf6e0_cls* FUN_00cbf6e0(unsigned int flags);
};

// @fnv 0x00cbf6e0
// pdb: LockFreeMap<char const *,KFModel *>::LockFreeMapIterator::`scalar deleting destructor' | ModelLoader.obj | fnv360_0822_retail, vtable, medium
FUN_00cbf6e0_cls* FUN_00cbf6e0_cls::FUN_00cbf6e0(unsigned int flags)
{
    m_ppVirtualMethodTable = &DAT_010c925c;
    if ((flags & 1) != 0)
        DAT_011f6238.Free(this);
    return this;
}

struct FUN_00ca5620
{
    unsigned int m_00;
    NiPointer<RefCounted> m_pReferencedObject;
    ~FUN_00ca5620();
};

// Destructor that releases the held RefCounted object by nulling m_pReferencedObject.
// @fnv 0x00ca5620
// pdb: hkExtendedMeshShapeCinfo::~hkExtendedMeshShapeCinfo | bhkExtendedMeshShape.obj | fnv360_1110_retail, objopen_prop, low
FUN_00ca5620::~FUN_00ca5620()
{
    m_pReferencedObject = (RefCounted*)0;
}

#include <math.h>
namespace fnv_00ca6b60 {
extern __declspec(thread) int tls_memContext;

struct ScopedMemContext
{
    int m_iOld;
    ScopedMemContext(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext()
    {
        tls_memContext = m_iOld;
    }
};

extern char* DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);

class NiGlobalStringTable
{
  public:
    static char* __cdecl AddString(const char* str);
};

class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* str)
    {
        m_kHandle = NiGlobalStringTable::AddString(str);
    }
    ~NiFixedString()
    {
        if (m_kHandle != DAT_0109b220)
            DAT_00fdf1c4(m_kHandle - 8);
    }
};

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class NiObject
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    int m_uiRefCount;
    int unk08;
    unsigned short m_usFlags;
};

class NiTriStripsData : public NiObject
{
  public:
    static const NiRTTI ms_kRTTI;
};

class NiAVObject
{
  public:
    void SetName(const NiFixedString& name);
};

class NiTriStrips : public NiAVObject
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
    float m_fScale;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    static void* __cdecl operator new(unsigned int size);
    static void __cdecl operator delete(void* p);
    NiTriStrips(NiTriStripsData* data);
};

class NiNode
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail);
};

struct ShapeEntry
{
    NiObject* m_pData;
    int unk04;
};

extern ShapeEntry DAT_012682f0;

}  // namespace fnv_00ca6b60

extern __declspec(thread) unsigned int t_uiMemContextC520;
inline unsigned int GetMemContextC520()
{
    return t_uiMemContextC520;
}
inline void SetMemContextC520(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC520 = m_uiGeometryShaderFlags;
}
class AutoMemContextC520
{
  public:
    AutoMemContextC520(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC520();
        SetMemContextC520(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC520()
    {
        SetMemContextC520(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorC520
{
  public:
    virtual ~hkMemoryAllocatorC520();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterC520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC520& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocatorC520* m_pStreamAllocator;
};

hkMemoryRouterC520* __cdecl GetMemoryRouterC520();

class BufferC520
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return GetMemoryRouterC520()->heap().AllocateMemoryBlock(uiSize);
    }
    BufferC520() throw()
    {
        Init();
    }
    void Init() throw();
    int m_aiData0;
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};

// hkpCharacterProxy_getShapePhantom: __thiscall getter, 4 bytes: mov eax,[ecx+0x30]; ret
// Original index entry spans 0xcac980..0xcac993 (20 bytes): this 4-byte getter,
// 12 bytes of int3 COMDAT pad, then a byte-identical anonymous twin getter at
// 0xcac990 (mov eax,[ecx+0x30]; ret) that the pack does not index.
// Twin drafted below so a re-indexer has the neighbor shape.

struct FUN_00cac980_class
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
    void* m_30;
    void* hkpCharacterProxy_getShapePhantom();
};

// @fnv 0x00cac980
// pdb: hkpCharacterProxy::getShapePhantom | hkpCharacterProxy.obj | fnv360_0721_beta, call_seq + skyrim(objrun), high
void* FUN_00cac980_class::hkpCharacterProxy_getShapePhantom()
{
    return m_30;
}

struct GetterCAC990
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
    int m_30;
    int Get();
};

// @fnv 0x00cac990
// pdb: hkpCharacterProxy::getShapePhantom | hkpCharacterProxy.obj | fnv360_0822_retail, objrun, high
int GetterCAC990::Get()
{
    return m_30;
}

struct S00cafef0_Elem
{
    int e0;
    int e4;
    float ez;
};

struct S00cafef0_Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    float m_18;
    float m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    S00cafef0_Elem* m_30;
    float m_34;
    void UpdateBoundsFromElements();
};

// Computes min/max of element ez values over m_10*m_14 elements and stores them offset by m_34 into m_18 and m_1c.
// @fnv 0x00cafef0
// pdb: hkBSHeightFieldShapeCinfo::CalcMinMax | hkBSHeightFieldShape.obj | fnv360_0822_retail, call_seq, medium
void S00cafef0_Obj::UpdateBoundsFromElements()
{
    S00cafef0_Elem* p = m_30;
    if (p)
    {
        float a = p->ez;
        float b = p->ez;
        for (int i = 0; i < m_10; i++)
        {
            for (int j = 0; j < m_14; j++)
            {
                float c = p->ez;
                if (!(a < c))
                    a = c;
                if (!(b > c))
                    b = c;
                ++p;
            }
        }
        m_1c = m_34 + b;
        m_18 = m_34 + a;
    }
}

namespace fnv_00cb0b80 {
extern int DAT_01268358;
extern "C" void __cdecl FUN_00c856c0(void*, void*);
extern "C" void __cdecl CopyIfNonEmpty(char*, const char*, int);
static __declspec(noinline) char* FUN_00cb0ad0(char* text, int count)
{
    int length = hkString_strLen((int)text);
    if (length > count)
        length = count;
    char* result = (char*)AllocateWithHeader(FUN_00c85750()->allocator, length + 1);
    CopyIfNonEmpty(result, text, length);
    result[length] = 0;
    return result;
}
static __declspec(noinline) void* FUN_00cb0aa0(char* text)
{
    int length = hkString_strLen((int)text) + 1;
    void* result = AllocateWithHeader(FUN_00c85750()->allocator, length);
    FUN_00cb1090(result, (int)text);
    return result;
}
struct StringSlot
{
    unsigned int* p;
};
static __declspec(noinline) void FUN_00cb0b10(char* text, int count, StringSlot slot)
{
    unsigned int* out = slot.p;
    unsigned int old = *out;
    if ((old & ~1u) != (unsigned int)text)
    {
        if (old & 1)
        {
            FUN_00c856c0(FUN_00c85750()->allocator, (void*)(old - 1));
        }
        if (text)
        {
            if (count == -1)
                *out = (unsigned int)FUN_00cb0aa0(text) + 1;
            else
                *out = (unsigned int)FUN_00cb0ad0(text, count) + 1;
        }
        else
        {
            *out = DAT_01268358;
        }
    }
}
}  // namespace fnv_00cb0b80

namespace fnv_00cb0ba0 {
extern unsigned int DAT_01268358;
extern "C" void __cdecl FUN_00c856c0(void* allocator, void* block);
extern "C" char* __cdecl FUN_00cb0ad0(const char* text, int count);

static __declspec(noinline) void* FUN_00cb0aa0(char* s)
{
    int n = hkString_strLen((int)s) + 1;
    void* block = AllocateWithHeader(FUN_00c85750()->allocator, n);
    FUN_00cb1090(block, (int)s);
    return block;
}

struct StringStorageCB
{
    unsigned int handle;
    StringStorageCB* __thiscall FUN_00cb0ba0(const char* text, int count);
};

struct StringRefCB
{
    StringStorageCB* ptr;
};

__declspec(noinline) void AssignStringCB(StringRefCB ref, const char* text, int count)
{
    StringStorageCB* self = ref.ptr;
    unsigned int old = self->handle;
    if ((old & ~1u) == (unsigned int)text)
        return;
    if (old & 1)
        FUN_00c856c0(FUN_00c85750()->allocator, (void*)(old - 1));
    if (text)
    {
        if (count == -1)
            self->handle = (unsigned int)FUN_00cb0aa0((char*)text) + 1;
        else
            self->handle = (unsigned int)FUN_00cb0ad0(text, count) + 1;
    }
    else
    {
        self->handle = DAT_01268358;
    }
}

static __declspec(noinline) void FUN_00cb0b10(StringRefCB ref, const char* text, int count)
{
    AssignStringCB(ref, text, count);
}

}  // namespace fnv_00cb0ba0

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif
extern const __m128 DAT_01267e30;
extern float DAT_01016248;
extern float DAT_0101e2bc;
extern __declspec(thread) int DAT_012722b4;

struct S00cb87e0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 v10;
    __m128 v20;
    volatile float f30;
    float f34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __forceinline S00cb87e0_Node()
    {
        f30 = DAT_01016248;
        unk00 = 0;
        unk04 = 0;
        v10 = DAT_01267e30;
        v20 = DAT_01267e30;
        f34 = DAT_0101e2bc;
    }
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((MemoryManager_t*)&DAT_011f6238)->FUN_00aa3e40(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
    void operator delete(void*) throw()
    {}
};

struct S00cb87e0_Guard
{
    int m_saved;
    S00cb87e0_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cb87e0_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};

namespace fnv_00cb96c0 {
// FUN_00cb96c0: CloneSpec::Clone(void* param) - allocate 0x70, 16-align with pad byte,
// construct, run base clone-into helper, copy cloneable fields, return the new object.

struct CloneableObj
{
    void FUN_00a6cfe0(CloneableObj* dst, void* param);
};

void __fastcall FUN_00a6d220(void* p);

extern unsigned int DAT_010c8a2c;
extern float DAT_01267e30;

struct CloneSpec : public CloneableObj
{
    unsigned int m_vtbl;
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
    __m128 m_u40;
    float m_f50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;

    __forceinline void* operator new(size_t size)
    {
        char* raw = (char*)((MemoryManager_t*)&_g_memoryManager)->FUN_00aa3e40((unsigned int)size);
        unsigned char pad = 0x10 - ((unsigned char)(unsigned int)raw & 0xF);
        raw += pad;
        raw[-1] = (char)pad;
        return raw;
    }

    __forceinline void operator delete(void* p)
    {
        unsigned char pad = ((unsigned char*)p)[-1];
        _g_memoryManager.Deallocate((char*)p - pad);
    }

    __forceinline CloneSpec()
    {
        FUN_00a6d220(this);
        m_vtbl = (unsigned int)&DAT_010c8a2c;
        m_u40 = *(const __m128*)&DAT_01267e30;
        m_f50 = 0.0f;
    }

    CloneSpec* FUN_00cb96c0(void* param);
};

}  // namespace fnv_00cb96c0

extern int DAT_010c81ac;

struct SpawnMidBase : FUN_00c87c30
{
    InitializedField unk0c;
    SpawnMidBase()
    {
        vtable = &DAT_0108febc;
        ++DAT_01268188;
    }
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

class CbaItem
{
  public:
    virtual ~CbaItem();
};

// Gamebryo-style array whose storage is released through its own virtual Free.
template <class T> class CbaArray
{
  public:
    virtual ~CbaArray()
    {
        RemoveAll();
    }
    virtual void* Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void* pvMem);

    void RemoveAll()
    {
        if (m_pBase)
        {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }

    unsigned int GetSize() const
    {
        return m_uiSize;
    }
    T& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
};

class CbaString
{
  public:
    ~CbaString()
    {
        if (m_pcString != DAT_0109b220)
            InterlockedDecrement((long*)((char*)m_pcString - 8));
    }
    void* m_pcString;
};

class CbaBase
{
  public:
    virtual ~CbaBase();  // FUN_00a5d3d0
    unsigned int unk04;
};

class FUN_00cba1d0 : public CbaBase
{
  public:
    virtual ~FUN_00cba1d0();

    CbaString m_kName;
    CbaArray<CbaItem*> m_kUnsortedGeometryList;
    CbaArray<void*> m_kOther;
};

// Deletes each CbaItem* in m_kUnsortedGeometryList and then releases the array's storage via RemoveAll.
// @fnv 0x00cba1d0
FUN_00cba1d0::~FUN_00cba1d0()
{
    for (unsigned int i = 0; i < m_kUnsortedGeometryList.GetSize(); i++)
        delete m_kUnsortedGeometryList.GetAt(i);
    m_kUnsortedGeometryList.RemoveAll();
}

extern int DAT_0126841c;

struct CB920Base
{
    virtual ~CB920Base();
};

static void CB920SetTag(int aiAllocationTag)
{
    g_tlsBlock.m_2b4 = aiAllocationTag;
}

struct CB920Guard
{
    int m_saved;

    CB920Guard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    void Leave()
    {
        CB920SetTag(m_saved);
    }

    ~CB920Guard()
    {
        Leave();
    }
};

struct FUN_00cbc920 : CB920Base
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* m_name;

    void Cleanup();
    virtual ~FUN_00cbc920();
};

// Removes this object from the CB920Map entry for m_name, cleans up the entry if it becomes empty, calls Cleanup, and decrements DAT_0126841c.
// @f3 0x009301d0 (community match, verified in this file)
struct Registry_00f7b6a8
{
    void FUN_00bea7b0(void* key, void** out);
    void FUN_00899cf0(void* key);
};
extern Registry_00f7b6a8 DAT_00f7b6a8;
struct Manager_01090a78
{
    void* FUN_0086ba60(void* p);
};
extern Manager_01090a78 DAT_01090a78;
extern int DAT_010f340c;
struct Layout_cbc920
{
    void* m_pVtable;
    int m_04;
    int m_08;
    int m_0c;
    void* m_name;
    void FUN_008f7ef0();
    void FUN_008f87c0();
};
struct FoundObj
{
    int f0;
    int f4;
    void FUN_00421610(void** p);
    void FUN_006c8220();
};
// pdb: bhkLiquidAction::~bhkLiquidAction | bhkLiquidAction.obj | fnv360_0822_retail, call_seq, medium
FUN_00cbc920::~FUN_00cbc920()
{
    Layout_cbc920* self = (Layout_cbc920*)this;
    if (self->m_name)
    {
        void* out = 0;
        DAT_00f7b6a8.FUN_00bea7b0(self->m_name, &out);
        if (out)
        {
            FoundObj* p = (FoundObj*)out;
            // the owner (this) is handed back through the same slot the lookup filled
            out = this;
            p->FUN_00421610(&out);
            if (p->f4 == 0 && p->f0 == 0)
            {
                DAT_00f7b6a8.FUN_00899cf0(self->m_name);
                p->FUN_006c8220();
                DAT_01090a78.FUN_0086ba60(p);
            }
        }
    }
    self->FUN_008f7ef0();
    --DAT_010f340c;
}


struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
};

struct ChainSource
{
    __m128 m_00;
    __m128 m_10;
    ChainNode* m_20;
    ChainNode* m_24;
};

struct ChainDest
{
    __m128 m_00;
    __m128 m_10;
    ChainNode* m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    ChainNode* m_48;
    int m_4c;
    int m_50[1];
};

// Copies two vectors, stores the end node of each chain in dst, and writes the second chain's m_04 values to dst->m_50 followed by -1.
// @fnv 0x00cbd700
static __declspec(noinline) void FUN_00cbd700(ChainSource* src, ChainDest* dst)
{
    dst->m_00 = src->m_00;
    dst->m_10 = src->m_10;

    ChainNode* node = src->m_20;
    while (node->m_0c)
        node = node->m_0c;
    dst->m_20 = node;

    node = src->m_24;
    while (node->m_0c)
        node = node->m_0c;
    dst->m_48 = node;

    dst->m_24 = src->m_20->m_04;
    dst->m_4c = src->m_24->m_04;

    int count = 0;
    ChainNode* n = src->m_24;
    while (n->m_0c)
    {
        n = n->m_0c;
        ++count;
    }

    ChainNode* cur = src->m_24;
    dst->m_50[count] = -1;
    for (int i = count - 1; i >= 0; i--)
    {
        dst->m_50[i] = cur->m_04;
        cur = cur->m_0c;
    }
}

void __cdecl InsertIntoContext(void* pList, void* pContext)
{
    FUN_00cbd700((ChainSource*)pList, (ChainDest*)pContext);
}

// Floors a float (rounds toward negative infinity) using integer bit manipulation of its IEEE-754 representation.
// @fnv 0x00cbfd80
// pdb: hkMath::hkFloor | hkMathTypes.obj | fnv360_0822_retail, call_gap + bridge(uconst|call_gap) + skyrim(call_seq), high
float __cdecl hkMath_hkFloor(float value)
{
    union
    {
        float f;
        int i;
    } u;
    u.f = value;
    int x = u.i;
    int e = (((unsigned)x >> 23) & 0xff) - 127;
    int t = 23 - e;
    int ns = ~(t >> 31);
    x &= ~(((x & 0x7fffffff) - 1) >> 31);
    int mask = ((int)0xff800000 >> ((ns & 23) - (ns & t))) | ~ns;
    int sign = x >> 31;
    int frac = ~((~mask & x) - 1) & (0x800000 >> e) & sign;
    int neg = e >> 31;
    u.i = ((frac + x) & ~neg & mask) | (neg & sign & 0xbf800000);
    return u.f;
}

extern double DAT_010c9300;
extern double DAT_010c92f8;
extern double DAT_010c92f0;
extern double DAT_01030f38;
extern double DAT_0101ff40;
// Polynomial approximation of atan2 with x as numerator and y as denominator, adjusted using the signs of y and x.
// @fnv 0x00cbff80
// pdb: hkMath_atan2fApproximation | hkMathTypes.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: x, y
float __cdecl Atan2(float x, float y)
{
    float ax = (float)fabs(x);
    float ay = (float)fabs(y);
    float t, result;
    if (ax <= ay)
    {
        t = ax / (float)(ay + DAT_010c9300);
        float tCopy = t;
        float partial = tCopy - (t * DAT_010c92f8) * t;
        result = partial - t * (t * (t * DAT_010c92f0));
    }
    else
    {
        t = ay / (float)(ax + DAT_010c9300);
        float tCopy = t;
        float partial = tCopy - (t * DAT_010c92f8) * t;
        result = partial - t * (t * (t * DAT_010c92f0));
        result = (float)(DAT_01030f38 - result);
    }
    if (y < 0.0f)
        result = (float)(DAT_0101ff40 - result);
    if (x < 0.0f)
        result = -result;
    return result;
}

namespace fnv_00ca3b00 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00ca3b00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00ca3b00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ca3b00
    virtual void FUN_00ca3b00();
};

Derived::Derived()
{}
}  // namespace fnv_00ca3b00

namespace fnv_00ca4510 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00ca4510();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00ca4510();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ca4510
    virtual void FUN_00ca4510();
};

Derived::Derived()
{}
}  // namespace fnv_00ca4510

extern int DAT_010c771c;
extern int g_fnvDecompCounter;

struct ScopeHost_cls
{
    void* m_vptr;
    void FUN_00c876a0();
    void FUN_00cd2de0();
    void FUN_00ca6590();
};

struct OwnerGuard_cls
{
    ScopeHost_cls* m_pOwnerObject;
    OwnerGuard_cls(ScopeHost_cls* owner)
    {
        m_pOwnerObject = owner;
        owner->m_vptr = &DAT_010c771c;
    }
    ~OwnerGuard_cls()
    {
        m_pOwnerObject->FUN_00cd2de0();
    }
};

// Sets a guard on this (sets the vtable pointer, calls FUN_00cd2de0 on exit), calls FUN_00c876a0, and decrements g_fnvDecompCounter.
// @fnv 0x00ca6590
void ScopeHost_cls::FUN_00ca6590()
{
    OwnerGuard_cls guard(this);
    FUN_00c876a0();
    --g_fnvDecompCounter;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00ca6780_sub
{
    unsigned int unk00;
    int m_04;
    int(__cdecl* m_08)(void* a, volatile unsigned int* b, unsigned int c, unsigned int d, unsigned int e);
};

struct FUN_00ca6780_arg
{
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
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned short unk1E6;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00ca6780_sub* m_24c;
};

struct FUN_00ca6780_cls
{
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual int v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* v2D(unsigned char* out);
    int FUN_00ca6780(FUN_00ca6780_arg* a1);
};

// @f3 0x009126d0 (community match, verified in this file)
// pdb: bhkNiTriStripsShape::LoadCInfo | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arStream
int FUN_00ca6780_cls::FUN_00ca6780(FUN_00ca6780_arg* a1)
{
    unsigned char c;
    volatile unsigned int* p = v2D(&c);
    int size = 0;
    if (p)
    {
        size = v2A();
        if (a1->unk04 < 4)
        {
            size -= 0x10;
        }
        FUN_00ca6780_sub* sub = a1->m_24c;
        int r = sub->m_08(sub, p, size, 0, 0);
        sub->m_04 += r;
        if (a1->m_1e5 != 1 && a1->unk04 >= 4)
        {
            p[8] = _byteswap_ulong(p[8]);
            p[9] = _byteswap_ulong(p[9]);
            p[10] = _byteswap_ulong(p[10]);
            p[11] = _byteswap_ulong(p[11]);
        }
    }
    return size;
}


namespace fnv_00cabf30 {
// sub ecx,8; jmp FUN_00cac120  ==  MSVC adjustor thunk for a secondary base at offset 8.
struct PrimaryBase
{
    virtual void FUN_00cabf30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00cabf30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cabf30
    virtual void FUN_00cabf30();
};

Derived::Derived()
{}
}  // namespace fnv_00cabf30

// Adjustor thunk for FUN_00cabf40: sub ecx,0xc; jmp FUN_00cac120.
// Primary base sized 12 (vptr + 8 pad) so the secondary->primary
// this adjustment is exactly 0xc.

struct Prim_00cabf40
{
    virtual void FUN_00cabf40();
    int m04;
    int m08;
};

struct Sec_00cabf40
{
    virtual void FUN_00cabf40();
};

struct TO_00cabf40 : Prim_00cabf40, Sec_00cabf40
{
// @fnv 0x00cabf40
    virtual void FUN_00cabf40();
};

// Forces vtable emission: the override lands in both the primary and the
// secondary vftable, so VC9 emits [thunk]:TO_00cabf40::FUN_00cabf40
// 'adjustor{12}' = sub ecx,0xc ; jmp TO_00cabf40::FUN_00cabf40.
static TO_00cabf40 g_thunk_00cabf40;

struct CAC410_TLSState
{
    char m_ucUnknownByte[0x2B4];
    int m_uiFilterValue;
};

__declspec(thread) CAC410_TLSState g_CAC410_TLSState;

struct CAC410_ScopedValue
{
    int m_oldValue;

    CAC410_ScopedValue() : m_oldValue(g_CAC410_TLSState.m_uiFilterValue)
    {
        g_CAC410_TLSState.m_uiFilterValue = 0x10;
    }

    ~CAC410_ScopedValue()
    {
        g_CAC410_TLSState.m_uiFilterValue = m_oldValue;
    }
};

extern int DAT_01268358;
int CB0Len(const char* s);

struct CB0StringPtr
{
    int m_pcText;
    CB0StringPtr(const CB0StringPtr& other);
    const char* cString() const
    {
        return (const char*)(m_pcText & ~1);
    }
};

struct CB0SelfRef
{
    CB0StringPtr* p;
};
static __declspec(noinline) void FUN_00cb0b10(CB0SelfRef selfRef, const char* s, int len)
{
    CB0StringPtr* self = selfRef.p;
    if (len == -1)
        len = CB0Len(s);
    self->m_pcText = (int)s + len;
}

// Sets m_pcText to DAT_01268358, then calls FUN_00cb0b10 with other's string and length -1, which stores the string's end pointer in m_pcText.
// @fnv 0x00cb0bd0
CB0StringPtr::CB0StringPtr(const CB0StringPtr& other)
{
    m_pcText = DAT_01268358;
    CB0SelfRef r;
    r.p = this;
    FUN_00cb0b10(r, other.cString(), -1);
}

struct S00cb8590_Out
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
};

struct S00cb8590_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk1e0;
    unsigned char unk1e4;
    unsigned char unk1e5;
};

struct S00cb8590_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual S00cb8590_Out* vfn2d(S00cb8590_Obj** pp)
    {
        return 0;
    }
    void FUN_00cb8590(int a0);
};
static __forceinline void S00cb8590_swapAll(S00cb8590_Out* p)
{
    p->unk10 = _byteswap_ulong(p->unk10);
    _ReadWriteBarrier();
    p->unk14 = _byteswap_ulong(p->unk14);
    _ReadWriteBarrier();
    p->unk18 = _byteswap_ulong(p->unk18);
    _ReadWriteBarrier();
    p->unk1c = _byteswap_ulong(p->unk1c);
    _ReadWriteBarrier();
    p->unk20 = _byteswap_ulong(p->unk20);
    _ReadWriteBarrier();
    p->unk24 = _byteswap_ulong(p->unk24);
    _ReadWriteBarrier();
    p->unk28 = _byteswap_ulong(p->unk28);
    _ReadWriteBarrier();
    p->unk2c = _byteswap_ulong(p->unk2c);
    _ReadWriteBarrier();
    p->unk30 = _byteswap_ulong(p->unk30);
    _ReadWriteBarrier();
    p->unk34 = _byteswap_ulong(p->unk34);
    _ReadWriteBarrier();
}

// Calls FUN_00c86790 on the object; unless its unk1e5 is 1, byte-swaps the ten 32-bit fields at 0x10-0x34 of the vfn2d result.
// @f3 0x0092c220 (community match, verified in this file)
void __stdcall FUN_008f88e0(S00cb8590_Obj* p);

// pdb: bhkOrientHingedBodyAction::LoadBinary | bhkOrientHingedBodyAction.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: bhkMotorAction::LoadBinary)
// pdb params: arStream
void S00cb8590_cls::FUN_00cb8590(int a0)
{
    S00cb8590_Obj* p = *(S00cb8590_Obj* volatile*)&a0;
    FUN_008f88e0(p);
    if (p->unk1e5 != 1)
    {
        S00cb8590_Out* out = vfn2d((S00cb8590_Obj**)&a0);
        if (out)
        {
            S00cb8590_swapAll(out);
        }
    }
}


struct FUN_00c868b0_Obj
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
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
};

struct FUN_00cb8610_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}

    virtual void FUN_00cb8610(void* arg);

    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}

    virtual FUN_00c868b0_Obj* vfB4(unsigned char* value);

    void FUN_00c868b0(void* arg);
};

// bhkRagdollTemplate::bhkRagdollTemplate @ 0xcbaf20 (84 bytes)
// ctor: NiExtraData base ctor (0xa7b2e0), derived vftable (0x10c8dcc), then member
// BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> (vftable 0x10c8d28 + three
// zero stores) constructed inline; returns this.
// The original carries a dead /GS+EH unwind-only registration frame (FuncInfo
// optimizer folded away, and the c1 EH scope (unwind funclet destroys the base
// subobject) survived as stale weight.

// base NiExtraData: named after its ctor's address so the implicit base-ctor
// call binds to 0xa7b2e0
struct FUN_00a7b2e0
{
    virtual void v0();
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a7b2e0();
    ~FUN_00a7b2e0();
};

struct AryType
{  // BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> stand-in
    virtual void v0();
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
    AryType();
};

class FUN_00cbaf20 : public FUN_00a7b2e0
{
  public:
    AryType m_data;
    FUN_00cbaf20();
};

AryType::AryType()
{
    if (0)
        throw 1;
    m_pData = 0;
    m_uiSize = 0;
    m_uiMaxSize = 0;
}

// Default constructor for FUN_00cbaf20; the body is empty and the base class and m_data member are default-constructed implicitly.
// @fnv 0x00cbaf20
// pdb: NiColorExtraData::NiColorExtraData | NiColorExtraData.obj | fnv360_0822_retail, caller_sim, low
FUN_00cbaf20::FUN_00cbaf20()
{}

struct SearchNodeCB
{
    int unk00;
    unsigned int id;
    int unk08;
    SearchNodeCB* parent;
};

struct InputCB
{
    __m128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* first;
    SearchNodeCB* second;
};

struct OutputCB
{
    __m128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* firstRoot;
    unsigned int firstId;
    int unk28_0;
    int unk28_1;
    int unk28_2;
    int unk28_3;
    int unk28_4;
    int unk28_5;
    int unk28_6;
    int unk28_7;
    SearchNodeCB* secondRoot;
    unsigned int secondId;
    unsigned int secondPath[8];
};

struct ContextCB
{
    int unk00;
    float limit;
    OutputCB* begin;
    OutputCB* next;
    int capacity;
    int size;
};

static __declspec(noinline) void CopyCB(OutputCB* dest, const InputCB* src)
{
    dest->point = src->point;
    *(__m128*)&dest->x = *(__m128 const*)&src->x;
    SearchNodeCB* c = src->first;
    while (c->parent)
        c = c->parent;
    dest->firstRoot = c;
    c = src->second;
    while (c->parent)
        c = c->parent;
    dest->secondRoot = c;
    dest->firstId = src->first->id;
    dest->secondId = src->second->id;
    SearchNodeCB* h = src->second;
    int count = 0;
    SearchNodeCB* n = h->parent;
    while (n)
    {
        n = n->parent;
        ++count;
    }
    dest->secondPath[count] = 0xffffffff;
    int i = count - 1;
    while (i >= 0)
    {
        dest->secondPath[i] = h->id;
        h = h->parent;
        --i;
    }
}

// Adds input to context, or when full replaces the highest-score entry if input's score is lower, then sets context->limit to the highest remaining score.
// @fnv 0x00cbd7a0
void __cdecl InsertIntoContext(const InputCB* input, ContextCB* context)
{
    if (context->capacity)
    {
        if (context->size < context->capacity)
        {
            CopyCB(context->next, input);
            ++context->size;
            ++context->next;
            return;
        }
        OutputCB* end = context->begin + context->size;
        OutputCB* cur = context->begin;
        OutputCB* best = cur++;
        __assume(cur < end);
        for (; cur < end; ++cur)
            if (cur->score > best->score)
                best = cur;
        if (input->score < best->score)
        {
            CopyCB(best, input);
            cur = context->begin;
            best = cur++;
            __assume(cur < end);
            for (; cur < end; ++cur)
                if (cur->score > best->score)
                    best = cur;
        }
        context->limit = best->score;
    }
}

struct FUN_00cbda30_io;

struct FUN_00cbda30_io
{
    unsigned int unk00;
    unsigned int m04;
    unsigned int(__cdecl* m08)(FUN_00cbda30_io*, void*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00cbda30_arg
{
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
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
    char unk1E6;
    char unk1E7;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00cbda30_io* m24C;
};

struct FUN_00cbda30_rec
{
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
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00cbda30_cls
{
    virtual void v00()
    {}
    FUN_00cbda30_rec* m04;
    void FUN_00c8a230(FUN_00cbda30_arg* a);
    void ReadRecord(FUN_00cbda30_arg* a1);
};

void SwapEndianBlocks(void* p);

extern "C" void _ReadWriteBarrier(void);
unsigned int* __cdecl SwapEndianBlocks(unsigned int* arg);

// Calls FUN_00c8a230, reads two 0x40-byte blocks at offsets 0x20 and 0x60 of m04 via a1->m24C, and byte-swaps them unless a1->m1E5 is 1.
// @fnv 0x00cbda30
// pdb: hkHingeConstraintCinfo::LoadBinary | bhkHingeConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arStream
void FUN_00cbda30_cls::ReadRecord(FUN_00cbda30_arg* a1)
{
    FUN_00c8a230(a1);
    FUN_00cbda30_rec* p = m04;
    FUN_00cbda30_io* io = a1->m24C;
    FUN_00cbda30_rec* b = (FUN_00cbda30_rec*)((char*)p + 0x20);
    io->m04 += io->m08(io, b, 0x40, 0, 0);
    io = a1->m24C;
    FUN_00cbda30_rec* q = (FUN_00cbda30_rec*)((char*)p + 0x60);
    io->m04 += io->m08(io, q, 0x40, 0, 0);
    p = q;
    if (a1->m1E5 != 1)
    {
        b->m30 = _byteswap_ulong(b->m30);
        _ReadWriteBarrier();
        b->m34 = _byteswap_ulong(b->m34);
        _ReadWriteBarrier();
        b->m38 = _byteswap_ulong(b->m38);
        _ReadWriteBarrier();
        b->m3C = _byteswap_ulong(b->m3C);
        SwapEndianBlocks((unsigned int*)b);
        p->m30 = _byteswap_ulong(p->m30);
        _ReadWriteBarrier();
        p->m34 = _byteswap_ulong(p->m34);
        _ReadWriteBarrier();
        p->m38 = _byteswap_ulong(p->m38);
        _ReadWriteBarrier();
        p->m3C = _byteswap_ulong(p->m3C);
        SwapEndianBlocks((unsigned int*)p);
    }
}

struct CA3F10MemMgr
{
    void* Allocate(unsigned int size);
};
extern CA3F10MemMgr g_kCA3F10MemMgr;

struct CA3F10BinaryStream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CA3F10BinaryStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

struct CA3F10Stream
{
    void* unk00;
    unsigned int m_uiFormatVersion;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    CA3F10BinaryStream* m_pUnderlyingStream;
};

template <class T> inline unsigned int CA3F10LoadBinary(CA3F10BinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}

extern unsigned int DAT_011b1750[];
extern unsigned int DAT_011b1754[];

struct CA3F10Triangle
{
    unsigned int uiVerts01;
    unsigned int uiVert2Welding;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};

struct CA3F10OldTriangle
{
    CA3F10Triangle kTri;
    float f08;
    float f0c;
    float f10;
};

struct CA3F10Vertex
{
    float x;
    float y;
    float z;
    CA3F10Vertex()
    {}
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};

struct CA3F10Normal
{
    float x;
    float y;
    float z;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};

struct CA3F10Data
{
    int unk00;
    int unk04;
    unsigned int m_uiTriangles;
    unsigned int m_uiVertices;
    unsigned short m_usNormals;
    unsigned short unk12;
    CA3F10Triangle* m_pkTriangles;
    CA3F10Vertex* m_pkVertices;
    int unk1c;
    int unk20;
    CA3F10Normal* m_pkNormals;

    void FUN_00ca3f10(CA3F10Stream* pkStream);
};

// Reads triangle, vertex, and normal data from a CA3F10Stream, handling format version differences for triangle and vertex reading.
// @fnv 0x00ca3f10
void CA3F10Data::FUN_00ca3f10(CA3F10Stream* pkStream)
{
    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_uiTriangles);
    m_pkTriangles = new CA3F10Triangle[m_uiTriangles];
    if (pkStream->m_uiFormatVersion < 0x21)
    {
        for (unsigned int i = 0; i < m_uiTriangles; i++)
        {
            CA3F10OldTriangle kOld;
            pkStream->m_pUnderlyingStream->BinaryRead(&kOld, sizeof(kOld), DAT_011b1754, 7);
            CA3F10Triangle& kTri = m_pkTriangles[i];
            kTri.uiVerts01 = kOld.kTri.uiVerts01;
            kTri.uiVert2Welding = kOld.kTri.uiVert2Welding;
        }
    }
    else
    {
        pkStream->m_pUnderlyingStream->BinaryRead(m_pkTriangles, m_uiTriangles * sizeof(CA3F10Triangle), DAT_011b1754,
                                                  4);
    }

    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_uiVertices);
    if (pkStream->m_uiFormatVersion >= 0x22)
    {
        CA3F10BinaryStream* pkIstr = pkStream->m_pUnderlyingStream;
        unsigned int (*pfnRead)(CA3F10BinaryStream*, void*, unsigned int, unsigned int*, unsigned int) =
            pkIstr->m_pfnRead;
        bool bUnused;
        unsigned int uiSize = 1;
        unsigned int uiRead = pfnRead(pkIstr, &bUnused, 1, &uiSize, 1);
        pkIstr->m_uiStreamFlags += uiRead;
        CA3F10Vertex* pkVerts = new CA3F10Vertex[m_uiVertices];
        unsigned int uiBytes = m_uiVertices * sizeof(CA3F10Vertex);
        m_pkVertices = pkVerts;
        pkStream->m_pUnderlyingStream->BinaryRead(pkVerts, uiBytes, DAT_011b1750, 1);
    }
    else
    {
        CA3F10Vertex* pkVerts = new CA3F10Vertex[m_uiVertices];
        unsigned int uiBytes = m_uiVertices * sizeof(CA3F10Vertex);
        m_pkVertices = pkVerts;
        pkStream->m_pUnderlyingStream->BinaryRead(pkVerts, uiBytes, DAT_011b1750, 1);
    }

    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_usNormals);
    m_pkNormals = new CA3F10Normal[m_usNormals];
    pkStream->m_pUnderlyingStream->BinaryRead(m_pkNormals, m_usNormals * sizeof(CA3F10Normal), DAT_011b1750, 1);
}

struct Alloc9bd0
{
    virtual void R();
    virtual void* Allocate(unsigned int);
};
extern "C" int DAT_010c82ec;
struct Rec9bd0;
struct Router9bd0
{
    int a[4];
    Alloc9bd0* allocator;
    Alloc9bd0& heap()
    {
        return *allocator;
    }
};
struct Sub9bd0
{
    int v;
    void FUN_00d21ce0(Rec9bd0*);
};
struct Item9bd0
{
    void FUN_00c905b0();
};
struct Rec9bd0
{
    void* vt;
    unsigned short cap, fl;
    int pad[2];
    Sub9bd0 sub;
    int pad2[2];
    float score;
    void FUN_00ca9b40(Item9bd0*);
    void FUN_00ca9aa0();
    static void* operator new(unsigned int size)
    {
        Rec9bd0* m = (Rec9bd0*)((Router9bd0*)FUN_00c85750())->heap().Allocate(size);
        m->cap = (unsigned short)size;
        return m;
    }
    static void operator delete(void*);
    Rec9bd0()
    {
        FUN_00ca9aa0();
        vt = &DAT_010c82ec;
    }
};
struct Ctx9bd0
{
    int a, b, c;
    void* coll;
    int d[3];
    float score;
};
struct Key9bd0
{
    int value;
};
struct Owner9bd0
{
    int u;
    Ctx9bd0* ctx;
    void ReleaseObject(Rec9bd0*, int);
    void FUN_00ca9bd0(Rec9bd0* r, Key9bd0 key);
};
extern "C" void _ReadWriteBarrier();
// Uses r or allocates a Rec9bd0, attaches an item made by CreateF4A30Result from ctx->coll and key, copies ctx->score, then calls ReleaseObject(rec, key).
// @f3 0x0091bb00 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
extern int DAT_00e367f0;
struct Heap9bd0F3
{
    void* FUN_008f6d30(unsigned int bytes, unsigned int tag);
};
struct Item9bd0F3
{
    virtual void deleteThis(int);
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            if (--m_referenceCount == 0)
                deleteThis(1);
        }
    }
};
extern "C" Item9bd0F3* __cdecl FUN_0097a980(void* c, int k);
struct Sub9bd0F3
{
    void hkpBridgeConstraintAtom_init(void* rec);
};
struct Rec9bd0F3
{
    void* vt;
    unsigned short cap, fl;
    int pad08;
    int pad0C;
    Sub9bd0F3 sub;
    int pad14;
    int pad18;
    float score;
    void FUN_0091b7c0(Item9bd0F3*);
    void FUN_0091ba60();
    static void* operator new(unsigned int size)
    {
        Heap9bd0F3* heap = (Heap9bd0F3*)TlsGetValue(DAT_010f3170);
        Rec9bd0F3* m = (Rec9bd0F3*)heap->FUN_008f6d30(size, 0x2c);
        m->cap = (unsigned short)size;
        return m;
    }
    static void operator delete(void*);
    Rec9bd0F3()
    {
        FUN_0091ba60();
        vt = &DAT_00e367f0;
    }
};
struct Owner9bd0F3
{
    int u;
    Ctx9bd0* ctx;
    void FUN_008fc3f0(Rec9bd0F3*, int);
};
// pdb: hkMalleableConstraintCinfo::CloneData | bhkMalleableConstraint.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apData, arCloneData
void Owner9bd0::FUN_00ca9bd0(Rec9bd0* apRecord, Key9bd0 key)
{
    Owner9bd0F3* self = (Owner9bd0F3*)this;
    Owner9bd0F3* volatile vself = self;
    _ReadWriteBarrier();
    Ctx9bd0* c = self->ctx;
    Rec9bd0F3* rec = (Rec9bd0F3*)apRecord;
    if (rec == 0)
        rec = new Rec9bd0F3;
    void* coll = c->coll;
    int k = *(volatile int*)&key.value;
    Item9bd0F3* pItem = coll ? FUN_0097a980(coll, k) : 0;
    if (pItem)
    {
        rec->FUN_0091b7c0(pItem);
        pItem->removeReference();
    }
    rec->score = c->score;
    rec->sub.hkpBridgeConstraintAtom_init(rec);
    vself->FUN_008fc3f0(rec, k);
}


extern "C" void _ReadWriteBarrier();
void __cdecl FUN_00c856c0(void*, void*);
extern "C" void __cdecl CopyIfNonEmpty(void*, int, int);
extern int DAT_01268358;
static __declspec(noinline) void* FUN_00cb0ad0(char* s, int maxLen)
{
    int len = hkString_strLen((int)s);
    if (len > maxLen)
        len = maxLen;
    char* p = (char*)AllocateWithHeader(FUN_00c85750()->allocator, len + 1);
    CopyIfNonEmpty(p, (int)s, len);
    p[len] = 0;
    return p;
}
struct StringSlot
{
    unsigned int* volatile p;
};
// Frees the slot's old string if its low bit is set, then stores a tagged copy of s (length-limited unless len is -1), or DAT_01268358 when s is null.
// @fnv 0x00cb0b10
static __declspec(noinline) void FUN_00cb0b10(StringSlot slotRef, char* apString, int aiLength)
{
    unsigned int* slot = slotRef.p;
    unsigned int cur = *slot;
    if ((char*)(cur & ~1u) == apString)
        return;
    if (cur & 1)
    {
        char* old = (char*)(cur - 1);
        FNVTaskMemoryRouter* r = FUN_00c85750();
        if (old)
            _ReadWriteBarrier();
        else
            _ReadWriteBarrier();
        FUN_00c856c0(r->allocator, old);
    }
    if (apString)
    {
        if (aiLength == -1)
        {
            *slot = (unsigned int)FUN_00cb0aa0(apString) + 1;
            return;
        }
        *slot = (unsigned int)FUN_00cb0ad0(apString, aiLength) + 1;
        return;
    }
    *slot = DAT_01268358;
}

struct S_ca4520_Entry
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
    unsigned short count;
    unsigned short unk46;
    unsigned short* runs;
    unsigned short* lists;
    unsigned short GetCount() const
    {
        return count;
    }
    unsigned short* GetLengths() const
    {
        return runs;
    }
    unsigned short GetVertices() const
    {
        return (unsigned short)unk08;
    }
    unsigned short* FUN_00a75f10();
};
struct S_ca4520_Slot
{
    NiPointer<S_ca4520_Entry> entry;
    int unk04;
};
struct S_ca4520
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_ca4520_Slot* slots;
    S_ca4520_Slot& GetPart(unsigned int n) const
    {
        return slots[n];
    }
    S_ca4520_Entry* GetData(unsigned int n) const
    {
        return GetPart(n).entry;
    }
    bool IsDegenerate(unsigned int key) const;
};

union HandleKey
{
    unsigned int raw;
    struct
    {
        unsigned int index : 20;
        unsigned int slot : 12;
    };
};

// Looks up the entry for the key's slot, walks its runs to the key's index, and returns true if any two of the three consecutive values there are equal.
// @fnv 0x00ca4520
// pdb: hkNiTriStripsShape::isChildShapeDegenerate | hkNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: aKey
bool S_ca4520::IsDegenerate(unsigned int key) const
{
    bool result = false;
    HandleKey k;
    k.raw = key;
    S_ca4520_Entry* e = GetData(k.slot);
    unsigned short count = e->GetCount();
    unsigned short* p = e->FUN_00a75f10();
    unsigned short* runs = e->GetLengths();
    unsigned short i = 0;
    unsigned int idx = k.index;
    while (i < count)
    {
        if (idx < (unsigned int)(runs[i] - 2))
            break;
        idx += 2 - runs[i];
        p += runs[i];
        ++i;
    }
    unsigned short* q = p + idx;
    unsigned short a = *q;
    q++;
    unsigned short b = *q;
    q++;
    unsigned short c = *q;
    if (a == b || a == c || b == c)
        result = true;
    return result;
}

static volatile int g_helperSink;
__declspec(noinline) static int FUN_00cb0b10(int a, int b, int c)
{
    g_helperSink = a + b + c;
    return g_helperSink;
}

struct SStringPtr
{
    void* FUN_00cb0c10(const char* s);
};
struct SelfRef
{
    void* p;
};
static int g_sink;
static __declspec(noinline) void FUN_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (int)s + len;
    *(int*)self.p = g_sink;
}

namespace fnv_00cb0c50 {
struct SStringPtr
{
    void FUN_00cb0c50(const char* s, int len);
};
struct SelfRef
{
    void* p;
};
static int g_sink;
static __declspec(noinline) void FUN_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (int)s + len;
    *(int*)self.p = g_sink;
}
}  // namespace fnv_00cb0c50

template <typename KEY> struct MapOps
{
    static __forceinline unsigned hash(KEY key, unsigned mod)
    {
        return unsigned((unsigned long)(key) >> 4) * 2654435761U & mod;
    }
    static __forceinline int isValid(KEY key)
    {
        return key != KEY(-1);
    }
    static __forceinline int equal(KEY key0, KEY key1)
    {
        return key0 == key1;
    }
};

struct ProbeMap64
{
    struct Pair
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };
    typedef MapOps<unsigned __int64> OPS;

    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FUN_00cb1c60(unsigned __int64 key);
};

namespace fnv_00ca2140 {
extern int DAT_010c7310;
struct ChildLayout;
typedef void (__thiscall ChildLayout::*ReleaseFunction)(void*);
extern ReleaseFunction DAT_010c7318;
struct BaseState
{
    virtual ~BaseState()
    {}
};
struct ChildLayout
{
    void* m_vptr;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    ~ChildLayout()
    {
        m_vptr = &DAT_010c7310;
        if (m_iWordAt04 != 0)
        {
            (this->*DAT_010c7318)(m_iWordAt04);
            m_iWordAt04 = 0;
            m_iThirdValue = 0;
            m_8 = 0;
        }
    }
};
struct FUN_00ca2140 : BaseState
{
    ChildLayout child;
    ~FUN_00ca2140();
};
// Destructor that only calls ClearAndFreeEntries on this.
// @fnv 0x00ca2140
// pdb: bhkRagdollPenetrationUtil::`scalar deleting destructor' | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00ca2140::~FUN_00ca2140()
{
    ((FUN_00ca20e0_Class*)this)->ClearAndFreeEntries();
}
}  // namespace fnv_00ca2140

extern int DAT_010c7600;
extern float DAT_010c72c0;
struct ExtraArray
{
    ~ExtraArray()
    {
        FUN_00aa10f0(m_pBase);
    }
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    unsigned int unk08, m_uiESize, m_uiCount, growBy;
    ExtraArray(unsigned int n = 0, unsigned int g = 1)
    {
        unk08 = n;
        growBy = g;
        m_uiESize = 0;
        m_uiCount = 0;
        m_pBase = 0;
        unk00 = (int)&DAT_010c7600;
    }
    __declspec(noinline) void Resize(unsigned int capacity)
    {
        if (capacity == unk08)
            return;
        if (capacity < m_uiESize)
        {
            for (unsigned int i = capacity; i < m_uiESize; ++i)
            {
                if (m_pBase[i] != S_00ca49a0_Elem(0))
                {
                    m_pBase[i] = S_00ca49a0_Elem(0);
                    --m_uiCount;
                }
            }
            m_uiESize = capacity;
        }
        S_00ca49a0_Elem* old = m_pBase;
        unk08 = capacity;
        if (capacity)
        {
            m_pBase = (S_00ca49a0_Elem*)FUN_00aa13e0(capacity * sizeof(S_00ca49a0_Elem));
            for (unsigned int i = 0; i < m_uiESize; ++i)
                m_pBase[i] = old[i];
            for (unsigned int i = m_uiESize; i < unk08; ++i)
                m_pBase[i] = S_00ca49a0_Elem(0);
        }
        else
            m_pBase = 0;
        FUN_00aa10f0(old);
    }
    void ClearRecords();
    __declspec(noinline) void FUN_00ca49a0(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= m_uiESize)
        {
            m_uiESize = i + 1;
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else if (m_pBase[i] == S_00ca49a0_Elem(0))
        {
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else
        {
            if (e == S_00ca49a0_Elem(0))
                --m_uiCount;
        }
        m_pBase[i] = e;
    }
    const S_00ca49a0_Elem& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    unsigned int Add(const S_00ca49a0_Elem& e)
    {
        return SetAtGrow(m_uiESize, e);
    }
    unsigned int SetAtGrow(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= unk08)
            Resize(i + growBy);
        FUN_00ca49a0(i, e);
        return i;
    }
};
inline void CopyEntry(ExtraArray& out, int i, const ExtraArray& source)
{
    const S_00ca49a0_Elem& e = source.m_pBase[i];
    unsigned at = out.m_uiESize;
    if (at >= out.unk08)
    {
        unsigned n = at + out.growBy;
        out.Resize(n);
    }
    out.FUN_00ca49a0(at, e);
}
struct SavedExtraArray : ExtraArray
{
    SavedExtraArray() : ExtraArray()
    {}
};
struct SerializedExtraBody
{
    unsigned int unk00;
    float scale;
    ExtraArray entries;
    unsigned int value20, value24, value28, value2c;
    static void Swap4(void* p)
    {
        *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
    }
    void Swap()
    {
        Swap4(&scale);
        Swap4(&value20);
        Swap4(&value24);
        Swap4(&value28);
        Swap4(&value2c);
    }
};
struct ExtraSerializer
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void Restore(int token);
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual SerializedExtraBody* Acquire(int* token);
    void bhkShape_SaveBinary(S_00ca59d0_Stream* stream);
    void FUN_00ca77f0(S_00ca59d0_Stream* stream);
};
inline void SaveR(S_00ca59d0_Bin& bin, const unsigned int* p)
{
    unsigned int uiSize = 4;
    unsigned int written = bin.unk0C(&bin, p, 4, &uiSize, 1);
    bin.unk04 += written;
}
inline void SaveRV(S_00ca59d0_Bin& bin, unsigned int value)
{
    SaveR(bin, &value);
}
// Copies the acquired body's entries, writes each entry's link via stream->v12 and its unk04 value, byte-swapping the body when unk1E4 is not 1.
// @f3 0x00913090 (community match, verified in this file)
// pdb: bhkNiTriStripsShape::SaveBinary | bhkNiTriStripsShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void ExtraSerializer::FUN_00ca77f0(S_00ca59d0_Stream* stream)
{

    int token;
    SerializedExtraBody* raw = Acquire(&token);
    SavedExtraArray entries;
    int count = 0;
    if (raw) {
    count = (int)raw->entries.m_uiESize;
    SerializedExtraBody* body = raw;
    for (int i = 0; i < count; ++i)
        CopyEntry(entries, i, body->entries);
    body->entries.ClearRecords();
    body->entries.Resize(0);
    body->scale = DAT_010c72c0;
    if (*(unsigned char*)&stream->unk1E4 != 1)
        body->Swap();
    }
    bhkShape_SaveBinary(stream);
    S_00ca59d0_Save(*stream->unk250, &count, 1);
    for (int i = 0; i < count; ++i)
    {
        int link = (int)entries.m_pBase[i].obj.m_p;
        stream->v12(link);
    }
    S_00ca59d0_Save(*stream->unk250, &count, 1);
    for (int i = 0; i < count; ++i)
    {
        SaveRV(*stream->unk250, entries.GetAt(i).unk04);
    }
    if (raw && *(unsigned char*)&stream->unk1E4 != 1)
        raw->Swap();
    Restore(token);
}


extern int DAT_0102009c;
extern int DAT_01268154;
extern int DAT_01268118;

struct cb86f0_obj : bhkRefObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;

    cb86f0_obj()
    {
        Initialize();
        vtable = (void*)0x102016c;
        const int inc = 1;
        unk0c = 0;
        DAT_01268154 += inc;
        vtable = (void*)&DAT_0102009c;
        DAT_01268118 += inc;
        vtable = (void*)0x10c8914;
    }

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

struct FUN_00cb86f0_class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50(void* obj, int param);
    cb86f0_obj* FUN_00cb86f0(int a1);
};

// Allocates a cb86f0_obj, calls v50 on it with a1, and returns the new object.
// @f3 0x0092c160 (community match, verified in this file)
extern int DAT_010f3194;
extern int DAT_00dc050c;
extern int DAT_00dc05d4;
extern int DAT_00e36e14;
extern int DAT_010f31ac;
extern int DAT_010f31b8;
void* __cdecl FUN_0089eb90(unsigned int size);
struct cb86f0_baseF3
{
    int __thiscall FUN_008f7c10();
};
struct cb86f0_objF3 : cb86f0_baseF3
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;

    cb86f0_objF3()
    {
        FUN_008f7c10();
        vtable = (void*)&DAT_00dc050c;
        const int inc = 1;
        unk0c = 0;
        DAT_010f31ac += inc;
        vtable = (void*)&DAT_00dc05d4;
        DAT_010f31b8 += inc;
        vtable = (void*)&DAT_00e36e14;
    }
    static void* operator new(unsigned int size)
    {
        return FUN_0089eb90(size);
    }
    static void operator delete(void* p);
};

struct FUN_00cb86f0_vt49
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v49(void* obj, int param);
};

cb86f0_obj* FUN_00cb86f0_class::FUN_00cb86f0(int a1)
{
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_010f3194);
    cb86f0_objF3* p = new cb86f0_objF3();
    reinterpret_cast<FUN_00cb86f0_vt49*>(this)->v49(p, a1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_010f3194);
    return (cb86f0_obj*)p;
}


struct S_ca5870_Alloc
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct S_ca5870_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_ca5870_Alloc* m_10;
};

struct S_ca5870_Obj
{
    S_ca5870_Obj(void* arg);
    int unk00;
    unsigned short m_04;
    unsigned short unk06;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    void FUN_00c905b0();

    static void* operator new(unsigned int size) throw()
    {
        S_ca5870_Holder* h = (S_ca5870_Holder*)FUN_00c85750();
        void* p = h->m_10->Alloc(size);
        ((S_ca5870_Obj*)p)->m_04 = (unsigned short)size;
        return p;
    }
};

extern "C" void __cdecl _ReadWriteBarrier(void);

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& val)
    {
        FNVTaskMemoryRouter* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(router->allocator, this, sizeof(T));
        }
        T* slot = m_data + m_iElementCount;
        _ReadWriteBarrier();
        *slot = val;
        m_iElementCount++;
    }
};

struct S_00cb0030_Out : S_00ca4e10_Out
{
    int unk08;
    int unk0c;
    __m128 unk10;
    int unk20;
    int unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
};

struct S_00cb0030_Cls : S_00ca4e10_Cls
{
    void bhkBvTreeShape_CopyCinfo(S_00cb0030_Out* out);
    void FUN_00cb0030(S_00cb0030_Out* out);
};

// Calls bhkBvTreeShape_CopyCinfo, then if obj->unk18 yields a source, fills out unk10, unk20, unk24, unk28, unk2c and unk40 from its fields.
// @f3 0x00921ba0 (community match, verified in this file)
struct S_b173Src
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
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
    float unk58;
    int unk5c;
    int unk60;
};
struct S_b173Obj
{
    S_b173Src* FUN_009a82b0();
};
struct S_b173Src2
{
    S_b173Src* FUN_009a7e90();
};
struct S_b173This
{
    void FUN_00910dc0(S_00cb0030_Out* out);
};

// pdb: bhkTriSampledHeightFieldBvTreeShape::CopyCinfo | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: bhkMoppBvTreeShape::CopyCinfo)
// pdb params: arInfo
void S_00cb0030_Cls::FUN_00cb0030(S_00cb0030_Out* out)
{
    ((S_b173This*)this)->FUN_00910dc0(out);
    if (unk08 != 0)
    {
        S_b173Src* a = ((S_b173Obj*)unk08)->FUN_009a82b0();
        if (a != 0)
        {
            S_b173Src* b = ((S_b173Src2*)a)->FUN_009a7e90();
            if (b != 0)
            {
                out->unk2c = b->unk58 + b->unk18;
                out->unk28 = b->unk18 - b->unk58;
                float* f = (float*)&out->unk10;
                f[0] = b->unk20;
                f[1] = b->unk24;
                f[2] = b->unk28;
                f[3] = b->unk2c;
                out->unk20 = b->unk10;
                out->unk24 = b->unk14;
                out->unk40 = b->unk60;
            }
        }
    }
}


// @f3twin 0x0091dd50 of 0x004a4bc0
int* __fastcall F3_FUN_0091dd50(SomeClass* pThis)
{
    return (int*)((char*)pThis + 0x74);
}

// @f3 0x004d58c0 (community match, verified in this file)
namespace f3m_004d58c0 {
struct LockedRect
{
    int pitch;
    char* bits;
};

struct D3DTex
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual long __stdcall LockRect(unsigned int level, LockedRect* rect, const void* area, unsigned long flags);
};

struct RendererData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual D3DTex* GetD3DTexture();
};

struct Texture
{
    char pad00[0x24];
    RendererData* rendererData;
};

struct ExtraDataList
{
    void FUN_00411790(Texture*& texture, LockedRect*& rect);
};

struct TESWorldSpace;

struct TESObjectCELL
{
    char pad00[0x24];
    unsigned char flags;
    char pad25[0x28 - 0x25];
    ExtraDataList extraData;
    char pad2c[0xc0 - 0x2c];
    TESWorldSpace* worldSpace;

    void FUN_004d58c0(int x, int y, LockedRect*& rect, int index, char value);
};

struct DataHandler
{
    TESObjectCELL* FUN_0043c690(int x, int y, TESWorldSpace* world, int create);
};

extern DataHandler* g_dataHandler;
void FUN_004d5760(TESObjectCELL* cell, Texture*& texture, LockedRect*& rect);

// pdb: TESObjectCELL::PlaceCanopyShadowInAdjacentCell | TESObjectCELL.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: TES::GetGridCellCell)
// pdb params: aiX, aiY, apRect, aiIndex, aiValue
void TESObjectCELL::FUN_004d58c0(int x, int y, LockedRect*& rect, int index, char value)
{
    Texture* texture = 0;
    if (!rect)
    {
        TESWorldSpace* world = 0;
        if (!(flags & 1))
            world = worldSpace;
        TESObjectCELL* cell = g_dataHandler->FUN_0043c690(x, y, world, 0);
        if (!cell)
            return;
        cell->extraData.FUN_00411790(texture, rect);
        if (!texture)
            FUN_004d5760(cell, texture, rect);
        if (!rect)
            return;
    }
    if (!rect->bits)
        texture->rendererData->GetD3DTexture()->LockRect(0, rect, 0, 0);
    char* bits = rect->bits;
    if (bits[index])
        bits[index] = (char)0xff;
    else
        bits[index] = value;
}
}   // namespace f3m_004d58c0
