#include <windows.h>
#include <math.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00be0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00be5db0 (community match, verified in this file)
#include <stdio.h>
#include <string.h>
#include <string>
#include <locale>
#include <streambuf>
namespace f3m_00be5db0 {

// The game heap's free never throws; with that known, ~basic_string is nothrow and its scope-exit EH state stores go.
struct XMLHeap {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory) throw();
};

// VC8 std::basic_filebuf<char>::uflow, written on a stand-in of the filebuf layout.
class FileBuf5db0 : public std::basic_streambuf<char, std::char_traits<char> >
{
public:
    typedef std::char_traits<char> _Traits;
    typedef std::codecvt<char, char, _Traits::state_type> _Cvt;

    const _Cvt* _Pcvt;              // 0x3c
    char _Mychar;                   // 0x40
    bool _Wrotesome;                // 0x41
    _Traits::state_type _State;     // 0x44
    bool _Closef;                   // 0x48
    FILE* _Myfile;                  // 0x4c

    int FUN_00be5db0();
};

int FileBuf5db0::FUN_00be5db0()
{
    if (gptr() != 0
        && gptr() < egptr())
        return (_Traits::to_int_type(*_Gninc()));
    else if (_Myfile == 0)
        return (_Traits::eof());
    else if (_Pcvt == 0)
    {
        char _Ch;
        int _Meta;
        if ((_Meta = fgetc(_Myfile)) == EOF)
            return (_Traits::eof());
        _Ch = (char)_Meta;
        return (_Traits::to_int_type(_Ch));
    }
    else
    {
        std::string _Str;

        for (; ; )
        {
            char _Ch, *_Dest;
            const char *_Src;
            ptrdiff_t _Nleft;
            int _Meta = fgetc(_Myfile);

            if (_Meta == EOF)
                return (_Traits::eof());

            _Str.append(1, (char)_Meta);
            switch (_Pcvt->in(_State,
                &*_Str.begin(), &*_Str.begin() + _Str.size(), _Src,
                &_Ch, &_Ch + 1, _Dest))
            {
            case std::codecvt_base::partial:
            case std::codecvt_base::ok:
                if (_Dest != &_Ch)
                {
                    for (_Nleft = &*_Str.begin() + _Str.size() - _Src;
                        0 < _Nleft; )
                        ungetc(_Src[--_Nleft], _Myfile);
                    return (_Traits::to_int_type(_Ch));
                }
                else
                    _Str.erase((size_t)0,
                        (size_t)(_Src - &*_Str.begin()));
                break;

            case std::codecvt_base::noconv:
                if (_Str.size() < sizeof (char))
                    break;

                memcpy_s(&_Ch, sizeof (char), &*_Str.begin(),
                    sizeof (char));
                return (_Traits::to_int_type(_Ch));

            default:
                return (_Traits::eof());
            }
        }
    }
}
}   // namespace f3m_00be5db0

// @f3 0x00be5840 (community match, verified in this file)
#include <string.h>
namespace f3m_00be5840 {
namespace Task2415 {
struct CharTraitsQ
{
    static bool eq(const char& _Left, const char& _Right)
    {
        return _Left == _Right;
    }
    static int FUN_004b20a0(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
};

struct StringQ
{
    enum
    {
        _BUF_SIZE = 16
    };
    int _Alval;
    union
    {
        char _Buf[_BUF_SIZE];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

    enum { npos = -1 };

    const char* FUN_004249b0() const
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }

    unsigned int FUN_00be5840(const char* _Ptr, unsigned int _Off, unsigned int _Count) const;
};

// @fnv 0x00a0c300
// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::rfind | Tile.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _Ptr, _Off, _Count
unsigned int StringQ::FUN_00be5840(const char* _Ptr, unsigned int _Off, unsigned int _Count) const
{
    if (_Count == 0)
        return (_Off < _Mysize ? _Off : _Mysize);
    if (_Count <= _Mysize)
    {
        const char* _Uptr = FUN_004249b0() + (_Off < _Mysize - _Count ? _Off : _Mysize - _Count);
        for (;; --_Uptr)
            if (CharTraitsQ::eq(*_Uptr, *_Ptr) && CharTraitsQ::FUN_004b20a0(_Uptr, _Ptr, _Count) == 0)
                return (_Uptr - FUN_004249b0());
            else if (_Uptr == FUN_004249b0())
                break;
    }

    return (npos);
}

}
}   // namespace f3m_00be5840

// @f3 0x00be5630 (community match, verified in this file)
namespace f3m_00be5630 {
struct FUN_00be5630_Rec {
    int first;
};

struct FUN_00be5630_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
    int unk24;
    int unk28;
    int unk2C;
    FUN_00be5630_Rec* unk30;
    int FUN_00be5630();
};

// pdb: FutErrorC::FutErrorC | lastError.obj | fnv360_0822_debug, objrun_open, low
int FUN_00be5630_Obj::FUN_00be5630()
{
    if (*unk20 != 0)
        return unk30->first;
    return 0;
}
}   // namespace f3m_00be5630

