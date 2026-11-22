#include <windows.h>
#include <new>
// src/f3staging/f3iso_008d8150_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x008d8150 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008d8150 (community match, verified in this file)
struct S8d8150_FreeList
{
    void* m_head;
    int m_numElem;
    __forceinline void put(void* p) throw()
    {
        m_numElem++;
        *(void**)p = m_head;
        m_head = p;
    }
};
struct S8d8150_ThreadMemory
{
    virtual void v00();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int m_maxNumElemsOnFreeList;
    S8d8150_FreeList m_free_list[17];
    void FUN_008f6890(int row, void* p, int memClass) throw();
    void FUN_008f6d90(void* p, int nbytes, int memClass);
    static S8d8150_ThreadMemory& getInstance() throw();
    __forceinline void deallocateChunk(void* p, int row) throw()
    {
        if (m_free_list[row].m_numElem >= m_maxNumElemsOnFreeList)
            FUN_008f6890(row, p, 0xd);
        else
            m_free_list[row].put(p);
    }
};
template <class T> struct S8d8150_Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline int getCapacity() const throw()
    {
        return m_capacityAndFlags & 0x3fffffff;
    }
    ~S8d8150_Array();
};
struct S8d8150_Obj
{
    virtual ~S8d8150_Obj();
};
struct S8d8150_Shape
{
    void FUN_00942310() throw();
};
struct S8d8150_Pair
{
    int a;
    int b;
};
struct S8d8150_Cont
{
    int unk00;
    ~S8d8150_Cont();
    void FUN_005e3010();
};
struct S8d8150_Mgr
{
    void FUN_0086ba60(int p);
};
struct S8d8150_Base
{
    int unk04;
    int unk08;
    int unk0c;
    virtual ~S8d8150_Base();
    void FUN_008f7ef0();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
};
struct FUN_008d8150 : S8d8150_Base
{
    S8d8150_Shape* unk10;
    void* unk14;
    S8d8150_Obj* unk18;
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
    S8d8150_Array<S8d8150_Obj*> unk70;
    S8d8150_Array<S8d8150_Pair> unk7c;
    int unk88;
    int unk8c;
    S8d8150_Cont unk90;
    virtual ~FUN_008d8150();
};

__forceinline S8d8150_ThreadMemory& S8d8150_ThreadMemory::getInstance() throw()
{
    extern unsigned long DAT_010f3170;
    return *static_cast<S8d8150_ThreadMemory*>(::TlsGetValue(DAT_010f3170));
}
template <class T> __forceinline S8d8150_Array<T>::~S8d8150_Array()
{
    if ((m_capacityAndFlags & 0x80000000) == 0)
    {
        S8d8150_ThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
    }
}

// pdb: bhkWorld::~bhkWorld | bhkWorld.obj | fnv360_0822_retail, udata, high
FUN_008d8150::~FUN_008d8150()
{
    extern int DAT_010f2a64;
    extern S8d8150_Mgr DAT_01090a78;
    S8d8150_Base* base = this;
    --DAT_010f2a64;
    base->vfn_98();
    if (unk18)
        delete unk18;
    base->vfn_98();
    unk18 = 0;
    S8d8150_Shape* shape = unk10;
    if (shape)
    {
        shape->FUN_00942310();
        S8d8150_ThreadMemory::getInstance().deallocateChunk(shape, 0xc);
        unk10 = 0;
    }
    void* block = unk14;
    if (block)
    {
        S8d8150_ThreadMemory::getInstance().deallocateChunk(block, 3);
        unk14 = 0;
    }
    base->vfn_98();
    FUN_008f7ef0();
    base->vfn_98();
    {
        int id = unk34;
        DAT_01090a78.FUN_0086ba60(id);
    }
    {
        int id = unk3c;
        DAT_01090a78.FUN_0086ba60(id);
    }
    {
        int id = unk44;
        DAT_01090a78.FUN_0086ba60(id);
    }
    {
        int id = unk4c;
        DAT_01090a78.FUN_0086ba60(id);
    }
    {
        int id = unk54;
        DAT_01090a78.FUN_0086ba60(id);
    }
    for (int i = 0; i < unk70.m_size; i++)
    {
        S8d8150_Obj* item = unk70.m_data[i];
        if (item)
            delete item;
    }
    unk70.m_size = 0;
    unk90.FUN_005e3010();
}
