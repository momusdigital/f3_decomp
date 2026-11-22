#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00aa0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00ab46c0 (community match, verified in this file)
extern CRITICAL_SECTION DAT_0116daf4;
namespace f3m_00ab46c0 {

extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(CRITICAL_SECTION*);
namespace f3_0592 {
struct RefObj5b
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;

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


template <class T> class SmartPtr5b
{
  public:
    T* m_pObject;

    SmartPtr5b(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    SmartPtr5b(const SmartPtr5b& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject) m_pObject->IncRefCount();
    }
    ~SmartPtr5b()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    SmartPtr5b& FUN_006e5cc0(const SmartPtr5b& rhs)
    {
        if (m_pObject != rhs.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = rhs.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ListItem5b
{
    ListItem5b* m_pNext;
    ListItem5b* m_pListObject;
    SmartPtr5b<RefObj5b> m_element;
};

struct Alloc5b
{
    unsigned int count;
    ListItem5b* FUN_00423640();
};

struct List5b
{
    ListItem5b* m_pHead;
    ListItem5b* m_pTail;
    Alloc5b m_kItemCount;

    ListItem5b* GetHeadPos() const
    {
        return m_pHead;
    }
    RefObj5b* GetNext(ListItem5b*& pos) const
    {
        RefObj5b* const& e = pos->m_element.m_pObject;
        pos = pos->m_pNext;
        return e;
    }


    void FUN_00827100(const SmartPtr5b<RefObj5b>& element)
    {
        ListItem5b* node = m_kItemCount.FUN_00423640();
        node->m_element.FUN_006e5cc0(element);
        node->m_pNext = 0;
        node->m_pListObject = m_pTail;
        if (m_pTail)
            m_pTail->m_pNext = node;
        else
            m_pHead = node;
        m_pTail = node;
        ++m_kItemCount.count;
    }

    SmartPtr5b<RefObj5b> FUN_00469c50();
    SmartPtr5b<RefObj5b> FUN_0058b9a0();
    void FUN_00ad3d80(ListItem5b* node);
    SmartPtr5b<RefObj5b> FUN_00ab43e0(ListItem5b*& pos)
    {
        ListItem5b* node = pos;
        if (node == m_pHead)
        {
            pos = node->m_pNext;
            return FUN_00469c50();
        }
        if (node == m_pTail)
        {
            pos = 0;
            return FUN_0058b9a0();
        }
        ListItem5b* prev = node->m_pListObject;
        ListItem5b* next = node->m_pNext;
        pos = next;
        if (prev) prev->m_pNext = next;
        if (next) next->m_pListObject = prev;
        SmartPtr5b<RefObj5b> element = node->m_element;
        FUN_00ad3d80(node);
        --m_kItemCount.count;
        return element;
    }
};

struct Owner5b
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
    List5b m_list50;
    List5b m_list5c;
    void FUN_00ab46c0(RefObj5b* p);
};

// @fnv 0x00c5b1c0
// pdb: BSPortalGraph::AttachAlwaysRenderChild | BSPortalGraph.obj | fnv360_0822_retail, call_dedup, low
// pdb params: pkChild
void Owner5b::FUN_00ab46c0(RefObj5b* p)
{
    if (!p)
        return;
    fnv_EnterCriticalSection(&DAT_0116daf4);
    ListItem5b* pos = m_list50.GetHeadPos();
    while (pos)
    {
        RefObj5b* cur = m_list50.GetNext(pos);
        if (cur == p)
            break;
    }
    if (!pos)
    {
        m_list50.FUN_00827100(p);
        pos = m_list5c.GetHeadPos();
        while (pos)
        {
            ListItem5b* saved2 = pos;
            RefObj5b* cur = m_list5c.GetNext(pos);
            if (cur == p)
            {
                m_list5c.FUN_00ab43e0(saved2);
            }
        }
    }
    LeaveCriticalSection(&DAT_0116daf4);
}
}
}   // namespace f3m_00ab46c0

// @f3 0x00ab3dd0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00ab3dd0 {

struct RefC5BB
{
    virtual void v_00();
    virtual void v_04();
    volatile long field_04;
    void IncRefCount()
    {
        InterlockedIncrement(&field_04);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&field_04))
            v_04();
    }
};
struct PtrC5BB
{
    RefC5BB* field_00;
    PtrC5BB(RefC5BB* p = 0)
    {
        field_00 = p;
        if (field_00)
            field_00->IncRefCount();
    }
    PtrC5BB(const PtrC5BB& p)
    {
        field_00 = p.field_00;
        if (field_00)
            field_00->IncRefCount();
    }
    ~PtrC5BB()
    {
        if (field_00)
            field_00->DecRefCount();
    }
    PtrC5BB& operator=(const PtrC5BB& other)
    {
        if (field_00 != other.field_00)
        {
            if (field_00)
                field_00->DecRefCount();
            field_00 = other.field_00;
            if (field_00)
                field_00->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const PtrC5BB& p) const
    {
        return field_00 != p.field_00;
    }
};
struct ArrayC5BB
{
    unsigned int field_00;
    PtrC5BB* field_04;
    unsigned short field_08, field_0a, field_0c, field_0e;
    PtrC5BB FUN_00ab3dd0(unsigned int index);
};
// Adapted from FNV reference 138670: array swap-removal with owning pointers.
// pdb: NiTArray<NiPointer<NiAVObject>,NiTNewInterface<NiPointer<NiAVObject> > >::RemoveAtAndFill | BSPortalGraph.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiIndex
PtrC5BB ArrayC5BB::FUN_00ab3dd0(unsigned int index)
{
    if (index >= field_0a)
        return PtrC5BB();
    --field_0a;
    PtrC5BB value = field_04[index];
    field_04[index] = field_04[field_0a];
    field_04[field_0a] = PtrC5BB();
    if (value != PtrC5BB())
        --field_0c;
    return value;
}
}   // namespace f3m_00ab3dd0

