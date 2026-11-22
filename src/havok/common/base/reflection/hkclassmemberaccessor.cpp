#include "f3_common.h"
// src/havok/common/base/reflection/hkclassmemberaccessor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassmemberaccessor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d87210_class
{
    char* m_p;
    char* __thiscall FUN_00d87210(int index);
};

// @fnv 0x00d87210
// pdb: hkClassMemberAccessor::asPointer | hkClassMemberAccessor.obj | tesv_win, objrun, medium
char* __thiscall FUN_00d87210_class::FUN_00d87210(int index)
{
    return m_p + index * 4;
}

// @fnv 0x00d87220
// pdb: hkClassMemberAccessor::asPointer | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: hkClassMemberAccessor::asCstring)
// pdb params: index
char* __fastcall FUN_00d87220(char* self, int edx, int index)
{
    return *(char**)self + index * 4;
}

struct FUN_00d87260_cls
{
    char* __thiscall FUN_00d87260(int a);
};

// @fnv 0x00d87260
char* __thiscall FUN_00d87260_cls::FUN_00d87260(int a)
{
    return *reinterpret_cast<char**>(this) + a * 2;
}

// @fnv 0x00d87290
// pdb: hkClassMemberAccessor::asSimpleArray | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun, low
// pdb params: index
const void* __fastcall FUN_00d87290(const void* pThis, int, int index)
{
    return (const char*)(*(const char**)pThis) + index * 8;
}

struct FUN_00d872a0_t
{
    void* __thiscall FUN_00d872a0(int arg);
};

// @fnv 0x00d872a0
// pdb: hkClassMemberAccessor::asVariant | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: hkClassMemberAccessor::asHomogeneousArray)
// pdb params: index
void* __thiscall FUN_00d872a0_t::FUN_00d872a0(int arg)
{
    return (char*)*(void**)this + 8 * arg;
}

// @fnv 0x00d872c0
// pdb: hkClassMemberAccessor::asHalf | hkClassMemberAccessor.obj | tesv_win, objrun_sim, low
int __fastcall FUN_00d872c0(int* self, int edx, int offset)
{
    int base = *self;
    return base + offset * 2;
}

struct FUN_00d87300_class
{
    int* FUN_00d87300(int index);
};

// @fnv 0x00d87300
// pdb: hkClassMemberAccessor::asVector4 | hkClassMemberAccessor.obj | tesv_win, objrun, medium
int* FUN_00d87300_class::FUN_00d87300(int index)
{
    return *(int**)this + index * 4;
}

// @fnv 0x00d87310
// pdb: hkClassMemberAccessor::asMatrix3 | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: index
void* __fastcall FUN_00d87310(void* self, int, int index)
{
    return (char*)*(void**)self + index * 3 * 16;
}

// @fnv 0x00d87350
// pdb: hkClassMemberAccessor::asHomogeneousArray | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: hkClassMemberAccessor::asSimpleArray)
// pdb params: index
int __fastcall FUN_00d87350(int* self, int, int idx)
{
    int base = *self;
    return base + idx * 12;
}

struct IntArrayView
{
    int* data;
    int* FUN_00d87270(int index);
};
// @fnv 0x00d87270
// pdb: hkClassMemberAccessor::asStringPtr | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: index
int* IntArrayView::FUN_00d87270(int index)
{
    return data + index;
}

struct FUN_00d87280_class
{
    int* m_p;
    int* __thiscall FUN_00d87280(int index);
};

// @fnv 0x00d87280
// pdb: hkClassMemberAccessor::asReal | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: index
int* __thiscall FUN_00d87280_class::FUN_00d87280(int index)
{
    return m_p + index;
}

struct CpuObject
{
    int value;
    int FUN_00d872e0(int amount);
};
// @fnv 0x00d872e0
// pdb: hkClassMemberAccessor::asInt8 | hkClassMemberAccessor.obj | tesv_win, objrun_sim, low
int CpuObject::FUN_00d872e0(int amount)
{
    return value + amount;
}

struct Pair
{
    int first;
    int second;
    Pair& FUN_00d873d0(const Pair& other);
};

// @fnv 0x00d873d0
// pdb: TESRegionPoint::TESRegionPoint | TESRegionPoint.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: AStarNode<struct BSPathSmootherPOVNode,struct BSPathSmootherPOVLink>::QHeuristic)
// pdb params: aNP2
Pair& Pair::FUN_00d873d0(const Pair& other)
{
    first = other.first;
    second = other.second;
    return *this;
}

