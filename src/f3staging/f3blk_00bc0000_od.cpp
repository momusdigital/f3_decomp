// src/f3staging/f3blk_00bc0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bcb0e0 (community match, verified in this file)
#include <intrin.h>

namespace ArchiveLookupB0E0 {

struct RefCountedArchive {

    virtual void Reserved();

    virtual void Destroy();

    long references;

};

struct __declspec(align(8)) PathKey {

    union {

        unsigned __int64 hash;

        struct { unsigned int low, high; } words;

    };

};

struct ArchiveEntry { unsigned int unk00, unk04, unk08, flags; };

struct ArchiveGroup { unsigned int unk00, unk04, unk08; ArchiveEntry* entries; };

struct ArchiveObject {

    bool FUN_00bc95f0(const PathKey*, int*, int);

    bool FUN_00bc97a0(int, PathKey*, int*, int, int);

    RefCountedArchive* RefCount() {

        return reinterpret_cast<RefCountedArchive*>(reinterpret_cast<char*>(this) + 0x158);

    }

    ArchiveGroup*& Groups() {

        return *reinterpret_cast<ArchiveGroup**>(reinterpret_cast<char*>(this) + 0x184);

    }

};

struct ArchiveLink { ArchiveObject* object; ArchiveLink* next; };

extern ArchiveLink* DAT_011786f0;

extern long (__stdcall *DAT_00d9b068)(long*);

extern long (__stdcall *DAT_00d9b064)(long*);

void* __cdecl ArchiveManager_TrimFileName(void*);

void __cdecl FUN_00bccca0(void*, PathKey*, PathKey*);

struct ScopedArchive {

    ArchiveObject* object;

    __forceinline ScopedArchive(ArchiveObject* value) : object(value) {

        if (object) {

            DAT_00d9b068(&object->RefCount()->references);

        }

    }

    __forceinline ~ScopedArchive() {

        if (object) {

            RefCountedArchive* counter = object->RefCount();

            if (DAT_00d9b064(&counter->references) == 0) {

                counter->Destroy();

            }

        }

    }

};

}

// pdb: ArchiveManager::InvalidateFile | Archive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apFileName
bool __cdecl FUN_00bcb0e0(void* request)

{

    using namespace ArchiveLookupB0E0;

    if (DAT_011786f0) {

        PathKey groupKey;

        PathKey entryKey;

        void* path = ArchiveManager_TrimFileName(request);

        FUN_00bccca0(path, &groupKey, &entryKey);

        ArchiveLink* link = DAT_011786f0;

        while (link) {

            ArchiveObject* archive = link->object;

            ScopedArchive hold(archive);

            if (archive) {

                int groupIndex;

                if (archive->FUN_00bc95f0(&groupKey, &groupIndex, 0)) {

                    const int group = groupIndex;

                    int entryIndex;

                    if (archive->FUN_00bc97a0(group, &entryKey, &entryIndex, 0, 0)) {

                        ArchiveGroup* const& groups = archive->Groups();

                        _ReadWriteBarrier();

                        int offset = entryIndex * static_cast<int>(sizeof(ArchiveEntry));

                        int groupOffset = group * static_cast<int>(sizeof(ArchiveGroup));
                        offset += reinterpret_cast<int>(reinterpret_cast<ArchiveGroup*>(reinterpret_cast<char*>(groups) + groupOffset)->entries);

                        reinterpret_cast<ArchiveEntry*>(offset)->flags &= 0x80000000u;

                        return true;

                    }

                }

            }

            link = link->next;

        }

    }

    return false;

}

// @f3 0x00bc7610 (community match, verified in this file)
namespace f3m_00bc7610 {
struct FUN_00bc7610_Owner
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual double Slot3(float value);
    float m_04;
    float* m_08;
    float* m_0c;
    unsigned char m_10;
    float FUN_00bc7180();
    void FUN_00bc7380(int flag);
    float FUN_00bc7610();
};

// pdb: SymGen::Next | RobertDavies_Random.obj | fnv360_0822_retail, vtable, medium
float FUN_00bc7610_Owner::FUN_00bc7610()
{
    if (m_10 != 0)
        FUN_00bc7380(1);
    int idx;
    float scale;
    float x;
    float tmp;
    float v;
    do
    {
        scale = 1.0f;
        x = FUN_00bc7180();
        if (x > 0.5f)
        {
            scale = -1.0f;
            x = 1.0f - x;
        }
        idx = (int)(x * m_04);
        float a = m_08[idx];
        tmp = a + (m_08[idx + 1] - a) * FUN_00bc7180();
        v = FUN_00bc7180() * m_0c[idx];
    } while (v >= m_0c[idx + 1] && v >= Slot3(tmp));
    return tmp * scale;
}
}   // namespace f3m_00bc7610