// @f3 0x00aa7510 (community match, verified in this file)
namespace f3m_00aa7510 {
struct Setting56 {
    const char* name;
    union {int integer;unsigned int unsignedValue;float real;const char* text;} value;
    const char* type;
};
int __cdecl FUN_00a9d930(const char*);
void __cdecl INISettingCollection_MainKey(const Setting56*,char*);
void __cdecl INISettingCollection_SubKey(const Setting56*,char*);
void __cdecl FUN_0061dbe0(unsigned int,unsigned int*,unsigned int*,unsigned int*,unsigned int*);
int __cdecl FUN_00403230(char*,unsigned int,const char*,...);
extern int (__stdcall* DAT_00d9b0fc)(const char*,const char*,const char*,const char*);
class ProfileWriter56 {
public:
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();
    virtual bool Open(bool);
    virtual void Close();
    char filename[260];
    void* handle;
    bool FUN_00aa7510(const Setting56* setting);
};
// pdb: INISettingCollection::WriteSetting | XINISetting_Xenon.obj | fnv360_0822_retail, vtable, medium
// pdb params: arSetting
bool ProfileWriter56::FUN_00aa7510(const Setting56* setting) {
    bool result=false;
    if(setting->type) {
        bool opened=(handle==0);
        if(opened)Open(true);
        if(handle) {
            int type=FUN_00a9d930(setting->type);
            char section[64],key[64],buffer[256];
            INISettingCollection_MainKey(setting,section);
            INISettingCollection_SubKey(setting,key);
            switch(type) {
            case 6:
                result=DAT_00d9b0fc(section,key,setting->value.text,filename)!=0;
                break;
            case 1:
            case 3:
                FUN_00403230(buffer,256,"%d",setting->value.integer);
                result=DAT_00d9b0fc(section,key,buffer,filename)!=0;
                break;
            case 5:
                FUN_00403230(buffer,256,"%.4f",setting->value.real);
                result=DAT_00d9b0fc(section,key,buffer,filename)!=0;
                break;
            case 7: {
                unsigned int r,g,b,a;
                FUN_0061dbe0(setting->value.unsignedValue,&r,&g,&b,&a);
                FUN_00403230(buffer,256,"%u,%u,%u",r,g,b);
                result=DAT_00d9b0fc(section,key,buffer,filename)!=0;
                break;
            }
            case 8: {
                unsigned int r,g,b,a;
                FUN_0061dbe0(setting->value.unsignedValue,&r,&g,&b,&a);
                FUN_00403230(buffer,256,"%u,%u,%u,%u",r,g,b,a);
                result=DAT_00d9b0fc(section,key,buffer,filename)!=0;
                break;
            }
            default:
                FUN_00403230(buffer,256,"%u",setting->value.unsignedValue);
                result=DAT_00d9b0fc(section,key,buffer,filename)!=0;
                break;
            }
        }
        if(opened)Close();
    }
    return result;
}
}   // namespace f3m_00aa7510

// @f3 0x00ab4a40 (community match, verified in this file)
#include <windows.h>
extern LONG DAT_0108ed80;
namespace f3m_00ab4a40 {
namespace portal_construct1977 {
struct RefObject{virtual ~RefObject();LONG refs;__forceinline RefObject():refs(0){InterlockedIncrement(&DAT_0108ed80);}};
struct Array12{void* data;unsigned int size,capacity;__forceinline Array12(){capacity=0;data=0;size=0;}~Array12();};
struct RefTarget{virtual void Interface();virtual void Destroy();LONG refs;};
struct Pointer4{RefTarget* value;__forceinline Pointer4():value(0){}~Pointer4();__forceinline Pointer4& operator=(RefTarget* p){if(value!=p){RefTarget* old=value;if(old){if(InterlockedDecrement(&old->refs)==0)old->Destroy();}value=p;}return *this;}};
struct ObjectArrayBase{virtual void Interface();void* data;unsigned short capacity,size,used,growth;__forceinline ObjectArrayBase(){capacity=0;growth=1;size=0;used=0;data=0;}};struct ObjectArray16:ObjectArrayBase{__forceinline ObjectArray16(){}~ObjectArray16();};
struct SimpleArray16{virtual void Interface();void* data;unsigned int size,capacity;__forceinline SimpleArray16(){data=0;size=0;capacity=0;}~SimpleArray16();};
struct PortalGraph:RefObject{Array12 first,second,third;Pointer4 root;Array12 fourth;ObjectArray16 objects;Pointer4 room;Array12 fifth,sixth;SimpleArray16 nodes;PortalGraph();virtual ~PortalGraph();};
typedef char PortalSize[(sizeof(PortalGraph)==0x78)?1:-1];
// pdb: BSPortalGraph::BSPortalGraph | BSPortalGraph.obj | fnv360_0822_retail, objrun_prop, low
PortalGraph::PortalGraph(){root=0;room=0;}
}
}   // namespace f3m_00ab4a40

// @f3 0x00aae7a0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aae7a0 {

struct RefCounted_00aae7a0 {
    virtual void slot00() {}
    virtual void slot04() {}
    int unk04;
};

// pdb: BSParticleSystemManager::SetAt | BSParticleSystemManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: i, pkChild, aspAVObject
void __stdcall FUN_00aae7a0(unsigned int param1, unsigned int param2, int* param3) {
    RefCounted_00aae7a0* object = (RefCounted_00aae7a0*)*param3;
    if (object != 0) {
        LONG count = InterlockedDecrement((volatile LONG*)((char*)object + 4));
        if (count == 0) {
            object->slot04();
        }
        *param3 = 0;
    }
}
}   // namespace f3m_00aae7a0

