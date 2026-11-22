// bssystem/archive.cpp: S_af9, NP_afc, ArchiveStand, CompressedArchiveFile and more (4 functions)
#include "f3_common.h"
extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);

// PC file-stream hierarchy (PC layouts and vtable slot order from the PC RTTI vftables, slot names and member names
struct _iobuf;
template <class T> class BSStringT;
class Archive;

class NiBinaryStream
{
  public:
    virtual ~NiBinaryStream();                 // v00
    virtual operator bool();                   // v04
    virtual void Seek(int iNumBytes);          // v08
    virtual unsigned int GetPosition();        // v0C
    virtual void SetEndianSwap(bool bDoSwap);  // v10
    unsigned int m_uiStreamFlags;              // +0x04
    void* m_pfnRead;                           // +0x08
    void* m_pfnWrite;                          // +0x0C
};

class NiFile : public NiBinaryStream
{
  public:
    virtual void Seek(int iOffset, int iWhence);  // v14
    virtual char* FileName();                     // v18
    virtual unsigned int GetFileSize();           // v1C
    unsigned int m_uiBufferAllocSize;             // +0x10
    unsigned int m_uiBufferReadSize;              // +0x14
    unsigned int m_uiPos;                         // +0x18
    unsigned int m_uiTotalFileSize;               // +0x1C
    char* m_pBuffer;                              // +0x20
    _iobuf* m_pFile;                              // +0x24
    int m_eMode;                                  // +0x28 NiFile::OpenMode
    bool m_bGood;                                 // +0x2C
  protected:
    bool Flush();
};

class BSFile : public NiFile
{
  public:
    virtual bool Open(bool, bool);           // v20
    virtual bool AttachFileStream(_iobuf*);  // v24
    virtual unsigned int GetSize();          // v28
    // MSVC places overloads in reverse declaration order: Read(char) is v2C, Read(wchar_t) v30
    virtual unsigned int Read(BSStringT<wchar_t>&, unsigned int);
    virtual unsigned int Read(BSStringT<char>&, unsigned int);
    virtual unsigned int GetLine(char*, unsigned int, wchar_t);  // v34
    // Write(char) is v38, Write(wchar_t) v3C
    virtual unsigned int Write(const BSStringT<wchar_t>&, bool);
    virtual unsigned int Write(const BSStringT<char>&, bool);
    virtual bool Exist();                                          // v40
    virtual unsigned int ReadRawData(void*, unsigned int);         // v44
    virtual unsigned int WriteRawData(const void*, unsigned int);  // v48
    virtual void SetEndianSwap(bool doSwap);                       // v10 override
    bool m_bIsOpen;                                                // +0x30
    bool m_bEndianSwap;                                            // +0x31
    char* m_pFileBuffer;                                           // +0x34
    int m_iBufferSize;                                             // +0x38
    unsigned int m_uiFileSize;                                     // +0x3C
    unsigned int m_uiFilePosition;                                 // +0x40
    char pFileName[260];                                           // +0x44
    int iResult;                                                   // +0x148
    unsigned int m_uiBufferPosition;                               // +0x14C
    unsigned int m_uiBufferSize;                                   // +0x150
    unsigned int m_uiValueId;                                      // +0x154
};

class ArchiveFile : public BSFile
{
  public:
    virtual void SetEndianSwap(bool doSwap);  // v10 override
    Archive* m_pArchive;                      // +0x158 NiPointer<Archive> in the original
    unsigned int m_uiFileIndex;               // +0x15C
};

class CompressedArchiveFile : public ArchiveFile
{
  public:
    virtual void SetEndianSwap(bool doSwap);  // v10 override
    virtual void Seek(int offset, int mode);  // v14 override
    void* m_pArchiveStream;                   // +0x160
    char* m_pCompressedBuffer;                // +0x164
    unsigned int m_uiCompressedSize;          // +0x168
    unsigned int m_uiUncompressedSize;        // +0x16C
    unsigned int m_uiCompressedPosition;      // +0x170
    unsigned int m_uiUncompressedPosition;    // +0x174
};

typedef char _sizecheck_NiFile[sizeof(NiFile) == 0x30 ? 1 : -1];
typedef char _sizecheck_BSFile[sizeof(BSFile) == 0x158 ? 1 : -1];
typedef char _sizecheck_ArchiveFile[sizeof(ArchiveFile) == 0x160 ? 1 : -1];
typedef char _sizecheck_CompressedArchiveFile[sizeof(CompressedArchiveFile) == 0x178 ? 1 : -1];

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
};

template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    void SetSize(unsigned int, bool);
    unsigned int Find(T const&, unsigned int, bool(__cdecl*)(T const&, T const&));
    bool FUN_0076b610() const;
    unsigned int Add(T const&);
};

extern int DAT_011acdfc;
extern int DAT_011ace00;
extern int DAT_011ace04;

struct Arc
{
    void LoadNames();
};
struct LNode
{
    Arc* item;
    LNode* next;
};
extern LNode* DAT_011f8160;

unsigned int __cdecl _strlen(const char*);

struct S_af9
{
    bool FindHashEntry(int, int*, int);
    bool FUN_00afa120(int, int, int, int, int);
    bool FUN_00af9bf0(int, int, int*, int, int);
};

struct Owner25
{
    bool FindHashEntry(int a, int* out, int c);
    bool FUN_00afa120(int a, int b, int* out, int c, int d);
    int FUN_00afa6e0(int a, int b, int c);
};

struct FUN_00afb170_Args
{
    bool param_1;
    int param_2;
};

// @fnv 0x00afb170
bool __fastcall FUN_00afb170(void* pThis, FUN_00afb170_Args args)
{
    if (args.param_2 == 1)
        return args.param_1;
    return args.param_2;
}

struct S_afbb
{
    char pad[0x150];
    unsigned int pos;
    unsigned int size;
    int FUN_00b01800(void*, unsigned int);
    int FUN_00afbbf0(void*, unsigned int);
};

struct ZlibStreamPeer;
struct ZlibStream
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned long m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
    unsigned long m_ulTotalOutputBytes;
    char* msg;
    ZlibStreamPeer* state;
    int* m_pAllocateCallback;
    int* m_pFreeCallback;
    void* opaque;
    int data_type;
    unsigned long m_ulAdler32Checksum;
    unsigned long reserved;
};
typedef char _sizecheck_z_stream_s[sizeof(ZlibStream) == 56 ? 1 : -1];

class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
extern int DAT_010a464c;
int __cdecl _inflateEnd(ZlibStream* kReadStream);

namespace fnv_00afc6c0 {
class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};

extern MemoryManager g_memoryManager;
void __fastcall DestroyCompressedArchiveFile(void* pThis);

}  // namespace fnv_00afc6c0

namespace fnv_00afc6f0 {
class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};

extern MemoryManager g_memoryManager;
void __fastcall DestroyCompressedArchiveFile(void* pThis);

}  // namespace fnv_00afc6f0

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObj
{
    virtual void v0();
    virtual void v1();
    long refs;
};
struct Pointee
{
    char pad[0x158];
    RefObj ro;
};
struct NP_afc
{
    Pointee* p;
    NP_afc* FUN_00afc770(NP_afc*);
};

namespace fnv_00afd1b0 {
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObj
{
    virtual void v0();
    virtual void v1();
    long refs;
};
struct Pointee
{
    char pad[0x158];
    RefObj ro;
};
}  // namespace fnv_00afd1b0

extern void(__stdcall* DAT_00fdf1c0)(int);

struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl ComputeNameHash(char*, char*, FileNameHash*);

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl ComputeNameHash(const char*, const char*, void*);

struct FUN_00afd390_class
{
    void* FUN_00afd390(const char* path, int mode);
};

extern bool DAT_011acdf9;
extern char* DAT_011f8158;
int __cdecl _strcpy_s(char*, unsigned int, const char*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};

struct ArchiveFileEntryStand
{
    char pad[0xc];
    unsigned int uiSize;
};
struct ArchiveStand
{
    char pad[0x1b4];
    unsigned char m_ucEntryType;
    bool IsFileEntryValid(ArchiveFileEntryStand* apFile, bool abIgnore);
};

namespace fnv_00afc430 {
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
    void _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
int __cdecl _inflateEnd(void*);
extern int DAT_010a464c;
extern unsigned int DAT_011f8164;
struct S_afbb
{
    int FUN_00afbbf0(void*, unsigned int);
};
struct FUN_00afb300
{
    FUN_00afb300(int, int, int, int, int);
    ~FUN_00afb300();
};
struct FUN_00afc430 : public FUN_00afb300
{
    FUN_00afc430(int, int, int, int, int);
};
}  // namespace fnv_00afc430

struct FUN_00afcde0_shell
{
    unsigned int* data;
    unsigned int size;
    unsigned int alloc;
    virtual void* v0();
    virtual unsigned int* v1(unsigned int);
    void InitArray(unsigned int, unsigned int);
};

struct FUN_00afce90_S
{
    unsigned __int64 value;
    int FUN_00afce90(const unsigned __int64& other);
};

extern bool DAT_011acdf9;
extern bool DAT_011f8154;
extern int DAT_011acdfc;
extern int DAT_011ace00;
extern int DAT_011ace04;

class MemoryManager;
extern MemoryManager g_memoryManager;
struct P03MM
{
    void* Allocate(unsigned int);
};
unsigned int __cdecl _strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
extern bool DAT_011acdf8;
extern char DAT_011f8050[];
extern const char DAT_010a433a[];
extern char* DAT_011f815c;
extern unsigned int DAT_011f8164;

namespace fnv_00af7db0 {
int __cdecl _stricmp(const char*, const char*);
}  // namespace fnv_00af7db0

