#include <windows.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_006c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d4190 (community match, verified in this file)
extern const char DAT_00e0f130[],DAT_00e0f100[],DAT_00e08284[];
namespace f3m_006d4190 {


struct Info497 {DWORD userSize;SYSTEMTIME time;char dateTime[260];char user[260];};
int __cdecl FUN_00403230(char*,unsigned int,const char*,...);
// pdb: BGSSaveLoadManager::GetVersionInfo | BGSSaveLoadManager.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __stdcall BGSSaveLoadManager_GetVersionInfo(char* output,unsigned int capacity) {
    Info497 info;
    info.user[0]=0;memset(info.user+1,0,259);
    info.dateTime[0]=0;memset(info.dateTime+1,0,259);
    info.userSize=260;
    GetUserNameA(info.user,&info.userSize);
    GetLocalTime(&info.time);
    FUN_00403230(info.dateTime,260,DAT_00e0f130,info.time.wMonth,info.time.wDay,info.time.wYear,info.time.wHour,info.time.wMinute,info.time.wSecond);
    FUN_00403230(output,capacity,DAT_00e0f100,info.user,info.dateTime,DAT_00e08284,48,21);
}
}   // namespace f3m_006d4190

// @f3 0x006deb90 (community match, verified in this file)
namespace f3m_006deb90 {




struct HeapStandIn6deb90 {
    void* Allocate(unsigned int auiSize);
    void Free(void* apMem);
};
extern HeapStandIn6deb90 DAT_01090a78;

class BSFile {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Open(int a, int b);

    BSFile(const char* apPath, int aeMode, int aiBufferSize, int abTextMode);
    static void* operator new(unsigned int auiSize) { return DAT_01090a78.Allocate(auiSize); }
    static void operator delete(void* apMem) { DAT_01090a78.Free(apMem); }

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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    char m_path[0x104];
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
};

struct FileSystemStandIn6deb90 {
    int FUN_00bc7d50(const char* apPath, int a, int b, int c);
};
extern FileSystemStandIn6deb90* DAT_011785d0;
extern char DAT_0116d880[];
extern char* DAT_0106ce10;
extern "C" int __cdecl FUN_00c02aeb(const char* apOld, const char* apNew);

struct SaveLoadStandIn6deb90 {
    void FUN_006de180(char* apName);
    void FUN_006dcd70(BSFile* apFile, int a);
    BSFile* FUN_006deb90(BSFile* apFile, const char* apName, int aeMode);
};

// pdb: TESSaveLoadGame::PrepForLoadSave | TESSaveLoadGame.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apFile, asFileName, aeAction
BSFile* SaveLoadStandIn6deb90::FUN_006deb90(BSFile* apFile, const char* apName, int aeMode)
{
    char tmpPath[0x104];
    char baseName[0x104];
    char bakPath[0x104];
    char savePath[0x104];
    char name[0x104];
    char dirPath[0x104];

    if (apFile) {
        strcpy_s(savePath, 0x104, apFile->m_path);
    } else {
        if (!apName) FUN_006de180(name);
        else strcpy_s(name, 0x104, apName);
        sprintf_s(savePath, 0x104, "%s%s%s.ess", DAT_0116d880, DAT_0106ce10, name);
        if (aeMode == 0) {
            strcpy_s(dirPath, 0x104, DAT_0116d880);
            strcat_s(dirPath, 0x104, DAT_0106ce10);
            CreateDirectoryA(dirPath, 0);
            for (int i = 0; i >= 0; i--) {
                strcpy_s(tmpPath, 0x104, DAT_0116d880);
                strcat_s(tmpPath, 0x104, DAT_0106ce10);
                strcat_s(tmpPath, 0x104, name);
                for (int j = 0; j < i; j++)
                    strcat_s(tmpPath, 0x104, ".bak");
                strcpy_s(bakPath, 0x104, tmpPath);
                strcat_s(bakPath, 0x104, ".bak");
                if (i == 0)
                    strcpy_s(tmpPath, 0x104, savePath);
                if (DAT_011785d0 && DAT_011785d0->FUN_00bc7d50(tmpPath, 0, 0, -1)) {
                    if (DAT_011785d0 && DAT_011785d0->FUN_00bc7d50(bakPath, 0, 0, -1))
                        DeleteFileA(bakPath);
                    FUN_00c02aeb(tmpPath, bakPath);
                }
            }
        }
    }

    switch (aeMode) {
    case 0:
        if (apFile) {
            strcpy_s(baseName, 0x104, strrchr(apFile->m_path, '\\') + 1);
            unsigned int len = strlen(baseName);
            if (len > 4) {
                char* ext = baseName + len - 4;
                if (_strnicmp(ext, ".ess", 4) == 0) *ext = 0;
            }
            FUN_006dcd70(apFile, 0);
            if (_strnicmp(baseName, "Save ", 5) != 0 && strstr(baseName, "autosave") == 0)
                return FUN_006deb90(0, baseName, 0);
            return FUN_006deb90(0, 0, 0);
        }
        return new BSFile(savePath, 1, 0x20000, 0);
    case 1: {
        BSFile* file = new BSFile(savePath, 0, 0x20000, 0);
        file->Open(0, 0);
        return file;
    }
    case 2:
        apFile->Open(0, 0);
    case 3:
        return apFile;
    }
    return apFile;
}
}   // namespace f3m_006deb90

