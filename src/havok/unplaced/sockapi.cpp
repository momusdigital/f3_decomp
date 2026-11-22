#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cc05f0Target
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void Invoke(const char* value, int mode);
};
struct RequestReceiver
{
    int unk00;
    int unk04;
    FUN_00cc05f0Target* unk08;
    RequestReceiver* GridCellArray_MoveItem(void* request);
    void GridCellArray_MoveItem(unsigned int sourceRow, unsigned int sourceColumn, unsigned int destinationRow, unsigned int destinationColumn);
};
// @f3 0x0047b400 (community match, verified in this file)
namespace rr_0047b400 {
struct Grid
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void ResetCell(unsigned int row, unsigned int column);

    int unk04;
    void* unk08;
    unsigned int dimension;
    int* cells;

};
}

// pdb: GridCellArray::MoveItem | GridCell.obj | fnv360_0822_retail, vtable, high
// pdb params: aiX1, aiY1, aiX2, aiY2
// pdb: GridCellArray::MoveItem | GridCell.obj | fnv360_0822_retail, vtable, high (was: InvokeFromRequest)
void RequestReceiver::GridCellArray_MoveItem(unsigned int sourceRow, unsigned int sourceColumn,
                                        unsigned int destinationRow, unsigned int destinationColumn)
{
    rr_0047b400::Grid* self = (rr_0047b400::Grid*)this;
    const unsigned int width = self->dimension;
    const int* source;
    if (sourceRow < width && sourceColumn < width)
        source = &self->cells[width * sourceRow + sourceColumn];
    else
        source = 0;

    if (destinationRow < width && destinationColumn < width)
    {
        if (source)
            self->cells[destinationRow * width + destinationColumn] = *source;
        else
            self->ResetCell(destinationRow, destinationColumn);
    }
}


static unsigned char* volatile g_out_slot;
static unsigned int volatile g_val_slot;
// @fnv 0x00da2eb0
// pdb: hkIsDigit | hkBsdSocket.obj | fnv360_0822_debug, objrun, low, conflict (bridge: connect)
static __declspec(noinline) unsigned char* FUN_00da2eb0(unsigned char* out, unsigned int c)
{
    *out = c >= 0x30u && c <= 0x39u;
    return out;
}
void da2eb0_probe_caller()
{
    FUN_00da2eb0(g_out_slot, g_val_slot);
}