namespace fnv_00af6340 {
enum ARCHIVE_TYPE
{
    ARCHIVE_TYPE_DUMMY
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct BSFileEntry
{
    char pad[0xc];
    int flags;
};
struct ArchiveFile;
struct ArchiveRefCount
{
    virtual void Slot0();
    virtual void Destroy();
    long count;
    void AcquireReference()
    {
        InterlockedIncrement(&count);
    }
    void DecRef()
    {
        if (!InterlockedDecrement(&count))
            Destroy();
    }
};
struct Archive
{
    char pad[0x158];
    ArchiveRefCount rc;
    ArchiveFile* CreateArchiveFile(BSFileEntry*, unsigned int, unsigned int);
};
struct ArchiveSmartPtr
{
    Archive* p;
    ArchiveSmartPtr(Archive* a) : p(a)
    {
        if (p)
            p->rc.AcquireReference();
    }
    Archive* operator->()
    {
        return p;
    }
    ~ArchiveSmartPtr()
    {
        if (p)
            p->rc.DecRef();
    }
};
}  // namespace fnv_00af6340

extern bool DAT_011f8154;

namespace fnv_00af44f0 {
extern char* DAT_011f8158;
extern char* DAT_011f815c;
extern "C" void __cdecl _DeallocateAlias(void* ptr);
struct MemoryManager
{
    void __thiscall _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;

}  // namespace fnv_00af44f0

extern unsigned int DAT_011f8164;

namespace fnv_00af56d0 {
extern "C" int __cdecl RemoveArchiveFile(int);
extern "C" int DAT_011f8160;

}  // namespace fnv_00af56d0

struct Entry16
{
    int a;
    int b;
    int c;
    unsigned int d;
};

struct FUN_00af9ba0_shell
{
    int FindEntryIndex(unsigned int key);
    unsigned int FUN_00af9b60(unsigned int index, unsigned int value);
    int FUN_00af96d0(int index, unsigned int value);
    int FUN_00af9ba0(unsigned int key);
};

namespace fnv_00afac20 {
struct FUN_00afac20_entry
{
    int a;
    int b;
    int c;
    unsigned int bits;
    inline void SetSize(unsigned int v)
    {
        bits = (v & 0x7fffffff) | (bits & 0x80000000);
    }
};
struct S_af9
{
    bool FUN_00af9bf0(int, int, int*, int*, int);
    bool FUN_00afac20(int a, int b, int c);
};
}  // namespace fnv_00afac20

namespace fnv_00afac90 {
struct FUN_00afac90_entry
{
    int a;
    int b;
    int c;
    unsigned int bits;
    inline void SetSize(unsigned int v)
    {
        bits = (v & 0x7fffffff) | (bits & 0x80000000);
    }
};
struct S_af9
{
    bool FUN_00afa120(int, int, int*, int, int);
    bool FUN_00afac90(int a, int b, int c);
};
}  // namespace fnv_00afac90

extern "C" __declspec(dllimport) int __stdcall TryEnterCriticalSection(void* cs);

namespace fnv_00afcd10 {
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;
}  // namespace fnv_00afcd10

namespace fnv_00afcd40 {
class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
}  // namespace fnv_00afcd40

namespace fnv_00afcd60 {
class MemoryManager
{
  public:
    void* Reallocate(void* p, unsigned int size);
};
extern MemoryManager g_memoryManager;
}  // namespace fnv_00afcd60

namespace fnv_00af5700 {
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl _stricmp(const char*, const char*);
struct FileFinder
{
    int GetFileLocation(char* apFileName, char* apPath, unsigned int auiArchiveType, unsigned int auiFlags);
};
extern FileFinder* g_fileFinder;
struct ArchiveListNode
{
    BSFile* pArchive;
    ArchiveListNode* pNext;
};
extern ArchiveListNode* DAT_011f8160;
void __cdecl RemoveArchiveFile(BSFile* apArchive);

}  // namespace fnv_00af5700

namespace fnv_00af5fa0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
int __cdecl FUN_00af7d80(const char* apFileName);
const char* __cdecl SkipDataPrefix(const char* apFileName);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
struct FileNameHash
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDirHash,
                                                     FileNameHash& arFileHash);
};
struct S_af9
{
    bool FUN_00af9bf0(int arDirHash, int arFileHash, int* apFolderIndex, int apFileIndex, int apFileName);
};
struct Archive : public S_af9
{
    void* OpenFile(unsigned int auiFolderIndex, unsigned int auiFileIndex, unsigned int auiBufferSize,
                   const char* apFileName);
    unsigned short HasArchiveTypeFlags(unsigned int auiFlags)
    {
        return *(unsigned short*)((char*)this + 0x180) & auiFlags;
    }
};
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
}  // namespace fnv_00af5fa0

namespace fnv_00af6160 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* p);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
int __cdecl FUN_00af7d80(const char* apFileName);
const char* __cdecl SkipDataPrefix(const char* apFileName);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
struct FileNameHash
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDirHash,
                                                     FileNameHash& arFileHash);
};
struct S_af9
{
    bool FUN_00af9bf0(int arDirHash, int arFileHash, int* apFolderIndex, int apFileIndex, int apFileName);
};
struct Archive : public S_af9
{
    void* OpenFile(unsigned int auiFolderIndex, unsigned int auiFileIndex, unsigned int auiBufferSize,
                   const char* apFileName);
    unsigned short HasArchiveTypeFlags(unsigned int auiFlags)
    {
        return *(unsigned short*)((char*)this + 0x180) & auiFlags;
    }
};
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
extern _RTL_CRITICAL_SECTION DAT_011f8170;
}  // namespace fnv_00af6160

namespace fnv_00af7e80 {
struct FUN_00afd390_class
{
    void* v;
    void* __thiscall FUN_00afd390(const char*, int);
};

}  // namespace fnv_00af7e80

namespace fnv_00afcce0 {
extern int DAT_010a469c;

struct FUN_00afcde0_shell
{
    void* vptr;
    void InitArray(unsigned int, unsigned int);
    void* FUN_00afcce0();
};

}  // namespace fnv_00afcce0

namespace fnv_00af8e60 {
extern long volatile DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct ArcBase
{
    virtual ~ArcBase();
    char data[0x154];
};
struct ArcRef
{
    virtual ~ArcRef()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
    long refs;
};
struct ArcLock
{
    char data[0x18];
    ~ArcLock()
    {
        DeleteCriticalSection(data);
    }
};
struct FUN_00af8e60 : ArcBase, ArcRef
{
    char pad[0x3c];
    ArcLock cs;
    virtual ~FUN_00af8e60();
    void ReleaseOwnedMemory();
    void FreeNames(int);
    void FreeEntries();
};
// Destructor that calls ReleaseOwnedMemory, FreeNames(0) and FreeEntries in sequence.
// @fnv 0x00af8e60
FUN_00af8e60::~FUN_00af8e60()
{
    ReleaseOwnedMemory();
    FreeNames(0);
    FreeEntries();
}
}  // namespace fnv_00af8e60

namespace fnv_00af9230 {
struct MemoryManager
{
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
struct S_af9
{
    char pad[0x1b4];
    unsigned char flags;
    char pad2[3];
    void* names;
    void* extra;
    inline bool IsStatic()
    {
        return flags & 4;
    }
    inline void SetOwned(bool b)
    {
        if (b)
            flags |= 0x10;
        else
            flags &= ~0x10;
    }
    void ReleaseOwnedMemory();
};
}  // namespace fnv_00af9230

namespace fnv_00af9410 {
struct MemoryManager
{
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
struct FUN_00af9410_entry
{
    int a;
    int b;
    int c;
    void* mem;
};
struct S_af9
{
    char pad[0x170];
    unsigned int count;
    char pad2[0x10];
    FUN_00af9410_entry* entries;
    char pad3[0x2c];
    unsigned char flags;
    inline unsigned int GetCount()
    {
        return count;
    }
    inline bool IsStatic()
    {
        return flags & 4;
    }
    void FreeEntries();
};
}  // namespace fnv_00af9410

namespace fnv_00af9ad0 {
struct FUN_00af9ad0_entry
{
    int a;
    int b;
    unsigned int size;
    void* base;
    inline unsigned int GetSize()
    {
        return size;
    }
    inline void* GetBase()
    {
        return base;
    }
};
struct S_af9
{
    char pad[0x170];
    unsigned int count;
    char pad2[0x10];
    FUN_00af9ad0_entry* entries;
    inline unsigned int GetCount()
    {
        return count;
    }
    int FindEntryIndex(unsigned int addr);
};
}  // namespace fnv_00af9ad0

extern int DAT_010a469c;

namespace fnv_00af5320 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class BSRefCountedSI
{
  public:
    virtual ~BSRefCountedSI();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
class Archive : public BSFile, public BSRefCountedSI
{
};
template <class T> class ArchivePtr
{
  public:
    ArchivePtr(const ArchivePtr& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArchivePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
inline const char* GetArchiveName(const ArchivePtr<Archive>& m_pArchive)
{
    return m_pArchive->FileName();
}
struct ArchiveListNode
{
    ArchivePtr<Archive> spItem;
    ArchiveListNode* pNext;
};
extern _RTL_CRITICAL_SECTION DAT_011f8170;

}  // namespace fnv_00af5320

namespace fnv_00afa550 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;
struct ArchiveFileEntryStand
{
    unsigned int iNameHash;
    unsigned int iDirHash;
    unsigned int iSize;
    unsigned int iOffset;
    unsigned int GetSize() const
    {
        return iSize & 0x3fffffff;
    }
    bool IsCompressed() const
    {
        return iSize & 0x40000000;
    }
};
struct ArchiveFolderEntryStand
{
    unsigned int iHash;
    unsigned int iCount;
    unsigned int iOffset;
    ArchiveFileEntryStand* pFiles;
};
struct ArchiveStand;
struct FUN_00afb300 : public ArchiveFile
{
    FUN_00afb300(const char*, ArchiveStand*, unsigned int, unsigned int, int);
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* p);
};
struct FUN_00afc430 : public CompressedArchiveFile
{
    FUN_00afc430(const char*, ArchiveStand*, unsigned int, unsigned int, int);
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* p);
};
struct ArchiveStand
{
    char pad[0x16c];
    unsigned int iArchiveFlags;
    char pad2[0x184 - 0x170];
    ArchiveFolderEntryStand* pFolders;
    bool GetArchiveFlag(unsigned int uiFlag) const
    {
        return !!(iArchiveFlags & uiFlag);
    }
    bool IsFileEntryValid(ArchiveFileEntryStand*, bool);
    ArchiveFile* OpenFile(int iFolder, int iFile, int iMode, const char* pName);
};

}  // namespace fnv_00afa550

namespace fnv_00afa750 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct ArchiveFileEntryStand
{
    unsigned int hash[2];
    unsigned int size;
    unsigned int offset;
    __forceinline bool IsCompressionToggled()
    {
        return size & 0x40000000;
    }
    __forceinline unsigned int GetSize()
    {
        return size & 0x3fffffff;
    }
    __forceinline unsigned int GetOffset()
    {
        return offset & 0x7fffffff;
    }
};
struct ArchiveStand;
struct FUN_00afb300 : ArchiveFile
{
    FUN_00afb300(unsigned int, ArchiveStand*, unsigned int, unsigned int, unsigned int);
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
struct FUN_00afc430 : CompressedArchiveFile
{
    FUN_00afc430(unsigned int, ArchiveStand*, unsigned int, unsigned int, unsigned int);
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
struct ArchiveStand
{
    char pad[0x16c];
    unsigned int flags;
    __forceinline bool IsCompressed()
    {
        return (flags & 4) != 0;
    }
    bool IsFileEntryValid(ArchiveFileEntryStand*, bool);
    ArchiveFile* CreateArchiveFile(ArchiveFileEntryStand*, unsigned int, unsigned int);
};
}  // namespace fnv_00afa750

namespace fnv_00afc7f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiRefObject
{
    virtual void _v00();
    virtual void DeleteThis();
    long m_uiRefCount;