// @f3 0x006d4840 (community match, verified in this file)
#include <windows.h>
namespace f3m_006d4840 {
namespace SaveLoad0372 {
struct SaveLoadFile {
    void FUN_006cda70(char* filename);
    void FUN_006cd9a0();
};
int __cdecl FUN_00c05a0f(const char* filename, int mode);
SaveLoadFile* __cdecl FUN_006cda90(char* filename, bool write, unsigned int bufferSize);
struct SaveLoadManager {
    void FUN_006d47a0(char* filename, char* fullPath, bool write);
    SaveLoadFile* FUN_006d4840(char* filename, bool write, int bufferType, int deviceID);
};
// pdb: BGSSaveLoadManager::OpenSaveFile | BGSSaveLoadManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apFileName, abWrite, aeBufferType, aiDeviceID
SaveLoadFile* SaveLoadManager::FUN_006d4840(char* filename, bool write, int bufferType, int deviceID)
{
    unsigned int bufferSize;
    SaveLoadFile* file;
    char fullPath[260];
    FUN_006d47a0(filename, fullPath, write);
    if (bufferType == 0)
        bufferSize = 0x10000;
    else if (bufferType == 1)
        bufferSize = 0x200000;
    else
        bufferSize = 0x10000;
    if (write) {
        if (FUN_00c05a0f(fullPath, 0) != -1)
            DeleteFileA(fullPath);
    }
    file = FUN_006cda90(fullPath, write, bufferSize);
    file->FUN_006cda70(filename);
    file->FUN_006cd9a0();
    return file;
}
}
}   // namespace f3m_006d4840

// @f3 0x006d51a0 (community match, verified in this file)
#include <windows.h>
#include <string.h>
namespace f3m_006d51a0 {
struct FUN_006d51a0_Owner {
    void FUN_006d46e0(char*);
    bool FUN_006d51a0();
};
// pdb: StartMenu::InitializeUserOptions | StartMenu.obj | fnv360_0721_retail, call_gap, low
bool FUN_006d51a0_Owner::FUN_006d51a0()
{
    char path[260];
    WIN32_FIND_DATAA data;
    FUN_006d46e0(path);
    strcat_s(path, 260, "*");
    strcat_s(path, 260, ".fos");
    HANDLE h = FindFirstFileA(path, &data);
    FindClose(h);
    return (char)(h != INVALID_HANDLE_VALUE);
}
}   // namespace f3m_006d51a0

