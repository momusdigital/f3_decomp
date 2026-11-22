// NiMemObject: the base of every Gamebryo class that allocates through the Gamebryo heap.
// Names: FNV360_PDB (NiMemObject::operator new/delete). PC: operator new 0x0089eb90, operator delete 0x0089ec10.
#ifndef FNV_NIMEMOBJECT_H
#define FNV_NIMEMOBJECT_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiMemObject
{
  public:
    static void* operator new(size_t stSize);
    static void* operator new[](size_t stSize);
    static void operator delete(void* pvMem, size_t stElementSize);
    static void operator delete[](void* pvMem, size_t stElementSize);

    // placement new (a class operator new hides the global one). There is no placement delete: with one, every
    // placement new-expression gets an exception-handling frame, and the game's have none.
    static void* operator new(size_t, void* p)
    {
        return p;
    }
    static void* operator new[](size_t, void* p)
    {
        return p;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiMemObject) == 0x1);
#endif
