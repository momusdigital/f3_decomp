#include <windows.h>
// src/f3staging/f3blk_00840000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008534e0 (community match, verified in this file)
namespace f3m_008534e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct FUN_008534e0_RefObj
{
    virtual void v00();
    virtual void v04();
    long m_iRefCount;
};

struct FUN_008534e0_Ptr
{
    FUN_008534e0_RefObj* m_p;
    FUN_008534e0_Ptr() : m_p(0) {}
};

inline void FUN_008534e0_Release(FUN_008534e0_RefObj* p)
{
    if (p)
    {
        FUN_008534e0_RefObj* q = p;
        if (InterlockedDecrement(&q->m_iRefCount) == 0)
            q->v04();
    }
}

struct FUN_008534e0_shell
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
    void** m_ppChildrenA0;
    short unkA4;
    unsigned short m_countA6;
    int unkA8;
    int unkAC;
    int m_iLastChildB0;
    int unkB4;
    int m_flagB8;
    int unkBC;
    void** m_ppBlocksC0;
    short unkC4;
    unsigned short m_countC6;
    unsigned short m_usedC8;

    void FUN_0082e590(unsigned int uiIndex, FUN_008534e0_Ptr& spChild);
    void FUN_008534e0(unsigned int uiIndex, FUN_008534e0_Ptr& spChildOut);
};

// pdb: NiSwitchNode::DetachChildAt | NiSwitchNode.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: NiSwitchNode::DetachChild)
// pdb params: i, aspAVObject
void FUN_008534e0_shell::FUN_008534e0(unsigned int uiIndex, FUN_008534e0_Ptr& spChildOut)
{
    m_flagB8 = 1;
    if (uiIndex < m_countA6)
    {
        if (uiIndex < m_countC6)
        {
            void* p = m_ppBlocksC0[uiIndex];
            m_ppBlocksC0[uiIndex] = 0;
            if (p)
                m_usedC8 += static_cast<unsigned short>(0xffff);
            if (uiIndex == static_cast<unsigned short>(m_countC6 - 1))
                m_countC6 = static_cast<unsigned short>(m_countC6 - 1);
        }
    }

    FUN_008534e0_Ptr spChild;
    FUN_0082e590(uiIndex, spChild);

    if (m_iLastChildB0 > -1 && (m_iLastChildB0 >= m_countA6 || !m_ppChildrenA0[m_iLastChildB0]))
        m_iLastChildB0 = -1;

    if (spChildOut.m_p != spChild.m_p)
    {
        FUN_008534e0_Release(spChildOut.m_p);
        spChildOut.m_p = spChild.m_p;
        if (spChild.m_p)
            InterlockedIncrement(&spChild.m_p->m_iRefCount);
        else
            return;
    }
    FUN_008534e0_Release(spChild.m_p);
}
}   // namespace f3m_008534e0

// @f3 0x00846060 (community match, verified in this file)
void __cdecl FUN_0089e890(void* pointer);
void __cdecl FUN_0089ec10(void* pointer, unsigned int bytes);
struct Heap846060 { void FUN_0086ba60(void* pointer); };
extern Heap846060 DAT_01090a78;
extern const int DAT_00e233d4;
struct Nested846060 { void FUN_00845fc0(unsigned int flags); };
struct Owned846060 {
    void* data;
    int unk04,unk08,unk0c;
    Nested846060* nested;
};
struct Owner846060 {
    const void* table;
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44;
    void* list;
    void* tail;
    int unk50;
    Owned846060* shared;
    void FUN_008557c0();
    Owner846060* FUN_00846060(unsigned int flags);
};
// pdb: NiTriShapeData::`vector deleting destructor' | NiTriShapeData.obj | tesv_win, vtable_prefix, medium
Owner846060* Owner846060::FUN_00846060(unsigned int flags) {
    table = &DAT_00e233d4;
    if (list) FUN_0089e890(list);
    Owned846060* owned = shared;
    if (owned) {
        FUN_0089e890(owned->data);
        if (owned->nested) owned->nested->FUN_00845fc0(1);
        DAT_01090a78.FUN_0086ba60(owned);
    }
    DAT_01090a78.FUN_0086ba60(tail);
    FUN_008557c0();
    if (flags & 1) FUN_0089ec10(this, sizeof(Owner846060));
    return this;
}

