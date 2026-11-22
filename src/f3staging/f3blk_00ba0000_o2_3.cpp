// src/f3staging/f3blk_00ba0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00baea20 (community match, verified in this file)
#include <string.h>
namespace f3m_00baea20 {
namespace Lighting1804 {
struct Heap { void FUN_0086ba60(void*); }; extern Heap DAT_01090a78;
struct Allocator { Allocator() {} Allocator(const Allocator&) {} void deallocate(char* p,unsigned) { DAT_01090a78.FUN_0086ba60(p); } };
struct StringBase { Allocator allocator; StringBase(Allocator a=Allocator()):allocator(a) {} };
struct String:StringBase {
    union { char buffer[16]; char* ptr; } data;
    unsigned size,capacity;
    String& FUN_0042f100(const char*,unsigned);
    String(const char* text):StringBase() { Tidy(); FUN_0042f100(text,strlen(text)); }
    ~String() { Tidy(true); }
    void Tidy(bool built=false) { if(built && capacity>=16) allocator.deallocate(data.ptr,capacity+1); capacity=15;size=0;data.buffer[0]=0; }
};
struct RuntimeError {
    virtual ~RuntimeError();
    const char* whatText; int doFree;
    String message;
};
struct FUN_00ba3920:RuntimeError {
    FUN_00ba3920(const String&,bool);
    virtual ~FUN_00ba3920();
};
struct Parser { int FUN_00ba92d0(); float FUN_00ba92a0(); };
struct Light {
    int mode; float first[13]; int count; float second[13]; float scale; int x,y; float third[13];
    void FUN_00baea20(Parser*);
};
// pdb: CLightingEngine::Parse | LightingEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void Light::FUN_00baea20(Parser* p) {
    int token=p->FUN_00ba92d0();
    do {
        switch(token) {
        case 0x1f42: mode=p->FUN_00ba92d0(); break;
        case 0x1f43: for(int i=0;i<13;++i) first[i]=p->FUN_00ba92a0(); break;
        case 0x1f44: count=p->FUN_00ba92d0(); break;
        case 0x1f45: for(int j=0;j<13;++j) second[j]=p->FUN_00ba92a0(); break;
        case 0x1f46: scale=p->FUN_00ba92a0(); break;
        case 0x1f47: x=p->FUN_00ba92d0(); break;
        case 0x1f48: y=p->FUN_00ba92d0(); break;
        case 0x1f49: for(int k=0;k<13;++k) third[k]=p->FUN_00ba92a0(); break;
        default: throw FUN_00ba3920("malformed lighting information",false);
        }
        token=p->FUN_00ba92d0();
    } while(token!=0x1f41);
}
}
}   // namespace f3m_00baea20

// @f3 0x00bb1730 (community match, verified in this file)
#include <vector>
#include <memory>
namespace f3m_00bb1730 {
namespace f3m_00bb1730 {

typedef std::vector<unsigned int> Elem;

struct Vec : std::vector<Elem> {
    void FUN_00bb1730(iterator _Where, size_type _Count, const Elem& _Val);
};

void Vec::FUN_00bb1730(iterator _Where, size_type _Count, const Elem& _Val)
{
    Elem _Tmp = _Val;
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity
            ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Tmp);
            _Umove(_Where._Myptr, _Mylast, _Ptr);
        } catch (...) {
            _Destroy(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        } catch (...) {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        std::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);

        stdext::_Unchecked_move_backward(_Where._Myptr, _Oldend - _Count, _Oldend);
        std::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

}
}   // namespace f3m_00bb1730
