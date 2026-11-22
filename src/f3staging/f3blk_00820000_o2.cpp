#include <windows.h>
// src/f3staging/f3blk_00820000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008269d0 (community match, verified in this file)
extern long (__stdcall *DAT_00d9b06c)(volatile long*, long, long);
struct Obj {
    virtual void Unknown00();
    virtual void Destroy();
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
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual int GetIndex();
    volatile long references;
};
struct Ptr {
    Obj* value;
    operator Obj*() const { return value; }
    Ptr& operator=(Obj* p) {
        if (value != p) {
            Obj* old = value;
            if (old && !InterlockedDecrement(&old->references)) old->Destroy();
            value = p;
            if (p) InterlockedIncrement(&p->references);
        }
        return *this;
    }
};
struct Node { Node* next; Node* previous; Ptr data; };
inline Ptr& GetNext(Node*& node) { Ptr* element = &node->data; node = node->next; return *element; }
struct Set { Set* FUN_00854b80(Set* source); };
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
struct Lock {
    volatile long owner;
    unsigned int count;
    void FUN_00409a80(int);
    void Unlock() { if (!--count) DAT_00d9b06c(&owner, 0, owner); }
};
extern Lock DAT_0108ede0;
struct Container {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Node* head;
    unsigned int unk28, count;
    void FUN_008269d0(Set* source, bool allocate, Set** output);
};
// pdb: NiAVObject::PushLocalProperties | NiAVObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkParentState, bCopyOnChange, aspPropertyState
void Container::FUN_008269d0(Set* source, bool allocate, Set** output) {
    if (!count) { Set* original = source; Set** target = *(Set** volatile*)&output; *target = original; return; }
    DAT_0108ede0.FUN_00409a80(0);
    Set* result;
    if (allocate) {
        void* p = DAT_01090a78.FUN_0086b930(0x1c);
        result = p ? ((Set*)p)->FUN_00854b80(source) : 0;
    } else result = source;
    Ptr* slots = (Ptr*)result;
    Node* node = head;
    while (node) {
        Obj* element = GetNext(node);
        if (element && element->GetIndex() <= 7)
            slots[element->GetIndex()] = element;
    }
    DAT_0108ede0.Unlock();
    Set* finalResult = result;
    Set** target = *(Set** volatile*)&output;
    *target = finalResult;
}

// @f3 0x00829a60 (community match, verified in this file)
namespace f3m_00829a60 {
struct Base829a60 { virtual ~Base829a60(); virtual void v4(); int pad[5]; Base829a60(); };
struct FUN_00829a60 : Base829a60 { unsigned short value; virtual ~FUN_00829a60(); FUN_00829a60(); };
// pdb: NiScreenTexture::GetTexturingProperty | NiXenonRenderer.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: NiProperty::NiProperty)
FUN_00829a60::FUN_00829a60() { value = 8; }
}   // namespace f3m_00829a60

// @f3 0x00824200 (community match, verified in this file)
namespace f3m_00824200 {
namespace f3m_00824200 { struct Heap { void FUN_0086ba60(void* p); }; extern Heap DAT_01090a78; struct O { ~O(); static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); } }; extern O* DAT_0108ec74; }
// pdb: NiGlobalStringTable::_SDMShutdown | NiGlobalStringTable.obj | fnv360_0822_retail, call_seq, medium, conflict (bridge: NiStaticDataManager::SetRootLibrary)
void __cdecl FUN_00824200() { delete f3m_00824200::DAT_0108ec74; f3m_00824200::DAT_0108ec74 = 0; }
}   // namespace f3m_00824200

// @f3 0x00829af0 (community match, verified in this file)
namespace f3m_00829af0 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B00829af0 { virtual ~B00829af0(); virtual void v4(); int pad[5]; B00829af0() throw(); };
struct D00829af0 : B00829af0 { unsigned short value; virtual ~D00829af0(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D00829af0() throw(); };
D00829af0::D00829af0() throw() { value = 8; }
// pdb: NiVertexColorProperty::CreateObject | NiVertexColorProperty.obj | fnv360_0822_retail, objopen_prop, low
D00829af0* __cdecl FUN_00829af0() { return new D00829af0(); }
}   // namespace f3m_00829af0

// @f3 0x0083f8e0 (community match, verified in this file)
extern const char* DAT_0108f448;
namespace f3m_0083f8e0 {
namespace register_name_0083f8e0 {
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
    void FUN_0083f8e0(NameArray*);
};
// pdb: NiLines::GetViewerStrings | NiLines.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_0083f8e0(NameArray* names) {
    FUN_0084ba30(names);
    void* value=FUN_00847b50(DAT_0108f448);
    names->Append(value);
}
}

}   // namespace f3m_0083f8e0

// @f3 0x0083f700 (community match, verified in this file)
extern const char* DAT_0108f440;
namespace f3m_0083f700 {
namespace register_name_0083f700 {
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
    void FUN_00855450(NameArray*);
    void FUN_0083f700(NameArray*);
};
// pdb: NiTriShape::GetViewerStrings | NiTriShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkStrings
void Object::FUN_0083f700(NameArray* names) {
    FUN_00855450(names);
    void* value=FUN_00847b50(DAT_0108f440);
    names->Append(value);
}
}

}   // namespace f3m_0083f700