// @f3 0x008557a0 (community match, verified in this file)
namespace f3m_008557a0 {
struct Base8557a0 { virtual ~Base8557a0(); virtual void v4(); int pad[15]; Base8557a0(); };
struct FUN_008557a0 : Base8557a0 { unsigned short value; virtual ~FUN_008557a0(); FUN_008557a0(); };
// pdb: NiTriBasedGeomData::NiTriBasedGeomData | NiTriBasedGeomData.obj | fnv360_0822_retail, call_seq, high
FUN_008557a0::FUN_008557a0() { value = 0; }
}   // namespace f3m_008557a0

// @f3 0x0085e250 (community match, verified in this file)
extern unsigned int FUN_00e2562c;
namespace f3m_0085e250 {

extern "C" void* __cdecl FUN_0089eb90(unsigned int size);

struct FUN_00840400_This {
    void FUN_00840400();
};


// pdb: NiTriStripsDynamicData::CreateObject | NiTriStripsDynamicData.obj | fnv360_0822_retail, objrun_prop, low
unsigned int* __cdecl FUN_0085e250() {

    unsigned int* esi_val = static_cast<unsigned int*>(FUN_0089eb90(0x54));

    if (esi_val != 0) {

        FUN_00840400_This* obj = reinterpret_cast<FUN_00840400_This*>(esi_val);
        obj->FUN_00840400();

        esi_val[0] = reinterpret_cast<unsigned int>(&FUN_00e2562c);

        char* base = reinterpret_cast<char*>(esi_val);
        *reinterpret_cast<unsigned short*>(base + 0x50) = 0;
        *reinterpret_cast<unsigned short*>(base + 0x52) = 0;

        return esi_val;
    }
    return 0;
}
}   // namespace f3m_0085e250

// @f3 0x00848ed0 (community match, verified in this file)
namespace f3m_00848ed0 {
struct P848ed0 { char pad[0xc]; int f; };
struct O848ed0 { void FUN_00848700(int v); void FUN_0082d9f0(P848ed0* p); void NiBillboardNode_OnVisible(P848ed0* p); };
// pdb: NiBillboardNode::OnVisible | NiBillboardNode.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void O848ed0::NiBillboardNode_OnVisible(P848ed0* p) { FUN_00848700(p->f); FUN_0082d9f0(p); }
}   // namespace f3m_00848ed0

// @f3 0x0084be60 (community match, verified in this file)
namespace f3m_0084be60 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B84be60 { virtual ~B84be60(); virtual void v4(); int pad[21]; B84be60() throw(); };
struct D84be60 : B84be60 { unsigned short w58, w5a; virtual ~D84be60(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D84be60() throw(); };
D84be60::D84be60() throw() { w58 = 0; w5a = 0; }
D84be60* __cdecl FUN_0084be60() { return new D84be60(); }
}   // namespace f3m_0084be60

// @f3 0x0085d6f0 (community match, verified in this file)
extern const char* DAT_01090864;
namespace f3m_0085d6f0 {
namespace register_name_0085d6f0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0083bd00(NameArray*);
    void FUN_0085d6f0(NameArray*);
};
// pdb: NiScreenSpaceCamera::GetViewerStrings | NiOldScreenSpace.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_0085d6f0(NameArray* names) {
    FUN_0083bd00(names);
    void* value=FUN_00847b50(DAT_01090864);
    names->Append(value);
}
}

}   // namespace f3m_0085d6f0

// @f3 0x0085d200 (community match, verified in this file)
extern const char* DAT_01090854;
namespace f3m_0085d200 {
namespace register_name_0085d200 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0083f700(NameArray*);
    void FUN_0085d200(NameArray*);
};
// pdb: NiScreenGeometry::GetViewerStrings | NiOldScreenSpace.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkStrings
void Object::FUN_0085d200(NameArray* names) {
    FUN_0083f700(names);
    void* value=FUN_00847b50(DAT_01090854);
    names->Append(value);
}
}

}   // namespace f3m_0085d200

// @f3 0x0085a210 (community match, verified in this file)
extern const char* DAT_01090700;
namespace f3m_0085a210 {
namespace register_name_0085a210 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00825b40(NameArray*);
    void FUN_0085a210(NameArray*);
};
// pdb: Ni2DBuffer::GetViewerStrings | Ni2DBuffer.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkStrings
void Object::FUN_0085a210(NameArray* names) {
    FUN_00825b40(names);
    void* value=FUN_00847b50(DAT_01090700);
    names->Append(value);
}
}

}   // namespace f3m_0085a210

