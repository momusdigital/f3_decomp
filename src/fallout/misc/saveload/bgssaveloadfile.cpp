// fallout/misc/saveload/bgssaveloadfile.cpp: BGSSaveLoadFileEntry, SaveLoadFile, BGSSaveLoadManager (2 functions)
#include "f3_common.h"
#include "bgssaveloadfile_types_BGSSaveLoadFile.h"
#include "bgssaveloadfile_types_BGSSaveLoadFileEntry.h"
#include "bgssaveloadfile_types_BGSSaveLoadManager.h"
#include "bgssaveloadfile_types_BGSSaveLoadHeader.h"
#include "bgssaveloadfile_types_NiTexture.h"
#include "MemoryManager.h"

class BSFile
{
  public:
    char opaque[0x158];
    BSFile(const char*, int, unsigned int, bool);
    unsigned int Read(void*, unsigned int);
    unsigned int GetFilePosition();
};

extern BGSSaveLoadManager* DAT_011de134;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
template <class T> unsigned int __cdecl BSStringLength(const T*);

// @fnv 0x008461e0
SaveLoadFile::SaveLoadFile(const char* fileName, bool flag, unsigned int size)
{
    pFile = 0;
    m_uiBufferSize = 0;
    m_uiFilePosition = 0;
    m_cFileName[0] = 0;
    if (!DAT_011de134->FUN_00424940())
        pFile = new BSFile(fileName, flag ? 1 : 0, size, false);
}

struct FUN_008464f0_arg
{
    const char* str;
    int unk04;
};

// @f3 0x007ab550 (community match, verified in this file)
struct FUN_008464f0_mem
{
    int FUN_00799390(char* owner, const char* str, int unk04);
    void FUN_007993c0(int value);
};
struct FUN_008464f0_obj
{
    int unk00;
    FUN_008464f0_mem* unk04;
};
// pdb: CombatProcedure::SetLookAtTarget | CombatProcedure.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSTArray<class ExtraAttachedArrows3D::DataItem,class BSTArrayHeapAllocator>::~BSTArray<class ExtraAttachedArrows3D::DataItem,class BSTArrayHeapAllocator>)
// pdb params: arLookAtPoint, acPriority
void __fastcall FUN_008464f0(char* pThis, FUN_008464f0_arg aStringArg)
{
    FUN_008464f0_obj* self = (FUN_008464f0_obj*)pThis;
    int r = self->unk04->FUN_00799390(pThis, aStringArg.str, aStringArg.unk04);
    self->unk04->FUN_007993c0(r);
}


struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    bool LoadGame(const char*, int, bool, bool);
};

namespace fnv_00846a20 {
struct _FILETIME_
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};

struct _WIN32_FIND_DATAA_
{
    unsigned int dwFileAttributes;
    _FILETIME_ ftCreationTime;
    _FILETIME_ ftLastAccessTime;
    _FILETIME_ ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

__declspec(dllimport) void* __stdcall FindFirstFileA(const char*, _WIN32_FIND_DATAA_*);
__declspec(dllimport) int __stdcall FindClose(void*);

struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    void GetFullPath(char*, char*, bool);
};

}  // namespace fnv_00846a20

namespace fnv_00846ad0 {
struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    bool IsQuickSaveFileName(const char*);
};

}  // namespace fnv_00846ad0

namespace fnv_00846af0 {
struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    bool IsSaveFileNameLegacyAutosave(const char*);
};

}  // namespace fnv_00846af0

class C8467E0Event;

class C8467E0Event
{
  public:
    unsigned int m_uiType;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int m_iData;

    void DispatchEvent();
};

__declspec(dllimport) int __stdcall DeleteFileA(const char*);