// @f3 0x0083c250 (community match, verified in this file)
extern const char* DAT_0108f414;
namespace f3m_0083c250 {
namespace register_name_0083c250 {
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
    void FUN_00855450(NameArray*);
    void FUN_0083c250(NameArray*);
};
// pdb: NiTriStrips::GetViewerStrings | NiTriStrips.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_0083c250(NameArray* names) {
    FUN_00855450(names);
    void* value=FUN_00847b50(DAT_0108f414);
    names->Append(value);
}
}

}   // namespace f3m_0083c250

// @f3 0x0082ea60 (community match, verified in this file)
namespace f3m_0082ea60 {
void** __cdecl FUN_006e3090(unsigned int count) throw();
template <class T> class NiTArray82ea60 {
public:
    virtual ~NiTArray82ea60();
    T* base;
    unsigned short maxSize;
    unsigned short size;
    unsigned short eSize;
    unsigned short growBy;
    __forceinline NiTArray82ea60(unsigned short initial, unsigned short grow) {
        maxSize = initial;
        growBy = grow;
        size = 0;
        eSize = 0;
        if (initial > 0)
            base = (T*)FUN_006e3090(initial);
        else
            base = 0;
    }
};
template <class T> class NiTPrimArray82ea60 : public NiTArray82ea60<T> {
public:
    __forceinline NiTPrimArray82ea60(unsigned short initial, unsigned short grow) : NiTArray82ea60<T>(initial, grow) {}
    virtual ~NiTPrimArray82ea60();
};
class FUN_00827190 {
public:
    FUN_00827190();
    virtual ~FUN_00827190();
    char pad04[0x98];
};
class FUN_0082ea60 : public FUN_00827190 {
public:
    FUN_0082ea60(unsigned int initial);
    virtual ~FUN_0082ea60();
    NiTPrimArray82ea60<void*> arr;
};
// pdb: NiNode::NiNode | NiNode.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiNumChildren
FUN_0082ea60::FUN_0082ea60(unsigned int initial) : arr(initial, 1)
{
}
}   // namespace f3m_0082ea60

// @f3 0x008340f0 (community match, verified in this file)
namespace f3m_008340f0 {
namespace task0885 {
void* FUN_0089e810(unsigned int);
inline void** Allocate(unsigned int count) { return (void**)FUN_0089e810(sizeof(void*)*count); }
class Base {
public:
 Base(unsigned int max, unsigned int grow) {
  capacity=(unsigned short)max; growth=(unsigned short)grow; size=0; used=0;
  if(capacity>0) data=Allocate(capacity); else data=0;
 }
 virtual ~Base();
 void** data;
 unsigned short capacity,size,used,growth;
};
class FUN_008340f0 : public Base {
public:
 FUN_008340f0(unsigned int max,unsigned int grow);
 virtual ~FUN_008340f0();
};
// pdb: NiTPrimitiveArray<NiD3DShaderDeclaration::NiPackerEntry *>::NiTPrimitiveArray<NiD3DShaderDeclaration::NiPackerEntry *> | NiD3DShaderDeclaration.obj | fnv360_0822_retail, call_gap, low
// pdb params: uiMaxSize, uiGrowBy
FUN_008340f0::FUN_008340f0(unsigned int max,unsigned int grow):Base(max,grow) {}
}
}   // namespace f3m_008340f0