struct D871A0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct D871A0Buffer
{
    void append(const void* data, int size, int flags);
    D871A0Buffer& FUN_00d871a0(const D871A0Array& a, int flags);
};

// Appends the array's data buffer with its size and flags to this buffer, then returns this buffer.
// @fnv 0x00d871a0
// pdb: hkClassMemberAccessor::hkClassMemberAccessor | hkClassMemberAccessor.obj | fnv360_0822_debug, call_gap, low
// pdb params: var, memberName
D871A0Buffer& D871A0Buffer::FUN_00d871a0(const D871A0Array& apArray, int flags)
{
    append(apArray.m_data, apArray.m_iElementCount, flags);
    return *this;
}

struct TargetClass
{
    void* ptr;
    bool* __thiscall FUN_00d871e0(bool* out);
};

// @fnv 0x00d871e0
bool* __thiscall TargetClass::FUN_00d871e0(bool* out)
{
    *out = (this->ptr != 0);
    return out;
}

struct D87240Array
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    char& FUN_00d87240(int i);
};

// @fnv 0x00d87240
// pdb: hkClassMemberAccessor::asCstring | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: index
char& D87240Array::FUN_00d87240(int i)
{
    return m_data[i];
}

struct D87250Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int& FUN_00d87250(int i);
};

// @fnv 0x00d87250
int& D87250Array::FUN_00d87250(int i)
{
    return m_data[i];
}

struct FUN_00d872f0_class
{
    int m_uiFilterValue;
    int __thiscall FUN_00d872f0(int offset);
};

// @fnv 0x00d872f0
// pdb: hkClassMemberAccessor::asUint8 | hkClassMemberAccessor.obj | tesv_win, objrun, medium
int __thiscall FUN_00d872f0_class::FUN_00d872f0(int offset)
{
    return m_uiFilterValue + offset;
}

struct SearchObject
{
    unsigned int field00;
    int FUN_00d87320(unsigned int arg0);
};
// @fnv 0x00d87320
int SearchObject::FUN_00d87320(unsigned int arg0)
{
    return (int)((arg0 << (6u & 31u)) + field00);
}

struct FUN_00d87330_class
{
    char* m_p;
    char* FUN_00d87330(int index);
};

// @fnv 0x00d87330
// pdb: hkClassMemberAccessor::asRotation | hkClassMemberAccessor.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: index
char* FUN_00d87330_class::FUN_00d87330(int index)
{
    return m_p + index * 0x30;
}

struct FnvCpu_FUN_00d871f0_CpuObject
{
    int value;
    int FUN_00d871f0();
};
// @fnv 0x00d871f0
// pdb: hkClassMemberAccessor::getAddress | hkClassMemberAccessor.obj | tesv_win, objrun, medium
int FnvCpu_FUN_00d871f0_CpuObject::FUN_00d871f0()
{
    return value;
}

struct FUN_00d87200_cls
{
    void* m_data;
    void* FUN_00d87200();
};

// @fnv 0x00d87200
// pdb: keyFromPair | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkThread::getHandle)
void* FUN_00d87200_cls::FUN_00d87200()
{
    return m_data;
}

struct D87370Obj
{
    void* unk00;
    int unk04;
    int __thiscall FUN_00d87370();
};

// @fnv 0x00d87370
// pdb: hkClass::getParent | hkClass.obj | fnv360_0822_retail, call_gap, high
int __thiscall D87370Obj::FUN_00d87370()
{
    return unk04;
}

struct StringMemberAccessor
{
    int* values;
    int* FUN_00d87230(int index);
};

// @fnv 0x00d87230
int* StringMemberAccessor::FUN_00d87230(int index)
{
    return values + index;
}

// @f3twin 0x0093d7f0 of 0x004a2280
struct F3Twin_0093d7f0 : public Pair { Pair& F3_FUN_0093d7f0(const Pair& other) ; };
// pdb: hkClassAccessor::hkClassAccessor | hkClassMemberAccessor.obj | tesv_win, objrun, medium
Pair& F3Twin_0093d7f0::F3_FUN_0093d7f0(const Pair& other) 
{
    first = other.first;
    second = other.second;
    return *this;
}
