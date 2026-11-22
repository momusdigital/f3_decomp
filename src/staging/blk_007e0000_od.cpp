#include "f3_common.h"
// src/staging/blk_007e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct Flt
{
    operator unsigned int();
};

struct GO
{
    void* operator=(void*);
};

namespace fnv_007fd640 {
struct Flt
{
    operator unsigned int();
};

}  // namespace fnv_007fd640

struct GameTimerRecord
{
    unsigned int GetTime() const;
};

struct ModelLoader
{
    void QueueModelLoad(char*, bool, unsigned int);
};
struct Loader_S
{
    void* m_p;
    ModelLoader* operator->();
};
// If g_011db63c is nonzero, calls the model loader with DAT_011a0bb0, true, true, then sets g_011db63c to 0.
// @f3 0x00452cd0 (community match, verified in this file)
struct A1450MemoryManager { void Deallocate(void*); };
extern A1450MemoryManager DAT_011f6238;
struct FUN_00cbc810_cls { void RemoveKey(unsigned int* key); };
struct Node_452cd0 {
    int unk00, unk04;
    void* ptr08;
};
struct FUN_007ffe00_Class {
    int unk00;
    FUN_00cbc810_cls m_map;
    void FUN_007ffe00(void* p);
};
// pdb: TESContainer::RemoveContainerObject | TESContainer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apCObj
void FUN_007ffe00_Class::FUN_007ffe00(void* p) {
    Node_452cd0* node = (Node_452cd0*)p;
    if (node) {
        m_map.RemoveKey((unsigned int*)&p);
        DAT_011f6238.Deallocate(node->ptr08);
        DAT_011f6238.Deallocate(node);
    }
}


struct Tile
{
    void __thiscall Set(int, int);
};
struct Menu
{
    void __thiscall LoadMenuData();
};

struct SoundPlaybackHandle
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    ~SoundPlaybackHandle();
};

struct BSSoundHandleEx
{
    SoundPlaybackHandle base;
    ~BSSoundHandleEx();
    bool Play(bool);
};

struct BSAudio
{
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};

template <class T> class NiPointer7FD
{
  public:
    T* Get() const;

    T* m_pObject;
};

struct NiNode;
template <class T> class NiPtrS
{
  public:
    T* m_pObject;
    ~NiPtrS();
    NiPtrS<T>& operator=(T* object);
};

struct Entry;
struct ValueX
{
    void Clear();
    void Copy(int, void*, int);
    void SetFloat(int, float);
    void Finish(int);
};
struct MenuX
{
    struct TileX* Create(struct TileX*, const char*, int);
};
struct TileX
{
    MenuX* GetMenu();
    void* GetValue(int);
    void Set(int, int);
    void Set(int, const char*, bool);
    float GetFloat(int);
    ValueX* GetAction(int);
};
struct Entry
{
    TileX* tile;
    int data;
    int extra;
    Entry(TileX*, int*);
};

template <class T> struct WXPointer
{
    T* m_pObject;

    WXPointer(T* apObject);
    ~WXPointer();
    WXPointer& operator=(T* apObject);
};

struct Accum
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Accum(int, unsigned int, unsigned int);
    void SetEnabled(bool);
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
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
};
struct Ref
{
    void* object;
    Ref(void* = 0);
    ~Ref();
    Ref& operator=(void*);
    operator Accum*() const;
};