// @f3 0x008321d0 (community match, verified in this file)
#include <string.h>
namespace Task1100 {
struct HeapEA0 {
 void* FUN_0086b930(unsigned int);
 void FUN_0086ba60(void*);
};
extern HeapEA0 DAT_01090a78;
struct AllocEA0 {  static void* operator new[](unsigned int n){return DAT_01090a78.FUN_0086b930(n);} };
struct Point3EA0 : AllocEA0 { Point3EA0() {}
 float x,y,z;
};
struct Point2EA0 : AllocEA0 { Point2EA0() {}
 float x,y;
};
}
struct RgbaColor : Task1100::AllocEA0 {
 float r,g,b,a;
 RgbaColor() throw();
};
namespace Task1100 {
struct BuffEA0 {int unk00,unk04;void* m_pCurrent;int m_iArrayLength;
 void* Allocate(unsigned bytes) { void* old=m_pCurrent; ++m_iArrayLength; m_pCurrent=(char*)m_pCurrent+bytes; return old; }
};
struct CountEA0 { int value; CountEA0(int v):value(v) {} };
struct ElementEA0 { int value; ElementEA0(int v):value(v) {} };
struct IoEA0 {
 int unk00;
 int pos04;
 int (__cdecl* read)(IoEA0*,void*,int,int*,int);
 __forceinline int ReadWrapped(void* data,CountEA0 bytes,ElementEA0 elem) { int result=read(this,data,bytes.value,&elem.value,1); pos04+=result; return result; }
 int BinaryRead(void* dest,int bytes,int size) { int result=read(this,dest,bytes,&size,1); pos04+=result; return result; }
};
struct StreamEA0 {
 int unk00;
 unsigned m_uiUserVersion;
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
 unsigned m_uiFileVersion;
 int unkdc;
 char* m_cName;
 int unke4;
 int unke8;
 int unkec;
 int unkf0;
 int unkf4;
 int unkf8;
 int unkfc;
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
 IoEA0* io;
 void* FUN_0082a330(int);
 void FUN_0082b560();
};
extern void* DAT_0108f280;
struct ObjEA0 {
 virtual void vf00();
 virtual void vf01();
 virtual void vf02();
 virtual void vf03();
 virtual void vf04();
 virtual void vf05();
 virtual void vf06();
 virtual void vf07();
 virtual void vf08();
 virtual void vf09();
 virtual void vf0a();
 virtual void vf0b();
 virtual void vf0c();
 virtual void vf0d();
 virtual void vf0e();
 virtual void vf0f();
 virtual void vf10();
 virtual void vf11();
 virtual void vf12();
 virtual void vf13();
 virtual void vf14();
 virtual void vf15();
 virtual void vf16();
 virtual void vf17();
 virtual void vf18();
 virtual void vf19();
 virtual void vf1a();
 virtual void vf1b();
 virtual void vf1c();
 virtual void vf1d();
 virtual void vf1e();
 virtual void vf1f();
 virtual BuffEA0* GetBuffData();
 int unk04;
 void FUN_00825ad0(StreamEA0&);
};
struct BoundEA0 {float x,y,z,r; void FUN_008181c0(StreamEA0&);};
struct GeomEA0: ObjEA0 {
 unsigned short m_usVertices;
 unsigned short unk0a;
 unsigned short m_usTrianglePoints;
 unsigned short m_usDirtyFlags;
 BoundEA0 m_kBound;
 Point3EA0* m_pkVertex;
 Point3EA0* m_pkNormal;
 RgbaColor* m_pkColor;
 Point2EA0* m_pkTexture;
 int unk30,unk34;
 unsigned char m_ucKeepFlags,m_ucCompressFlags;
 unsigned short unk3a;
 bool m_bVerticesDirty;
 unsigned short GetTextureCount() const { return m_usTrianglePoints & 0x1f; }
 void FUN_008321d0(StreamEA0&);
};
static __forceinline void ReadEA0(StreamEA0& s,void* dest,int bytes,int width) {
 IoEA0* io=s.io;
 io->BinaryRead(dest,bytes,width);
}
static __forceinline void ReadNormalEA0(StreamEA0& s, void* p,int count){IoEA0* io=s.io;io->ReadWrapped(p,count*12,4);}
static __forceinline void ReadPoint2EA0(StreamEA0& s, void* p,unsigned count){IoEA0* io=s.io;for(unsigned i=0;i<3;++i) count+=count;io->BinaryRead(p,count,4);}
extern void __cdecl FUN_00831dd0(StreamEA0&,Point2EA0*,unsigned);
extern void __cdecl FUN_00c24b70(const void*,const void*,unsigned);
extern char DAT_00e217c8[];
// pdb: NiGeometryData::LoadBinary | NiGeometryData.obj | fnv360_0822_retail, ustr, medium
// pdb params: kStream
void GeomEA0::FUN_008321d0(StreamEA0& kStream)
{
    void* pvCur;
    ObjEA0::FUN_00825ad0(kStream);
    if (kStream.m_uiFileVersion >= 0x0a010072)
    {
        int pkBuff;
        ReadEA0(kStream, &pkBuff, 4, 4);
        DAT_0108f280 = kStream.FUN_0082a330(pkBuff);
    }
    ReadEA0(kStream, &m_usVertices, 2, 2);
    if (kStream.m_uiFileVersion >= 0x0a000110)
    {
        ReadEA0(kStream, &m_ucKeepFlags, 1, 1);
        ReadEA0(kStream, &m_ucCompressFlags, 1, 1);
    }
    bool r;
    if (kStream.m_uiFileVersion < 0x04010000)
    {
        ReadEA0(kStream, &m_pkVertex, 4, 4);
        r = m_pkVertex != 0;
    }
    else
    {
        ReadEA0(kStream, &r, 1, 1);
    }
    if (r)
    {
        if ((pvCur = GetBuffData()) != 0)
        {
            int iTotal = 12 * m_usVertices;
            BuffEA0* tmp = GetBuffData();
            pvCur = tmp->Allocate(iTotal);
            m_pkVertex = (Point3EA0*)pvCur;
        }
        else
        {
            m_pkVertex = new Point3EA0[m_usVertices];
        }
        if (kStream.m_uiUserVersion >= 0x13 && !m_bVerticesDirty)
            memset(m_pkVertex, 0, m_usVertices * 12);
        else
            ReadEA0(kStream, m_pkVertex, m_usVertices * 12, 4);
    }
    int iNormalCount = m_usVertices;
    if (kStream.m_uiFileVersion >= 0x0a000002)
    {
        ReadEA0(kStream, &m_usTrianglePoints, 2, 2);
        if (m_usTrianglePoints & 0xf000)
            iNormalCount = iNormalCount * 3;
    }
    bool uiTexCount;
    if (kStream.m_uiFileVersion < 0x04010000)
    {
        ReadEA0(kStream, &m_pkNormal, 4, 4);
        uiTexCount = m_pkNormal != 0;
    }
    else
    {
        ReadEA0(kStream, &uiTexCount, 1, 1);
    }
    if (uiTexCount)
    {
        if ((pvCur = GetBuffData()) != 0)
        {
            BuffEA0* tmp = GetBuffData();
            pvCur = tmp->m_pCurrent;
            unsigned int iTotal;
            iTotal = iNormalCount * 12;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            tmp->m_iArrayLength++;
            m_pkNormal = (Point3EA0*)pvCur;
        }
        else
        {
            m_pkNormal = new Point3EA0[iNormalCount];
        }
        if (kStream.m_uiUserVersion < 0x13 || m_bVerticesDirty)
            ReadNormalEA0(kStream, m_pkNormal, iNormalCount);
    }
    m_kBound.FUN_008181c0(kStream);
    bool bHasColor;
    if (kStream.m_uiFileVersion < 0x04010000)
    {
        ReadEA0(kStream, &m_pkColor, 4, 4);
        bHasColor = m_pkColor != 0;
    }
    else
    {
        ReadEA0(kStream, &bHasColor, 1, 1);
    }
    if (bHasColor)
    {
        if ((pvCur = GetBuffData()) != 0)
        {
            int iTotal = m_usVertices * 16;
            BuffEA0* tmp = GetBuffData();
            pvCur = tmp->m_pCurrent;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            tmp->m_iArrayLength++;
            m_pkColor = (RgbaColor*)pvCur;
        }
        else
        {
            m_pkColor = new RgbaColor[m_usVertices];
        }
        if (kStream.m_uiUserVersion < 0x13 || m_bVerticesDirty)
            ReadEA0(kStream, m_pkColor, m_usVertices * 16, 4);
    }
    if (kStream.m_uiFileVersion < 0x0500000a)
    {
        unsigned short usTempFlags;
        ReadEA0(kStream, &usTempFlags, 2, 2);
        unsigned short bHasVertex = (usTempFlags ^ m_usTrianglePoints) & 1;
        m_usTrianglePoints ^= bHasVertex;
    }
    else if (kStream.m_uiFileVersion < 0x0a000002)
    {
        ReadEA0(kStream, &m_usTrianglePoints, 2, 2);
    }
    if (kStream.m_uiFileVersion < 0x04010000)
        ReadEA0(kStream, &m_pkTexture, 4, 4);
    unsigned int uiTextureFlags;
    if (kStream.m_uiUserVersion < 0x1b)
    {
        unsigned short flags = m_usTrianglePoints;
        uiTextureFlags = (unsigned char)flags & 0x1f;
        if ((unsigned short)uiTextureFlags > 1)
            m_usTrianglePoints = flags | 1;
    }
    else
    {
        uiTextureFlags = 0;
    }
    if ((unsigned short)(m_usTrianglePoints & 1) > 0)
    {
        unsigned int bHasNormal = (m_usTrianglePoints & 1) * m_usVertices;
        if ((pvCur = GetBuffData()) != 0)
        {
            BuffEA0* tmp = GetBuffData();
            int iTotal = bHasNormal * 8;
            pvCur = tmp->m_pCurrent;
            ++tmp->m_iArrayLength;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            m_pkTexture = (Point2EA0*)pvCur;
        }
        else
        {
            m_pkTexture = new Point2EA0[bHasNormal];
        }
        if (kStream.m_uiUserVersion < 0x13 || m_bVerticesDirty)
        {
            ReadPoint2EA0(kStream, m_pkTexture, bHasNormal);
            if ((unsigned short)uiTextureFlags > 1)
            {
                unsigned int uiExtraCount = ((unsigned short)uiTextureFlags - 1) * m_usVertices;
                Point2EA0* pkTemp = new Point2EA0[uiExtraCount];
                FUN_00831dd0(kStream, pkTemp, uiExtraCount);
                DAT_01090a78.FUN_0086ba60(pkTemp);
                FUN_00c24b70(DAT_00e217c8, &kStream.m_cName, (uiExtraCount * 8) >> 10);
            }
        }
    }
    if (kStream.m_uiFileVersion >= 0x0500000a)
        ReadEA0(kStream, &m_usDirtyFlags, 2, 2);
    if (kStream.m_uiFileVersion >= 0x0a030007)
        kStream.FUN_0082b560();
}
}

