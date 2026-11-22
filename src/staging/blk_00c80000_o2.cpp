#include "f3_common.h"
// src/staging/blk_00c80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_010c53dc;
extern int DAT_01267e60;

struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};

struct FUN_00c81550_holder
{
    void FUN_00c81550();
};

// @fnv 0x00c81550
// pdb: bhkBlendCollisionObject::~bhkBlendCollisionObject | bhkBlendCollisionObject.obj | fnv360_0721_beta, call_seq, medium
void FUN_00c81550_holder::FUN_00c81550()
{
    *(int*)this = (int)&DAT_010c53dc;
    --DAT_01267e60;
    ((FUN_00c6c290_holder*)this)->FUN_00c6c290();
}

void* __cdecl FUN_00c81c50(void*);
// Calls FUN_00c81c50 on arg and returns the float at offset 0x18 of the result, or 1.0f if the result is null.
// @fnv 0x00c82580
// pdb: bhkBlendCollisionObject::GetBipBlendValue | bhkBlendCollisionObject.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apBip
float FUN_00c82580(void* arg)
{
    void* p = FUN_00c81c50(arg);
    return p ? *(float*)((char*)p + 0x18) : 1.0f;
}

extern int DAT_011b09d8[];

// Copies the three ints of entry a from DAT_011b09d8 into the buffer c.
// @fnv 0x00c84cd0
// pdb: bhkShape::GetMaterialColor | bhkShape.obj | fnv360_0822_retail, objrun, medium, conflict (skyrim: bhkShape::LinkObject)
// pdb params: aeType, arColor
void __cdecl FUN_00c84cd0(int aiIndex, void* apOut)
{
    int* p = &DAT_011b09d8[aiIndex * 3];
    *(int*)apOut = p[0];
    *(int*)((char*)apOut + 4) = p[1];
    *(int*)((char*)apOut + 8) = p[2];
}

struct bhkRefObject
{
    void UpdateReference(bool);
};
struct bhkBoxShape
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    void FUN_00c84e50(bool b);
};
// Links m_next to this when b is set, otherwise clears it, then calls UpdateReference(b) on this as a bhkRefObject.
// @fnv 0x00c84e50
// pdb: bhkShape::Link | bhkShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: abAttach
void bhkBoxShape::FUN_00c84e50(bool b)
{
    if (this && m_next)
    {
        struct bhkBoxShape* p = (struct bhkBoxShape*)m_next;
        p->m_next = b ? this : 0;
    }
    reinterpret_cast<bhkRefObject*>(this)->UpdateReference(b);
}

struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct FUN_00c87670_Class : NiObject
{
    void FUN_00c87670(NiStream& stream);
    void* m_pad_0x4;
    void* m_pad_0x8;
    void* m_field_0xc;
};
// @fnv 0x00c87670
// pdb: bhkSerializable::LinkObject | bhkSerializable.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream
void FUN_00c87670_Class::FUN_00c87670(NiStream& stream)
{
    NiObject::LinkObject(stream);
    if (m_field_0xc)
        ((void(__thiscall*)(FUN_00c87670_Class*, void*)) reinterpret_cast<void**>(
            reinterpret_cast<void**>(this)[0])[44])(this, m_field_0xc);
}

extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c88a20_cls
{
    void __thiscall FUN_00c88930();
    void* __thiscall FUN_00c88a20(unsigned int flags);
};
// Calls FUN_00c88930, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c88a20
// pdb: NiTransformData::`scalar deleting destructor' | NiTransformData.obj | fnv360_0822_retail, caller_sim, high
void* __thiscall FUN_00c88a20_cls::FUN_00c88a20(unsigned int flags)
{
    FUN_00c88930();
    if (flags & 1)
        operator delete(this, 0x2c);
    return this;
}

struct FUN_00cf4ce0_cls
{
    void FUN_00cf4ce0(int* arg);
};

struct FUN_00c8aa40_cls
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    void FUN_00c8aa40(int* arg);
};

// @fnv 0x00c8aa40
// pdb: bhkBinaryAction::SetRigidBodyA | bhkBinaryAction.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apBody
void FUN_00c8aa40_cls::FUN_00c8aa40(int* pOther)
{
    if (this && m_p8)
        reinterpret_cast<FUN_00cf4ce0_cls*>(m_p8)->FUN_00cf4ce0(reinterpret_cast<FUN_00c8aa40_cls*>(pOther)->m_p8);
}

// @f3 0x005ad270 (community match, verified in this file)
namespace f3m_005ad270 {
struct C_005ad270 { int FUN_005ad270(); };
// pdb: PackageLocation::GetSaveSize | PackageLocation.obj | fnv360_0822_retail, call_seq, medium
int C_005ad270::FUN_005ad270()
{
    int result = 5;
    char v = *(char*)this;
    if (v >= 0 && (v <= 4 || v == 5))
        result = 9;
    return result;
}
}   // namespace f3m_005ad270


struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
// @fnv 0x00c8cd00
void FUN_00c8cd00(void* apBlock)
{
    if (apBlock)
        g_memoryManager.Deallocate((char*)apBlock - *(const unsigned char*)((const char*)apBlock - 1));
}

struct FUN_00c9a6e0_struct
{
    void FUN_00c9a6e0();
};

struct FUN_00c9a820_class
{
    void Reset();
};

// Calls the sub-object at offset 0x38, then sets the floats at 0x54 and 0x50 to -1.0 and the int at 0x58 to 0.
// @fnv 0x00c9a820
// pdb: bhkBlendController::ClearKeys | bhkBlendController.obj | fnv360_0822_retail, call_gap, medium
void FUN_00c9a820_class::Reset()
{
    ((FUN_00c9a6e0_struct*)((char*)this + 0x38))->FUN_00c9a6e0();
    *(float*)((char*)this + 0x54) = -1.0f;
    *(int*)((char*)this + 0x58) = 0;
    *(float*)((char*)this + 0x50) = -1.0f;
}

void __cdecl FUN_00c9ad60();
void __cdecl _delete(void* ptr, unsigned int size);
struct FUN_00c9af20_class
{
    void FUN_00c9ad60();
    void* FUN_00c9af20(int flag);
};
// @fnv 0x00c9af20
void* FUN_00c9af20_class::FUN_00c9af20(int aiFlags)
{
    FUN_00c9ad60();
    if (aiFlags & 1)
        _delete(this, 0x5c);
    return this;
}

extern void(__stdcall* DAT_010c53bc)(int*);
struct FUN_00c80630_holder
{
    int* m_vtbl;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void ResetHolder();
};
// @f3 0x0045bd00 (community match, verified in this file)
struct FUN_0086ba60_cls
{
    void FUN_0086ba60(int* p);
};
extern FUN_0086ba60_cls DAT_01090a78;
extern int DAT_00dbdf60;

// pdb: TESTexture::~TESTexture | TESTexture.obj | fnv360_0822_retail, call_seq, low
void FUN_00c80630_holder::ResetHolder()
{
    *(int* volatile*)&m_vtbl = (int*)&DAT_00dbdf60;
    int* old = *(int* volatile*)&m_p4;
    if (old)
    {
        DAT_01090a78.FUN_0086ba60(old);
    }
    m_p4 = 0;
    *(short*)((char*)&m_p8 + 2) = 0;
    *(short*)&m_p8 = 0;
}


struct FUN_00c81640_cls
{
    void* __thiscall FUN_00c81640(bool flag);
};

// @fnv 0x00c81640
// pdb: bhkBlendCollisionObject::`scalar deleting destructor' | bhkBlendCollisionObject.obj | fnv360_1110_retail, caller_sim, low, conflict (skyrim: hkStiffSpringConstraintCinfo::SetPivotInB)
void* __thiscall FUN_00c81640_cls::FUN_00c81640(bool abFree)
{
    *reinterpret_cast<void**>(this) = &DAT_010c53dc;
    --DAT_01267e60;
    reinterpret_cast<FUN_00c6c290_holder*>(this)->FUN_00c6c290();
    if (abFree & 1)
        _delete(this, 0x2c);
    return this;
}

struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 DAT_011a9490;
// Checks whether the NiPoint3 at offset 0x10 of p equals DAT_011a9490 and returns 1 if so, otherwise 0.
// @fnv 0x00c84ec0
int __stdcall FUN_00c84ec0(void* apObject)
{
    NiPoint3* v = (NiPoint3*)((char*)apObject + 0x10);
    if (v->x == DAT_011a9490.x && v->y == DAT_011a9490.y && v->z == DAT_011a9490.z)
        return 1;
    return 0;
}

extern int DAT_010c69f4;
struct FUN_00c6aca0_holder
{
    void* __thiscall FUN_00c6aca0();
};
struct FUN_00c9a040_cls
{
    void* __thiscall FUN_00c9a040(bool b);
};
// @fnv 0x00c9a040
// pdb: bhkWorldM::`scalar deleting destructor' | bhkWorldM.obj | fnv360_0822_retail, objrun, medium
void* __thiscall FUN_00c9a040_cls::FUN_00c9a040(bool abFree)
{
    *(void**)this = (void*)&DAT_010c69f4;
    ((FUN_00c6aca0_holder*)this)->FUN_00c6aca0();
    if (abFree & 1)
        g_memoryManager.Deallocate(this - *(unsigned char*)(this - 1));
    return this;
}

__forceinline int Sign_00c9a070(float f)
{
    return f < 0.0f ? -1 : 1;
}

struct Range_00c9a070
{
    float fHi;
    float fLo;
    Range_00c9a070(float h, float l) : fHi(h), fLo(l)
    {}
};

__forceinline void Adjust_00c9a070(float& out, float v, float fHi, float fLo)
{
    Range_00c9a070 r(fHi, fLo);
    float s = (float)Sign_00c9a070(v);
    float t = v + (r.fHi - r.fLo) * s;
    if (t * s > 0.0f)
        out -= t;
}

struct FUN_00c9a070_shell
{
    char _pad0[0xa0];
    float fLo[3];
    char _padac[0x14];
    float fHi[3];
    void AdjustVector(float* p);
};

// Adjusts each of the three components of p using the corresponding fHi/fLo bounds via Adjust_00c9a070.
// @f3 0x00908c40 (community match, verified in this file)
// pdb: bhkWorldM::CalcNewCenter | bhkWorldM.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arCenter
void FUN_00c9a070_shell::AdjustVector(float* p)

{

    float value = p[0];

    Range_00c9a070 bounds(fHi[0],fLo[0]);

    if (value < 0.0f) {

        float v = value - bounds.fHi;

        v += bounds.fLo;

        if (v < 0.0f) p[0] -= v;

    } else {

        float v = value + bounds.fHi;

        v -= bounds.fLo;

        if (v > 0.0f) p[0] -= v;

    }

    value = p[1]; bounds.fHi = fHi[1]; bounds.fLo = fLo[1];

    if (value < 0.0f) {

        float v = value - bounds.fHi;

        v += bounds.fLo;

        if (v < 0.0f) p[1] -= v;

    } else {

        float v = value + bounds.fHi;

        v -= bounds.fLo;

        if (v > 0.0f) p[1] -= v;

    }

    value = p[2]; bounds.fHi = fHi[2]; bounds.fLo = fLo[2];

    if (value < 0.0f) {

        float v = value - bounds.fHi;

        v += bounds.fLo;

        if (v < 0.0f) p[2] -= v;

    } else {

        float v = value + bounds.fHi;

        v -= bounds.fLo;

        if (v > 0.0f) p[2] -= v;

    }

}


namespace fnv_00c9a2c0 {
struct NiPoint3
{
    float x, y, z;
    char* FUN_00a59af0(const char* pcName);
};
char* FUN_00a7d330(const char*);
extern __declspec(thread) int g_iTlsMemContext;

struct StrArr
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct MemContextScope
{
    int iSaved;
    MemContextScope(int aiMemoryContext)
    {
        iSaved = g_iTlsMemContext;
        g_iTlsMemContext = aiMemoryContext;
    }
    ~MemContextScope()
    {
        g_iTlsMemContext = iSaved;
    }
};

}  // namespace fnv_00c9a2c0

extern int DAT_010c6b04;
extern "C" void __cdecl NiFree(void*);
struct FUN_00c9ae80_class
{
    void* m_p0;
    void* m_p4;
    void* __thiscall FUN_00c9ae80(unsigned char b);
};
// Sets m_p0 to DAT_010c6b04, frees m_p4 with NiFree, and if bit 0 of b is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00c9ae80
// pdb: NiTArray<CombatGroup *,NiTMallocInterface<CombatGroup *> >::`scalar deleting destructor' | CombatManager.obj | fnv360_0822_retail, vtable, medium
void* __thiscall FUN_00c9ae80_class::FUN_00c9ae80(unsigned char abFree)
{
    void* p = m_p4;
    m_p0 = &DAT_010c6b04;
    NiFree(p);
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00c9aeb0_t
{
    char m_data[0x5c];
    FUN_00c9aeb0_t();
    ~FUN_00c9aeb0_t();
    static void* operator new(unsigned int);
};
// Allocates and constructs a new FUN_00c9aeb0_t object, returning its pointer.
// @fnv 0x00c9b020
FUN_00c9aeb0_t* FUN_00c9b020()
{
    return new FUN_00c9aeb0_t;
}

struct ScriptX
{
    void GetLocalData();
    void bhkShapePhantom_SetPositionAndLinearCast(int a, int b, int c, int d);
};
extern void(__stdcall* DAT_0126820c_enter)(int*);
extern void(__stdcall* DAT_0126820c_leave)(int*);
// @f3 0x00568600 (community match, verified in this file)
extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(void*);
extern int DAT_010f327c;

struct ScriptXInterface
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
    virtual void Invoke(int a, int b, int c, int d);
};

struct ScriptXLayout
{
    int unk00;
    int unk04;
    ScriptXInterface* unk08;
};

// pdb: bhkShapePhantom::SetPositionAndLinearCast | bhkShapePhantom.obj | fnv360_0822_retail, call_seq, high
// pdb params: arPos, arIn, arPnts, apStart
// pdb: bhkShapePhantom::SetPositionAndLinearCast | bhkShapePhantom.obj | fnv360_0822_retail, call_seq, high (was: InvokeInterfaceCall)
void ScriptX::bhkShapePhantom_SetPositionAndLinearCast(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    if (this)
    {
        ScriptXInterface* iface = reinterpret_cast<ScriptXLayout*>(this)->unk08;
        if (iface)
        {
            fnv_EnterCriticalSection(&DAT_010f327c);
            GetLocalData();
            iface->Invoke(aiArg1, aiArg2, aiArg3, aiArg4);
            GetLocalData();
            fnv_LeaveCriticalSection(&DAT_010f327c);
        }
    }
}


struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c6b910 : A51BF0Base
{
    FUN_00c6b910();
};

struct bhkBlendCollisionObject : FUN_00c6b910
{
    void* m_vtbl;
    unsigned char m_pad_04[8];
    unsigned short m_flags;
    unsigned char m_pad_0e[6];
    unsigned char m_flag14;
    unsigned char m_pad_15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;

    void __thiscall FUN_00c657f0(void* p, int value);

    bhkBlendCollisionObject()
    {
        m_vtbl = &DAT_010c53dc;
        ++DAT_01267e60;
        m_f18 = 0.0f;
        m_flags &= 0xfeff;
        m_f1c = 1.0f;
        m_i20 = 8;
        m_i24 = 0;
        m_i28 = 0;
        m_flag14 = 0;
    }

    bhkBlendCollisionObject* FUN_00c81670(int value);
};

// @f3 0x008f31a0 (community match, verified in this file)
namespace task1442 {
void* __cdecl FUN_0089eb90(unsigned);
extern int DAT_010f2edc;
struct FUN_008d9f90 { virtual void slot0(); FUN_008d9f90(); };
struct bhkBlendCollisionObject : FUN_008d9f90 {
 int unk04, unk08;
 unsigned short m_flags, unk0E;
 int unk10;
 unsigned char m_flag14, unk15, unk16, unk17;
 float m_f18,m_f1c;
 int m_i20,m_i24,m_i28;
 virtual void slot1();
 static void* operator new(unsigned n) { return FUN_0089eb90(n); }
 bhkBlendCollisionObject() { ++DAT_010f2edc; m_f18=0.0f; m_flags&=0xfeff; m_f1c=1.0f; m_i20=10; m_i24=0; m_i28=0; m_flag14=0; }
 void FUN_008d1f10(void*,int);
};
}
// pdb: bhkBlendCollisionObject::CreateClone | bhkBlendCollisionObject.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
bhkBlendCollisionObject* bhkBlendCollisionObject::FUN_00c81670(int value) {
 task1442::bhkBlendCollisionObject* p=new task1442::bhkBlendCollisionObject;
 ((task1442::bhkBlendCollisionObject*)this)->FUN_008d1f10(p,value);
 p->m_f1c=this->m_f1c; p->m_f18=this->m_f18; p->m_i24=this->m_i24;
 return (bhkBlendCollisionObject*)p;
}


namespace fnv_00c81730 {
struct A51BF0Base
{
    int* m_vtbl;
    int m_pad4;
    int m_pad8;
    unsigned short m_flags;
    unsigned char m_pad10;
    char m_pad11[3];

    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c6b910_cls
{
    void FUN_00c6b910();
};

struct bhkBlendCollisionObject : A51BF0Base
{
    unsigned char m_flag14;
    char m_pad15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;

    bhkBlendCollisionObject()
    {
        reinterpret_cast<FUN_00c6b910_cls*>(this)->FUN_00c6b910();
        m_vtbl = reinterpret_cast<int*>(&DAT_010c53dc);
        ++DAT_01267e60;
        m_f18 = 0.0f;
        m_flags &= 0xfeff;
        m_f1c = 1.0f;
        m_i20 = 8;
        m_i24 = 0;
        m_i28 = 0;
        m_flag14 = 0;
    }
};

}  // namespace fnv_00c81730

struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const* str);
};

extern char* _EmptyFS;

struct DynCastHelper
{
    NiObject* __thiscall DynamicCast(unsigned int const* rtti);
};

int* __cdecl FUN_00c4b470(int, int, int);

struct StringHolder
{
    char* p;

    StringHolder(char const* str) : p(NiGlobalStringTable::AddString(str))
    {}

    ~StringHolder()
    {
        if (p != _EmptyFS)
        {
            InterlockedDecrement(reinterpret_cast<long*>(p - 8));
        }
    }
};

// Looks up a named property on param_1, dynamic-casts the result to a float-bearing object, and returns its value at offset 0x18, defaulting to 1.0f.
// @f3 0x008f38a0 (community match, verified in this file)
NiObject* __cdecl FUN_007235f0(void* obj);

// pdb: bhkBlendCollisionObject::GetBlendValue | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRoot, apName
float GetFloatProperty(int aiObject, char const* apName)
{
    float result = 1.0f;

    if (aiObject != 0)
    {
        int* object;

        if (apName != 0)
        {
            {
                StringHolder str(apName);
                object = FUN_00c4b470(aiObject, reinterpret_cast<int>(&str.p), 0);
            }

            if (object == 0)
            {
                object = reinterpret_cast<int*>(aiObject);
            }
        }
        else
        {
            object = reinterpret_cast<int*>(aiObject);
        }

        NiObject* casted = FUN_007235f0(object);

        if (casted != 0)
        {
            result = *reinterpret_cast<float*>(reinterpret_cast<char*>(casted) + 0x18);
        }
    }

    return result;
}


struct NiObjLB
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void LoadBinary(NiStream& stream);
};

struct FUN_00c87650_t : NiObjLB
{
    virtual void LoadBinary(NiStream& stream);
};

// Calls the base NiObjLB::LoadBinary, then dispatches virtual slot 43 on this with the stream.
// @fnv 0x00c87650
// pdb: bhkSerializable::LoadBinary | bhkSerializable.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkSerializable::RegisterStreamables)
// pdb params: arStream
void FUN_00c87650_t::LoadBinary(NiStream& stream)
{
    NiObjLB::LoadBinary(stream);
    ((void(__thiscall*)(void*, NiStream&))(*(void***)this)[43])(this, stream);
}

void(__stdcall* DAT_0126813c_leave)(void*);

struct FUN_00c88410_t
{
    void FUN_00caa140();
    void* __thiscall FUN_00c88410(unsigned int flags);
};

// Calls FUN_00caa140, then deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x00c88410
// pdb: bhkMouseSpringAction::`scalar deleting destructor' | GlobalFunc.obj | fnv360_0822_retail, vtable_prefix, high
void* __thiscall FUN_00c88410_t::FUN_00c88410(unsigned int flags)
{
    FUN_00caa140();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

struct FUN_00c8a7e0_t
{
    void FUN_00c8a720();
    void* FUN_00c8a7e0(bool b);
};
// Calls FUN_00c8a720, then deletes this with size 0x10 when b has bit 0 set, and returns this.
// @fnv 0x00c8a7e0
// pdb: BSFaceGenModelMap::Entry::`scalar deleting destructor' | BSFaceGenManager.obj | fnv360_0822_retail, vtable, high
void* FUN_00c8a7e0_t::FUN_00c8a7e0(bool abDelete)
{
    FUN_00c8a720();
    if (abDelete & 1)
        _delete(this, 0x10);
    return this;
}

struct FUN_00cf4d30_holder
{
    void SetRefObject(void*);
};
struct FUN_00c8aa60_holder
{
    int* m_auiShapeKeys;
    int* m_pAuxiliaryObject;
    int* m_target;
    void FUN_00c8aa60(void* arg);
};
// @fnv 0x00c8aa60
// pdb: bhkBinaryAction::SetRigidBodyB | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: bhkBinaryAction::SetRigidBodyA)
// pdb params: apBody
void FUN_00c8aa60_holder::FUN_00c8aa60(void* arg)
{
    if (this && m_target)
    {
        void** p = (void**)arg;
        ((FUN_00cf4d30_holder*)m_target)->SetRefObject(p[2]);
    }
}

struct H_00c8c810
{
    void FUN_00c84e50(bool);
    void InvokeCallbacksOnEntries();
    void ReleaseReferencedObjects();
    void FUN_00c8b410(bool b);
};
// Calls one of two methods depending on b, then forwards b to FUN_00c84e50.
// @fnv 0x00c8b410
// pdb: bhkListShape::Link | bhkListShape.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: abAttach
void H_00c8c810::FUN_00c8b410(bool b)
{
    if (b)
        InvokeCallbacksOnEntries();
    else
        ReleaseReferencedObjects();
    FUN_00c84e50(b);
}

namespace fnv_00c8c090 {
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : public A51BF0Base
{
    S_00cb79d0_Base();
    int* volatile m_p0;
    int m_p4;
    int m_p8;
};

extern int DAT_01030bf4;
extern int DAT_01066d44;
extern int DAT_012680f8;
extern int DAT_012681b0;

struct Object_00c8c090 : public S_00cb79d0_Base
{
    int m_iThirdValue;
    int m_10;

    Object_00c8c090()
    {
        m_p0 = (int*)&DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_p0 = (int*)&DAT_01066d44;
        ++DAT_012681b0;
    }

    ~Object_00c8c090()
    {}
};

// Allocates and constructs a new Object_00c8c090, returning it as an S_00cb79d0_Base pointer.
// @fnv 0x00c8c090
// pdb: bhkTransformShape::bhkTransformShape | bhkTransformShape.obj | fnv360_0822_retail, objrun, medium
S_00cb79d0_Base* FUN_00c8c090()
{
    return new Object_00c8c090;
}
}  // namespace fnv_00c8c090

extern int DAT_010c6fb0;
struct FUN_00c9d890_t
{
    int* m_p0;
    FUN_00c9d890_t(char b);
    ~FUN_00c9d890_t();
};
// Sets m_p0 to point at DAT_010c6fb0 and, if bit 0 of b is set, deletes this object.
// @fnv 0x00c9d890
// pdb: hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::`scalar deleting destructor' | hkpMultithreadedSimulation.obj | fnv360_0822_retail, vtable, high
FUN_00c9d890_t::FUN_00c9d890_t(char abDelete)
{
    m_p0 = &DAT_010c6fb0;
    if (abDelete & 1)
        operator delete(this);
}

extern __declspec(thread) unsigned int memoryCategory;

struct ScopedMemoryCategory
{
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ScopedMemoryCategory()
    {
        memoryCategory = previous;
    }
};

struct ArenaAllocator
{
    virtual void Reserved();
    virtual char* Allocate(unsigned int bytes);
};

struct ArenaMemoryManager : MemoryManager
{
    void* Allocate(unsigned int bytes);
};

struct TemporaryArena
{
    char* start;
    char* cursor;
    char* end;
    ArenaAllocator* current;
    ArenaAllocator* allocator;
    unsigned int unk14;
    ArenaAllocator* saved;
    unsigned int unk1C;
    unsigned int unk20;
    TemporaryArena();
    static void* operator new(unsigned int bytes)
    {
        return static_cast<ArenaMemoryManager*>(&g_memoryManager)->Allocate(bytes);
    }
};

struct ArenaRegistrationFlag
{
    unsigned int value;
    ArenaRegistrationFlag() : value(1)
    {}
    ArenaRegistrationFlag(const ArenaRegistrationFlag& other) : value(other.value)
    {}
};

extern "C" __declspec(dllimport) void __stdcall ArenaEnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall ArenaLeaveCriticalSection(void*);

struct FlaggedObj_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct WalkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FlaggedObj_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// @fnv 0x00c80330
// pdb: bhkUtilFunctions::SetCOUseVel | bhkUtilFunctions.obj | fnv360_0822_retail, call_gap, low
// pdb params: abUseVel, apObj
void SetFlagRecursive(bool abSet, WalkNode_cls* node)
{
    FlaggedObj_cls* f = node->m_1c;
    if (f != 0)
    {
        if (abSet)
        {
            f->m_0c |= 0x20;
        }
        else
        {
            f->m_0c &= 0xffdf;
        }
    }

    WalkNode_cls* child = node->v03();
    if (child != 0)
    {
        unsigned int i = 0;
        while (i < child->m_a6)
        {
            WalkNode_cls** arr = child->m_a0;
            WalkNode_cls* item = arr[i];
            if (item != 0)
            {
                SetFlagRecursive(abSet, item);
            }
            ++i;
        }
    }
}

class AnimIdle
{
  public:
    virtual void FUN_00c80570_slot0();
    virtual void FUN_00c80570_slot1();
    long refs;
    void IncRefCount();
    void DecRefCount();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct MM
{
    void Deallocate(void* mem);
};
extern MM _g_memoryManager;
struct GlobalObject_004ee810
{
    ~GlobalObject_004ee810();
};
struct FUN_00c80570_Node
{
    NiPointer<AnimIdle> key;
    FUN_00c80570_Node* next;
    void RemoveNode(const NiPointer<AnimIdle>* keyp);
};
// @fnv 0x00c80570
// pdb: BSSimpleList<NiPointer<BSTempEffect> >::Remove | BGSDecalNode.obj | fnv360_0822_retail, call_dedup, low
// pdb params: item
void FUN_00c80570_Node::RemoveNode(const NiPointer<AnimIdle>* apKey)
{
    AnimIdle* k = apKey->m_pObject;
    if (!k)
        return;
    FUN_00c80570_Node* nx = next;
    if (!nx && !key.m_pObject)
        return;
    FUN_00c80570_Node* cur = this;
    FUN_00c80570_Node* prev = this;
    do
    {
        if (cur->key.m_pObject == k)
            break;
        prev = cur;
        cur = cur->next;
    } while (cur);
    if (!cur)
        return;
    if (cur == this)
    {
        if (nx)
        {
            next = nx->next;
            key = nx->key;
            nx->next = 0;
            reinterpret_cast<GlobalObject_004ee810*>(nx)->~GlobalObject_004ee810();
            _g_memoryManager.Deallocate(nx);
            return;
        }
        AnimIdle* r = key.m_pObject;
        if (r)
        {
            if (InterlockedDecrement(&r->refs) == 0)
                r->FUN_00c80570_slot1();
            key.m_pObject = 0;
        }
        return;
    }
    prev->next = cur->next;
    cur->next = 0;
    reinterpret_cast<GlobalObject_004ee810*>(cur)->~GlobalObject_004ee810();
    _g_memoryManager.Deallocate(cur);
}

struct SpawnedAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct SpawnedPtrArray
{
    void** m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};

extern "C" void _ReadWriteBarrier(void);
SpawnedAllocHolder* FUN_00c85750();
void ResizeAudioStream(void* allocator, SpawnedPtrArray* arr, unsigned int growBy);

inline void* __cdecl operator new(unsigned int, void* placement)
{
    return placement;
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct NiAllocator
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern NiAllocator DAT_011f6238;
struct RefObject
{
    int unk00;
    volatile long referenceCount;
};
struct RefNode
{
    RefObject* item;
    RefNode* next;
    __forceinline RefNode(RefObject* p)
    {
        item = p;
        if (p)
            InterlockedIncrement(&p->referenceCount);
        next = 0;
    }
};
struct RefOwner
{
    RefObject* item;
    RefNode* head;
    void __thiscall FUN_006e5cc0(int* param);
    void __thiscall FUN_00c80a30(int* param);
};
// If *param is set, prepends a RefNode holding item to head (when item exists) and calls FUN_006e5cc0(param).
// @fnv 0x00c80a30
// pdb: BSSimpleList<NiPointer<ObstacleData> >::AddHead | NavMeshObstacleManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: item
void RefOwner::FUN_00c80a30(int* param)
{
    if (*param)
    {
        if (item)
        {
            void* memory = DAT_011f6238.FUN_00aa3e40(8);
            RefNode* node = memory ? new (memory) RefNode(item) : 0;
            node->next = head;
            head = node;
            FUN_006e5cc0(param);
            return;
        }
        FUN_006e5cc0(param);
    }
}

struct FUN_00c80b20_item8
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct FUN_00c80b20_cls
{
    virtual void Slot0();
    virtual void* AllocBuffer(unsigned int count);
    virtual void FreeBuffer(void* buffer);
    FUN_00c80b20_item8* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    unsigned int AppendSlot();
    void CopyItems(void* dst, void* src, unsigned int count);
    void InsertItemAt(unsigned int index, FUN_00c80b20_item8& item);
};

// Inserts an item at the given index, growing the buffer if full and shifting later items up by one slot.
// @fnv 0x00c80b20
// pdb: BSSimpleArray<bhkUtilFunctions::AVLevel,1024>::Insert | bhkUtilFunctions.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiIndex, aValue
void FUN_00c80b20_cls::InsertItemAt(unsigned int index, FUN_00c80b20_item8& item)
{
    if (index == m_uiLogicalSize)
    {
        unsigned int slot = AppendSlot();
        m_pBuffer[slot] = item;
        return;
    }
    if (m_uiLogicalSize == m_iReservedSize)
    {
        unsigned int newCap = m_iReservedSize > 0x400 ? m_iReservedSize + 0x400 : m_iReservedSize * 2;
        char* newBuf = (char*)AllocBuffer(newCap);
        CopyItems(newBuf, m_pBuffer, index);
        CopyItems(newBuf + index * 8 + 8, (char*)m_pBuffer + index * 8, m_uiLogicalSize - index);
        FreeBuffer(m_pBuffer);
        m_pBuffer = (FUN_00c80b20_item8*)newBuf;
        m_iReservedSize = newCap;
    }
    else
    {
        CopyItems((char*)m_pBuffer + index * 8 + 8, (char*)m_pBuffer + index * 8, m_uiLogicalSize - index);
    }
    m_uiLogicalSize++;
    m_pBuffer[index] = item;
}

// bhkWorld_GetRTTI : a one-line function - getter
extern int g_target_00c81570;
// @fnv 0x00c81570
// pdb: bhkWorld::GetRTTI | bhkWorld.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
void* bhkWorld_GetRTTI()
{
    return &g_target_00c81570;
}

struct FUN_00c81580_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1C;
    int unk20;
    int m_i24;
    void FUN_00c657f0(FUN_00c81580_cls* dest, void* other);
    void FUN_00c81580(FUN_00c81580_cls* dest, void* other);
};

// @fnv 0x00c81580
// pdb: bhkBlendCollisionObject::CopyMembers | bhkBlendCollisionObject.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: hkStiffSpringConstraintCinfo::SetPivotInA)
// pdb params: apDest, arCloneData
void FUN_00c81580_cls::FUN_00c81580(FUN_00c81580_cls* dest, void* other)
{
    this->FUN_00c657f0(dest, other);
    dest->m_f1C = m_f1C;
    dest->m_f18 = m_f18;
    dest->m_i24 = m_i24;
}

class C815B0Base
{
  public:
    bool IsEqual(C815B0Base* pkOther);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C815B0Constraint : public C815B0Base
{
  public:
    float m_fMinAngle;
    float m_fMaxAngle;

    bool FUN_00c815b0(C815B0Constraint* pkOther);
};

// Compares the base fields via C815B0Base::IsEqual, then checks that m_fMaxAngle and m_fMinAngle match the other constraint's values.
// @f3 0x008f3070 (community match, verified in this file)
// pdb: bhkBlendCollisionObject::IsEqual | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apObject
bool C815B0Constraint::FUN_00c815b0(C815B0Constraint* pkOther)
{
    bool bEqual = IsEqual(pkOther);
    if (bEqual)
    {
        bEqual = bEqual & (pkOther->m_fMaxAngle == m_fMaxAngle);
        bEqual = bEqual & (pkOther->m_fMinAngle == m_fMinAngle);
    }
    return bEqual;
}


extern int DAT_010c53dc;
extern int DAT_01267e60;

struct FUN_00c6b910_holder
{
    void FUN_00c6b910();
};

struct FUN_00c81600_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    float m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    FUN_00c81600_cls* Initialize();
};

// @fnv 0x00c81600
FUN_00c81600_cls* FUN_00c81600_cls::Initialize()
{
    reinterpret_cast<FUN_00c6b910_holder*>(this)->FUN_00c6b910();
    *(int**)this = &DAT_010c53dc;
    DAT_01267e60++;
    m_18 = 0.0f;
    m_1c = 1.0f;
    m_24 = 0;
    m_28 = 0;
    m_14 = 0;
    m_0c &= 0xfeff;
    m_20 = 8;
    return this;
}

struct C819A0Range
{
    float m_fMinimum;
    float m_fMaximum;
};

class C819A0Primary
{
  public:
    virtual ~C819A0Primary();

    int unk04;
    int unk08;
    int unk0C;
};

class C819A0Secondary
{
  public:
    virtual ~C819A0Secondary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiValue1;
};

class C819A0Object : public C819A0Primary, public C819A0Secondary
{
};

class C819A0Holder
{
  public:
    int unk00;
    int unk04;
    C819A0Object* m_pPointer;
};

class C819A0Base
{
  public:
    void Init(void* pvParam);

    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    short unk0E;
    C819A0Holder* m_pkHolder;
    int unk14;
};

class C819A0Derived : public C819A0Base
{
  public:
    void InitFromFlags(void* pvParam);

    float m_fMinimum;
    float m_fMaximum;
};

// @f3 0x008f3310 (community match, verified in this file)
extern C819A0Range DAT_00f79d30[];

// pdb: bhkBlendCollisionObject::LinkObject | bhkBlendCollisionObject.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: bhkStiffSpringConstraint::bhkStiffSpringConstraint)
// pdb params: arStream
void C819A0Derived::InitFromFlags(void* pvParam)
{
    Init(pvParam);
    m_usFlags |= 0x28;

    C819A0Secondary* pkSecondary = m_pkHolder && m_pkHolder->m_pPointer
        ? (C819A0Secondary*)m_pkHolder->m_pPointer : 0;
    unsigned int uiFlags = pkSecondary ? pkSecondary->m_uiValue1 : 0;
    unsigned int uiIndex = (uiFlags >> 8) & 0x1f;
    m_fMinimum = DAT_00f79d30[uiIndex].m_fMinimum;
    m_fMaximum = DAT_00f79d30[uiIndex].m_fMaximum;
}


class FUN_00c81aa0_poly
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
    virtual void v39(int a);
    int unk04;
    unsigned int m_08;
};

class FUN_00c81aa0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_00c81aa0_poly* m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    int m_24;
    void FUN_00c81aa0();
};

