#include "f3_common.h"
// src/staging/blk_00ae0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);

extern "C" long __cdecl _fseek(void* stream, long offset, int whence);

extern int DAT_010a39d8;

extern "C" long __cdecl _fseek(void* stream, long offset, int whence);

extern int DAT_010a42cc;

extern int DAT_010a42cc;

extern int DAT_010a42dc;

extern int DAT_010a42ec;

extern int DAT_010a4328;

extern int DAT_010a4328;

struct NiFile;

extern int DAT_010a39d8;

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};

namespace fnv_00af1cc0 {
struct MemoryManager
{
    void Deallocate(void*);
};
}  // namespace fnv_00af1cc0

struct BSFile
{
    void __thiscall Close();
    virtual ~BSFile();
};

extern int DAT_010a42dc;

void* __cdecl _NiMalloc(unsigned int);

void* __cdecl _NiMalloc(unsigned int);

struct BSAudio
{
    char pad[0x38];
    void* pAudio;
};
extern BSAudio* DAT_011f6d98;

extern int DAT_010a42ec;

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

extern int(__stdcall* FUN_00fdf1c4)(char*);

struct S_00ae9290_Object
{
// @fnv 0x00ae9290
    virtual void FUN_00ae9290_f0()
    {}
    virtual void FUN_00ae9290_f1()
    {}
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

extern "C" int(__stdcall* DAT_00fdf060)(void);

struct FUN_00aea9d0_Listener
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void __stdcall vf3C(float value, int flag)
    {}
};

void* __cdecl _fnv_zlib_memset(void* p, int c, int n);
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};

struct FUN_00ae9360_Base
{
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    FUN_00ae9360_Base();
    virtual ~FUN_00ae9360_Base();
};

typedef int(__cdecl* FUN_00af2180_ProcFn)(void* self, void* arg0, int product, int* out, int one);

// FUN_00af2c70 - an empty __thiscall member function in an /Od module.
//
// The original is 11 bytes:
//   55           push ebp
//   8b ec        mov  ebp, esp
//   51           push ecx
//   89 4d fc     mov  dword ptr [ebp-4], ecx   <- the /Od spill of `this`
//   8b e5        mov  esp, ebp
//   5d           pop  ebp
//   c3           ret
//
// Under /Od MSVC 2008 always gives a member function a frame and always
// homes `this` at [ebp-4]; with no locals at all the frame is just the
// single `push ecx`, which is why the epilogue is `mov esp,ebp; pop ebp; ret`
// instead of a bare `pop ebp; ret`.
//
// The class name is deliberately tag-free so that the tag appears exactly
// once, in the mangled name of the member function itself.

// FUN_00af2c80 - an empty __thiscall member function in an /Od module.
//
// The original is 11 bytes:
//   55           push ebp
//   8b ec        mov  ebp, esp
//   51           push ecx
//   89 4d fc     mov  dword ptr [ebp-4], ecx   <- the /Od spill of `this`
//   8b e5        mov  esp, ebp
//   5d           pop  ebp
//   c3           ret
//
// Under /Od MSVC 2008 always gives a member function a frame and always
// homes `this` at [ebp-4]; with no locals at all the frame is just the
// single `push ecx`, which is why the epilogue is `mov esp,ebp; pop ebp; ret`
// instead of a bare `pop ebp; ret`.

extern "C" __declspec(dllimport) bool __cdecl SteamAPI_IsSteamRunning();
extern "C" __declspec(dllimport) unsigned int __cdecl SteamUser();

typedef void(__cdecl* FUN_00af2db0_Notify)(int code, int value);

int __cdecl FUN_00ec3bad(int value);

unsigned int* __cdecl FUN_00ec3bad(unsigned int* value);

struct S_00aff060_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;

    int __thiscall FUN_00aff060(void*);
};

extern int(__stdcall* DAT_00fdf138)(void*);

// Returns 0 if DAT_00fdf138 returns nonzero for this->unk10, otherwise 4.
// @f3 0x004248b0 (community match, verified in this file)
class S_00aff060_Target
{
  public:
    virtual void Slot0();
    virtual void Slot1();
    virtual bool Slot2(void* a1, int* out);
};