// @f3 0x0082c870 (community match, verified in this file)
#include <string.h>
namespace f3m_0082c870 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace native_82c870 {

struct Object { virtual void Slot0(); virtual void Dispose(); long references; };
typedef Object* (__cdecl *Factory)();
struct Stream { int unk00; unsigned int position; unsigned int (__cdecl* read)(Stream*, void*, unsigned int, unsigned int*, unsigned int);
template<class T> void Read(T* buffer, unsigned int count=1) { unsigned int size=sizeof(T); position+=read(this,buffer,count*sizeof(T),&size,1); } };
struct Ref {
    Object* value;
    Ref(Object* object) throw() : value(object) { if(object) InterlockedIncrement(&object->references); }
    operator Object*() const throw() { return value; }
    ~Ref() throw() { if(value && !InterlockedDecrement(&value->references)) value->Dispose(); }
};
struct ObjectArray { int unk00; Object** data; unsigned int size; unsigned int used, count;
 __declspec(noinline) void FUN_0082b0b0(unsigned int i,const Ref& value) throw();
};
void ObjectArray::FUN_0082b0b0(unsigned int i,const Ref& value) throw(){
 if(i>=used){used=i+1;if(value.value)++count;}
 else if(value.value){if(!data[i])++count;}else if(data[i])--count;
 Object* old=data[i];
 if(old!=value.value){if(old && !InterlockedDecrement(&old->references))old->Dispose();data[i]=value.value;if(value.value)InterlockedIncrement(&value.value->references);}
}
struct Loader { bool FUN_00bea7b0(const char*, Factory&); }; extern Loader* DAT_0108f104;
void* FUN_0089e810(unsigned int); void FUN_0089e890(void*);
struct Reader {
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
unsigned int version;
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
ObjectArray objects;
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
Stream* stream;
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
unsigned int error;
char errorText[260]; bool FUN_0082c870(); };
// pdb: NiStream::LoadRTTI | NiStream.obj | fnv360_0822_retail, ustr, medium
bool Reader::FUN_0082c870() {
    unsigned short typeCount;
    stream->Read(&typeCount);
    Factory* factories=static_cast<Factory*>(FUN_0089e810(typeCount*sizeof(Factory)));
    for(unsigned int i=0; i<typeCount; ++i) {
        char name[256];
        unsigned int length;
        stream->Read(&length);
        stream->Read(name,length);
        name[length]=0;
        if(version<0x14010001 && strcmp(name,"NiControllerManager")==0) {
            error=3;
            strcpy_s(errorText,260,"Older files may not contain animation data. Reexport required.");
            return false;
        }
        if(!DAT_0108f104->FUN_00bea7b0(name,factories[i])) {
            error=5;
            strcpy_s(errorText,260,name);
            strcat_s(errorText,260,": cannot find create function.");
            factories[i]=0;
        }
    }
    for(unsigned int i=0; i<objects.size; ++i) {
        bool allowNull=false;
        unsigned short index;
        stream->Read(&index);
        if(version>=0x14020005 && (index&0x8000)) {
            index&=0x7fff;
            allowNull=true;
        }
        bool create=factories[index]!=0;
        if(create) create=true;
        if(!create) {
            if(!allowNull) { FUN_0089e890(factories); return false; }
            objects.FUN_0082b0b0(i,static_cast<Object*>(0));
        } else {
            Ref retained(factories[index]());
            objects.FUN_0082b0b0(i,retained);
        }
    }
    FUN_0089e890(factories);
    return true;
}
}






}   // namespace f3m_0082c870