// Reads a masked type from m_10's m_08 chain and, if it is 8 or 0x1d and m_24 is nonzero, calls the poly's v39 with m_24.
// @fnv 0x00c81aa0
// pdb: bhkBlendCollisionObject::UpdateAddedToWorld | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun, medium
void FUN_00c81aa0_cls::FUN_00c81aa0()
{
    FUN_00c81aa0_poly* p = m_10;
    if (p != 0)
    {
        unsigned int t = p->m_08;
        if (t != 0)
        {
            t += 0x10;
            if (t != 0)
            {
                t = *(unsigned int*)(t + 0x1c);
            }
            else
            {
                t = 0;
            }
        }
        else
        {
            t = 0;
        }
        t &= 0x7f;
        if (t == 8 || t == 0x1d)
        {
            if (m_24 != 0)
            {
                p->v39(m_24);
            }
        }
    }
}

struct FUN_00c81ae0_target
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
    virtual void v39(void* arg);
};

struct FUN_00c81ae0_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FUN_00c81ae0_target* m_10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* m_24;
    unsigned int m_28;

    void FUN_00c81890();
    void InitOnce();
};

// @fnv 0x00c81ae0
// pdb: bhkBlendCollisionObject::IncForceAdd | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun, medium
void FUN_00c81ae0_cls::InitOnce()
{
    bool first = m_28 == 0;
    m_28++;
    if (first)
    {
        FUN_00c81890();
        FUN_00c81ae0_target* obj = m_10;
        if (obj != 0)
        {
            unsigned int p = *(unsigned int*)((char*)obj + 8);
            unsigned int flags;
            if (p != 0)
            {
                p += 0x10;
                if (p != 0)
                {
                    flags = *(unsigned int*)(p + 0x1c);
                }
                else
                {
                    flags = 0;
                }
            }
            else
            {
                flags = 0;
            }
            flags &= 0x7f;
            if (flags == 8 || flags == 0x1d)
            {
                void* arg = m_24;
                if (arg != 0)
                {
                    obj->v39(arg);
                }
            }
        }
    }
}

extern unsigned int DAT_012043f8;

extern unsigned __int64 selected_target_masks[];

// Sets or clears the symmetric bits for uiA and uiB in selected_target_masks according to bSelected.
// @fnv 0x00c827f0
// pdb: bhkCollisionFilter::SetLayerCollision | bhkCollisionFilter.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aeA, aeB, abSet
void SetSelectionMask(unsigned int uiIndexA, unsigned int uiIndexB, bool bSelected)
{
    if (bSelected)
    {
        selected_target_masks[uiIndexA] |= (unsigned __int64)1 << uiIndexB;
        selected_target_masks[uiIndexB] |= (unsigned __int64)1 << uiIndexA;
    }
    else
    {
        selected_target_masks[uiIndexA] &= ~((unsigned __int64)1 << uiIndexB);
        selected_target_masks[uiIndexB] &= ~((unsigned __int64)1 << uiIndexA);
    }
}

struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    NiColor(float fR, float fG, float fB) : r(fR), g(fG), b(fB)
    {}
};

// Writes the NiColor associated with the low 7 bits of layer into out, falling back to DAT_011a9b7c for unknown layers.
// @f3 0x008f6020 (community match, verified in this file)
extern NiColor DAT_00f731bc;
// pdb: bhkCollisionFilter::GetDebugColor | bhkCollisionFilter.obj | fnv360_0822_retail, uconst, low
// pdb params: aiFilter, arColor
void __cdecl GetLayerColor(unsigned int layer, NiColor& rColor)
{
    switch (layer & 0x7f)
    {
    case 1:
        rColor = NiColor(1.0f, 0.0f, 0.0f);
        break;
    case 2:
    case 10:
        rColor = NiColor(0.9f, 0.24f, 0.92f);
        break;
    case 3:
        rColor = NiColor(0.96f, 0.8f, 0.8f);
        break;
    case 4:
        rColor = NiColor(0.27f, 0.41f, 0.94f);
        break;
    case 5:
        rColor = NiColor(0.85f, 0.61f, 0.16f);
        break;
    case 6:
        rColor = NiColor(0.9f, 0.73f, 0.42f);
        break;
    case 7:
        rColor = NiColor(0.23f, 0.97f, 0.9f);
        break;
    case 8:
        rColor = NiColor(0.0f, 1.0f, 0.0f);
        break;
    case 9:
        rColor = NiColor(0.8f, 0.62f, 0.45f);
        break;
    case 11:
        rColor = NiColor(0.51f, 0.98f, 0.98f);
        break;
    case 12:
    case 14:
        rColor = NiColor(0.73f, 0.76f, 0.75f);
        break;
    case 16:
        rColor = NiColor(0.73f, 0.78f, 0.7f);
        break;
    case 13:
    case 17:
        rColor = NiColor(0.96f, 0.97f, 0.52f);
        break;
    case 18:
        rColor = NiColor(0.0f, 0.7f, 0.0f);
        break;
    case 30:
        rColor = NiColor(1.0f, 1.0f, 0.0f);
        break;
    case 31:
        rColor = NiColor(1.0f, 0.8f, 0.0f);
        break;
    case 24:
        rColor = NiColor(0.45f, 0.6f, 0.1f);
        break;
    default:
        rColor = DAT_00f731bc;
        break;
    }
}


struct ObjA
{
    unsigned char m_flag;
    unsigned char unk01[0x1b];
    void* m_p1c;
};
extern "C" unsigned char __cdecl FUN_00c84740(void* pA, void* pB);
// Calls FUN_00c84740 with the m_p1c pointers of p2 and p3, stores the returned byte in p1->m_flag and returns p1.
// @fnv 0x00c84880
// pdb: bhkCollisionFilter::isCollisionEnabled | bhkCollisionFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: arColA, arColB
ObjA* __stdcall FUN_00c84880(ObjA* p1, ObjA* p2, ObjA* p3)
{
    void* pB = p2->m_p1c;
    void* pA = p3->m_p1c;
    unsigned char result = FUN_00c84740(pB, pA);
    p1->m_flag = result;
    return p1;
}

struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

unsigned char __cdecl FUN_00c84740(int a1, int a2);

// @fnv 0x00c848b0
// pdb: bhkCollisionFilter::isCollisionEnabled | bhkCollisionFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInput, arBodyA, arBodyB, arCollection, aKey
unsigned char* __stdcall FUN_00c848b0(unsigned char* pResult, int a2, ChainNode* pChainA, ChainNode* pChainB, int a5,
                                      int a6)
{
    ChainNode* p = pChainB;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    int tailB = ((volatile ChainNode*)p)->m_1c;

    ChainNode* q = pChainA;
    while (q->m_0c != 0)
    {
        q = q->m_0c;
    }
    int tailA = q->m_1c;
    *pResult = FUN_00c84740(tailA, tailB);
    return pResult;
}

// FUN_00c84930: stdcall 3-arg wrapper.
//   a2->m_24 and a3->m_1c are passed to the cdecl helper FUN_00c84740,
//   the resulting byte is written through the first (out) parameter, which is returned.
unsigned char __cdecl FUN_00c84740(int a1, int a2);

struct NodeA
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
};

struct NodeB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

// @fnv 0x00c84930
// pdb: bhkCollisionFilter::isCollisionEnabled | bhkCollisionFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInput, arCollidableB
unsigned char* __stdcall FUN_00c84930(unsigned char* pResult, NodeA* pNodeA, NodeB* pNodeB)
{
    int v1 = pNodeB->m_1c;
    int v2 = pNodeA->m_24;
    *pResult = FUN_00c84740(v2, v1);
    return pResult;
}

namespace fnv_00c84960 {
struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

unsigned char __cdecl FUN_00c84740(int a1, int a2);

// @fnv 0x00c84960
// pdb: bhkCollisionFilter::isCollisionEnabled | bhkCollisionFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: input, collectionBodyA, collectionBodyB, containerShapeA, containerShapeB, keyA, keyB
unsigned char* __stdcall FUN_00c84960(unsigned char* pResult, int aiUnused, ChainNode* pChainA, ChainNode* pChainB,
                                      int a5, int a6, int a7, int a8)
{
    ChainNode* q = pChainA;
    while (q->m_0c != 0)
    {
        q = q->m_0c;
    }
    int tailA = q->m_1c;

    ChainNode* p = pChainB;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    int tailB = p->m_1c;

    *pResult = FUN_00c84740(tailA, tailB);
    return pResult;
}
}  // namespace fnv_00c84960

struct FUN_00c84dc0_param
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00c84dc0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool FUN_00ba87d0(FUN_00c84dc0_param* p);
    bool FUN_00c84dc0(FUN_00c84dc0_param* p);
};

// Calls FUN_00ba87d0 on p and, if true, checks that the low 5 bits of p->m_10 XOR this->m_10 are zero.
// @fnv 0x00c84dc0
bool FUN_00c84dc0_cls::FUN_00c84dc0(FUN_00c84dc0_param* pParam)
{
    bool b = this->FUN_00ba87d0(pParam);
    if (b)
    {
        unsigned int x = pParam->m_10 ^ this->m_10;
        b = (x & 0x1f) == 0;
    }
    return b;
}

class FUN_00c84df0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_10;

    void bhkSerializable_CopyMembers(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
    void bhkShape_CopyMembers(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
};

// Calls bhkSerializable_CopyMembers with first and second, then copies the low 5 bits of m_10 into first->m_10.
// @fnv 0x00c84df0
// pdb: bhkShape::CopyMembers | bhkShape.obj | fnv360_0822_retail, caller_sim + bridge(hash|vtable) + skyrim(caller_sim), high
void FUN_00c84df0_cls::bhkShape_CopyMembers(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second)
{
    bhkSerializable_CopyMembers(first, second);
    first->m_10 = m_10 & 0x1f;
}

struct FUN_00c84e80_holder
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    int __thiscall ApplyToNext(int* arg_2);
};

extern void __cdecl FUN_00cf0690(void* object, float value, int* data);

// If this and m_next are non-null, passes m_next, the float at arg_2[1] and arg_2 to FUN_00cf0690; otherwise returns 1.
// @fnv 0x00c84e80
// pdb: bhkShape::CalcMass | bhkShape.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: bhkShape::GetMaterialName)
// pdb params: arProp
int FUN_00c84e80_holder::ApplyToNext(int* pData)
{
    int result = 0;

    if (this != 0 && m_next != 0)
    {
        float value = reinterpret_cast<float*>(pData)[1];
        FUN_00cf0690(m_next, value, pData);
    }
    else
    {
        result = 1;
    }

    return result;
}

// Target class of the first virtual call
class TargetCls
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual int v56(int a);
};

class FUN_00c84f10_cls
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
    virtual TargetCls* v51();
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int FUN_00c84f10(int a);
};

// If a is not -1 and v51() returns an object, forwards a to its v56; otherwise returns m_i10 masked to 0x1f.
// @f3 0x008f76a0 (community match, verified in this file)
struct TargetStub
{
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual void t09();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual void t45();
    virtual void t46();
    virtual void t47();
    virtual void t48();
    virtual void t49();
    virtual void t50();
    virtual void t51();
    virtual void t52();
    virtual void t53();
    virtual void t54();
    virtual int t55(int a);
};

struct OwnerStub
{
    virtual void u00();
    virtual void u01();
    virtual void u02();
    virtual void u03();
    virtual void u04();
    virtual void u05();
    virtual void u06();
    virtual void u07();
    virtual void u08();
    virtual void u09();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual TargetStub* u50();
};

// pdb: bhkShape::GetSubshapeMaterial | bhkShape.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiKey
int FUN_00c84f10_cls::FUN_00c84f10(int a)
{
    if (a != -1)
    {
        TargetStub* pTarget = ((OwnerStub*)this)->u50();
        if (pTarget)
            return pTarget->t55(a);
    }
    return m_i10 & 0x1f;
}


struct NiStream;

struct BaseThunk
{
    bool FUN_00a81fe0(NiStream& stream);
};

struct C_t
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
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(NiStream* a);
};

struct B_t
{
    int unk00;
    int unk04;
    C_t* unk08;
};

struct A_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    B_t* unk10;
};

struct FUN_00c85ac0_cls : BaseThunk
{
    int unk00;
    int unk04;
    A_t* unk08;

    void FUN_00c85ac0(NiStream* a);
};

// Walks this->unk08 to a nested object and calls its v15 with the stream, then calls FUN_00a81fe0 on the stream.
// @fnv 0x00c85ac0
// pdb: bhkWorldObject::RegisterStreamables | bhkWorldObject.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arStream
void FUN_00c85ac0_cls::FUN_00c85ac0(NiStream* pStream)
{
    if (this)
    {
        A_t* pa = this->unk08;
        if (pa)
        {
            B_t** ppb = &pa->unk10;
            if (ppb)
            {
                B_t* pb = *ppb;
                if (pb)
                {
                    C_t* pc = pb->unk08;
                    if (pc)
                        pc->v15(pStream);
                }
            }
        }
    }
    this->FUN_00a81fe0(*pStream);
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

class RefLeaf_t
{
  public:
    virtual void unk00();
    virtual void unk04();
    unsigned int m_04;
};

struct Inner_t;

struct Inner_t
{
    int unk00;
    int unk04;
    RefLeaf_t* m_08;
};

class BC85BA0Target
{
  public:
    int unk00;
    long m_lRefCount;
};

class BC85BA0Link
{
  public:
    int unk00;
    int unk04;
    BC85BA0Target* m_pkTarget;
};

class BC85BA0Holder
{
  public:
    BC85BA0Link* m_pkLink;
};

class BC85BA0HkObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_pvUserData;
    BC85BA0Holder m_kHolder;
};

class BC85BA0RefObject
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
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void RegisterWithWorld();
    void UpdateReference(bool bAdd);
};

class BC85BA0WorldObject : public BC85BA0RefObject
{
  public:
    void FUN_00c85b00();
    void SetHkObjectUserData(bool bAdd);

    int unk04;
    BC85BA0HkObject* m_pkHkObject;
};

// @f3 0x008f9a90 (community match, verified in this file)
// pdb: bhkWorldObject::Link | bhkWorldObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: abAttach
void BC85BA0WorldObject::SetHkObjectUserData(bool bAdd)
{
    void* pvUserData;
    if (bAdd)
    {
        if (this)
        {
            BC85BA0Target* pkTarget = 0;
            if (m_pkHkObject)
            {
                BC85BA0Holder* pkHolder = &m_pkHkObject->m_kHolder;
                if (pkHolder && pkHolder->m_pkLink)
                    pkTarget = pkHolder->m_pkLink->m_pkTarget;
            }
            if (pkTarget)
                InterlockedIncrement(&pkTarget->m_lRefCount);
        }
        pvUserData = this;
    }
    else
    {
        RegisterWithWorld();
        BC85BA0Target* pkTarget = 0;
        if (m_pkHkObject)
        {
            BC85BA0Holder* pkHolder = &m_pkHkObject->m_kHolder;
            if (pkHolder && pkHolder->m_pkLink)
                pkTarget = pkHolder->m_pkLink->m_pkTarget;
        }
        if (pkTarget)
        {
            if (InterlockedDecrement(&pkTarget->m_lRefCount) == 0)
                (*(void(__thiscall**)(void*))(*(void***)pkTarget + 1))(pkTarget);
        }
        pvUserData = 0;
    }
    if (this && m_pkHkObject)
        m_pkHkObject->m_pvUserData = pvUserData;
    UpdateReference(bAdd);
}


struct FUN_00c87600_Base
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
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
};

struct FUN_00c87600_Arg : FUN_00c87600_Base
{
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
};

struct FUN_00c87600_Obj : FUN_00c87600_Base
{
    virtual void vfA4(int value);
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
    virtual void* vfB4(void* value);

    void __thiscall bhkSerializable_CopyMembers(void* arg1, void* arg2);
};

struct FUN_00a5d450_helper
{
    void __thiscall CreateVertexBufferSet(void* arg1, void* arg2);
};

// Calls the base helper with arg1 and arg2, passes the result of vfB4 to arg1's vfB0, then calls vfA4 with 1.
// @fnv 0x00c87600
// pdb: bhkSerializable::CopyMembers | bhkSerializable.obj | fnv360_0721_beta, call_seq + bridge(hash|call_seq) + skyrim(caller_sim), high
void __thiscall FUN_00c87600_Obj::bhkSerializable_CopyMembers(void* pTarget, void* arg2)
{
    reinterpret_cast<FUN_00a5d450_helper*>(this)->CreateVertexBufferSet(pTarget, arg2);

    void* result = this->vfB4(&arg2);
    reinterpret_cast<FUN_00c87600_Arg*>(pTarget)->vfB0(result);

    this->vfA4(1);
}

// bhkSerializable_PostInit: thiscall, 18 bytes. Self virtual call at slot 0xa4 (index 41) tail-jumped with constant 1 in the stack arg.
struct FUN_00c876d0_cls
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
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void Tail(int a);
    void bhkSerializable_PostInit(int a);
};

// @fnv 0x00c876d0
// pdb: bhkSerializable::PostInit | bhkSerializable.obj | fnv360_0822_retail, vtable, high
// pdb params: __formal
// pdb: bhkSerializable::PostInit | bhkSerializable.obj | fnv360_0822_retail, vtable, high (was: TailOne)
void FUN_00c876d0_cls::bhkSerializable_PostInit(int a)
{
    this->Tail(1);
}

class C87710BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(C87710BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

class C87710Stream
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
    C87710BinaryStream* m_pUnderlyingStream;
};

class C87710HavokObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual unsigned int GetDataSize();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void* GetData(bool& bIsValid);

    unsigned int FUN_00c87710(C87710Stream& kStream);
};

// Reads the object's data block of GetDataSize() bytes from the stream into the buffer returned by GetData and returns that size.
// @f3 0x008f7f40 (community match, verified in this file)
// pdb: bhkSerializable::LoadCInfo | bhkSerializable.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
unsigned int C87710HavokObject::FUN_00c87710(C87710Stream& kStream)
{
    bool bIsValid;
    void* pvData = GetData(bIsValid);
    unsigned int uiSize = 0;
    if (pvData)
    {
        uiSize = GetDataSize();
        kStream.m_pUnderlyingStream->BinaryRead(pvData, uiSize, 0, 0);
    }
    return uiSize;
}


class BC87850BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC87850BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BC87850BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

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

class BC87850Stream
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
    BC87850BinaryStream* m_pUnderlyingStream;
    BC87850BinaryStream* m_pBackingStream;
};

template <class T>
inline void BC87850BinaryStreamSave(BC87850BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BC87850SaveBinary(BC87850Stream& kStream, const T& value)
{
    BC87850BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BC87850RefObject
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
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void FreeSerializeData(int iHandle);
    virtual unsigned int GetSerializeSize();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual char* GetSerializeData(int* piHandle);

    void BaseSaveBinary(BC87850Stream& kStream);
    void bhkSerializable_SaveBinary(BC87850Stream& kStream);
};

// Gets the serialize data buffer and handle, saves the base binary, writes the buffer to the stream, then frees the serialize data.
// @f3 0x008f8060 (community match, verified in this file)
// pdb: bhkSerializable::SaveBinary | bhkSerializable.obj | fnv360_0822_retail, call_seq, high
// pdb params: arStream
// pdb: bhkSerializable::SaveBinary | bhkSerializable.obj | fnv360_0822_retail, call_seq, high (was: SaveSerializeData)
void BC87850RefObject::bhkSerializable_SaveBinary(BC87850Stream& kStream)
{
    int iHandle;
    char* pSerializeData = GetSerializeData(&iHandle);
    BaseSaveBinary(kStream);
    if (pSerializeData)
    {
        BC87850BinaryStreamSave(*kStream.m_pBackingStream, pSerializeData, GetSerializeSize());
        FreeSerializeData(iHandle);
    }
}


struct NiObjectData
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    unsigned int m_uiFilterValue;
};

struct FUN_00c879e0_Class
{
    void* m_p0;
    void* m_p4;
    NiObjectData* m_p8;

    void __thiscall FUN_00c879e0(unsigned int* result);
};

// @fnv 0x00c879e0
// pdb: bhkUnaryAction::CopyCinfo | bhkUnaryAction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
void __thiscall FUN_00c879e0_Class::FUN_00c879e0(unsigned int* result)
{
    *result = (this != 0 && m_p8 != 0) ? m_p8->m_uiFilterValue : 0u;
}

struct C87A10HavokObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_ulUserData;
};

class C87A10RefObject
{
  public:
    int unk00;
    int unk04;
    C87A10HavokObject* m_pPointer;

    void UpdateReference(bool bAdd);
};

class C87A10WorldObject : public C87A10RefObject
{
  public:
    void FUN_00c87a10(bool bAdd);
};

// @fnv 0x00c87a10
// pdb: bhkAction::Link | bhkAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: abAttach
void C87A10WorldObject::FUN_00c87a10(bool bAdd)
{
    if (this && m_pPointer)
        m_pPointer->m_ulUserData = bAdd ? this : 0;
    UpdateReference(bAdd);
}

extern int DAT_0126817c;

// @fnv 0x00c88370
// pdb: bhkCachingShapePhantom::GetRTTI | bhkCharacterController.obj | fnv360_0721_beta, objrun, medium
void* __cdecl FUN_00c88370()
{
    return &DAT_0126817c;
}

// Constructor of a two-level Havok wrapper: attach the given Havok object (through its referenced-object base).

extern int g_iC88380RefObjectCount;
extern int g_iC88380WrapperCount;

class C88380ReferencedObject
{
  public:
    int m_iMemSizeAndFlags;
};

class C88380HavokBase
{
  public:
    virtual ~C88380HavokBase();
};

class C88380HavokObject : public C88380HavokBase, public C88380ReferencedObject
{
};

class C88380Root
{
  public:
    C88380Root();
    virtual ~C88380Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class C88380Holder : public C88380Root
{
  public:
    C88380Holder() : m_pkHavokObject(0)
    {}
    virtual ~C88380Holder();
    void* m_pkHavokObject;
};

class C88380RefObject : public C88380Holder
{
  public:
    C88380RefObject()
    {
        ++g_iC88380RefObjectCount;
    }
    virtual ~C88380RefObject();
    void SetReferencedObject(C88380ReferencedObject* pkObject);
};

class FUN_00c88380 : public C88380RefObject
{
  public:
    FUN_00c88380(C88380HavokObject* pkObject);
    virtual ~FUN_00c88380();
};

// Constructs a wrapper that stores the given Havok object via SetReferencedObject and increments the wrapper count.
// @fnv 0x00c88380
// pdb: bhkStiffSpringConstraint::bhkStiffSpringConstraint | bhkUtilFunctions.obj | fnv360_0822_retail, call_gap, low
// pdb params: arInfo
FUN_00c88380::FUN_00c88380(C88380HavokObject* pkObject)
{
    SetReferencedObject(pkObject);
    ++g_iC88380WrapperCount;
}

extern int DAT_0126831c;

// @fnv 0x00c88400
int* __cdecl FUN_00c88400()
{
    return &DAT_0126831c;
}

struct FNVTransformState
{
    int component00, component04, component08, component0c;
    int component10, component14, component18, component1c;
    int component20, component24, component28, component2c;
    int component30;
};

struct FNVTraversalNode
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14;
    FNVTraversalNode* parent;
    int unknown1c, unknown20, unknown24;
    int unknown28, unknown2c, unknown30;
    FNVTransformState state;
};

struct FNVTraversalOutput : FNVTransformState
{
    void FUN_00a86bf0();
    FNVTransformState FUN_0062c250(FNVTransformState* state);
};

// Walks up the parent chain from node to stop, applying each node's state to output and finalizing when stop is reached.
// @fnv 0x00c884c0
// pdb: GetTransformRecursive | WeaponObject.obj | fnv360_0822_retail, caller_sim, high
// pdb params: apObject, apRoot, aWorldTransform
// pdb: GetTransformRecursive | WeaponObject.obj | fnv360_0822_retail, caller_sim, high (was: AccumulateParentTransforms)
void __cdecl GetTransformRecursive(FNVTraversalNode* node, FNVTraversalNode* stop, FNVTraversalOutput* output)
{
    if (node == 0)
        return;
    if (node == stop)
    {
        output->FUN_00a86bf0();
        return;
    }
    GetTransformRecursive(node->parent, stop, output);
    static_cast<FNVTransformState&>(*output) = output->FUN_0062c250(&node->state);
}

struct ThreadTlsBlock
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
extern __declspec(thread) ThreadTlsBlock g_tls;

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

class TlsCallTarget
{
  public:
    unsigned int Lookup(int* p);
    void Apply(unsigned int v);
};

class FUN_00c886c0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    TlsCallTarget* m_08;
    void CallTargetWithArgs();
};

// Creates a TLS flag guard, then if m_08 is set calls CallWithArgs(t,1,1), looks up DAT_012681f0 and applies the result if nonzero.
// @f3 0x008fa3f0 (community match, verified in this file)
extern int DAT_010f32f8;
void __cdecl FUN_00e34374();

struct SelfOrig
{
    unsigned int m_00;
    unsigned int m_04;
    TlsCallTarget* m_08;
    void FUN_008f3010();
};
struct OrigGuard
{
    SelfOrig* m_p;
    OrigGuard(SelfOrig* p) : m_p(p) { p->m_00 = (unsigned int)&FUN_00e34374; }
    ~OrigGuard() { m_p->FUN_008f3010(); }
};
struct TlsTargetOrig
{
    unsigned int FUN_00825200(int* p);
    void FUN_00825110(unsigned int v);
};
void __cdecl FUN_008d7720(void* t, int a, int b);

// pdb: WeaponObject::~WeaponObject | WeaponObject.obj | fnv360_0822_retail, caller_sim, low
void FUN_00c886c0_cls::CallTargetWithArgs()
{
    SelfOrig* self = (SelfOrig*)this;
    OrigGuard guard(self);
    TlsTargetOrig* t = (TlsTargetOrig*)self->m_08;
    if (t != 0)
    {
        FUN_008d7720(t, 1, 1);
        unsigned int r = t->FUN_00825200(&DAT_010f32f8);
        if (r != 0)
        {
            t->FUN_00825110(r);
        }
    }
}


class C88930Base
{
  public:
    virtual ~C88930Base();
};

class FUN_00c88930 : public C88930Base
{
  public:
    void Release();

    virtual ~FUN_00c88930();
};

// @fnv 0x00c88930
// pdb: LoadedReferenceMap::~LoadedReferenceMap | BGSLoadedReferenceCollection.obj | fnv360_0822_debug, call_seq, medium
FUN_00c88930::~FUN_00c88930()
{
    Release();
}

class SpawnedBase_b7559
{
  public:
    virtual void unk00();
    int m_04;

    SpawnedBase_b7559();
    ~SpawnedBase_b7559();
};

class FUN_00c894d0 : public SpawnedBase_b7559
{
  public:
    FUN_00c894d0(int a, int b, int c, int d, int e);
    virtual void unk00();
    void Init_b7559(int a, int b, int c, int d, int e);
};

// Constructs the object by forwarding all five arguments to Init_b7559.
// @fnv 0x00c894d0
// pdb: WeaponObject::WeaponObject | WeaponObject.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aOwnerFilter, apOwner3d, apObject, apReplaceObject, abDefaultKeyframed
FUN_00c894d0::FUN_00c894d0(int a, int b, int c, int d, int e)
{
    Init_b7559(a, b, c, d, e);
}

namespace fnv_00c89540 {
extern __declspec(thread) unsigned int g_tlsMemoryMode;
int __cdecl FUN_00c802d0(int);
void* __cdecl FUN_00aa13e0(unsigned int);
struct FUN_00c894d0
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
    FUN_00c894d0(int, int, int, int, int);
    static void* operator new(unsigned int count)
    {
        return FUN_00aa13e0(count);
    }
};
struct ScopedMemoryMode
{
    unsigned int previousMode;
    explicit ScopedMemoryMode(unsigned int mode) : previousMode(g_tlsMemoryMode)
    {
        g_tlsMemoryMode = mode;
    }
    ~ScopedMemoryMode()
    {
        g_tlsMemoryMode = previousMode;
    }
};
}  // namespace fnv_00c89540

extern int DAT_01268188;

class PolyBase
{
  public:
    virtual ~PolyBase();
};

class FUN_00c89640_cls : public PolyBase
{
  public:
    virtual ~FUN_00c89640_cls();
    void FUN_00c876a0();
};

// @fnv 0x00c89640
// pdb: bhkConstraint::~bhkConstraint | bhkConstraint.obj | fnv360_0822_retail, call_seq, high
FUN_00c89640_cls::~FUN_00c89640_cls()
{
    FUN_00c876a0();
    --DAT_01268188;
}

struct S_00c89810_ResultInner
{
    void* unk0;
    void* unk4;
    int unk8;
};

struct S_00c89810_Result
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2(int value)
    {}

    S_00c89810_ResultInner* m_p4;
};

struct S_00c89810_Owner
{
    virtual void d00()
    {}
    virtual void d01()
    {}
    virtual void d02()
    {}
    virtual void d03()
    {}
    virtual void d04()
    {}
    virtual void d05()
    {}
    virtual void d06()
    {}
    virtual void d07()
    {}
    virtual void d08()
    {}
    virtual void d09()
    {}
    virtual void d0a()
    {}
    virtual void d0b()
    {}
    virtual void d0c()
    {}
    virtual void d0d()
    {}
    virtual void d0e()
    {}
    virtual void d0f()
    {}
    virtual void d10()
    {}
    virtual void d11()
    {}
    virtual void d12()
    {}
    virtual void d13()
    {}
    virtual void d14()
    {}
    virtual void d15()
    {}
    virtual void d16()
    {}
    virtual void d17()
    {}
    virtual void d18()
    {}
    virtual void d19()
    {}
    virtual void d1a()
    {}
    virtual void d1b()
    {}
    virtual void d1c()
    {}
    virtual void d1d()
    {}
    virtual void d1e()
    {}
    virtual void d1f()
    {}
    virtual void d20()
    {}
    virtual void d21()
    {}
    virtual void d22()
    {}
    virtual void d23()
    {}
    virtual void d24()
    {}
    virtual void d25()
    {}
    virtual void d26()
    {}
    virtual void d27()
    {}
    virtual void d28()
    {}
    virtual void d29()
    {}

    virtual void mA8()
    {}
    virtual void mA9()
    {}
    virtual void mAA()
    {}
    virtual void* mB4(char* value)
    {
        return 0;
    }

    void SetValueAndReset(int value);
};

// Calls mB4 to obtain a result object, invokes its v2 with value, clears m_p4->unk8, then calls mA8.
// @f3 0x008fbe10 (community match, verified in this file)
struct S_00c89810_ResultF3
{
    virtual void v0();
    virtual void v1();
    virtual void SetValue(int value);
    virtual void v3();
    virtual void SetValueEx(int value, int flags);
    S_00c89810_ResultInner* m_p4;
};
// pdb: bhkConstraint::LinkObject | bhkConstraint.obj | fnv360_0822_debug, objrun, low
// pdb params: arStream
void S_00c89810_Owner::SetValueAndReset(int value)
{
    char local;

    void* returned = this->mB4(&local);
    S_00c89810_ResultF3* result = returned ? (S_00c89810_ResultF3*)((char*)returned - 4) : 0;

    if (((unsigned int*)value)[1] < 0x11)
        result->SetValueEx(value, 0);
    else
        result->SetValue(value);
    result->m_p4->unk8 = 0;

    this->mA8();
}


struct FUN_00c898e0_Inner
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
    virtual void Slot21(int a);
};

struct FUN_00c898e0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c898e0_Inner* m_0c;
};

struct FUN_00c898e0_Holder
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
    virtual void v50();
    virtual void v51();
    virtual FUN_00c898e0_Sub* GetSub();
    void DispatchToInnerSlot(int arg);
    void FUN_00a81fe0(int a);
};

// Gets the sub-object, forwards arg to its inner object's Slot21 if present, then calls FUN_00a81fe0(arg).
// @f3 0x008fbef0 (community match, verified in this file)
struct FUN_00c898e0_Sub;
struct FUN_00c898e0_Inner;
struct FUN_008fbef0_Stand
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
    virtual void v50();
    virtual FUN_00c898e0_Sub* GetSub();
    void FUN_008c1240(int a);
};
// pdb: bhkConstraint::RegisterStreamables | bhkConstraint.obj | fnv360_0822_retail, objrun, low
// pdb params: arStream
void FUN_00c898e0_Holder::DispatchToInnerSlot(int arg)
{
    FUN_008fbef0_Stand* self = reinterpret_cast<FUN_008fbef0_Stand*>(this);
    FUN_00c898e0_Sub* sub = self->GetSub();
    if (sub != 0)
    {
        FUN_00c898e0_Inner* p = sub->m_0c;
        if (p != 0)
        {
            p->Slot21(arg);
        }
    }
    self->FUN_008c1240(arg);
}