// @f3 0x00aa1540 (community match, verified in this file)
#include <math.h>
namespace f3m_00aa1540 {
namespace Worker2434 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& other) const { return Vec3(x-other.x,y-other.y,z-other.z); }
};
inline float Abs(float x) { return (float)fabs((double)x); }
struct Primitive {
    void* vtable;
    int unk04, unk08;
    Vec3 center;
    Vec3 radii;
    bool FUN_00aa1540(Vec3 point);
};
// pdb: BSMultiBoundAABB::FastPointWithin | BSMultiBoundAABB.obj | fnv360_0822_retail, objrun, medium
// pdb params: kpoint
bool Primitive::FUN_00aa1540(Vec3 point)
{
    Vec3 delta = point-center;
    return !(Abs(delta.x)-radii.x > (double)0.01f) &&
           !(Abs(delta.y)-radii.y > (double)0.01f) &&
           Abs(delta.z)-radii.z <= (double)0.01f;
}
}
}   // namespace f3m_00aa1540

// @f3 0x00aa3170 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aa3170 {
namespace f3m_00aa3170 {
struct RefObj {
    virtual ~RefObj();
    int unk04;
    long refs;
    void DecRef() { if (!InterlockedDecrement(&refs)) delete this; }
};
struct Node {
    int unk00;
    int unk04;
    union {
        RefObj* obj;
        Node* next;
    };
};
struct Config { int unk00, unk04, unk08, unk0c; int limit; };
struct Pool {
    Config* config;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    Node* freeHead;
    int freeCount;
    void FUN_00aa3000();
    void FUN_00aa3170(Node* node);
};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::DeleteNode | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apNode
void Pool::FUN_00aa3170(Node* node)
{
    if (node->obj) {
        node->obj->DecRef();
        node->obj = 0;
    }
    node->next = freeHead;
    ++freeCount;
    freeHead = node;
    if (freeCount == config->limit)
        FUN_00aa3000();
}
}
}   // namespace f3m_00aa3170

// @f3 0x00aab350 (community match, verified in this file)
#include <windows.h>
extern char* DAT_00e207a8;
extern char DAT_01091f04;
namespace f3m_00aab350 {
namespace f3m_00aab350 {
char* __cdecl FUN_008242a0(const char* s);
struct FixedString {
    char* handle;
    FixedString(const char* s) { handle = FUN_008242a0(s); }
    ~FixedString() {
        if (handle == DAT_00e207a8)
            return;
        InterlockedDecrement((long*)(handle - 8));
    }
};
struct Result;
struct Finder {
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
    virtual Result* Find(const FixedString& name);
};
struct Extra {
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
    Finder* finder;
};
struct Obj {
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
    virtual Result* Create(const FixedString& name);
    Extra* FUN_00825200(void* rtti);
};
// pdb: BSUtilities::GetObjectByName | BSUtilities.obj | fnv360_0822_debug, call_seq, medium
// pdb params: apScene, apName, bTestScenegraph
Result* __cdecl FUN_00aab350(Obj* obj, const char* name, bool create)
{
    if (!obj || !name)
        return 0;
    Extra* ext = obj->FUN_00825200(&DAT_01091f04);
    FixedString fs(name);
    if (ext) {
        Result* r = ext->finder->Find(fs);
        if (r)
            return r;
    }
    if (create)
        return obj->Create(fs);
    return 0;
}
}
}   // namespace f3m_00aab350

// @f3 0x00ab3f40 (community match, verified in this file)
#include <windows.h>
namespace f3m_00ab3f40 {
namespace Worker2500 {
struct RefObj5b
{

    virtual ~RefObj5b();

    virtual void DeleteThis();

    volatile long m_uiRefCount;

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

    unsigned int m_uiValue1;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    void SetBit(bool bVal, unsigned int uiMask)
    {

        if (bVal)
            m_uiValue1 |= uiMask;

        else
            m_uiValue1 &= ~uiMask;
    }
};

struct SPtr5b
{

    RefObj5b* m_pObject;

    SPtr5b(const SPtr5b& other)
    {

        m_pObject = other.m_pObject;

        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~SPtr5b()
    {

        if (m_pObject)
        {

            m_pObject->DecRefCount();
        }
    }

    operator RefObj5b*() const
    {
        return m_pObject;
    }

    RefObj5b* operator->() const
    {
        return m_pObject;
    }

    bool operator==(RefObj5b* p) const
    {
        return m_pObject == p;
    }
};

struct SArray5b
{
    virtual ~SArray5b();
    SPtr5b* data;
    unsigned short capacity, size, used, grow;
    const SPtr5b& GetAt(unsigned int i) const
    {
        return data[i];
    }
    unsigned short GetSize() const
    {
        return size;
    }

    SPtr5b FUN_00ab3dd0(unsigned int uiIndex);
};

struct Owner5b
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

    SArray5b m_kArray;

    SPtr5b* m_pBase;

    unsigned short unk44;

    unsigned short m_usSize;

    void FUN_00ab3f40(RefObj5b* pkObj);
};

// @fnv 0x00c5b740
// pdb: BSPortalGraph::DetachQAlwaysRenderChild | BSPortalGraph.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: pkChild
void Owner5b::FUN_00ab3f40(RefObj5b* pkObj)

{

    for (unsigned int i = 0; i < m_kArray.size; i++)
    {

        SPtr5b pSceneObject = m_kArray.GetAt(i);

        if (pSceneObject && pSceneObject == pkObj)
        {

            m_kArray.FUN_00ab3dd0(i);

            pSceneObject->SetBit(false, 1);

            break;
        }
    }
}

}
}   // namespace f3m_00ab3f40

// @f3 0x00ab87c0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00ab87c0 {
namespace task2521 {
struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_00ab87c0(unsigned int idx, NiRefStubB5652** a2);
};