// @f3 0x00827350 (community match, verified in this file)
namespace f3m_00827350 {


struct AtomicValues { long exchange; long comparand; };
inline void ReleaseOwner(long* destination, AtomicValues values) { InterlockedCompareExchange(destination, values.exchange, values.comparand); }

struct FUN_00827350_lock
{
    long m_pOwnerObject;
    int m_uiItemCount;
    void FUN_00409a80(int mode);
};
extern FUN_00827350_lock DAT_0108ede0;

struct FUN_00827350_node
{
    int m_iWordAt00;
    FUN_00827350_node* m_next;
    void* m_item;
};

struct FUN_00827350_item
{
    virtual void vSlot00();
    virtual void vSlot01();
    virtual void vSlot02();
    virtual void vSlot03();
    virtual void vSlot04();
    virtual void vSlot05();
    virtual void vSlot06();
    virtual void vSlot07();
    virtual void vSlot08();
    virtual void vSlot09();
    virtual void vSlot10();
    virtual void vSlot11();
    virtual void vSlot12();
    virtual void vSlot13();
    virtual void vSlot14();
    virtual void vSlot15();
    virtual void vSlot16();
    virtual void vSlot17();
    virtual void vSlot18();
    virtual void vSlot19();
    virtual void vSlot20();
    virtual void vSlot21();
    virtual void vSlot22();
    virtual void vSlot23();
    virtual void vSlot24();
    virtual void vSlot25();
    virtual void vSlot26();
    virtual void vSlot27();
    virtual void vSlot28();
    virtual void vSlot29();
    virtual void vSlot30();
    virtual void vSlot31();
    virtual void vSlot32();
    virtual void vSlot33();
    virtual void vSlot34();
    virtual int vfn35();

    long m_iWordAt04;
    FUN_00827350_item* FUN_00825850(void* ctx);
};

struct FUN_00827350_sub
{
    void FUN_00af0680(void** p);
};

struct FUN_00827350_owner
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00827350_sub m_24;
};

struct FUN_00827350_list
{
    int m_iWordAt00;
    FUN_00827350_node* m_pFirstNode;
};