struct RefTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03(int a)
    {}
};

struct FUN_00c89920_cls
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
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual unsigned char* GetRef(unsigned char* flag);
    void InvokeRefTarget(int a);
};

// Gets a reference via GetRef, adjusts it to the RefTarget base, and calls its v03 with a.
// @fnv 0x00c89920
// pdb: bhkConstraint::SaveBinary | bhkConstraint.obj | fnv360_0822_retail, objrun, medium
// pdb params: arStream
void FUN_00c89920_cls::InvokeRefTarget(int a)
{
    unsigned char flag;
    unsigned char* r = GetRef(&flag);
    RefTarget* p = (r != 0) ? (RefTarget*)(r - 4) : (RefTarget*)0;
    p->v03(a);
}

struct FUN_00c89960_cls
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
    virtual void v41(int flag);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void* v45(unsigned int* p);
    void __thiscall FUN_00c878c0(unsigned int a);
    void FUN_00c89960(unsigned int a1);
};

// Calls FUN_00c878c0 with a1, resolves an inner object via v45, calls its v5 with a1, then v41(1).
// @f3 0x008fbf70 (community match, verified in this file)
struct Stub_8f80d0
{
    void FUN_008f80d0(void* stream);
};
struct InnerStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void* stream);
};

// pdb: bhkConstraint::GetViewerStrings | bhkConstraint.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void FUN_00c89960_cls::FUN_00c89960(unsigned int a1)
{
    unsigned int uiStream = *(volatile unsigned int*)&a1;
    ((Stub_8f80d0*)this)->FUN_008f80d0((void*)uiStream);

    void* pThing = v45(&a1);
    if (pThing)
    {
        InnerStub* pInner = (InnerStub*)((char*)pThing - 4);
        if (pInner)
        {
            pInner->v6((void*)uiStream);
            v41(1);
        }
    }
}


struct S_00c89a30_Obj;
struct S_00c89a30_Owner;
struct S_00c89a30_Obj
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
    virtual int v37();
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
    virtual void v53(S_00c89a30_Obj* o, int f);
    int unk04;
    S_00c89a30_Owner* unk08;
    void FUN_00c6b320(S_00c89a30_Owner* owner);
    bool FUN_00c89a30(S_00c89a30_Obj* other);
};
// @f3 0x008fc120 (community match, verified in this file)
struct S_00c89a30_ObjF3
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual int getKind();
    virtual void s39();
    virtual void detach();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void attachTo(S_00c89a30_Obj* o, int f);
};
struct S_00c89a30_LinkF3
{
    void FUN_008d8a30(S_00c89a30_Owner* owner);
};
// pdb: bhkConstraint::Add | bhkConstraint.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apWorld
bool S_00c89a30_Obj::FUN_00c89a30(S_00c89a30_Obj* other)
{
    S_00c89a30_Owner* owner = this ? unk08 : 0;
    bool r = false;
    if (owner)
    {
        S_00c89a30_ObjF3* self = (S_00c89a30_ObjF3*)this;
        if (other)
        {
            int a = self->getKind();
            int b = ((S_00c89a30_ObjF3*)other)->getKind();
            if (a != b)
            {
                self->detach();
                self->attachTo(other, 1);
                ((S_00c89a30_LinkF3*)other)->FUN_008d8a30(owner);
                r = true;
            }
        }
        else
        {
            self->detach();
        }
    }
    return r;
}


namespace fnv_00c89d10 {
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

extern __declspec(thread) TlsBlock_t g_tlsBlock;

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

struct FUN_00c89d10_P;
class VObjA
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Notify(FUN_00c89d10_P* p);
};

struct FUN_00c89d10_R
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
    int unk90;
    int m_94;
};

struct FUN_00c89d10_Q
{
    int unk00;
    int unk04;
    FUN_00c89d10_R* m_08;
};

struct FUN_00c89d10_P
{
    int unk00;
    int unk04;
    class VObjA* m_08;
    int unk0C;
    int unk10;
    FUN_00c89d10_Q* m_14;
};

}  // namespace fnv_00c89d10

extern __declspec(thread) int DAT_tls_field;
struct TlsGuard
{
    int old;
    TlsGuard() : old(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~TlsGuard()
    {
        DAT_tls_field = old;
    }
};

struct S_00c8a280_Child
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct S_00c8a280_Bin
{
    void* __vf;
    unsigned int m_uiPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(S_00c8a280_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
};
inline void S_00c8a280_Save(S_00c8a280_Bin* b, const void* buf, unsigned int bytes)
{
    unsigned int comp = bytes;
    unsigned int n = b->m_pfnWrite(b, buf, bytes, &comp, 1);
    b->m_uiPos += n;
}
struct S_00c8a280_Stream
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
    virtual void v12(int a);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk1E4;
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
    unsigned int unk24C;
    S_00c8a280_Bin* m_pBackingStream;
};
struct S_00c8a280_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int m_04;
    unsigned int m_08;
    S_00c8a280_Child* m_0c;
    S_00c8a280_Child* m_10;
    void FUN_00c8a280(S_00c8a280_Stream& kStream);
};
// Writes a version value, the m_0c values of m_0c and m_10 (or 0), calls v4, then writes m_08 to the stream.
// @f3 0x008fc5d0 (community match, verified in this file)
// pdb: hkConstraintCinfo::SaveBinary | bhkConstraint.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream
void S_00c8a280_Obj::FUN_00c8a280(S_00c8a280_Stream& kStream)
{
    unsigned int uiVersion = 2;
    S_00c8a280_Save(kStream.m_pBackingStream, &uiVersion, 4);
    kStream.v12(m_0c ? m_0c->m_0c : 0);
    kStream.v12(m_10 ? m_10->m_0c : 0);
    (*(void(__thiscall**)(void*))(*(void***)this + 5))(this);
    S_00c8a280_Save(kStream.m_pBackingStream, &m_08, 4);
}


class C8A4B0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C8A4B0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C8A4B0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class C8A4B0Object;

class C8A4B0Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(C8A4B0Object* pkObject);

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
    C8A4B0BinaryStream* m_pBackingStream;
};

template <class T>
inline void C8A4B0BinaryStreamSave(C8A4B0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C8A4B0SaveBinary(C8A4B0Stream& kStream, const T& value)
{
    C8A4B0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class C8A4B0Shape
{
  public:
    void SaveSphere(C8A4B0Stream& kStream);
    void SaveBox(C8A4B0Stream& kStream);
    void SaveCapsule(C8A4B0Stream& kStream);

    int unk00;
    int unk04;
    char m_cType;
};

// Writes the shape's type byte to the stream, then dispatches to SaveSphere, SaveBox or SaveCapsule; writes a zero byte if pkShape is null.
// @fnv 0x00c8a4b0
// pdb: hkConstraintCinfo::SaveMotor | bhkConstraint.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apMotor, arStream
void __stdcall SaveShape(C8A4B0Shape* pkShape, C8A4B0Stream& kStream)
{
    if (pkShape)
    {
        C8A4B0SaveBinary(kStream, pkShape->m_cType);
        switch (pkShape->m_cType)
        {
        case 1:
            pkShape->SaveSphere(kStream);
            break;
        case 2:
            pkShape->SaveBox(kStream);
            break;
        case 3:
            pkShape->SaveCapsule(kStream);
            break;
        }
    }
    else
    {
        char cNone = 0;
        C8A4B0SaveBinary(kStream, cNone);
    }
}

struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00c8a790
// pdb: bhkCollisionBox::GetRTTI | bhkCharacterController.obj | fnv360_0822_retail, objrun_prop, low
GlobalObject* __cdecl FUN_00c8a790()
{
    return &g_global;
}

struct FUN_00c8a7a0_cls;

struct FUN_00c8a7a0_cls
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void* v2D(unsigned int* out);
    void Init(unsigned int a);
    void FUN_00c8a7a0(unsigned int a1);
};

// Calls Run twice on the object, calls Init, then obtains a pointer via v2D and zeroes its second and third words.
// @f3 0x008fb740 (community match, verified in this file)
struct StreamStub_82b560
{
    void FUN_0082b560();
};
struct ObjStub_8f7ea0
{
    void FUN_008f7ea0(void* stream);
};

// pdb: bhkBinaryAction::LoadBinary | bhkBinaryAction.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void FUN_00c8a7a0_cls::FUN_00c8a7a0(unsigned int a1)
{
    unsigned int uiStream = *(volatile unsigned int*)&a1;
    StreamStub_82b560* pStream = (StreamStub_82b560*)uiStream;
    pStream->FUN_0082b560();
    pStream->FUN_0082b560();
    ((ObjStub_8f7ea0*)this)->FUN_008f7ea0(pStream);

    void* pResult = v2D(&a1);
    if (pResult)
    {
        ((int*)pResult)[1] = 0;
        ((int*)pResult)[2] = 0;
    }
}


// Result block filled in by WriteScriptTargetInfo.
struct ScriptOutBlock
{
    int unk00;
    int unk04;
    void* unk08;
};

// Object reached through the member pointer of the owner.
struct ScriptTarget
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    void* m_1c;
};

class ScriptOwnerBase
{
  public:
    void FUN_00c879e0(ScriptOutBlock* pOut);
};

class FUN_00c8a800_cls : public ScriptOwnerBase
{
  public:
    int unk00;
    int unk04;
    ScriptTarget* m_pFlagTarget;
    void WriteScriptTargetInfo(ScriptOutBlock* pOut);
};

// Calls the base writer, then stores the target's m_18 and m_1c into pOut->unk04 and pOut->unk08, or 0 when this or the target is null.
// @fnv 0x00c8a800
// pdb: bhkOrientHingedBodyAction::CopyCinfo | bhkOrientHingedBodyAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void FUN_00c8a800_cls::WriteScriptTargetInfo(ScriptOutBlock* pOut)
{
    this->FUN_00c879e0(pOut);
    pOut->unk04 = (this != 0 && m_pFlagTarget != 0) ? m_pFlagTarget->m_18 : 0;
    pOut->unk08 = (this != 0 && m_pFlagTarget != 0) ? m_pFlagTarget->m_1c : 0;
}

struct Ca980Block
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
    unsigned int m_1C;
};

class FUN_00c8a980_cls
{
  public:
    int unk00;
    int unk04;
    Ca980Block* m_08;
    bool FUN_00ba87d0(FUN_00c8a980_cls* p);
    bool FUN_00c8a980(FUN_00c8a980_cls* p);
};

// Calls FUN_00ba87d0 and, if it succeeds, also compares m_18 and m_1C of both objects' m_08 blocks, returning whether all match.
// @f3 0x008fb7f0 (community match, verified in this file)
struct FUN_00c8a980_clsF3
{
    bool FUN_008c1550(FUN_00c8a980_cls* apOther);
};
// pdb: bhkBinaryAction::IsEqual | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apObject
bool FUN_00c8a980_cls::FUN_00c8a980(FUN_00c8a980_cls* apOther)
{
    bool result = ((FUN_00c8a980_clsF3*)this)->FUN_008c1550(apOther);
    if (result)
    {
        unsigned int a = (this != 0 && this->m_08 != 0) ? this->m_08->m_18 : 0;
        unsigned int b = (apOther != 0 && apOther->m_08 != 0) ? apOther->m_08->m_18 : 0;
        result = (a == b);
        if (result)
        {
            unsigned int c = (this != 0 && this->m_08 != 0) ? this->m_08->m_1C : 0;
            unsigned int d = (apOther != 0 && apOther->m_08 != 0) ? apOther->m_08->m_1C : 0;
            result = (c == d);
        }
    }
    return result;
}


extern int DAT_012681a0;

class FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_base();
};

class FUN_00c8adf0_cls : public FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_cls();
    void FUN_00c876a0();
};

// @fnv 0x00c8adf0
FUN_00c8adf0_cls::~FUN_00c8adf0_cls()
{
    FUN_00c876a0();
    --DAT_012681a0;
}

struct FUN_00c8b000_Node
{
    int m_00;
    void* m_04;
    void* m_08;
};

struct FUN_00c8b000_Item;

struct FUN_00c8b000_Obj
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
    virtual FUN_00c8b000_Node* v18(int a);
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
    virtual bool v52(int a);
};

struct FUN_00c8b000_Item
{
    int m_00;
    int m_04;
    FUN_00c8b000_Obj* m_08;
};

struct FUN_00c8b000_List
{
    int m_00;
    FUN_00c8b000_Item** m_04;
    int m_08;
};

struct FUN_00c8b000_cls
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
    virtual FUN_00c8b000_List* v45(bool* out);
    void bhkShape_CopyMembers(int a, int b);
    void UpdateListEntries(int a1, int a2);
};

// @f3 0x008fcc70 (community match, verified in this file)
namespace f3m_008fcc70 {
struct ObjView8fcc70
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
    virtual FUN_00c8b000_Node* v18(int a);
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
    virtual bool v51(int a);
};
struct FUN_008f7580_stub
{
    void FUN_008f7580(int a, int b);
};
}

// pdb: bhkListShape::CopyMembers | bhkListShape.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apDest, arCloneData
void FUN_00c8b000_cls::UpdateListEntries(int a1, int a2)
{
    bool flag;
    FUN_00c8b000_List* list = v45(&flag);
    if (list != 0)
    {
        for (int i = 0; i < list->m_08; ++i)
        {
            FUN_00c8b000_Item* item = list->m_04[i];
            if (item != 0)
            {
                f3m_008fcc70::ObjView8fcc70* obj = reinterpret_cast<f3m_008fcc70::ObjView8fcc70*>(item->m_08);
                if (obj != 0 && !obj->v51(a2))
                {
                    FUN_00c8b000_Node* node = obj->v18(a2);
                    FUN_00c8b000_Item* result = node != 0 ? (FUN_00c8b000_Item*)node->m_08 : 0;
                    list->m_04[i] = result;
                }
            }
        }
    }
    reinterpret_cast<f3m_008fcc70::FUN_008f7580_stub*>(this)->FUN_008f7580(a1, a2);
}


struct FileContext
{
    void NiStream_ReadMultipleLinkIDs();
};
struct H_00c8b1d0
{
    virtual void reservedVirtual0();
    virtual void reservedVirtual1();
    virtual void reservedVirtual2();
    virtual void reservedVirtual3();
    virtual void reservedVirtual4();
    virtual void reservedVirtual5();
    virtual void reservedVirtual6();
    virtual void reservedVirtual7();
    virtual void reservedVirtual8();
    virtual void reservedVirtual9();
    virtual void reservedVirtual10();
    virtual void reservedVirtual11();
    virtual void reservedVirtual12();
    virtual void reservedVirtual13();
    virtual void reservedVirtual14();
    virtual void reservedVirtual15();
    virtual void reservedVirtual16();
    virtual void reservedVirtual17();
    virtual void reservedVirtual18();
    virtual void reservedVirtual19();
    virtual void reservedVirtual20();
    virtual void reservedVirtual21();
    virtual void reservedVirtual22();
    virtual void reservedVirtual23();
    virtual void reservedVirtual24();
    virtual void reservedVirtual25();
    virtual void reservedVirtual26();
    virtual void reservedVirtual27();
    virtual void reservedVirtual28();
    virtual void reservedVirtual29();
    virtual void reservedVirtual30();
    virtual void reservedVirtual31();
    virtual void reservedVirtual32();
    virtual void reservedVirtual33();
    virtual void reservedVirtual34();
    virtual void reservedVirtual35();
    virtual void reservedVirtual36();
    virtual void reservedVirtual37();
    virtual void reservedVirtual38();
    virtual void reservedVirtual39();
    virtual void reservedVirtual40();
    virtual void reservedVirtual41();
    virtual void* GetSharedData();
    virtual void reservedVirtual43();
    virtual void reservedVirtual44();
    virtual char* GetDataPosition(FileContext* volatile* object);
    void FUN_00c84d00(FileContext* object);
    void bhkListShape_LoadBinary(FileContext* object);
};
void __cdecl FUN_00cf0930(char* data, void* shared, char* component);
void __cdecl LoadIntArray(FileContext* object, char* component);
// @f3 0x008fcd00 (community match, verified in this file)
// pdb: bhkListShape::LoadBinary | bhkListShape.obj | fnv360_0822_retail, caller_sim, high
// pdb params: arStream
// pdb: bhkListShape::LoadBinary | bhkListShape.obj | fnv360_0822_retail, caller_sim, high (was: ProcessFileContext)
void H_00c8b1d0::bhkListShape_LoadBinary(FileContext* volatile object)
{
    FileContext* stableObject = object;
    stableObject->NiStream_ReadMultipleLinkIDs();
    FUN_00c84d00(stableObject);
    char* data = GetDataPosition(&object);
    if (!data)
        return;
    if (reinterpret_cast<unsigned char*>(stableObject)[0x1E5] != 1)
    {
        void* shared = GetSharedData();
        FUN_00cf0930(data, shared, data + 0x10);
        FUN_00cf0930(data, shared, data + 4);
    }
    LoadIntArray(stableObject, data + 0x10);
}


// HandleAllEntries — walks the entry array of the list object held at this+0x08
// and forwards the parameter to each entry's handler-object virtual
// (vtable slot 21), then calls the member routine FUN_00aa0ad0 on this.
//
// Count source: vtable slot 1 of the sub-object embedded at list+0x10, with
// the owner chain (this, list) null-checked; the entry walk re-checks the
// chain on every iteration and skips null slots / null handler objects.
//
// Target: __thiscall (this in ecx), callee pops 4 bytes (1 stack parameter),
// size 109, /MT /O2 /GS /EHsc /Gy.

// Sub-object embedded at list+0x10; its vtable slot 1 returns the entry
// count as an unsigned value.
struct SubObj00
{
    virtual void v0();
    virtual unsigned int GetCount();  // vtable +0x04
};

// Handler object; vtable slot 21 (+0x54) is invoked with the parameter.
struct Handler00;

// Entry object referenced by a slot; field +0x08 points at the handler
// object that receives the per-entry virtual call.
struct Entry00;

// One 16-byte slot of the entry array at list+0x18; only the first dword
// (a pointer to the entry object) is read here.
struct Slot00
{
    Entry00* p0;  // +0x00
    int unk04;
    int unk08;
    int unk0C;
};

struct Entry00
{
    int unk00;
    int unk04;
    Handler00* unk08;  // +0x08
};

struct Handler00
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
    virtual void Handle(void* param);  // vtable +0x54
};

// The list object held at this+0x08: embedded polymorphic sub-object at
// +0x10, spare dword at +0x14, entry array base at +0x18.
struct List00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SubObj00 sub;  // +0x10
    int unk14;
    Slot00* arr;  // +0x18
};

// Owning class of the target member.
struct Owner00
{
    int unk00;
    int unk04;
    List00* unk08;  // +0x08

    void __thiscall FUN_00aa0ad0(void* param);  // defined elsewhere
    void HandleAllEntries(void* param);
};

// Calls Handle(param) on each entry's handler in the list, then calls FUN_00aa0ad0(param).
// @fnv 0x00c8b240
// pdb: bhkListShape::RegisterStreamables | bhkListShape.obj | fnv360_0721_beta, objrun_sim, low
// pdb params: arStream
void Owner00::HandleAllEntries(void* param)
{
    unsigned int count;
    if (this != 0)
    {
        List00* list = this->unk08;
        if (list != 0)
            count = list->sub.GetCount();
        else
            count = 0;
    }
    else
        count = 0;

    for (unsigned int i = 0; i < count; i++)
    {
        if (this != 0)
        {
            List00* list = this->unk08;
            if (list != 0)
            {
                Entry00* entry = list->arr[i].p0;
                if (entry != 0)
                {
                    Handler00* h = entry->unk08;
                    if (h != 0)
                        h->Handle(param);
                }
            }
        }
    }

    this->FUN_00aa0ad0(param);
}

struct DecCountProvider
{
    virtual void Slot00();
    virtual int GetCount();
};

struct DecTarget
{
    int unk00;
    int unk04;
};

struct DecItem
{
    int unk00;
    int unk04;
    DecTarget* m_08;
};

struct DecEntry
{
    DecItem* m_00;
    int unk04;
    int unk08;
    int unk0C;
};

struct DecOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DecCountProvider m_10;
    int unk14;
    DecEntry* m_18;
};

typedef void(__stdcall* DecCallback)(void* arg);
extern "C" DecCallback DAT_00fdf1c0;

struct FUN_00c8b2b0_cls
{
    int unk00;
    int unk04;
    DecOwner* m_08;
    void InvokeCallbacksOnEntries();
};

// Calls DAT_00fdf1c0 for each entry's item target in reverse order, stopping early if the owner or count is null/zero.
// @fnv 0x00c8b2b0
// pdb: bhkListShape::AddbhkShapeRef | bhkListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void FUN_00c8b2b0_cls::InvokeCallbacksOnEntries()
{
    if (this == 0)
        return;
    DecOwner* p = m_08;
    if (p == 0)
        return;
    int n = p->m_10.GetCount();
    if (n == 0)
        return;
    DecCallback fn = DAT_00fdf1c0;
    do
    {
        DecOwner* o = m_08;
        --n;
        if (o != 0)
        {
            DecEntry* e = &o->m_18[n];
            DecItem* it = e->m_00;
            if (it != 0 && it->m_08 != 0)
                fn((void*)&it->m_08->unk04);
        }
    } while (n != 0);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(thread) int g_memoryContext;

struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_memoryContext;
        g_memoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_memoryContext = previousContext;
    }
};

struct RefCountedEntry
{
    virtual void UnusedVirtual();
    virtual void Release();
    volatile long referenceCount;
};

struct Record
{
    int firstField;
    int secondField;
    RefCountedEntry* referencedObject;
};

struct CollectionSlot
{
    Record* record;
    int key;
    int status;
    int extra;
};

struct IndexedRecords
{
    virtual void FirstVirtual();
    virtual unsigned int GetSize();
    int capacity;
    CollectionSlot* entries;
};

struct RecordCollection
{
    int header0;
    int header4;
    int header8;
    int headerC;
    IndexedRecords items;
};

struct CollectionHolderLayout
{
    int state;
    int reserved;
    RecordCollection* collection;
};

// Iterates the collection's entries backwards and releases each record's referenced object when its reference count drops to zero.
// @fnv 0x00c8b310
void H_00c8c810::ReleaseReferencedObjects()
{
    MemoryContextScope m_uiMemoryContext;
    CollectionHolderLayout* holder = reinterpret_cast<CollectionHolderLayout*>(this);

    if (this != 0)
    {
        RecordCollection* records = holder->collection;
        if (records != 0)
        {
            unsigned int count = records->items.GetSize();
            if (count != 0)
            {
                unsigned int offset = count << 4;
                do
                {
                    --count;
                    offset -= 16;
                    if (holder->collection != 0)
                    {
                        Record* record = *reinterpret_cast<Record**>(
                            reinterpret_cast<unsigned char*>(holder->collection->items.entries) + offset);
                        if (record != 0)
                        {
                            RefCountedEntry* reference = record->referencedObject;
                            if (reference != 0 && InterlockedDecrement(&reference->referenceCount) == 0)
                            {
                                reference->Release();
                            }
                        }
                    }
                } while (count != 0);
            }
        }
    }
}

extern __declspec(thread) int tls_iMemContext;

struct MemContextScope
{
    int iOld;
    MemContextScope(int iNew)
    {
        iOld = tls_iMemContext;
        tls_iMemContext = iNew;
    }
    ~MemContextScope()
    {
        tls_iMemContext = iOld;
    }
};

int __cdecl sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
char* __cdecl CreateDebugString(const char* pcName);
char* __cdecl CreateDebugString(const char* pcName, int iValue);

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};

struct NiRTTIStub
{
    const char* m_pcName;
    const NiRTTIStub* m_pBaseRTTI;
};
extern NiRTTIStub bhkListShape_ms_RTTI;

struct hkpShapeContainerStub
{
    virtual ~hkpShapeContainerStub();
    virtual int GetNumChildShapes();
};

struct hkpListShapeStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpShapeContainerStub kContainer;
};

struct bhkShapeCollectionBase
{
    void GetViewerStrings_base(ViewerStrings* pkStrings);
};

struct bhkListShapeStub : bhkShapeCollectionBase
{
    int unk00;
    int unk04;
    hkpListShapeStub* m_pHavokObject;

    void FUN_00c8bcd0(ViewerStrings* pkStrings);
};

static inline hkpListShapeStub* GetHkListShape(bhkListShapeStub* p)
{
    return p ? p->m_pHavokObject : 0;
}

// @f3 0x008fd7e0 (community match, verified in this file)
extern char DAT_00e32750[];
extern char DAT_00e347d0[];

// pdb: bhkListShape::GetViewerStrings | bhkListShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void bhkListShapeStub::FUN_00c8bcd0(ViewerStrings* pkStrings)
{
    GetViewerStrings_base(pkStrings);
    pkStrings->Add(CreateDebugString(bhkListShape_ms_RTTI.m_pcName));
    hkpListShapeStub* pHk = GetHkListShape(this);
    int iShapeCount = pHk ? pHk->kContainer.GetNumChildShapes() : 0;
    pkStrings->Add(CreateDebugString(DAT_00e32750, iShapeCount));
    for (int i = 0; i < iShapeCount; i++)
    {
        char acBuf[32];
        sprintf_s(acBuf, 32, DAT_00e347d0, i);
    }
}


namespace fnv_00c8be30 {
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

}  // namespace fnv_00c8be30

class C8CCC0Base
{
  public:
    bool IsEqual(const C8CCC0Base& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class C8CCC0Derived : public C8CCC0Base
{
  public:
    bool FUN_00c8ccc0(const C8CCC0Derived& kOther) const;

    int m_iValue;
};

// Calls the base IsEqual and, if it succeeds, also compares m_iValue with the other object's m_iValue.
// @fnv 0x00c8ccc0
// pdb: bhkStream::Endian | bhkTransformShape.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkRigidBody::IsEqual)
// pdb params: arRot
bool C8CCC0Derived::FUN_00c8ccc0(const C8CCC0Derived& kOther) const
{
    bool bEqual = IsEqual(kOther);
    if (bEqual)
        bEqual = m_iValue == kOther.m_iValue;
    return bEqual;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);

struct SwapMatrix_c8ce70
{
    unsigned long m00;
    unsigned long m04;
    unsigned long m08;
    unsigned long m0c;
    unsigned long m10;
    unsigned long m14;
    unsigned long m18;
    unsigned long m1c;
    unsigned long m20;
    unsigned long m24;
    unsigned long m28;
    unsigned long m2c;
};

inline void Swap32_c8ce70(void* p)
{
    unsigned long* q = (unsigned long*)p;
    *q = _byteswap_ulong(*q);
}
inline void Swap16_c8ce70(void* p)
{
    unsigned short* q = (unsigned short*)p;
    *q = _byteswap_ushort(*q);
}

void __cdecl SwapEndianBlocks(SwapMatrix_c8ce70* m);

struct SwapBlock_c8ce70
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
    unsigned short unk2c;
    short unk2e;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    SwapMatrix_c8ce70 unk70;
    float unka0;
    float unka4;
    float unka8;
    float unkac;
    float unkb0;
    float unkb4;
    float unkb8;
    float unkbc;
    float unkc0;
    float unkc4;
    float unkc8;
    float unkcc;
    float unkd0;

    void SwapEndian();
};

// @f3 0x008fe660 (community match, verified in this file)
// pdb: bhkRigidBodyCinfo::Endian | bhkRigidBody.obj | fnv360_0822_retail, call_seq, medium
void SwapBlock_c8ce70::SwapEndian()
{
    Swap32_c8ce70(&unk30);
    Swap32_c8ce70(&unk34);
    Swap32_c8ce70(&unk38);
    Swap32_c8ce70(&unk3c);
    Swap32_c8ce70(&unk40);
    Swap32_c8ce70(&unk44);
    Swap32_c8ce70(&unk48);
    Swap32_c8ce70(&unk4c);
    Swap32_c8ce70(&unk50);
    Swap32_c8ce70(&unk54);
    Swap32_c8ce70(&unk58);
    Swap32_c8ce70(&unk5c);
    Swap32_c8ce70(&unk60);
    Swap32_c8ce70(&unk64);
    Swap32_c8ce70(&unk68);
    Swap32_c8ce70(&unk6c);
    SwapEndianBlocks(&unk70);
    Swap32_c8ce70(&unka0);
    Swap32_c8ce70(&unka4);
    Swap32_c8ce70(&unka8);
    Swap32_c8ce70(&unkac);
    Swap32_c8ce70(&unkb0);
    Swap32_c8ce70(&unkb4);
    Swap32_c8ce70(&unkb8);
    Swap32_c8ce70(&unkbc);
    Swap32_c8ce70(&unkc0);
    Swap32_c8ce70(&unkc4);
    Swap32_c8ce70(&unkc8);
    Swap32_c8ce70(&unkcc);
}


class FUN_00c8d090_item
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
    virtual void v15(int a);
};

struct FUN_00c8d090_node
{
    FUN_00c8d090_item* m_pInventoryEntryData;
    FUN_00c8d090_node* m_pNext;
};

struct FUN_00c8d090_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00c8d090_node m_14;

    bool Check(int a);
    bool CheckAndNotify(int a);
};

// Calls Check(a); if it succeeds, walks the m_14 linked list and calls v15(a) on each item, returning the Check result.
// @fnv 0x00c8d090
// pdb: bhkRigidBody::RegisterStreamables | bhkRigidBody.obj | fnv360_0721_beta, objrun, medium
// pdb params: arStream
bool FUN_00c8d090_cls::CheckAndNotify(int a)
{
    bool ok = Check(a);
    if (ok)
    {
        FUN_00c8d090_node* node = &m_14;
        if (node != 0)
        {
            do
            {
                FUN_00c8d090_item* item = node->m_pInventoryEntryData;
                if (item == 0)
                {
                    break;
                }
                item->v15(a);
                node = node->m_pNext;
            } while (node != 0);
        }
    }
    return ok;
}

struct FUN_00c8d0d0_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    int GetNodeCount();
};

// @fnv 0x00c8d0d0
// pdb: bhkRigidBody::GetActConCount | bhkRigidBody.obj | fnv360_0721_beta, objrun, medium
int FUN_00c8d0d0_Object::GetNodeCount()
{
    int count = 0;
    int* node = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14);

    while (node && *node)
    {
        ++count;
        node = *reinterpret_cast<int**>(reinterpret_cast<char*>(node) + 4);
    }

    return count;
}

class C90830ReferencedObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    C90830ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual ~C90830ReferencedObject()
    {}
};

struct C90830Stream
{
    int m_iHandle;
    unsigned short m_usFlags;

    C90830Stream() : m_iHandle(-15), m_usFlags(0x8000)
    {}
    void ResetThreadCheck() throw();
};

struct FUN_00c90e00
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float m_24;

    FUN_00c90e00(int flag);
};

// If flag is set and m_24 equals DAT_01012060, sets m_24 to 1.0f.
// @f3 0x0090ab60 (community match, verified in this file)
extern const double DAT_00db38b0;
extern float DAT_00de6e60;
extern void* DAT_00e35170[];

FUN_00c90e00::FUN_00c90e00(int flag)
{
    *(unsigned short*)((char*)this + 6) = 1;
    *(void**)this = DAT_00e35170;
    if (flag)
    {
        if (m_24 == DAT_00db38b0)
            m_24 = DAT_00de6e60;
    }
}


namespace fnv_00c99f80 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00c99f80

extern int DAT_012681e8;

// @fnv 0x00c99fe0
void* __cdecl FUN_00c99fe0()
{
    return &DAT_012681e8;
}

extern int DAT_012681c0;

struct FUN_00c9a660_cls
{
    float m_00;
    float m_04;
    float m_08;

    bool NotEqual(const FUN_00c9a660_cls* other) const;
};

// Returns true when any of the three floats differs from the corresponding float in other.
// @fnv 0x00c9a660
// pdb: NiPoint3::operator!= | MultiBoundMarkerData.obj | fnv360_0822_debug, call_gap, high
// pdb params: pt
bool FUN_00c9a660_cls::NotEqual(const FUN_00c9a660_cls* other) const
{
    int r = (m_00 == other->m_00 && m_04 == other->m_04 && m_08 == other->m_08) ? 1 : 0;
    return !(char)r;
}

struct FUN_00c9a840_cls
{
    struct Vec3
    {
        float x;
        float y;
        float z;
    };
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
    Vec3* m_pVerts;
    int unk40;
    int unk44;
    unsigned int m_uiItemCount;

    bool FUN_00a6cc80(FUN_00c9a840_cls* other);
    bool FUN_00c9a840(FUN_00c9a840_cls* other);
};
// @fnv 0x00c9a840
// pdb: bhkBlendController::IsEqual | bhkBlendController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apObject
bool FUN_00c9a840_cls::FUN_00c9a840(FUN_00c9a840_cls* other)
{
    bool eq = FUN_00a6cc80(other);
    if (eq)
    {
        eq = (m_uiItemCount == other->m_uiItemCount);
        unsigned int i = 0;
        while (eq && i < m_uiItemCount)
        {
            unsigned int off = i * 12;
            Vec3* pb = (Vec3*)((char*)other->m_pVerts + off);
            Vec3* pa = (Vec3*)((char*)m_pVerts + off);
            eq = (pa->x == pb->x) && (pa->y == pb->y) && (pa->z == pb->z);
            i++;
        }
    }
    return eq;
}

extern double DAT_010231b0;
extern double DAT_010241b0;

struct FUN_00c9ab10_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float* unk3c;
    int unk40;
    int unk44;
    int unk48;

    void FUN_00c9ab10();
};