// @f3 0x008562c0 (community match, verified in this file)
extern const char* DAT_01090608;
namespace f3m_008562c0 {
namespace register_name_008562c0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_00825b40(NameArray*);
    void FUN_008562c0(NameArray*);
};
// pdb: NiPalette::GetViewerStrings | NiPalette.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkStrings
void Object::FUN_008562c0(NameArray* names) {
    FUN_00825b40(names);
    void* value=FUN_00847b50(DAT_01090608);
    names->Append(value);
}
}

}   // namespace f3m_008562c0

// @f3 0x00855450 (community match, verified in this file)
extern const char* DAT_01090574;
namespace f3m_00855450 {
namespace register_name_00855450 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0084ba30(NameArray*);
    void FUN_00855450(NameArray*);
};
// pdb: NiTriBasedGeom::GetViewerStrings | NiTriBasedGeom.obj | fnv360_0822_retail, call_gap, low
// pdb params: pkStrings
void Object::FUN_00855450(NameArray* names) {
    FUN_0084ba30(names);
    void* value=FUN_00847b50(DAT_01090574);
    names->Append(value);
}
}

}   // namespace f3m_00855450

// @f3 0x00851890 (community match, verified in this file)
extern const char* DAT_01090528;
extern const char DAT_00e24058[];
namespace f3m_00851890 {
namespace extended_names_00851890 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847d80(const char*,unsigned int);
struct Object {
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int value;
    void FUN_0083f700(NameArray*);
    void FUN_00851890(NameArray*);
};
// pdb: BSResizableTriShape::GetViewerStrings | BSResizableTriShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void Object::FUN_00851890(NameArray* names) {
    FUN_0083f700(names);
    void* handle=FUN_00847b50(DAT_01090528);
    names->Append(handle);
    handle=FUN_00847d80(DAT_00e24058,value);
    names->Append(handle);
}
}
}   // namespace f3m_00851890

// @f3 0x008556c0 (community match, verified in this file)
extern const char* DAT_0109057c;
extern const char DAT_00e24c08[];
namespace f3m_008556c0 {
namespace extended_008556c0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847e20(const char*,unsigned int);
struct Object {
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
    unsigned int value;
    void FUN_00832be0(NameArray*);
    void FUN_008556c0(NameArray*);
};
// pdb: NiLinesData::GetViewerStrings | NiLinesData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void Object::FUN_008556c0(NameArray* names) {
    FUN_00832be0(names);
    void* handle=FUN_00847b50(DAT_0109057c);
    names->Append(handle);
    handle=FUN_00847e20(DAT_00e24c08,value);
    names->Append(handle);
}
}
}   // namespace f3m_008556c0

// @f3 0x00849d40 (community match, verified in this file)
extern const char* DAT_0108f4b8;
extern const char DAT_00e23860[];
namespace f3m_00849d40 {
namespace extended_00849d40 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847d80(const char*,unsigned int);
struct Object {
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
    unsigned int value;
    void FUN_0083e180(NameArray*);
    void FUN_00849d40(NameArray*);
};
// pdb: BSPackedAdditionalGeometryData::GetViewerStrings | BSPackedAdditionalGeometryData.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void Object::FUN_00849d40(NameArray* names) {
    FUN_0083e180(names);
    void* handle=FUN_00847b50(DAT_0108f4b8);
    names->Append(handle);
    handle=FUN_00847d80(DAT_00e23860,value);
    names->Append(handle);
}
}
}   // namespace f3m_00849d40

// @f3 0x0085bd20 (community match, verified in this file)
namespace f3m_0085bd20 {
namespace f3m_0085bd20 { extern void** DAT_0109083c; extern unsigned int DAT_01090844; }
// pdb: NiMaterialLibrary::~NiMaterialLibrary | NiMaterialLibrary.obj | fnv360_0721_beta, objrun_prop, low
void __cdecl FUN_0085bd20(void* p) { using namespace f3m_0085bd20; unsigned int n = DAT_01090844; for (unsigned int i = 0; i < n; i++) { if (DAT_0109083c[i] == p) { if ((int)i >= 0) { n = n - 1; DAT_01090844 = n; DAT_0109083c[i] = DAT_0109083c[n]; } return; } } }
}   // namespace f3m_0085bd20