// Under a global lock, walks the list p2 and for each item with vfn35() below 7 resolves it with ctx and passes it to self->m_24.FUN_00af0680.
// Fallout 3 task 0001: adapted from the packet starting draft.
// pdb: NiAVObject::CloneProperties | NiAVObject.obj | fnv360_0822_retail, call_gap, medium
// pdb params: pkDest, pkList, kCloning
void __stdcall FUN_00827350(FUN_00827350_owner* apOwner, void* apList, void* apContext)
{
    DAT_0108ede0.FUN_00409a80(0);
    FUN_00827350_node* node = ((FUN_00827350_list*)apList)->m_pFirstNode;
    while (node != 0)
    {
        void** ppItem = &node->m_item;
        node = node->m_next;
        FUN_00827350_item* item = (FUN_00827350_item*)*ppItem;

        if (item == 0)
            continue;
        if (item->vfn35() >= 7)
            continue;
        item = item->FUN_00825850(apContext);
        if (item->vfn35() >= 7)
            continue;
        void* itemRef = item;
        InterlockedIncrement(&item->m_iWordAt04);
        apOwner->m_24.FUN_00af0680(&itemRef);
        if (InterlockedDecrement(&item->m_iWordAt04) == 0)
        {
            item->vSlot01();
        }
    }
    DAT_0108ede0.m_uiItemCount--;
    if (DAT_0108ede0.m_uiItemCount == 0)
    {
        AtomicValues values = {0, DAT_0108ede0.m_pOwnerObject};
        ReleaseOwner(&DAT_0108ede0.m_pOwnerObject, values);
    }
}
}   // namespace f3m_00827350

// @f3 0x00824170 (community match, verified in this file)
namespace f3m_00824170 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern int DAT_0108ec7c;
extern int DAT_0108ec78;

struct ThreadContext {
    char pad[0x298];
    unsigned int mode;
};

extern __declspec(thread) ThreadContext g_threadContext;

struct ThreadedTableEntry {
    int unk00;
    int unk04;
    int unk08;
    short flag;
    short unk0e;
    void FUN_00801c20(const char** key);
};

struct ThreadedTable {
    unsigned int FUN_00823f30(const char* key, unsigned int flags);
    void FUN_00824170(const char** key, unsigned int flags);
};

// pdb: NiGlobalStringTable::InsertString | NiGlobalStringTable.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: kHandle, stLen
void ThreadedTable::FUN_00824170(const char** key, unsigned int flags)
{
    unsigned int previousMode = g_threadContext.mode;
    g_threadContext.mode = 8;

    unsigned int index = FUN_00823f30(*key, flags);
    void* criticalSection = (char*)this + 0x2080;
    EnterCriticalSection(criticalSection);

    unsigned int entryOffset = index << 4;
    if (*(short*)((char*)this + entryOffset + 0xc) != 0)
        ++DAT_0108ec7c;

    ((ThreadedTableEntry*)((char*)this + entryOffset))->FUN_00801c20(key);
    ++DAT_0108ec78;
    LeaveCriticalSection(criticalSection);
    g_threadContext.mode = previousMode;
}
}   // namespace f3m_00824170

// @f3 0x0082a730 (community match, verified in this file)
#include <windows.h>

struct SpinLock82a730 {
    volatile long owner;
    unsigned int count;
    void FUN_00409a80(int spin);
    void Release() {
        if (!--count) DAT_00d9b06c(&owner, 0, owner);
    }
};

struct Node82a730 {
    Node82a730* next;
    int unk04;
    short unk08;
};

extern SpinLock82a730 DAT_0106e5a0;
extern Node82a730* DAT_0106e588;

// pdb: NiTPointerMap<char const *,unsigned short>::DeleteItem | NiStream.obj | tesv_win, vtable, medium
void __stdcall FUN_0082a730(Node82a730* node) {
    node->unk08 = 0;
    DAT_0106e5a0.FUN_00409a80(0);
    node->unk04 = 0;
    node->next = DAT_0106e588;
    DAT_0106e588 = node;
    if (!--DAT_0106e5a0.count) { long current = DAT_0106e5a0.owner; DAT_00d9b06c(&DAT_0106e5a0.owner, 0, current); }
}

// @f3 0x00836e10 (community match, verified in this file)
namespace f3m_00836e10 {
struct ProductVector {float x,y,z,w;};
// pdb: operator* | NiTCBRotKey.obj | tesv_win, call_dedup, low
ProductVector FUN_00836e10(float factor,const ProductVector& input) {ProductVector result;result.x=input.x*factor;result.y=input.y*factor;result.z=input.z*factor;result.w=input.w*factor;return result;}
}   // namespace f3m_00836e10

// @f3 0x00838e30 (community match, verified in this file)
extern const int FUN_00e2224c;
extern const int FUN_00e2220c;
extern const int FUN_00e2222c;
namespace f3m_00838e30 {
extern "C" void* __cdecl FUN_00c00610(void* p, int c, unsigned int n);
void* __cdecl FUN_0089e810(unsigned int size);

struct Array838e30 {
    const void* table;
    int count;
    void** data;
    int unk0c;
    void FUN_00838790();
};

struct Owner838e30;
void __cdecl FUN_00838830(void* source, Owner838e30* owner);

struct Owner838e30 {
    const void* table;
    int unk04;
    Array838e30 unk08;
    void* unk18;
    void FUN_00825800();
    Owner838e30* FUN_00838e30(void* source, int count);
};

// pdb: NiDefaultAVObjectPalette::NiDefaultAVObjectPalette | NiControllerManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: pkScene, uiHashSize
Owner838e30* Owner838e30::FUN_00838e30(void* source, int count) {
    FUN_00825800();
    table = &FUN_00e2224c;
    Array838e30* array = &unk08;
    array->count = count;
    array->table = &FUN_00e2220c;
    array->unk0c = 0;
    array->data = (void**)FUN_0089e810(count * 4);
    FUN_00c00610(array->data, 0, array->count * 4);
    array->table = &FUN_00e2222c;
    unk18 = source;
    if (source) {
        unk08.FUN_00838790();
        FUN_00838830(unk18, this);
    }
    return this;
}
}   // namespace f3m_00838e30