// @fnv 0x00c9ab10
// pdb: bhkBlendController::FixStartAndEndTimes | bhkBlendController.obj | fnv360_0822_retail, call_seq, medium
void FUN_00c9ab10_class::FUN_00c9ab10()
{
    float value = 0.0f;
    float result = 0.0f;

    int count = this->unk48;
    if (count != 0)
    {
        float* values = this->unk3c;
        float first = values[0];

        value = this->unk14;
        result = this->unk18;

        if (value > first || value == DAT_010231b0)
        {
            value = first;
        }

        float last = values[count * 3 - 3];

        if (result > last || result == DAT_010241b0)
        {
            result = last;
        }
    }

    this->unk14 = value;
    this->unk18 = result;
}

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct Elem_c9ac00
{
    float a;
    float b;
    float c;
    Elem_c9ac00()
    {}
    Elem_c9ac00(int i)
    {
        float f = (float)(i / 100.0);
        a = -1.0f;
        b = f;
        c = f;
    }
    Elem_c9ac00& operator=(const Elem_c9ac00& o)
    {
        a = o.a;
        b = o.b;
        c = o.c;
        return *this;
    }
    bool operator!=(const Elem_c9ac00& o) const
    {
        return a != o.a || b != o.b || c != o.c;
    }
};

struct LargeArray_c9ac00
{
    void** m_ppVirtualMethodTable;
    Elem_c9ac00* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};

// @f3 0x009147c0 (community match, verified in this file)
namespace n9147c0 {
struct Key {
    float a;
    float b;
    float c;
    Key() {}
    Key(int i)
    {
        float f = (float)(i / 100.0);
        a = -1.0f;
        c = f;
        b = c;
    }
    bool operator!=(const Key& o) const
    {
        return a != o.a || b != o.b || c != o.c;
    }
};
}
// pdb: NiTLargeArray<BLENDKEY,NiTMallocInterface<BLENDKEY> >::SetSize | bhkBlendController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: uiMaxSize
void LargeArray_c9ac00::Resize(unsigned int uiMaxSize)
{
    typedef n9147c0::Key T;
    if (uiMaxSize == m_uiMaxSize)
        return;
    unsigned int i;
    if (uiMaxSize < m_uiSize) {
        for (i = uiMaxSize; i < m_uiSize; i++) {
            if (((T*)m_pBase)[i] != T(0)) {
                ((T*)m_pBase)[i] = T(0);
                m_uiESize--;
            }
        }
        m_uiSize = uiMaxSize;
    }
    T* pSaveBase = (T*)m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (uiMaxSize > 0) {
        m_pBase = (Elem_c9ac00*)NiMalloc(sizeof(T) * m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
            ((T*)m_pBase)[i] = pSaveBase[i];
        for (i = m_uiSize; i < m_uiMaxSize; i++)
            ((T*)m_pBase)[i] = T(0);
    } else {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}


void FUN_00aa10f0(int value);

struct SubObject_c9ad60
{
    int m_00;

    virtual ~SubObject_c9ad60();
};

struct Base_c9ad60
{
    virtual void unk00();
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

    ~Base_c9ad60();
};

class FUN_00c9ad60_cls : public Base_c9ad60
{
  public:
    SubObject_c9ad60 m_38;

    virtual ~FUN_00c9ad60_cls();
};

SubObject_c9ad60::~SubObject_c9ad60()
{
    FUN_00aa10f0(m_00);
}

// Destructor of the class; the empty body relies on the implicit destruction of the m_38 sub-object, which releases its m_00 via FUN_00aa10f0.
// @fnv 0x00c9ad60
FUN_00c9ad60_cls::~FUN_00c9ad60_cls()
{}

// FUN_00c9add0 : a one-line function - getter
extern int g_target_00c9add0;
// @fnv 0x00c9add0
// pdb: bhkBlendCollisionObject::GetRTTI | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun, medium
void* FUN_00c9add0()
{
    return &g_target_00c9add0;
}

struct S_00c9af40_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_00c9af40_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(S_00c9af40_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};

struct S_00c9af40_Point
{
    float x, y, z;
    S_00c9af40_Point()
    {}
    S_00c9af40_Point(const S_00c9af40_Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};

namespace fnv_00c9b1a0 {
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

}  // namespace fnv_00c9b1a0

extern __declspec(thread) int g_iC9B970MemContext;

class C9B970MemContext
{
  public:
    C9B970MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iC9B970MemContext;
        g_iC9B970MemContext = aiMemoryContext;
    }
    ~C9B970MemContext()
    {
        g_iC9B970MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

namespace fnv_00c9ba40 {
extern __declspec(thread) int memoryCategory;
struct ReadScope
{
    int previous;
    ReadScope() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ReadScope()
    {
        memoryCategory = previous;
    }
};
struct BinaryInput
{
    void* vtable;
    unsigned int position;
    unsigned int (*read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadCount(unsigned int& value)
    {
        unsigned int componentSize = 4;
        Read(&value, 4, &componentSize, 1);
    }
    void Read(void* data, unsigned int bytes, unsigned int* components, unsigned int count)
    {
        position += read(this, data, bytes, components, count);
    }
};
struct SerializedPoint
{
    float first, second, third;
    SerializedPoint(float value = -1.0f, float percentage = 0.0f)
        : first(value), second(percentage / 100.0), third(percentage / 100.0)
    {}
};
}  // namespace fnv_00c9ba40

namespace fnv_00c9bef0 {
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

}  // namespace fnv_00c9bef0

struct FUN_00c9ea90_Base
{
    virtual void b0();
    FUN_00c9ea90_Base(int a, int b);
};

struct FUN_00c9ea90 : FUN_00c9ea90_Base
{
    virtual void v0();

    FUN_00c9ea90(int a1);
};

// @f3 0x0090dec0 (community match, verified in this file)
// pdb: hkpPhantom::hkpPhantom | hkpShapePhantom.obj | fnv360_0822_debug, callee_sim, low
// pdb params: shape
FUN_00c9ea90::FUN_00c9ea90(int aiValue) : FUN_00c9ea90_Base(aiValue, 2)
{
    char* self = (char*)this;
    *(volatile int*)(self + 0x80) = 0;
    *(volatile int*)(self + 0x84) = 0;
    *(volatile unsigned int*)(self + 0x88) = 0x80000000u;
    *(volatile int*)(self + 0x8c) = 0;
    *(volatile int*)(self + 0x90) = 0;
    *(volatile unsigned int*)(self + 0x94) = 0x80000000u;
    char* pa = self + 0x10;
    *(unsigned char*)(pa + 0x10) = (unsigned char)((unsigned int)self - (unsigned int)pa);
}


namespace fnv_00c9eae0 {
// FUN_00c9eae0 : cdecl one-arg entry point that forwards a record pointer and
// a 16-bit count field to the game allocator's virtual slot 2.

struct FUN_00c9eae0_alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned short count);
};

struct FUN_00c9eae0_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00c9eae0_alloc* m_pAllocator;
};

FUN_00c9eae0_holder* FUN_00c85750();

}  // namespace fnv_00c9eae0

namespace fnv_00c9eb00 {
struct FnvCpu_FUN_00c9eb00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00c9eb00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00c9eb00_CpuAllocator* allocator;
};
FnvCpu_FUN_00c9eb00_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00c9eb00

// Give the object an emissive material of the given color, notify listeners, then update it through the owner.

struct C11F0Color
{
    float r;
    float g;
    float b;
};

class C11F0Object;

extern void(__cdecl* g_pfnC11F0EmissiveChanged)(C11F0Object* pkObject, C11F0Color* pkColor);

class C11F0Material
{
  public:
    C11F0Material();
    virtual ~C11F0Material();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    void SetEmittance(const C11F0Color& kColor)
    {
        m_kEmissive = kColor;
        m_uiRevisionID++;
    }

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    C11F0Color m_kEmissive;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int m_uiRevisionID;
    int unk48;
};

class C11F0Object
{
  public:
    void AttachProperty(C11F0Material* pkProperty);
};

typedef int(__cdecl* NiBinaryStream_fn)(void* s, void* buf, unsigned int n, int* out, int flag);

struct NiBinaryStream
{
    void* m_00;
    unsigned int m_04;
    NiBinaryStream_fn m_08;

    unsigned int BinaryRead(void* p, unsigned int n, int* sizes, unsigned int count)
    {
        unsigned int read = m_08(this, p, n, sizes, count);
        m_04 += read;
        return read;
    }
};

struct NiStream
{
    int m_00;
    unsigned int m_04;
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
    NiBinaryStream* m_24c;
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    int uiSize = sizeof(T);
    kIstr->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream* kStream, T& value)
{
    NiBinaryStreamLoad(kStream->m_24c, &value);
}

struct C818F0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00c65800(NiStream* p);
    void FUN_00c818f0(NiStream* p);
};

// @fnv 0x00c818f0
// pdb: bhkBlendCollisionObject::LoadBinary | bhkBlendCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void C818F0_cls::FUN_00c818f0(NiStream* pStream)
{
    int buf;
    FUN_00c65800(pStream);
    ReadBinaryValue(pStream, m_18);
    ReadBinaryValue(pStream, m_1c);
    if (pStream->m_04 < 8)
    {
        ReadBinaryValue(pStream, buf);
        ReadBinaryValue(pStream, buf);
    }
}

struct S_00c81b40_Callee
{
    virtual void m_v01();
    virtual void m_v02();
    virtual void m_v03();
    virtual void m_v04();
    virtual void m_v05();
    virtual void m_v06();
    virtual void m_v07();
    virtual void m_v08();
    virtual void m_v09();
    virtual void m_v10();
    virtual void m_v11();
    virtual void m_v12();
    virtual void m_v13();
    virtual void m_v14();
    virtual void m_v15();
    virtual void m_v16();
    virtual void m_v17();
    virtual void m_v18();
    virtual void m_v19();
    virtual void m_v20();
    virtual void m_v21();
    virtual void m_v22();
    virtual void m_v23();
    virtual void m_v24();
    virtual void m_v25();
    virtual void m_v26();
    virtual void m_v27();
    virtual void m_v28();
    virtual void m_v29();
    virtual void m_v30();
    virtual void m_v31();
    virtual void m_v32();
    virtual void m_v33();
    virtual void m_v34();
    virtual void m_v35();
    virtual void m_v36();
    virtual void m_v37();
    virtual void m_v38();
    virtual void m_v39();
    virtual void m_v40(int* argument);

    int unk04;
    unsigned char* m_data8;
};

struct S_00c81b40_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c81b40_Callee* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int* unk24;
    int unk28;

    void UpdateCountdown();
};

// Decrements unk28; when it reaches zero, checks the callee's data flags for 8 or 0x1d and calls m_v40 with unk24.
// @fnv 0x00c81b40
// pdb: bhkBlendCollisionObject::DecForceAdd | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun, medium
void S_00c81b40_Owner::UpdateCountdown()
{
    unk28--;

    if (unk28 > 0)
        return;

    S_00c81b40_Callee* callee = unk10;
    unk28 = 0;

    if (callee == 0)
        return;

    unsigned char* data = callee->m_data8;

    if (data != 0)
        data += 0x10;

    unsigned int flags = data ? *(unsigned int*)(data + 0x1c) : 0;

    flags &= 0x7f;

    if (flags != 8 && flags != 0x1d)
        return;

    int* argument = unk24;
    if (argument == 0)
        return;

    callee->m_v40(argument);
}

char* __cdecl CreateDebugString(const char* pcName, float fValue);
char* __cdecl CreateDebugString(const char* pcName, bool bValue);
char* __cdecl CreateDebugString(const char* pcName, const char* pcValue);
extern char* g_01267e64_str;

__forceinline bool GetFlagBit8(unsigned short f)
{
    return (f >> 8) & 1;
}
__forceinline bool GetFlagBit9(unsigned short f)
{
    return (f >> 9) & 1;
}
struct FUN_00c825b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1c;
    int unk20;
    int m_i24;

    void FUN_00c66060(ViewerStrings* pkStrings);
    void AddToViewerStrings(ViewerStrings* pkStrings);
};

// @f3 0x008f4230 (community match, verified in this file)
// pdb: bhkBlendCollisionObject::AddViewerStrings | bhkBlendCollisionObject.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void FUN_00c825b0_cls::AddToViewerStrings(ViewerStrings* pkStrings)
{
    FUN_00c66060(pkStrings);
    char* pcString;
    pcString = CreateDebugString(g_01267e64_str);
    pkStrings->Add(pcString);
    pcString = CreateDebugString("fHeirGain", m_f18);
    pkStrings->Add(pcString);
    pcString = CreateDebugString("fVelGain", m_f1c);
    pkStrings->Add(pcString);
    pcString = CreateDebugString("bBlendPos", GetFlagBit8(m_usFlags));
    pkStrings->Add(pcString);
    pcString = CreateDebugString("bAlwaysBlend", GetFlagBit9(m_usFlags));
    pkStrings->Add(pcString);
    char buf[64];
    sprintf_s(buf, 64, "0x%08X", m_i24);
    pcString = CreateDebugString("Stored World", buf);
    pkStrings->Add(pcString);
}


struct FUN_00c84900_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int FUN_00c84900_call(unsigned int value);
};
struct FUN_00c84900_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* field20;
};
extern unsigned char __cdecl FUN_00c84740(void* object, unsigned int value);
// Calls the caller's virtual method with value, passes the result and object->field20 to FUN_00c84740, and stores the returned byte in output.
// @fnv 0x00c84900
// pdb: bhkCollisionFilter::isCollisionEnabled | bhkCollisionFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInput, arShape, arCollection, aKey
unsigned char* __stdcall CallAndStoreResult(unsigned char* output, FUN_00c84900_object* object, int unused,
                                            FUN_00c84900_vtbl* caller, unsigned int value)
{
    unsigned int result = caller->FUN_00c84900_call(value);
    void* field = object->field20;
    *output = FUN_00c84740(field, result);
    return output;
}

char* __cdecl FUN_00a7d5e0(const char* prefix, const char* str);
char* __cdecl FUN_00a7d510(const char* prefix, unsigned int val);
char* __cdecl FUN_00a7d370(const char* prefix, bool val);

extern const char* kFilterLayers[];
extern const char* kFilterParts[];

struct HavokFilterInfo
{
    unsigned int m_uFilterInfo;

    unsigned short GetGroup() const
    {
        return (unsigned short)(m_uFilterInfo >> 16);
    }
    unsigned int GetLayer() const
    {
        return m_uFilterInfo & 0x7F;
    }
    bool GetLink() const
    {
        return (m_uFilterInfo >> 15) & 1;
    }
    unsigned int GetPart() const
    {
        return (m_uFilterInfo >> 8) & 0x1F;
    }
    bool GetNoCol() const
    {
        return (m_uFilterInfo >> 14) & 1;
    }
    bool GetScaled() const
    {
        return (m_uFilterInfo >> 13) & 1;
    }

    void AppendToViewerStrings(ViewerStrings* pkStrings);
};

static __forceinline void AddString(ViewerStrings* pkStrings, char* pcString)
{
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

// Formats the filter info and its group, layer, link, part, no-collision and scaled flags into prefixed strings appended to pkStrings.
// @fnv 0x00c849b0
// pdb: CFilter::GetViewerStrings | bhkCollisionFilter.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void HavokFilterInfo::AppendToViewerStrings(ViewerStrings* pkStrings)
{
    char acBuffer[128];

    sprintf_s(acBuffer, sizeof(acBuffer), "0x%08X", m_uFilterInfo);
    AddString(pkStrings, FUN_00a7d5e0("COLFILTER", acBuffer));

    sprintf_s(acBuffer, sizeof(acBuffer), "0x%X", GetGroup());
    AddString(pkStrings, FUN_00a7d5e0("-GROUP", acBuffer));

    AddString(pkStrings, FUN_00a7d5e0("-LAYER", kFilterLayers[GetLayer()]));

    AddString(pkStrings, FUN_00a7d370("-LINK", GetLink()));

    if (GetLayer() == 8)
        goto LABEL_PART_STR;
    if (GetLayer() == 0x1D)
    {
    LABEL_PART_STR:
        const char* pszPart = kFilterParts[GetPart()];
        AddString(pkStrings, FUN_00a7d5e0("-PART", pszPart));
    }
    else if (GetLink())
    {
        AddString(pkStrings, FUN_00a7d510("-PART", GetPart()));
    }

    AddString(pkStrings, FUN_00a7d370("-NOCOL", GetNoCol()));

    AddString(pkStrings, FUN_00a7d370("-SCALED", GetScaled()));
}

struct FUN_00c84d50_arg
{
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00c;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01c;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02c;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03c;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04c;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05c;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06c;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07c;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08c;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09c;
    int m_unk0a0;
    int m_unk0a4;
    int m_unk0a8;
    int m_unk0ac;
    int m_unk0b0;
    int m_unk0b4;
    int m_unk0b8;
    int m_unk0bc;
    int m_unk0c0;
    int m_unk0c4;
    int m_unk0c8;
    int m_unk0cc;
    int m_unk0d0;
    int m_unk0d4;
    int m_unk0d8;
    int m_unk0dc;
    int m_unk0e0;
    int m_unk0e4;
    int m_unk0e8;
    int m_unk0ec;
    int m_unk0f0;
    int m_unk0f4;
    int m_unk0f8;
    int m_unk0fc;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10c;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11c;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12c;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13c;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14c;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15c;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16c;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17c;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18c;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19c;
    int m_unk1a0;
    int m_unk1a4;
    int m_unk1a8;
    int m_unk1ac;
    int m_unk1b0;
    int m_unk1b4;
    int m_unk1b8;
    int m_unk1bc;
    int m_unk1c0;
    int m_unk1c4;
    int m_unk1c8;
    int m_unk1cc;
    int m_unk1d0;
    int m_unk1d4;
    int m_unk1d8;
    int m_unk1dc;
    int m_unk1e0;
    unsigned char m_unk1e4;
};

struct FUN_00c84d50_cls
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
    virtual void v41(void* object);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual int* v45(void*& object);

    int m_unk04;
    int m_unk08;
    int m_unk0c;
    unsigned int m_flags;

    void bhkSerializable_SaveBinary(void* arg);
    void bhkShape_SaveBinary(void* arg);
};

// @fnv 0x00c84d50
// pdb: bhkShape::SaveBinary | bhkShape.obj | fnv360_0822_retail, caller_sim + bridge(vtable|vtable) + skyrim(objrun), high
void FUN_00c84d50_cls::bhkShape_SaveBinary(void* arg)
{
    void* object;
    int* result = v45(object);
    unsigned int value = m_flags & 0x1fu;
    *result = value;

    FUN_00c84d50_arg* data = static_cast<FUN_00c84d50_arg*>(arg);
    if (data->m_unk1e4 != 1)
        *result = _byteswap_ulong(value);

    bhkSerializable_SaveBinary(arg);

    if (data->m_unk1e4 != 1)
        *result = _byteswap_ulong(*result);

    v41(object);
}

struct NiFixedStrX
{
    char* m_str;
    NiFixedStrX(const char* str)
    {
        m_str = NiGlobalStringTable::AddString(str);
    }
    __forceinline ~NiFixedStrX()
    {
        if (m_str != _EmptyFS)
            InterlockedDecrement((long*)(m_str - 8));
    }
};

struct NiNodeX
{
    int unk00;
    int unk04;
    char* m_name;
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
    NiNodeX(unsigned short count);
    void SetName(const NiFixedStrX& name);
    static void* operator new(unsigned int size);
};

struct bhkWorldX
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
    virtual void AddDebugNode(NiNodeX* node, NiPoint3* offset);
};

struct WorldHolder
{
    int unk00;
    int unk04;
    bhkWorldX* m_pOwningWorld;
};

struct PhantomData
{
    WorldHolder* m_holder;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_pCollisionShape;
};

struct WorldObjectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhantomData m_data;
};

void __cdecl GetLayerColor(int shape, NiPoint3* out);

struct bhkWorldObjectX
{
    int unk00;
    int unk04;
    WorldObjectX* m_obj;
    NiNodeX* AddDebugNodeToWorld(NiNodeX* node);
};

// Ensures node has a name, computes a point via GetLayerColor and adds the node to the world's debug nodes, returning the node.
// @f3 0x008fa0e0 (community match, verified in this file)
struct F3World2162
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
    virtual void AddDebugNode(NiNodeX* node);
};
extern const char FUN_00e329a0[];

extern const NiPoint3 FUN_00f731bc;

extern void* __cdecl FUN_0089eb90(unsigned int size);

inline void* NiNodeX::operator new(unsigned size){return FUN_0089eb90(size);}

struct DebugColorCompareCall {

    float x, y, z;

    bool FUN_00914770(const NiPoint3* rhs);

};

struct FUN_0083fc40 {

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    int unk20, unk24;

    NiPoint3 color;

    int unk34, unk38, unk3c, unk40;

    int refs;

    int unk48;

    FUN_0083fc40();
    static void* operator new(unsigned size){return FUN_0089eb90(size);}

};

struct DebugNodeAttachCall { void FUN_004236f0(FUN_0083fc40* material); };

// pdb: bhkWorldObject::CreateDisplayGeometry | bhkWorldObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apNode
NiNodeX* bhkWorldObjectX::AddDebugNodeToWorld(NiNodeX* node)

{

    PhantomData* data;

    WorldHolder* holder;

    F3World2162* world;

    if (this && m_obj && (data = &m_obj->m_data) != 0 &&

        (holder = data->m_holder) != 0 && (world = (F3World2162*)holder->m_pOwningWorld) != 0)

    {

        if (!node) node = new NiNodeX(0);

        if (!node->m_name)

        {

            NiFixedStrX name(FUN_00e329a0);

            node->SetName(name);

        }

        NiPoint3 pt;

        pt.x = 0.0f;

        pt.y = 0.0f;

        pt.z = 0.0f;

        PhantomData* pData2 = m_obj ? &m_obj->m_data : 0;

        GetLayerColor(pData2 ? pData2->m_pCollisionShape : 0, &pt);

        if (((DebugColorCompareCall*)&pt)->FUN_00914770(&FUN_00f731bc))

        {

            FUN_0083fc40* material = new FUN_0083fc40;

            material->color = pt;

            ++material->refs;

            ((DebugNodeAttachCall*)node)->FUN_004236f0(material);

        }

        world->AddDebugNode(node);

        return node;

    }

    return node;

}


extern __declspec(thread) int g_iC88760AllocTag;

struct BC88760AllocTagScope
{
    int m_iSaved;

    BC88760AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC88760AllocTag;
        g_iC88760AllocTag = aiAllocationTag;
    }
    ~BC88760AllocTagScope()
    {
        g_iC88760AllocTag = m_iSaved;
    }
};

class BC88760CloningProcess;

class BC88760Base
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC88760Base();
    virtual ~BC88760Base();

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
};

class BC88760Derived : public BC88760Base
{
  public:
    BC88760Derived()
    {}
    virtual ~BC88760Derived();

    void CopyMemberData(BC88760Derived* pkDest, BC88760CloningProcess& kCloning);
    BC88760Derived* FUN_00c88760(BC88760CloningProcess& kCloning);
};

class NiNode;
class NiAVObject;
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* pcString) : m_kHandle(NiGlobalStringTable::AddString(pcString))
    {}
    ~NiFixedString()
    {
        if (m_kHandle != _EmptyFS)
            InterlockedDecrement(reinterpret_cast<long*>(m_kHandle - 8));
    }
};
class NiUpdateData
{
  public:
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bUnk8;
    NiUpdateData()
        : m_fTime(0.0f), m_bUpdate(false), m_bIsMultiThreaded(false), m_bUpdateGeomorphs(false),
          m_bUpdateShadowSceneNode(false), m_bUnk8(false)
    {}
};
struct FUN_00c88810_Collision
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
};
class NiAVObject
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* IsSceneNode();
    char pad04[0x14];
    NiNode* m_pParentNode;
    FUN_00c88810_Collision* m_spCollisionObject;
    void Update(const NiUpdateData& kUpdateData);
};
class NiNode : public NiAVObject
{
  public:
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
    char pad20[0x9c - 0x20];
    NiTObjectArray<NiAVObject*> m_kChildList;
};
void bhkWorld_SetMotion(NiNode* apNode, int aiArg, bool abA, bool abB, bool abC);
// Updates apObject, then for each child of the Chain01 node's parent with a collision object, calls Unk_2A and bhkWorld_SetMotion.
// @fnv 0x00c88810
// pdb: WeaponObject::UpdateChain | WeaponObject.obj | fnv360_0822_retail, ustr, high
// pdb params: apWeaponObj, apWorld
// pdb: WeaponObject::UpdateChain | WeaponObject.obj | fnv360_0822_retail, ustr, high (was: UpdateChainCollision)
void WeaponObject_UpdateChain(NiAVObject* apObject)
{
    NiNode* pkRoot = apObject->IsSceneNode();
    if (!pkRoot)
        return;
    NiAVObject* pkChain = pkRoot->GetObjectByName("Chain01");
    if (!pkChain)
        return;
    apObject->Update(NiUpdateData());
    NiNode* pkParent = pkChain->m_pParentNode;
    if (!pkParent)
        return;
    for (unsigned int i = 0; i < pkParent->m_kChildList.m_usSize; i++)
    {
        NiAVObject* pkChild = pkParent->m_kChildList.m_pBase[i];
        if (pkChild)
        {
            FUN_00c88810_Collision* pkCollision = pkChild->m_spCollisionObject;
            if (pkCollision)
            {
                pkCollision->Unk_2A();
                bhkWorld_SetMotion((NiNode*)pkChild, 1, false, true, true);
            }
        }
    }
}

// LinkObject: resolve the two linked bodies and store their Havok entities in the constraint data.

class C8A910Stream
{
  public:
    void* GetLoadedObject();
};

class C8A910Body
{
  public:
    int unk00;
    int unk04;
    void* m_pkEntity;
};

struct C8A910ConstraintData
{
    int unk00;
    void* m_pkEntityA;
    void* m_pkEntityB;
};

class C8A910Constraint
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual C8A910ConstraintData* GetConstraintData(unsigned int& ruiType);

    void LinkObjectBase(C8A910Stream& kStream);
    void FUN_00c8a910(C8A910Stream& kStream);
};

// @f3 0x008fb780 (community match, verified in this file)
// pdb: bhkBinaryAction::LinkObject | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void C8A910Constraint::FUN_00c8a910(C8A910Stream& kStream)
{
    C8A910Body* pkBodyA = (C8A910Body*)kStream.GetLoadedObject();
    C8A910Body* pkBodyB = (C8A910Body*)kStream.GetLoadedObject();
    unsigned int uiType;
    C8A910ConstraintData* pkData = GetConstraintData(uiType);
    if (pkData && pkBodyA)
    {
        pkData->m_pkEntityA = pkBodyA->m_pkEntity;
        pkData->m_pkEntityB = pkBodyB ? pkBodyB->m_pkEntity : 0;
    }
    LinkObjectBase(kStream);
}


class Dispatcher
{
  public:
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
    virtual void Dispatch(void* p);
};

class Node1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};

class Mid
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Node1* m_18;
    Node1* m_1c;
};

class RefChainOwner
{
  public:
    int unk00;
    int unk04;
    Mid* m_08;
    void bhkSerializable_SaveBinary(Dispatcher* p);
    void DispatchChainNodes(Dispatcher* arg);
};

// Dispatches the m_0c payloads of the m_18 and m_1c nodes reached through m_08, then calls bhkSerializable_SaveBinary.
// @fnv 0x00c8aac0
// pdb: bhkBinaryAction::SaveBinary | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void RefChainOwner::DispatchChainNodes(Dispatcher* pDispatcher)
{
    Node1* n = (this && m_08) ? m_08->m_18 : 0;
    void* q;
    switch (n != 0)
    {
    case 0:
        q = 0;
        break;
    default:
        q = n->m_0c;
        break;
    }
    pDispatcher->Dispatch(q);

    Node1* k = (this && m_08) ? m_08->m_1c : 0;
    void* r;
    switch (k != 0)
    {
    case 0:
        r = 0;
        break;
    default:
        r = k->m_0c;
        break;
    }
    pDispatcher->Dispatch(r);

    bhkSerializable_SaveBinary(pDispatcher);
}

extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_01030bf4;
extern int DAT_010c44e4;
extern int DAT_010c485c;
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012681a0;

struct Base_00c8ae60
{
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00c87c30();
    Base_00c8ae60()
    {
        FUN_00c87c30();
    }
};
struct Object_00c8ae60 : Base_00c8ae60
{
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    Object_00c8ae60()
    {
        vtable = &DAT_01030bf4;
        unk0c = 0;
        unk10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
// Allocates and constructs a new Object_00c8ae60, returning the pointer.
// @fnv 0x00c8ae60
Object_00c8ae60* __cdecl FUN_00c8ae60()
{
    return new Object_00c8ae60;
}

// Forward a call to every child wrapper of this group's Havok object.

class C8B4D0Wrapper
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Apply(int iArg1, int iArg2);
};

struct C8B4D0Child
{
    int unk00;
    int unk04;
    C8B4D0Wrapper* m_pkWrapper;
};

struct C8B4D0Slot
{
    C8B4D0Child* m_pkChild;
    int unk04;
    int unk08;
    int unk0C;
};

class C8B4D0Counter
{
  public:
    virtual void Unk_00();
    virtual int GetCount();
};

struct C8B4D0HavokGroup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B4D0Counter m_kCounter;
    int unk14;
    C8B4D0Slot* m_pkSlots;
};

class C8B4D0Group
{
  public:
    int unk00;
    int unk04;
    C8B4D0HavokGroup* m_pkHavok;

    C8B4D0HavokGroup* GetHavok()
    {
        return this ? m_pkHavok : 0;
    }
    int GetChildCount()
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_kCounter.GetCount() : 0;
    }
    C8B4D0Child* GetChild(int i)
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_pkSlots[i].m_pkChild : 0;
    }

    void ApplyToChildren(int iArg1);
};

// Iterates all children of the group's havok data and calls Apply(iArg1, iArg2) on each child's wrapper if present.
// @f3 0x008fd1e0 (community match, verified in this file)
struct CWrap52
{
    virtual void U00();
    virtual void U01();
    virtual void U02();
    virtual void U03();
    virtual void U04();
    virtual void U05();
    virtual void U06();
    virtual void U07();
    virtual void U08();
    virtual void U09();
    virtual void U0A();
    virtual void U0B();
    virtual void U0C();
    virtual void U0D();
    virtual void U0E();
    virtual void U0F();
    virtual void U10();
    virtual void U11();
    virtual void U12();
    virtual void U13();
    virtual void U14();
    virtual void U15();
    virtual void U16();
    virtual void U17();
    virtual void U18();
    virtual void U19();
    virtual void U1A();
    virtual void U1B();
    virtual void U1C();
    virtual void U1D();
    virtual void U1E();
    virtual void U1F();
    virtual void U20();
    virtual void U21();
    virtual void U22();
    virtual void U23();
    virtual void U24();
    virtual void U25();
    virtual void U26();
    virtual void U27();
    virtual void U28();
    virtual void U29();
    virtual void U2A();
    virtual void U2B();
    virtual void U2C();
    virtual void U2D();
    virtual void U2E();
    virtual void U2F();
    virtual void U30();
    virtual void U31();
    virtual void U32();
    virtual void U33();
    virtual void Apply(int iArg1);
};

// pdb: bhkListShape::BuildDisplayGeometry | bhkListShape.obj | fnv360_0721_beta, objrun_sim, low, conflict (bridge: bhkListShape::CanShare)
// pdb params: apNode, arDefColor
void C8B4D0Group::ApplyToChildren(int iArg1)
{
    int iChildCount = GetChildCount();
    for (int i = 0; i < iChildCount; i++)
    {
        C8B4D0Child* pkChild = GetChild(i);
        C8B4D0Wrapper* pkWrapper = pkChild ? pkChild->m_pkWrapper : 0;
        if (pkWrapper)
            reinterpret_cast<CWrap52*>(pkWrapper)->Apply(iArg1);
    }
}


SpawnedAllocHolder* FUN_00c85750();

struct C8B8A0Alloc;
struct C8B8A0Array;
void FUN_00c908c0(C8B8A0Alloc* allocator, C8B8A0Array* arr, int capacity, int elemSize);
struct C8B8A0Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(C8B8A0Alloc& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(int));
        }
    }
    void _setSize(C8B8A0Alloc& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        SpawnedAllocHolder* router = FUN_00c85750();
        C8B8A0Alloc* allocator = (C8B8A0Alloc*)router->m_pAllocator;
        _setSize(*allocator, n);
    }
    void clear()
    {
        m_iElementCount = 0;
    }
};

struct C8B8A0Out
{
    int unk00;
    C8B8A0Array m_keys;
    C8B8A0Array m_iSlotIds;
};

struct C8B8A0Iface
{
    virtual void v00();
    virtual int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
    virtual int GetValue(void* it);
};

struct C8B8A0Entry
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
};

struct C8B8A0Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B8A0Iface m_iface;
    int unk14;
    C8B8A0Entry* m_entries;
};

struct MyObj
{
    int unk00;
    int unk04;
    C8B8A0Map* m_map;
    void FUN_00c84e20(void* out);
    void FillKeyValueArrays(C8B8A0Out* out);
};

// Resizes the output key and value arrays to the map's entry count, then fills them with each entry's key and interface value.
// @f3 0x008fcd80 (community match, verified in this file)
extern "C" void FUN_00901e90(struct F3Arr* arr, int newSize, int elemSize);
struct F3Arr
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(int));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(n);
        m_iElementCount = n;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
};
struct F3Obj
{
    void FUN_0096ab80(C8B8A0Out* out);
};
// pdb: bhkListShape::CopyCinfo | bhkListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void MyObj::FillKeyValueArrays(C8B8A0Out* out)
{
    ((F3Obj*)this)->FUN_0096ab80(out);
    C8B8A0Map* m;
    unsigned int n = (this && (m = m_map) != 0) ? m->m_iface.GetCount() : 0;
    out->m_keys.clear();
    F3Arr* keys = (F3Arr*)&out->m_keys;
    keys->SetSizeAndGrow(n);
    F3Arr* values = (F3Arr*)&out->m_iSlotIds;
    values->SetSizeAndGrow(n);
    void* it = (this && (m = m_map) != 0) ? m->m_iface.GetFirst() : 0;
    for (unsigned int i = 0; i < n; i++)
    {
        keys->m_data[i] = (this && (m = m_map) != 0) ? m->m_entries[i].m_key : 0;
        values->m_data[i] = (this && (m = m_map) != 0) ? m->m_iface.GetValue(it) : 0;
        it = (this && (m = m_map) != 0) ? m->m_iface.GetNext(it) : 0;
    }
}