// @f3 0x0084a860 (community match, verified in this file)
extern const char* DAT_0108f4cc;
namespace f3m_0084a860 {
namespace viewer_0084a860 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void AppendSpecificInfo(NameArray*);
    void FUN_00825b40(NameArray*);
    void FUN_0084a860(NameArray*);
};
// pdb: NiCollisionObject::GetViewerStrings | NiCollisionObject.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkStrings
void Object::FUN_0084a860(NameArray* names) {
    FUN_00825b40(names);
    void* handle=FUN_00847b50(DAT_0108f4cc);
    names->Append(handle);
    AppendSpecificInfo(names);
}
}
}   // namespace f3m_0084a860

// @f3 0x008558d0 (community match, verified in this file)
extern const char* DAT_01090584;
extern const char DAT_00e24cd0[];
namespace f3m_008558d0 {
namespace viewer_008558d0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847ce0(const char*,unsigned short);
struct Object {
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
    unsigned short value;
    void FUN_00832be0(NameArray*);
    void FUN_008558d0(NameArray*);
};
// pdb: NiTriBasedGeomData::GetViewerStrings | NiTriBasedGeomData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void Object::FUN_008558d0(NameArray* names) {
    FUN_00832be0(names);
    void* handle=FUN_00847b50(DAT_01090584);
    names->Append(handle);
    handle=FUN_00847ce0(DAT_00e24cd0,value);
    names->Append(handle);
}
}
}   // namespace f3m_008558d0

// @f3 0x008448e0 (community match, verified in this file)
namespace f3m_008448e0 {
namespace task0779 {
struct NiPalette;
struct PixelLayout { unsigned int m_uiRedMask, m_uiGreenMask; };
void* __cdecl FUN_00bffa60(void*, const void*, unsigned int);
// @fnv 0x00a7a160
// pdb: NiDevImageConverter::Convert24ToRGB24 | NiDevImageConverter.obj | fnv360_0822_retail, objrun, medium
// pdb params: uiWidth, uiHeight, uiDestSize, pucDest, pkSrcPal, kDestBits, pucSrc, kSrcBits
void __cdecl FUN_008448e0(unsigned int uiWidth, unsigned int uiHeight, unsigned int, unsigned char* pDst,
                          const NiPalette*, const PixelLayout&,
                          const unsigned char* pSrc, const PixelLayout& kSrcBits)
{
    if (kSrcBits.m_uiGreenMask == 0xFF00u)
    {
        if (kSrcBits.m_uiRedMask == 0xFF0000u)
        {
            if (uiHeight <= 0)
                return;
            unsigned int y = uiHeight;
            const unsigned char* src = pSrc;
            unsigned char* dst = pDst;
            do
            {
                if (uiWidth > 0)
                {
                    unsigned int x = uiWidth;
                    do
                    {
                        *dst++ = src[2];
                        *dst++ = src[1];
                        *dst++ = src[0];
                        src += 3;
                    } while (--x);
                }
            } while (--y);
        }
        else if (kSrcBits.m_uiRedMask == 0xFFu)
        {
            FUN_00bffa60(pDst, pSrc, uiWidth * uiHeight * 3);
        }
    }
}

}
}   // namespace f3m_008448e0

// @f3 0x00845fe0 (community match, verified in this file)
namespace f3m_00845fe0 {
struct Owned845fe0 {
    void FUN_00846030();
};

struct Owner845fe0 {
    const void* table;
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44;
    void* list;
    void* tail;
    int unk50;
    Owned845fe0* shared;
    void FUN_008557c0();
    void FUN_00845fe0();
};

// pdb: NiTriShapeData::~NiTriShapeData | NiTriShapeData.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: NiTriShapeData::GetTriList)
void Owner845fe0::FUN_00845fe0() {
    table = &DAT_00e233d4;
    if (list) FUN_0089e890(list);
    Owned845fe0* owned = shared;
    if (owned) {
        owned->FUN_00846030();
        DAT_01090a78.FUN_0086ba60(owned);
    }
    DAT_01090a78.FUN_0086ba60(tail);
    FUN_008557c0();
}
}   // namespace f3m_00845fe0