// @f3 0x0083a9d0 (community match, verified in this file)
namespace f3m_0083a9d0 {
class NiPoint3
{
public:
    float x, y, z;
};

class NiMatrix3
{
public:
    float m_pEntry[3][3];
};

class NiTransform
{
public:
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
};

class NiBound
{
public:
    NiPoint3 m_kCenter;
    float m_fRadius;
};

class NiFrustum
{
public:
    float m_fLeft, m_fRight, m_fTop, m_fBottom, m_fNear, m_fFar;
    bool m_bOrtho;
};

class NiCameraPrefix
{
public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64;
};

class NiCamera
{
public:
    NiCameraPrefix m_kPrefix;
    NiTransform m_kWorld;
    float m_afWorldToCamera[4][4];
    NiFrustum m_kViewFrustum;
};

struct CrossPoint : NiPoint3
{
    __declspec(noalias) NiPoint3 UnitCross(const NiPoint3& vector) const;
};

inline NiPoint3 Scaled(float radius, const NiPoint3& unit)
{
    NiPoint3 result;
    result.x = radius * unit.x;
    result.y = radius * unit.y;
    result.z = radius * unit.z;
    return result;
}

__forceinline NiPoint3 Added(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

__forceinline void ClampBounds(float& lower, float& upper, float minimum, float maximum)
{
    if (lower < minimum)
    {
        lower = minimum;
        if (upper < minimum)
            upper = minimum;
        else if (upper > maximum)
            upper = maximum;
    }
    else if (upper > maximum)
    {
        upper = maximum;
        if (lower > maximum)
            lower = maximum;
    }
}

__forceinline void FullBound(NiPoint3& lo, NiPoint3& hi)
{
    lo.y = -1.0f;
    lo.x = -1.0f;
    hi.y = 1.0f;
    hi.x = 1.0f;
}

__forceinline NiPoint3 Subbed(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

__forceinline const NiPoint3& Pass(const NiPoint3& p)
{
    return p;
}

struct CameraBound_0083a9d0 : public NiCamera
{
    void FUN_0083a9d0(const NiBound& bound, NiPoint3& kMin, NiPoint3& kMax, float fTolerance);
};

void CameraBound_0083a9d0::FUN_0083a9d0(const NiBound& bound, NiPoint3& kMin, NiPoint3& kMax, float fTolerance)
{
    NiPoint3 kCenter = bound.m_kCenter;
    float fRadius = bound.m_fRadius;
    NiPoint3 kScratch;
    kScratch.x = kCenter.x - m_kWorld.m_Translate.x;
    kScratch.y = kCenter.y - m_kWorld.m_Translate.y;
    kScratch.z = kCenter.z - m_kWorld.m_Translate.z;
    float fInv = 1.0f / (m_kViewFrustum.m_fFar - m_kViewFrustum.m_fNear);
    NiPoint3 kCol0;
    kCol0.x = m_kWorld.m_Rotate.m_pEntry[0][0];
    kCol0.y = m_kWorld.m_Rotate.m_pEntry[1][0];
    kCol0.z = m_kWorld.m_Rotate.m_pEntry[2][0];
    float fDepth = kCol0.x * kScratch.x + kCol0.y * kScratch.y + kCol0.z * kScratch.z;
    fDepth = fDepth - m_kViewFrustum.m_fNear;
    if (m_kViewFrustum.m_bOrtho)
    {
        kMin.z = 0.0f;
        kMax.z = 0.0f;
    }
    else
    {
        kMin.z = float(fDepth - fRadius) * fInv;
        kMax.z = float(fDepth + fRadius) * fInv;
    }
    {
        NiPoint3 kRel;
        kRel.x = m_kWorld.m_Rotate.m_pEntry[0][1];
        kRel.y = m_kWorld.m_Rotate.m_pEntry[1][1];
        kRel.z = m_kWorld.m_Rotate.m_pEntry[2][1];
        const NiPoint3& kUnit = Pass(((const CrossPoint&)kScratch).UnitCross(kRel));
        NiPoint3 kCross;
        kCross.x = fRadius * kUnit.x;
        kCross.y = fRadius * kUnit.y;
        kCross.z = fRadius * kUnit.z;
        NiPoint3 kPt;
        kPt.x = kCenter.x - kCross.x;
        kPt.y = kCenter.y - kCross.y;
        kPt.z = kCenter.z - kCross.z;
        float fW = kPt.x * m_afWorldToCamera[3][0] + (double)(kPt.y * m_afWorldToCamera[3][1]) +
                   (double)(kPt.z * m_afWorldToCamera[3][2]) + m_afWorldToCamera[3][3];
        if (fW > fTolerance)
        {
        }
        else
        {
            FullBound(kMin, kMax);
            ClampBounds(kMin.z, kMax.z, 0.0f, 1.0f);
            return;
        }
        float coordinateX = kPt.x;
        float coordinateZ = kPt.z;
        kMin.x = (coordinateX * m_afWorldToCamera[0][0] + kPt.y * m_afWorldToCamera[0][1] +
                  coordinateZ * m_afWorldToCamera[0][2] + m_afWorldToCamera[0][3]) / fW;
        NiPoint3 kPositive = Added(kCenter, kCross);
        float fWMax = kPositive.x * m_afWorldToCamera[3][0] + kPositive.y * m_afWorldToCamera[3][1] +
                      kPositive.z * m_afWorldToCamera[3][2] + m_afWorldToCamera[3][3];
        if (fWMax > fTolerance)
        {
        }
        else
        {
            FullBound(kMin, kMax);
            ClampBounds(kMin.z, kMax.z, 0.0f, 1.0f);
            return;
        }
        kMax.x = (kPositive.x * m_afWorldToCamera[0][0] + kPositive.y * m_afWorldToCamera[0][1] +
                  kPositive.z * m_afWorldToCamera[0][2] + m_afWorldToCamera[0][3]) / fWMax;
    }
    {
        NiPoint3 kRel;
        kRel.x = m_kWorld.m_Rotate.m_pEntry[0][2];
        kRel.y = m_kWorld.m_Rotate.m_pEntry[1][2];
        kRel.z = m_kWorld.m_Rotate.m_pEntry[2][2];
        const NiPoint3& kUnit = Pass(((const CrossPoint&)kRel).UnitCross(kScratch));
        NiPoint3 kCross = Scaled(fRadius, kUnit);
        NiPoint3 kPt = Subbed(kCenter, kCross);
        float fW = kPt.x * m_afWorldToCamera[3][0] + kPt.y * m_afWorldToCamera[3][1] +
                   kPt.z * m_afWorldToCamera[3][2] + m_afWorldToCamera[3][3];
        if (fW > fTolerance)
        {
        }
        else
        {
            FullBound(kMin, kMax);
            ClampBounds(kMin.z, kMax.z, 0.0f, 1.0f);
            return;
        }
        kMin.y = (((kPt.x * m_afWorldToCamera[1][0] + kPt.y * m_afWorldToCamera[1][1]) + m_afWorldToCamera[1][2] * kPt.z) + m_afWorldToCamera[1][3]) / fW;
        NiPoint3 kPositive = Added(kCenter, kCross);
        float fWMax = kPositive.x * m_afWorldToCamera[3][0] + kPositive.y * m_afWorldToCamera[3][1] +
                      kPositive.z * m_afWorldToCamera[3][2] + m_afWorldToCamera[3][3];
        if (fWMax > fTolerance)
        {
        }
        else
        {
            FullBound(kMin, kMax);
            ClampBounds(kMin.z, kMax.z, 0.0f, 1.0f);
            return;
        }
        kMax.y = (kPositive.x * m_afWorldToCamera[1][0] + kPositive.y * m_afWorldToCamera[1][1] +
                  kPositive.z * m_afWorldToCamera[1][2] + m_afWorldToCamera[1][3]) / fWMax;
    }
    ClampBounds(kMin.x, kMax.x, -1.0f, 1.0f);
    ClampBounds(kMin.y, kMax.y, -1.0f, 1.0f);
    ClampBounds(kMin.z, kMax.z, 0.0f, 1.0f);
}
}   // namespace f3m_0083a9d0

// @f3 0x0083ec20 (community match, verified in this file)
extern int DAT_00f73164;
namespace f3m_0083ec20 {

// pdb: NiProcessorSpecificCode::SetVectorTransformFunction | NiProcessor.obj | tesv_win, call_seq, medium
void FUN_0083ec20(int value)
{
    DAT_00f73164 = value;
}
}   // namespace f3m_0083ec20

// @f3 0x0083ec30 (community match, verified in this file)
extern int DAT_00f73168;
namespace f3m_0083ec30 {

// pdb: NiProcessorSpecificCode::SetPointTransformFunction | NiProcessor.obj | tesv_win, call_seq, medium
void FUN_0083ec30(int value)
{
    DAT_00f73168 = value;
}
}   // namespace f3m_0083ec30

// @f3 0x00839f80 (community match, verified in this file)
extern int FUN_00e22464;
namespace f3m_00839f80 {
namespace Dtor_00839f80
{

struct Owner
{
    void FUN_00826b80();
    void FUN_00839f80();
};

// pdb: NiCamera::~NiCamera | NiCamera.obj | fnv360_0822_retail, call_gap, high
void Owner::FUN_00839f80()
{
    *(int*)this = (int)&FUN_00e22464;
    FUN_00826b80();
}
}
}   // namespace f3m_00839f80

// @f3 0x00836650 (community match, verified in this file)
namespace f3m_00836650 {
namespace f3m_00836650 {
void* __cdecl FUN_0089eb90(unsigned int size);
struct Item {
    Item() throw();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
};
struct Obj {
    int unk00; int unk04; int unk08;
    int unk0c;
    void FUN_00835b50(Item* item, int arg);
    void FUN_008258b0(Obj* self, int arg);
    void* FUN_00836650(int arg);
};
// pdb: NiTexturingProperty::CreateClone | NiTexturingProperty.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kCloning
void* Obj::FUN_00836650(int arg) {
    if (unk0c) {
        Item* item = new Item;
        FUN_00835b50(item, arg);
        return item;
    }
    FUN_008258b0(this, arg);
    return this;
}
}
}   // namespace f3m_00836650