extern __declspec(thread) int g_C8B9E0AllocTag;

struct C8B9E0AllocTagScope
{
    int m_iSaved;

    C8B9E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_C8B9E0AllocTag;
        g_C8B9E0AllocTag = aiAllocationTag;
    }
    ~C8B9E0AllocTagScope()
    {
        g_C8B9E0AllocTag = m_iSaved;
    }
};

class C8B9E0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern C8B9E0Heap g_kC8B9E0Heap;

template <class T> class C8B9E0Array
{
  public:
    C8B9E0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class C8B9E0Listener
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kC8B9E0Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    C8B9E0Listener() : m_pkOwnerManager(0)
    {}

    void* m_pkOwnerManager;
    C8B9E0Array<void*> m_kAdded;
    C8B9E0Array<void*> m_kRemoved;
};

struct ListAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* data, int bytes);
};
struct ShapeArray
{
    FUN_00c8b000_Item** data;
    int size;
    int capacity;
    ShapeArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ShapeArray()
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        ListAllocator* alloc = (ListAllocator*)holder->m_pAllocator;
        size = 0;
        if (!(capacity & 0x80000000))
        {
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        }
        data = 0;
        capacity = 0x80000000;
    }
    void swap(ShapeArray& other)
    {
        FUN_00c8b000_Item** oldData = data;
        data = other.data;
        other.data = oldData;
        int oldSize = size;
        size = other.size;
        other.size = oldSize;
        int oldCapacity = capacity;
        capacity = other.capacity;
        other.capacity = oldCapacity;
    }
};

// @fnv 0x00c8cdb0
// pdb: bhkStream::Endian | bhkRigidBody.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arRot
unsigned int* __cdecl SwapEndianBlocks(unsigned int* auiData)
{
    unsigned int* p = auiData + 2;
    int n = 3;
    do
    {
        p[-2] = _byteswap_ulong(p[-2]);
        p[-1] = _byteswap_ulong(p[-1]);
        p[0] = _byteswap_ulong(p[0]);
        p[1] = _byteswap_ulong(p[1]);
        p += 4;
    } while (--n != 0);
    return auiData;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

extern __declspec(thread) int g_iAllocTagC9A;

struct AllocTagScopeC9A
{
    int m_iSaved;

    AllocTagScopeC9A(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagC9A;
        g_iAllocTagC9A = aiAllocationTag;
    }
    ~AllocTagScopeC9A()
    {
        g_iAllocTagC9A = m_iSaved;
    }
};

class ObstacleDataC9A
{
  public:
    virtual ~ObstacleDataC9A();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class NiPointerC9A
{
  public:
    NiPointerC9A(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC9A()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

void __cdecl FreeNodeC9A(void* pvNode);

template <class T> class BSSimpleListC9A
{
  public:
    __declspec(noinline) void Remove(const T& kItem)
    {
        for (BSSimpleListC9A* pkNode = this; pkNode->m_pkNext; pkNode = pkNode->m_pkNext)
        {
            BSSimpleListC9A* pkNext = pkNode->m_pkNext;
            if (pkNext->m_item.m_pObject == kItem.m_pObject)
            {
                pkNode->m_pkNext = pkNext->m_pkNext;
                FreeNodeC9A(pkNext);
                return;
            }
        }
    }

    T m_item;
    BSSimpleListC9A* m_pkNext;
};

class ObstacleManagerC9A
{
  public:
    int unk00;
    int unk04;
    int unk08;
    BSSimpleListC9A<NiPointerC9A<ObstacleDataC9A> > m_kObstacles;

    void FUN_00c9a520(ObstacleDataC9A* pkData);
};

// Removes the given obstacle from m_kObstacles when pkData is non-null and its ref count is above zero.
// @f3 0x0090a750 (community match, verified in this file)
void ObstacleManagerC9A::FUN_00c9a520(ObstacleDataC9A* pkData)
{
    if (pkData && pkData->m_uiRefCount > 0)
    {
        m_kObstacles.Remove(NiPointerC9A<ObstacleDataC9A>(pkData));
    }
}


struct FUN_00c9abc0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    short unk0a;
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
    float unk50;
    float unk54;
    void __thiscall FUN_00c9abc0(int param2);
};

// If the flag bit in unk09 is set and unk50 is non-negative, writes unk50 and unk54 into param2 at offsets 0x18/0x1c and resets both to -1.0f.
// @fnv 0x00c9abc0
void __thiscall FUN_00c9abc0_cls::FUN_00c9abc0(int param2)
{
    if ((unk09 & 1) != 0 && unk50 >= 0.0f)
    {
        *(float*)(param2 + 0x18) = unk50;
        *(float*)(param2 + 0x1c) = unk54;
        unk50 = unk54 = -1.0f;
    }
    return;
}

struct FUN_00c9a6c0
{
    float time, value1, value2;
    FUN_00c9a6c0();
};
struct TargetFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct TargetBody
{
    int unk00, unk04, unk08, unk0c;
    TargetFlags flags;
};
struct TargetLink
{
    int unk00, unk04;
    TargetBody* body;
    unsigned int GetFlags() const
    {
        TargetFlags* info = body ? &body->flags : 0;
        return info ? info->flags : 0;
    }
};
struct TargetExtra
{
    int unk00, unk04, unk08, unk0c;
    TargetLink* link;
    int unk14;
    float start, end;
    float GetStart() const
    {
        return start;
    }
    float GetEnd() const
    {
        return end;
    }
};
struct ExtraList
{
    TargetExtra* FUN_00653290(int* type);
};
struct TargetController
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
    virtual void v35(float time);
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    float frequency, phase, start, end;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    LargeArray_c9ac00 keys;
    int unk50, unk54;
    unsigned int mode;
    void Reset();
    void FUN_00c9b1a0(FUN_00c9a6c0* key);
};
struct SceneNode;
struct SceneObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneNode* AsNode();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    ExtraList* extras;
    TargetController* FUN_00a5c570(int* type);
};
struct SceneNode : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity, childCount;
};
extern int DAT_01267e64;
extern const float DAT_01015f5c;

namespace fnv_00c9b470 {
struct LocalRTTI
{
};
extern LocalRTTI g_01267e64, g_012043f8, g_012681f0;
extern float DAT_01015f5c;
struct FUN_00c9a6c0
{
    float x, y, z;
    FUN_00c9a6c0();
};
}  // namespace fnv_00c9b470

struct Node253;
struct HavokObject253
{
    int unk00, unk04, unk08;
    Node253* owner;
};
struct PhysicsData253
{
    int unk00;
    HavokObject253* first;
    HavokObject253* second;
};
struct Map253
{
    bool FUN_00a53c30(Node253* key, void*& value);
};
struct CloneProcess253
{
    Map253* map;
};
struct Node253
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual Node253* Clone(void* process);
    int references;
    HavokObject253* object;
};
struct Owner253
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual PhysicsData253* GetData(bool* temporary);
    void bhkSerializable_CopyMembers(void* destination, void* process);
    void ClonePhysicsData(void* destination, void* process);
};
// @f3 0x008fb680 (community match, verified in this file)
// pdb: bhkBinaryAction::CopyMembers | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: pDest, arCloneData
void Owner253::ClonePhysicsData(void* destination, void* process)
{
    bool temporary;
    PhysicsData253* data = GetData(&temporary);
    Node253* first = data->first ? data->first->owner : 0;
    Node253* second = data->second ? data->second->owner : 0;
    CloneProcess253* context = static_cast<CloneProcess253*>(process);
    data->first = 0;
    data->second = 0;
    if (first)
    {
        if (context->map->FUN_00a53c30(first, process))
        {
            Node253* clone = static_cast<Node253*>(process);
            data->first = clone ? clone->object : 0;
        }
        if (second)
        {
            Node253* clone;
            if (context->map->FUN_00a53c30(second, process))
                clone = static_cast<Node253*>(process);
            else
                clone = second->Clone(context);
            data->second = clone ? clone->object : 0;
        }
    }
    bhkSerializable_CopyMembers(destination, context);
}


class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012043f8;
struct Param5380d0;
struct This5380d0
{
    bool FUN_005380d0(Param5380d0*);
};
void EnableConstraintsAndZeroArrays(void*, void*);
struct ControllerRTTI
{
    const char* name;
    const ControllerRTTI* base;
};
struct ControllerOwner
{
    unsigned int unkCur;
    unsigned int unkValue;
    unsigned int uNewnk;
    unsigned int unk00C;
    unsigned int uTmpnk;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk1E4;
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
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    This5380d0* manager;
};
struct ControllerObject
{
    virtual void slot();
    virtual void slotCur();
    virtual void slotValue();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual unsigned int GetType();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual ControllerOwner* GetOwner();
};
struct ControllerLink
{
    unsigned int unk, unk04;
    void* active;
    ControllerObject* object;
    void Process()
    {
        EnableConstraintsAndZeroArrays(this, active);
    }
    bool IsActive() const
    {
        return active != 0;
    }
    void Update()
    {
        if (IsActive())
            Process();
    }
    void ProcessIfActive()
    {
        if (active)
            EnableConstraintsAndZeroArrays(this, active);
    }
};
struct ControllerFallback
{
    ControllerObject* object;
};
struct IdleController
{
    virtual void slot();
    virtual void DeleteThis();
    virtual const ControllerRTTI* GetRTTI();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void HandleControllerData(This5380d0*);
    virtual void slot28();
    virtual void slot29();
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual ControllerLink* GetLink();
    long refs;
    ControllerLink* link;
    ControllerFallback* fallback;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    bool IsKindOfType(const ControllerRTTI* wanted)
    {
        const ControllerRTTI* type = GetRTTI();
        while (type)
        {
            if (type == wanted)
                return true;
            type = type->base;
        }
        return false;
    }
    void ProcessActive()
    {
        if (link->active)
            link->Process();
    }
    ControllerObject* GetObject()
    {
        return link ? link->object : (fallback ? fallback->object : 0);
    }
};
struct ControllerPtr
{
    IdleController* m_pObject;
    __forceinline ControllerPtr(IdleController* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~ControllerPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ControllerPtr& operator=(const ControllerPtr& other);
};
// Walks the node's controller collection, activating or removing controllers by type, then recurses into child nodes.
// @f3 0x008f1df0 (community match, verified in this file)
struct N2066_This5380d0
{
    bool FUN_004c8ee0(Param5380d0*);
};
void hkpResponseModifier_enableConstraint(void*, void*);
struct N2066_ControllerRTTI
{
    const char* name;
    const N2066_ControllerRTTI* base;
};
struct N2066_ControllerOwner {
 unsigned unk000;
 unsigned unk004;
 unsigned unk008;
 unsigned unk00c;
 unsigned unk010;
 unsigned unk014;
 unsigned unk018;
 unsigned unk01c;
 unsigned unk020;
 unsigned unk024;
 unsigned unk028;
 unsigned unk02c;
 unsigned unk030;
 unsigned unk034;
 unsigned unk038;
 unsigned unk03c;
 unsigned unk040;
 unsigned unk044;
 unsigned unk048;
 unsigned unk04c;
 unsigned unk050;
 unsigned unk054;
 unsigned unk058;
 unsigned unk05c;
 unsigned unk060;
 unsigned unk064;
 unsigned unk068;
 unsigned unk06c;
 unsigned unk070;
 unsigned unk074;
 unsigned unk078;
 unsigned unk07c;
 unsigned unk080;
 unsigned unk084;
 unsigned unk088;
 unsigned unk08c;
 unsigned unk090;
 unsigned unk094;
 unsigned unk098;
 unsigned unk09c;
 unsigned unk0a0;
 unsigned unk0a4;
 unsigned unk0a8;
 unsigned unk0ac;
 unsigned unk0b0;
 unsigned unk0b4;
 unsigned unk0b8;
 unsigned unk0bc;
 unsigned unk0c0;
 unsigned unk0c4;
 unsigned unk0c8;
 unsigned unk0cc;
 unsigned unk0d0;
 unsigned unk0d4;
 unsigned unk0d8;
 unsigned unk0dc;
 unsigned unk0e0;
 unsigned unk0e4;
 unsigned unk0e8;
 unsigned unk0ec;
 unsigned unk0f0;
 unsigned unk0f4;
 unsigned unk0f8;
 unsigned unk0fc;
 unsigned unk100;
 unsigned unk104;
 unsigned unk108;
 unsigned unk10c;
 unsigned unk110;
 unsigned unk114;
 unsigned unk118;
 unsigned unk11c;
 unsigned unk120;
 unsigned unk124;
 unsigned unk128;
 unsigned unk12c;
 unsigned unk130;
 unsigned unk134;
 unsigned unk138;
 unsigned unk13c;
 unsigned unk140;
 unsigned unk144;
 unsigned unk148;
 unsigned unk14c;
 unsigned unk150;
 unsigned unk154;
 unsigned unk158;
 unsigned unk15c;
 unsigned unk160;
 unsigned unk164;
 unsigned unk168;
 unsigned unk16c;
 unsigned unk170;
 unsigned unk174;
 unsigned unk178;
 unsigned unk17c;
 unsigned unk180;
 unsigned unk184;
 unsigned unk188;
 unsigned unk18c;
 unsigned unk190;
 unsigned unk194;
 unsigned unk198;
 unsigned unk19c;
 unsigned unk1a0;
 unsigned unk1a4;
 unsigned unk1a8;
 unsigned unk1ac;
 unsigned unk1b0;
 unsigned unk1b4;
 unsigned unk1b8;
 unsigned unk1bc;
 unsigned unk1c0;
 unsigned unk1c4;
 unsigned unk1c8;
 unsigned unk1cc;
 unsigned unk1d0;
 unsigned unk1d4;
 unsigned unk1d8;
 unsigned unk1dc;
 unsigned unk1e0;
 unsigned unk1e4;
 unsigned unk1e8;
 unsigned unk1ec;
 unsigned unk1f0;
 unsigned unk1f4;
 unsigned unk1f8;
 unsigned unk1fc;
 unsigned unk200;
 unsigned unk204;
 unsigned unk208;
 unsigned unk20c;
 unsigned unk210;
 unsigned unk214;
 unsigned unk218;
 unsigned unk21c;
 unsigned unk220;
 unsigned unk224;
 unsigned unk228;
 unsigned unk22c;
 unsigned unk230;
 unsigned unk234;
 unsigned unk238;
 unsigned unk23c;
 unsigned unk240;
 unsigned unk244;
 unsigned unk248;
 unsigned unk24c;
 unsigned unk250;
 unsigned unk254;
 unsigned unk258;
 unsigned unk25c;
 unsigned unk260;
 unsigned unk264;
 unsigned unk268;
 unsigned unk26c;
 unsigned unk270;
 unsigned unk274;
 unsigned unk278;
 unsigned unk27c;
 unsigned unk280;
 unsigned unk284;
 unsigned unk288;
 unsigned unk28c;
 unsigned unk290;
 unsigned unk294;
 unsigned unk298;
 unsigned unk29c;
 unsigned unk2a0;
 unsigned unk2a4;
 unsigned unk2a8;
 unsigned unk2ac;
 unsigned unk2b0;
 unsigned unk2b4;
 unsigned unk2b8;
 unsigned unk2bc;
 unsigned unk2c0;
 unsigned unk2c4;
 unsigned unk2c8;
 unsigned unk2cc;
 unsigned unk2d0;
 unsigned unk2d4;
 unsigned unk2d8;
 unsigned unk2dc;
 unsigned unk2e0;
 unsigned unk2e4;
 unsigned unk2e8;
 unsigned unk2ec;
 unsigned unk2f0;
 unsigned unk2f4;
 unsigned unk2f8;
 unsigned unk2fc;
 unsigned unk300;
 unsigned unk304;
 unsigned unk308;
 unsigned unk30c;
 N2066_This5380d0* manager;
};
struct N2066_ControllerObject {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual unsigned GetType();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
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
 virtual N2066_ControllerOwner* GetOwner();
};
struct N2066_ControllerLink
{
    unsigned int unk, unk04;
    void* active;
    N2066_ControllerObject* object;
    void Process()
    {
        hkpResponseModifier_enableConstraint(this, active);
    }
    bool IsActive() const
    {
        return active != 0;
    }
    void Update()
    {
        if (IsActive())
            Process();
    }
    void ProcessIfActive()
    {
        if (active)
            hkpResponseModifier_enableConstraint(this, active);
    }
};
struct N2066_ControllerFallback
{
    N2066_ControllerObject* object;
};
struct N2066_IdleController
{
    virtual void slot();
    virtual void DeleteThis();
    virtual const N2066_ControllerRTTI* GetRTTI();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void HandleControllerData(N2066_This5380d0*);
    virtual void slot28();
    virtual void slot29();
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
    virtual void slot30();
    virtual void slot31();
    virtual N2066_ControllerLink* GetLink();
    long refs;
    N2066_ControllerLink* link;
    N2066_ControllerFallback* fallback;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    bool IsKindOfType(const N2066_ControllerRTTI* wanted)
    {
        const N2066_ControllerRTTI* type = GetRTTI();
        while (type)
        {
            if (type == wanted)
                return true;
            type = type->base;
        }
        return false;
    }
    void ProcessActive()
    {
        if (link->active)
            link->Process();
    }
    N2066_ControllerObject* GetObject()
    {
        return link ? link->object : (fallback ? fallback->object : 0);
    }
};
struct N2066_ControllerPtr
{
    N2066_IdleController* m_pObject;
    __forceinline N2066_ControllerPtr(N2066_IdleController* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~N2066_ControllerPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    N2066_ControllerPtr& operator=(const N2066_ControllerPtr& other);
};
struct N2066_ControllerList
{
    N2066_ControllerPtr item;
    N2066_ControllerList* next;
    ~N2066_ControllerList();
    void FUN_004c25a0(const N2066_ControllerPtr& key);
};
void N2066_ControllerList::FUN_004c25a0(const N2066_ControllerPtr& key)
{
    if (!key.m_pObject)
        return;
    if (!next && !item.m_pObject)
        return;
    N2066_ControllerList* prev = this;
    N2066_ControllerList* cur = this;
    while (cur->item.m_pObject != key.m_pObject)
    {
        prev = cur;
        cur = cur->next;
        if (!cur)
            return;
    }
    if (cur == this)
    {
        N2066_ControllerList* pNext = next;
        if (pNext)
        {
            next = pNext->next;
            item = pNext->item;
            pNext->next = 0;
            pNext->~N2066_ControllerList();
            _g_memoryManager.Deallocate(pNext);
        }
        else if (item.m_pObject)
        {
            item.m_pObject->DecRefCount();
            item.m_pObject = 0;
        }
    }
    else
    {
        prev->next = cur->next;
        cur->next = 0;
        cur->~N2066_ControllerList();
        _g_memoryManager.Deallocate(cur);
    }
}
struct N2066_ControllerCollection
{
    unsigned int unk, unk04, unk08, unk0C, unk10;
    N2066_ControllerList head;
};
struct N2066_ControllerExtra
{
    unsigned int unk, unk04, unk08, unk0C;
    N2066_ControllerCollection* collection;
};

extern N2066_ControllerRTTI DAT_010f31fc;
N2066_ControllerExtra* FUN_00424fe0(WalkNode_cls*);
// pdb: bhkUtilFunctions::RemoveSpringConstraints | bhkUtilFunctions.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apObject
void ProcessControllerList(WalkNode_cls* node)
{
    if (node)
    {
        {
            N2066_ControllerExtra* extra = FUN_00424fe0(node);
            if (extra && extra->collection)
            {
                N2066_ControllerList* entry = &extra->collection->head;
                while (entry && entry->item.m_pObject)
                {
                    N2066_IdleController* original = entry->item.m_pObject;
                    N2066_IdleController* controller =
                        original->IsKindOfType(&DAT_010f31fc) ? original : 0;
                    if (controller)
                    {
                        switch (controller->GetObject()->GetType())
                        {
                        case 2:
                        case 7:
                        case 13:
                            if (!controller->link->active)
                            {
                                N2066_ControllerLink* link = controller->GetLink();
                                N2066_ControllerObject* object = link ? link->object : 0;
                                N2066_ControllerOwner* owner = object->GetOwner();
                                controller->HandleControllerData(owner ? owner->manager : 0);
                            }
                            if (controller->link->IsActive())
                                hkpResponseModifier_enableConstraint(controller->link, controller->link->active);
                            break;
                        case 8: {
                            N2066_ControllerLink* link = controller->GetLink();
                            N2066_ControllerObject* object = link ? link->object : 0;
                            if (object)
                            {
                                N2066_ControllerOwner* owner = object->GetOwner();
                                N2066_This5380d0* manager = owner ? owner->manager : 0;
                                manager->FUN_004c8ee0(reinterpret_cast<Param5380d0*>(controller));
                            }
                            N2066_ControllerPtr spKey(controller);
                            entry->FUN_004c25a0(spKey);
                        }
                        break;
                        }
                    }
                    entry = entry->next;
                }
            }
        }
        WalkNode_cls* children = node->v03();
        if (children)
        {
            for (unsigned int i = 0; i < children->m_a6; ++i)
                ProcessControllerList(children->m_a0[i]);
        }
    }
}


struct C817D0Node
{
    void UpdateWorldLoc();
};

struct C817D0RefNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags;
};

struct C817D0TlsBlock
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
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int m_2c0;
};

__declspec(thread) C817D0TlsBlock g_c817d0Tls;

struct C817D0Cls
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfA0();
    virtual void vfA4();

    unsigned int unk04;
    C817D0Node* m_08;
    unsigned short m_0c;
    unsigned short unk0e;
    C817D0RefNode* m_10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    void __thiscall UpdateNodeState(int);
    void FUN_00c65b00();
};

// @f3 0x008f3460 (community match, verified in this file)
extern __declspec(thread) int DAT_tls_0x2a0;

struct FUN_008d2120_holder
{
    int __thiscall FUN_008d2120();
};
// pdb: bhkBlendCollisionObject::UpdateWorldData | bhkBlendCollisionObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: __formal
void C817D0Cls::UpdateNodeState(int)
{
    int state = DAT_tls_0x2a0;
    if (state == 3)
        return;
    if (m_14 != 0)
    {
        if (m_08 != 0)
            m_08->UpdateWorldLoc();
        m_14 = 0;
        return;
    }
    C817D0RefNode* pRefNode = m_10;
    if (pRefNode == 0 || (bool)((pRefNode->m_flags >> 6) & 1) == 0)
    {
        if ((bool)((m_0c >> 6) & 1) != 0)
        {
            if (state != 2)
            {
                ((FUN_008d2120_holder*)this)->FUN_008d2120();
                m_0c = (unsigned short)(m_0c & 0xffbf);
                return;
            }
        }
        else if ((bool)(m_0c & 1) != 0)
        {
            if (pRefNode != 0 || m_18 < 1.0f || m_20 == 1)
                vfA4();
            return;
        }
    }
    if (m_08 != 0)
        m_08->UpdateWorldLoc();
}


void __cdecl FUN_00c87670(int* param_1, unsigned int param_2);

// @fnv 0x00c84cc0
// pdb: NiLinRotKey::FillDerivedVals | NiLinRotKey.obj | fnv360_0822_retail, objrun_prop, high
// pdb params: pkKeys, uiNumKeys, ucSize
void __cdecl FUN_00c84cc0(int* param_1, unsigned int param_2)
{
    FUN_00c87670(param_1, param_2);
}

// Fallout: New Vegas — FUN_00c85620
// __cdecl aligned-allocation helper: requests an over-sized block from the
// heap object's virtual allocator, aligns the returned pointer up to the
// requested alignment, and stores a small header immediately below the
// aligned pointer: {owner, end, offset-to-raw}.

// @fnv 0x00c85800
// pdb: NiStepRotKey::Equal | NiStepRotKey.obj | tesv_win, caller_sim, low
void __cdecl FUN_00c85800()
{
    extern void __cdecl FUN_00ba87d0();
    FUN_00ba87d0();
}

extern void __cdecl FUN_00a5d3a0();
extern int DAT_010c5b54;
struct FUN_00c87c30_t
{
    int* pVTable;
    int unk04;
    int unk08;
    FUN_00c87c30_t* FUN_00c87c30();
};
// @fnv 0x00c87c30
// pdb: NiAccumulator::NiAccumulator | NiAccumulator.obj | fnv360_0822_retail, call_seq, high
FUN_00c87c30_t* FUN_00c87c30_t::FUN_00c87c30()
{
    FUN_00a5d3a0();
    pVTable = &DAT_010c5b54;
    unk08 = 0;
    return this;
}

struct FUN_00c87c50_cls
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
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot36(bool b);
    int unk04;
    NiObject* unk08;
    void FUN_00c87c50(NiObject* arg);
};
// @fnv 0x00c87c50
// pdb: bhkRefObject::SethkObject | bhkRefObject.obj | fnv360_0822_retail, caller, medium
// pdb params: aphkObject
void FUN_00c87c50_cls::FUN_00c87c50(NiObject* apObject)
{
    if (unk08 != apObject)
    {
        slot36(false);
        unk08 = apObject;
        slot36(true);
    }
}

extern int DAT_01268160;

// @fnv 0x00c87c80
// pdb: bhkNiCollisionObject::GetRTTI | bhkNiCollisionObject.obj | fnv360_0822_retail, objrun, medium
int* __cdecl FUN_00c87c80()
{
    return &DAT_01268160;
}

extern __declspec(thread) int DAT_tls_field;
struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard() : previous(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~MemoryContextGuard()
    {
        DAT_tls_field = previous;
    }
};
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct FUN_00a5d3d0
{
    virtual ~FUN_00a5d3d0();
};
struct FUN_00c87d20 : FUN_00a5d3d0
{
    int m_field04;
    FUN_00c905b0_Class* m_ref;
    virtual ~FUN_00c87d20();
};
// Destructor that enters a memory context and, if m_ref is set, calls FUN_00c905b0 on it.
// @fnv 0x00c87d20
FUN_00c87d20::~FUN_00c87d20()
{
    MemoryContextGuard guard;
    if (m_ref)
        m_ref->FUN_00c905b0();
}

struct FUN_00c87dc0_class
{
    void __thiscall FUN_00c87d20();
    unsigned int __thiscall FUN_00c87dc0(unsigned char param_2);
};

extern "C" void __cdecl operator delete(void*, unsigned int);

// Calls FUN_00c87d20, then deletes this (0xC bytes) when bit 0 of param_2 is set, and returns this as an unsigned int.
// @fnv 0x00c87dc0
// pdb: bhkRefObject::`scalar deleting destructor' | bhkRefObject.obj | fnv360_0822_debug, caller_sim, low
unsigned int __thiscall FUN_00c87dc0_class::FUN_00c87dc0(unsigned char param_2)
{
    FUN_00c87d20();
    if ((param_2 & 1) != 0)
    {
        ::operator delete(this, 0xC);
    }
    return reinterpret_cast<unsigned int>(this);
}

namespace fnv_00c87de0 {
extern const char* DAT_01268160;
char* __cdecl FUN_00a7d330(const char*);

struct StrArr;

}  // namespace fnv_00c87de0

void __cdecl DispatchToTarget();
// @fnv 0x00c87fa0
// pdb: TESReactionForm::ClearDataComponent | TESReactionForm.obj | fnv360_0822_retail, vtable, medium
void __cdecl FUN_00c87fa0()
{
    DispatchToTarget();
}

void FUN_00c6b760();

// @fnv 0x00c87fb0
void FUN_00c87fb0()
{
    FUN_00c6b760();
}

struct Elem_c891
{
    int unk00;
    int unk04;
    Elem_c891* unk08;
    Elem_c891* getE() const
    {
        return unk08;
    }
};
struct Holder_c891
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Elem_c891* elem10;
};
struct Heap_c891
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};
Holder_c891* __cdecl FUN_00c802d0(int);
struct Arr_c891
{
    Elem_c891** m_data;
    int m_iElementCount;
    int m_cap;
    Arr_c891() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    Elem_c891*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    ~Arr_c891()
    {
        SpawnedAllocHolder* r = FUN_00c85750();
        Heap_c891* heap = (Heap_c891*)r->m_pAllocator;
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap->ReturnMemory(m_data, (m_cap & 0x3fffffff) * 4);
    }
};

extern void FUN_00c87650();

// @fnv 0x00c896b0
// pdb: NiBoolInterpController::IsEqual | NiBoolInterpController.obj | fnv360_0822_retail, caller_sim, high
// pdb params: pkObject
void FUN_00c896b0()
{
    FUN_00c87650();
}

struct AttachObject;
struct AttachData;
struct AttachObject
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
    virtual AttachData* GetData();
    virtual void v38();
    virtual void Add(AttachObject*);
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
    virtual void Set(AttachObject*);
    virtual AttachObject* GetTarget();
    virtual AttachData* GetConstraint();
    int unk04;
    AttachData* owner;
    int unk0c;
    unsigned int flags;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    AttachData* data24;
    int unk28;
    unsigned int id;
    void FUN_00a29680();
    bool AddOrRemoveConstraint(AttachObject* body, bool add);
};
struct AttachData
{
    unsigned char HasObjectOfType()
    {
        return object08 != 0;
    }
    int unk00;
    int unk04;
    AttachObject* object08;
    AttachObject* object0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AttachObject* object24;
    int unk28;
    unsigned int id;
};
struct DiagFlag
{
    bool enabled;
    DiagFlag(bool value) : enabled(value)
    {}
    DiagFlag(const DiagFlag& other) : enabled(other.enabled)
    {}
};
struct DiagString
{
    int a, b, c;
    DiagString(char*, unsigned int, DiagFlag);
    void Append(const char*);
    ~DiagString();
};
struct DiagSink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int, unsigned int, char*, const char*, int);
};
extern DiagSink* diagnosticSink;
// Adds or removes a constraint body on the target, fixing the constraint id and reporting when the target bodies are not yet in the world.
// @f3 0x008fc200 (community match, verified in this file)
namespace Isolated8fc200 {
struct AttachObject;
struct AttachData;
struct AttachObject
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
    virtual AttachData* GetConstraint();
    virtual void Add(AttachObject*);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void Set(AttachObject*);
    virtual AttachData* GetData();
    virtual AttachObject* GetTarget();
    int unk04;
    AttachData* owner;
    int unk0c;
    unsigned int flags;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int count;
    AttachData* data24;
    int unk28;
    unsigned int id;
    bool OwnerHasObject();
    __forceinline bool Run(AttachObject* body, bool add);
};

struct AttachData
{
    unsigned char HasObjectOfType()
    {
        return object08 != 0;
    }
    int unk00;
    int unk04;
    AttachObject* object08;
    AttachObject* object0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AttachObject* object24;
    int unk28;
    unsigned int id;
};

extern const char str_00e346b0[];
extern const char str_00e3462c[];

inline bool AttachObject::OwnerHasObject() { if (!owner) return false; unsigned char u = owner->HasObjectOfType(); return u != 0; }

__forceinline bool AttachObject::Run(AttachObject* body, bool add)
{
    bool result = false;
    AttachData* constraint = reinterpret_cast<AttachData*>(GetTarget());
    if (add)
    {
        if (constraint && constraint->object0c)
        {
            AttachObject* target = constraint->object0c;
            if (!target->OwnerHasObject())
            {
                unsigned int hi = GetData()->id; unsigned int lo = constraint->id & 0xffff; constraint->id = (hi & 0xffff0000u) | lo;
            }
            if (body->count <= 0)
            {
                target->Add(body);
                if (!target->GetConstraint() && !(target->flags & 0x30))
                {
                    {
                        char buffer[512];
                        DiagString message(buffer, 512, DiagFlag(true));
                        message.Append(str_00e346b0);
                        diagnosticSink->Report(1, 0x234f24fc, buffer, str_00e3462c, 786);
                    }
                    target->Set(body);
                }
            }
        }
        else
        {
            result = true;
            AttachData* data = body ? body->GetConstraint() : 0;
            AttachObject* object = data ? data->object24 : 0;
            Set(object);
        }
    }
    else
    {
        AttachData* data = body ? body->GetConstraint() : 0;
        AttachObject* object = data ? data->object24 : 0;
        if (constraint == (AttachData*)object)
            Set(0);
    }
    return result;
}


}

// pdb: bhkConstraint::ProcessEntityB | bhkConstraint.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apWorld, abAdd
bool AttachObject::AddOrRemoveConstraint(AttachObject* body, bool add)
{
 return reinterpret_cast<Isolated8fc200::AttachObject*>(this)->Run(reinterpret_cast<Isolated8fc200::AttachObject*>(body),add);
}


struct Alloc8b_c8b090
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
    virtual void ReleaseBlock(void* p, int size);
};

extern __declspec(thread) int g_hkTlsScopeValue;

struct TlsScope_c8b090
{
    int m_old;
    TlsScope_c8b090(int v)
    {
        m_old = g_hkTlsScopeValue;
        g_hkTlsScopeValue = v;
    }
    ~TlsScope_c8b090()
    {
        g_hkTlsScopeValue = m_old;
    }
};

struct hkRefObj_c8b090
{
    virtual void vf0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int size)
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        hkRefObj_c8b090* b = (hkRefObj_c8b090*)alloc->AllocateMemoryBlock(static_cast<int>(size));
        b->m_usMemSizeAndFlags = (unsigned short)size;
        return b;
    }
    static void operator delete(void* p, unsigned int size)
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        alloc->ReleaseBlock(p, static_cast<int>(size));
    }
    void removeReference();
};

struct hkShapeContainer_c8b090
{
    virtual void v0();
    virtual int GetNumChildShapes();
    virtual int GetFirstKey();
    virtual int GetNextShapeKey(int key);
};

struct hkShapeBase_c8b090 : hkRefObj_c8b090
{
    int unk08;
    int unk0c;
};

struct hkListShape_c8b090 : hkShapeBase_c8b090, hkShapeContainer_c8b090
{
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
    hkListShape_c8b090(void* shapes, unsigned int count, int policy);
    void setChild(int key, int value);
};

struct ListInfo_c8b090
{
    int unk00;
    void* m_shapes;
    unsigned int m_numShapes;
    int unk0c;
    int* m_iSlotIds;
    unsigned int m_uiArrayCount;
};

struct bhkListOwner_c8b090
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
    virtual void SetShape(hkListShape_c8b090* shape);
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
    virtual void SetListInfo(ListInfo_c8b090* info);
    void SetListShape(ListInfo_c8b090* info);
};