// @f3 0x00bfe9f0 (community match, verified in this file)
namespace f3m_00bfe9f0 {
namespace f3m_00bfe9f0 {

struct Memory {
    void FUN_0086ba60(void*);
};
extern Memory DAT_01090a78;

struct Text {
    char* text;
    unsigned short length;
    unsigned short capacity;

    ~Text() {
        if (text)
            DAT_01090a78.FUN_0086ba60(text);
        text = 0;
        capacity = 0;
        length = 0;
    }
};

struct FUN_00bfe9f0 {
    unsigned char pad[0x38];
    Text text;

    ~FUN_00bfe9f0();
};

FUN_00bfe9f0::~FUN_00bfe9f0()
{
}

}
}   // namespace f3m_00bfe9f0

// @f3 0x00bee440 (community match, verified in this file)
namespace f3m_00bee440 {


struct AnimNode;
struct Pending {
    AnimNode* unk00;
    Pending* unk04;
    Pending():unk00(0),unk04(0) {}
    ~Pending();
    void FUN_0049fac0(AnimNode*);
    void FUN_006c8220();
};
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct Property {
    int unk00,unk04;
    float unk08;
    void* unk0c;
    void Tile_Value_ClearActions();
    void Tile_Value_CalculateValue(bool);
    __forceinline void Set(float f) {
        bool changed = unk08 != f || unk0c != 0;
        unk08 = f;
        if(unk0c) { DAT_01090a78.FUN_0086ba60(unk0c); unk0c=0; }
        Tile_Value_ClearActions();
        Tile_Value_CalculateValue(changed);
    }
};
struct Widget {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual unsigned v3();
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
    void* unk2c;
    Property* FUN_00bee080(unsigned);
    Property* FUN_00bece90(unsigned);
    void FUN_00bee190(unsigned,float,bool);
    void FUN_00bead50(void*,float);
    __forceinline float GetFloat(unsigned id){Property* p=FUN_00bece90(id);return p?p->unk08:0.0f;}
};
struct Animation {
    float unk00,unk04;
    unsigned unk08;
    float unk0c;
    unsigned unk10;
    Widget* unk14;
    unsigned unk18;
};
struct AnimNode {
    Animation* unk00;
    AnimNode* unk04;
    void FUN_00421610(AnimNode**);
};
extern AnimNode DAT_011796a8;
struct Names { bool FUN_00bea7b0(const char*,unsigned*); };
extern Names DAT_0106a3b4;
unsigned __cdecl FUN_00bea9e0(const char*);
__forceinline unsigned NameId(const char* name){unsigned key=0x80000000;DAT_0106a3b4.FUN_00bea7b0(name,&key);return key;}

float __cdecl FUN_00475740(float,float,float,float,float);
Pending::~Pending() { FUN_006c8220(); }
__forceinline float Pulse(float start,float end,float low,float high,float progress) {
 return start+(end-start)*((progress-low)/(double(high)-low));
}
// pdb: Tile::UpdateFadeControls | Tile.obj | fnv360_0822_retail, uconst, low
void FUN_00bee440() {
    if (!DAT_011796a8.unk04 && !DAT_011796a8.unk00) return;
    Pending pending;
    for (AnimNode* node=&DAT_011796a8; node; node=node->unk04) {
        if (!node->unk00) break;
        float end=node->unk00->unk04;
        float start=node->unk00->unk00;
        unsigned mode=node->unk00->unk18;
        unsigned id=node->unk00->unk10;
        float progress;
        switch(mode) {
        case 0: {
            unsigned ticks=GetTickCount();
            progress=(ticks-node->unk00->unk08)/node->unk00->unk0c;
            if (!(progress < 1.0f)) progress=1.0f;
            if(node->unk00->unk14->v3()==904 && id==4009) {
                float alpha=(start+(end-start)*progress)/255.0;
                void* object=node->unk00->unk14->unk2c;
                node->unk00->unk14->FUN_00bead50(object,alpha);
            }
            float value=start+(end-start)*progress;
            Property* prop=node->unk00->unk14->FUN_00bee080(id);
            if(prop) prop->Set(value);
            if(progress>=1.0f) pending.FUN_0049fac0(node);
            break;
        }
        case 1: case 2: case 3: {
            float count=node->unk00->unk14->GetFloat(NameId("_FlashCount"));
            float total=node->unk00->unk14->GetFloat(NameId("_TotalFlashCount"));
            unsigned ticks=GetTickCount();
            progress=(ticks-node->unk00->unk08)/node->unk00->unk0c;
            if(progress>=1.0f) {
                if((mode==2 && count<3.0f)||(mode==3 && count<total)||mode==1) {
                    node->unk00->unk08=GetTickCount();
                    progress=0.0f;
                }
                if(mode==2 || mode==3) {
                    node->unk00->unk14->FUN_00bee190(FUN_00bea9e0("_FlashCount"),(float)(count+1.0),true);
                    if(mode==2) {
                        if(count>3.0f) node->unk00->unk14->FUN_00bee190(id,end,true);
                    } else if(mode==3) {
                        if(count>total) {
                            node->unk00->unk14->FUN_00bee190(id,start,true);
                            pending.FUN_0049fac0(node);
                        }
                    }
                }
            }
            if(mode==2 && count>=3.0f) {
                float ramp=start+(end-start)*progress;
                float value=end<ramp?end:ramp;
                node->unk00->unk14->FUN_00bee190(id,value,true);
                if(ramp>=end) pending.FUN_0049fac0(node);
            } else {
                float wave=1.0f-(float)fabs((float)(progress*2.0f-1.0f));
                float value=start+(end-start)*wave;
                Property* target=node->unk00->unk14->FUN_00bee080(id);
                if(target) target->Set(value);
            }
            break;
        }
        case 4: {
            unsigned ticks=GetTickCount();
            Animation* anim=node->unk00;
            progress=(ticks-anim->unk08)/anim->unk0c;
            if(progress<0.16666f) {
                float value=Pulse(start,end,0.0f,0.16666f,progress);
                Property* prop=anim->unk14->FUN_00bee080(id);
                if(prop) prop->Set(value);
            } else if(progress<double(0.83334f)) {
                anim->unk14->FUN_00bee190(id,end,true);
            } else if(progress>=1.0f) {
                anim->unk14->FUN_00bee190(id,start,true);
                pending.FUN_0049fac0(node);
            } else {
                anim->unk14->FUN_00bee190(id,FUN_00475740(end,start,0.83334f,1.0f,progress),true);
            }
            break;
        }
        }
    }
    for(Pending* p=&pending;p;p=p->unk04) {
        AnimNode* item=p->unk00;
        if(!item) break;
        AnimNode* copy=item;
        DAT_011796a8.FUN_00421610(&copy);
        DAT_01090a78.FUN_0086ba60(item);
    }
    pending.FUN_006c8220();
}



}   // namespace f3m_00bee440