// @f3 0x0085be90 (community match, verified in this file)
extern const int DAT_00e251cc;
extern const int DAT_00db7764;
extern char* DAT_00e207a8;
extern long DAT_0108ed80;
namespace f3m_0085be90 {


void __cdecl FUN_0085bd20(void* object);
void __cdecl FUN_0089ec10(void* pointer, unsigned int bytes);

struct Owner85be90 {
    const void* table;
    long refCount;
    char* name;
    Owner85be90* NiMaterialLibrary(unsigned int flags);
};

Owner85be90* Owner85be90::NiMaterialLibrary(unsigned int flags) {
    table = &DAT_00e251cc;
    FUN_0085bd20(this);
    if (name != DAT_00e207a8) InterlockedDecrement((long*)(name - 8));
    table = &DAT_00db7764;
    InterlockedDecrement(&DAT_0108ed80);
    if (flags & 1) FUN_0089ec10(this, sizeof(Owner85be90));
    return this;
}
}   // namespace f3m_0085be90

// @f3 0x008404a0 (community match, verified in this file)
namespace f3m_008404a0 {
namespace task1296 {
void* __cdecl FUN_0089eb90(unsigned);extern int DAT_00e231b4;
struct Object{int* vtable;
unsigned u4;
unsigned u8;
unsigned uc;
unsigned u10;
unsigned u14;
unsigned u18;
unsigned u1c;
unsigned u20;
unsigned u24;
unsigned u28;
unsigned u2c;
unsigned u30;
unsigned u34;
unsigned u38;
unsigned u3c;
unsigned u40;
unsigned short count,unknown46;void* items;void* other;void FUN_008557a0();};
// pdb: NiTriStripsData::CreateObject | NiTriStripsData.obj | tesv_win, caller_sim, low
void* __cdecl FUN_008404a0(){Object*p=(Object*)FUN_0089eb90(0x50);if(p){p->FUN_008557a0();p->vtable=&DAT_00e231b4;p->count=0;p->items=0;p->other=0;return p;}return 0;}
}
}   // namespace f3m_008404a0

// @f3 0x0085bd60 (community match, verified in this file)
#include <windows.h>
namespace f3m_0085bd60 {
// pdb: NiTSet<NiMaterialLibrary *,NiTMallocInterface<NiMaterialLibrary *> >::Add | NiMaterialLibrary.obj | fnv360_0721_beta, objrun, medium
// pdb params: element
namespace Task85bd{struct Owner;extern int DAT_00e251cc,DAT_00db7764;extern void* DAT_00e207a8;extern long DAT_0108ed80;void __cdecl FUN_0085bd20(Owner*);struct Owner{void*methods;int unk04;void*value;~Owner();};Owner::~Owner(){methods=&DAT_00e251cc;FUN_0085bd20(this);if(value!=DAT_00e207a8)InterlockedDecrement((long*)value-2);methods=&DAT_00db7764;InterlockedDecrement(&DAT_0108ed80);}}
}   // namespace f3m_0085bd60

// @f3 0x00845ee0 (community match, verified in this file)
#include <string.h>
namespace f3m_00845ee0 {
struct ComparedBuffer {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; unsigned count;unsigned short* data;bool FUN_008557e0(ComparedBuffer*);bool FUN_00845ee0(ComparedBuffer*);};
// pdb: NiTriShapeData::IsEqual | NiTriShapeData.obj | fnv360_0822_retail, objopen_prop, low, conflict (skyrim: NiTriStripsData::IsEqual)
// pdb params: pkObject
bool ComparedBuffer::FUN_00845ee0(ComparedBuffer* other){if(!FUN_008557e0(other))return false;if(count!=other->count)return false;if(memcmp(data,other->data,count*2))return false;return true;}
}   // namespace f3m_00845ee0

