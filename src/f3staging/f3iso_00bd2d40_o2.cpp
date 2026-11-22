#include <new>
// src/f3staging/f3iso_00bd2d40_o2.cpp - Fallout 3 ISOLATED unit (19 Nov 2026) for 0x00bd2d40 alone: its original passes arguments in registers to
// a static helper of its own file, which only works without other code (16-byte-aligned locals) in the unit. Write the helper
// static in your candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bd2d40 (community match, verified in this file)
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class NiAVObject
{
public:
    void IncRefCount();
    void DecRefCount();
};

extern "C" const NiPoint3 FNV_NiPoint3Zero;

class BSAudioManager
{
public:
    typedef void (__cdecl *SoundCallback)(void*);
    bool SetCompletionCallback(unsigned int soundHandle, SoundCallback callback, void* userData);
    void FUN_00bd24f0(unsigned int command, unsigned int soundHandle, void* userData,
                      SoundCallback callback, NiPointer<NiAVObject> object, NiPoint3 position);
};

// pdb: BSAudioManager::SetCompletionCallback | BSAudioManager.obj | fnv360_1110_retail, call_seq + bridge(call_gap|call_gap), high
bool BSAudioManager::SetCompletionCallback(unsigned int soundHandle, SoundCallback callback, void* userData)
{
    FUN_00bd24f0(0x3a, soundHandle, userData, callback, static_cast<NiAVObject*>(0), FNV_NiPoint3Zero);
    return true;
}
