// gamebryo2.2/corelibs/nianimation/niinterpcontroller.cpp: NiInterpController, NiInterpControllerTriple, NiInterpControllerFlagCheck, BaseWrap (5 functions)
#include "f3_common.h"
#include "niinterpcontroller_decls.h"
// @fnv 0x00a2f910
// pdb: NiInterpController::LoadBinary | NiInterpController.obj | fnv360_0822_retail, call_gap, low
// pdb params: kStream
void NiInterpController::LoadBinary(NiStream& stream)
{
    NiTimeController::LoadBinary(stream);
    if (stream.version >= 0x0a010068 && stream.version < 0x0a01006d)
    {
        bool value;
        stream.input->Read(&value, 1);
        if (value)
            flags |= 0x20;
        else
            flags &= ~0x20;
    }
}
// @fnv 0x00c9a6b0
// @f3 0x00914ad0 (community match, verified in this file)
extern const double DAT_00dba730;
void NiInterpControllerTriple::ResetTriple() {
    f0 = -1.0f;
    float value = (float)(0.0 / DAT_00dba730);
    f1 = f2 = value;
}


class NiInterpControllerFlagCheck : public NiInterpController
{
  public:
    void ResetIfFlagClear();
};

// @fnv 0x00a2f8f0
// pdb: NiInterpController::ResetTimeExtrema | NiInterpController.obj | fnv360_0822_retail, objrun_prop, medium
void NiInterpControllerFlagCheck::ResetIfFlagClear()
{
    unsigned char value = *(unsigned char*)((char*)this + 8);
    for (int i = 0; i < 5; ++i)
        value = (unsigned char)(value >> 1);
    if (!(value & 1))
    {
        *(float*)((char*)this + 0x14) = 0.0f;
        *(float*)((char*)this + 0x18) = 0.0f;
    }
}

struct StrArr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char**);
};
struct BaseCall
{
    unsigned int unk00;
    unsigned int unk04;
    void FUN_00a6d830(StrArr*);
};
extern const char* g_011f36bc_arg1;
extern char* __cdecl FUN_00a7d330(const char*);
extern "C" char* __cdecl FUN_00a7d370(const char*, int);
struct BaseWrap : BaseCall
{
    unsigned char flags;
    void WriteManagerControlledFlag(StrArr*);
};
// Calls the base writer, then appends a string and an "IsManagerControlled" entry derived from bit 5 of flags to the stream.
// @fnv 0x00a2f980
// pdb: NiInterpController::GetViewerStrings | NiInterpController.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void BaseWrap::WriteManagerControlledFlag(StrArr* stream)
{
    FUN_00a6d830(stream);
    char* value = FUN_00a7d330(g_011f36bc_arg1);
    unsigned int index = stream->unk0a;
    if (index >= stream->unk08)
    {
        stream->SetSize(stream->unk0e + index);
    }
    stream->SetAt(index, &value);
    *(unsigned char*)&value = (flags >> 5) & 1;
    value = FUN_00a7d370("IsManagerControlled", *(int*)&value);
    index = stream->unk0a;
    if (index >= stream->unk08)
    {
        stream->SetSize(stream->unk0e + index);
    }
    stream->SetAt(index, &value);
}