    void DecrementReferenceCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveBase
{
    virtual void _v00();
    char pad[0x154];
};

struct Archive : public ArchiveBase, public NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;

    ~NiPointer()
    {
        if (m_pObject)
        {
            m_pObject->DecrementReferenceCount();
        }
    }
};

}  // namespace fnv_00afc7f0

namespace fnv_00afc880 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncrementReferenceCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecrementReferenceCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveBase
{
    virtual void _v00();
    char pad[0x154];
};

struct Archive : public ArchiveBase, public NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;

    NiPointer() : m_pObject(0)
    {}

    NiPointer(const NiPointer& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject)
        {
            m_pObject->IncrementReferenceCount();
        }
    }

    bool operator==(T* p) const
    {
        return m_pObject == p;
    }

    bool operator!=(T* p) const
    {
        return m_pObject != p;
    }
};

struct NP_afc
{
    NiPointer<Archive> m_spArchive;
    NP_afc* m_pkNext;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }

    NP_afc(NP_afc* other) : m_spArchive(other->m_spArchive), m_pkNext(0)
    {}

    NP_afc* FUN_00afc770(NP_afc* other)
    {
        if (m_spArchive.m_pObject != other->m_spArchive.m_pObject)
        {
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->DecrementReferenceCount();
            }
            m_spArchive.m_pObject = other->m_spArchive.m_pObject;
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->IncrementReferenceCount();
            }
        }
        return this;
    }

    void PushArchive(NP_afc*);
};

}  // namespace fnv_00afc880

namespace fnv_00afcc10 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncrementReferenceCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecrementReferenceCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveBase
{
    virtual void _v00();
    char pad[0x154];
};

struct Archive : public ArchiveBase, public NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;

    NiPointer() : m_pObject(0)
    {}

    NiPointer(const NiPointer& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject)
        {
            m_pObject->IncrementReferenceCount();
        }
    }

    bool operator==(T* p) const
    {
        return m_pObject == p;
    }

    bool operator!=(T* p) const
    {
        return m_pObject != p;
    }
};

struct NP_afc
{
    NiPointer<Archive> m_spArchive;
    NP_afc* m_pkNext;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }

    NP_afc(NP_afc* other) : m_spArchive(other->m_spArchive), m_pkNext(0)
    {}

    NP_afc* FUN_00afc770(NP_afc* other)
    {
        if (m_spArchive.m_pObject != other->m_spArchive.m_pObject)
        {
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->DecrementReferenceCount();
            }
            m_spArchive.m_pObject = other->m_spArchive.m_pObject;
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->IncrementReferenceCount();
            }
        }
        return this;
    }

    void AppendArchive(NP_afc*);
};

}  // namespace fnv_00afcc10

namespace fnv_00af6540 {
struct Archive;
struct BSFileEntry;
struct FileNameHash;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
struct FileNameHash
{
    unsigned char cLast;
    unsigned int uiCRC;
};
struct Owner25
{
    int FUN_00afa6e0(int arDirectoryHash, int arFileNameHash, int apFileName);
};
struct Archive : public Owner25
{
    unsigned short HasArchiveType(int aeArchiveTypeIndex)
    {
        return *(unsigned short*)((char*)this + 0x180) & (1 << aeArchiveTypeIndex);
    }
};
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
}  // namespace fnv_00af6540

struct MemMgr_00affd80
{
    void* Allocate(unsigned int);
};
struct DeallocMM_00affd80
{
    void _DeallocateAlias(void*);
};
extern MemMgr_00affd80 _g_memoryManager;
extern int DAT_010a2480;
extern __declspec(thread) int DAT_tls_memctx;
__forceinline void* operator new[](unsigned int auiSize)
{
    return _g_memoryManager.Allocate(auiSize);
}
__forceinline void operator delete[](void* apMem)
{
    ((DeallocMM_00affd80*)&_g_memoryManager)->_DeallocateAlias(apMem);
}
__forceinline int GetMemCtx_00affd80()
{
    return DAT_tls_memctx;
}
__forceinline void SetMemCtx_00affd80(int aiCtx)
{
    DAT_tls_memctx = aiCtx;
}
struct MemCtxScope_00affd80
{
    int iOld;
    __forceinline MemCtxScope_00affd80(int aiCtx)
    {
        iOld = GetMemCtx_00affd80();
        DAT_tls_memctx = aiCtx;
    }
    __forceinline ~MemCtxScope_00affd80()
    {
        SetMemCtx_00affd80(iOld);
    }
};

namespace fnv_00af96d0 {
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

struct MemMgrStand
{
    void* Allocate(unsigned int auiSize);
    void Deallocate(void* apMem);
};
extern MemMgrStand g_arcMemMgr;
extern int DAT_011ace04;
extern int DAT_010a2480;

inline void* operator new[](unsigned int auiSize)
{
    return g_arcMemMgr.Allocate(auiSize);
}
inline void operator delete[](void* apMem)
{
    g_arcMemMgr.Deallocate(apMem);
}

struct ArcFolderRec
{
    int unk00;
    int unk04;
    unsigned int uiFileCount;
    unsigned int unk0c;
};

struct ArcStream;
typedef unsigned int(__cdecl* ArcReadFn)(ArcStream*, void*, unsigned int, unsigned int*, unsigned int);

struct ArcStream
{
    virtual ~ArcStream();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(int aiOffset, int aiWhence);
    unsigned int m_uiStreamFlags;
    ArcReadFn m_pfnRead;
    inline unsigned int BinaryRead(void* apBuffer, unsigned int auiBytes, unsigned int* apuiSizes, unsigned int auiNum)
    {
        unsigned int uiRead = m_pfnRead(this, apBuffer, auiBytes, apuiSizes, auiNum);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

inline unsigned int ArcLoadChars(ArcStream& arStream, char* apBuffer, unsigned int auiCount)
{
    unsigned int uiCompSize = 1;
    unsigned int uiRet = arStream.BinaryRead(apBuffer, auiCount, &uiCompSize, 1);
    return uiRet;
}

struct ArcStand : public ArcStream
{
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
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
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    unsigned int uiFlags;
    int unk170;
    int unk174;
    int unk178;
    unsigned int uiNamesLength;
    int unk180;
    ArcFolderRec* pFolders;
    int unk188;
    int unk18c;
    unsigned int uiNamesOffset;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    unsigned char m_ucEntryType;
    char unk1b5;
    char unk1b6;
    char unk1b7;
    int unk1b8;
    int unk1bc;
    char* pNameBuffer;
    unsigned int** ppFileNameOffsets;
    bool FUN_00afb170(bool, int);
    inline bool HasNameTable()
    {
        return m_ucEntryType & 0x20;
    }
    inline bool HasFileNames()
    {
        return (uiFlags & 2) != 0;
    }
    inline bool HasFlag20()
    {
        return (uiFlags & 0x20) != 0;
    }
    inline bool CheckCache(bool abFlag, int aiVal)
    {
        return FUN_00afb170(abFlag, aiVal);
    }
    static inline int GetCacheVal()
    {
        return DAT_011ace04;
    }
    inline unsigned int GetFolderFileCount(unsigned int auiFolder)
    {
        return pFolders[auiFolder].uiFileCount;
    }
    inline void CopyName(char* apDest, const char* apSrc)
    {
        strcpy_s(apDest, 0x100, apSrc);
    }
    char* FUN_00af96d0(unsigned int auiFolder, unsigned int auiFile);
};

}  // namespace fnv_00af96d0

struct ArcCS
{
    int unk00;
};
struct ArcCS;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(ArcCS*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(ArcCS*);
struct ArchiveStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int iOffset, int iWhence);
    virtual char* FileName();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual unsigned int ReadRaw(void* apBuffer, unsigned int auiSize);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
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
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    ArcCS kCS;
    unsigned int GetTruePos()
    {
        return unk038 != -1 ? unk038 : unk150;
    }
    void Lock()
    {
        EnterCriticalSection(&kCS);
    }
    void Unlock()
    {
        LeaveCriticalSection(&kCS);
    }
};

struct FUN_00afbc70_shell : public ArchiveFile
{
    ArchiveStub* GetArchive()
    {
        return (ArchiveStub*)m_pArchive;
    }
    void LockArchive(char* apName)
    {
        if (GetArchive())
            GetArchive()->Lock();
    }
    unsigned int GetTruePos()
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
    unsigned int ReadFromArchive(void* apBuffer, unsigned int auiSize);
};

namespace fnv_00afbde0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

template <class T> class NiPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct ArcStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int iOffset, int iWhence);
    virtual char* FileName();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual unsigned int ReadArc(void* buf, unsigned int size);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int m_iBufferSize;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
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
    unsigned int unk198;
    int csLock;
    unsigned int GetPos() const
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
};

struct ArcFileX
{
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int m_iBufferSize;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
    NiPointer<ArcStream> m_pArchive;
    unsigned int m_uiFileIndex;
    unsigned int GetPos() const
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
    void LockArc(const char* apName)
    {
        if (m_pArchive)
            EnterCriticalSection(&m_pArchive->csLock);
    }
    unsigned int FUN_00afbde0(void* buf, unsigned int size);
};

}  // namespace fnv_00afbde0