// @f3 0x00be1e20 (community match, verified in this file)
#include <string>
#include <xutility>
namespace f3m_00be1e20 {
// std::vector<Elem>::erase(iterator _First, iterator _Last) from the VS2005 <vector> (release, _SECURE_SCL on,
// no iterator debugging): 44-byte Elem holding a std::string at +0x10; stdext::unchecked_copy is the out-of-line
// instance 0x00be1a80 and std::_Destroy_range the out-of-line instance 0x005944c0. Fresh from the header form.

namespace f3m_00be1e20 {

struct Elem {
    int unk00, unk04, unk08, unk0c;
    std::string text;
};

struct Vec;

// _Vector_const_iterator / _Vector_iterator with _SECURE_SCL: the container pointer, then the element pointer.
struct IterBase {
    const Vec* _Mycont;
};

struct Iter : IterBase {
    Elem* _Myptr;
    bool operator==(const Iter& _Right) const
    {
        _SCL_SECURE_VALIDATE(this->_Mycont != NULL && this->_Mycont == _Right._Mycont);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const Iter& _Right) const { return !(*this == _Right); }
};

struct Alloc {
    char unk00;
};

Elem* __cdecl FUN_00be1a80(Elem* _First, Elem* _Last, Elem* _Dest);                       // stdext::unchecked_copy
void __cdecl FUN_005944c0(Elem* _First, Elem* _Last, Alloc& _Al, std::_Nonscalar_ptr_iterator_tag);   // std::_Destroy_range

struct Vec {
    Alloc _Alval;
    Elem* _Myfirst;
    Elem* _Mylast;
    Elem* _Myend;
    void _Destroy(Elem* _First, Elem* _Last) { FUN_005944c0(_First, _Last, _Alval, std::_Ptr_cat(_First, _Last)); }
    Iter FUN_00be1e20(Iter _First, Iter _Last);   // erase
};

// pdb: BSTSmallArrayHeapAllocatorCore::Adopt | BSTSmallArray.obj | tesv_win, objopen_prop, low
Iter Vec::FUN_00be1e20(Iter _First, Iter _Last)
{
    if (_First != _Last) {
        Elem* _Ptr = FUN_00be1a80(_Last._Myptr, _Mylast, _First._Myptr);
        _Destroy(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}

}
}   // namespace f3m_00be1e20
