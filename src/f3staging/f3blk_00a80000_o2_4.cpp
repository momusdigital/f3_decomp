#include <windows.h>
// src/f3staging/f3blk_00a80000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00a8e7b0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a8e7b0 {

namespace monitor_report {
struct Stream;
struct Node;
struct Options;

void __cdecl FUN_00943960(Stream&, const char* format, ...);
int __cdecl hkString_strCmp(const char* lhs, const char* rhs);
void __cdecl FUN_00923500(void* dst, int value, int count);
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);
void __cdecl FUN_00a8d350(Node* sum, Node* frame);
void __cdecl FUN_00a8c550(Stream&, Node*, int depth, float factor);
void __cdecl FUN_00a8d310(Node*, Node*, int destTimer, int sourceTimer, float smoothing);
void __cdecl FUN_00a8ccf0(Node*, int numThreads, int numSpus, Stream&, Options&);

struct FreeList {
    struct Entry { Entry* next; };
    Entry* head;
    int count;

    void* take() {
        Entry* p = head;
        if (p) {
            --count;
            head = p->next;
        }
        return p;
    }
    void put(void* p) {
        ++count;
        Entry* entry = static_cast<Entry*>(p);
        entry->next = head;
        head = entry;
    }
};

struct ThreadMemory {
    unsigned int field00, field04, field08, field0c;
    unsigned int field10, field14, field18, field1c;
    char* stackCurrent;
    void* previousStack;
    char* stackBase;
    char* stackEnd;
    int stackSize;
    int maxFreeCount;
    FreeList rows[17];

    static ThreadMemory* get() {
        return static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
    }
    void* FUN_008f6800(int row, int memoryClass);
    void FUN_008f6890(int row, void* p, int memoryClass);
    void FUN_008f6d90(void* p, int bytes, int memoryClass);

    void* allocateNode() {
        if (void* p = rows[6].take()) return p;
        return FUN_008f6800(6, 0x1b);
    }
    void releaseNode(void* p) {
        if (rows[6].count >= maxFreeCount)
            FUN_008f6890(6, p, 0x1b);
        else
            rows[6].put(p);
    }
};

struct NodeArray {
    Node** data;
    int size;
    int capacityAndFlags;

    int getSize() const { return size; }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    Node*& operator[](int i) { return data[i]; }
    void reserve(int n) {
        const int capacity = getCapacity();
        if (capacity < n) {
            int doubled = 2 * capacity;
            FUN_00901e90(this, n < doubled ? doubled : n, sizeof(Node*));
        }
    }
    void setSize(int n) {
        reserve(n);
        size = n;
    }
    void releaseMemory() {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = getCapacity();
            ThreadMemory::get()->FUN_008f6d90(data, capacity * sizeof(Node*), 0x17);
        }
    }
};

struct Node {
    float value[8];
    unsigned short count[8];
    NodeArray children;
    double absoluteStartTime;
    Node* parent;
    const char* name;
    unsigned int userFlags;
    enum Type { Timer, Directory, Single } type;

    Node* FUN_00a8d060(Node* parent, const char* name, Type type);
    void FUN_00a8d0f0();
};

struct Options {
    int indentationToFirstTimerValue;
    int timerColumnWidth;
    int tabSpacingForTimerNames;
    int tabSpacingForTimerValues;
    bool displayPartialTree;
    Node* activeNode;
    char rightArrowChar, downArrowChar;
};

struct HkBool {
    unsigned char value;
    HkBool(bool b) : value(b) {}
};

static __declspec(noinline) Node* FUN_00a8c7a0(Node* root, const char* name, HkBool useFirstChild) {
    for (int i = 0; i < root->children.getSize(); ++i) {
        if (!hkString_strCmp(name, root->children[i]->name))
            return root->children[i];
    }
    if (useFirstChild.value && root->children.getSize() > 0)
        return root->children[0];
    return 0;
}

static __declspec(noinline) Node* FUN_00a8c800(Node* root, const char* name, const Node* previous) {
    int i = 0;
    for (; i < root->children.getSize(); ++i) {
        if (root->children[i] == previous) break;
    }
    for (++i; i < root->children.getSize(); ++i) {
        if (!hkString_strCmp(name, root->children[i]->name))
            return root->children[i];
    }
    return 0;
}