// @fnv 0x00a32940
// pdb: NiTArray<NiPointer<NiAVObject>,NiTMallocInterface<NiPointer<NiAVObject> > >::SetAt | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiIndex, element
void FUN_00a32940_cls::FUN_00ab87c0(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((unsigned int)*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((unsigned int)*apNewStub != key.m_00)
        {
            if ((unsigned int)m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((unsigned int)m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

}

}   // namespace f3m_00ab87c0

// @f3 0x00ab48d0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00ab48d0 {
namespace Task2504 {
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRef()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct RefPtr
{
    RefObj* m_pObject;
    RefPtr() : m_pObject(0) {}
    RefPtr& operator=(const RefPtr& other) {
        if (m_pObject != other.m_pObject) {
            if (m_pObject) m_pObject->DecRef();
            m_pObject = other.m_pObject;
            if (m_pObject) m_pObject->AcquireReference();
        }
        return *this;
    }
    __forceinline RefPtr(RefObj* pkObj)
    {
        m_pObject = pkObj;
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    __forceinline RefPtr(const RefPtr& kOther)
    {
        m_pObject = kOther.m_pObject;
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    __forceinline ~RefPtr()
    {
        if (m_pObject)
            m_pObject->DecRef();
    }
    __forceinline operator RefObj*() const
    {
        return m_pObject;
    }
    __forceinline bool operator==(RefObj* pkObj) const
    {
        return m_pObject == pkObj;
    }
};

struct PtrArray
{
    void* m_pVtbl;
    RefPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline RefPtr& operator[](unsigned int uiIndex)
    {
        return m_pBase[uiIndex];
    }
    void FUN_005574c0(unsigned int size);
    __declspec(noinline) void FUN_00470f10(unsigned int index, const RefPtr& value) {
        static RefPtr empty;
        if (index >= m_usSize) {
            m_usSize = (unsigned short)(index + 1);
            if (value.m_pObject != empty.m_pObject) ++m_usESize;
        } else if (value.m_pObject != empty.m_pObject) {
            if (m_pBase[index].m_pObject == empty.m_pObject) ++m_usESize;
        } else if (m_pBase[index].m_pObject != empty.m_pObject) --m_usESize;
        m_pBase[index] = value;
    }
    __declspec(noinline) unsigned int FUN_0082e8d0(const RefPtr& value) {
        if (!value.m_pObject) return (unsigned int)-1;
        unsigned short index;
        for (index=0;index<m_usSize;++index) {
            if (!m_pBase[index].m_pObject) {
                m_pBase[index]=value;
                ++m_usESize;
                return index;
            }
        }
        unsigned int result=m_usSize;
        if (result>=m_usMaxSize) FUN_005574c0(result+m_usGrowBy);
        FUN_00470f10(result,value);
        return result;
    }
};

struct Owner_c5b5f0
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
    PtrArray m_kArray;
    void FUN_00ab48d0(RefObj* pkObj);
};

// @fnv 0x00c5b5f0
// pdb: BSPortalGraph::AttachQAlwaysRenderChild | BSPortalGraph.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: pkChild
void Owner_c5b5f0::FUN_00ab48d0(RefObj* pkObj)
{
    if (pkObj == 0)
        return;
    bool bFound = false;
    for (unsigned int i = 0; i < m_kArray.m_usSize; i++)
    {
        RefPtr spEntry = m_kArray[i];
        if (spEntry && spEntry == pkObj)
            bFound = true;
    }
    if (!bFound)
    {
        RefPtr spNew = pkObj;
        m_kArray.FUN_0082e8d0(spNew);
    }
}
}
}   // namespace f3m_00ab48d0

// @f3 0x00aaa120 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aaa120 {
namespace task2533 {
struct RefCounted {virtual void v0();virtual void v1();long m_uiRefCount;};
struct SmartReference {RefCounted* m_pObject;
static void Release(RefCounted* ref){if(InterlockedDecrement(&ref->m_uiRefCount)==0)ref->v1();}
SmartReference& operator=(RefCounted* replacement){if(m_pObject!=replacement){if(m_pObject)Release(m_pObject);m_pObject=replacement;}return *this;}
~SmartReference(){if(m_pObject)Release(m_pObject);}
};
struct FUN_00ab5d80 {virtual ~FUN_00ab5d80();
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
};
struct FUN_00aaa120: FUN_00ab5d80 {SmartReference m_kSmartReference;virtual ~FUN_00aaa120();};
// pdb: BSMultiBoundNode::~BSMultiBoundNode | BSMultiBoundNode.obj | fnv360_0822_retail, call_seq, high
FUN_00aaa120::~FUN_00aaa120(){m_kSmartReference=static_cast<RefCounted*>(0);}
}
}   // namespace f3m_00aaa120

// @f3 0x00aaabd0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aaabd0 {
namespace task2520 {
struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_00aaabd0(unsigned int idx, NiRefStubB5652** a2);
};

// @fnv 0x00a32940
// pdb: NiTArray<NiPointer<NiRefObject>,NiTNewInterface<NiPointer<NiRefObject> > >::SetAt | NiObjectGarbage.obj | fnv360_0822_retail, call_seq, high
// pdb params: uiIndex, element
void FUN_00a32940_cls::FUN_00aaabd0(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((unsigned int)*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((unsigned int)*apNewStub != key.m_00)
        {
            if ((unsigned int)m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((unsigned int)m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

}
}   // namespace f3m_00aaabd0

// @f3 0x00abd4e0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00abd4e0 {
namespace Task2522 {
class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_00abd4e0(unsigned int idx, NiRefStubB5652** a2);
};

struct StaticKeyB5652 {
    NiRefStubB5652* m_00;
    StaticKeyB5652(NiRefStubB5652* p) throw() : m_00(p) { if (p) InterlockedIncrement(&p->m_iObjectReferenceCount); }
    ~StaticKeyB5652() throw() { if(m_00 && InterlockedDecrement(&m_00->m_iObjectReferenceCount)==0) m_00->Destroy(); }
};
// @fnv 0x00a32940
// pdb: NiTArray<NiPointer<NiPSysMeshEmitter::NiSkinnedEmitterData>,NiTNewInterface<NiPointer<NiPSysMeshEmitter::NiSkinnedEmitterData> > >::SetAt | NiPSysMeshEmitter.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: uiIndex, element
void FUN_00a32940_cls::FUN_00abd4e0(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if (*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if (*apNewStub != key.m_00)
        {
            if (m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if (m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

}
}   // namespace f3m_00abd4e0

// @f3 0x00aa2b10 (community match, verified in this file)
#include <windows.h>
extern volatile long DAT_0116d13c;
namespace f3m_00aa2b10 {
namespace Task2573 {
inline int S00c3de80_Zero()
{
    return 0;
}

struct S00c3de80_Key
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();

    int unk08;
    int unk0c;
    __int64 value;
};

struct S00c3de80_Obj
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

    bool __thiscall FUN_00aa2a00(S00c3de80_Key* object);
    bool __thiscall FUN_00aa2b10(S00c3de80_Key* object);
};

// @fnv 0x00c3de80
// pdb: IOManager::AddTask | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: apTask
bool S00c3de80_Obj::FUN_00aa2b10(S00c3de80_Key* object)
{
    S00c3de80_Key* self = object;
    if (unk40 != 6)
    {
        if ((unsigned char)(self->value >> 16) <= unk40)
        {
            self->value = (self->value & 0xffffffffff00ffffLL) + ((__int64)S00c3de80_Zero() << 16);
        }
    }

    self->v6();

    while (!FUN_00aa2a00(self))
    {
        __declspec(align(2)) unsigned short serial = (unsigned short)InterlockedIncrement(&DAT_0116d13c);

        self->value = (self->value & 0xffffffffffff0000LL) + (int)serial;
    }

    return true;
}

}
}   // namespace f3m_00aa2b10

// @f3 0x00aa2860 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aa2860 {
namespace Task2584 {
struct RequestValue
{
    unsigned int first, second;
};


struct FUN_00aa2860_Req
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    volatile long m_0c;
    RequestValue value;
};

class FUN_00aa2860_cls
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
// @fnv 0x00c3e690
    virtual void v18(FUN_00aa2860_Req* apRequest);
    void FUN_00424b70(FUN_00aa2860_Req* p);
    bool FUN_00aa2860(FUN_00aa2860_Req* p, RequestValue value);
};

// pdb: BSTaskManager<__int64>::RequeueTask | IOManager.obj | fnv360_0822_debug, call_seq, medium
// pdb params: apTask, aNewKey
bool FUN_00aa2860_cls::FUN_00aa2860(FUN_00aa2860_Req* p, RequestValue value)
{
    long v = p->m_0c;
    if (v == 0)
    {
        p->value = value;
        return true;
    }
    else if (v < 3)
    {
        bool ok = InterlockedCompareExchange(&p->m_0c, 2, v) == v;
        if (ok)
        {
            FUN_00424b70(p);
            p->value = value;
            bool ok2 = InterlockedCompareExchange(&p->m_0c, 0, 2) == 2;
            if (ok2)
            {
                v18(p);
            }
            return true;
        }
    }
    return false;
}

}
}   // namespace f3m_00aa2860

// @f3 0x00aae4d0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aae4d0 {
namespace Worker2585 {
struct Ref {
    virtual void Reserved();
    virtual void Destroy();
    volatile long count;
    __forceinline void IncRefCount() { InterlockedIncrement(&count); }
    __forceinline void DecRefCount() { if(InterlockedDecrement(&count)==0) Destroy(); }
};
struct Pointer {
    Ref* object;
    __forceinline Pointer(Ref* value=0) { object=value; if(object) object->IncRefCount(); }
    __forceinline ~Pointer() { if(object) object->DecRefCount(); }
};
struct Dispatcher {
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Invoke(int,int,Pointer*);
    void FUN_00aae4d0(int,int);
};
// pdb: BSParticleSystemManager::SetAt | BSParticleSystemManager.obj | fnv360_0721_beta, vtable, medium
// pdb params: i, pkChild
void Dispatcher::FUN_00aae4d0(int first,int second)
{
    Pointer result;
    Invoke(first,second,&result);
}
}
}   // namespace f3m_00aae4d0

// @f3 0x00ab49c0 (community match, verified in this file)
#include <windows.h>
extern CRITICAL_SECTION DAT_0116daf4;
namespace f3m_00ab49c0 {
struct Ref { void* m_pObject; };
struct SpawnNode { SpawnNode* m_pkNext; SpawnNode* m_pkPrevious; Ref m_element; };
struct SpawnList { SpawnNode* m_pkHead; SpawnNode* m_pkTail; unsigned int count; void FUN_00abb340(); };
struct SpawnedObject {
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
SpawnList m_50, m_5c;
void FUN_00ab48d0(void*); void FUN_00ab3f40(void*); void FUN_00ab49c0();
};
// @fnv 0x00c5b8d0
// pdb: BSPortalGraph::ProcessQueue | BSPortalGraph.obj | fnv360_0822_retail, call_gap_sim, low
void SpawnedObject::FUN_00ab49c0()
{
    EnterCriticalSection(&DAT_0116daf4);
    void* value;
    SpawnNode* node;
    {
        SpawnNode* head = m_50.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            Ref* ref = &node->m_element;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                FUN_00ab48d0(value);
            }
        }
    }
    m_50.FUN_00abb340();
    {
        SpawnNode* head = m_5c.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            Ref* ref = &node->m_element;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                FUN_00ab3f40(value);
            }
        }
    }
    m_5c.FUN_00abb340();
    LeaveCriticalSection(&DAT_0116daf4);
}
}   // namespace f3m_00ab49c0