// @f3 0x006d5bf0 (community match, verified in this file)
namespace f3m_006d5bf0 {

namespace f3m_6d5bf0 {
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
extern const char DAT_00dc0ad4[];
extern const char DAT_00e0828c[];
struct Item {
    int unk00, unk04;
    unsigned int unk08;
    void FUN_006cdc90();
    bool FUN_006cddc0();
    bool FUN_006cddd0();
};
struct List {
    Item* head;
    int unk04;
    List() { head = 0; unk04 = 0; }
    static void* operator new(unsigned int size) throw() { return DAT_01090a78.FUN_0086b930(size); }
};
struct Mgr {
    List* list;
    int unk04;
    unsigned int count;
    void FUN_006d4e80();
    void FUN_006d5980();
    void FUN_006d46e0(char* path);
    void FUN_006d5a40(char* name, int a, int b);
    void FUN_006d5bf0();
};
// pdb: BGSSaveLoadManager::IsSaveFileNameCustom | BGSSaveLoadManager.obj | fnv360_0822_debug, objrun, low
// pdb params: apSaveFileName
void Mgr::FUN_006d5bf0()
{
    WIN32_FIND_DATAA fd;
    char path[260];
    FUN_006d4e80();
    if (list)
        FUN_006d5980();
    list = new List;
    count = 1;
    FUN_006d46e0(path);
    strcat_s(path, 260, DAT_00dc0ad4);
    strcat_s(path, 260, DAT_00e0828c);
    HANDLE h = FindFirstFileA(path, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.nFileSizeLow)
                FUN_006d5a40(fd.cFileName, -1, 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
        Item* p = list->head;
        if (p && count <= 1) {
            p->FUN_006cdc90();
            count = p->unk08;
            if (!p->FUN_006cddc0() && !p->FUN_006cddd0())
                count++;
        }
    }
}
}
}   // namespace f3m_006d5bf0

// @f3 0x006c09c0 (community match, verified in this file)
#include <windows.h>
namespace f3m_006c09c0 {
namespace N6C09C0 {
struct Owned6c0 { virtual ~Owned6c0(); };
struct Lock6c0 {
    CRITICAL_SECTION cs;
    ~Lock6c0() { DeleteCriticalSection(&cs); }
};
struct Base6c0 { virtual ~Base6c0() {} };
struct FUN_006c09c0 : Base6c0 {
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; Owned6c0* owned; Lock6c0 lock;
    virtual ~FUN_006c09c0();
};
// pdb: StreamingVoiceContext::~StreamingVoiceContext | FalloutAudioMedia.obj | fnv360_0822_debug, objopen_prop, low
FUN_006c09c0::~FUN_006c09c0() {
    if (owned) delete owned;
}
}
}   // namespace f3m_006c09c0

// @f3 0x006d4900 (community match, verified in this file)
#include <windows.h>
#include <string.h>
extern int DAT_01079b70;
namespace f3m_006d4900 {
namespace BackupRotation6d4900 {
struct Heap {void FUN_0086ba60(void*);}; extern Heap DAT_01090a78;
struct FUN_006cd980 {char filename[260];void* file;~FUN_006cd980();static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}};
int __cdecl FUN_00c05a0f(const char*,int);
int __cdecl FUN_00c02aeb(const char*,const char*);
struct Manager {void FUN_006d47a0(char*,char*,unsigned char);void FUN_006d4900(FUN_006cd980*,int);};
void Manager::FUN_006d4900(FUN_006cd980* header,int rotate) {
 char base[260];
 char source[260];
 char destination[260];
 char path[260];
 char filename[260];
 strcpy_s(filename,260,header->filename);
 delete header;
 if((unsigned char)rotate) {
  FUN_006d47a0(filename,path,(unsigned char)rotate);
  strcpy_s(base,260,path);
  base[strlen(base)-4]=0;
  for(int count=DAT_01079b70-1;count>=0;--count) {
   strcpy_s(source,260,base);
   for(int i=0;i<count;++i)strcat_s(source,260,".bak");
   strcpy_s(destination,260,source);
   strcat_s(destination,260,".bak");
   if(FUN_00c05a0f(source,0)!=-1) {
    if(FUN_00c05a0f(destination,0)!=-1)DeleteFileA(destination);
    FUN_00c02aeb(source,destination);
   }
  }
  FUN_00c02aeb(path,base);
  strcpy_s(path,260,base);
 }
}
}
}   // namespace f3m_006d4900
