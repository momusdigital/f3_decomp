#include <windows.h>
#include <new>
// src/f3staging/f3iso_00af1dd0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00af1dd0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00af1dd0 (community match, verified in this file)
// Fallout's texture-manager layout. Supporting types are private to this
// contribution; only FUN_00b6f0b0 replaces an existing unit declaration.
struct RendererAF19Heap
{
    void FUN_0086ba60(void* memory) throw();
};
namespace RendererAF19Imports
{
    extern RendererAF19Heap DAT_01090a78;
}

struct RendererAF19RefObject
{
    virtual ~RendererAF19RefObject() throw();
    virtual void DeleteThis() throw();
    LONG m_refCount;

    void IncRefCount() throw() { InterlockedIncrement(&m_refCount); }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_refCount) == 0)
            DeleteThis();
    }
};
struct RendererAF19Texture : RendererAF19RefObject {};

struct RendererAF19Ptr
{
    RendererAF19Texture* m_object;

    operator RendererAF19Texture*() const throw() { return m_object; }

    ~RendererAF19Ptr() throw()
    {
        if (m_object)
            m_object->DecRefCount();
    }
    RendererAF19Ptr& operator=(RendererAF19Texture* object) throw()
    {
        if (m_object != object)
        {
            if (object)
                object->IncRefCount();
            if (m_object)
                m_object->DecRefCount();
            m_object = object;
        }
        return *this;
    }
    static void operator delete(void* memory) throw();
};
struct RendererAF19ValueNode
{
    RendererAF19ValueNode* m_next;
    RendererAF19ValueNode* m_prev;
    RendererAF19Ptr m_item;
};
struct RendererAF19SlotNode
{
    RendererAF19SlotNode* m_next;
    RendererAF19SlotNode* m_prev;
    RendererAF19Ptr* m_item;
};
struct RendererAF19ReturnPtr
{
    RendererAF19Texture* object;
};
struct RendererAF19PendingList
{
    RendererAF19ValueNode* m_head;
    RendererAF19ValueNode* m_tail;
    unsigned int m_count;
    void FUN_0058b9a0(RendererAF19ReturnPtr& result);
    ~RendererAF19PendingList();
};
struct RendererAF19PoolList
{
    RendererAF19ValueNode* m_head;
    RendererAF19ValueNode* m_tail;
    unsigned int m_count;
    void FUN_00469c50(RendererAF19ReturnPtr& result);
    ~RendererAF19PoolList();
};
struct RendererAF19SlotList
{
    RendererAF19SlotNode* m_head;
    RendererAF19SlotNode* m_tail;
    unsigned int m_count;
    ~RendererAF19SlotList() throw();
};
struct RendererAF19Lock
{
    // Thread ownership is shared with the node allocator's acquiring threads.
    volatile LONG m_owner;
    LONG m_count;
    void FUN_00409a80(int flag) throw();
};
extern RendererAF19Lock DAT_0106e5a0;
extern RendererAF19SlotNode* DAT_0106e588;
extern char DAT_00f6dd84;
extern int DAT_0108f048;

struct FUN_00b6f0b0
{
    RendererAF19PoolList m0[4];
    RendererAF19PoolList m30[4];
    RendererAF19SlotList m60;
    RendererAF19SlotList m6c;
    RendererAF19PendingList m78;
    RendererAF19PendingList m84;
    RendererAF19Ptr m90;
    RendererAF19Ptr m94;

    void FUN_00af0de0(RendererAF19Texture* texture) throw();
    void FUN_00af1be0(int a, int b);
    ~FUN_00b6f0b0();
};

inline void RendererAF19Ptr::operator delete(void* memory) throw()
{
    RendererAF19Imports::DAT_01090a78.FUN_0086ba60(memory);
}

// pdb: BSTextureManager::~BSTextureManager | BSTextureManager.obj | fnv360_0822_retail, call_gap_sim, medium
FUN_00b6f0b0::~FUN_00b6f0b0()
{
    {
        unsigned int count = m84.m_count;
        if (count != 0)
        {
            do
            {
                RendererAF19ReturnPtr result;
                m84.FUN_0058b9a0(result);
                if (result.object)
                    result.object->DecRefCount();
            } while (m84.m_count != 0);
        }
    }
    if (m78.m_count != 0)
    {
        do
        {
            RendererAF19ReturnPtr result;
            m78.FUN_0058b9a0(result);
            if (result.object)
                result.object->DecRefCount();
        } while (m78.m_count != 0);
    }
    {
        unsigned int count = m6c.m_count;
        if (count != 0)
        {
            do
            {
                RendererAF19Ptr* holder = m6c.m_head->m_item;
                *holder = 0;
                RendererAF19SlotNode* node = m6c.m_head;
                m6c.m_head = node->m_next;
                if (m6c.m_head)
                    m6c.m_head->m_prev = 0;
                else
                    m6c.m_tail = 0;
                node->m_item = 0;
                DAT_0106e5a0.FUN_00409a80(0);
                node->m_prev = 0;
                node->m_next = DAT_0106e588;
                --DAT_0106e5a0.m_count;
                DAT_0106e588 = node;
                if (DAT_0106e5a0.m_count == 0)
                {
                    LONG owner = DAT_0106e5a0.m_owner;
                    InterlockedCompareExchange(&DAT_0106e5a0.m_owner, 0, owner);
                }
                --m6c.m_count;
                delete holder;
            } while (m6c.m_count != 0);
        }
    }
    if (m60.m_count != 0)
    {
        do
        {
            RendererAF19Ptr* holder = m60.m_head->m_item;
            *holder = 0;
            RendererAF19SlotNode* node = m60.m_head;
            m60.m_head = node->m_next;
            if (m60.m_head)
                m60.m_head->m_prev = 0;
            else
                m60.m_tail = 0;
            node->m_item = 0;
            DAT_0106e5a0.FUN_00409a80(0);
            node->m_prev = 0;
            node->m_next = DAT_0106e588;
            --DAT_0106e5a0.m_count;
            DAT_0106e588 = node;
            if (DAT_0106e5a0.m_count == 0)
            {
                LONG owner = DAT_0106e5a0.m_owner;
                InterlockedCompareExchange(&DAT_0106e5a0.m_owner, 0, owner);
            }
            --m60.m_count;
            delete holder;
        } while (m60.m_count != 0);
    }
    if (DAT_00f6dd84 == 0)
        FUN_00af1be0(DAT_0108f048, 0);

    unsigned int* count = &m0[0].m_count;
    for (int n = 4; n != 0; --n)
    {
        while (*count != 0)
        {
            RendererAF19PoolList* list = (RendererAF19PoolList*)(count - 2);
            FUN_00af0de0(list->m_head->m_item);
            RendererAF19ReturnPtr result;
            list->FUN_00469c50(result);
            if (result.object)
                result.object->DecRefCount();
        }
        count += 3;
    }
    m90 = 0;
    m94 = 0;
}
