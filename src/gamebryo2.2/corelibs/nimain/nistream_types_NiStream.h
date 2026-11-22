// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NISTREAM_TYPES_H
#define FNV_NISTREAM_TYPES_H
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "layout_support.h"
class BSStreamHeader;
class NiBinaryStream;
class NiObjectGroup;
class ProcessorAffinityInfo;
class NiSearchPath;
class NiStream;
class NiStream__BackgroundLoadProcedure;
class NiTLargeObjectArray_NiFixedString_;
class NiTLargeObjectArray_NiPointer_NiObject___;
class NiTPrimitiveArray_NiObjectGroup___;
class NiTPrimitiveSet_unsigned_int_;
class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___;
class NiThread;
enum NiStream__ThreadStatus
{
    NiStream__ThreadStatus_IDLE = 0,
    NiStream__ThreadStatus_LOADING = 1,
    NiStream__ThreadStatus_CANCELLING = 2,
    NiStream__ThreadStatus_PAUSING = 3,
    NiStream__ThreadStatus_PAUSED = 4
};
enum NiThread__Priority
{
    NiThread__Priority_IDLE = 0,
    NiThread__Priority_LOWEST = 1,
    NiThread__Priority_BELOW_NORMAL = 2,
    NiThread__Priority_NORMAL = 3,
    NiThread__Priority_ABOVE_NORMAL = 4,
    NiThread__Priority_HIGHEST = 5,
    NiThread__Priority_TIME_CRITICAL = 6,
    NiThread__Priority_NUM_PRIORITIES = 7
};
enum NiProcessorAffinity__Processor
{
    NiProcessorAffinity__Processor_PROCESSOR_0 = 1,
    NiProcessorAffinity__Processor_PROCESSOR_1 = 2,
    NiProcessorAffinity__Processor_PROCESSOR_2 = 4,
    NiProcessorAffinity__Processor_PROCESSOR_3 = 8,
    NiProcessorAffinity__Processor_PROCESSOR_4 = 16,
    NiProcessorAffinity__Processor_PROCESSOR_5 = 32,
    NiProcessorAffinity__Processor_PROCESSOR_6 = 64,
    NiProcessorAffinity__Processor_PROCESSOR_7 = 128,
    NiProcessorAffinity__Processor_PROCESSOR_8 = 256,
    NiProcessorAffinity__Processor_PROCESSOR_9 = 512,
    NiProcessorAffinity__Processor_PROCESSOR_10 = 1024,
    NiProcessorAffinity__Processor_PROCESSOR_11 = 2048,
    NiProcessorAffinity__Processor_PROCESSOR_12 = 4096,
    NiProcessorAffinity__Processor_PROCESSOR_13 = 8192,
    NiProcessorAffinity__Processor_PROCESSOR_14 = 16384,
    NiProcessorAffinity__Processor_PROCESSOR_15 = 32768,
    NiProcessorAffinity__Processor_PROCESSOR_16 = 65536,
    NiProcessorAffinity__Processor_PROCESSOR_17 = 131072,
    NiProcessorAffinity__Processor_PROCESSOR_18 = 262144,
    NiProcessorAffinity__Processor_PROCESSOR_19 = 524288,
    NiProcessorAffinity__Processor_PROCESSOR_20 = 1048576,
    NiProcessorAffinity__Processor_PROCESSOR_21 = 2097152,
    NiProcessorAffinity__Processor_PROCESSOR_22 = 4194304,
    NiProcessorAffinity__Processor_PROCESSOR_23 = 8388608,
    NiProcessorAffinity__Processor_PROCESSOR_24 = 16777216,
    NiProcessorAffinity__Processor_PROCESSOR_25 = 33554432,
    NiProcessorAffinity__Processor_PROCESSOR_26 = 67108864,
    NiProcessorAffinity__Processor_PROCESSOR_27 = 134217728,
    NiProcessorAffinity__Processor_PROCESSOR_28 = 268435456,
    NiProcessorAffinity__Processor_PROCESSOR_29 = 536870912,
    NiProcessorAffinity__Processor_PROCESSOR_30 = 1073741824,
    NiProcessorAffinity__Processor_PROCESSOR_31 = -2147483648,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_0_THREAD_0 = 1,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_0_THREAD_1 = 2,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_1_THREAD_0 = 4,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_1_THREAD_1 = 8,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_2_THREAD_0 = 16,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_2_THREAD_1 = 32,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_0 = 3,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_1 = 12,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_2 = 48,
    NiProcessorAffinity__Processor_PROCESSOR_DONT_CARE = -1
};
#pragma pack(push, 4)
class BSStreamHeader
{
  public:
    unsigned int uiVersion;         // +0x0, 4 bytes
    char pAuthor[64];               // +0x4, 64 bytes
    char PluginMetadata[64];        // +0x44, 64 bytes
    char PluginMetadataHeader[64];  // +0x84, 64 bytes
    // void __cdecl BSStreamHeader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSStreamHeader) == 196);
FNV_STATIC_ASSERT(offsetof(BSStreamHeader, uiVersion) == 0);
FNV_STATIC_ASSERT(offsetof(BSStreamHeader, pAuthor) == 4);
FNV_STATIC_ASSERT(offsetof(BSStreamHeader, PluginMetadata) == 68);
FNV_STATIC_ASSERT(offsetof(BSStreamHeader, PluginMetadataHeader) == 132);
#pragma pack(push, 4)
class NiTPrimitiveArray_NiObjectGroup___ : public NiTArray<NiObjectGroup*, NiTMallocInterface<NiObjectGroup*> >
{
  public:
    // base NiTArray<NiObjectGroup *,NiTMallocInterface<NiObjectGroup *> > at +0x0, size 16
    // NiTPrimitiveArray<NiObjectGroup *>
    // void __cdecl NiTPrimitiveArray<NiObjectGroup *>::*()
    // NiTPrimitiveArray<NiObjectGroup *>& __cdecl NiTPrimitiveArray<NiObjectGroup *>::*(const NiTPrimitiveArray<NiObjectGroup *>&)
    // void __cdecl NiTPrimitiveArray<NiObjectGroup *>::*()
    // void __cdecl NiTPrimitiveArray<NiObjectGroup *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_NiObjectGroup___) == 16);
#pragma pack(push, 4)
class NiTLargeObjectArray_NiPointer_NiObject___
    : public NiTLargeArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >
{
  public:
    // base NiTLargeArray<NiPointer<NiObject>,NiTNewInterface<NiPointer<NiObject> > > at +0x0, size 24
    // NiTLargeObjectArray<NiPointer<NiObject> >
    // void __cdecl NiTLargeObjectArray<NiPointer<NiObject> >::*()
    // NiTLargeObjectArray<NiPointer<NiObject> >& __cdecl NiTLargeObjectArray<NiPointer<NiObject> >::*(const NiTLargeObjectArray<NiPointer<NiObject> >&)
    // void __cdecl NiTLargeObjectArray<NiPointer<NiObject> >::*()
    // void __cdecl NiTLargeObjectArray<NiPointer<NiObject> >::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTLargeObjectArray_NiPointer_NiObject___) == 24);
#pragma pack(push, 4)
class NiTLargeObjectArray_NiFixedString_ : public NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> >
{
  public:
    // base NiTLargeArray<NiFixedString,NiTNewInterface<NiFixedString> > at +0x0, size 24
    // NiTLargeObjectArray<NiFixedString>
    // void __cdecl NiTLargeObjectArray<NiFixedString>::*()
    // NiTLargeObjectArray<NiFixedString>& __cdecl NiTLargeObjectArray<NiFixedString>::*(const NiTLargeObjectArray<NiFixedString>&)
    // void __cdecl NiTLargeObjectArray<NiFixedString>::*()
    // void __cdecl NiTLargeObjectArray<NiFixedString>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTLargeObjectArray_NiFixedString_) == 24);
#pragma pack(push, 4)
class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
  public:
    unsigned int* m_pBase;               // +0x0, 4 bytes
    unsigned int m_uiAlloced;       // +0x4, 4 bytes  // src: FNV360_PDB +0x4 (old: m_uiElementCount)
    unsigned int m_uiUsed;  // +0x8, 4 bytes  // src: FNV360_PDB +0x8 (old: m_uiAllocatedCapacity)
    // NiTSet<unsigned int,NiTMallocInterface<unsigned int> >
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // unsigned int __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // unsigned int* __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // GetAt
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
    // bool __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // bool __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int, const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // Realloc
    // int __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // NiTSet<unsigned int,NiTMallocInterface<unsigned int> >& __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const NiTSet<unsigned int,NiTMallocInterface<unsigned int> >&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // void* __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_pBase) == 0);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_uiAlloced) == 4);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_uiUsed) == 8);
#pragma pack(push, 4)
class NiTPrimitiveSet_unsigned_int_ : public NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
  public:
    // base NiTSet<unsigned int,NiTMallocInterface<unsigned int> > at +0x0, size 12
    // NiTPrimitiveSet<unsigned int>
    // void __cdecl NiTPrimitiveSet<unsigned int>::*()
    // NiTPrimitiveSet<unsigned int>& __cdecl NiTPrimitiveSet<unsigned int>::*(const NiTPrimitiveSet<unsigned int>&)
    // void __cdecl NiTPrimitiveSet<unsigned int>::*()
    // void* __cdecl NiTPrimitiveSet<unsigned int>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet_unsigned_int_) == 12);
#pragma pack(push, 4)
class ProcessorAffinityInfo
{
  public:
    NiProcessorAffinity__Processor m_eProcessorAffinity;  // +0x0, 4 bytes
    unsigned int m_uiProcessorAffinityMask;               // +0x4, 4 bytes
    // ProcessorAffinityInfo
    // unsigned int __cdecl ProcessorAffinityInfo::*()
    // void __cdecl ProcessorAffinityInfo::*(unsigned int)
    // ProcessorAffinityInfo::Processor __cdecl ProcessorAffinityInfo::*()
    // void __cdecl ProcessorAffinityInfo::*(ProcessorAffinityInfo::Processor)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ProcessorAffinityInfo) == 8);
FNV_STATIC_ASSERT(offsetof(ProcessorAffinityInfo, m_eProcessorAffinity) == 0);
FNV_STATIC_ASSERT(offsetof(ProcessorAffinityInfo, m_uiProcessorAffinityMask) == 4);
#pragma pack(push, 4)
class NiStream
{
  public:
    void** m_ppVirtualMethodTable;                                     // +0x0, 4 bytes
    BSStreamHeader m_BSStreamHeader;                            // +0x4, 196 bytes  // src: FNV360_PDB +0x4 (old: m_kHeader)
    NiTPrimitiveArray_NiObjectGroup___ m_kGroups;  // +0xC8, 16 bytes  // src: FNV360_PDB +0xC8 (old: m_kObjectGroups)
    unsigned int m_uiNifFileVersion;                         // +0xD8, 4 bytes  // src: FNV360_PDB +0xD8 (old: m_uiNifVersion)
    unsigned int m_uiNifFileUserDefinedVersion;                         // +0xDC, 4 bytes  // src: FNV360_PDB +0xDC (old: StreamFileInfo)
    char m_acFileName[260];                         // +0xE0, 260 bytes  // src: FNV360_PDB +0xE0 (old: m_acInputFilePath)
    bool m_bSaveLittleEndian;                             // +0x1E4, 1 bytes  // src: FNV360_PDB +0x1E4 (old: m_bFirstStreamFlag)
    bool m_bSourceIsLittleEndian;                            // +0x1E5, 1 bytes  // src: FNV360_PDB +0x1E5 (old: m_bSecondStreamFlag)
    unsigned char layoutPadding1E6[2];
    NiSearchPath* m_pkSearchPath;                                             // +0x1E8, 4 bytes  // src: FNV360_PDB +0x1E8 (old: m_pSearchPath)
    NiTLargeObjectArray_NiPointer_NiObject___ m_kObjects;  // +0x1EC, 24 bytes  // src: FNV360_PDB +0x1EC (old: m_kThirdFollowingStreamField)
    NiTLargePrimitiveArray<unsigned int> m_kObjectSizes;          // +0x204, 24 bytes  // src: FNV360_PDB +0x204 (old: ObjectSerializationStream)
    NiTLargeObjectArray_NiPointer_NiObject___ m_kTopObjects;            // +0x21C, 24 bytes  // src: FNV360_PDB +0x21C (old: m_kTopLevelObjects)
    NiTLargeObjectArray_NiFixedString_ m_kFixedStrings;                       // +0x234, 24 bytes  // src: FNV360_PDB +0x234 (old: m_kStringTable)
    NiBinaryStream* m_pkIstr;                                     // +0x24C, 4 bytes  // src: FNV360_PDB +0x24C (old: m_pUnderlyingStream)
    NiBinaryStream* m_pkOstr;                                        // +0x250, 4 bytes  // src: FNV360_PDB +0x250 (old: m_pBackingStream)
    NiTPrimitiveSet_unsigned_int_ m_kLinkIDs;             // +0x254, 12 bytes  // src: FNV360_PDB +0x254 (old: m_kSecondFollowingStreamField)
    unsigned int m_uiLinkIndex;                                          // +0x260, 4 bytes  // src: FNV360_PDB +0x260 (old: StreamObjectIndex)
    NiTPrimitiveSet_unsigned_int_ m_kLinkIDBlocks;                   // +0x264, 12 bytes  // src: FNV360_PDB +0x264 (old: m_kSecondUnsignedIntSet)
    unsigned int m_uiLinkBlockIndex;                                       // +0x270, 4 bytes  // src: FNV360_PDB +0x270 (old: m_uiObjectIndexCount)
    NiTPointerMap<const NiObject*, unsigned int> m_kRegisterMap;        // +0x274, 16 bytes  // src: FNV360_PDB +0x274 (old: m_kObjectToIndexMap)
    unsigned short m_usNiAVObjectFlags;                                        // +0x284, 2 bytes  // src: FNV360_PDB +0x284 (old: m_usAVObjectFlags)
    unsigned short m_usNiTimeControllerFlags;                                  // +0x286, 2 bytes  // src: FNV360_PDB +0x286 (old: m_usTimeControllerFlags)
    unsigned short m_usNiPropertyFlags;                                        // +0x288, 2 bytes  // src: FNV360_PDB +0x288 (old: m_usPropertyFlags)
    unsigned char layoutPadding28A[2];
    NiStream__ThreadStatus m_eBackgroundLoadStatus;  // +0x28C, 4 bytes  // src: FNV360_PDB +0x28C (old: m_eStreamThreadStatus)
    bool m_bBackgroundLoadExitStatus;                          // +0x290, 1 bytes  // src: FNV360_PDB +0x290 (old: m_bThreadActive)
    unsigned char layoutPadding291[3];
    unsigned int m_uiLoad;                       // +0x294, 4 bytes  // src: FNV360_PDB +0x294 (old: StreamThreadContext)
    unsigned int m_uiLink;                   // +0x298, 4 bytes  // src: FNV360_PDB +0x298 (old: m_uiBackgroundLoadState)
    unsigned int m_uiPostLink;                  // +0x29C, 4 bytes  // src: FNV360_PDB +0x29C (old: BackgroundLoadThreadInfo)
    NiThread* m_pkThread;                      // +0x2A0, 4 bytes  // src: FNV360_PDB +0x2A0 (old: m_pBackgroundLoadThread)
    NiStream__BackgroundLoadProcedure* m_pkBGLoadProc;  // +0x2A4, 4 bytes  // src: FNV360_PDB +0x2A4 (old: BackgroundLoadTask)
    NiThread__Priority m_ePriority;                   // +0x2A8, 4 bytes  // src: FNV360_PDB +0x2A8 (old: m_eThreadPriority)
    ProcessorAffinityInfo m_kAffinity;       // +0x2AC, 8 bytes  // src: FNV360_PDB +0x2AC (old: m_kBackgroundLoadSemaphore)
    char m_acLastLoadedRTTI[260];                                 // +0x2B4, 260 bytes  // src: FNV360_PDB +0x2B4 (old: m_acLoadPath)
    unsigned int m_uiLastError;                        // +0x3B8, 4 bytes  // src: FNV360_PDB +0x3B8 (old: m_uiNativeThreadId)
    char m_acLastErrorMessage[260];                         // +0x3BC, 260 bytes  // src: FNV360_PDB +0x3BC (old: m_acSecondPathBuffer)
    char m_acFilePath[260];                           // +0x4C0, 260 bytes  // src: FNV360_PDB +0x4C0 (old: m_acFilePathBuffer)
    // NiStream
    // void __cdecl NiStream::*(NiObject*)
    // void __cdecl NiStream::*(NiObject*)
    // void __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*(unsigned int)
    // Load
    // Save
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*(bool)
    // bool __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // BackgroundLoadBegin
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // const ProcessorAffinityInfo& __cdecl NiStream::*()
    // void __cdecl NiStream::*(const ProcessorAffinityInfo&)
    // const NiThread::Priority __cdecl NiStream::*()
    // void __cdecl NiStream::*(const NiThread::Priority)
    // unsigned int __cdecl NiStream::*(const char*)
    // unsigned int __cdecl NiStream::*(unsigned int, unsigned int, unsigned int, unsigned int)
    // unsigned int __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned int)
    // unsigned int __cdecl NiStream::*()
    // const char* __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*(char*&)
    // void __cdecl NiStream::*(const char*)
    // void __cdecl NiStream::*(NiFixedString&)
    // void __cdecl NiStream::*(const NiFixedString&)
    // void __cdecl NiStream::*(NiFixedString&)
    // void __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned int)
    // NiObjectGroup* __cdecl NiStream::*(unsigned int)
    // unsigned int __cdecl NiStream::*(NiObjectGroup*)
    // NiBinaryStream& __cdecl NiStream::*()
    // NiBinaryStream& __cdecl NiStream::*()
    // void __cdecl NiStream::*(NiTexture*)
    // void __cdecl NiStream::*(const char*, NiPointer<NiTexture>&)
    // NiSearchPath* __cdecl NiStream::*()
    // void __cdecl NiStream::*(NiSearchPath*)
    // const char* __cdecl NiStream::*()
    // unsigned short __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned short)
    // unsigned short __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned short)
    // unsigned short __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned short)
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // int __cdecl NiStream::*(const char*, NiObject* __cdecl ()*)
    // void __cdecl NiStream::*(const char*)
    // void __cdecl NiStream::*(void __cdecl (NiStream&, NiObject*)*)
    // void __cdecl NiStream::*(void __cdecl (NiStream&, NiObject*)*)
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*(const char*)
    // const char* __cdecl NiStream::*()
    // void __cdecl NiStream::*(const char*)
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*(char*, unsigned int)
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*(NiAVObject*)
    // void __cdecl NiStream::*(char*)
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*(const char*)
    // unsigned int __cdecl NiStream::*(const NiFixedString&)
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // NiStream& __cdecl NiStream::*(const NiStream&)
    // void __cdecl NiStream::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiStream) == 1476);
FNV_STATIC_ASSERT(offsetof(NiStream, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiStream, m_BSStreamHeader) == 4);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kGroups) == 200);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNifFileVersion) == 216);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNifFileUserDefinedVersion) == 220);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acFileName) == 224);
FNV_STATIC_ASSERT(offsetof(NiStream, m_bSaveLittleEndian) == 484);
FNV_STATIC_ASSERT(offsetof(NiStream, m_bSourceIsLittleEndian) == 485);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkSearchPath) == 488);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kObjects) == 492);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kObjectSizes) == 516);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kTopObjects) == 540);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kFixedStrings) == 564);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkIstr) == 588);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkOstr) == 592);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kLinkIDs) == 596);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiLinkIndex) == 608);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kLinkIDBlocks) == 612);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiLinkBlockIndex) == 624);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kRegisterMap) == 628);
FNV_STATIC_ASSERT(offsetof(NiStream, m_usNiAVObjectFlags) == 644);
FNV_STATIC_ASSERT(offsetof(NiStream, m_usNiTimeControllerFlags) == 646);
FNV_STATIC_ASSERT(offsetof(NiStream, m_usNiPropertyFlags) == 648);
FNV_STATIC_ASSERT(offsetof(NiStream, m_eBackgroundLoadStatus) == 652);
FNV_STATIC_ASSERT(offsetof(NiStream, m_bBackgroundLoadExitStatus) == 656);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiLoad) == 660);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiLink) == 664);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiPostLink) == 668);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkThread) == 672);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkBGLoadProc) == 676);
FNV_STATIC_ASSERT(offsetof(NiStream, m_ePriority) == 680);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kAffinity) == 684);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acLastLoadedRTTI) == 692);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiLastError) == 952);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acLastErrorMessage) == 956);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acFilePath) == 1216);
#endif
