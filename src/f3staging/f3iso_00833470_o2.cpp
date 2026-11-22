#include <new>
// src/f3staging/f3iso_00833470_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00833470 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00833470 (community match, verified in this file)
struct NiNode;
struct NiStream { char pad[0xd8]; unsigned m_uiNifVersion; unsigned FUN_0082a2b0(); void* FUN_0082a280(); };
struct NiAVObject { void FUN_00827480(NiStream&); };
struct List { NiTListItem<NiNode*>* m_pkHead; NiTListItem<NiNode*>* m_pkTail; struct {unsigned m_uiCount;} m_kItemCount; };
struct NiDynamicEffect : NiAVObject { char pad[0xb8]; List m_kAffectedNodes; void FUN_00833470(NiStream&); };
namespace Native924 {
typedef NiTListItem<NiNode*> Item;
struct Lock { volatile long owner; void FUN_00409a80(int); };
extern Lock DAT_0106e5a0;
extern int DAT_0106e5a4;
extern Item* DAT_0106e588;
extern long (__stdcall* DAT_00d9b06c)(volatile long*, long, long);
void __cdecl FUN_00422ab0();
static __forceinline Item* NewItem()
{
    DAT_0106e5a0.FUN_00409a80(0);
    Item* item = DAT_0106e588;
    if (!item) { FUN_00422ab0(); item = DAT_0106e588; }
    DAT_0106e588 = item->m_pkNext;
    item->m_element = 0;
    item->m_pkNext = 0;
    item->m_pkPrev = 0;
    if (!--DAT_0106e5a4)
    {
        long owner = DAT_0106e5a0.owner;
        DAT_00d9b06c(&DAT_0106e5a0.owner, 0, owner);
    }
    return item;
}
}
// pdb: NiDynamicEffect::LinkObject | NiDynamicEffect.obj | fnv360_0822_retail, objrun, medium
// pdb params: kStream
void NiDynamicEffect::FUN_00833470(NiStream& stream)
{
    NiAVObject::FUN_00827480(stream);
    if (stream.m_uiNifVersion >= 0x0a00010e)
    {
        unsigned int count = stream.FUN_0082a2b0();
        while (count--)
        {
            NiNode* node = reinterpret_cast<NiNode*>(stream.FUN_0082a280());
            if (node)
            {
                NiTListItem<NiNode*>* item = Native924::NewItem();
                item->m_element = node;
                item->m_pkPrev = 0;
                item->m_pkNext = m_kAffectedNodes.m_pkHead;
                if (m_kAffectedNodes.m_pkHead)
                    m_kAffectedNodes.m_pkHead->m_pkPrev = item;
                else
                    m_kAffectedNodes.m_pkTail = item;
                ++m_kAffectedNodes.m_kItemCount.m_uiCount;
                m_kAffectedNodes.m_pkHead = item;
            }
        }
    }
}
