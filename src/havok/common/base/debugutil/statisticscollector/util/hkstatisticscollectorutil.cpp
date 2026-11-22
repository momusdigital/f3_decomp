#include "f3_common.h"
// src/havok/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class Hasher
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
    virtual int Hash(const char* s, int len);
};

struct Audio
{
    char pad[0x10];
    Hasher* hasher;
    Hasher& GetHasher()
    {
        return *hasher;
    }
};

extern "C" Audio* __cdecl FUN_00c85750();

// If s is non-null, computes its length plus one, hashes it via the audio hasher, and emits it through h with kind 1 and *a.
// @f3 0x0046b740 (community match, verified in this file)
struct FUN_00cf5fe0_Node
{
    FUN_00cf5fe0_Node* next;
    FUN_00cf5fe0_Node* prev;
    void* value;
};
struct FUN_00cf5fe0_Pool
{
    int refs;
    FUN_00cf5fe0_Node* FUN_00423640();
};
struct FUN_00cf5fe0_List
{
    FUN_00cf5fe0_Node* tail;
    FUN_00cf5fe0_Node* head;
    FUN_00cf5fe0_Pool pool;
};
struct FUN_00cf5fe0_Manager
{
    char pad00[0x14];
    FUN_00cf5fe0_List list;
};
extern "C" FUN_00cf5fe0_Manager* __cdecl FUN_0046b690();

// pdb: BGSDecalManager::AddDecalEmitter | BGSDecalManager.obj | fnv360_0822_retail, objrun, medium
// pdb params: apEmitter
extern "C" void __cdecl FUN_00cf5fe0(void* value)
{
    if (!value)
        return;
    FUN_00cf5fe0_List* list = &FUN_0046b690()->list;
    FUN_00cf5fe0_Node* n = list->pool.FUN_00423640();
    n->value = value;
    n->next = 0;
    n->prev = list->head;
    if (list->head)
    {
        list->head->next = n;
        list->pool.refs++;
        list->head = n;
    }
    else
    {
        list->pool.refs++;
        list->tail = n;
        list->head = n;
    }
}


namespace fnv_00cf6080 {
struct S_00cf6080_Allocator
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void* vfn_2C(void* p, int numBytes);
};
struct S_00cf6080_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00cf6080_Allocator* unk10;
    S_00cf6080_Allocator* heap()
    {
        return unk10;
    }
};
S_00cf6080_Router* FUN_00c85750();

}  // namespace fnv_00cf6080

struct Target
{
    int FUN_00d470d0();
};

struct TypeInfo
{
    unsigned char m_ucKind;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    short m_sValue;
};

TypeInfo* __cdecl FUN_00d868a0(int aiType);

struct Thing
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    unsigned char m_ucType;

    Target* FUN_00d86910();
};

// Reads the type from apThing, looks up its TypeInfo, and returns m_sValue if positive, else the result of FUN_00d470d0 for kind 0x19, otherwise -1.
// @f3 0x0097e9c0 (community match, verified in this file)
// pdb: hkStatisticsCollectorUtil::_getArrayElementSize | hkStatisticsCollectorUtil.obj | fnv360_0822_retail, caller_sim, high
// pdb params: mem
// pdb: hkStatisticsCollectorUtil::_getArrayElementSize | hkStatisticsCollectorUtil.obj | fnv360_0822_retail, caller_sim, high (was: GetThingValue)
int __cdecl hkStatisticsCollectorUtil__getArrayElementSize(Thing* thing) {
 TypeInfo* info=FUN_00d868a0(thing->m_ucType);
 short value=info->m_sValue;
 if(value>0)return value;
 if(info->m_ucKind==25)return thing->FUN_00d86910()->FUN_00d470d0();
 return -1;
}


struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Shape;

__declspec(nothrow) hkBool __cdecl GetFlagByState(const Shape* s);

// FUN_00cf60d0 - 69 bytes at 0x00cf60d0
//
// The function forwards to one of two virtual slots of its last argument,
// choosing between them on the flag byte that the walker writes through the
// pointer it is handed.  The walker returns the very pointer it was given, so
// the test reads the byte through the returned pointer.

void* __cdecl FUN_00cf60d0(void* context, const void* a, const void* b, const void* c);

struct SpawnedObject
{
    int CalleeA(int aiArg);
};

void __cdecl CalleeB_00cf60d0(int aiA, int aiB, int aiC, int aiD);

// Calls CalleeA on the object at aiSecond with aiFirst; if it returns nonzero, passes 0, aiFirst, the result and aiSecond to CalleeB_00cf60d0.
// @fnv 0x00cf6140
void __cdecl CallObjectMethodAndDispatch(int aiFirst, int aiSecond)
{
    SpawnedObject* pObj = (SpawnedObject*)aiSecond;
    int result = pObj->CalleeA(aiFirst);
    if (result != 0)
    {
        CalleeB_00cf60d0(0, aiFirst, result, aiSecond);
    }
}

struct CF63C0Bool
{
    char m_cBooleanValue;

    CF63C0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

// Candidate for GetFlagByState  (0x00cf62b0, 80 bytes)
//
// The original:
//   mov ecx,[esp+8]            ; the object
//   mov ax,word [ecx+0x10]     ; a 16-bit flag field
//   shr ax,9 / test al,1 / jne  -> set *out = 1
//   movzx eax,byte [ecx+0xc]   ; a byte "type" field
//   dec eax / cmp eax,0x20 / ja -> set *out = 0
//   movzx edx,byte [eax+map] / jmp [edx*4+jt]   (33-case two level switch)
//   ... 3 clusters: *out=1, *out=0, and one that calls a helper.
//
// The helper at 0x00d86910 is a __thiscall member that returns the dword at
// this+4; it must be a real call (not inlined) so that `this` stays in ECX.

struct Meta64;
struct Writer64;
struct Flags64
{
    unsigned short value;
    unsigned short get() const
    {
        return value;
    }
};
struct Member64
{
    const char* name;
    Meta64* pClassInfo;
    void* enumeration;
    unsigned char type, subtype;
    short cArraySize;
    Flags64 flags;
    unsigned short offset;
    void* attributes;
    int FUN_00d86940();
    Meta64* FUN_00d86910();
};
struct Meta64
{
    int FUN_00d46f70();
    Member64* FUN_00d46f80(int);
    int FUN_00d470d0();
};
struct Writer64
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Begin(const char*);
    virtual void End();
    int unk04, unk08, unk0c;
    unsigned char includeStorage;
    void EmitString(const char*, const char*);
};
void __cdecl FUN_00cf60d0(const char*, void*, Meta64*, Writer64*);
int __cdecl hkStatisticsCollectorUtil__getArrayElementSize(Member64*);

struct hkClassMember
{
    const char* m_name;
    void* m_class;
    void* m_pClassEnum;
    unsigned char m_type;
    enum Type
    {
        TYPE_VOID
    };
    Type getType() const
    {
        return (Type)m_type;
    }
};

struct hkClass
{
    int GetNumDeclaredMembers() const;
    const hkClassMember& GetDeclaredMember(int i) const;
    void touch() const
    {}
};

int __cdecl FUN_00cb0fa0(const char* a, const char* b);

const void* volatile g_obj;
const hkClass* volatile g_klass;
const char* volatile g_out;

int __cdecl FUN_00cb0fa0(const char*, const char*);
