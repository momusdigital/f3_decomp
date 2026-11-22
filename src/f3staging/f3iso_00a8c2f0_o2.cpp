#include <new>
// src/f3staging/f3iso_00a8c2f0_o2.cpp - Fallout 3 ISOLATED unit (19 Nov 2026) for 0x00a8c2f0 alone: its original passes arguments in registers to
// a static helper of its own file, which only works without other code (16-byte-aligned locals) in the unit. Write the helper
// static in your candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a8c2f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a8c2f0 {
namespace monitor_stream {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long slot) throw();
extern int __cdecl hkString_strCmp(const char* first, const char* second);

struct ThreadMemory {
    struct FreeBlock {
        FreeBlock* next;
    };
    struct Bucket {
        FreeBlock* first;
        int count;
    };
    enum MemoryClass { MEMORY_CLASS_MONITOR = 27 };
    struct Stack {
        __declspec(align(16)) char* current;
        Stack* previous;
        char* base;
        char* end;
    };
    virtual void* alignedAllocate(int alignment, int bytes, MemoryClass category);
    virtual void alignedDeallocate(void* block);
    virtual void setStackArea(void* buffer, int bytes);
    virtual void releaseCachedMemory();
    virtual ~ThreadMemory();
    virtual void* onStackOverflow(int bytes);
    virtual void onStackUnderflow(void* block);
    void* memory;
    int referenceCount;
    Stack stack;
    int stackSize;
    int maxPerList;
    Bucket buckets[17];
    int rowToSize[17];
    char smallSizeToRow[513];
    int largeSizeToRow[8];
    void* FUN_008f6800(int sizeClass, MemoryClass category) throw();
    void* allocateMonitorNode() {
        Bucket& bucket = buckets[6];
        if (bucket.first) {
            FreeBlock* result = bucket.first;
            --bucket.count;
            bucket.first = result->next;
            return result;
        }
        return FUN_008f6800(6, MEMORY_CLASS_MONITOR);
    }
};

template<class T>
struct Array {
    T* data;
    int size;
    int capacityAndFlags;
    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }
};

struct FUN_00a8d060 {
    typedef FUN_00a8d060 Node;
    float values[8];
    unsigned short counts[8];
    Array<Node*> children;
    double absoluteStartTime;
    Node* parent;
    const char* name;
    unsigned int userFlags;
    unsigned int type;
    enum NodeType { TIMER, DIRECTORY, SINGLE };

    FUN_00a8d060(Node* owner, const char* label, NodeType nodeType) throw();
    static void* operator new(unsigned int) {
        ThreadMemory* thread = static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
        return thread->allocateMonitorNode();
    }
};
typedef FUN_00a8d060 MonitorNode;

// pdb: findChildWithHint | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, objrun, medium, conflict (skyrim: hkDefaultMemoryTracker::ClassAlloc::operator==)
static __declspec(noinline) bool FUN_00a8c2f0(const char* name, int& hint, const MonitorNode* parent)
{
    if (parent->children.size > hint && hkString_strCmp(parent->children[hint]->name, name) == 0)
        return true;
    for (int i = 0; i < parent->children.size; ++i) {
        if (hkString_strCmp(parent->children[i]->name, name) == 0) {
            hint = i;
            return true;
        }
    }
    return false;
}

void __cdecl FUN_00a8d1f0(MonitorNode* destination, MonitorNode* source,
                          int hint, int sourceTimer, float blend)
{
    int timer = hint;
    if (timer > 6)
        timer = 6;
    hint = 0;
    int i = 0;
    if (source->children.size > 0) {
        double weight = 1.0f - blend;
        int size;
        do {
            MonitorNode* sourceChild = source->children[i];
            MonitorNode* result;
            if (!FUN_00a8c2f0(source->children[i]->name, hint, destination)) {
                void* storage = MonitorNode::operator new(sizeof(MonitorNode));
                if (storage) {
                    MonitorNode::NodeType kind = static_cast<MonitorNode::NodeType>(sourceChild->type);
                    result = ::new(storage) MonitorNode(destination, sourceChild->name, kind);
                } else {
                    result = 0;
                }
            } else {
                result = destination->children[hint];
            }
            result->values[timer] = static_cast<float>(sourceChild->values[sourceTimer] * weight + result->values[timer]);
            result->counts[timer] = sourceChild->counts[sourceTimer];
            FUN_00a8d1f0(result, sourceChild, timer, sourceTimer, blend);
            size = source->children.size;
            if (hint < size - 1)
                ++hint;
            ++i;
        } while (i < size);
    }
}
}
}   // namespace f3m_00a8c2f0