struct S_00aff060_Fields
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    S_00aff060_Target* unk24;
};

// pdb: ModelLoader::GetLoadedFileFromMap | ModelLoader.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apFileName
int S_00aff060_Class::FUN_00aff060(void* a1)
{
    S_00aff060_Fields* self = reinterpret_cast<S_00aff060_Fields*>(this);
    int result = 0;
    bool ok = self->unk24->Slot2(a1, &result);
    return ok ? result : 0;
}


extern "C" __declspec(dllimport) int __stdcall CopyFileA(const char* lpExistingFileName, const char* lpNewFileName,
                                                         unsigned char bFailIfExists);

struct BucketTableStorage
{
    struct Node
    {
        Node* next;
    };
    unsigned int bucketCount;
    Node** data;
    unsigned int count;
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void FreeItem(Node*);
    virtual void unk14();
    virtual void FreeNode(Node*);

    void ClearAll()
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            while (data[i])
            {
                Node* node = data[i];
                data[i] = data[i]->next;
                FreeItem(node);
                FreeNode(node);
            }
        }
        count = 0;
    }
};

struct AudioFile
{
    virtual AudioFile* Destroy(unsigned int);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int offset, int origin);
    int position;
    int(__cdecl* read)(AudioFile*, void*, int, int*, int);
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    bool valid;
    __forceinline bool IsValid()
    {
        return valid;
    }
    char unk2d;
    short unk2e;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
};

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* lpFileName, unsigned long dwDesiredAccess,
                                                             unsigned long dwShareMode, void* lpSecurityAttributes,
                                                             unsigned long dwCreationDisposition,
                                                             unsigned long dwFlagsAndAttributes, void* hTemplateFile);

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* lpBuffer, unsigned long nNumberOfBytesToRead,
                                                        unsigned long* lpNumberOfBytesRead, void* lpOverlapped);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();

typedef unsigned long DWORD;
typedef void* HANDLE;

enum
{
    ERROR_SUCCESS = 0,
    ERROR_FILE_NOT_FOUND = 2,
    ERROR_PATH_NOT_FOUND = 3,
    ERROR_WRITE_PROTECT = 19
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct xMMCKINFO
{
    unsigned int ckid;
    unsigned int cksize;
    unsigned int fccType;
    unsigned int dwDataOffset;
    unsigned int dwFlags;
};

struct xMMIOINFO
{
    unsigned int dwFlags;
    unsigned int fccIOProc;
    void* pIOProc;
    unsigned int wErrorRet;
    void* htask;
    int cchBuffer;
    char* pchBuffer;
    char* pchNext;
    char* pchEndRead;
    char* pchEndWrite;
    int lBufOffset;
    int lDiskOffset;
    unsigned int adwInfo[3];
    unsigned int dwReserved1;
    unsigned int dwReserved2;
    void* hmmio;
};

extern "C" void*(__stdcall* xmmioOpen)(char* pszFile, xMMIOINFO* pInfo, unsigned int dwFlags);
extern "C" unsigned int(__stdcall* xmmioDescend)(void* h, xMMCKINFO* pck, const xMMCKINFO* pckParent,
                                                 unsigned int uFlags);
extern "C" unsigned int(__stdcall* xmmioClose)(void* h, unsigned int uFlags);
extern "C" int(__stdcall* xmmioRead)(void* h, char* pch, int cch);
extern "C" unsigned int(__stdcall* xmmioAscend)(void* h, xMMCKINFO* pck, unsigned int uFlags);
extern "C" unsigned int(__stdcall* xmmioGetInfo)(void* h, xMMIOINFO* pInfo, unsigned int uFlags);
extern "C" unsigned int(__stdcall* xmmioAdvance)(void* h, xMMIOINFO* pInfo, unsigned int uFlags);

int __cdecl FUN_00ec3bad(int value);

// DirectSound buffer copy and auxiliary stream-state duplication.

typedef unsigned int U32;

typedef unsigned short U16;

struct GuidValue
{
    U32 data0;
    U32 data1;
    U32 data2;
    U32 data3;
};

struct WaveFormat
{
    U16 tag;
    U16 channels;
    U32 m_uiSamplesPerSecond;
    U32 averageBytes;
    U16 blockAlign;
    U16 m_usBitsPerSample;
};

struct AudioInterface
{

