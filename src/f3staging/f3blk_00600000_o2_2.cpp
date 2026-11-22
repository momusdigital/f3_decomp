// src/f3staging/f3blk_00600000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0061efa0 (community match, verified in this file)
namespace f3m_0061efa0 {
// pdb: InterfaceManager::ConvertButton | InterfaceManager.obj | fnv360_0822_debug, objrun, low
// pdb params: aeButton
int __cdecl FUN_0061efa0(int value) {
    switch(value) {
    case 9: return 10;
    case 10: return 11;
    case 11: return 12;
    case 12: return 13;
    case 6: return 7;
    case 5: return 6;
    case 15: return 15;
    case 16: return 14;
    case 1: return 1;
    case 2: return 2;
    case 4: return 5;
    case 3: return 4;
    case 13: return 16;
    case 14: return 17;
    case 17: return 8;
    case 18: return 9;
    default: return -1;
    }
}
}   // namespace f3m_0061efa0

// @f3 0x0061b990 (community match, verified in this file)
namespace f3m_0061b990 {
namespace Construct61b9 {extern void* DAT_00e0356c;struct Object{void* table;int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int value;void FUN_006999e0();Object();};Object::Object(){FUN_006999e0();table=&DAT_00e0356c;value=0;}}
}   // namespace f3m_0061b990

// @f3 0x0060b790 (community match, verified in this file)
namespace f3m_0060b790 {
struct ArrOps60B790 { void FUN_00cb9930(unsigned* destination, unsigned* source, unsigned count); };
struct Arr60B790 {
    virtual void Slot0();
    virtual void** Allocate(unsigned count);
    virtual void Free(void** data);
    void** data;
    unsigned size;
    unsigned capacity;
    unsigned FUN_005e5350();
    void FUN_0060b790(unsigned index, void** item);
};
// pdb: BSSimpleArray<MessageMenu::MessageMenuEntry *,1024>::Insert | MessageMenu.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: aiIndex, aValue
void Arr60B790::FUN_0060b790(unsigned index, void** item) {
    if (index == size) {
        unsigned slot = FUN_005e5350();
        void** destination = data;
        void* value = *item;
        destination[slot] = value;
        return;
    }
    if (size == capacity) {
        unsigned nextCapacity = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
        void** nextData = Allocate(nextCapacity);
        ((ArrOps60B790*)this)->FUN_00cb9930((unsigned*)nextData, (unsigned*)data, index);
        unsigned offset = index * 4;
        ((ArrOps60B790*)this)->FUN_00cb9930((unsigned*)((char*)nextData + offset + 4), (unsigned*)((char*)data + offset), size - index);
        Free(data);
        data = nextData;
        capacity = nextCapacity;
    } else {
        unsigned offset = index * 4;
        ((ArrOps60B790*)this)->FUN_00cb9930((unsigned*)((char*)data + offset + 4), (unsigned*)((char*)data + offset), size - index);
    }
    ++size;
    data[index] = *item;
}
}   // namespace f3m_0060b790

// @f3 0x00616350 (community match, verified in this file)
namespace f3m_00616350 {
namespace quadrant {
struct Point {
    float x, y;
    Point() { y = 0.0f; x = 0.0f; }
    Point(float xValue, float yValue) : x(xValue), y(yValue) {}
    Point(const volatile Point& other) : x(other.x), y(other.y) {}
};
struct Owner {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054;
    unsigned mode;
    Point* FUN_00616350(Point* out);
};
// pdb: BGSTerrainNode::GetOffsetFromParent | BGSTerrainNode.obj | fnv360_0822_retail, call_seq, medium
Point* Owner::FUN_00616350(Point* out)
{
    volatile float v, w;
    switch (mode) {
    case 1: { v = 0.5f; w = 0.0f; out->x = v; out->y = w; return out; }
    case 3: { v = 0.5f; w = 0.5f; out->x = v; out->y = w; return out; }
    case 2: { v = 0.0f; w = 0.0f; out->x = v; out->y = w; return out; }
    case 4: { v = 0.0f; w = 0.5f; out->x = v; out->y = w; return out; }
    default: { w = 0.0f; v = 0.0f; out->x = v; out->y = w; return out; }
    }
}
}
}   // namespace f3m_00616350