// @f3 0x00bd1850 (community match, verified in this file)
void* operator new(unsigned int,void* p) { return p; }
#include <string.h>
extern "C" unsigned long __readfsdword(unsigned long);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" unsigned long _tls_index;
extern bool DAT_01179154;
struct ThreadState {
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
 unsigned unk158;
 unsigned unk15c;
 unsigned unk160;
 unsigned unk164;
 unsigned unk168;
 unsigned unk16c;
 unsigned unk170;
 unsigned unk174;
 unsigned unk178;
 unsigned unk17c;
 unsigned unk180;
 unsigned unk184;
 unsigned unk188;
 unsigned unk18c;
 unsigned unk190;
 unsigned unk194;
 unsigned unk198;
 unsigned unk19c;
 unsigned unk1a0;
 unsigned unk1a4;
 unsigned unk1a8;
 unsigned unk1ac;
 unsigned unk1b0;
 unsigned unk1b4;
 unsigned unk1b8;
 unsigned unk1bc;
 unsigned unk1c0;
 unsigned unk1c4;
 unsigned unk1c8;
 unsigned unk1cc;
 unsigned unk1d0;
 unsigned unk1d4;
 unsigned unk1d8;
 unsigned unk1dc;
 unsigned unk1e0;
 unsigned unk1e4;
 unsigned unk1e8;
 unsigned unk1ec;
 unsigned unk1f0;
 unsigned unk1f4;
 unsigned unk1f8;
 unsigned unk1fc;
 unsigned unk200;
 unsigned unk204;
 unsigned unk208;
 unsigned unk20c;
 unsigned unk210;
 unsigned unk214;
 unsigned unk218;
 unsigned unk21c;
 unsigned unk220;
 unsigned unk224;
 unsigned unk228;
 unsigned unk22c;
 unsigned unk230;
 unsigned unk234;
 unsigned unk238;
 unsigned unk23c;
 unsigned unk240;
 unsigned unk244;
 unsigned unk248;
 unsigned unk24c;
 unsigned unk250;
 unsigned unk254;
 unsigned unk258;
 unsigned unk25c;
 unsigned unk260;
 unsigned unk264;
 unsigned unk268;
 unsigned unk26c;
 unsigned unk270;
 unsigned unk274;
 unsigned unk278;
 unsigned unk27c;
 unsigned unk280;
 unsigned unk284;
 unsigned unk288;
 unsigned unk28c;
 unsigned unk290;
 unsigned unk294;
 unsigned context;
};
extern __declspec(thread) unsigned tlsContext;
struct MemoryScope { unsigned previous; MemoryScope(unsigned v){previous=tlsContext;tlsContext=v;} ~MemoryScope(){tlsContext=previous;} };
struct Point3 { float x,y,z; };
struct FUN_00bd0770 {
 char* name; char nameBuffer[260]; char* filename; char filenameBuffer[260];
 float minDistance,maxDistance; Point3 position; unsigned flags; float gain,frequency; unsigned unk230,unk234,unk238;
 FUN_00bd0770();
 ~FUN_00bd0770() { name=0;filename=0;minDistance=maxDistance=gain=frequency=0;flags=unk230=unk234=unk238=0; }
 FUN_00bd0770& FUN_00bd0830(const FUN_00bd0770&);
};
extern const Point3 DAT_0108ec68;
FUN_00bd0770::FUN_00bd0770() {
 minDistance=maxDistance=0.0f;
 nameBuffer[0]=0; filenameBuffer[0]=0; name=nameBuffer; filename=filenameBuffer;
 position=DAT_0108ec68;
 flags=0;gain=frequency=0.0f;unk230=unk234=unk238=0;
}
__declspec(noinline) FUN_00bd0770& FUN_00bd0770::FUN_00bd0830(const FUN_00bd0770& b) {
 nameBuffer[0]=0;filenameBuffer[0]=0;
 if(b.name){char* d=name;const char* s=b.name;while((*d++=*s++)!=0){}}
 if(b.filename){char* d=filename;const char* s=b.filename;while((*d++=*s++)!=0){}}
 minDistance=b.minDistance;maxDistance=b.maxDistance;position=b.position;flags=b.flags;gain=b.gain;frequency=b.frequency;unk230=b.unk230;unk234=b.unk234;unk238=b.unk238;return *this;
}
struct FUN_00bd0910 {
 unsigned id; float volume,pitch; unsigned flags,category; bool active;
 FUN_00bd0770 debug;
 FUN_00bd0910() { id=0;volume=0;flags=0;category=0;active=false; }
 FUN_00bd0910(unsigned i,unsigned f,float p,unsigned c,bool a) {id=i;volume=1;pitch=p;flags=f;category=c;active=a;}
 FUN_00bd0910(const FUN_00bd0910&);
 void SetDebug(FUN_00bd0770 value) {debug.FUN_00bd0830(value);}
 FUN_00bd0910& operator=(const FUN_00bd0910& b) { id=b.id;volume=b.volume;pitch=b.pitch;flags=b.flags;category=b.category;active=b.active;debug.FUN_00bd0830(b.debug);return *this; }
};
struct Sound {
 virtual void v00(); virtual bool IsActive(); virtual void v08(); virtual void v0c(); virtual float Pitch();
 virtual void v14();
 virtual void v18();
 virtual void v1c();
 virtual void v20();
 virtual void v24();
 virtual void v28();
 virtual void v2c();
 virtual void v30();
 virtual void v34();
 virtual void v38();
 virtual void v3c();
 virtual void v40();
 virtual void v44();
 virtual void v48();
 virtual void v4c();
 virtual void v50();
 virtual Point3* Position(Point3*);
 unsigned unk004;
 unsigned unk008;
 unsigned unk00c;
 unsigned unk010;
 unsigned unk014;
 unsigned short unk018; unsigned short unk01a;
 unsigned short unk01c; unsigned short unk01e;
 unsigned unk020;
 unsigned unk024;
 unsigned unk028;
 unsigned unk02c;
 unsigned unk030;
 unsigned short unk034;
 char filename[260];
 unsigned short unk13a;
 float unk13c;
 float unk140;
 unsigned unk144;
 unsigned unk148;
 unsigned unk14c;
 float unk150;
 bool FUN_00bd7880(); bool FUN_00bd7890();
 double Saturate150() const { float value=unk150>3.4028234663852886e37?-1.0f:unk150; return value; }
 double Saturate140() const { float value=unk140>3.4028234663852886e37?-1.0f:unk140; return value; }
 double Saturate13c() const { float value=unk13c>3.4028234663852886e37?-1.0f:unk13c; return value; }
};
struct Entry {Entry* next;unsigned key;FUN_00bd0910* value;};
struct Map { virtual void v00(); virtual unsigned Hash(unsigned); virtual bool Equals(unsigned,unsigned); unsigned unk04;Entry** buckets;unsigned unk0c;
 __declspec(noinline) bool FUN_00bea7b0(unsigned key,FUN_00bd0910** out){unsigned h=Hash(key);for(Entry* e=buckets[h];e;e=e->next)if(Equals(key,e->key)){*out=e->value;return true;}return false;}
 void FUN_00880f70(unsigned,FUN_00bd0910*); };