    virtual long __stdcall QueryInterface(const void*, void**) = 0;

    virtual long __stdcall AddRef() = 0;

    virtual long __stdcall Release() = 0;

    virtual long __stdcall CreateBuffer(void*, void**, void*) = 0;

    virtual long __stdcall v10() = 0;

    virtual long __stdcall v14(WaveFormat*, U32, U32*) = 0;

    virtual long __stdcall v18() = 0;

    virtual long __stdcall v1c() = 0;

    virtual long __stdcall v20() = 0;

    virtual long __stdcall v24() = 0;

    virtual long __stdcall v28() = 0;

    virtual long __stdcall Lock(U32, U32, void**, U32*, void**, U32*, U32) = 0;

    virtual long __stdcall v30() = 0;

    virtual long __stdcall v34() = 0;

    virtual long __stdcall v38() = 0;

    virtual long __stdcall v3c() = 0;

    virtual long __stdcall v40() = 0;

    virtual long __stdcall SetValue(float, U32) = 0;

    virtual long __stdcall v48() = 0;

    virtual long __stdcall Unlock(void*, U32, void*, U32) = 0;
};

struct CopyState
{
    U32 idle;
    U32 active;
    U32 byteCount;
    U32 segmentSize;
    U32 thirdSize;
    U32 index;
    void* bytes;
    void* segments;
    void* third;
};

struct AudioMemory
{
    void* __thiscall FUN_00aa3e40(U32 size);
};

extern AudioMemory DAT_011f6238;

extern GuidValue DAT_01093f04, DAT_01100fe4;

extern GuidValue DAT_01100f94, DAT_01100fb4;

extern const char DAT_010a4168[], DAT_010a4130[], DAT_010a40f0[], DAT_010a40b0[], DAT_010a4074[], DAT_010a4038[];

extern const char DAT_010a3ffc[], DAT_010a3fc0[], DAT_010a3f84[], DAT_010a3f48[], DAT_010a3f0c[], DAT_010a3ed0[];

class AudioBuffer
{

  public:
    virtual void v00() = 0;

    virtual void v04() = 0;

    virtual void v08() = 0;

    virtual void v0c() = 0;

    virtual void v10() = 0;

    virtual void v14() = 0;

    virtual void v18() = 0;

    virtual void v1c() = 0;

    virtual void v20() = 0;

    virtual void v24() = 0;

    virtual void OnCopied() = 0;

    unsigned int unk_004;

    unsigned int m_flags;

    unsigned int unk_00c;

    unsigned int m_uiContentCount;

    int m_playLength;

    unsigned int unk_018;

    unsigned int unk_01c;

    unsigned int unk_020;

    unsigned int unk_024;

    unsigned int unk_028;

    unsigned int unk_02c;

    unsigned int unk_030;

    unsigned short m_sampleRate;
    unsigned short m_unused36;

    unsigned int unk_038;

    unsigned int unk_03c;

    unsigned int unk_040;

    unsigned int unk_044;

    unsigned int unk_048;

    unsigned int unk_04c;

    unsigned int unk_050;

    unsigned int unk_054;

    unsigned int unk_058;

    unsigned int unk_05c;

    unsigned int unk_060;

    unsigned int unk_064;

    unsigned int unk_068;

    unsigned int unk_06c;

    unsigned int unk_070;

    unsigned int unk_074;

    unsigned int unk_078;

    unsigned int unk_07c;

    unsigned int unk_080;

    unsigned int unk_084;

    unsigned int unk_088;

    unsigned int unk_08c;

    unsigned int unk_090;

    unsigned int unk_094;

    unsigned int unk_098;

    unsigned int unk_09c;

    unsigned int unk_0a0;

    unsigned int unk_0a4;

    unsigned int unk_0a8;

    unsigned int unk_0ac;

    unsigned int unk_0b0;

    unsigned int unk_0b4;

    unsigned int unk_0b8;

