#include <new>
// src/f3staging/f3iso_00962850_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00962850 alone: its served file builds the neighbouring 0x00962880 wrong.
// Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00962850 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00962850 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long slot);

namespace RagdollMemory {
enum MemoryClass { Animation = 14 };

class hkThreadMemory {
public:
    void FUN_008f6d90(void* storage, int bytes, MemoryClass category);
};

class hkBaseObject {
public:
    virtual ~hkBaseObject();
};

class hkReferencedObject : public hkBaseObject {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

class hkaRagdollInstance : public hkReferencedObject {
public:
    virtual ~hkaRagdollInstance();
    static void operator delete(void* storage);
    void* FUN_00962850(unsigned int flags);
};

inline void hkaRagdollInstance::operator delete(void* storage)
{
    hkReferencedObject* object = static_cast<hkaRagdollInstance*>(storage);
    hkThreadMemory* memory = static_cast<hkThreadMemory*>(TlsGetValue(DAT_010f3170));
    memory->FUN_008f6d90(storage, object->m_memSizeAndFlags, Animation);
}

// pdb: hkaRagdollInstance::`scalar deleting destructor' | hkaRagdollInstance.obj | fnv360_0822_retail, vtable, high
void* hkaRagdollInstance::FUN_00962850(unsigned int flags)
{
    hkaRagdollInstance::~hkaRagdollInstance();
    if (flags & 1)
        hkaRagdollInstance::operator delete(this);
    return this;
}
}
}   // namespace f3m_00962850