// @f3 0x00ab5a10 (community match, verified in this file)
#include <windows.h>
namespace f3m_00ab5a10 {
struct RegistryOpen {
    virtual void v00();
    char keyName[260];
    HKEY hKey;
    bool FUN_00ab5a10(bool create);
};
// pdb: RegSettingCollection::Open | XRegSetting.obj | tesv_win, uimport, low
bool RegistryOpen::FUN_00ab5a10(bool create)
{
    DWORD disposition;
    bool result = false;
    if (create)
        result = (RegCreateKeyExA(HKEY_LOCAL_MACHINE, keyName, 0, 0, 0, KEY_ALL_ACCESS, 0, &hKey, &disposition) == 0);
    else
        result = (RegOpenKeyExA(HKEY_LOCAL_MACHINE, keyName, 0, KEY_ALL_ACCESS, &hKey) == 0);
    return result;
}
}   // namespace f3m_00ab5a10

// @f3 0x00ab8cc0 (community match, verified in this file)
#include <windows.h>
extern void* DAT_0116eb70;
namespace f3m_00ab8cc0 {
namespace f3m_00ab8cc0 {
struct NiNode;
struct NiAVObject {
    virtual void v00();
    virtual void DeleteThis();
    virtual void v08();
    virtual NiNode* IsNode();
    virtual void v10();
    virtual void v14();
    virtual int v18();
    long refs;
    int FUN_00824a50(void* rtti);
    void IncRef() { InterlockedIncrement(&refs); }
    void DecRef() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
struct NiNode : NiAVObject {
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
    NiAVObject** children;
    unsigned short capacity;
    unsigned short count;
};
struct ObjPtr {
    NiAVObject* p;
    ObjPtr(NiAVObject* o = 0) : p(o) { if (p) p->IncRef(); }
    ~ObjPtr() { if (p) p->DecRef(); }
};
struct ObjList {
    virtual void Destroy();
    ObjPtr* data;
    unsigned short capacity, size, effectiveSize, grow;
    void FUN_00ab8130(unsigned int capacity);
    __declspec(noinline) void FUN_00ab87c0(unsigned int index, const ObjPtr& value) {
        static ObjPtr empty;
        if (index >= size) {
            size = (unsigned short)(index + 1);
            if (value.p != empty.p) ++effectiveSize;
        } else if (value.p != empty.p) {
            if (data[index].p == empty.p) ++effectiveSize;
        } else if (data[index].p != empty.p) --effectiveSize;
        ObjPtr& dest = data[index];
        if (dest.p != value.p) {
            if (dest.p) dest.p->DecRef();
            dest.p = value.p;
            if (dest.p) dest.p->IncRef();
        }
    }
    __declspec(noinline) unsigned int FUN_00ab8ab0(const ObjPtr& value) {
        unsigned int index = size;
        if (index >= capacity) FUN_00ab8130(index + grow);
        FUN_00ab87c0(index, value);
        return index;
    }
};
struct Collector {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50;
    NiAVObject* exclude;
    int mode;
    ObjList list;
    void FUN_00ab8cc0(NiAVObject* obj);
};
// pdb: BSPSysArrayEmitter::SetObjectPointers | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_gap, medium
// pdb params: pObject
void Collector::FUN_00ab8cc0(NiAVObject* obj)
{
    if (!obj)
        return;
    NiNode* node = obj->IsNode();
    if (obj == exclude)
        return;
    bool take;
    switch (mode) {
    default:
        take = node != 0;
        break;
    case 1:
        take = obj->FUN_00824a50(DAT_0116eb70) != 0;
        break;
    case 0:
        take = obj->v18() != 0;
        break;
    }
    if (take)
        list.FUN_00ab8ab0(ObjPtr(obj));
    if (node) {
        for (unsigned int i = node->count; i; ) {
            --i;
            FUN_00ab8cc0(node->children[i]);
        }
    }
}
}
}   // namespace f3m_00ab8cc0

// @f3 0x00aaf800 (community match, verified in this file)
#include <windows.h>
extern int DAT_00e30c9c;
namespace f3m_00aaf800 {
namespace f3aaf800 {
struct FUN_00837e10 {
 virtual void v00();
 FUN_00837e10();
 ~FUN_00837e10();
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
};
void* AllocateArray(unsigned int);
struct Array {
    void* table;
    void* data;
    unsigned short capacity,size,live,grow;
    void Initialize(unsigned int initial, unsigned int growth) {
        capacity=(unsigned short)initial;
        grow=(unsigned short)growth;
        size=0;
        live=0;
        if (capacity > 0) data=AllocateArray(capacity);
        else data=0;
        table=&DAT_00e30c9c;
    }
};
struct RefObject {
 virtual void v00(); virtual void DeleteThis(); long refs;
 void IncRef() { InterlockedIncrement(&refs); }
 void DecRef() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
struct Ref {
 RefObject* pointer;
 Ref(RefObject* p=0):pointer(p) { if(pointer)pointer->IncRef(); }
 ~Ref() { if(pointer)pointer->DecRef(); }
};
struct Controller : FUN_00837e10 {
    int index;
    Ref ref;
    Controller() {}
};
struct FUN_00aaf800 : Controller {
    Array array;
    virtual void v00();
    FUN_00aaf800();
};
// pdb: NiBSBoneLODController::NiBSBoneLODController | NiBSBoneLODController.obj | fnv360_0822_debug, call_seq, low
FUN_00aaf800::FUN_00aaf800() { index=-1;array.Initialize(0,1); }
}
}   // namespace f3m_00aaf800

// @f3 0x00aa5720 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aa5720 {
namespace f3_2911 {
struct RefObject {
 virtual ~RefObject();
 unsigned int unk04;
 volatile long references;
 inline void DeleteThis() { delete this; }
 inline void Release() { if(InterlockedDecrement(&references)==0) DeleteThis(); }
};
// pdb: BSSimpleArray<NiPointer<QueuedFile>,1024>::_DestructItems | QueuedFiles.obj | fnv360_0822_retail, call_seq, low
// pdb params: apFirstAddr, aiCount
void __stdcall FUN_00aa5720(RefObject** items,unsigned int count) {
 for(unsigned int i=0;i<count;++i) {
  if(items[i]) {
  RefObject* item=items[i];
  if(InterlockedDecrement(&item->references)==0) delete item;
  }
 }
}
}

}   // namespace f3m_00aa5720

// @f3 0x00aa37d0 (community match, verified in this file)
namespace f3m_00aa37d0 {

namespace f3m_00aa37d0 {
extern BOOL (__stdcall* DAT_00d9b07c)(DWORD);
struct Heap { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct Pool {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int pending;
    void FUN_00aa3000();
};
struct Entry { int key; Pool* pool; };
struct Registry {
    unsigned int count;
    DWORD tlsIndex;
    Entry* entries;
    void FUN_00aa37d0();
};
// pdb: ThreadSpecificInterfaceManager<LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface>::~ThreadSpecificInterfaceManager<LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface> | IOManager.obj | fnv360_0822_retail, call_gap, low
void Registry::FUN_00aa37d0()
{
    for (unsigned int i = 0; i < count; ++i) {
        Pool* volatile v = entries[i].pool;
        v = v;
        if (v) {
            Pool* p = v;
            while (p->pending)
                p->FUN_00aa3000();
            DAT_01090a78.FUN_0086ba60(p);
        }
    }
    DAT_01090a78.FUN_0086ba60(entries);
    DAT_00d9b07c(tlsIndex);
}
}
}   // namespace f3m_00aa37d0

// @f3 0x00aa9fc0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00aa9fc0 {
namespace task2956 {
struct Semaphore {volatile LONG count;HANDLE handle;int unk08;void Release(){ReleaseSemaphore(handle,1,0);InterlockedIncrement(&count);}void Wait(){WaitForSingleObject(handle,INFINITE);InterlockedDecrement(&count);}};
struct Worker {
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
Semaphore start,done;};
struct Owner {Worker** workers;void(__cdecl*callback)(void*);void*argument;bool active;void FUN_00aa9fc0(void(__cdecl*)(void*),void*);};
// pdb: BSParallelTaskManager::RunTask | BSParallelTaskManager.obj | fnv360_0822_retail, call_seq, low
// pdb params: apTaskFunc, apData
void Owner::FUN_00aa9fc0(void(__cdecl*cb)(void*),void*arg){active=true;callback=cb;argument=arg;(*workers)->start.Release();callback(argument);(*workers)->done.Wait();active=false;}
}
}   // namespace f3m_00aa9fc0

// @f3 0x00ab7930 (community match, verified in this file)
namespace f3m_00ab7930 {

struct NiNode
{
    virtual ~NiNode();
    NiNode(unsigned short);
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
};

struct NiTPointerList_NiPointer_NiAVObject___ {
    void* head;
    void* tail;
    unsigned count;
    NiTPointerList_NiPointer_NiAVObject___() { count=0; head=0; tail=0; }
    ~NiTPointerList_NiPointer_NiAVObject___();
    void FUN_00abb340();
};
class NiParticles;
template<class T> class PrimitiveArrayStorage {
public:
    virtual ~PrimitiveArrayStorage();
    T* data;
    unsigned short capacity,size,used,grow;
    PrimitiveArrayStorage() {capacity=0;grow=1;size=0;used=0;data=0;}
};
template<class T> class NiTPrimitiveArray : public PrimitiveArrayStorage<T> {
public:
    NiTPrimitiveArray() {}
    virtual ~NiTPrimitiveArray();
};
class BSMasterParticleSystem : public NiNode {
public:
    NiTPointerList_NiPointer_NiAVObject___ emitters;
    unsigned short countB8,limitBA,countBC;
    unsigned fieldC0;
    int fieldC4,fieldC8;
    NiTPrimitiveArray<NiParticles*> particles;
    float fieldDC;
    virtual ~BSMasterParticleSystem();
    BSMasterParticleSystem();
};
// pdb: NiTPrimitiveArray<NiParticles *>::NiTPrimitiveArray<NiParticles *> | BSMasterParticleSystem.obj | fnv360_0822_retail, uvref, medium
// pdb params: uiMaxSize, uiGrowBy
BSMasterParticleSystem::BSMasterParticleSystem() : NiNode(0) {
    fieldC4=-1;
    fieldC8=-1;
    limitBA=20;
    countBC=0;
    countB8=0;
    fieldC0=0;
    emitters.FUN_00abb340();
    fieldDC=0.0f;
}
}   // namespace f3m_00ab7930

// @f3 0x00aa3df0 (community match, verified in this file)
namespace f3m_00aa3df0 {
namespace f52_00aa3df0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct WorkItemRef;
struct Scheduler;

// Per-thread work queue: the first lookup starts a scan, the second continues it.
struct ThreadQueue {
    bool FUN_00aa26f0(unsigned int slot, __int64* key, WorkItemRef* item);
    bool FUN_00aa3850(unsigned int slot, __int64* key, WorkItemRef* item);
};

// Thread-local slot holding one ThreadQueue per thread, created on demand.
// Thread-local slot holding one ThreadQueue per thread, created on demand.
struct ThreadQueueSlot {
    int unk00;
    unsigned tlsIndex;
    ThreadQueue* FUN_0042ba10(Scheduler* owner);
    ThreadQueue* Get(Scheduler* owner) {
        unsigned index = tlsIndex;
        void* value = TlsGetValue(index);
        return value ? (ThreadQueue*)value : FUN_0042ba10(owner);
    }
};

struct ScanState {
    void* vtable;
    int unk04;
    unsigned int slot;
    int unk0c;
    __int64 key;
    unsigned char flags;   // bit 0: scan of this slot started, bit 1: all slots exhausted
    bool Started() const { return bool(flags & 1); }
    bool Finished() const { return bool(flags & 2); }
    void SetStarted(bool value) { if (value) flags |= 1; else flags &= ~1; }
    void SetFinished(bool value) { if (value) flags |= 2; else flags &= ~2; }
};

struct Scheduler {
    void* vtable;
    int unk04;
    unsigned int slotCount;
    int unk0c;
    int unk10;
    ThreadQueueSlot* queues;
    unsigned Count() const { return slotCount; }
    ThreadQueue* GetQueue() { return queues->Get(this); }
    bool FUN_00aa3df0(ScanState* state, __int64* keyOut, WorkItemRef* item, bool advance);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::GetNext | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arIterator, arKey, arData, abSwitchBuckets
bool Scheduler::FUN_00aa3df0(ScanState* state, __int64* keyOut, WorkItemRef* item, bool advance)
{
    bool result = false;
    if (state->Finished())
        result = false;
    else {
        while (true) {
            if (!state->Started()) {
                result = GetQueue()->FUN_00aa26f0(state->slot, &state->key, item);
                state->SetStarted(true);
            } else
                result = GetQueue()->FUN_00aa3850(state->slot, &state->key, item);
            if (!result) {
                ++state->slot;
                if (state->slot >= Count())
                    state->SetFinished(true);
                else if (advance) {
                    state->SetStarted(false);
                    continue;
                }
            } else
                *keyOut = state->key;
            break;
        }
    }
    return result;
}
}
}   // namespace f3m_00aa3df0

// @f3 0x00aa4430 (community match, verified in this file)
namespace f3m_00aa4430 {
extern void* (__stdcall * const g_tlsGet_00aa4430)(unsigned long);
extern int (__stdcall * const g_tlsSet_00aa4430)(unsigned long, void*);
namespace fn_00aa4430 {
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* addend);
__declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct WorkQueue {
    bool PopItem(void* outItem);
};
struct ThreadSlotEntry {
    unsigned long m_threadId;
    WorkQueue* m_queue;
};
struct ThreadSlots {
    unsigned int m_capacity;
    unsigned long m_tlsIndex;
    ThreadSlotEntry* m_entries;
    volatile long m_used;
};
struct QueueSource {
    virtual void v00();
    virtual WorkQueue* CreateQueue(unsigned int slot);
    int m_fields[4];
    ThreadSlots* m_slots;
};
static __forceinline WorkQueue* GetThreadQueue(QueueSource& source) {
    ThreadSlots& slots = *source.m_slots;
    unsigned long index = slots.m_tlsIndex;
    WorkQueue* existing = (WorkQueue*)g_tlsGet_00aa4430(index);
    if (existing) {
        return existing;
    }
    WorkQueue* created = 0;
    unsigned int slot = InterlockedIncrement(&slots.m_used) - 1;
    if (slot < slots.m_capacity) {
        created = source.CreateQueue(slot);
        slots.m_entries[slot].m_queue = created;
        slots.m_entries[slot].m_threadId = GetCurrentThreadId();
        g_tlsSet_00aa4430(slots.m_tlsIndex, created);
    }
    return created;
}
struct QueueContext {
    virtual void v00();
    virtual void v01();
    virtual void OnPopped();
    QueueSource** m_sources;
    unsigned int m_count;
    bool FUN_00aa4430(void* outItem);
};
bool QueueContext::FUN_00aa4430(void* outItem) {
    for (unsigned int i = 0; i < m_count; ++i) {
        WorkQueue* queue = GetThreadQueue(*m_sources[i]);
        if (queue->PopItem(outItem)) {
            OnPopped();
            return true;
        }
    }
    return false;
}
}
}   // namespace f3m_00aa4430