// @f3 0x008fceb0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;

namespace n8fceb0 {
struct hkThreadMemory {
    void* FUN_008f6d30(int nbytes, int memClass);
    void Deallocate(void* p, int nbytes, int memClass);
};
struct RefObj {
    virtual void Destroy(int flags);
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    static void* operator new(unsigned int size)
    {
        hkThreadMemory* mem = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
        RefObj* b = (RefObj*)mem->FUN_008f6d30(size, 0x27);
        b->m_memSizeAndFlags = (unsigned short)size;
        return b;
    }
    static void operator delete(void* p, unsigned int size)
    {
        hkThreadMemory* mem = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
        mem->Deallocate(p, size, 0x27);
    }
    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            if (--m_referenceCount == 0)
                Destroy(1);
        }
    }
};
struct Container {
    virtual void v0();
    virtual int GetNumChildShapes();
    virtual int GetFirstKey();
    virtual int GetNextShapeKey(int key);
};
struct FUN_0097dab0 : RefObj {
    int unk08;
    int unk0c;
    Container container;
    int unk14[0x17];
    FUN_0097dab0(void* shapes, unsigned int count);
    void FUN_0097ad10(int key, int value);
};
}
// pdb: bhkListShape::Init | bhkListShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void bhkListOwner_c8b090::SetListShape(ListInfo_c8b090* info)
{
    using namespace n8fceb0;
    if (!info)
        return;
    void* shapes = info->m_shapes;
    unsigned int count = info->m_numShapes;
    FUN_0097dab0* shape = new FUN_0097dab0(shapes, count);
    int key = shape->container.GetFirstKey();
    if (!(count < info->m_uiArrayCount))
        count = info->m_uiArrayCount;
    for (unsigned int i = 0; i < count; i++)
    {
        shape->FUN_0097ad10(key, info->m_iSlotIds[i]);
        shape->container.GetNextShapeKey(key);
    }
    SetShape((hkListShape_c8b090*)shape);
    shape->removeReference();
    SetListInfo(info);
}


struct C8B540Selected;

class C8B540Selected
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual int GetResult(int iArg);
};

struct C8B540Group : C8B4D0Group
{
    int unk0C;
    int m_iFallback;

    int GetSelectedResult(int iArg);
};

// Iterates children, calls Select on each child's wrapper and returns the first non-0x24 GetResult result, else m_iFallback masked with 0x1f.
// @f3 0x008fd250 (community match, verified in this file)
struct C8B540SelectedF3
{
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();
    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();
    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();
    virtual void s078();
    virtual void s07c();
    virtual void s080();
    virtual void s084();
    virtual void s088();
    virtual void s08c();
    virtual void s090();
    virtual void s094();
    virtual void s098();
    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();
    virtual void s0b0();
    virtual void s0b4();
    virtual void s0b8();
    virtual void s0bc();
    virtual void s0c0();
    virtual void s0c4();
    virtual void s0c8();
    virtual void s0cc();
    virtual void s0d0();
    virtual void s0d4();
    virtual void s0d8();
    virtual int GetResult(int iArg);
};
struct C8B540WrapperF3
{
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();
    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();
    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();
    virtual void s078();
    virtual void s07c();
    virtual void s080();
    virtual void s084();
    virtual void s088();
    virtual void s08c();
    virtual void s090();
    virtual void s094();
    virtual void s098();
    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();
    virtual void s0b0();
    virtual void s0b4();
    virtual void s0b8();
    virtual void s0bc();
    virtual void s0c0();
    virtual void s0c4();
    virtual C8B540SelectedF3* Select();
};
// pdb: bhkListShape::RembhkShapeRef | bhkListShape.obj | fnv360_0822_retail, objrun_sim, low
int C8B540Group::GetSelectedResult(int iArg)
{
    int result = 0x20;
    unsigned int count = GetChildCount();
    for (unsigned int i = 0; i < count; i++)
    {
        if (result != 0x20)
            break;

        C8B4D0Child* pkChild = GetChild(i);
        C8B540WrapperF3* pkWrapper = pkChild ? (C8B540WrapperF3*)pkChild->m_pkWrapper : 0;
        C8B540SelectedF3* pkSelected = pkWrapper->Select();
        if (pkSelected)
            result = pkSelected->GetResult(iArg);
    }

    if (result == 0x20)
        result = m_iFallback & 0x1f;

    return result;
}


extern int DAT_012681cc;

// @fnv 0x00c8ff70
int __cdecl FUN_00c8ff70()
{
    return reinterpret_cast<int>(&DAT_012681cc);
}

void __cdecl FUN_00c818f0(int, int);

// @fnv 0x00c8ff80
// pdb: NiPSysResetOnLoopCtlr::RegisterStreamables | NiPSysResetOnLoopCtlr.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void __cdecl FUN_00c8ff80(int param_1, int param_2)
{
    FUN_00c818f0(param_1, param_2);
}

struct FUN_00c819a0_holder
{
    static void InitFromFlags();
};

// @fnv 0x00c8ff90
// pdb: BSMultiTargetTreadTransfController::LinkObject | BSMultiTargetTreadTransfController.obj | fnv360_0822_retail, call_seq, high
// pdb params: arStream
void __cdecl FUN_00c8ff90()
{
    FUN_00c819a0_holder::InitFromFlags();
}

extern "C" void __cdecl FUN_00cb7610();

// @fnv 0x00c8ffa0
// pdb: BSMultiTargetTreadTransfController::LoadBinary | BSMultiTargetTreadTransfController.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void __cdecl FUN_00c8ffa0()
{
    FUN_00cb7610();
}

extern void __cdecl FUN_00c819f0();

// @fnv 0x00c8ffb0
// pdb: BSMultiTargetTreadTransfController::RegisterStreamables | BSMultiTargetTreadTransfController.obj | fnv360_0822_retail, caller_sim, high
// pdb params: arStream
void __cdecl FUN_00c8ffb0()
{
    FUN_00c819f0();
}

bool __cdecl FUN_00c815b0(C815B0Constraint* pkOther);

// @fnv 0x00c8ffc0
bool __cdecl FUN_00c8ffc0(C815B0Constraint* pkOther)
{
    return FUN_00c815b0(pkOther);
}

struct C90160Matrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};
extern const C90160Matrix DAT_011a9448;

class C90160Derived : public BC88760Base
{
  public:
    C90160Matrix matrix;
    C90160Derived() : matrix(DAT_011a9448)
    {}
    virtual ~C90160Derived();

    void FUN_00c81580(C90160Derived* destination, BC88760CloningProcess& cloning);
    C90160Derived* FUN_00c90160(BC88760CloningProcess& cloning);
};

// @f3 0x00901c40 (community match, verified in this file)
// pdb: bhkBlendCollisionObjectAddRotation::CreateClone | bhkBlendCollisionObjectAddRotation.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
C90160Derived* C90160Derived::FUN_00c90160(BC88760CloningProcess& cloning)
{
    C90160Derived* clone = new C90160Derived();
    FUN_00c81580(clone, cloning);
    clone->matrix = matrix;
    return clone;
}


// 0x00c90350  xor eax,eax; ret
// @fnv 0x00c90350
// pdb: hkpAabbPhantom::getMotionState | bhkAvoidBox.obj | fnv360_0822_debug, vtable_prefix, medium
int __cdecl FUN_00c90350()
{
    return 0;
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);

// @f3 0x00464c90 (community match, verified in this file)
namespace f3m_00464c90 {
namespace f3m_00464c90 {

void __stdcall FUN_006ff040(int code, void* p);

struct C118 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void* m_18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30;
    unsigned int m_34;
};

struct Owner {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114;
    C118* m_118;

    bool FUN_00463650();
    bool FUN_00464c90(unsigned int value);
};

// pdb: Animation::SpecialIdlePlay | Animation.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apActor
bool Owner::FUN_00464c90(unsigned int value)
{
    if (FUN_00463650())
    {
        m_118->m_34 = value;
        FUN_006ff040(0xd, m_118->m_18);
        return true;
    }
    return false;
}

}
}   // namespace f3m_00464c90


// @fnv 0x00c90e30
int __stdcall FUN_00c90e30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
    return 0;
}

struct FUN_00c92b00_Entry
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    int value48;
    int value4c;
};

struct FUN_00c92b00_Class
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    FUN_00c92b00_Entry** entries28;
    int count2c;
    int unk30;
    FUN_00c92b00_Entry** entries34;
    int count38;

    void FUN_00c92a80(int first, int second);
    void ApplyEntries();
};

// Calls FUN_00c92a80 with value48 and value4c for every entry in entries28 (count2c) and entries34 (count38).
// @fnv 0x00c92b00
// pdb: hkpWorld::findInitialContactPointsOfAllEntities | hkpWorld.obj | tesv_win, objrun_open, low
void FUN_00c92b00_Class::ApplyEntries()
{
    for (int i = 0; i < count2c; ++i)
    {
        FUN_00c92b00_Entry* entry = entries28[i];
        FUN_00c92a80(entry->value48, entry->value4c);
    }
    for (int i = 0; i < count38; ++i)
    {
        FUN_00c92b00_Entry* entry = entries34[i];
        FUN_00c92a80(entry->value48, entry->value4c);
    }
}

struct FUN_00c9a620_Obj
{
    float unk00;
    float unk04;
    float unk08;

    int __thiscall FUN_00c9a620(float* other);
};

// Returns 1 if the three floats at unk00, unk04 and unk08 all equal the corresponding elements of other, otherwise 0.
// @fnv 0x00c9a620
// pdb: BSSimpleArray<NiPoint3,1024>::DefaultEqualFunction<NiPoint3> | BGSAutoWater.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aOne, aTwo
int __thiscall FUN_00c9a620_Obj::FUN_00c9a620(float* other)
{
    if (unk00 == other[0] && unk04 == other[1] && unk08 == other[2])
    {
        return 1;
    }
    return 0;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

class RefObject0AA0
{
  public:
    virtual ~RefObject0AA0();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    long m_uiRefCount;
};

template <class T> class NiPointer0AA0
{
  public:
    NiPointer0AA0(const NiPointer0AA0& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer0AA0& operator=(const NiPointer0AA0& ptr);
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct MemoryManager0AA0
{
    void* Allocate(unsigned int uiSize);
};
extern MemoryManager0AA0 g_kMemoryManager0AA0;

class ListNode0AA0
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return g_kMemoryManager0AA0.Allocate(uiSize);
    }
    ListNode0AA0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject) : m_pReferencedObject(spRetainedObject)
    {
        m_pkNext = 0;
    }
    void FUN_00c80aa0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject);

    NiPointer0AA0<RefObject0AA0> m_pReferencedObject;
    ListNode0AA0* m_pkNext;
};

// Appends spRetainedObject to the tail of the linked list, reusing the last node's slot if it is empty.
// @fnv 0x00c80aa0
// pdb: BSSimpleList<NiPointer<BSTempEffect> >::AddTail | BSTempEffectSimpleDecal.obj | fnv360_0822_retail, call_gap, low
// pdb params: item
void ListNode0AA0::FUN_00c80aa0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject)
{
    if (!spRetainedObject)
        return;
    ListNode0AA0* pkNode = this;
    while (pkNode->m_pkNext)
        pkNode = pkNode->m_pkNext;
    if (pkNode->m_pReferencedObject)
        pkNode->m_pkNext = new ListNode0AA0(spRetainedObject);
    else
        pkNode->m_pReferencedObject = spRetainedObject;
}

struct FUN_00c819f0_stream
{
    void* vtable;
    unsigned int m_04;
    unsigned int unk08;
    unsigned int(__cdecl* m_0c)(FUN_00c819f0_stream* self, void* buffer, unsigned int size, unsigned int* sizes,
                                unsigned int count);
};

class FUN_00c819f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int m_1c;
    void Callee65820(int a1);
    void FUN_00c819f0(int a1);
};

// Calls Callee65820, then twice calls the m_0c callback of the stream at a1+0x250 on m_18 and m_1c (4 bytes each), adding each result to the stream's m_04.
// @fnv 0x00c819f0
// pdb: bhkBlendCollisionObject::SaveBinary | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void FUN_00c819f0_cls::FUN_00c819f0(int a1)
{
    char* obj = (char*)a1;
    FUN_00c819f0_stream* __restrict o;
    unsigned int(__cdecl * fn)(FUN_00c819f0_stream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int* cnt = (unsigned int*)&a1;
    Callee65820(a1);
    o = *(FUN_00c819f0_stream**)(obj + 0x250);

    o->m_04 += o->m_0c((a1 = 4, o), &m_18, 4, cnt, 1);
    o = *(FUN_00c819f0_stream**)(obj + 0x250);

    o->m_04 += o->m_0c((a1 = 4, o), &m_1c, 4, cnt, 1);
}

struct MeshMemoryScope
{
    int saved;
    MeshMemoryScope()
    {
        saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 16;
    }
    ~MeshMemoryScope()
    {
        g_tlsBlock.m_2b4 = saved;
    }
};
inline void* __cdecl operator new[](unsigned int size)
{
    return DAT_011f6238.FUN_00aa3e40(size);
}
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};

struct ObjectController
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
    virtual void* v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();

    void* unk04;
    void* m_pObject;
    void SetObject(void* replacement);
    void FUN_00c87c50(void* replacement);
};

// If replacement differs from m_pObject, calls v28() when v25()'s state has a nonzero field at 0x350, then calls FUN_00c87c50(replacement).
// @f3 0x008f7fa0 (community match, verified in this file)
struct OC_Stub
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
    virtual void* GetState();
    virtual void v39();
    virtual void Notify();
};

// pdb: bhkSerializable::SethkObject | bhkSerializable.obj | fnv360_0822_retail, vtable, medium
// pdb params: aphkObject
void ObjectController::SetObject(void* replacement)
{
    void* current = this ? m_pObject : 0;

    if (replacement != current)
    {
        if (current)
        {
            OC_Stub* pStub = (OC_Stub*)this;
            void* state = pStub->GetState();
            if (state && *(int*)((char*)state + 0x310) != 0)
                pStub->Notify();
        }
        FUN_00c87c50(replacement);
    }
}


struct FUN_00c87a50_t
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* FUN_00c87a50();
};

// @fnv 0x00c87a50
// pdb: bhkAction::GethkWorldRw | bhkAction.obj | fnv360_0822_retail, vtable, medium
void* FUN_00c87a50_t::FUN_00c87a50()
{
    if (this && unk08)
    {
        return *(void**)((char*)unk08 + 8);
    }
    return 0;
}

struct NiPlane
{
    int unk00;
    int unk04;
    int unk08;

    bool operator==(const NiPlane& other) const;
};

struct Mat364
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

    bool _Call_4d9ae0(const Mat364& other) const;
};

extern unsigned char DAT_011f426c;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;

struct Target_00c88450
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
    Mat364 unk34;
    NiPlane unk58;
};

struct Cinfo_00c88450
{
    int unk00;
    int unk04;
    Target_00c88450* unk08;

    void __thiscall UpdateNodeState(void* arg);
    void __thiscall FUN_00c88450(void* arg);
};

// If unk08's plane equals DAT_011f426c or its matrix check against DAT_011a9448 fails, sets both to those values; then always calls UpdateNodeState(arg).
// @fnv 0x00c88450
void __thiscall Cinfo_00c88450::FUN_00c88450(void* arg)
{
    Target_00c88450* target = unk08;

    if (target != 0)
    {
        NiPlane* plane = &target->unk58;

        if (*plane == *reinterpret_cast<NiPlane const*>(&DAT_011f426c) ||
            !target->unk34._Call_4d9ae0(*reinterpret_cast<Mat364 const*>(&DAT_011a9448)))
        {
            target->unk34 = *reinterpret_cast<Mat364 const*>(&DAT_011a9448);
            plane->unk00 = *reinterpret_cast<int*>(&DAT_011f426c);
            plane->unk04 = *reinterpret_cast<int*>(&DAT_011f4270);
            plane->unk08 = *reinterpret_cast<int*>(&DAT_011f4274);
        }
    }

    UpdateNodeState(arg);
}

struct Process89730
{
    Map253* map;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};
struct Poly89730
{
    virtual void slot0();
    virtual void Scale(int iUnused, Process89730* pkProcess);
};
struct Data89730Base
{
    int unk00;
};
struct Data89730 : public Poly89730, public Data89730Base
{
    int unk08;
    HavokObject253* m_pkFirst;
    HavokObject253* m_pkSecond;
};
struct Owner89730
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual Data89730Base* GetData(bool* pbTemporary);
    void bhkSerializable_CopyMembers(void* pkDestination, Process89730* pkProcess);
    void FUN_00c89730(void* pkDestination, Process89730* pkProcess);
};

// Scales the data from GetData if pkProcess->m_fScale is not 1, re-links its two object pointers via the process map or Clone, then calls bhkSerializable_CopyMembers.
// @fnv 0x00c89730
// pdb: bhkConstraint::CopyMembers | bhkConstraint.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pDest, arCloneData
void Owner89730::FUN_00c89730(void* pkDestination, Process89730* pkProcess)
{
    bool bTemporary;
    Data89730* pkData = static_cast<Data89730*>(GetData(&bTemporary));
    if (pkProcess->m_fScale != 1.0f)
        pkData->Scale(0, pkProcess);
    Node253* pkFirstOwner = pkData->m_pkFirst ? pkData->m_pkFirst->owner : 0;
    Node253* pkSecondOwner = pkData->m_pkSecond ? pkData->m_pkSecond->owner : 0;
    pkData->m_pkFirst = 0;
    pkData->m_pkSecond = 0;
    if (pkFirstOwner)
    {
        void* pkClone;
        if (pkProcess->map->FUN_00a53c30(pkFirstOwner, pkClone))
            pkData->m_pkFirst = pkClone ? ((Node253*)pkClone)->object : 0;
        if (pkSecondOwner)
        {
            Node253* pkSecondClone;
            if (pkProcess->map->FUN_00a53c30(pkSecondOwner, pkClone))
                pkSecondClone = (Node253*)pkClone;
            else
                pkSecondClone = pkSecondOwner->Clone(pkProcess);
            pkData->m_pkSecond = pkSecondClone ? pkSecondClone->object : 0;
        }
    }
    bhkSerializable_CopyMembers(pkDestination, pkProcess);
}

struct FUN_00d53200_class
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    int unk04;
    int unk08;
    void FUN_00c8a230(NiStream& kStream);
};
// Calls NiStream_ReadMultipleLinkIDs on kStream, calls vfn10, then calls ReadBinaryValue(&kStream, unk08).
// @f3 0x008fc580 (community match, verified in this file)
struct W30FileCtx
{
    void FUN_0082b620();
};
struct W30Vt6
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
void FUN_00d53200_class::FUN_00c8a230(NiStream& kStream)
{
    ((W30FileCtx*)&kStream)->FUN_0082b620();
    ((W30Vt6*)this)->v5();
    ReadBinaryValue(&kStream, unk08);
}


extern int DAT_01268194;

struct ActorBase
{
    virtual ~ActorBase();
};
struct FUN_00c8a720 : ActorBase
{
    virtual ~FUN_00c8a720();
    void FUN_00c876a0();
};
// @fnv 0x00c8a720
// pdb: bhkBinaryAction::~bhkBinaryAction | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, high
FUN_00c8a720::~FUN_00c8a720()
{
    FUN_00c876a0();
    --DAT_01268194;
}

class C8AAResult
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};

class C8AASub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    C8AAResult* m_18;
    C8AAResult* m_1c;
};

class C8AAHost
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    C8AASub* m_08;
    C8AAResult* GetA()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_18;
        else
            r = 0;
        return r;
    }
    C8AAResult* GetOther()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_1c;
        else
            r = 0;
        return r;
    }
    int GetResultValue(char c);
};

// Returns the m_0c field of the C8AAResult selected by c ('A'/'a' picks GetA, otherwise GetOther), or 0 if the result is null.
// @fnv 0x00c8aa00
int C8AAHost::GetResultValue(char c)
{
    C8AAResult* y;
    if (c == 'A' || c == 'a')
        y = GetA();
    else
        y = GetOther();
    return y ? y->m_0c : 0;
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00c8aa80_cls : BaseThunk
{
    int unk00;
    int unk04;
    Mid* m_08;
    void FUN_00c8aa80(NiStream* a);
};

// Looks up m_08->m_1c, calls v15(a) on its m_0c object if present, then calls FUN_00a81fe0 on the stream.
// @fnv 0x00c8aa80
// pdb: bhkBinaryAction::RegisterStreamables | bhkBinaryAction.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arStream
void FUN_00c8aa80_cls::FUN_00c8aa80(NiStream* apStream)
{
    Node1* node = this && m_08 ? m_08->m_1c : 0;
    _ReadWriteBarrier();
    if (node)
    {
        C_t* t = (C_t*)node->m_0c;
        if (t)
            t->v15(apStream);
    }
    FUN_00a81fe0(*apStream);
}

extern unsigned int DAT_010c6234;

struct Ffd0base
{
    void Initialize();
};

struct Arr9
{
    int v[9];
};

struct FUN_00c8ffd0
{
    void* m_vtbl;
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
    Arr9 tab;
    FUN_00c8ffd0();
};

// Initializes the base class, sets the vtable pointer, and copies a 9-element array from a global data location.
// @fnv 0x00c8ffd0
FUN_00c8ffd0::FUN_00c8ffd0()
{
    ((Ffd0base*)this)->Initialize();
    m_vtbl = &DAT_010c6234;
    tab = *(const Arr9*)&DAT_011a9448;
}

namespace fnv_00c90000 {
extern int DAT_010c6234;
void __cdecl FUN_00aa1460(void* object, unsigned int size);
struct FUN_00c90000_Object
{
    int* m_vftable;
    void __thiscall FUN_00c81550();
    FUN_00c90000_Object* __thiscall FUN_00c90000(unsigned int flags);
};
// Sets m_vftable to DAT_010c6234, calls FUN_00c81550, and if bit 0 of flags is set calls FUN_00aa1460(this, 0x50); returns this.
// @fnv 0x00c90000
// pdb: bhkBlendCollisionObjectAddRotation::`scalar deleting destructor' | bhkBlendCollisionObjectAddRotation.obj | fnv360_0822_retail, caller_sim, low
FUN_00c90000_Object* FUN_00c90000_Object::FUN_00c90000(unsigned int flags)
{
    m_vftable = &DAT_010c6234;
    FUN_00c81550();
    if (flags & 1)
        FUN_00aa1460(this, 0x50);
    return this;
}
}  // namespace fnv_00c90000

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);

SpawnedAllocHolder* FUN_00c85750() throw();

struct C99F10Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiBytes) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiBytes) throw();
};

struct C99F10Array
{
    void** m_ppData;
    int m_uiLogicalSize;
    int m_iCapacity;
    ~C99F10Array() throw()
    {
        SpawnedAllocHolder* pHolder = FUN_00c85750();
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_pAllocator;
        m_uiLogicalSize = 0;
        if (!(m_iCapacity & 0x80000000))
        {
            pAlloc->FreeArray(m_ppData, (m_iCapacity & 0x3fffffff) * 4);
        }
        m_ppData = 0;
        m_iCapacity = 0x80000000;
    }
};

struct C99F10Base
{
    virtual ~C99F10Base() throw()
    {}
    int unk04;
};

struct FUN_00c9a520_shell
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
    virtual void* v9(void* pvArg);

    void FUN_00c9a520(void* pvData);
    void FUN_00c9a5e0(void* pvArg);
};

// @f3 0x0090a7e0 (community match, verified in this file)
struct NativeView1468 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* Resolve(void* argument);
    void FUN_0090a750(void* data);
};
void FUN_00c9a520_shell::FUN_00c9a5e0(void* argument) {
    NativeView1468* self=reinterpret_cast<NativeView1468*>(this);
    self->FUN_0090a750(self->Resolve(argument));
}


struct DispatchObject;
typedef int(__thiscall* DispatchAction)(DispatchObject*, void*);
struct DispatchObject
{
    void** vtable;
    void* unk04;
    DispatchObject* unk08;
    int type;
    int Dispatch(void* argument)
    {
        return reinterpret_cast<DispatchAction>(vtable[0x38])(this, argument);
    }
};
struct DispatchContainer
{
    void* unk00;
    void* argument;
    void* unk08;
    void* objectLink;
};
typedef void*(__thiscall* GetTarget)(DispatchObject*);
// Finds a target from container->objectLink (or container) by object type 8/10 via vtable slot 4, or type 9 via unk08; returns target->Dispatch(argument) or 0x24.
// @f3 0x008f1b80 (community match, verified in this file)
// pdb: bhkUtilFunctions::GetMaterialValue | bhkUtilFunctions.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arBody
int __cdecl FUN_00c80020(DispatchContainer* container)
{
    void* link = container->objectLink;
    if (!link)
        link = container;
    DispatchObject* target = 0;
    if (link)
    {
        DispatchObject* object = *reinterpret_cast<DispatchObject**>(link);
        int type = object->type;
        if (type == 9 || type == 11)
        {
            void* result = reinterpret_cast<GetTarget>(object->vtable[5])(object);
            if (result)
            {
                char* wrapper = static_cast<char*>(result) - 0x10;
                if (wrapper)
                    target = *reinterpret_cast<DispatchObject**>(wrapper + 8);
                else
                    target = 0;
            }
            else
                target = 0;
        }
        else
        {
            DispatchObject* checked = *reinterpret_cast<DispatchObject**>(link);
            if (checked && type == 10)
                target = checked->unk08;
        }
    }
    int result = 0;
    if (target)
    {
        void* argument = container->argument;
        result = reinterpret_cast<DispatchAction>(target->vtable[0x37])(target, argument);
        if (result >= 0x1f)
            result = 0x1f;
    }
    return result;
}


// FUN_00c80090: cdecl, one pointer arg; probes nested object chain.
class ProbeX;
class ProbeY;
class ProbeZ;
class ProbeE;
class ProbeD;
class ProbeC;
class ProbeObj;

extern int DAT_012681c0;

struct PackedPropertyByte
{
    unsigned char value;
    PackedPropertyByte()
    {}
    inline bool operator!=(int rhs) const
    {
        return value != rhs;
    }
};
class ProbeZ
{
  public:
    PackedPropertyByte FUN_00c9bff0() const;
};

class ProbeX
{
  public:
    ProbeY* FUN_00653290(const void* type);
};

class ProbeY
{
  public:
    int unk00;
    int unk04;
    ProbeZ* m_08;
};

struct SelectedBits
{
    unsigned int bits;
    inline operator bool() const
    {
        return bits != 0;
    }
};
class ProbeE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
    inline SelectedBits SelectedFlag() const
    {
        SelectedBits result = {m_0c & 2};
        return result;
    }
};

class ProbeD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ProbeX* m_10;
};

class ProbeC
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
    virtual ProbeD* GetD();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
};

class ProbeObj
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
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
    ProbeC** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
    inline unsigned int ChildCount() const
    {
        return m_a6;
    }
    inline ProbeC* FirstChild() const
    {
        return ChildCount() <= 0 ? 0 : *m_a0;
    }
};

static inline bool CheckBody(ProbeD* body, ProbeObj*& obj)
{
    ProbeX* object = body->m_10;
    if (object)
    {
        ProbeY* rigid = object->FUN_00653290(&DAT_012681c0);
        if (rigid && rigid->m_08)
            return rigid->m_08->FUN_00c9bff0() != 0;
    }
    return false;
}
// Gets a body via obj->m_1c->GetD(), or via the first child's m_1c when extra data bit 1 is set; returns whether CheckBody is true for it.
// @f3 0x008f1c80 (community match, verified in this file)
extern int DAT_010f3220;
ProbeE* __cdecl FUN_00aa60f0(ProbeObj* o);
ProbeD* __cdecl FUN_008da450(ProbeC* child);
ProbeY* __cdecl FUN_00424d50(const void* type, ProbeX* object);
class ProbeZB
{
  public:
    PackedPropertyByte FUN_0090b0e0() const;
};

static inline bool CheckBody2214(ProbeD* body, ProbeObj*& obj)
{
    ProbeX* object = body->m_10;
    ProbeY* rigid = FUN_00424d50(&DAT_010f3220, object);
    if (rigid && rigid->m_08)
        return reinterpret_cast<ProbeZB*>(rigid->m_08)->FUN_0090b0e0() != 0;
    return false;
}
// @fnv 0x00c80090
// pdb: HasActiveRB | bhkUtilFunctions.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apScene
bool FUN_00c80090(ProbeObj* obj)
{
    bool result = false;
    ProbeC* c = obj->m_1c;
    ProbeD* body = c ? c->GetD() : 0;
    if (!body)
    {
        ProbeE* extra = FUN_00aa60f0(obj);
        unsigned int sel = extra ? extra->m_0c & 2 : 0;
        if (sel)
        {
            body = FUN_008da450(obj->FirstChild());
        }
    }
    if (body)
    {
        if (CheckBody2214(body, obj))
            result = true;
        else
            result = false;
    }
    return result;
}


struct WalkBits_c804
{
    union
    {
        unsigned int raw;
        struct
        {
            unsigned int lo : 7;
            unsigned int hi : 25;
        };
    };
    WalkBits_c804()
    {}
    WalkBits_c804(unsigned int r) : raw(r)
    {}
    void SetLo(unsigned int f)
    {
        lo = f;
    }
};

class WalkLookup_c804
{
  public:
    void* Find(const void* key);
};

class WalkMid_c804
{
  public:
    void Apply(unsigned int value);
    void Apply2(WalkBits_c804 value);
};

struct WalkHit_c804
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    WalkMid_c804* m_10;
};

struct WalkNode_c804
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_c804* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    WalkLookup_c804* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_c804** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// For node and recursively each child, looks up DAT_012043f8 in m_1c and, if found, applies a value with its low 7 bits set to flag via Apply2.
// @f3 0x005e5540 (community match, verified in this file)
namespace Walk107 {
struct Resource;
struct Shape {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18;unsigned flags;};
struct ShapeOwner {unsigned unk00,unk04,unk08,unk0c;Shape shape;};
struct Resource {unsigned unk00,unk04;ShapeOwner* owner;};
struct Container {unsigned unk00,unk04,unk08,unk0c;Resource* resource;};
struct Reference {Resource* resource;void FUN_008e9650(Resource*);};
struct ChildGroup:WalkNode_c804 {unsigned short childCount;};
}
Walk107::Container* __cdecl FUN_00424fe0(WalkNode_c804*);
void __cdecl FUN_005e3250(WalkHit_c804*);
// pdb: NavMeshObstacleManager::FindFirstObstacleFor3D | NavMeshObstacleManager.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: ap3D, apRetObstacle
bool __cdecl FUN_00c804d0(WalkNode_c804* node,WalkHit_c804* hit){
 using namespace Walk107;
 Container* container=FUN_00424fe0(node);
 if(container&&container->resource){
  Resource* resource=container->resource;
  Shape* shape=resource->owner?&resource->owner->shape:0;
  unsigned type=shape?shape->flags:0;
  type&=0x7f;
  if(type==2||type==4||type==10||type==20||type==28){
   hit->unk08=0;
   reinterpret_cast<Reference*>(&hit->unk0C)->FUN_008e9650(resource);
   FUN_005e3250(hit);
   return true;
  }
 }
 ChildGroup* group=static_cast<ChildGroup*>(node->v03());
 if(group){
  for(unsigned i=0;i<group->childCount;++i){
   WalkNode_c804* child=group->m_a0[i];
   if(child&&FUN_00c804d0(child,hit))return true;
  }
 }
 return false;
}


extern unsigned int DAT_012043f8;

struct WorkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    DynCastHelper* unk1C;
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
    WorkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct NodeDepth
{
    WorkNode_cls* node;
    unsigned int depth;
};

struct WorkStack_cls
{
    unsigned int unk00;
    unsigned int* m_04;
    unsigned int m_08;
    void __thiscall InsertItemAt(int a1, NodeDepth* a2);
};

// Recursively searches a work stack for a node matching a dynamic cast, pushing children with increased depth when no match is found.
// @f3 0x008f2760 (community match, verified in this file)
NiObject* __cdecl FUN_00424fe0(WorkNode_cls* apNode);
// pdb: bhkUtilFunctions::FindCollisionObjectBFSRec | bhkUtilFunctions.obj | fnv360_0822_retail, objrun, medium
// pdb params: apObject, apQueue, auiMaxLevel, auiCurLevel
NiObject* __cdecl FUN_00c80c00(WorkNode_cls* apNode, WorkStack_cls* apStack, unsigned int uiMaxDepth,
                               unsigned int uiDepth)
{
    NiObject* result = FUN_00424fe0(apNode);
    if (result == 0)
    {
        if (apNode->v03() != 0 && uiDepth < uiMaxDepth)
        {
            unsigned int index = 0;
            while (index < apNode->m_a6)
            {
                WorkNode_cls* item = apNode->m_a0[index];
                if (item != 0)
                {
                    NodeDepth entry;
                    entry.node = item;
                    entry.depth = uiDepth + 1;
                    apStack->InsertItemAt(0, &entry);
                }
                ++index;
            }
        }
    }
    if (apStack->m_08 != 0 && result == 0)
    {
        unsigned int count = apStack->m_08;
        unsigned int* entries = apStack->m_04;
        unsigned int uiNodePtr = entries[count * 2 - 2];
        unsigned int high = entries[count * 2 - 1];
        apStack->m_08 = count - 1;
        result = FUN_00c80c00((WorkNode_cls*)uiNodePtr, apStack, uiMaxDepth, high);
    }
    return result;
}


// FUN_00c81890 (unit_a1df186ed60f.cpp) - 95B, /MT /O2 /GS /EHsc /Gy
// v4: extern __declspec(thread) int DAT_tls_0x2c0 (probe-exact a1+64 8b 0d+8b 14 81+8b 82 c0020000);
//     uchar bitfield f6/f0 (probe-exact mov cl/shr/test forms); m_bits word AND per v3 match
extern __declspec(thread) int DAT_tls_0x2c0;  // TLS slot +0x2C0 (module index 0x126fd98)
struct FUN_00c65b00_holder
{
    int __thiscall FUN_00c65b00();
};
struct FUN_00a68bf0_holder
{
    int __thiscall FUN_00a68bf0();
};  // ?UpdateWorldLoc@NiAVObject@@QAEXXZ