// pdb: hkMonitorStreamAnalyzer::writeStatisticsDetails | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, ustr, medium
// pdb params: outstream, nodes, numThreads, numSpus, reportLevel, nodeIdForFrameOverview, showMultithreadedSummary
void __cdecl FUN_00a8e7b0(Stream& stream, NodeArray* pArray, int aiThreadCount, int aiSpuCount, int flags, const char* key, bool combineThreads)
{
    FUN_00943960(stream, "Havok version: %s\n", "Havok-5.5.0-r1");
    if (pArray->size == 1)
    {
        float total = 0.0f;

        NodeArray* children = &pArray->data[0]->children;
        {
            Node sum;
            sum.FUN_00a8d060(0, "Sum", Node::Directory);
            float time = 1.0f / children->size;
            int i = 0;
            if (children->size > 0)
            {
                do
                {
                    FUN_00a8d350(&sum, children->data[i]);
                    i++;
                } while (i < children->size);
            }

            Node* node = FUN_00a8c7a0(&sum, key, true);
            if (node)
            {
                do
                {
                    total += node->value[0] * time;
                    node = FUN_00a8c800(&sum, key, node);
                } while (node);
            }
            if (total <= 0.0f)
                total = 1000.0f;
            if (flags & 1)
            {
                FUN_00943960(stream, "\n\n");
                FUN_00943960(stream, "*********************************\n");
                FUN_00943960(stream, "********** Total Times    *******\n");
                FUN_00943960(stream, "*********************************\n");
                FUN_00943960(stream, "Timers are added together\n");
                FUN_00a8c550(stream, &sum, 0, time);
            }
            sum.FUN_00a8d0f0();
        }
        if (flags & 2)
        {
            FUN_00943960(stream, "\n\n");
            FUN_00943960(stream, "*********************************\n");
            FUN_00943960(stream, "********** Per Frame Time *******\n");
            FUN_00943960(stream, "*********************************\n");
            FUN_00943960(stream, "Ascii Art all frames overview\n");
            char bar[50];

            FUN_00923500(bar, 0x20, 0x28);
            bar[40] = 0;
            int row = 0;
            for (; row < children->size; row++)
            {
                Node* pThread = children->data[row];
                if (pThread->children.size == 0)
                    continue;
                float time = 0.0f;
                const char* name = "Unknown";
                Node* t = FUN_00a8c7a0(pThread, key, true);
                if (t)
                {
                    do
                    {
                        time += t->value[0];
                        name = t->name;
                        t = FUN_00a8c800(pThread, key, t);
                    } while (t);
                }
                float pct = time * 20.0 / total;
                int bars = (int)pct;
                if (bars < 0)
                    bars = 0;
                if (bars >= 0x28)
                    bars = 0x27;
                int column = 0;
                char* p = bar;
                for (; column + 4 < bars; column += 4) *p++ = '\t';
                int marker = column;
                for (; marker < bars; ++marker) *p++ = ' ';
                *p++ = '#';
                ++marker;
                column += 4;
                for (; marker < column; ++marker) *p++ = ' ';
                for (; column < 40; column += 4) *p++ = '\t';
                *p = 0;
                FUN_00943960(stream, bar);
                FUN_00943960(stream, "%i %-12s %f\n", row, name, (double)time);
            }
        }
    }
    if (flags & 4)
    {
        if (pArray->size != 1 && combineThreads)
        {
            Node* pThread0 = pArray->data[0];
            int iFrame = 0;
            if (pThread0->children.size > 0)
            {
                do
                {
                    FUN_00943960(stream, "\n");
                    FUN_00943960(stream, "****************************************\n");
                    FUN_00943960(stream, "****** Summary Frame:%i ******\n", iFrame);
                    FUN_00943960(stream, "****************************************\n");
                    NodeArray arr;
                    arr.data = 0;
                    arr.size = 0;
                    arr.capacityAndFlags = (int)0x80000000;
                    int iCount = pArray->size;
                    arr.setSize(iCount);
                    for (int k = 0; k < pArray->size; k++)
                    {
                        Node* obj = (Node*)ThreadMemory::get()->allocateNode();
                        if (obj)
                            obj = obj->FUN_00a8d060(0, "", Node::Directory);
                        else
                            obj = 0;
                        arr.data[k] = obj;
                        Node* pThread = pArray->data[k];
                        if (pThread->children.size > iFrame)
                            FUN_00a8d350(arr.data[k], pThread->children.data[iFrame]);
                    }
                    int m = 1;
                    Options cfg;
                    cfg.tabSpacingForTimerNames = 4;
                    cfg.tabSpacingForTimerValues = 2;
                    cfg.timerColumnWidth = 0x10;
                    cfg.displayPartialTree = 0;
                    
                    for (; m < arr.size; m++)
                        FUN_00a8d310(arr.data[0], arr.data[m], m, 0, 0.0f);
                    FUN_00a8ccf0(arr.data[0], aiThreadCount, aiSpuCount, stream, cfg);
                    for (int k = 0; k < pArray->size; k++)
                    {
                        Node* obj = arr.data[k];
                        if (obj)
                        {
                            obj->FUN_00a8d0f0();
                            ThreadMemory::get()->releaseNode(obj);
                        }
                    }
                    arr.releaseMemory();
                    iFrame++;
                } while (iFrame < pArray->data[0]->children.size);
            }
        }
        else
        {
            Node* pThread0 = pArray->data[0];
            int frameIndex = 0;
            if (pThread0->children.size > 0)
            {
                do
                {
                    int threadIndex = 0;
                    if (pArray->size > 0)
                    {
                        do
                        {
                            Node* pThread = pArray->data[threadIndex];
                            if (frameIndex < pThread->children.size)
                            {
                                Node sum2;
                                sum2.FUN_00a8d060(0, "Sum", Node::Directory);
                                FUN_00a8d350(&sum2, pThread->children.data[frameIndex]);
                                FUN_00943960(stream, "\n");
                                FUN_00943960(stream, "****************************************\n");
                                FUN_00943960(stream, "****** Summary Frame:%i Thread:%i ******\n", frameIndex, threadIndex);
                                FUN_00943960(stream, "****************************************\n");
                                Node* pTimer = pThread->children.data[frameIndex];
                                FUN_00943960(stream, "%s\n", pTimer->name);
                                float one = 1.0f;
                                FUN_00a8c550(stream, &sum2, 0, one);
                                sum2.FUN_00a8d0f0();
                            }
                            threadIndex++;
                        } while (threadIndex < pArray->size);
                    }
                    frameIndex++;
                } while (frameIndex < pArray->data[0]->children.size);
            }
        }
    }
    if (flags & 8)
    {
        Node* pThread0 = pArray->data[0];
        int detailIndex = 0;
        if (pThread0->children.size > 0)
        {
            do
            {
                int threadIndex = 0;
                if (pArray->size > 0)
                {
                    do
                    {
                        Node* pThread = pArray->data[threadIndex];
                        if (detailIndex < pThread->children.size)
                        {
                            FUN_00943960(stream, "\n\n");
                            FUN_00943960(stream, "***************************************\n");
                            if (threadIndex < aiThreadCount)
                                FUN_00943960(stream, "***** Details Frame-%i Thread:%i ******\n", detailIndex, threadIndex);
                            else
                                FUN_00943960(stream, "***** Details Frame-%i Spu:%i ******\n", detailIndex,
                                             threadIndex - aiThreadCount);
                            FUN_00943960(stream, "***************************************\n");
                            FUN_00943960(stream, "%s\n", pThread->children.data[detailIndex]->name);
                            float one = 1.0f;
                            FUN_00a8c550(stream, pThread->children.data[detailIndex], 0, one);
                        }
                        threadIndex++;
                    } while (threadIndex < pArray->size);
                }
                detailIndex++;
            } while (detailIndex < pArray->data[0]->children.size);
        }
    }
}
}
}   // namespace f3m_00a8e7b0
