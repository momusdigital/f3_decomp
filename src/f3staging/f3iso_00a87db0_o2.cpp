#include <new>
// src/f3staging/f3iso_00a87db0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a87db0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a87db0 (community match, verified in this file)
namespace f3m_00a87db0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace Sa87db0_ {

void __cdecl FUN_00901f10(void* array, int elemSize);

struct TlsHolder
{
    static unsigned long DAT_010f3170;
};

struct Heap
{
    void FUN_008f6d90(void* data, int size, int tag);
};

struct P154Array
{
    int* data;
    int count;
    int capacity;

    __forceinline P154Array()
        : data(0), count(0), capacity(int(0x80000000))
    {
    }
    void FUN_009b2a80(int pos, int* src, int n);
    __forceinline void append(const int& v)
    {
        if (count == int(capacity & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[count] = v;
        ++count;
    }
    __forceinline void insert(int* src, int pos, int n)
    {
        FUN_009b2a80(pos, src, n);
    }
    __forceinline void release()
    {
        if (!(capacity & int(0x80000000)))
        {
            int cap = capacity & 0x3fffffff;
            Heap* heap = (Heap*)TlsGetValue(TlsHolder::DAT_010f3170);
            heap->FUN_008f6d90(data, cap * 4, 23);
        }
    }
};

struct P154Pair
{
    int first;
    int second;
};

struct P154PairArray
{
    P154Pair* data;
    int count;
    int capacity;

    __forceinline P154Pair& grow()
    {
        if (count == int(capacity & 0x3fffffff))
            FUN_00901f10(this, 8);
        return data[count++];
    }
};

struct P154Metric
{
    virtual void slot00();
    virtual int cost(const int* data, int count);
};

struct P154Settings
{
    int limit;
    int unk04, unk08, unk0C;
    P154PairArray pairs;
    P154Metric* metric;
    int base;
};

struct P154Writer
{
    int unk00, unk04, unk08;
    int count;
};

struct P154Node
{
    int unk00;
    bool leaf;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C;
    int index;
    int unk44, unk48, unk4C, unk50, unk54, unk58;
    int offset;
    int* values;
    int unk64, unk68, unk6C;
    P154Node* high;
    P154Node* low;
};

struct P154Region
{
    int depth;
    bool leaf;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30;
    int context;
    int unk38, unk3C, unk40, unk44;

    void FUN_00a85e30(P154Node* node);
    void FUN_00a88a60(P154Node* node, float* scale);
    void FUN_00a88b00();
};
typedef char VerifyP154Region72[(sizeof(P154Region) == 72) ? 1 : -1];

struct P154Result
{
    bool valid;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct P154Tree
{
    int unk00, unk04, unk08, unk0C;
    P154Writer* writer;
    P154Settings* settings;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    float scale30;

    int FUN_00a87710(P154Node* node, P154Region* parent, P154Region* region);
    void FUN_00a86fc0(P154Node* node, P154Region* parent, P154Region* region, P154Result* info);
    int FUN_00a87770(P154Node* node, P154Region* parent, P154Region* region, P154Result* info);
    int FUN_00a87db0(P154Node* node, P154Region* parent, P154Region* region, P154Array* output);

    __forceinline int getCost(const P154Array& values, int size) const
    {
        int cost = size;
        if (settings->metric && values.count)
            cost += settings->metric->cost(values.data, values.count);
        return cost;
    }
};

// pdb: hkpMoppDefaultAssembler::calcChunkPoints | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: currentNode, parentInfo, currentInfo, terminalsOut
int P154Tree::FUN_00a87db0(P154Node* node, P154Region* parent, P154Region* region, P154Array* output)
{
    int size;
    if (settings->metric)
        region->context = parent->context;
    if (node->leaf)
    {
        if (settings->metric)
            region->context = *node->values;
        int start = writer->count;
        FUN_00a87710(node, parent, region);
        int leafSize = writer->count - start;
        output->append(*node->values);
        int value = *node->values;
        int result = leafSize;
        if (settings->metric)
            result += settings->metric->cost(&value, 1);
        return result;
    }
    else
    {
        P154Result info;
        info.valid = false;
        FUN_00a86fc0(node, parent, region, &info);
        region->context = parent->context;
        P154Array lowValues;
        int lowSize, lowCost;
        {
            P154Node* low = node->low;
            P154Region child = *region;
            child.FUN_00a85e30(low);
            child.FUN_00a88a60(low, &scale30);
            child.depth = region->depth + 1;
            child.leaf = false;
            child.FUN_00a88b00();
            lowSize = writer->count;
            FUN_00a87db0(low, region, &child, &lowValues);
            lowSize = writer->count - lowSize;
            lowCost = getCost(lowValues, lowSize);
        }
        P154Array highValues;
        int highSize, highCost;
        {
            P154Node* high = node->high;
            P154Region child = *region;
            child.FUN_00a85e30(high);
            child.FUN_00a88a60(high, &scale30);
            child.depth = region->depth + 1;
            child.leaf = false;
            child.FUN_00a88b00();
            highSize = writer->count;
            FUN_00a87db0(high, region, &child, &highValues);
            highSize = writer->count - highSize;
            highCost = getCost(highValues, highSize);
        }
        int splitSize = writer->count;
        FUN_00a87770(node, parent, region, &info);
        splitSize = writer->count - splitSize;
        P154Array merged;
        merged.insert(lowValues.data, 0, lowValues.count);
        merged.insert(highValues.data, merged.count, highValues.count);
        size = highSize + splitSize + lowSize;
        if (settings->metric && merged.count)
            size += settings->metric->cost(merged.data, merged.count);
        bool highRemoved = false, lowRemoved = false;
        while (size >= settings->limit - settings->base)
        {
            int index = settings->pairs.count;
            P154Pair& pair = settings->pairs.grow();
            P154Node* selected;
            int oldSize, cost;
            if (highCost > lowCost)
            {
                selected = node->high;
                cost = highCost;
                oldSize = highSize;
                highCost = 3;
                highRemoved = true;
                size = lowRemoved ? splitSize + 6 : splitSize + lowCost + 3;
            }
            else
            {
                selected = node->low;
                cost = lowCost;
                oldSize = lowSize;
                lowCost = 3;
                lowRemoved = true;
                size = highRemoved ? splitSize + 6 : splitSize + highCost + 3;
            }
            pair.second = settings->base + cost + 5;
            selected->index = index;
            writer->count += 3 - oldSize;
            P154Node* lowChild = node->low;
            if (lowRemoved)
                lowChild->offset += 3 - oldSize;
            node->high->offset += 3 - oldSize;
            node->offset += 3 - oldSize;
        }
        output->count = 0;
        if (!lowRemoved)
            output->insert(lowValues.data, 0, lowValues.count);
        if (!highRemoved)
            output->insert(highValues.data, output->count, highValues.count);
        merged.release();
        highValues.release();
        lowValues.release();
    }
    return size;
}

}
}   // namespace f3m_00a87db0