struct ArchiveEntryBuf
{
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct ArchiveArray
{
    ArchiveEntryBuf** data;
    unsigned int size;
    unsigned int alloc;
    virtual ~ArchiveArray();
    unsigned int GetSize() const
    {
        return size;
    }
    ArchiveEntryBuf* GetAt(unsigned int idx) const
    {
        return data[idx];
    }
};

class ArchiveRefObject
{
  public:
    virtual ~ArchiveRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class ArchiveObj : public BSFile, public ArchiveRefObject
{
};

class ArchivePtr
{
  public:
    ArchiveObj* m_pObject;
    ArchivePtr(ArchiveObj* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArchivePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ArchivePtr& operator=(const ArchivePtr& ptr);
    ArchivePtr& operator=(ArchiveObj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ArchiveList
{
    ArchivePtr m_item;
    ArchiveList* m_pkNext;
    ~ArchiveList();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            ArchiveList* pNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            ArchiveList* pDel = m_pkNext;
            delete pDel;
            m_pkNext = pNext;
        }
        m_item = ArchivePtr(0);
    }
};

extern ArchiveArray* DAT_011f8168;
extern ArchiveArray* DAT_011f816c;
extern ArchivePtr DAT_011f8190[2][9];
inline ArchivePtr& GetArchivePtr(int aiType, unsigned int auiIndex)
{
    return DAT_011f8190[aiType][auiIndex];
}

struct RefCounted_af5
{
    virtual ~RefCounted_af5();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct ArcPtr_af5
{
    T* m_pObject;
    ArcPtr_af5(T* const& p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArcPtr_af5()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

namespace fnv_00af6690 {
struct BSRefCountedStub
{
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long refCount;

    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};

struct ArchiveStub : public BSFile, public BSRefCountedStub
{
    int unk160;
    int unk164;
    int unk168;
    unsigned int uiFlags;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    unsigned short usTypes;

    int FindEntry(int a, int b, int c);
    unsigned short HasType(unsigned int auiMask) const
    {
        return (unsigned short)(usTypes & auiMask);
    }
};

template <class T> struct ArchivePtr
{
    T* m_pObject;

    ArchivePtr(const ArchivePtr& rhs) : m_pObject(rhs.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArchivePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

}  // namespace fnv_00af6690

extern ArcCS DAT_011f8170;
struct ArchiveDirectoryIndex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
    unsigned int count;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned short types;
    bool FUN_00afdc00(const FileNameHash* key);
};
struct LookupArchive : BSFile
{
    RefObj reference;
    ArchiveDirectoryIndex index;
    unsigned int GetTypes() const
    {
        const LookupArchive* archive = this;
        return archive->index.types;
    }
    bool Contains(const FileNameHash* key)
    {
        return index.FUN_00afdc00(key);
    }
};
__forceinline void AddArchiveReference(RefObj* reference)
{
    InterlockedIncrement(&reference->refs);
}
__forceinline void ReleaseArchiveReference(RefObj* reference)
{
    if (!InterlockedDecrement(&reference->refs))
        reference->v1();
}
struct ScopedArchive
{
    LookupArchive* pointer;
    __forceinline ScopedArchive(Arc* const& value) : pointer((LookupArchive*)value)
    {
        if (pointer)
            AddArchiveReference(&pointer->reference);
    }
    __forceinline ~ScopedArchive()
    {
        if (pointer)
            ReleaseArchiveReference(&pointer->reference);
    }
};

extern "C" char* __cdecl strrchr(const char*, int);
struct ArchiveRef : RefObj
{
    __forceinline void Retain()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void Release()
    {
        if (!InterlockedDecrement(&refs))
            v1();
    }
};
struct ArchiveView : BSFile
{
    ArchiveRef reference;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int flags;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned short types;
    __forceinline unsigned int GetTypes()
    {
        return types;
    }
};
struct ArchiveOwner
{
    ArchiveView* p;
    __forceinline ArchiveOwner(const ArchiveOwner& archive) : p(archive.p)
    {
        if (p)
            p->reference.Retain();
    }
    __forceinline ~ArchiveOwner()
    {
        if (p)
            p->reference.Release();
    }
    __forceinline operator ArchiveView*()
    {
        return p;
    }
    __forceinline ArchiveView* operator->()
    {
        return p;
    }
};
__forceinline unsigned int CountEntries(LNode* input)
{
    unsigned int node = 0;
    LNode* entry = input;
    while (entry)
    {
        if (entry->item)
            ++node;
        entry = entry->next;
    }
    return node;
}

struct SortKey
{
    unsigned __int64 value;
};
__forceinline int CompareSortKeys(SortKey* current, SortKey* other)
{
    if (current->value < other->value)
        return -1;
    else if (current->value > other->value)
        return 1;
    return 0;
}

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct BSIntrusiveRefCounted_af7
{
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long BackgroundTask;
    void IncRefCount()
    {
        InterlockedIncrement(&BackgroundTask);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&BackgroundTask) == 0)
            DeleteThis();
    }
};

struct Archive_af7
{
    int unk000;
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
    BSIntrusiveRefCounted_af7 kRefCounted;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    unsigned short usFileTypes;

    unsigned short HasFileType(unsigned int auiType)
    {
        return usFileTypes & auiType;
    }
    void ProcessFiles_afac20(int a, int b, int c);
};

struct ArchivePtr_af7
{
    Archive_af7* pObject;
    ArchivePtr_af7(Archive_af7* const& p) : pObject(p)
    {
        if (pObject)
            pObject->kRefCounted.IncRefCount();
    }
    ~ArchivePtr_af7()
    {
        if (pObject)
            pObject->kRefCounted.DecRefCount();
    }
    Archive_af7* operator->() const
    {
        return pObject;
    }
};

struct ArchiveNode_af7
{
    Archive_af7* pItem;
    ArchiveNode_af7* pNext;
    bool IsEmpty() const
    {
        return !pNext && (bool)(int)(pItem == 0);
    }
};

struct ArchiveNames : BSFile
{
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int flags;
    unsigned int directoryCount;
    unsigned int fileCount;
    unsigned int unk178;
    unsigned int nameBytes;
    unsigned int unk180;
    Entry16* directories;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int namePosition;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned char nameFlags;
    unsigned int unk1b8;
    unsigned int unk1bc;
    char* names;
    unsigned int** offsets;
    __forceinline void SetNamesReady(bool ready)
    {
        if (ready)
            nameFlags |= 0x20;
        else
            nameFlags &= ~0x20;
    }
    __forceinline unsigned int GetFileCount()
    {
        return fileCount;
    }
    __forceinline unsigned int GetDirectoryCount()
    {
        return directoryCount;
    }
    __forceinline unsigned int GetNameBytes()
    {
        return nameBytes;
    }
    __forceinline bool HasNames()
    {
        return (flags & 2) != 0;
    }
    __forceinline unsigned int GetDirectoryFiles(unsigned int index)
    {
        return directories[index].c;
    }
    __forceinline unsigned int ReadNames(void* buffer, unsigned int size, unsigned int* unitSize)
    {
        unsigned int result = ((unsigned int(__cdecl*)(void*, void*, unsigned int, unsigned int*,
                                                       unsigned int))m_pfnRead)(this, buffer, size, unitSize, 1);
        m_uiStreamFlags += result;
        return result;
    }
    __forceinline unsigned int ReadBytes(void* buffer, unsigned int size)
    {
        unsigned int unitSize = 1;
        unsigned int bytesReturned = ReadNames(buffer, size, &unitSize);
        return bytesReturned;
    }
    __forceinline unsigned int NameLength(const char* name)
    {
        return strlen(name);
    }
    void LoadNames();
};

namespace fnv_00af92f0 {
inline void BSFreeMem(void* apMem)
{
    g_memoryManager._DeallocateAlias(apMem);
}

struct ArchiveNames
{
    int unk00;
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    unsigned int uiDirectoryCount;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    unsigned char ucArchiveFlags;
    unsigned char unk1B5;
    unsigned char unk1B6;
    unsigned char unk1B7;
    int unk1B8;
    int unk1BC;
    char* pDirectoryStringsBuffer;
    char** pFileNameStrings;

    bool IsRetainingNames()
    {
        return (ucArchiveFlags & 4) ? true : false;
    }
    unsigned int GetDirectoryCount()
    {
        return uiDirectoryCount;
    }
    void SetNamesFreed(bool abSet)
    {
        if (abSet)
            ucArchiveFlags |= 0x20;
        else
            ucArchiveFlags &= ~0x20;
    }

    void FreeNames(bool abKeepFileNames);
};

}  // namespace fnv_00af92f0

extern "C" void __cdecl FUN_00ecbc5b(char*, unsigned int);
extern int __cdecl _stricmp(const char*, const char*);
void __cdecl FNV_Warning(const char*, ...);
struct ArchiveSearch : ArchiveStub
{
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0;
    unsigned char flags;
    bool Disabled()
    {
        return (flags & 1) ? true : false;
    }
    bool HasNames()
    {
        return (unk16c & 1) != 0;
    }
    unsigned int Count()
    {
        return unk170;
    }
    FileNameHash* GetHash(unsigned int i)
    {
        return (FileNameHash*)(((Entry16*)unk184) + i);
    }
    const char* GetString(unsigned int);
};
inline int FileNameHash::Compare(FileNameHash* rhs)
{
    if (*(unsigned __int64*)this < *(unsigned __int64*)rhs)
        return -1;
    else if (*(unsigned __int64*)this > *(unsigned __int64*)rhs)
        return 1;
    return 0;
}
inline unsigned int TextLength(const char* text)
{
    return _strlen(text);
}
inline void CopyText(char* dst, unsigned int size, const char* src)
{
    _strcpy_s(dst, size, src);
}
inline void LowerText(char* dst, unsigned int size)
{
    FUN_00ecbc5b(dst, size);
}

namespace fnv_00afa120 {
struct Entry97
{
    unsigned int hash0, hash1;
    unsigned int size, offset;
};
struct Group97
{
    unsigned int hash0, hash1;
    unsigned int count;
    Entry97* entries;
    unsigned int Size() const
    {
        return count;
    }
};
struct MM97
{
    void* FUN_00aa3e40(unsigned int);
    void FUN_00aa4060(void*);
};
extern MM97 DAT_011f6238;
inline void Copy97(char* d, unsigned int n, const char* s)
{
    strcpy_s(d, n, s);
}
void __cdecl FUN_00ecbc5b(char*, unsigned int);
inline void Lower97(char* d, unsigned int n)
{
    FUN_00ecbc5b(d, n);
}
inline unsigned int Length97(const char* s)
{
    return strlen(s);
}
extern "C" char* __cdecl strtok_s(char*, const char*, char**);
extern "C" int __cdecl _stricmp(const char*, const char*);
}  // namespace fnv_00afa120

namespace fnv_00afad00 {
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
template <unsigned int N> inline int strcat_s(char (&dest)[N], const char* src)
{
    return strcat_s(dest, N, src);
}
extern char DAT_011f8050[];
struct BSHashA
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
inline unsigned int ZeroAD()
{
    return 0;
}
struct SubAD
{
    unsigned int lo;
    unsigned int hi;
    unsigned int pad8;
    unsigned int flags;
    void ClearLowAD()
    {
        flags = (ZeroAD() & 0x7fffffff) | (flags & 0x80000000);
    }
};
struct EntryAD
{
    unsigned int lo;
    unsigned int hi;
    unsigned int count;
    SubAD* subs;
    unsigned int GetCount() const
    {
        return count;
    }
    SubAD* GetSub(int idx)
    {
        return subs + idx;
    }
};
struct Hash64
{
    unsigned __int64 v;
};
inline int HashCompareAD(const Hash64& a, const Hash64& b)
{
    if (a.v < b.v)
        return -1;
    else if (a.v > b.v)
        return 1;
    return 0;
}
struct ListAD1
{
    int pad0;
    FUN_00afce90_S** items;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
    FUN_00afce90_S** GetItems()
    {
        return items;
    }
    FUN_00afce90_S* GetItemAt(int idx)
    {
        return items[idx];
    }
};
struct ListAD2
{
    int pad0;
    Hash64** items;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
    Hash64** GetItems()
    {
        return items;
    }
    Hash64* GetItemAt(int idx)
    {
        return items[idx];
    }
};
extern ListAD1* DAT_011f816c;
extern ListAD2* DAT_011f8168;
inline ListAD1* List1Ptr()
{
    return DAT_011f816c;
}
inline ListAD2* List2Ptr()
{
    return DAT_011f8168;
}
struct ThisAD
{
    char pad[0x16c];
    unsigned int uiFlags;
    unsigned int count170;
    unsigned int GetCount170() const
    {
        return count170;
    }
    bool CheckFlagAD(unsigned int bit) const
    {
        return (this->uiFlags & bit) != 0;
    }
    char pad174[0x10];
    EntryAD* entries;
    const char* GetString(int);
    void FUN_00b01510(BSHashA*);
    int FUN_00b01590(char*, const char*, BSHashA*);
    int ClearMatchedEntries();
};
}  // namespace fnv_00afad00

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);

struct FUN_00afb520_mm
{
    void FUN_00aa4060(void* p);
};
extern FUN_00afb520_mm DAT_011f6238;

extern int DAT_010a2484;
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
__forceinline void RenderCopyData(void* dest, const void* source, unsigned int size)
{
    FUN_00ec44d0(dest, source, size);
}
struct ArchiveRead : ArchiveStub
{
    char* FUN_00aa1ac0();
    void FUN_00aa16d0(int, int);
    unsigned int FUN_00aa1570(void*, unsigned int);
    int GetCurrentPos()
    {
        int value = unk01c;
        return value;
    }
    int GetReadSize()
    {
        int value = unk014;
        return value;
    }
    unsigned int GetBufferSize()
    {
        unsigned int value = unk010;
        return value;
    }
    unsigned int GetLength()
    {
        unsigned int value = unk154;
        return value;
    }
    void SetPos(int pos)
    {
        unk018 = pos;
    }
    void SetReadSize(int size)
    {
        unk014 = size;
    }
    void SetTruePos(int pos)
    {
        unk150 = pos;
    }
};
struct Reader078 : ArchiveFile
{
    ArchiveRead* GetArchive()
    {
        return (ArchiveRead*)m_pArchive;
    }
    void LockArchive(char* name)
    {
        if (GetArchive())
            GetArchive()->Lock();
    }
    void UnlockArchive()
    {
        if (GetArchive())
            GetArchive()->Unlock();
    }
    unsigned int ReadAtOffset(char* output, unsigned int size, unsigned int offset);
};

struct ArcRefObject
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct ArcObj : public BSFile, public ArcRefObject
{
};
struct ArcPtr
{
    ArcObj* m_pObject;
    ArcPtr(ArcObj* pObject)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArcPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ArcPtr& operator=(const ArcPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    ArcPtr& operator=(ArcObj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(ArcObj* pObject) const
    {
        return m_pObject == pObject;
    }
    bool operator!=(const ArcPtr& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }
};
struct BSSimpleList
{
    ArcPtr m_item;
    BSSimpleList* m_pkNext;
    ~BSSimpleList()
    {
        RemoveAll();
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            BSSimpleList* pkNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = pkNext;
        }
        m_item = ArcPtr(0);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager._DeallocateAlias(pvMem);
    }
    bool IsEmpty() const
    {
        return m_pkNext == 0 && m_item == 0;
    }
    void RemoveItem(const ArcPtr& item);
};

struct ListItem
{
    unsigned int value;
    ListItem* next;
    ~ListItem();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct NullRef
{
    Pointee* object;
    NullRef(Pointee* p = 0) : object(p)
    {
        RefObj* pRef;
        if (object)
        {
            RefObj* ref = &object->ro;
            InterlockedIncrement(&ref->refs);
        }
    }
    ~NullRef()
    {
        if (object)
        {
            RefObj* ref = &object->ro;
            if (!InterlockedDecrement(&ref->refs))
                ref->v1();
        }
    }
};

struct OwnerList
{
    Pointee* object;
    ListItem* head;
    OwnerList* FUN_00afc770(const NullRef& rhs)
    {
        RefObj* r0 = 0;
        RefObj* r1 = 0;
        if (object != rhs.object)
        {
            if (object)
            {
                r0 = &object->ro;
                if (!InterlockedDecrement(&r0->refs))
                    r0->v1();
            }
            object = rhs.object;
            if (object)
            {
                r1 = &object->ro;
                InterlockedIncrement(&r1->refs);
            }
        }
        return this;
    }
    void FUN_00afcaf0();
};

namespace fnv_00af5480 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpcs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpcs);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plong);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plong);

struct RefBase_af5480
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct ObjBase_af5480
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int unk154;
};

struct Obj_af5480 : ObjBase_af5480, RefBase_af5480
{
};

template <class T> struct NiPtr_af5480
{
    T* m_pObject;
    NiPtr_af5480(T* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPtr_af5480()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct MemoryManager_af5480
{
    void* Allocate(unsigned int uiSize);
};

extern MemoryManager_af5480 g_memoryManager_af5480;

struct NP_af5480
{
    NP_af5480* FUN_00afc770(NP_af5480* pkOther);
};

struct LNode_af5480
{
    Obj_af5480* m_pObject;
    LNode_af5480* m_pNext;
    void AddTail(NiPtr_af5480<Obj_af5480>& sp)
    {
        if (!sp.m_pObject)
            return;
        LNode_af5480* pNode = this;
        while (pNode->m_pNext)
            pNode = pNode->m_pNext;
        if (pNode->m_pObject)
        {
            LNode_af5480* pNew = (LNode_af5480*)g_memoryManager_af5480.Allocate(8);
            LNode_af5480* pInsert;
            if (pNew)
            {
                Obj_af5480* pkObject = sp.m_pObject;
                pNew->m_pObject = pkObject;
                if (pkObject)
                    pkObject->IncRefCount();
                pNew->m_pNext = 0;
                pInsert = pNew;
            }
            else
            {
                pInsert = 0;
            }
            pNode->m_pNext = pInsert;
        }
        else
        {
            NP_af5480* pOther = (NP_af5480*)pNode;
            NP_af5480* pSp = (NP_af5480*)&sp;
            pOther->FUN_00afc770(pSp);
        }
    }
};

}  // namespace fnv_00af5480

namespace fnv_00af5550 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    volatile long m_uiRefCount;
};

class MyArchiveFile : public BSFile, public NiRefObject
{
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;