// @f3 0x008516a0 (community match, verified in this file)
namespace f3m_008516a0 {
struct T8516a0 { int a0; int a4; volatile int a8; volatile float ac; };
struct O8516a0 { unsigned int unk_pad_0, unk_pad_4, unk_pad_8, unk_pad_12, unk_pad_16, unk_pad_20, unk_pad_24, unk_pad_28; T8516a0* t; unsigned int unk_pad2_0, unk_pad2_4, unk_pad2_8, unk_pad2_12, unk_pad2_16, unk_pad2_20, unk_pad2_24, unk_pad2_28, unk_pad2_32, unk_pad2_36, unk_pad2_40, unk_pad2_44, unk_pad2_48, unk_pad2_52, unk_pad2_56, unk_pad2_60, unk_pad2_64, unk_pad2_68, unk_pad2_72, unk_pad2_76, unk_pad2_80, unk_pad2_84, unk_pad2_88, unk_pad2_92, unk_pad2_96, unk_pad2_100, unk_pad2_104, unk_pad2_108, unk_pad2_112, unk_pad2_116, unk_pad2_120, unk_pad2_124, unk_pad2_128, unk_pad2_132, unk_pad2_136, unk_pad2_140, unk_pad2_144, unk_pad2_148, unk_pad2_152, unk_pad2_156, unk_pad2_160; int c8; int cc; volatile int d0; float d4; void FUN_008516a0(int a, int b, int c, float d); };
// pdb: BSResizableTriShape::SetLocalBound | BSResizableTriShape.obj | fnv360_0721_beta, objrun_sim, low
// pdb params: aBound
void O8516a0::FUN_008516a0(int a,int b,int c,float d) { c8=a; cc=b; d0=c; d4=d; T8516a0* p=t; p->a0=a; p->ac=d; p->a4=b; p->a8=c; }
}   // namespace f3m_008516a0

// @f3 0x00845700 (community match, verified in this file)
extern int DAT_00e232cc;
namespace f3m_00845700 {
namespace w845700 {
extern long (__stdcall* const DAT_00d9b06c)(volatile long*,long,long);
struct Gate { volatile long owner; long count; void FUN_00409a80(const char*); long OwnerValue() const { return owner; } void Unlock() { if(--count==0) { long thread=OwnerValue(); DAT_00d9b06c(&owner,0,thread); } } }; extern Gate DAT_0106e5a0;
struct Item { void** table; void Destroy() { ((void(__thiscall*)(Item*,unsigned))table[0])(this,1); } };
struct Node { Node* next; Node* prev; Item* item; }; extern Node* DAT_0106e588;
void Free(Node* node) { node->item=0; DAT_0106e5a0.FUN_00409a80(0); node->prev=0; node->next=DAT_0106e588; DAT_0106e588=node; DAT_0106e5a0.Unlock(); }
struct List { Node* head; Node* tail; unsigned count; Item* Remove() { Node* node=head; head=node->next; if(head) head->prev=0; else tail=0; Item* item=node->item; Free(node); count+=-1; return item; } void FUN_00bd12d0(); };
struct Member { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; void FUN_00c24b70(); };
struct Owner { void* table; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0; int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0; int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc; int unk400; int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420; int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c; int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c; int unk480; int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c; int unk4a0; int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc; int unk4c0; int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc; int unk4e0; int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc; int unk500; int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c; int unk520; int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c; int unk540; int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c; int unk560; int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c; int unk580; int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c; int unk5a0; int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc; int unk5c0; int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc; int unk5e0; int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc; int unk600; int unk604; int unk608; int unk60c; int unk610; int unk614; int unk618; int unk61c; int unk620; int unk624; int unk628; int unk62c; int unk630; int unk634; int unk638; int unk63c; int unk640; int unk644; int unk648; int unk64c; int unk650; int unk654; int unk658; int unk65c; int unk660; int unk664; int unk668; int unk66c; int unk670; int unk674; int unk678; int unk67c; int unk680; int unk684; int unk688; int unk68c; int unk690; int unk694; int unk698; int unk69c; int unk6a0; int unk6a4; int unk6a8; int unk6ac; int unk6b0; int unk6b4; int unk6b8; int unk6bc; int unk6c0; int unk6c4; int unk6c8; int unk6cc; int unk6d0; int unk6d4; int unk6d8; int unk6dc; int unk6e0; int unk6e4; int unk6e8; int unk6ec; int unk6f0; int unk6f4; int unk6f8; int unk6fc; int unk700; int unk704; int unk708; int unk70c; int unk710; int unk714; int unk718; int unk71c; int unk720; int unk724; int unk728; int unk72c; int unk730; int unk734; int unk738; int unk73c; int unk740; int unk744; int unk748; int unk74c; int unk750; int unk754; int unk758; int unk75c; int unk760; int unk764; int unk768; int unk76c; int unk770; int unk774; int unk778; int unk77c; Member member; List list; void FUN_00840c70(); void FUN_00845700(); };
// pdb: NiDevImageConverter::~NiDevImageConverter | NiDevImageConverter.obj | fnv360_0822_retail, caller_sim, medium
void Owner::FUN_00845700() { table=&DAT_00e232cc; while(list.count) { Item* item=list.Remove(); if(item) item->Destroy(); } list.FUN_00bd12d0(); member.FUN_00c24b70(); FUN_00840c70(); }
}
}   // namespace f3m_00845700