typedef int(__thiscall* FN_00c81890_VT)(void*);

union U_00c81890
{
    unsigned short m_bits;  // +0xC word member
    struct
    {
        unsigned char f0 : 1;
        unsigned char : 5;
        unsigned char f6 : 1;
        unsigned char : 1;
    } bf;
};

struct E_T
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
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual int va4();
    void* m_p4;
    void* m_p8;
    U_00c81890 u_c;

    bool GetBit(int n) const
    {
        return (u_c.m_bits >> n) & 1;
    }
    void ClearBit(int n)
    {
        u_c.m_bits &= ~(1 << n);
    }
    int __thiscall FUN_00c81890();
};

// Returns DAT_tls_0x2c0 if it is 3; otherwise calls FUN_00c65b00 (clearing bit 6), va4, or m_p8->FUN_00a68bf0 depending on bits 6 and 0, else returns it.
// @fnv 0x00c81890
// pdb: bhkBlendCollisionObject::ForceUpdateWorldData | bhkBlendCollisionObject.obj | fnv360_0822_retail, caller_sim, low
int __thiscall E_T::FUN_00c81890()
{
    int result = DAT_tls_0x2c0;
    if (result != 3)
    {
        if (GetBit(6))
        {
            if (result != 2)
            {
                result = ((FUN_00c65b00_holder*)this)->FUN_00c65b00();
                ClearBit(6);
                return result;
            }
        }
        else if (GetBit(0))
            return va4();
        if (m_p8)
            return ((FUN_00a68bf0_holder*)m_p8)->FUN_00a68bf0();
    }
    return result;
}

struct A50Inner
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char m_e8;
};
class A50Obj
{
  public:
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
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4(int t);
    int m_04;
    A50Inner* m_08;
};
struct A50Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    A50Obj* m_10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    void __thiscall FUN_00c81a50();
};
// If m_10 is set, calls its ve4(m_20) when m_20 is 4 and kind m_08->m_e8 is not 4, or m_20 is 1 and kind is 4 or 5; a null m_08 also calls.
// @f3 0x008f3760 (community match, verified in this file)
struct FUN_00c81a50_Inner
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    unsigned char m_d8;
};

struct FUN_00c81a50_Obj
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
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc(int t);
};

// pdb: bhkBlendCollisionObject::SynchronizeMotionType | bhkBlendCollisionObject.obj | fnv360_0822_retail, call_gap, low
void A50Cls::FUN_00c81a50()
{
    A50Obj* p = m_10;
    if (!p)
        return;
    if (m_20 == 6)
    {
        FUN_00c81a50_Inner* q = (FUN_00c81a50_Inner*)p->m_08;
        int kind = q ? q->m_d8 : 0;
        if (!q)
            goto call;
        if (kind != m_20)
            goto call;
    }
    if (m_20 == 1)
    {
        FUN_00c81a50_Inner* q = (FUN_00c81a50_Inner*)p->m_08;
        int kind = q ? q->m_d8 : 0;
        if (!q)
            goto call;
        if (kind == 6)
            goto call;
        if (kind != 7)
            return;
    }
    else
    {
        return;
    }
call:
    ((FUN_00c81a50_Obj*)p)->vdc(m_20);
}


namespace fnv_00c828f0 {
extern unsigned int DAT_01268078[32];
extern unsigned __int64 DAT_01267f20[43];

inline void SetSelectionMask(unsigned int uiA, unsigned int uiB, bool bSelected)
{
    if (bSelected)
    {
        DAT_01267f20[uiA] |= (unsigned __int64)1 << uiB;
        DAT_01267f20[uiB] |= (unsigned __int64)1 << uiA;
    }
    else
    {
        DAT_01267f20[uiA] &= ~((unsigned __int64)1 << uiB);
        DAT_01267f20[uiB] &= ~((unsigned __int64)1 << uiA);
    }
}

inline void SetFlagPair(unsigned int uiA, unsigned int uiB, bool bSelected)
{
    if (bSelected)
    {
        DAT_01268078[uiA] |= 1 << uiB;
        DAT_01268078[uiB] |= 1 << uiA;
    }
    else
    {
        DAT_01268078[uiA] &= ~(1 << uiB);
        DAT_01268078[uiB] &= ~(1 << uiA);
    }
}

// Zeroes DAT_01268078 and DAT_01267e70, fills DAT_01267f20 with 0xFF, applies many pair flag and mask updates, calls FUN_00c82870(34, ...), and sets three ints.
// @f3 0x008f4500 (community match, verified in this file)
extern unsigned __int64 DAT_010f2f98[];
extern unsigned int DAT_010f30f0[];
extern unsigned int DAT_010f2ee8[];
void FUN_008f4400(unsigned int uiIndexA, unsigned int uiIndexB, bool bSelected);
void __cdecl FUN_008f4480(unsigned int uiIndex, unsigned __int64 uiMask);
void __cdecl FUN_00c00610(void* pDest, int iValue, unsigned int uiSize);

void bhkCollisionFilter_InitFlags();
namespace fnv_00c828f0 { void bhkCollisionFilter_InitFlags(); }
// pdb: bhkCollisionFilter::InitFlags | bhkCollisionFilter.obj | fnv360_0822_retail, udata, high (was: InitializeSelectionMasks)
void ::fnv_00c828f0::bhkCollisionFilter_InitFlags()
{
    struct SelectionMaskWords { unsigned int low; unsigned int high; };
    FUN_00c00610(DAT_010f30f0, 0, 128);
    FUN_00c00610(DAT_010f2f98, 0xFF, 344);
    FUN_00c00610(DAT_010f2ee8, 0, 172);
    DAT_010f30f0[6] |= (1u << 1);
    DAT_010f30f0[1] |= (1u << 6);
    DAT_010f30f0[12] |= (1u << 1);
    DAT_010f30f0[1] |= (1u << 12);
    DAT_010f30f0[7] |= (1u << 1);
    DAT_010f30f0[1] |= (1u << 7);
    DAT_010f30f0[13] |= (1u << 1);
    DAT_010f30f0[1] |= (1u << 13);
    DAT_010f30f0[17] |= (1u << 1);
    DAT_010f30f0[1] |= (1u << 17);
    DAT_010f30f0[6] |= (1u << 2);
    DAT_010f30f0[2] |= (1u << 6);
    DAT_010f30f0[12] |= (1u << 2);
    DAT_010f30f0[2] |= (1u << 12);
    DAT_010f30f0[7] |= (1u << 2);
    DAT_010f30f0[2] |= (1u << 7);
    DAT_010f30f0[13] |= (1u << 2);
    DAT_010f30f0[2] |= (1u << 13);
    DAT_010f30f0[6] |= (1u << 3);
    DAT_010f30f0[3] |= (1u << 6);
    DAT_010f30f0[12] |= (1u << 3);
    DAT_010f30f0[3] |= (1u << 12);
    DAT_010f30f0[7] |= (1u << 3);
    DAT_010f30f0[3] |= (1u << 7);
    DAT_010f30f0[13] |= (1u << 3);
    DAT_010f30f0[3] |= (1u << 13);
    DAT_010f30f0[4] |= (1u << 6);
    DAT_010f30f0[6] |= (1u << 4);
    DAT_010f30f0[4] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 4);
    DAT_010f30f0[4] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 4);
    DAT_010f30f0[4] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 4);
    DAT_010f30f0[4] |= (1u << 17);
    DAT_010f30f0[17] |= (1u << 4);
    DAT_010f30f0[5] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 5);
    DAT_010f30f0[6] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 6);
    DAT_010f30f0[13] |= (1u << 5);
    DAT_010f30f0[5] |= (1u << 13);
    DAT_010f30f0[6] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 6);
    DAT_010f30f0[6] |= (1u << 17);
    DAT_010f30f0[17] |= (1u << 6);
    DAT_010f30f0[6] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 6);
    DAT_010f30f0[6] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 6);
    DAT_010f30f0[7] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 7);
    DAT_010f30f0[18] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 18);
    DAT_010f30f0[18] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 18);
    DAT_010f30f0[18] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 18);
    DAT_010f30f0[18] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 18);
    DAT_010f30f0[15] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 15);
    DAT_010f30f0[8] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 8);
    DAT_010f30f0[7] |= (1u << 10);
    DAT_010f30f0[10] |= (1u << 7);
    DAT_010f30f0[18] |= (1u << 15);
    DAT_010f30f0[15] |= (1u << 18);
    DAT_010f30f0[9] |= (1u << 15);
    DAT_010f30f0[15] |= (1u << 9);
    DAT_010f30f0[10] |= (1u << 18);
    DAT_010f30f0[18] |= (1u << 10);
    DAT_010f30f0[16] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 16);
    DAT_010f30f0[14] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 14);
    DAT_010f30f0[16] |= (1u << 18);
    DAT_010f30f0[18] |= (1u << 16);
    DAT_010f30f0[10] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 10);
    DAT_010f30f0[10] |= (1u << 15);
    DAT_010f30f0[15] |= (1u << 10);
    DAT_010f30f0[6] |= (1u << 11);
    DAT_010f30f0[11] |= (1u << 6);
    DAT_010f30f0[7] |= (1u << 11);
    DAT_010f30f0[11] |= (1u << 7);
    DAT_010f30f0[12] |= (1u << 6);
    DAT_010f30f0[6] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 17);
    DAT_010f30f0[17] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 12);
    DAT_010f30f0[13] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 15);
    DAT_010f30f0[15] |= (1u << 13);
    DAT_010f30f0[10] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 10);
    DAT_010f30f0[16] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 16);
    DAT_010f30f0[8] |= (1u << 15);
    DAT_010f30f0[15] |= (1u << 8);
    DAT_010f30f0[16] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 16);
    DAT_010f30f0[16] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 16);
    DAT_010f30f0[22] |= (1u << 7);
    DAT_010f30f0[7] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 5);
    DAT_010f30f0[5] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 6);
    DAT_010f30f0[6] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 13);
    DAT_010f30f0[13] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 11);
    DAT_010f30f0[11] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 12);
    DAT_010f30f0[12] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 1);
    DAT_010f30f0[1] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 4);
    DAT_010f30f0[4] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 3);
    DAT_010f30f0[3] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 2);
    DAT_010f30f0[2] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 10);
    DAT_010f30f0[10] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 22);
    DAT_010f30f0[15] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 15);
    DAT_010f30f0[16] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 16);
    DAT_010f30f0[18] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 18);
    DAT_010f30f0[20] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 20);
    DAT_010f30f0[21] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 21);
    DAT_010f30f0[17] |= (1u << 22);
    DAT_010f30f0[22] |= (1u << 17);
    DAT_010f30f0[24] |= (1u << 4);
    DAT_010f30f0[4] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 3);
    DAT_010f30f0[3] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 8);
    DAT_010f30f0[8] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 9);
    DAT_010f30f0[9] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 10);
    DAT_010f30f0[10] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 14);
    DAT_010f30f0[14] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 15);
    DAT_010f30f0[15] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 16);
    DAT_010f30f0[16] |= (1u << 24);
    DAT_010f30f0[2] |= (1u << 24);
    DAT_010f30f0[24] |= (1u << 2);
    DAT_010f2f98[19] &= ~(1ui64 << 3);
    DAT_010f2f98[3] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 26);
    DAT_010f2f98[26] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 28);
    DAT_010f2f98[28] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 6);
    DAT_010f2f98[6] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 7);
    DAT_010f2f98[7] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 12);
    DAT_010f2f98[12] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 16);
    DAT_010f2f98[16] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 30);
    DAT_010f2f98[30] &= ~(1ui64 << 19);
    DAT_010f2f98[31] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 31);
    DAT_010f2f98[19] &= ~(1ui64 << 35);
    DAT_010f2f98[35] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 33);
    DAT_010f2f98[33] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 36);
    DAT_010f2f98[36] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 37);
    DAT_010f2f98[37] &= ~(1ui64 << 19);
    DAT_010f2f98[38] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 38);
    DAT_010f2f98[42] &= ~(1ui64 << 19);
    DAT_010f2f98[19] &= ~(1ui64 << 42);
    DAT_010f2f98[19] &= ~(1ui64 << 11);
    DAT_010f2f98[11] &= ~(1ui64 << 19);
    DAT_010f2f98[20] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 20);
    DAT_010f2f98[20] &= ~(1ui64 << 16);
    DAT_010f2f98[16] &= ~(1ui64 << 20);
    DAT_010f2f98[20] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 20);
    DAT_010f2f98[20] &= ~(1ui64 << 37);
    DAT_010f2f98[37] &= ~(1ui64 << 20);
    DAT_010f2f98[20] &= ~(1ui64 << 11);
    DAT_010f2f98[11] &= ~(1ui64 << 20);
    DAT_010f2f98[8] &= ~(1ui64 << 20);
    DAT_010f2f98[20] &= ~(1ui64 << 8);
    DAT_010f2f98[21] &= ~(1ui64 << 1);
    DAT_010f2f98[1] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 2);
    DAT_010f2f98[2] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 3);
    DAT_010f2f98[3] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 26);
    DAT_010f2f98[26] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 28);
    DAT_010f2f98[28] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 4);
    DAT_010f2f98[4] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 5);
    DAT_010f2f98[5] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 6);
    DAT_010f2f98[6] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 7);
    DAT_010f2f98[7] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 29);
    DAT_010f2f98[29] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 9);
    DAT_010f2f98[9] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 10);
    DAT_010f2f98[10] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 11);
    DAT_010f2f98[11] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 12);
    DAT_010f2f98[12] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 13);
    DAT_010f2f98[13] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 14);
    DAT_010f2f98[14] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 17);
    DAT_010f2f98[17] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 16);
    DAT_010f2f98[16] &= ~(1ui64 << 21);
    DAT_010f2f98[21] |= (1ui64 << 30);
    DAT_010f2f98[30] |= (1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 31);
    DAT_010f2f98[31] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 35);
    DAT_010f2f98[35] &= ~(1ui64 << 21);
    DAT_010f2f98[21] |= (1ui64 << 33);
    DAT_010f2f98[33] |= (1ui64 << 21);
    DAT_010f2f98[37] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 37);
    DAT_010f2f98[38] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 38);
    DAT_010f2f98[39] &= ~(1ui64 << 21);
    DAT_010f2f98[21] &= ~(1ui64 << 39);
    DAT_010f2f98[30] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 30);
    DAT_010f2f98[21] &= ~(1ui64 << 40);
    DAT_010f2f98[40] &= ~(1ui64 << 21);
    reinterpret_cast<SelectionMaskWords*>(DAT_010f2f98)[21].high &= ~(1u << 9);
    DAT_010f2f98[41] &= ~(1ui64 << 21);
    DAT_010f2f98[30] &= ~(1ui64 << 29);
    DAT_010f2f98[29] &= ~(1ui64 << 30);
    DAT_010f2f98[18] &= ~(1ui64 << 1);
    DAT_010f2f98[1] &= ~(1ui64 << 18);
    DAT_010f2f98[30] |= (1ui64 << 11);
    DAT_010f2f98[11] |= (1ui64 << 30);
    DAT_010f2f98[18] &= ~(1ui64 << 2);
    DAT_010f2f98[2] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 3);
    DAT_010f2f98[3] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 26);
    DAT_010f2f98[26] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 28);
    DAT_010f2f98[28] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 4);
    DAT_010f2f98[4] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 5);
    DAT_010f2f98[5] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 6);
    DAT_010f2f98[6] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 7);
    DAT_010f2f98[7] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 29);
    DAT_010f2f98[29] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 9);
    DAT_010f2f98[9] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 10);
    DAT_010f2f98[10] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 11);
    DAT_010f2f98[11] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 12);
    DAT_010f2f98[12] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 13);
    DAT_010f2f98[13] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 14);
    DAT_010f2f98[14] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 17);
    DAT_010f2f98[17] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 16);
    DAT_010f2f98[16] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 30);
    DAT_010f2f98[30] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 31);
    DAT_010f2f98[31] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 35);
    DAT_010f2f98[35] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 37);
    DAT_010f2f98[37] &= ~(1ui64 << 18);
    DAT_010f2f98[29] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 29);
    DAT_010f2f98[38] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 38);
    DAT_010f2f98[39] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 39);
    DAT_010f2f98[40] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 40);
    DAT_010f2f98[41] &= ~(1ui64 << 18);
    DAT_010f2f98[18] &= ~(1ui64 << 41);
    DAT_010f2f98[8] &= ~(1ui64 << 5);
    DAT_010f2f98[5] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 4);
    DAT_010f2f98[4] &= ~(1ui64 << 8);
    DAT_010f2f98[10] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 10);
    DAT_010f2f98[15] &= ~(1ui64 << 1);
    DAT_010f2f98[1] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 2);
    DAT_010f2f98[2] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 3);
    DAT_010f2f98[3] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 26);
    DAT_010f2f98[26] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 28);
    DAT_010f2f98[28] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 4);
    DAT_010f2f98[4] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 5);
    DAT_010f2f98[5] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 6);
    DAT_010f2f98[6] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 7);
    DAT_010f2f98[7] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 8);
    DAT_010f2f98[8] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 29);
    DAT_010f2f98[29] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 9);
    DAT_010f2f98[9] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 10);
    DAT_010f2f98[10] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 11);
    DAT_010f2f98[11] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 12);
    DAT_010f2f98[12] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 13);
    DAT_010f2f98[13] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 14);
    DAT_010f2f98[14] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 17);
    DAT_010f2f98[17] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 16);
    DAT_010f2f98[16] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 30);
    DAT_010f2f98[30] &= ~(1ui64 << 15);
    DAT_010f2f98[15] &= ~(1ui64 << 31);
    DAT_010f2f98[31] &= ~(1ui64 << 15);
    FUN_008f4400(15, 35, false);
    FUN_008f4400(15, 37, false);
    FUN_008f4400(15, 38, false);
    FUN_008f4400(15, 39, false);
    FUN_008f4400(15, 40, false);
    FUN_008f4400(15, 41, false);
    FUN_008f4400(33, 1, false);
    FUN_008f4400(33, 2, false);
    FUN_008f4400(33, 3, false);
    FUN_008f4400(33, 26, false);
    FUN_008f4400(33, 28, false);
    FUN_008f4400(33, 4, false);
    FUN_008f4400(33, 5, false);
    FUN_008f4400(33, 6, false);
    FUN_008f4400(33, 7, false);
    FUN_008f4400(33, 8, false);
    FUN_008f4400(33, 29, false);
    FUN_008f4400(33, 9, false);
    FUN_008f4400(33, 10, false);
    DAT_010f2f98[33] |= (1ui64 << 11);
    DAT_010f2f98[11] |= (1ui64 << 33);
    FUN_008f4400(33, 12, false);
    FUN_008f4400(33, 13, false);
    FUN_008f4400(33, 14, false);
    FUN_008f4400(33, 33, false);
    FUN_008f4400(33, 17, false);
    FUN_008f4400(33, 15, false);
    FUN_008f4400(33, 16, false);
    FUN_008f4400(33, 30, false);
    FUN_008f4400(33, 31, false);
    FUN_008f4400(33, 35, false);
    FUN_008f4400(33, 37, false);
    FUN_008f4400(33, 38, false);
    FUN_008f4400(33, 39, false);
    FUN_008f4400(33, 40, false);
    FUN_008f4400(33, 41, false);
    FUN_008f4400(35, 5, false);
    FUN_008f4400(35, 7, false);
    FUN_008f4400(35, 12, false);
    FUN_008f4400(35, 35, false);
    FUN_008f4400(35, 11, false);
    FUN_008f4400(35, 6, false);
    FUN_008f4400(36, 7, false);
    FUN_008f4400(36, 12, false);
    FUN_008f4400(36, 11, false);
    FUN_008f4400(37, 3, false);
    FUN_008f4400(37, 26, false);
    FUN_008f4400(37, 28, false);
    FUN_008f4400(37, 7, false);
    FUN_008f4400(37, 11, false);
    FUN_008f4400(37, 12, false);
    FUN_008f4400(37, 30, false);
    FUN_008f4400(38, 31, false);
    FUN_008f4400(38, 4, false);
    FUN_008f4400(38, 5, false);
    FUN_008f4400(38, 6, false);
    FUN_008f4400(38, 7, false);
    FUN_008f4400(38, 8, false);
    FUN_008f4400(38, 29, false);
    FUN_008f4400(38, 30, false);
    FUN_008f4400(38, 10, false);
    FUN_008f4400(38, 35, false);
    FUN_008f4400(38, 12, false);
    FUN_008f4400(38, 14, false);
    FUN_008f4400(38, 16, false);
    FUN_008f4400(38, 41, false);
    FUN_008f4400(38, 36, false);
    FUN_008f4400(38, 37, false);
    FUN_008f4400(31, 31, false);
    FUN_008f4400(31, 1, false);
    FUN_008f4400(31, 4, false);
    FUN_008f4400(31, 5, false);
    FUN_008f4400(31, 6, false);
    FUN_008f4400(31, 7, false);
    FUN_008f4400(31, 8, false);
    FUN_008f4400(31, 29, false);
    FUN_008f4400(31, 9, false);
    FUN_008f4400(31, 10, false);
    FUN_008f4400(31, 11, false);
    FUN_008f4400(31, 13, false);
    FUN_008f4400(31, 15, false);
    FUN_008f4400(31, 17, false);
    FUN_008f4400(31, 35, false);
    FUN_008f4400(31, 41, false);
    FUN_008f4400(31, 36, false);
    FUN_008f4400(31, 37, false);
    FUN_008f4400(41, 3, false);
    FUN_008f4400(41, 26, false);
    FUN_008f4400(41, 28, false);
    FUN_008f4400(41, 7, false);
    FUN_008f4400(41, 11, false);
    FUN_008f4400(41, 35, false);
    FUN_008f4400(41, 36, false);
    FUN_008f4400(41, 37, false);
    FUN_008f4400(41, 39, false);
    FUN_008f4400(41, 40, false);
    FUN_008f4400(41, 38, false);
    FUN_008f4400(41, 41, false);
    FUN_008f4400(6, 7, false);
    FUN_008f4400(6, 16, false);
    FUN_008f4400(6, 3, false);
    FUN_008f4400(12, 1, false);
    FUN_008f4400(12, 2, false);
    FUN_008f4400(12, 3, false);
    FUN_008f4400(12, 26, false);
    FUN_008f4400(12, 28, false);
    FUN_008f4400(12, 9, false);
    FUN_008f4400(12, 10, false);
    FUN_008f4400(12, 11, false);
    FUN_008f4400(12, 12, false);
    FUN_008f4400(12, 13, false);
    FUN_008f4400(12, 15, false);
    FUN_008f4400(12, 16, false);
    FUN_008f4400(12, 17, false);
    FUN_008f4400(12, 22, false);
    FUN_008f4400(12, 32, false);
    FUN_008f4400(12, 38, false);
    FUN_008f4400(12, 42, false);
    FUN_008f4400(12, 37, false);
    FUN_008f4400(12, 36, false);
    FUN_008f4400(12, 41, false);
    FUN_008f4400(22, 1, false);
    FUN_008f4400(22, 2, false);
    FUN_008f4400(22, 3, false);
    FUN_008f4400(22, 26, false);
    FUN_008f4400(22, 4, false);
    FUN_008f4400(22, 5, false);
    FUN_008f4400(22, 6, false);
    FUN_008f4400(22, 7, false);
    FUN_008f4400(22, 8, false);
    FUN_008f4400(22, 29, false);
    FUN_008f4400(22, 9, false);
    FUN_008f4400(22, 10, false);
    FUN_008f4400(22, 11, false);
    FUN_008f4400(22, 12, false);
    FUN_008f4400(22, 13, false);
    FUN_008f4400(22, 14, false);
    FUN_008f4400(22, 15, false);
    FUN_008f4400(22, 16, false);
    FUN_008f4400(22, 17, false);
    FUN_008f4400(22, 18, false);
    FUN_008f4400(22, 19, false);
    FUN_008f4400(22, 20, false);
    FUN_008f4400(22, 22, false);
    FUN_008f4400(22, 23, false);
    FUN_008f4400(22, 25, false);
    FUN_008f4400(22, 31, false);
    FUN_008f4400(22, 32, false);
    FUN_008f4400(22, 33, false);
    FUN_008f4400(22, 35, false);
    FUN_008f4400(22, 36, false);
    FUN_008f4400(22, 37, false);
    FUN_008f4400(22, 38, false);
    FUN_008f4400(22, 41, false);
    FUN_008f4400(22, 42, false);
    FUN_008f4400(23, 1, false);
    FUN_008f4400(23, 2, false);
    FUN_008f4400(23, 3, false);
    FUN_008f4400(23, 26, false);
    FUN_008f4400(23, 28, false);
    FUN_008f4400(23, 4, false);
    FUN_008f4400(23, 5, false);
    FUN_008f4400(23, 7, false);
    FUN_008f4400(23, 8, false);
    FUN_008f4400(23, 29, false);
    FUN_008f4400(23, 9, false);
    FUN_008f4400(23, 10, false);
    FUN_008f4400(23, 11, false);
    FUN_008f4400(23, 12, false);
    FUN_008f4400(23, 13, false);
    FUN_008f4400(23, 14, false);
    FUN_008f4400(23, 15, false);
    FUN_008f4400(23, 16, false);
    FUN_008f4400(23, 17, false);
    FUN_008f4400(23, 18, false);
    FUN_008f4400(23, 19, false);
    FUN_008f4400(23, 20, false);
    FUN_008f4400(23, 22, false);
    FUN_008f4400(23, 23, false);
    FUN_008f4400(23, 25, false);
    FUN_008f4400(23, 30, false);
    FUN_008f4400(23, 31, false);
    FUN_008f4400(23, 32, false);
    FUN_008f4400(23, 33, false);
    FUN_008f4400(23, 35, false);
    FUN_008f4400(23, 36, false);
    FUN_008f4400(23, 37, false);
    FUN_008f4400(23, 38, false);
    FUN_008f4400(23, 41, false);
    FUN_008f4400(23, 42, false);
    FUN_008f4400(24, 1, false);
    FUN_008f4400(24, 2, false);
    FUN_008f4400(24, 3, false);
    FUN_008f4400(24, 26, false);
    FUN_008f4400(24, 28, false);
    FUN_008f4400(24, 4, false);
    FUN_008f4400(24, 5, false);
    FUN_008f4400(24, 7, false);
    FUN_008f4400(24, 8, false);
    FUN_008f4400(24, 29, false);
    FUN_008f4400(24, 9, false);
    FUN_008f4400(24, 10, false);
    FUN_008f4400(24, 11, false);
    FUN_008f4400(24, 12, false);
    FUN_008f4400(24, 13, false);
    FUN_008f4400(24, 14, false);
    FUN_008f4400(24, 15, false);
    FUN_008f4400(24, 16, false);
    FUN_008f4400(24, 17, false);
    FUN_008f4400(24, 18, false);
    FUN_008f4400(24, 19, false);
    FUN_008f4400(24, 20, false);
    FUN_008f4400(24, 21, false);
    FUN_008f4400(24, 22, false);
    FUN_008f4400(24, 23, false);
    FUN_008f4400(24, 24, false);
    FUN_008f4400(24, 25, false);
    FUN_008f4400(24, 31, false);
    FUN_008f4400(24, 32, false);
    FUN_008f4400(24, 33, false);
    FUN_008f4400(24, 35, false);
    FUN_008f4400(24, 36, false);
    FUN_008f4400(24, 37, false);
    FUN_008f4400(24, 38, false);
    FUN_008f4400(24, 42, false);
    FUN_008f4400(25, 3, false);
    FUN_008f4400(25, 26, false);
    FUN_008f4400(25, 28, false);
    FUN_008f4400(25, 6, false);
    FUN_008f4400(25, 7, false);
    FUN_008f4400(25, 8, false);
    FUN_008f4400(25, 12, false);
    FUN_008f4400(25, 15, false);
    FUN_008f4400(25, 16, false);
    FUN_008f4400(25, 18, false);
    FUN_008f4400(25, 30, false);
    FUN_008f4400(25, 31, false);
    FUN_008f4400(25, 35, false);
    FUN_008f4400(25, 36, false);
    FUN_008f4400(25, 37, false);
    FUN_008f4400(25, 38, false);
    FUN_008f4400(25, 42, false);
    FUN_008f4400(25, 11, false);
    FUN_008f4400(7, 7, false);
    FUN_008f4400(7, 16, false);
    FUN_008f4400(7, 3, false);
    FUN_008f4400(7, 26, false);
    FUN_008f4400(7, 28, false);
    FUN_008f4400(42, 4, false);
    FUN_008f4400(42, 6, false);
    FUN_008f4400(42, 5, false);
    FUN_008f4400(42, 11, false);
    FUN_008f4400(42, 29, false);
    FUN_008f4400(42, 31, false);
    FUN_008f4400(42, 38, false);
    FUN_008f4400(42, 35, false);
    FUN_008f4400(42, 41, false);
    FUN_008f4400(42, 37, false);
    FUN_008f4400(27, 19, false);
    FUN_008f4400(27, 25, false);
    FUN_008f4400(27, 31, false);
    FUN_008f4400(27, 32, false);
    FUN_008f4400(27, 33, false);
    FUN_008f4400(27, 35, false);
    FUN_008f4400(27, 37, false);
    FUN_008f4400(27, 42, false);
    FUN_008f4400(27, 5, false);
    FUN_008f4480(34, 0x10000004ui64);
    DAT_010f2ee8[13] = 2;
    DAT_010f2ee8[9] = 3;
    DAT_010f2ee8[11] = 4;
}

}  // namespace fnv_00c828f0

struct FUN_00c84d00_obj
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
};

struct FUN_00c84d00_cls
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual int* vGet(FUN_00c84d00_obj** pp);
    void FUN_00c87650(FUN_00c84d00_obj* a);
    void FUN_00c84d00(FUN_00c84d00_obj* a1);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_10;
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// @f3 0x008f7490 (community match, verified in this file)
// pdb: bhkShape::LoadBinary | bhkShape.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: bhkShape::RegisterStreamables)
// pdb params: arStream
void FUN_00c84d00_cls::FUN_00c84d00(FUN_00c84d00_obj* apObj)
{
    FUN_00c87650(apObj);
    FUN_00c84d00_obj* out;
    int* p = vGet(&out);
    if (!p)
        return;
    if (apObj->m_1e5 != 1)
    {
        *p = (int)_byteswap_ulong((unsigned long)*p);
    }
    if (*p >= 0x20)
    {
        *p = 0;
    }
    m_10 = *p;
    *p = 0;
}


class Obj
{
  public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0a();
    virtual void* v0b();
    virtual void* v0c();
    virtual void* v0d();
    virtual void* v0e();
    virtual void* v0f();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1a();
    virtual void* v1b();
    virtual void* v1c();
    virtual void* v1d();
    virtual void* v1e();
    virtual void* v1f();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    unsigned int unk04;
    Obj* m_08;
    void FUN_00c6b0a0(Obj* p);
    bool FUN_00c85810(Obj* a);
};
// If m_08 is set: with a null, calls v28; otherwise if v25() differs from a->m_08, calls v28, passes m_08 to a->FUN_00c6b0a0 and returns true.
// @f3 0x008f8210 (community match, verified in this file)
struct R3_Callee
{
    void FUN_008d8af0(Obj* p);
};
// pdb: bhkAction::Add | bhkAction.obj | fnv360_1110_retail, objrun, medium
// pdb params: apWorld
bool Obj::FUN_00c85810(Obj* a)
{
    Obj* p = this ? m_08 : 0;
    bool r = false;
    if (p)
    {
        if (a)
        {
            Obj* w = (Obj*)this->v26();
            if (w != a->m_08)
            {
                this->v28();
                ((R3_Callee*)a)->FUN_008d8af0(p);
                r = true;
            }
        }
        else
        {
            this->v28();
        }
    }
    return r;
}


struct FUN_00cca4e0
{
    void* m_00;
    void* m_04;
    void* m_08;
    int m_0c;
    int m_10;
    FUN_00cca4e0(void* value);
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
};

struct S00c859e0_holder
{
    void* m_00;
    void* m_04;
};

typedef S00c859e0_holder*(__thiscall* S00c859e0_slot45)(void*, unsigned int*);

extern __declspec(thread) unsigned int t_uiMemContextC877;

inline unsigned int GetMemContextC877()
{
    return t_uiMemContextC877;
}

inline void SetMemContextC877(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC877 = m_uiGeometryShaderFlags;
}

class AutoMemContextC877
{
  public:
    AutoMemContextC877(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC877();
        SetMemContextC877(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC877()
    {
        SetMemContextC877(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

struct C89AC0_Owner;
struct C89AC0_Child
{
    int unk00;
    int unk04;
    C89AC0_Owner* m_pSharedOwner;
    void FUN_00c905b0();
    void FUN_00c90510();
};
struct C89AC0_Owner
{
    int unk00;
    C89AC0_Child* m_pChildObject;
    void SetChildObject(C89AC0_Child* child);
};

struct ThreadData674
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk1E4;
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
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};
extern __declspec(thread) ThreadData674 g_threadData;
struct Context674
{
    unsigned int previous;
    Context674()
    {
        previous = g_threadData.context;
        g_threadData.context = 16;
    }
    ~Context674()
    {
        g_threadData.context = previous;
    }
};
struct Input674
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(Input674*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes)
    {
        unsigned int size = bytes;
        position += read(this, data, bytes, &size, 1);
    }
};
struct Stream674
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
    Input674* input;
    Input674* Input()
    {
        return input;
    }
};
struct Heap674
{
    virtual void v0();
    virtual void* Allocate(unsigned int);
};
struct Base674
{
    virtual ~Base674();
    unsigned short size;
    unsigned short flags;
    static void* operator new(unsigned int size)
    {
        SpawnedAllocHolder* r = FUN_00c85750();
        Heap674* heap = (Heap674*)r->m_pAllocator;
        Base674* b = (Base674*)heap->Allocate(size);
        b->size = (unsigned short)size;
        return b;
    }
    static void operator delete(void* memory);
};
// Reads a type byte and, for types 1 to 3, allocates the matching Base674 subclass, calls its stream method and returns it; otherwise returns null.
// @f3 0x008fc6d0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
struct hkThreadMemoryF3c
{
    void* FUN_008f6d30(int nbytes, int memClass);
};
struct Base674F3 : Base674
{
    static void* operator new(unsigned int size)
    {
        hkThreadMemoryF3c* mem = (hkThreadMemoryF3c*)TlsGetValue(DAT_010f3170);
        Base674* b = (Base674*)mem->FUN_008f6d30(size, 0x2c);
        b->size = (unsigned short)size;
        return b;
    }
};
struct FUN_0097a290_class : Base674F3
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_0097a290_class();
    void FUN_0097a2c0(Stream674*);
};
struct FUN_0097a450_class : Base674F3
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    FUN_0097a450_class();
    void FUN_0097a4a0(Stream674*);
};
struct FUN_0097a610_class : Base674F3
{
    int unk08, unk0C, unk10, unk14, unk18;
    FUN_0097a610_class();
    void FUN_0097a640(Stream674*);
};