    NiPointer(T* pObject = (T*)0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    operator T*() const
    {
        return m_pObject;
    }

    NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct LNode
{
    NiPointer<MyArchiveFile> item;
    LNode* next;

    void DeleteNode(LNode* n);
    LNode* FUN_00afc770(LNode* a2);

    void Remove(NiPointer<MyArchiveFile>& target)
    {
        LNode* head = (LNode*)0;
        LNode* tail = (LNode*)0;
        LNode* pNext = (LNode*)0;
        LNode* pPrev = (LNode*)0;
        if (!target.m_pObject)
            return;
        if (!next && !item.m_pObject)
            return;
        LNode* curr = this;
        LNode* prev = this;
        while (curr && curr->item.m_pObject != target.m_pObject)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
            return;
        if (curr == this)
        {
            if (next)
            {
                prev = next;
                next = prev->next;
                FUN_00afc770(prev);
                prev->next = (LNode*)0;
                DeleteNode(prev);
            }
            else
            {
                item = (MyArchiveFile*)0;
            }
        }
        else
        {
            prev->next = curr->next;
            curr->next = (LNode*)0;
            DeleteNode(curr);
        }
    }
};

struct _RTL_CRITICAL_SECTION;
extern NiPointer<MyArchiveFile> g_files[2][9];

inline NiPointer<MyArchiveFile>& GetFile(int j, unsigned int i)
{
    return g_files[j][i];
}

}  // namespace fnv_00af5550

namespace fnv_00af4550 {
extern unsigned char DAT_011acdf8;
extern const char* DAT_011f8158;
extern const char* DAT_011f815c;
extern const char DAT_010a433a[];
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" int __cdecl _stricmp(const char*, const char*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" char* __cdecl strtok_s(char*, const char*, char**);
struct ArchiveRef
{
    virtual void slot0();
    virtual void Destroy();
    long count;
    inline void AcquireReference()
    {
        InterlockedIncrement(&count);
    }
    inline void DecRef()
    {
        if (!InterlockedDecrement(&count))
            Destroy();
    }
};
class Archive : public BSFile
{
  public:
    ArchiveRef refs;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned short types;
    inline unsigned short HasType(unsigned int i)
    {
        return (unsigned short)(types & (1 << i));
    }
    inline unsigned long BufferSize()
    {
        return m_uiBufferAllocSize;
    }
    bool SetBufferSize(unsigned int);
};
template <class T> struct ArchivePointer
{
    T* ptr;
    inline ArchivePointer(T* p) : ptr(p)
    {
        if (ptr)
            ptr->refs.AcquireReference();
    }
    inline ~ArchivePointer()
    {
        if (ptr)
            ptr->refs.DecRef();
    }
    inline operator T*() const
    {
        return ptr;
    }
    inline T* operator->() const
    {
        return ptr;
    }
    inline T* GetForAssignment() const
    {
        T* previous;
        unsigned long previousCount;
        return ptr;
    }
    void FUN_00afd1b0(T*);
};
inline unsigned int MainArchiveGroup()
{
    return 0;
}
extern ArchivePointer<Archive> DAT_011f8190[2][9];
struct ArchiveMemory
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern ArchiveMemory DAT_011f6238;
inline char* AllocationResult(char* const& result)
{
    return result;
}
inline void ArchiveFree(void* const& data)
{
    DAT_011f6238.Deallocate(data);
}
inline int CopyPath(char* dest, unsigned int size, const char* source)
{
    return strcpy_s(dest, size, source);
}
inline int AppendPath(char* dest, unsigned int size, const char* source)
{
    return strcat_s(dest, size, source);
}
inline unsigned long TextLength(const char* text)
{
    return strlen(text);
}
}  // namespace fnv_00af4550

namespace fnv_00afd4e0 {
struct FileNameHash
{
    unsigned char unk00, unk01, unk02, unk03;
    unsigned int unk04;
};
extern char DAT_011acfbc[6][10];
}  // namespace fnv_00afd4e0

namespace fnv_00af4be0 {
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
extern MemoryManagerAllocHelper g_memoryManager;
struct LNode;
extern LNode* DAT_011f8160;
static const char emptyPathWarning[] = "Loading a user created or misnamed BSA";
extern bool DAT_011acdf8;
int __cdecl strcpy_s(char*, unsigned int, const char*);
unsigned int __cdecl strlen(const char*);
void __cdecl FNV_Warning(const char*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct OpenRef
{
    virtual void v0();
    virtual void Destroy();
    long refs;
    void Inc()
    {
        InterlockedIncrement(&refs);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
struct PluginFile
{
    virtual ~PluginFile();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    bool good;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    char name[260];
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    OpenRef ref;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    unsigned short types;
    unsigned short unk182;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    unsigned char flags;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;

    static void* operator new(unsigned int);
    static void operator delete(void*);
    PluginFile(const char*, unsigned int, int, bool);
    bool IsGood()
    {
        return good;
    }
    bool IsBad()
    {
        return (flags & 1) != 0 ? true : false;
    }
    const char* Name()
    {
        return name;
    }
};
struct OpenPtr
{
    PluginFile* p;
    OpenPtr(PluginFile* a) throw() : p(a)
    {
        if (p)
            p->ref.Inc();
    }
    ~OpenPtr()
    {
        if (p)
            p->ref.Dec();
    }
    operator PluginFile*() const
    {
        return p;
    }
    OpenPtr& operator=(const OpenPtr&);
    OpenPtr(const OpenPtr& a) throw() : p(a.p)
    {
        if (p)
            p->ref.Inc();
    }
};

struct OpenNode
{
    OpenPtr item;
    OpenNode* next;
    static void* operator new(unsigned int size)
    {
        return ((MemoryManagerAllocHelper*)&g_memoryManager)->Allocate(size);
    }
    OpenNode() throw() : item(0), next(0)
    {}
    OpenNode(const OpenPtr& p) throw() : item(p), next(0)
    {}
    static OpenNode* Create(const OpenPtr& value)
    {
        OpenNode* result = new OpenNode(value);
        return result;
    }
    static OpenNode* CreateDirect(const OpenPtr& value)
    {
        return new OpenNode(value);
    }
    void InsertCurrent(const OpenPtr& value)
    {
        if (!value.p)
            return;
        if (item.p)
        {
            OpenNode* insertedNode = CreateDirect(item);
            insertedNode->next = next;
            next = insertedNode;
            item = value;
        }
        else
            item = value;
    }
    void PushArchive(const OpenPtr& value)
    {
        if (!value.p)
            return;
        if (item.p)
        {
            OpenNode* allocatedNode = Create(item);
            OpenNode* insertedNode = allocatedNode;
            insertedNode->next = next;
            next = insertedNode;
            item = value;
        }
        else
            item = value;
    }
    void AppendArchive(const OpenPtr& value)
    {
        if (!value.p)
            return;
        OpenNode* tail = this;
        while (tail->next)
            tail = tail->next;
        if (tail->item.p)
        {
            OpenNode* allocated = Create(value);
            OpenNode* created = allocated;
            tail->next = created;
        }
        else
            tail->item = value;
    }
};

struct OpenFinder
{
    int Find(const char*, char*, int, int);
};
extern OpenFinder* g_fileFinder;
__forceinline void SetOpenNode(OpenNode* const& p)
{
    DAT_011f8160 = (LNode*)p;
}
}  // namespace fnv_00af4be0

namespace fnv_00af67d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkCriticalSection);
extern "C" int __cdecl strcpy_s(char* pcDst, unsigned int uiSize, const char* pcSrc);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    long m_uiRefCount;
};
static __forceinline void AcquireReference(NiRefObject* o)
{
    o->IncRefCount();
}
template <class T> class NiPointer
{
  public:
    NiPointer(T* pObj = 0)
    {
        m_pObject = pObj;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct ArchiveFileEntry
{
    unsigned int uiNameHash;
    unsigned int uiDirHash;
    unsigned int uiReserved;
    unsigned int uiSize;
};
class Archive : public BSFile, public NiRefObject
{
  public:
    void Lock()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void Unlock()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
    const char* FUN_00af9ba0(ArchiveFileEntry* pkEntry);
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int m_kCriticalSection;
};
extern Archive* DAT_011f8190[2][9];

static __forceinline Archive* GetArc(bool c, unsigned int i)
{
    return DAT_011f8190[c ? 1 : 0][i];
}
}  // namespace fnv_00af67d0

namespace fnv_00af7060 {
struct MemoryManager
{
    void* Allocate(unsigned int);
};
extern MemoryManager _g_memoryManager;
inline void* __cdecl operator new[](unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct ArcCS
{
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
};

struct HashKey
{
    unsigned int low, high;
    const unsigned __int64& Value() const
    {
        return *(const unsigned __int64*)this;
    }
    int Compare(const HashKey* rhs) const
    {
        if (Value() < rhs->Value())
            return -1;
        else if (Value() > rhs->Value())
            return 1;
        return 0;
    }
    int CompareTo(const HashKey* rhs) const
    {
        int order = Compare(rhs);
        return order;
    }
    HashKey(const char*, int);
    void* operator new(unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
};
inline unsigned int CombinedLength(const char* prefix, const char* name)
{
    unsigned int prefixLength = strlen(prefix);
    return prefixLength + strlen(name) + 1;
}
inline void CopyPath(char* dest, unsigned int size, const char* src)
{
    strcpy_s(dest, size, src);
}
inline void AppendPath(char* dest, unsigned int size, const char* src)
{
    strcat_s(dest, size, src);
}
void* __cdecl operator new(unsigned int);
struct PathNode
{
    const char* path;
    PathNode* next;
    PathNode(const PathNode*);
    void FUN_005ae3d0(char* const& value)
    {
        if (!value)
            return;
        if (path)
        {
            PathNode* node = new PathNode(this);
            node->next = next;
            next = node;
            path = value;
        }
        else
        {
            path = value;
        }
    }
};
struct FileRecord
{
    HashKey key;
    unsigned int size, offset;
};
struct DirectoryRecord
{
    unsigned int low, high, count;
    FileRecord* files;
    unsigned int Count()
    {
        return count;
    }
};
struct ArchiveSearch
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
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
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    DirectoryRecord* dirs;
    int unk188, unk18c, unk190, unk194, unk198;
    ArcCS lock;
    bool FindHashEntry(int, int*, int);
    bool IsFileEntryValid(FileRecord*, bool);
    const char* FUN_00af96d0(int, unsigned int);
};
}  // namespace fnv_00af7060

namespace fnv_00af7eb0 {
struct MemoryManager
{
    void* __thiscall Allocate(unsigned int);
    void __thiscall Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
inline void* __cdecl operator new[](unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
inline void* __cdecl operator new(unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
inline void __cdecl operator delete[](void* p)
{
    _g_memoryManager.Deallocate(p);
}
inline void __cdecl operator delete(void* p)
{
    _g_memoryManager.Deallocate(p);
}
extern volatile long DAT_011f4400;
extern unsigned char DAT_011acdf9;
extern bool DAT_011f8154;
extern int DAT_011acdfc, DAT_011ace00, DAT_011ace04;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern void(__stdcall* DAT_00fdf054)(void*);
struct Entry077
{
    unsigned int hashLow, hashHigh, size;
    Entry077* files;
    Entry077()
    {
        size = 0;
        files = 0;
    }
    void SetFiles(Entry077* p)
    {
        files = p;
    }
};
struct FUN_00afd8b0
{
    unsigned int magic, version, offset, flags, directories, files, dirNamesSize, fileNamesSize;
    unsigned short types, reserved;
    FUN_00afd8b0();
};
struct Header077 : FUN_00afd8b0
{
    Entry077* entries;
    Header077()
    {
        entries = 0;
    }
    unsigned int Count()
    {
        return directories;
    }
    unsigned int DirNamesSize()
    {
        return dirNamesSize;
    }
    unsigned int FileNamesSize()
    {
        return fileNamesSize;
    }
    unsigned int Version()
    {
        return version;
    }
    void SetFiles(unsigned int i, Entry077* p)
    {
        entries[i].SetFiles(p);
    }
    unsigned int FileCount(unsigned int i)
    {
        return entries[i].size;
    }
    bool Valid()
    {
        return magic == 0x415342;
    }
    bool VersionValid()
    {
        return version <= 0x68;
    }
    bool Has(unsigned int flag)
    {
        return (flags & flag) != 0;
    }
    static void SetFlag(unsigned int& field, unsigned int mask, bool value)
    {
        field = value ? field | mask : field & ~mask;
    }
    void SetVersionFlag()
    {
        SetFlag(flags, 0x100, false);
    }
};
struct NiRefObject077
{
    virtual ~NiRefObject077();
    long refs;
    NiRefObject077()
    {
        refs = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
};
struct FUN_00b00260 : BSFile
{
    FUN_00b00260(const char*, int, unsigned int, bool);
    bool FUN_00afb170(bool, int);
    static int CacheMode0()
    {
        return DAT_011acdfc;
    }
    static int CacheMode1()
    {
        return DAT_011ace00;
    }
    static int CacheMode2()
    {
        return DAT_011ace04;
    }
    bool NeedCache();
};
struct Critical077
{
    int debug, lock, recursion, owner, semaphore, spin;
    Critical077()
    {
        DAT_00fdf054(this);
    }
    ~Critical077();
};
struct ArcStream077;
typedef unsigned int(__cdecl* ArcReadFn077)(ArcStream077*, void*, unsigned int, unsigned int*, unsigned int);
struct ArcStream077
{
    virtual ~ArcStream077();
    unsigned int m_uiStreamFlags;
    ArcReadFn077 m_pfnRead;
    unsigned int BinaryRead(void* buffer, unsigned int length, unsigned int* sizes, unsigned int number)
    {
        unsigned int uiRead = m_pfnRead(this, buffer, length, sizes, number);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
inline unsigned int ArcLoadChars(BSFile& stream, void* buffer, unsigned int length)
{
    unsigned int uiCompSize = 1;
    unsigned int uiRet = reinterpret_cast<ArcStream077&>(stream).BinaryRead(buffer, length, &uiCompSize, 1);
    return uiRet;
}
inline unsigned int ArcStringLength(const char* value)
{
    return strlen(value);
}
struct FUN_00af7eb0 : Header077, FUN_00b00260, NiRefObject077
{
    struct Time077
    {
        unsigned int low, high;
    } stamp;
    unsigned int namesOffset;
    unsigned int cacheIndex, cacheOffset;
    Critical077 critical;
    unsigned char status;
    unsigned char statusReserved;
    unsigned short statusReserved2;
    char* directoryNames;
    unsigned int* directoryOffsets;
    char* fileNames;
    unsigned int** fileOffsets;
    unsigned int id;
    FUN_00af7eb0(const char*, int, bool, bool);
    virtual ~FUN_00af7eb0();
    void ClearMatchedEntries();
    bool SetBufferSize(unsigned int);
    void ReadArray(Entry077* buffer, unsigned int count)
    {
        ArcLoadChars(*this, buffer, count * sizeof(Entry077));
    }
    bool Good()
    {
        return m_bGood;
    }
    template <int mask> void SetStatus(bool value)
    {
        if (value)
            status |= mask;
        else
            status &= ~mask;
    }
    bool HasStatus(int mask)
    {
        return (status & mask) ? true : false;
    }
    unsigned int TruePos()
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
};
}  // namespace fnv_00af7eb0

namespace fnv_00af94c0 {
extern int DAT_010a2480;
extern int DAT_010a2484;
struct ArcMemMgr
{
    void FUN_00aa4060(void* p);
    void* FUN_00aa3e40(unsigned int uiSize);
};
extern ArcMemMgr DAT_011f6238;
inline void ArcFree(void* p)
{
    DAT_011f6238.FUN_00aa4060(p);
}
inline void* ArcAlloc(unsigned int uiSize)
{
    return DAT_011f6238.FUN_00aa3e40(uiSize);
}
struct ArcEntry
{
    unsigned int a;
    unsigned int b;
    unsigned int uiIndex;
    unsigned int c;
};
class ArcStream
{
  public:
    virtual ~ArcStream();
    virtual operator bool();
    virtual void Seek(int iNumBytes);
    virtual unsigned int GetPosition();
    virtual void SetEndianSwap(bool bDoSwap);
    virtual void SeekTo(int iOffset, int iWhence);
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(ArcStream* pkThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                              unsigned int uiNumComponents);
    void* m_pfnWrite;
    char pad10[0x16c - 0x10];
    unsigned int m_uiValue1;
    unsigned int m_uiCount;
    char pad174[0x184 - 0x174];
    ArcEntry* m_pkEntryArray;
    char pad188[0x1b4 - 0x188];
    unsigned char m_ucFlags;
    char pad1b5[3];
    char* m_pcData;
    unsigned int* m_puiOffsets;

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = 1;
        unsigned int uiBytesRead;
        unsigned int d;
        uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, &uiComponentSize, 1);
        m_uiStreamFlags += uiBytesRead;
        d = uiBytesRead;
        return d;
    }
    bool IsLoaded() const
    {
        return (m_ucFlags & 0x10) ? true : false;
    }
    bool HasStrings() const
    {
        return (m_uiValue1 & 1) != 0;
    }
    unsigned int LookupSequenceByKey(unsigned int i) const
    {
        return m_pkEntryArray[i].uiIndex;
    }
    char* GetString(unsigned int uiIndex);
};

}  // namespace fnv_00af94c0

namespace fnv_00afa8e0 {
struct PoolY
{
    void* FUN_00aa3e40(unsigned int uiSize);
    void FUN_00aa4060(void* p);
};
extern PoolY DAT_011f6238;
extern bool DAT_011f8154;
extern "C" int __cdecl FUN_00ec65a6(char* dst, unsigned int sz, const char* src);
extern "C" int __cdecl FUN_00ecbc5b(char* s, unsigned int sz);
inline void* AllocNY(unsigned int n)
{
    return DAT_011f6238.FUN_00aa3e40(n + 1);
}
inline void CopyStrY(char* d, unsigned int n, const char* s)
{
    FUN_00ec65a6(d, n, s);
}
inline void LowerY(char* s, unsigned int n)
{
    FUN_00ecbc5b(s, n);
}
struct ArcY
{
    char pad[0x16c];
    unsigned int m_uiValue1;
    bool Flag1() const
    {
        return (m_uiValue1 & 1) != 0;
    }
    bool Flag2() const
    {
        return (m_uiValue1 & 2) != 0;
    }
    bool FUN_00af9bf0(int a, int b, int* pA, int* pB, int c);
    const char* GetString(int a);
    const char* FUN_00af96d0(int a, int b);
    const char* GetPathComponent(int a1, int a2, const char* pPath);
};
}  // namespace fnv_00afa8e0

namespace fnv_00afb300 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
void __cdecl FUN_00ec65a6(char* d, unsigned int n, const char* s);
void __cdecl FUN_00ec44d0(void* d, const void* s, unsigned int n);
extern unsigned int DAT_011f8164;
struct RefBase
{
    virtual ~RefBase();
    long m_iObjectReferenceCount;
    void AcquireReference()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
};
struct FileBase
{
    virtual ~FileBase();
    unsigned int m_04, m_08, m_0c;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
    unsigned int m_1c;
    char* m_pBuffer;
    char pad24[0x20];
    char pFileName[0x104];
    int iResult;
    unsigned int m_uiBufferPosition;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
};
struct Archive : FileBase, RefBase
{
    unsigned int m_160, m_164, m_168;
    unsigned int m_flags;
    bool IsFlag()
    {
        return (m_flags & 0x100) != 0;
    }
};
struct ArchivePtr
{
    Archive* m_p;
    ArchivePtr(Archive* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    ~ArchivePtr();
    ArchivePtr& FUN_00afd1b0(Archive* p);
    Archive* operator->()
    {
        return m_p;
    }
};
struct FUN_00aff180 : FileBase
{
    FUN_00aff180();
    void FUN_00afbfa0(int);
    void FUN_00afb5f0(int, int);
    unsigned int ReadAtOffset(char*, unsigned int, int);
    void DebugCheck()
    {
        const char* pName;
        const char* pBuffer;
    }  // compiled-out debug check (locals only)
    char* Cur()
    {
        char* r = m_pBuffer + m_uiPos + 1;
        return r;
    }
};
struct FUN_00afb300 : FUN_00aff180
{
    ArchivePtr m_pArchive;
    unsigned int m_uiFileIndex;
    virtual ~FUN_00afb300();
    FUN_00afb300(const char* name, Archive* arch, unsigned int off, unsigned int size, int mode);
};
// Initializes the archive-backed object and buffer, then may read bytes and copy a length-prefixed name from the buffer.
// @fnv 0x00afb300
FUN_00afb300::FUN_00afb300(const char* name, Archive* arch, unsigned int off, unsigned int size, int mode)
{
    DebugCheck();
    if (name)
        FUN_00ec65a6(pFileName, 0x104, name);
    m_pBuffer = 0;
    m_pArchive.FUN_00afd1b0(arch);
    m_uiFileIndex = off;
    m_uiValueId = size;
    FUN_00afbfa0(0);
    m_uiBufferAllocSize = (size > DAT_011f8164 && mode != -1) ? DAT_011f8164 : size;
    FUN_00afb5f0(0, 0);
    if (mode == -1 || m_pArchive->IsFlag())
    {
        int x = 0;
        m_uiBufferReadSize = ReadAtOffset(m_pBuffer, m_uiBufferAllocSize, x);
        if (m_pArchive->IsFlag())
        {
            unsigned char len = m_pBuffer[m_uiPos];
            FUN_00ec44d0(pFileName, Cur(), len);
            pFileName[len] = 0;
            m_uiPos = len + m_uiPos + 1;
            m_uiBufferSize = len + 1;
        }
    }
}
}  // namespace fnv_00afb300

namespace fnv_00af7400 {
struct CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

extern "C"
{
    __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
    __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
}

unsigned int __cdecl strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);

const char* __cdecl SkipDataPrefix(const char*);
int __cdecl FUN_00af7d80(const char*);

class FUN_00afd390_class
{
  public:
    int unk00;
    int unk04;
    void* FUN_00afd390(const char*, int);
};

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    inline int GetNameID()
    {
        return unk08;
    }
};

class Archive : public BSFile, public NiRefObject
{
  public:
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    unsigned short m_usFlags;
    short unk182;
    ArchiveEntry* pEntries;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    CRITICAL_SECTION cs;
    unsigned char unk1B4;
    unsigned char unk1B5;
    short unk1B6;
    inline unsigned int GetFlags()
    {
        return m_usFlags;
    }
    inline ArchiveEntry* GetEntry(int index)
    {
        return &pEntries[index];
    }
    inline bool HasNameTable()
    {
        return unk1B4 & 0x20;
    }
    inline void Lock()
    {
        EnterCriticalSection(&cs);
    }
    inline void Unlock()
    {
        LeaveCriticalSection(&cs);
    }
};

class Owner25
{
  public:
    bool FindHashEntry(int, int*, int);
};

class FUN_00af9ba0_shell
{
  public:
    int FUN_00af96d0(int, unsigned int);
};

struct NP_afc
{
    Archive* m_pObject;

    NP_afc(Archive* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }
    NP_afc(const NP_afc& p)
    {
        m_pObject = p.m_pObject;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }
    ~NP_afc()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
    operator Archive*() const
    {
        return m_pObject;
    }
    NP_afc* FUN_00afc770(NP_afc* rhs)
    {
        if (m_pObject != rhs->m_pObject)
        {
            if (m_pObject)
            {
                m_pObject->DecRefCount();
            }
            m_pObject = rhs->m_pObject;
            if (m_pObject)
            {
                m_pObject->IncRefCount();
            }
        }
        return this;
    }
};

struct LNode
{
    NP_afc item;
    LNode* next;
};
extern LNode* DAT_011f8160;

class FUN_00aa5140
{
  public:
    FUN_00aa5140();
    const char* FUN_00aa5230(int);
};

__forceinline const char* ResolveNameInline(ArchiveEntry& entry, NP_afc& archive, int& index)
{
    int id = entry.unk08;
    static FUN_00aa5140 s_obj;
    const char* name = s_obj.FUN_00aa5230(id);
    return (const char*)((FUN_00af9ba0_shell*)(Archive*)archive)->FUN_00af96d0(index, (unsigned int)name);
}

}  // namespace fnv_00af7400

void* __cdecl FUN_00ec7230(void* dst, const void* src, unsigned int size);

struct S_00afea20_Arr
{
    int unk00;
    unsigned int* m_pBuffer;
    unsigned int m_uiSize;

    void FUN_0042fb60(unsigned int* pDst, unsigned int* pSrc, unsigned int ItemUpdateArray)
    {
        if (ItemUpdateArray <= 0)
            return;
        if (pDst < pSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(unsigned int));
        }
        else if (pDst > pSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(unsigned int));
        }
    }

    void RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray);
};

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_00af8e60
{
    ~FUN_00af8e60();
};
struct FUN_00afc680 : FUN_00af8e60
{
    virtual ~FUN_00afc680();
    static void operator delete(void* p)
    {
        __Dummy_00b6fef0(p, 0x1d0);
    }
};

extern MemoryManager g_memoryManager;
struct FUN_00afcdc0
{
    ~FUN_00afcdc0();
};
struct FUN_00afcd90 : FUN_00afcdc0
{
    virtual ~FUN_00afcd90();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct ArchiveStreamBase : public BSFile
{
    virtual void* FUN_00afce80(unsigned int flags);
};
struct StreamSecondary
{
    virtual void* FUN_00afce80(unsigned int flags);
};
struct ArchiveStreamFile : public ArchiveStreamBase, public StreamSecondary
{
    ArchiveStreamFile();
// @fnv 0x00afce80
    virtual void* FUN_00afce80(unsigned int flags);
};
ArchiveStreamFile::ArchiveStreamFile()
{}

namespace fnv_00af7800 {
struct RecursiveMutex
{
    unsigned debug, lockCount, recursionCount, owner, semaphore, spin;
};

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);

__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" char* __cdecl strrchr(const char*, int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
int __cdecl FUN_00af7d80(const char*);
struct LNode;
extern LNode* DAT_011f8160;

struct ArchiveDirectoryKey
{
    unsigned low, high;
    ArchiveDirectoryKey(const char*, int);
};

struct ArchiveFileMeta
{
    unsigned hashLow, hashHigh;
    unsigned offset, size;
    unsigned Offset()
    {
        return offset & 0x3fffffff;
    }
};

struct ArchiveDirectory
{
    unsigned hashLow, hashHigh, count;
    ArchiveFileMeta* files;
    unsigned Count()
    {
        return count;
    }
    ArchiveFileMeta* File(unsigned i)
    {
        return files + i;
    }
};

struct ArchiveRefBlock
{
    virtual void Unknown();
    virtual void DeleteThis();
    volatile long count;
    void Acquire()
    {
        InterlockedIncrement(&count);
    }
    void Release()
    {
        if (!InterlockedDecrement(&count))
            DeleteThis();
    }
};

struct PathArchive
{

    unsigned unk000;

    unsigned unk004;

    unsigned unk008;

    unsigned unk00c;

    unsigned unk010;

    unsigned unk014;

    unsigned unk018;

    unsigned unk01c;

    unsigned unk020;

    unsigned unk024;

    unsigned unk028;

    unsigned unk02c;

    unsigned unk030;

    unsigned unk034;

    unsigned unk038;

    unsigned unk03c;

    unsigned unk040;

    unsigned unk044;

    unsigned unk048;

    unsigned unk04c;

    unsigned unk050;

    unsigned unk054;

    unsigned unk058;

    unsigned unk05c;

    unsigned unk060;

    unsigned unk064;

    unsigned unk068;

    unsigned unk06c;

    unsigned unk070;

    unsigned unk074;

    unsigned unk078;

    unsigned unk07c;

    unsigned unk080;

    unsigned unk084;

    unsigned unk088;

    unsigned unk08c;

    unsigned unk090;

    unsigned unk094;

    unsigned unk098;

    unsigned unk09c;

    unsigned unk0a0;

    unsigned unk0a4;

    unsigned unk0a8;

    unsigned unk0ac;

    unsigned unk0b0;

    unsigned unk0b4;

    unsigned unk0b8;

    unsigned unk0bc;

    unsigned unk0c0;

    unsigned unk0c4;

    unsigned unk0c8;

    unsigned unk0cc;

    unsigned unk0d0;

    unsigned unk0d4;

    unsigned unk0d8;

    unsigned unk0dc;

    unsigned unk0e0;

    unsigned unk0e4;

    unsigned unk0e8;

    unsigned unk0ec;

    unsigned unk0f0;

    unsigned unk0f4;

    unsigned unk0f8;

    unsigned unk0fc;

    unsigned unk100;

    unsigned unk104;

    unsigned unk108;

    unsigned unk10c;

    unsigned unk110;

    unsigned unk114;

    unsigned unk118;

    unsigned unk11c;

    unsigned unk120;

    unsigned unk124;

    unsigned unk128;

    unsigned unk12c;

    unsigned unk130;

    unsigned unk134;

    unsigned unk138;

    unsigned unk13c;

    unsigned unk140;

    unsigned unk144;

    unsigned unk148;

    unsigned unk14c;

    unsigned unk150;

    unsigned unk154;

    ArchiveRefBlock reference;

    unsigned unk160;

    unsigned unk164;

    unsigned unk168;

    unsigned unk16c;

    unsigned unk170;

    unsigned unk174;

    unsigned unk178;

    unsigned unk17c;

    unsigned short types, reserved182;
    ArchiveDirectory* directories;

    unsigned unk188;

    unsigned unk18c;

    unsigned unk190;

    unsigned unk194;

    unsigned unk198;

    RecursiveMutex lock;

    unsigned char flags;

    ArchiveRefBlock* Ref()
    {
        return &reference;
    }

    unsigned Types()
    {
        return types;
    }

    bool FindHashEntry(ArchiveDirectoryKey*, unsigned*, bool);

    ArchiveDirectory* Directory(unsigned i)
    {
        return directories + i;
    }

    bool IsConcurrent()
    {
        return (flags & 32) ? true : false;
    }

    RecursiveMutex* Lock()
    {
        return &lock;
    }

    const char* FUN_00af96d0(unsigned, unsigned);
};

struct PathArchivePointer
{

    PathArchive* pointer;

    PathArchivePointer(const PathArchivePointer& p)
    {
        pointer = p.pointer;
        if (pointer)
            pointer->Ref()->Acquire();
    }

    PathArchivePointer(PathArchive* p)
    {
        pointer = p;
        if (pointer)
            pointer->Ref()->Acquire();
    }

    __forceinline ~PathArchivePointer()
    {
        if (pointer)
            pointer->Ref()->Release();
    }

    PathArchive* operator->() const
    {
        return pointer;
    }

    operator PathArchive*() const
    {
        return pointer;
    }

    PathArchivePointer& FUN_00afc770(const PathArchivePointer& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->Ref()->Release();
            pointer = other.pointer;
            if (pointer)
                pointer->Ref()->Acquire();
        }
        return *this;
    }
};

const char* SkipDataPrefix(const char*);

}  // namespace fnv_00af7800

__if_not_exists(MemMgrStand)
{
    struct MemMgrStand
    {
        void* Allocate(unsigned int auiSize);
        void Deallocate(void* apMem);
    };
}
extern MemMgrStand g_arcMemMgr;
struct ArchiveArray;
inline void* operator new(unsigned int, void* memory)
{
    return memory;
}
extern "C" char* __cdecl strstr(const char*, const char*);
struct FUN_00afd390
{
    unsigned int low;
    unsigned int high;
    FUN_00afd390(const char*, int);
    inline void* operator new(unsigned int size)
    {
        return g_arcMemMgr.Allocate(size);
    }
    inline void operator delete(void* memory)
    {
        g_arcMemMgr.Deallocate(memory);
    }
};
struct FUN_00afcce0
{
    virtual ~FUN_00afcce0();
    virtual FUN_00afd390** Allocate(unsigned int);
    FUN_00afd390** entries;
    unsigned int count;
    unsigned int capacity;
    FUN_00afcce0();
    inline void* operator new(unsigned int size)
    {
        return g_arcMemMgr.Allocate(size);
    }
    inline void operator delete(void* memory)
    {
        g_arcMemMgr.Deallocate(memory);
    }
    void InitArray(unsigned int allocated, unsigned int size)
    {
        entries = 0;
        count = 0;
        capacity = 0;
        if (size > allocated)
            allocated = size;
        if (allocated > 0)
        {
            entries = Allocate(allocated);
            capacity = allocated;
        }
        if (size > 0)
        {
            for (unsigned int i = 0; i < size; ++i)
                new (&entries[i]) FUN_00afd390*;
            count = size;
        }
    }
    void FUN_00a0d0c0(unsigned int, unsigned int);
    unsigned int FUN_00a11ee0()
    {
        if (count == capacity)
        {
            if (capacity == 0)
            {
                unsigned int initialCapacity = 4;
                entries = Allocate(initialCapacity);
                capacity = initialCapacity;
            }
            else
            {
                unsigned int newCapacity = capacity > 1024 ? capacity + 1024 : capacity * 2;
                FUN_00a0d0c0(newCapacity, count);
                capacity = newCapacity;
            }
        }
        ++count;
        return count - 1;
    }
    unsigned int FUN_00a11d20(FUN_00afd390* const& value)
    {
        unsigned int index = FUN_00a11ee0();
        for (unsigned int i = 0; i < 1; ++i)
            new (&entries[index + i]) FUN_00afd390*;
        entries[index] = value;
        return index;
    }
};
extern ArchiveArray* DAT_011f816c;
extern ArchiveArray* DAT_011f8168;
struct ArchiveListStream : BSFile
{
    inline unsigned int Read(void* buffer, unsigned int bytes)
    {
        unsigned int componentSize = 1;
        unsigned int bytesRead = BinaryRead(buffer, bytes, &componentSize, 1);
        return bytesRead;
    }
    inline unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int result = ((unsigned int(__cdecl*)(NiBinaryStream*, void*, unsigned int, unsigned int*,
                                                       unsigned int))m_pfnRead)(this, buffer, bytes, sizes, count);
        m_uiStreamFlags += result;
        return result;
    }
};

namespace archive_master_lookup {
using fnv_00af6540::Owner25;
using fnv_00af6340::Archive;

class ArchiveHandle
{
  public:
    Archive* object;
    ArchiveHandle(Archive* value)
    {
        object = value;
        if (object)
            object->rc.AcquireReference();
    }
    ~ArchiveHandle()
    {
        if (object)
            object->rc.DecRef();
    }
    operator Archive*() const
    {
        return object;
    }
    Archive* operator->() const
    {
        return object;
    }
};
extern fnv_00af6540::NiPointer<fnv_00af6540::Archive> DAT_011f8190[9];
extern fnv_00af6540::NiPointer<fnv_00af6540::Archive> DAT_011f81b4[9];
inline Archive* SelectMaster(int index)
{
    return reinterpret_cast<Archive*>(
        static_cast<fnv_00af6540::Archive*>(DAT_011f8190[index] ? DAT_011f8190[index] : DAT_011f81b4[index]));
}
}