// @f3 0x0084d0b0 (community match, verified in this file)
#include <string.h>
namespace f3m_0084d0b0 {

struct SkinPartition1539 {
    unsigned int unk00;
    unsigned short* bones04;
    float* weights08;
    unsigned short* vertexMap0C;
    unsigned char* boneIndices10;
    unsigned short* indices14;
    unsigned short* stripLengths18;
    unsigned short vertices1C;
    unsigned short triangles1E;
    unsigned short bones20;
    unsigned short strips22;
    unsigned short weightsPerVertex24;
    __forceinline int CompareBones(const SkinPartition1539* b) const { return memcmp(bones04,b->bones04,bones20*sizeof(unsigned short)); }
    unsigned int FUN_0084d090();
    bool FUN_0084d0b0(const SkinPartition1539*);
};

// pdb: NiSkinPartition::Partition::IsEqual | NiSkinPartition.obj | tesv_win, call_seq, medium
bool SkinPartition1539::FUN_0084d0b0(const SkinPartition1539* other)
{
    if (vertices1C!=other->vertices1C) return false;
    if (triangles1E!=other->triangles1E) return false;
    if (bones20!=other->bones20) return false;
    if (strips22!=other->strips22) return false;
    if (weightsPerVertex24!=other->weightsPerVertex24) return false;
    if (CompareBones(other)) return false;
    if (memcmp(vertexMap0C,other->vertexMap0C,vertices1C*sizeof(unsigned short))) return false;
    unsigned int weightCount=vertices1C*weightsPerVertex24;
    if (memcmp(weights08,other->weights08,weightCount*sizeof(float))) return false;
    if (!strips22) {
        if (memcmp(indices14,other->indices14,triangles1E*3*sizeof(unsigned short))) return false;
    } else {
        if (memcmp(stripLengths18,other->stripLengths18,strips22*sizeof(unsigned short))) return false;
        if (memcmp(indices14,other->indices14,FUN_0084d090()*sizeof(unsigned short))) return false;
    }
    if ((!boneIndices10)!=(!other->boneIndices10)) return false;
    if (boneIndices10 && memcmp(boneIndices10,other->boneIndices10,weightCount)) return false;
    return true;
}


}   // namespace f3m_0084d0b0

// @f3 0x0085be90 (community match, verified in this file)
#include <windows.h>

class NiMemObject
{
  public:
    static void operator delete(void* p, unsigned int size);
};

class NiRefObject : public NiMemObject
{
  public:
    virtual ~NiRefObject()
    {
        InterlockedDecrement((long*)&ms_lObjectCount);
    }
    unsigned int m_uiRefCount;
    static unsigned int ms_lObjectCount;
};

class NiGlobalStringTable
{
  public:
    static char* ms_pcEmptyString;
};