// @f3 0x00aac810 (community match, verified in this file)
namespace f3m_00aac810 {
namespace fn_00aac810 {
struct Point3 {
    float x, y, z;
};
class Point2 {
public:
    float x, y;
    Point2() {}
    Point2(float a, float b) {
        x = a;
        y = b;
    }
};
struct PointArray {
    void* vptr;
    Point3* data;
    unsigned size, capacity;
    Point3& GetAt(unsigned i) const { return data[i]; }
};
struct ShortArray {
    void* table;
    unsigned short* data;
    unsigned size, capacity;
    bool Contains(const unsigned short& value) const;
};
__declspec(noinline) bool ShortArray::Contains(const unsigned short& value) const {
    unsigned n;
    for (n = 0; n < size; ++n)
        if (data && data[n] == value)
            goto found;
    n = (unsigned)-1;
found:
    return n != (unsigned)-1;
}
struct TriangulationPolygon {
    PointArray* vertices;
    ShortArray* concave;
    bool FUN_00aac810(unsigned tip, unsigned previous, unsigned next);
    bool PointInTriangle(Point2 point, unsigned a, unsigned b, unsigned c);
};
inline float SignedEdgeArea(const Point3& from, const Point3& to, double x, double y) {
    const float edgeX = to.x - from.x;
    const float edgeY = to.y - from.y;
    const float pointX = float(x - from.x);
    const float pointY = float(y - from.y);
    return edgeX * pointY - edgeY * pointX;
}
__declspec(noinline) bool TriangulationPolygon::PointInTriangle(Point2 point, unsigned a, unsigned b, unsigned c) {
    const Point3* data = vertices->data;
    const double y = point.y;
    const double x = point.x;
    if (!(SignedEdgeArea(data[b], data[c], x, y) <= 0.0f))
        return false;
    if (!(SignedEdgeArea(data[c], data[a], x, y) <= 0.0f))
        return false;
    return SignedEdgeArea(data[a], data[b], x, y) <= 0.0f;
}
// pdb: BSPolygon2D::IsAnEar | BSPolygon.obj | fnv360_0721_beta, objrun, medium
// pdb params: aiIndex, aiPrev, aiNext
__declspec(noinline) bool TriangulationPolygon::FUN_00aac810(unsigned tip, unsigned previous, unsigned next) {
    ShortArray* list = concave;
    if (list) {
        const unsigned count = list->size;
        if (count > 0) {
            const unsigned short key = static_cast<unsigned short>(tip);
            if (!list->Contains(key)) {
                for (unsigned i = 0; i < count; ++i) {
                    const unsigned index = list->data[i];
                    if (index != previous && index != next) {
                        const Point3& vertex = vertices->GetAt(index);
                        const Point2 point(vertex.x, vertex.y);
                        if (PointInTriangle(point, previous, tip, next))
                            return false;
                    }
                }
                return true;
            }
            return false;
        }
    }
    return true;
}
}
}   // namespace f3m_00aac810