    unsigned int unk_0bc;

    unsigned int unk_0c0;

    unsigned int unk_0c4;

    unsigned int unk_0c8;

    unsigned int unk_0cc;

    unsigned int unk_0d0;

    unsigned int unk_0d4;

    unsigned int unk_0d8;

    unsigned int unk_0dc;

    unsigned int unk_0e0;

    unsigned int unk_0e4;

    unsigned int unk_0e8;

    unsigned int unk_0ec;

    unsigned int unk_0f0;

    unsigned int unk_0f4;

    unsigned int unk_0f8;

    unsigned int unk_0fc;

    unsigned int unk_100;

    unsigned int unk_104;

    unsigned int unk_108;

    unsigned int unk_10c;

    unsigned int unk_110;

    unsigned int unk_114;

    unsigned int unk_118;

    unsigned int unk_11c;

    unsigned int unk_120;

    unsigned int unk_124;

    unsigned int unk_128;

    unsigned int unk_12c;

    unsigned int unk_130;

    unsigned int unk_134;

    unsigned int unk_138;

    unsigned int unk_13c;

    unsigned int unk_140;

    unsigned int unk_144;

    unsigned int m_copy148;

    unsigned int m_copy14c;

    unsigned int unk_150;

    unsigned int unk_154;

    unsigned short m_unused158;
    unsigned short m_sampleCount;

    unsigned int unk_15c;

    unsigned int unk_160;

    unsigned int unk_164;

    unsigned int unk_168;

    unsigned int unk_16c;

    unsigned int unk_170;

    unsigned int unk_174;

    unsigned int unk_178;

    unsigned int unk_17c;

    unsigned int unk_180;

    unsigned int unk_184;

    unsigned int unk_188;

    unsigned int unk_18c;

    unsigned int unk_190;

    unsigned int unk_194;

    AudioInterface* m_device;

    AudioInterface* m_buffer;

    unsigned int m_ctrl1a0;

    unsigned int m_descSize;

    unsigned int m_descFlags;

    unsigned int m_bufferBytes;

    unsigned int unk_1b0;

    WaveFormat* m_eVertexFormat;

    GuidValue m_algo;

    unsigned int m_oldBuffer;

    AudioInterface* m_duplicate;

    unsigned int m_ctrl1d0;

    AudioInterface* m_iBufferSize;

    unsigned int m_ctrl1d8;

    unsigned int m_totalBytes;

    unsigned int unk_1e0;

    unsigned int unk_1e4;

    unsigned int unk_1e8;

    unsigned int unk_1ec;

    unsigned int unk_1f0;

    unsigned int unk_1f4;

    unsigned int unk_1f8;

    unsigned int unk_1fc;

    unsigned int unk_200;

    unsigned int unk_204;

    unsigned int unk_208;

    unsigned int unk_20c;

    unsigned int unk_210;

    unsigned int unk_214;

    unsigned int unk_218;

    unsigned int unk_21c;

    unsigned int unk_220;

    unsigned int unk_224;

    CopyState* m_copyState;

    void __thiscall FUN_00ae97a0(AudioBuffer*, bool);

    bool __thiscall SetFlagState(bool);

    __forceinline bool IsBuffered()
    {
        return (m_flags & 0x10) || (m_flags & 0x4000000) || (m_flags & 0x2000000);
    }
    __forceinline bool Any()
    {
        return (m_flags & 0x4000000) || (m_flags & 0x2000000);
    }
    void __thiscall FUN_00af0630(AudioBuffer*, bool);
};

namespace fnv_00afdda0 {
struct MemoryAllocator
{
    void* FUN_00aa3e40(unsigned int);
};
extern MemoryAllocator DAT_011f6238;
}  // namespace fnv_00afdda0

extern BSAudio* DAT_011f6d98;

namespace Worker114 {
struct FUN_00ae9360_Base
{
    virtual ~FUN_00ae9360_Base();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned short flags034;
    char fileName[260];
    unsigned short unk13a;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    FUN_00ae9360_Base();
};
}

extern "C" __declspec(dllimport) int __stdcall WriteFile(void*, const void*, unsigned long, unsigned long*, void*);