class NiFixedString
{
  public:
    ~NiFixedString()
    {
        if (m_kHandle != NiGlobalStringTable::ms_pcEmptyString)
            InterlockedDecrement((long*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

extern "C" void __cdecl FUN_0085bd20(void* p);

class NiMaterialLibrary : public NiRefObject // src: F3_EXE vtable 0x00e251cc (old: FUN_0085be90)
{
  public:
    virtual ~NiMaterialLibrary();
    NiFixedString m_kName;
};

NiMaterialLibrary::~NiMaterialLibrary()
{
    FUN_0085bd20(this);
}

// @f3 0x0085be90 (community match, verified in this file)
extern const void* const DAT_0109f7f4;
extern const void* const vftable_NiRefObject;
extern long g_liveObjectCount;
extern char* g_kNullStringHandle;
namespace f3m_0085be90 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct FUN_0085be90_obj
{
    const void* m_pVTable;
    long m_lRefCount;
    char* m_kName;
    FUN_0085be90_obj* NiMaterialLibrary(unsigned int flags);
};

void __cdecl FUN_0085bd20(FUN_0085be90_obj* obj);

FUN_0085be90_obj* FUN_0085be90_obj::NiMaterialLibrary(unsigned int flags)
{
    m_pVTable = &DAT_0109f7f4;
    FUN_0085bd20(this);
    if (m_kName != g_kNullStringHandle)
        InterlockedDecrement((long*)(m_kName - 8));
    m_pVTable = &vftable_NiRefObject;
    InterlockedDecrement(&g_liveObjectCount);
    if (flags & 1)
        FUN_0089ec10(this, sizeof(FUN_0085be90_obj));
    return this;
}
}   // namespace f3m_0085be90

// @f3 0x008557c0 (community match, verified in this file)
extern void* DAT_00e24c1c[];
namespace f3m_008557c0 {
struct CleanupObject8557c0 {
 void** table;
 void FUN_00831f90();
 void FUN_008557c0();
};
// pdb: NiTriBasedGeomData::~NiTriBasedGeomData | NiTriBasedGeomData.obj | fnv360_0822_retail, caller, medium
void CleanupObject8557c0::FUN_008557c0(){table=DAT_00e24c1c;FUN_00831f90();}
}   // namespace f3m_008557c0

// @f3 0x0084a740 (community match, verified in this file)
extern int FUN_00e23964;
namespace f3m_0084a740 {
namespace Dtor_0084a740
{

struct Owner
{
    void FUN_00825830();
    void FUN_0084a740();
};

// pdb: NiCollisionObject::~NiCollisionObject | NiCollisionObject.obj | fnv360_0721_beta, call_seq, medium
void Owner::FUN_0084a740()
{
    *(int*)this = (int)&FUN_00e23964;
    FUN_00825830();
}
}
}   // namespace f3m_0084a740

// @f3 0x008553d0 (community match, verified in this file)
extern int FUN_00e24a5c;
namespace f3m_008553d0 {
namespace Dtor_008553d0
{

struct Owner
{
    void FUN_0084b120();
    void FUN_008553d0();
};

// pdb: NiTriBasedGeom::~NiTriBasedGeom | NiTriBasedGeom.obj | fnv360_0822_retail, call_seq, high
void Owner::FUN_008553d0()
{
    *(int*)this = (int)&FUN_00e24a5c;
    FUN_0084b120();
}
}
}   // namespace f3m_008553d0

// @f3 0x00851a60 (community match, verified in this file)
namespace f3m_00851a60 {
struct Object851a60
{
    void FUN_00851980();
    void FUN_00851a60(int arg);
};

void __stdcall FUN_0083f630(int arg);

void Object851a60::FUN_00851a60(int arg)
{
    FUN_00851980();
    FUN_0083f630(arg);
}
}   // namespace f3m_00851a60

// @f3 0x00851a70 (community match, verified in this file)
namespace f3m_00851a70 {
struct Object851a70
{
    void FUN_00851980();
    void FUN_00851a70(int arg);
};

void __stdcall FUN_0083f670(int arg);

void Object851a70::FUN_00851a70(int arg)
{
    FUN_00851980();
    FUN_0083f670(arg);
}
}   // namespace f3m_00851a70

// @f3 0x00840c40 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace f3m_00840c40 {
extern int DAT_00db7764;
extern int DAT_00e232ac;
extern long DAT_0108ed80;
struct Member { void FUN_00855c60(); };
struct Obj {
    void* vtable;
    int refCount;
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    Member unk80;
    Obj* FUN_00840c40();
};
// pdb: NiImageConverter::NiImageConverter | NiImageConverter.obj | fnv360_0822_retail, objrun, medium
Obj* Obj::FUN_00840c40() {
    vtable = &DAT_00db7764;
    refCount = 0;
    ::InterlockedIncrement(&DAT_0108ed80);
    vtable = &DAT_00e232ac;
    unk80.FUN_00855c60();
    return this;
}
}

// @f3 0x00840c70 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace f3m_00840c70 {
extern int DAT_00db7764;
extern int DAT_00e232ac;
extern long DAT_0108ed80;
extern void* DAT_0108f478;
void __cdecl FUN_0089e890(void*);
struct Member { void FUN_00855bb0(); };
struct Obj {
    void* vtable;
    int refCount;
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    Member unk80;
    void FUN_00840c70();
};
// pdb: NiImageConverter::~NiImageConverter | NiImageConverter.obj | fnv360_0822_retail, call_seq, medium
void Obj::FUN_00840c70() {
    vtable = &DAT_00e232ac;
    if (DAT_0108f478) FUN_0089e890(DAT_0108f478);
    DAT_0108f478 = 0;
    unk80.FUN_00855bb0();
    vtable = &DAT_00db7764;
    ::InterlockedDecrement(&DAT_0108ed80);
}
}
