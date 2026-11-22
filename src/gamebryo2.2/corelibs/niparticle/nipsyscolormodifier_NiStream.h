// Authored declaration for the Nif particle stream helper closure.
#ifndef FNV_NISTREAM_LOCAL_H
#define FNV_NISTREAM_LOCAL_H
#include "f3_common.h"
#include "NiObject.h"

#pragma pack(push, 4)
class NiStream : public NiObject
{
  public:
    void ResetStreamState();
    unsigned int ReadUnsignedInteger();
    unsigned int GetLinkIDFromObject(const NiObject* pkObject);
    NiObject* DeserializeObject();
    NiObject* GetLoadedObject(unsigned int uiLinkID);
};
#pragma pack(pop)
#endif