// pdb: hkConstraintCinfo::LoadMotor | bhkConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arStream
void* __stdcall FUN_00c8a330(Stream674* stream)
{
    Base674* result = 0;

    unsigned char type = 0;
    stream->Input()->Read(&type, 1);
    switch (type)
    {
    case 1: {
        FUN_0097a290_class* o = new FUN_0097a290_class;
        o->FUN_0097a2c0(stream);
        result = o;
        break;
    }
    case 2: {
        FUN_0097a450_class* o = new FUN_0097a450_class;
        o->FUN_0097a4a0(stream);
        result = o;
        break;
    }
    case 3: {
        FUN_0097a610_class* o = new FUN_0097a610_class;
        o->FUN_0097a640(stream);
        result = o;
        break;
    }
    }
    return result;
}


extern "C" void _ReadWriteBarrier(void);

namespace fnv_00c8af10 {
extern __declspec(thread) unsigned int memoryCategory;
extern int DAT_01030bf4, DAT_010c44e4, DAT_010c485c;
extern int DAT_012680f8, DAT_012686d0, DAT_012681a0;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct NewShape
{
    int* vtable;
    int field04, field08, field0c, field10;
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    void __thiscall FUN_00c87c30();
    NewShape()
    {
        FUN_00c87c30();
        vtable = &DAT_01030bf4;
        field0c = 0;
        field10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
struct MemoryCategoryScope
{
    unsigned int previous;
    MemoryCategoryScope() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~MemoryCategoryScope()
    {
        memoryCategory = previous;
    }
};
}  // namespace fnv_00c8af10

struct AllocLocal;
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n);
struct TypeInfoLocal
{
    const char* name;
    TypeInfoLocal* base;
};
extern TypeInfoLocal g_012682e8, g_012682dc, g_012686a0, g_01268264;
struct ShapeLocal
{
    virtual void v0();
    virtual void v1();
    virtual TypeInfoLocal* GetType();
    int reference;
    ShapeLocal* object;
    ShapeLocal* FUN_00653290(const TypeInfoLocal*);
    bool IsType(const TypeInfoLocal* type)
    {
        const TypeInfoLocal* current = GetType();
        while (current)
        {
            if (current == type)
                return true;
            current = current->base;
        }
        return false;
    }
};
struct WrapperLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int);
    WrapperLocal(ShapeLocal*);
};

struct AllocLocal;
struct AllocLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
    void Clear(SpawnedPtrArray& arr)
    {
        int cap = arr.m_uiCapacity;
        arr.m_uiCount = 0;
        if (!(cap & 0x80000000))
        {
            void* p = arr.m_pData;
            DeallocateLocal(this, p, cap & 0x3fffffff);
        }
        arr.m_pData = 0;
        arr.m_uiCapacity = 0x80000000;
    }
};
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n)
{
    a->Free(p, n * 4);
}
void FUN_00c908c0(void*, SpawnedPtrArray*, int, int);
template <class T> inline void ConstructLocal(T* dest, int n, const T& value)
{
    for (int k = 0; k < n; ++k)
        dest[k] = value;
}
struct ArrayLocal : SpawnedPtrArray
{
    void Clear(AllocLocal& allocator)
    {
        m_uiCount = 0;
        if ((int)m_uiCapacity >= 0)
            allocator.Free(m_pData, (m_uiCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_uiCapacity = 0x80000000;
    }
    void Reserve(void* allocator, int count)
    {
        int capacity = m_uiCapacity & 0x3fffffff;
        if (capacity < count)
        {
            int desired = capacity * 2;
            if (count >= desired)
                desired = count;
            FUN_00c908c0(allocator, this, desired, 4);
        }
    }
    void Append(SpawnedAllocHolder* holder, ShapeLocal* raw)
    {
        if (m_uiCount == (m_uiCapacity & 0x3fffffff))
            ResizeAudioStream(holder->m_pAllocator, this, 4);
        ConstructLocal(m_pData + m_uiCount, 1, (void*)raw);
        ++m_uiCount;
    }
};
struct LoadStreamLocal
{
    int unk00;
    unsigned int version;
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    char filename;
    unsigned int NiStream_GetNumberOfLinkIDs();
    ShapeLocal* FUN_00a63430();
};
struct ListLocal
{
    int unk00;
    ArrayLocal items;
};
struct LoaderLocal
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
    virtual ListLocal* GetList(bool*);
    void FUN_00c84cc0(LoadStreamLocal*);
    void LoadShapes(LoadStreamLocal*);
};
// Refills items with shapes read from stream (some wrapped in WrapperLocal), builds an old-version message when version < 17, then calls FUN_00c84cc0.
// @f3 0x008fd620 (community match, verified in this file)
struct hkThreadMemoryLoadF3
{
    void FUN_008f6d90(void* p, int nbytes, int memClass);
};
void __cdecl FUN_00901e90(void* array, int numElements, int sizeElem);
void __cdecl FUN_00901f10(void* array, int sizeElem);
extern TypeInfoLocal DAT_0116924c, DAT_010f32f0;

static inline bool IsKindOfLoadF3(ShapeLocal* shape, const TypeInfoLocal* type)
{
    for (const TypeInfoLocal* c = shape->GetType(); c; c = c->base)
    {
        if (c == type)
            return true;
    }
    return false;
}
static __forceinline void ClearAndDeallocateLoadF3(ArrayLocal& a)
{
    if ((a.m_uiCapacity & 0x80000000) == 0)
    {
        int n = a.m_uiCapacity & 0x3fffffff;
        hkThreadMemoryLoadF3* mem = (hkThreadMemoryLoadF3*)TlsGetValue(DAT_010f3170);
        mem->FUN_008f6d90(a.m_pData, n * 4, 0x17);
    }
    a.m_pData = 0;
    a.m_uiCount = 0;
    a.m_uiCapacity = (a.m_uiCapacity & 0xc0000000) | 0x80000000;
}
static inline void ReserveLoadF3(ArrayLocal& a, int n)
{
    int capacity = a.m_uiCapacity & 0x3fffffff;
    if (capacity < n)
    {
        int cap2 = capacity * 2;
        int newSize = n < cap2 ? cap2 : n;
        FUN_00901e90(&a, newSize, 4);
    }
}
static inline void PushBackLoadF3(ArrayLocal& a, void* e)
{
    if (a.m_uiCount == (a.m_uiCapacity & 0x3fffffff))
        FUN_00901f10(&a, 4);
    a.m_pData[a.m_uiCount] = e;
    a.m_uiCount++;
}

// pdb: bhkListShape::LinkObject | bhkListShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: arStream
void LoaderLocal::LoadShapes(LoadStreamLocal* stream)
{
    bool shared;
    ListLocal* list = GetList(&shared);
    unsigned int count = stream->NiStream_GetNumberOfLinkIDs();
    if (list)
    {
        ClearAndDeallocateLoadF3(list->items);
        ReserveLoadF3(list->items, count);
        for (unsigned int i = 0; i < count; ++i)
        {
            ShapeLocal* object = stream->FUN_00a63430();
            if (object)
                PushBackLoadF3(list->items, object->object);
        }
        if (stream->version < 17)
        {
            unsigned int size = list->items.m_uiCount;
            for (unsigned int index = 0; index < size; ++index)
            {
                ShapeLocal* entry = (ShapeLocal*)list->items.m_pData[index];
                if (entry && entry->object)
                {
                    ShapeLocal* shape = entry->object;
                    if (!IsKindOfLoadF3(shape, &DAT_0116924c) && !IsKindOfLoadF3(shape, &DAT_010f32f0))
                        goto finished;
                }
            }
            char message[1000];
            sprintf_s(message, 1000,
                      "HAVOK: %s contains an old (Havok 3.3) hkpConvexListShape (%d) and should be re-exported to 17.",
                      &stream->filename, stream->version);
        }
    }
finished:
    FUN_00c84cc0(stream);
}


class S00c8bf40_Flags
{
  public:
    bool FUN_00c84dc0(const S00c8bf40_Flags* pkOther) const;
    bool FUN_00c8bf40(const S00c8bf40_Flags* pkOther) const;
};

// @fnv 0x00c8bf40
// pdb: NiInterpController::CopyMembers | NiInterpController.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: pkDest, kCloning
bool S00c8bf40_Flags::FUN_00c8bf40(const S00c8bf40_Flags* pkOther) const
{
    return FUN_00c84dc0(pkOther);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct FUN_00c6c290
{
    void FUN_00c6b980(int);
};
struct S00c90090_Obj
{
    virtual void S00c90090_v0();
    virtual void S00c90090_v1();
    int m_ref;
};
struct S00c90090_Ptr
{
    S00c90090_Obj* p;
    S00c90090_Ptr(S00c90090_Obj* q) : p(q)
    {
        if (p)
            InterlockedIncrement((long volatile*)&p->m_ref);
    }
    ~S00c90090_Ptr()
    {
        if (p)
        {
            if (!InterlockedDecrement((long volatile*)&p->m_ref))
                p->S00c90090_v1();
        }
    }
};
struct S00c90090_Self
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
    virtual void vf8C(int i);
    int m_p4;
    int m_p8;
    int m_pc;
    S00c90090_Obj* m_p10;
    int m_p14;
    float m_f18;
    float m_f1c;
    int m_p20;
    int m_p24;
    float GetF1C() const
    {
        return m_f1c;
    }
    void SetF1C(float f)
    {
        m_f1c = f;
    }
    float GetF18() const
    {
        return m_f18;
    }
    void SetF18(float f)
    {
        m_f18 = f;
    }
    void FUN_00c90090(S00c90090_Self* src);
};
// Copies src's m_p10 object (via FUN_00c6b980), the two floats and m_p24, then calls vf8C with src->m_p8.
// @fnv 0x00c90090
// pdb: bhkBlendCollisionObjectAddRotation::CopyFrom | bhkBlendCollisionObjectAddRotation.obj | fnv360_0822_retail, call_gap, low
// pdb params: apBlendObj
void S00c90090_Self::FUN_00c90090(S00c90090_Self* src)
{
    S00c90090_Ptr r(src->m_p10);
    ((FUN_00c6c290*)src)->FUN_00c6b980(0);
    ((FUN_00c6c290*)this)->FUN_00c6b980((int)r.p);
    SetF1C(src->GetF1C());
    SetF18(src->GetF18());
    int t24 = src->m_p24;
    m_p24 = t24;
    int n = src->m_p8;
    vf8C(n);
}

extern const float DAT_01017870;
extern const float DAT_010177e8;
extern const float DAT_01018180;
extern const float DAT_01056528;

struct MotionSettings
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
    float first;
    float second;
    int mode;
    void SetPreset(int preset);
};

// Sets first, second, and mode fields from preset-specific constants based on the preset index.
// @f3 0x0090a8b0 (community match, verified in this file)
namespace f3m_0090a8b0 {
struct MotionSettingsView_90a8b0
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
    float first;
    float second;
    int mode;
    __forceinline void SetPreset(int preset)
    {
    switch (preset)
    {
    case 1:
        first = DAT_01017870;
        mode = 2;
        second = DAT_010177e8;
        break;
    case 2:
        first = DAT_01018180;
        mode = 2;
        second = 1.0f;
        break;
    case 3:
        mode = 2;
        first = DAT_010177e8;
        second = DAT_01056528;
        break;
    case 4:
        first = DAT_01017870;
        mode = 4;
        second = DAT_010177e8;
        break;
    case 5:
        first = DAT_01018180;
        mode = 4;
        second = 1.0f;
        break;
    case 6:
        mode = 4;
        first = DAT_010177e8;
        second = DAT_01056528;
        break;
    case 7:
        first = DAT_01017870;
        mode = 8;
        second = DAT_010177e8;
        break;
    case 8:
        first = DAT_01018180;
        mode = 8;
        second = 1.0f;
        break;
    case 9:
        mode = 8;
        first = DAT_010177e8;
        second = DAT_01056528;
        break;
    }
}
};
}

// pdb: hkpWorldCinfo::setupSolverInfo | hkpWorldCinfo.obj | tesv_win, objrun_open, low
void MotionSettings::SetPreset(int preset)
{
    reinterpret_cast<f3m_0090a8b0::MotionSettingsView_90a8b0*>(this)->SetPreset(preset);
}


struct SpawnedAllocHolder;
SpawnedAllocHolder* __cdecl FUN_00c85750();

struct RefObjectC9
{
    virtual void Unknown();
    virtual void Destroy();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            Destroy();
    }
};
struct SmartC9
{
    RefObjectC9* pointer;
    SmartC9(RefObjectC9* p = 0) : pointer(p)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    SmartC9(const SmartC9& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~SmartC9()
    {
        if (pointer)
            pointer->DecRefCount();
    }
    SmartC9& operator=(const SmartC9& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = other.pointer;
            if (pointer)
                pointer->IncRefCount();
        }
        return *this;
    }
};
struct ListC9
{
    SmartC9 item;
    ListC9* next;
    ListC9(const SmartC9& p) : item(p), next(0)
    {}
    __declspec(noinline) void FUN_00631540(const SmartC9& p)
    {
        if (!p.pointer)
            return;
        if (item.pointer)
        {
            ListC9* node = new ListC9(item);
            node->next = next;
            next = node;
        }
        item = p;
    }
};

extern const float DAT_01012054;
extern const double DAT_01017a40;
struct C9A6E0Entry
{
    float fA;
    float fB;
    float fC;
    void Set(float a, float b, float c)
    {
        fA = a;
        fB = b;
        fC = c;
    }
    void Set3(float a, float p)
    {
        float z = (float)(p / 100.0);
        fA = a;
        fB = z;
        fC = z;
    }
};
static inline float Pct(float f)
{
    return (float)(f / 100.0);
}
static inline float Pct2(int f)
{
    return (float)(f / 100.0);
}
struct C9A6E0Array
{
    int unk00;
    C9A6E0Entry* m_pkEntryArray;
    int unk08;
    unsigned int m_uiCount;
    unsigned int m_uiAllocatedCapacity;
    void FUN_00c9a6e0();
};

// Resets all entries to (-1, 0, 0) and zeroes the count and allocated capacity.
// @fnv 0x00c9a6e0
void C9A6E0Array::FUN_00c9a6e0()
{
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        float fZero = Pct(0.0f);
        m_pkEntryArray[i].Set(-1.0f, fZero, fZero);
    }
    m_uiCount = 0;
    m_uiAllocatedCapacity = 0;
}

namespace fnv_00c9a730 {
extern float DAT_01012054;
extern double DAT_01017a40;

}  // namespace fnv_00c9a730

float __cdecl FUN_00a42050(float t, float a, float b);
struct KeyPair
{
    float time;
    float first;
    float second;
};
struct KeyPairInterpolator
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    unsigned int lastIndex;
    int unk38;
    KeyPair* keys;
    int unk40, unk44;
    unsigned int count;
    bool Interpolate(float time, float& first, float& second);
};
// Finds the keys bracketing time, advancing a cached index, and interpolates first and second between them via FUN_00a42050; returns false if there are no keys.
// @fnv 0x00c9a8c0
// pdb: bhkBlendController::CalculateGain | bhkBlendController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: afTime, arGain, arVelGain
bool KeyPairInterpolator::Interpolate(float time, float& first, float& second)
{
    if (count)
    {
        if (count == 1)
        {
            first = keys[0].first;
            second = keys[0].second;
            return true;
        }
        unsigned int last = count - 1;
        float previousTime = keys[lastIndex].time;
        if (time < previousTime)
        {
            lastIndex = 0;
            previousTime = keys[0].time;
        }
        float nextTime = previousTime;
        unsigned int next;
        next = lastIndex + 1;
        __assume(next <= last);
        for (; next <= last; ++next)
        {
            nextTime = keys[next].time;
            if (time <= nextTime)
                break;
            ++lastIndex;
            previousTime = nextTime;
        }
        float delta = nextTime - previousTime;
        float firstValue = keys[lastIndex].first;
        float secondValue = keys[lastIndex].second;
        if (delta != 0.0f)
        {
            float ratio = (time - previousTime) / delta;
            float nextFirst = keys[next].first;
            first = FUN_00a42050(ratio, firstValue, nextFirst);
            float nextSecond = keys[next].second;
            second = FUN_00a42050(ratio, secondValue, nextSecond);
        }
        else
        {
            first = firstValue;
            second = secondValue;
        }
        return true;
    }
    return false;
}

extern __declspec(thread) int DAT_012722b4;

struct TlsGuardS00c9_t
{
    int m_saved;

    TlsGuardS00c9_t()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }

    ~TlsGuardS00c9_t()
    {
        DAT_012722b4 = m_saved;
    }
};

#include <stdlib.h>
struct C00624070
{
    unsigned int value;
    __declspec(noinline) bool FUN_00624070();
};

extern unsigned __int64 selected_target_masks[];

extern unsigned int DAT_01268078[];

__forceinline bool Mask135(unsigned int a, unsigned int b)
{
    return (DAT_01268078[(a >> 8) & 31] & (1 << ((b >> 8) & 31))) != 0;
}

// Returns whether values a and b pass a check using their low 7 layer bits, flag bits, and Mask135 or selected_target_masks lookups.
// @fnv 0x00c84740
// pdb: bhkCollisionFilter::IsCollisionEnabled | bhkCollisionFilter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aInfoA, aInfoB
bool FUN_00c84740(unsigned int a, unsigned int b)
{

    unsigned int cachedA = a;

    unsigned int cachedB = b;

    unsigned int layerA = cachedA & 0x7f;

    if (layerA != 40 && (((unsigned char)(cachedA >> 14) & 1) || ((unsigned char)(cachedB >> 14) & 1)))
        return false;

    if (!(cachedA & 0xffff0000) || !(cachedB & 0xffff0000))
        return true;

    unsigned int different = (cachedA ^ cachedB) & 0xffff0000;

    unsigned int layerB = cachedB & 0x7f;

    if (layerA == 8 && layerB == layerA && !different)
    {

        return Mask135(cachedA, cachedB);
    }

    if (layerA == 8 && layerB == layerA)
        return false;
    if (different)
        return (selected_target_masks[layerA] & (1ULL << layerB)) != 0;

    if ((cachedA & cachedB) & 0x8000)
    {

        if (!(selected_target_masks[layerA] & (1ULL << layerB)))
            return false;

        return abs(int((cachedA >> 8) & 31) - int((cachedB >> 8) & 31)) != 1;
    }

    if (!((C00624070*)&a)->FUN_00624070() || !((C00624070*)&b)->FUN_00624070())
        return false;

    return Mask135(cachedA, cachedB);
}

__declspec(noinline) bool C00624070::FUN_00624070()
{
    unsigned int layer = value & 127;
    return layer == 8 || layer == 29;
}

// @fnv 0x00c85d20
unsigned Apply(unsigned bits, char on)
{
    if (on == 0)
        bits |= 0x4000u;
    else
        bits &= ~0x4000u;
    return bits;
}

struct MemoryCategoryScope_00c89dd0
{
    int previous;
    MemoryCategoryScope_00c89dd0(int* block) : previous(block[0x2b4 / 4])
    {
        block[0x2b4 / 4] = 16;
    }
    ~MemoryCategoryScope_00c89dd0()
    {
        previous = 0;
    }
};

struct PendingAllocation_00c89dd0
{
    void* pointer;
    PendingAllocation_00c89dd0(void* value) : pointer(value)
    {}
    ~PendingAllocation_00c89dd0()
    {
        pointer = 0;
    }
};

SpawnedAllocHolder* FUN_00c85750();

#include <string.h>
struct FUN_00c90030_Matrix
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
};

struct FUN_00c90030_Transform
{
    void* __thiscall FUN_0043f8d0(void* a, void* b, void* c, void* d);
};

struct FUN_00c90030_Result
{
    void* __thiscall FUN_0043f8d0();
};

struct FUN_00c90030_Outer
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
    FUN_00c90030_Transform unk68;
};

struct FUN_00c90030_Source
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

    void __thiscall FUN_00a68bf0();
};

struct FUN_00c90030_holder
{
    void* unk00;
    void* unk04;
    FUN_00c90030_Source* unk08;
    void* unk0C;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    FUN_00c90030_Matrix unk2C;

    void __thiscall UpdateNodeState(int value);
    void __thiscall FUN_00c90030(int value);
};

// If unk10 is set, calls UpdateNodeState; otherwise calls FUN_00a68bf0 on unk08, then computes a transform and copies 9 ints into source at offset 0x68.
// @f3 0x00901ce0 (community match, verified in this file)
// pdb: bhkBlendCollisionObjectAddRotation::UpdateWorldData | bhkBlendCollisionObjectAddRotation.obj | fnv360_0822_retail, caller_sim, low
// pdb params: UpdateData
void __thiscall FUN_00c90030_holder::FUN_00c90030(int aiState)
{
    FUN_00c90030_Matrix local00;
    FUN_00c90030_Matrix local24;

    if (unk10 != 0)
    {
        UpdateNodeState(aiState);
    }
    else if (unk08 != 0)
    {
        unk08->FUN_00a68bf0();
    }

    FUN_00c90030_Matrix matrixCopy = unk2C;
    FUN_00c90030_Source* source = unk08;
    FUN_00c90030_Outer* outer = *reinterpret_cast<FUN_00c90030_Outer**>(reinterpret_cast<char*>(source) + 0x18);

    void* result = outer->unk68.FUN_0043f8d0(&local24, reinterpret_cast<char*>(source) + 0x34, &local00, &matrixCopy);

    FUN_00c90030_Result* resultObject = reinterpret_cast<FUN_00c90030_Result*>(result);

    void* matrix = resultObject->FUN_0043f8d0();

    memcpy(reinterpret_cast<char*>(source) + 0x68, matrix, 9 * sizeof(int));
}


extern char DAT_010c6b0c[];

void* __cdecl NiMalloc(unsigned int size);

struct NiTLargeArrayStub
{
    void* m_vtbl;
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;

    NiTLargeArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_vtbl = &DAT_010c6b04;
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiMaxSize > 0)
            m_pBase = (void**)NiMalloc(sizeof(void*) * m_uiMaxSize);
        else
            m_pBase = 0;
    }
};

struct NiTLargePrimitiveArrayStub : NiTLargeArrayStub
{
    NiTLargePrimitiveArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTLargeArrayStub(uiMaxSize, uiGrowBy)
    {
        m_vtbl = DAT_010c6b0c;
    }
    ~NiTLargePrimitiveArrayStub();
};

struct BaseC9
{
    virtual void v00();
    int unk04[0xc];
    BaseC9();
    ~BaseC9();
};

struct FUN_00c9aeb0 : BaseC9
{
    int unk34;
    NiTLargePrimitiveArrayStub m_kArray;
    float unk50;
    float unk54;
    int unk58;

    virtual void v00();
    FUN_00c9aeb0();
};

// Initializes the FUN_00c9aeb0 object by zeroing unk34, setting unk50 and unk54 to -1.0f, and zeroing unk58.
// @f3 0x00914c20 (community match, verified in this file)
// pdb: bhkBlendController::bhkBlendController | bhkBlendController.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: BSLagBoneController::BSLagBoneController)
FUN_00c9aeb0::FUN_00c9aeb0()
{
    unk34 = 0;
    unk50 = -1.0f;
    unk54 = -1.0f;
    unk58 = 0;
    m_kArray.m_uiGrowBy = 4;
}


extern int DAT_011f4428;

struct S00c81c50_Obj;
struct S00c81c50_Arr
{
    S00c81c50_Obj** data;
    unsigned short cap;
    unsigned short size;
    unsigned short esize;
    unsigned short grow;
    unsigned short GetSize() const
    {
        return size;
    }
    S00c81c50_Obj* GetAt(unsigned int i) const
    {
        return data[i];
    }
};

struct S00c81c50_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00c81c50_Obj* IsSceneNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S00c81c50_Obj* collision;
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
    S00c81c50_Arr children;

    S00c81c50_Obj* FUN_00653290(int* rtti);

    __forceinline S00c81c50_Obj* GetCollision()
    {
        S00c81c50_Obj* c = collision;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_01267e64);
    }
    __forceinline S00c81c50_Obj* FirstNode()
    {
        S00c81c50_Obj* c = children.size > 0 ? children.data[0] : 0;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_011f4428);
    }
};

struct S00c81c50_Ptr
{
    S00c81c50_Obj* m_p;
    S00c81c50_Ptr(S00c81c50_Obj* p) : m_p(p)
    {}
    S00c81c50_Ptr& operator=(S00c81c50_Obj* p)
    {
        m_p = p;
        return *this;
    }
    operator S00c81c50_Obj*() const
    {
        return m_p;
    }
};

// Returns pkNode's collision object, else searches its first node, a child chosen by esize, and that child's children for one; returns null if none.
// @f3 0x008f3950 (community match, verified in this file)
S00c81c50_Obj* __cdecl FUN_007235f0(S00c81c50_Obj* pkNode);
S00c81c50_Obj* __cdecl FUN_00424d50(int* pkRTTI, S00c81c50_Obj* pkObject);
extern int DAT_0108f200;
static inline S00c81c50_Obj* NodeGetAt(S00c81c50_Obj* pkParent, unsigned int i)
{
    return i >= pkParent->children.GetSize() ? 0 : pkParent->children.GetAt(i);
}
// pdb: bhkBlendCollisionObject::GetFirstCollisionObject | bhkBlendCollisionObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apBip
void* __cdecl FUN_00c81c50(S00c81c50_Obj* pkNode)
{
    S00c81c50_Obj* pkResult = 0;
    if (pkNode)
    {
        pkResult = FUN_007235f0(pkNode);
        if (!pkResult)
        {
            S00c81c50_Obj* pkParent = pkNode;
            pkNode = FUN_00424d50(&DAT_0108f200, NodeGetAt(pkParent, 0));
            if (pkNode)
                pkResult = FUN_007235f0(pkNode);
            if (!pkResult)
            {
                pkNode = FUN_00424d50(&DAT_0108f200, NodeGetAt(pkParent, 0));
                if (pkNode)
                    pkResult = FUN_007235f0(pkNode);
            }
            if (!pkNode)
                pkNode = pkParent;
            if (!pkResult)
            {
                unsigned int idx = pkNode->children.esize != 1;
                if (pkNode->children.size > idx)
                {
                    pkNode = pkNode->children.data[idx];
                    if (pkNode)
                    {
                        pkResult = FUN_007235f0(pkNode);
                        if (!pkResult)
                        {
                            S00c81c50_Obj* pkNodeNode = pkNode->IsSceneNode();
                            if (pkNodeNode)
                            {
                                for (unsigned int i = 0; i < pkNodeNode->children.GetSize(); i++)
                                {
                                    pkResult = FUN_007235f0(pkNodeNode->children.GetAt(i));
                                    if (pkResult)
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return pkResult;
}


struct Z577
{
    unsigned char index;
    void __thiscall FUN_00ca9360(float* value);
};

struct Y577
{
    unsigned char unk00[0xbd];
    Z577 z;
};

struct A577
{
    Y577* __thiscall FUN_00ca86c0();
    unsigned char unk00[0x19d];
    unsigned char unk19d;
};

struct S_00c8cd20_object
{
    unsigned int unk00;
    unsigned int unk04;
    A577* unk08;

    float __thiscall GetFloatValue();
};

// Returns the DAT_010c7948 entry for a Z577's index (from the owner's FUN_00ca86c0 result, or a local one filled via FUN_00ca9360), else 0.0.
// @f3 0x004e6160 (community match, verified in this file)
extern float DAT_00e35180[];
struct Z577F3
{
    unsigned char index;
    void __thiscall FUN_0090aba0(float* value);
};
struct Y577F3
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
    Z577F3 z;
};
struct A577F3
{
    Y577F3* __thiscall hkpRigidBody_getStoredDynamicMotion();
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
    unsigned char unk18C;
};
// pdb: bhkRigidBody::GethkMaxLinearVelocity | TESObjectREFR.obj | fnv360_0822_retail, call_gap, medium
float __thiscall S_00c8cd20_object::GetFloatValue()
{
    volatile float ret;
    if (this && this->unk08)
    {
        A577F3* owner = (A577F3*)this->unk08;
        Y577F3* result = owner->hkpRigidBody_getStoredDynamicMotion();
        Z577F3* z;
        Z577F3 local_z;
        if (result)
        {
            z = &result->z;
        }
        else
        {
            ret = DAT_00e35180[owner->unk18C];
            local_z.FUN_0090aba0((float*)&ret);
            z = &local_z;
        }
        ret = DAT_00e35180[z->index];
        return ret;
    }
    ret = 0.0f;
    return ret;
}


extern __declspec(thread) int g_tlsMemContext;

struct S00c89ec0_Scope
{
    int saved;
    S00c89ec0_Scope()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 0x10;
    }
    ~S00c89ec0_Scope()
    {
        g_tlsMemContext = saved;
    }
};

struct S00c89ec0_Res
{
    bool FUN_00c68d50(int key);
};

struct S00c89ec0_Owner
{
    int unk00;
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
    S00c89ec0_Res* unk350;
    S00c89ec0_Res* GetRes()
    {
        return unk350;
    }
};

__declspec(noinline) int __stdcall FUN_00c84ec0(void* apObject);

struct ShareChildShape
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
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
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual bool V52(int a1);
};

struct ShareChildObject
{
    int unk0;
    int unk4;
    ShareChildShape* shape;
};

struct ShareChildEntry
{
    ShareChildObject* pObj;
    int unk4;
    int unk8;
    int unkC;
};

struct ShareListData : hkpListShapeStub
{
    int unk14;
    ShareChildEntry* arr;
};

class ListShapeSharingView : public bhkListShapeStub
{
  public:
    __forceinline ShareListData* GetNode()
    {
        return this != 0 ? (ShareListData*)m_pHavokObject : 0;
    }

    unsigned char FUN_00c8b440(int a1);
};

// Returns FUN_00c84ec0(a1) ANDed with V52(a1) of each non-null child shape in the list, stopping early once the result is zero.
// @f3 0x008fd150 (community match, verified in this file)
// pdb: bhkListShape::CanShare | bhkListShape.obj | fnv360_0721_beta, objrun_sim, low
// pdb params: arCloneData
unsigned char ListShapeSharingView::FUN_00c8b440(int a1)
{
    unsigned char result = (unsigned char)FUN_00c84ec0((void*)a1);
    while (true)
    {
        if (result == 0)
        {
            break;
        }
        int count;
        if (ShareListData* pNode = GetNode())
        {
            count = pNode->kContainer.GetNumChildShapes();
        }
        else
        {
            count = 0;
        }
        int i = 0;
        do
        {
            if (i >= count)
            {
                break;
            }
            if (ShareListData* pNode = GetNode())
            {
                ShareChildObject* pObj = pNode->arr[i].pObj;
                if (pObj != 0)
                {
                    ShareChildShape* q = pObj->shape;
                    if (q != 0)
                    {
                        typedef bool (__thiscall* ShapeSlot51)(void* self, int a1);
                        result &= (unsigned char)((ShapeSlot51)(*(void***)q)[51])(q, a1);
                    }
                }
            }
            i++;
        } while (result != 0);
        break;
    }
    return result;
}


struct c9b090_material
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float first, second;
};
struct c9b090_owner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    DynCastHelper* helper;
};
struct Target_c9b090
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
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual float compute(float);
    unsigned int unk04;
    unsigned short flags, unk0a;
    unsigned int unk0c, unk10, unk14;
    float time;
    unsigned int unk1c;
    float lastTime;
    unsigned int unk24, unk28;
    c9b090_owner* object;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    void* data;
    unsigned int unk4c;
    float savedFirst, savedSecond;
    bool IsActive() const
    {
        return (flags >> 3) & 1;
    }
    bool MustReset() const
    {
        return (flags >> 6) & 1;
    }
    void FUN_00c9b090(float* input);
};
// @f3 0x009151c0 (community match, verified in this file)
struct FUN_00914a50_obj
{
    void FUN_00914a50();
};
struct FUN_00914a90_obj
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    short unk0a;
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
    float unk50;
    float unk54;
    __declspec(noinline) void __thiscall FUN_00914a90(int param2);
};

// If the flag bit in unk09 is set and unk50 is non-negative, writes unk50 and unk54 into param2 at offsets 0x18/0x1c and resets both to -1.0f.
// @fnv 0x00c9abc0
__declspec(noinline) void __thiscall FUN_00914a90_obj::FUN_00914a90(int param2)
{
    if ((unk09 & 1) != 0 && unk50 >= 0.0f)
    {
        *(float*)(param2 + 0x18) = unk50;
        *(float*)(param2 + 0x1c) = unk54;
        unk50 = unk54 = -1.0f;
    }
    return;
}

// pdb: bhkBlendController::Update | bhkBlendController.obj | fnv360_0822_retail, caller_sim, low
// pdb params: UpdateData
void Target_c9b090::FUN_00c9b090(float* apTime)
{
    if (!object || !IsActive() || !data)
        return;
    c9b090_material* mat = (c9b090_material*)FUN_007235f0(object);
    if (mat)
    {
        float value = compute(*apTime);
        float first, second;
        if (((KeyPairInterpolator*)this)->Interpolate(value, first, second))
        {
            if (savedFirst < 0.0f)
            {
                savedFirst = mat->first;
                savedSecond = mat->second;
            }
            mat->first = first;
            mat->second = second;
        }
        if (value == time && (flags & 6) == 4)
        {
            if (MustReset())
                ((FUN_00c9a820_class*)this)->Reset();
            ((FUN_00914a50_obj*)this)->FUN_00914a50();
            ((FUN_00914a90_obj*)this)->FUN_00914a90((int)mat);
            v90();
        }
        return;
    }
    lastTime = *apTime;
}

