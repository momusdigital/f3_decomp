#include "f3_common.h"
// src/havok/common/base/memory/allocator/solver/hksolverallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/solver/hksolverallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);

struct FUN_00c66560_class
{
    void* m_pVftable;

    __declspec(noinline) void FUN_00cbf1a0();
};

struct FUN_00cd06a0_class : public FUN_00c66560_class
{
    unsigned char m_aPadding[0x120];
    unsigned char m_CriticalSection[24];

    void ResetVftableAndDeleteCriticalSection();
};

// @f3 0x0086da50 (community match, verified in this file)
extern int DAT_00e2804c;
extern int DAT_00e27f54;
// pdb: AbstractHeap::~AbstractHeap | AbstractHeap.obj | tesv_win, objrun_sim, low
void FUN_00cd06a0_class::ResetVftableAndDeleteCriticalSection()
{
    m_pVftable = &DAT_00e2804c;
    DeleteCriticalSection(reinterpret_cast<char*>(this) + 0x20D8);
    m_pVftable = &DAT_00e27f54;
}


// @fnv 0x00d5e880
// pdb: hkpSimpleContactConstraintData::getSolverResults | hkpSimpleContactConstraintData.obj | tesv_win, objrun_open, low
int __stdcall FUN_00d5e880(int arg0)
{
    return 0;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

struct hkCriticalSectionD5E9
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct hkStreamD5E9
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cur;
    int m_10;

    void init(char* p, int size)
    {
        m_kRayStart = p;
        m_cur = p;
        m_kRayEnd = p + size;
        m_10 = 0;
    }
};

namespace fnv_00d5e9b0 {
extern void(__stdcall* DAT_00fdf05c)(void* pvSection);
extern void(__stdcall* DAT_00fdf100)(void* pvSection);

class hkCriticalSectionD5E9
{
  public:
    int m_kCriticalSection[6];
    void enter()
    {
        DAT_00fdf05c(&m_kCriticalSection);
    }
    void leave()
    {
        DAT_00fdf100(&m_kCriticalSection);
    }
};

class hkCriticalSectionLockD5E9
{
  public:
    hkCriticalSectionD5E9* m_kCriticalSection;
    hkCriticalSectionLockD5E9(hkCriticalSectionD5E9* pkSection) : m_kCriticalSection(pkSection)
    {
        m_kCriticalSection->enter();
    }
    ~hkCriticalSectionLockD5E9()
    {
        m_kCriticalSection->leave();
    }
};

struct hkFreeBlockD5E9
{
    char* m_kRayStart;
    int m_iElementCount;
};

inline void memMoveD5E9(void* pvDst, const void* pvSrc, int iNumBytes)
{
    for (int i = 0; i < iNumBytes; i += 4)
        *(int*)((char*)pvDst + i) = *(const int*)((const char*)pvSrc + i);
}

template <typename T> struct hkArrayD5E9
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAtAndCopy(int iIndex)
    {
        m_iElementCount--;
        memMoveD5E9(m_data + iIndex, m_data + iIndex + 1, (m_iElementCount - iIndex) * sizeof(T));
    }
};

class hkBlockAllocatorD5E9
{
  public:
    void* m_ppVirtualMethodTable;
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cur;
    int m_iCurrentUsage;
    unsigned int m_peakUsage;
    hkArrayD5E9<hkFreeBlockD5E9> m_pFreeBlocks;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    hkCriticalSectionD5E9 m_pWorldLock;

    void updateStats()
    {
        m_iCurrentUsage++;
        unsigned int uiUsed = m_cur - m_kRayStart;
        if (uiUsed > m_peakUsage)
            m_peakUsage = uiUsed;
    }

    char* Allocate(int* piSizeInOut) throw();
};

}  // namespace fnv_00d5e9b0

inline void* operator new(unsigned int, void* ptr)
{
    return ptr;
}

template <typename T> struct hkArrayD5E9
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T, int N> struct hkInplaceArrayD5E9 : public hkArrayD5E9<T>
{
    T m_kStorage[N];
    hkInplaceArrayD5E9()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct S00d5eb10_Block
{
    void* p;
    int size;
    S00d5eb10_Block()
    {}
    S00d5eb10_Block(void* p_, int s_) : p(p_), size(s_)
    {}
};

struct S00d5eb10_BlockArray
{
    S00d5eb10_Block* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S00d5eb10_Block m_kStorage[32];

    S00d5eb10_Block& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }

    __forceinline void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        int count = m_iElementCount - index;
        int numBytes = count * sizeof(S00d5eb10_Block);
        S00d5eb10_Block* d = &m_data[index];
        S00d5eb10_Block* s = d + 1;
        for (int j = 0; j < numBytes; j += 4)
        {
            *(int*)((char*)d + j) = *(const int*)((const char*)s + j);
        }
    }

    void FUN_00d5eda0(int unk0, int index, const S00d5eb10_Block* item);
    void aiRecipeIndex(int index, const S00d5eb10_Block& b)
    {
        FUN_00d5eda0(0, index, &b);
    }
};
