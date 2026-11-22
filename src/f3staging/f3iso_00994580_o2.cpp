#include <new>
// src/f3staging/f3iso_00994580_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00994580 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00994580 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00994580 {
struct SweepNodeX {
    unsigned int minimum, maximum;
    unsigned short lowZ, highZ;
    unsigned int handle;
};
struct SweepPairX {
    unsigned int* first;
    unsigned int second;
    SweepPairX(unsigned int* a, unsigned int b) : first(a), second(b) {}
};
struct SweepPairsX { SweepPairX* data; int size; unsigned int capacity; };
struct SweepNodesX { SweepNodeX* data; int size; unsigned int capacity; };
struct Endpoint { unsigned short value, handle; };
struct SweepAxisX {
    Endpoint* data; int size; unsigned int capacity;
    void FUN_00991230(int low, int high);
};
struct SweepGroupX {
    unsigned short node, unk02;
    unsigned short* data;
    int size;
    unsigned int capacity;
    __forceinline int find(unsigned short value) const {
        for (int i = 0; i < size; ++i)
            if (data[i] == value) return i;
        return -1;
    }
};
struct SweepThreadMemory {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void* OnStackOverflow(int bytes);
    virtual void OnStackUnderflow(void* pointer);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* current;
    int unk24;
    char* base;
    char* end;
};
extern void* (__stdcall *DAT_00d9b080)(unsigned int);
void __cdecl FUN_00901f10(SweepPairsX*, int);
void __cdecl FUN_00901e90(SweepNodesX*, int, int);
struct SweepOwnerX {
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
    SweepNodesX nodes;
    SweepAxisX axes[3];
    int groupCount;
    unsigned short shiftBits, unkD6;
    SweepGroupX* groups;
    void FUN_00991290(int count, int key, SweepNodeX* node, unsigned int index, unsigned int* bits);
    void FUN_00990c60(SweepNodeX* base, int count, SweepNodeX* node);
    void FUN_00994580(unsigned int* handle, SweepPairsX* pairs);
};

static __forceinline void RemoveOverlaps994580(SweepOwnerX& owner, SweepNodesX& nodeArray,
                                               unsigned int* handle, unsigned long nodeIndex,
                                               unsigned int* bitField, SweepNodeX& node,
                                               SweepPairsX* pairs)
{
    SweepNodeX* wordNodes = nodeArray.data;
    unsigned int* bitFieldEnd = bitField + (owner.nodes.size >> 5) + 1;
    for (; bitField < bitFieldEnd; wordNodes += 32, ++bitField) {
        SweepNodeX* testNode = wordNodes;
        unsigned int mask = *bitField;
        while (mask) {
            if (!(mask & 255)) {
                testNode += 8;
                mask >>= 8;
            } else {
                if (mask & 1) {
                    if (!(((testNode->maximum - node.minimum) |
                           (node.maximum - testNode->minimum)) & 0x80008000)) {
                        unsigned int other = testNode->handle;
                        if (!(other & 1)) {
                            if (pairs->size == (int)(pairs->capacity & 0x3fffffff))
                                FUN_00901f10(pairs, 8);
                            pairs->data[pairs->size] = SweepPairX(handle, other);
                            ++pairs->size;
                        } else {
                            SweepGroupX* group = reinterpret_cast<SweepGroupX*>(
                                reinterpret_cast<char*>(owner.groups) + (other & ~1));
                            int at = group->find((unsigned short)nodeIndex);
                            int& members = group->size;
                            members--;
                            int last = members;
                            group->data[at] = group->data[last];
                        }
                    }
                }
                ++testNode;
                mask >>= 1;
            }
        }
    }
}

// pdb: hkp3AxisSweep::removeObject | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
void SweepOwnerX::FUN_00994580(unsigned int* handle, SweepPairsX* pairs)
{
    unsigned long base = *handle;
    unsigned long count = nodes.size;
    SweepNodesX& arr = nodes;
    SweepNodeX* alloc = arr.data + base;

    unsigned int* index;
    SweepThreadMemory* memory = (SweepThreadMemory*)DAT_00d9b080(DAT_010f3170);
    int bytes = (int)(((count >> 5) * 4 + 0x30) & ~0xf);
    char* current = memory->current;
    char* next = current + bytes;
    if (next <= memory->end) {
        memory->current = next;
        index = (unsigned int*)current;
    } else {
        index = (unsigned int*)memory->OnStackOverflow(bytes);
    }

    FUN_00991290(count, axes[0].data[alloc->lowZ].value, alloc, base, index);
    RemoveOverlaps994580(*this, arr, handle, base, index, *alloc, pairs);

    SweepThreadMemory* endMemory = (SweepThreadMemory*)DAT_00d9b080(DAT_010f3170);
    endMemory->current = (char*)index;
    if ((char*)index == endMemory->base)
        endMemory->OnStackUnderflow(index);

    SweepNodeX* originalNodes = arr.data;
    axes[0].FUN_00991230(alloc->lowZ, alloc->highZ);
    axes[1].FUN_00991230(
        (unsigned short)alloc->minimum, (unsigned short)alloc->maximum);
    axes[2].FUN_00991230(
        (unsigned short)(alloc->minimum >> 16), (unsigned short)(alloc->maximum >> 16));
    FUN_00990c60(originalNodes, count, alloc);

    if (base < (unsigned int)(count - 1)) {
        *alloc = arr.data[count - 1];
        axes[0].data[alloc->lowZ].handle = (unsigned short)base;
        axes[0].data[alloc->highZ].handle = (unsigned short)base;
        if (!(alloc->handle & 1)) {
            axes[1].data[(unsigned short)alloc->minimum].handle = (unsigned short)base;
            axes[1].data[(unsigned short)alloc->maximum].handle = (unsigned short)base;
            axes[2].data[(unsigned short)(alloc->minimum >> 16)].handle = (unsigned short)base;
            axes[2].data[(unsigned short)(alloc->maximum >> 16)].handle = (unsigned short)base;
            *(unsigned int*)alloc->handle = base;
        } else {
            SweepGroupX* group = reinterpret_cast<SweepGroupX*>(
                reinterpret_cast<char*>(groups) + (alloc->handle & ~1));
            group->node = (unsigned short)base;
        }
        if (groupCount && !(alloc->handle & 1)) {
            unsigned short low = alloc->lowZ;
            Endpoint* endpoints = axes[0].data;
            int cursor = endpoints[low].value >> (unsigned short)(16 - shiftBits);
            if (cursor > 0 && arr.data[groups[cursor - 1].node].highZ > low)
                --cursor;
            int end = (endpoints[alloc->highZ].value >> (unsigned short)(16 - shiftBits)) - 1;
            if (cursor <= end) {
                unsigned short oldIndex = (unsigned short)(count - 1);
                for (int i = cursor; i <= end; ++i) {
                    SweepGroupX& group = groups[i];
                    group.data[group.find(oldIndex)] = (unsigned short)base;
                }
            }
        }
    }

    int newCount = count - 1;
    int capacity = arr.capacity & 0x3fffffff;
    if (capacity < newCount) {
        int doubled = capacity * 2;
        FUN_00901e90(&arr, newCount < doubled ? doubled : newCount, 16);
    }
    arr.size = newCount;
}
}   // namespace f3m_00994580