struct Audio {
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
 Map map;
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
 unsigned lock;
 void FUN_00880f70(unsigned,FUN_00bd0910*);
 void FUN_00bd1850(unsigned,Sound*);
};
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
// pdb: BSAudioManager::SetVoiceState | BSAudioManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiID, apSound
void Audio::FUN_00bd1850(unsigned key,Sound* sound) {
 MemoryScope context(11);
 FUN_00bd0910 info;
 FUN_00bd0770 debug;
 FUN_00bd0770 staging;
 Point3 point;
 bool debugging=DAT_01179154;
 if(sound) {
  unsigned category=sound->unk014; unsigned flags=sound->unk008; unsigned id=sound->unk004;
  float pitch=sound->Pitch();
  info=FUN_00bd0910(id,flags,pitch,category,sound->IsActive());
  if(debugging) {
   memset(&debug,0,sizeof(debug));
   if(debug.filename!=debug.filenameBuffer)debug.filename=debug.filenameBuffer;
   const char* filename=sound->filename;
   if(filename) strcpy_s(debug.filename,260,filename); else strcpy_s(debug.filename,260,"NotTESSound");
   if(sound->FUN_00bd7880()||sound->FUN_00bd7890()) {
    debug.position.z=sound->Saturate150();
    debug.position.x=sound->Position(&point)->x;debug.position.y=sound->Position(&point)->y;debug.minDistance=sound->Saturate140();debug.maxDistance=sound->Saturate13c();
   } else { debug.position.z=0; debug.position.x=0; debug.position.y=0; debug.minDistance=0; debug.maxDistance=0; }
   debug.unk230=sound->unk018;debug.unk234=sound->unk01c;debug.unk238=sound->unk01e;
  }
 }
 EnterCriticalSection(&lock);
 FUN_00bd0910* result=0;
 if(map.FUN_00bea7b0(key,&result)) {
  if(debugging) { result->SetDebug(debug); }
  result->id=info.id;result->volume=info.volume;result->pitch=info.pitch;result->flags=info.flags;result->category=info.category;result->active=info.active;
 } else {
  void* memory=DAT_01090a78.FUN_0086b930(sizeof(FUN_00bd0910));
  result=memory?new(memory) FUN_00bd0910(info):0;
  if(debugging) { result->SetDebug(debug); }
  map.FUN_00880f70(key,result);
 }
 LeaveCriticalSection(&lock);
}
