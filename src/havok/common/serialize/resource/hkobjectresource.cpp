#include "f3_common.h"
// src/havok/common/serialize/resource/hkobjectresource.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resource/hkobjectresource.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

namespace fnv_00e04ee0 {
struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

}  // namespace fnv_00e04ee0

struct FUN_00e05090_class;

struct FUN_00e05090_manager
{
    // Virtual destructor for the manager class; performs no work.
// @fnv 0x00e05090
    virtual ~FUN_00e05090_manager()
    {}
    virtual void FUN_00e05090_other();
    virtual void FUN_00e05090_free(FUN_00e05090_class* pObject, unsigned short resourceId);
};

struct FUN_00e05090_class
{
    virtual FUN_00e05090_class* FUN_00e05090(int flags);
    unsigned short m_resourceId;
    void ReleaseResource();
};

struct hkBoolD46D
{
    char m_cBooleanValue;
    hkBoolD46D(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class FUN_00d46d40_s
{
  public:
    const char* FUN_00d46d40();
    FUN_00d46d40_s* FUN_00d46d50();

    hkBoolD46D FUN_00d46d80(FUN_00d46d40_s* pkNode);
};

// @fnv 0x00e04e50
// pdb: hkpConvexPieceMeshShape::getFirstKey | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00e04e50()
{
    return 0;
}

extern "C" void* DAT_010ea4dc[];
// @f3 0x006d5980 (community match, verified in this file)
namespace f3m_006d5980 {
struct Heap {
    void FUN_0086ba60(void*);
};
extern Heap DAT_01090a78;

struct Item {
    void FUN_006cdb80();
    ~Item() { FUN_006cdb80(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct ListNode {
    Item* item;
    ListNode* next;
    void FUN_006c8220();
    ~ListNode() { FUN_006c8220(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Owner {
    ListNode* list;
    int unk04;
    void FUN_006d5980();
};

// pdb: BGSSaveLoadManager::DeleteSaveGameList | BGSSaveLoadManager.obj | fnv360_0721_beta, caller, low, conflict (skyrim: BGSCellNumericIDArrayMap::AddReference)
void Owner::FUN_006d5980()
{
    for (ListNode* node = list; node; node = node->next) {
        if (node->item)
            delete node->item;
    }
    if (list) {
        list->FUN_006c8220();
        delete list;
        list = 0;
    }
    unk04 = 0;
}
}


namespace fnv_00e04f80 {

struct Referenced_00e04f80
{
    void FUN_00c905b0();
};

struct ListenerVTable_00e04f80;
struct Listener_00e04f80
{
    ListenerVTable_00e04f80* methods;
};
typedef void (Listener_00e04f80::*ResourceCallback_00e04f80)(Referenced_00e04f80*, const char*);
struct ListenerVTable_00e04f80
{
    ResourceCallback_00e04f80 vfunc00;
    ResourceCallback_00e04f80 vfunc04;
    ResourceCallback_00e04f80 vfunc08;
    ResourceCallback_00e04f80 vfunc0c;
    ResourceCallback_00e04f80 vfunc10;
    ResourceCallback_00e04f80 onResourceRemoved;
};

extern char DAT_010ea4dc;

}  // namespace fnv_00e04f80

namespace fnv_00e05030 {
struct hkBool
{
    char m_cBooleanValue;
    hkBool();
};

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
    hkBool FUN_00d46d80(FUN_00d46d40_s* other);
};

}  // namespace fnv_00e05030
