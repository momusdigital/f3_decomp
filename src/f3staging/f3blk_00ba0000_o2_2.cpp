// src/f3staging/f3blk_00ba0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bbdff0 (community match, verified in this file)
#include <string>
#include <stdexcept>
namespace f3m_00bbdff0 {

class IdvFileError : public std::runtime_error {
public:
    IdvFileError(const std::string& message, int code);
};

namespace f3m_00bbdff0 {
class CTreeFileAccess {
public:
    int FUN_00ba92d0();
    float FUN_00ba92a0();
};

class CLodParameters {
public:
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int lodLevels;
    int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90;
    int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0;
    int unkB4; int unkB8; int unkBC;
    int lodStyle;
    int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8;
    float lodDistanceNear;
    float lodDistanceFar;
    float lodTransition;
    float lodBillboard;
    float lodFade;

    void FUN_00bbdff0(CTreeFileAccess& reader);
};

// pdb: CTreeEngine::ParseLodInfo | TreeEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void CLodParameters::FUN_00bbdff0(CTreeFileAccess& reader)
{
    int token = reader.FUN_00ba92d0();
    do {
        switch (token) {
        case 0x232F:
            lodLevels = reader.FUN_00ba92d0();
            break;
        case 0x2330:
            lodDistanceNear = reader.FUN_00ba92a0();
            break;
        case 0x2332: {
            float value = reader.FUN_00ba92a0();
            lodTransition = value;
            if (value == 0.0f)
                lodTransition = 0.1f;
            break;
        }
        case 0x2333:
            lodStyle = reader.FUN_00ba92d0();
            break;
        case 0x2334:
            lodDistanceFar = reader.FUN_00ba92a0();
            break;
        case 0x2335:
            lodBillboard = reader.FUN_00ba92a0();
            break;
        case 0x2336:
            lodFade = reader.FUN_00ba92a0();
            break;
        default:
            throw IdvFileError("malformed engine lod data", 0);
        }
        token = reader.FUN_00ba92d0();
    } while (token != 0x232E);
}
}
}   // namespace f3m_00bbdff0

// @f3 0x00bb0fe0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb0fe0 {

namespace f3m_00bb0fe0 {
// std::vector<T>::clear (VC8 release, checked iterators)
struct List : std::vector<int> {
    void FUN_00bb0fe0();
};
}

// pdb: std::vector<std::vector<unsigned short *,std::allocator<unsigned short *> >,std::allocator<std::vector<unsigned short *,std::allocator<unsigned short *> > > >::clear | IndexedGeometry.obj | fnv360_0721_beta, objrun_open, low
void f3m_00bb0fe0::List::FUN_00bb0fe0()
{
    erase(begin(), end());
}
}   // namespace f3m_00bb0fe0

// @f3 0x00ba1140 (community match, verified in this file)
namespace f3m_00ba1140 {
namespace f3m_00ba1140 {
struct Matrix { float m[4][4]; };
struct Vec3 {
    float x, y, z;
    Vec3 FUN_00ba1140(const Matrix& t) const;
};
}

// pdb: CSpeedTreeRT::SGeometry::SIndexed::SIndexed | SpeedTreeRT.obj | fnv360_0822_debug, objrun_open, low
f3m_00ba1140::Vec3 f3m_00ba1140::Vec3::FUN_00ba1140(const Matrix& t) const
{
    Vec3 r;
    r.x = x * t.m[0][0] + y * t.m[1][0] + z * t.m[2][0] + t.m[3][0];
    r.y = x * t.m[0][1] + y * t.m[1][1] + z * t.m[2][1] + t.m[3][1];
    r.z = x * t.m[0][2] + y * t.m[1][2] + z * t.m[2][2] + t.m[3][2];
    return r;
}
}   // namespace f3m_00ba1140

// @f3 0x00ba8140 (community match, verified in this file)
#include <vector>
namespace f3m_00ba8140 {

namespace f3m_00ba8140 {
// std::vector<int>::push_back, written out on a derived class (the library body, VC8 release)
struct IntList : std::vector<int> {
    void FUN_00ba8140(const int& value);
};
}

void f3m_00ba8140::IntList::FUN_00ba8140(const int& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00ba8140

// @f3 0x00bb21b0 (community match, verified in this file)
#include <vector>
#include <string.h>
namespace f3m_00bb21b0 {
struct StripOwner {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 unsigned short count20;
 int unk24;
 std::vector<unsigned int> counts28;
 std::vector<std::vector<unsigned short> > lengths38;
 std::vector<std::vector<unsigned short*> > strips48;
 int unk58,unk5c,unk60,unk64;
 std::vector<float> positions68;
 void FUN_00bb1100();
 void FUN_00bb21b0(bool parity);
};
// pdb: CIndexedGeometry::CombineStrips | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: bToggleFaceOrdering
void StripOwner::FUN_00bb21b0(bool parity)
{
 if ((unsigned short)(positions68.size() / 3) > 0)
 {
  std::vector<std::vector<unsigned short> > lengthTable(count20);
  std::vector<std::vector<unsigned short*> > stripTable(count20);
  std::vector<unsigned int> countTable(count20);
  for (unsigned short i = 0; i < count20; ++i)
  {
   int total = 0;
   for (unsigned short j = 0; j < ((short)i > -1 ? (unsigned short)strips48[(short)i].size() : (unsigned short)0); ++j)
    total += lengths38[i][j];
   if (total > 0)
   {
    if (parity)
    {
     for (unsigned short j = 0; j < ((short)i > -1 ? (unsigned short)strips48[(short)i].size() : (unsigned short)0) - 1; ++j)
     {
      unsigned short len = lengths38[i][j];
      if (len % 2 == 0)
       total += 2;
      else
       total += 3;
     }
    }
    else
    {
     int n = ((short)i > -1 ? (unsigned short)strips48[(short)i].size() : (unsigned short)0);
     if (n > 0)
      n--;
     total += 2 * n;
    }
    unsigned short* data = new unsigned short[total];
    unsigned short* out = data;
    for (unsigned short j = 0; j < ((short)i > -1 ? (unsigned short)strips48[(short)i].size() : (unsigned short)0); ++j)
    {
     unsigned short len = lengths38[i][j];
     memcpy(out, strips48[i][j], len * sizeof(unsigned short));
     out += len;
     if (j < ((short)i > -1 ? (unsigned short)strips48[(short)i].size() : (unsigned short)0) - 1)
     {
      if (parity)
      {
       if (len % 2 == 0)
       {
        *out++ = strips48[i][j][len - 1];
        unsigned short head = strips48[i][j + 1][0];
        *out++ = head;
       }
       else
       {
        *out++ = strips48[i][j][len - 1];
        *out++ = strips48[i][j][len - 1];
        unsigned short head = strips48[i][j + 1][0];
        *out++ = head;
       }
      }
      else
      {
       *out++ = strips48[i][j][len - 1];
       unsigned short head = strips48[i][j + 1][0];
       *out++ = head;
      }
     }
    }
    lengthTable[i].push_back((unsigned short)total);
    stripTable[i].push_back(data);
    countTable[i] = total - 2;
   }
   else
   {
    lengthTable[i].clear();
    stripTable[i].clear();
    countTable[i] = 0;
   }
  }
  FUN_00bb1100();
  lengths38 = lengthTable;
  strips48 = stripTable;
  counts28 = countTable;
 }
}
}   // namespace f3m_00bb21b0

// @f3 0x00bb9dd0 (community match, verified in this file)
#include <vector>
#include <memory>
namespace f3m_00bb9dd0 {
namespace f3m_00bb9dd0 {

typedef std::vector<unsigned int> Elem;

struct Vec : std::vector<Elem> {
    void FUN_00bb9dd0(iterator _Where, size_type _Count, const Elem& _Val);
};

void Vec::FUN_00bb9dd0(iterator _Where, size_type _Count, const Elem& _Val)
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
}   // namespace f3m_00bb9dd0

// @f3 0x00bb8f50 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb8f50 {
namespace f3m_00bb8f50 {

typedef std::vector<unsigned int> Elem;

Elem* __cdecl FUN_00bb8f50(Elem* _First, Elem* _Last, Elem* _Dest, std::allocator<Elem>& _Al,
                          std::_Swap_move_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _Dest;
    Elem _Val;
    try {
        for (; _First != _Last; ++_Dest, ++_First) {
            _Al.construct(_Dest, _Val);
            std::swap(*_Dest, *_First);
        }
    } catch (...) {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

}
}   // namespace f3m_00bb8f50

// @f3 0x00bb5880 (community match, verified in this file)
#include <vector>
#include <stdexcept>
namespace f3m_00bb5880 {
// std::vector<Elem>::vector(const vector& _Right) from the VS2005 <vector> (Elem: 56-byte trivially copyable struct),
// _SECURE_SCL checked iterators, written fresh from the header bodies (vector copy constructor, _Buy, _Ucopy, size,
// max_size, begin/end, _Vector_const_iterator(ptr, cont), stdext::unchecked_uninitialized_copy -> std::_Uninit_copy
// with the std::_Ptr_cat tag). _Buy keeps its header body; the compiler leaves it out of line (called at 0x00bb57d0)
// with _Xlen (0x00bc5f00) and std::_Allocate<Elem> (0x00bb46f0) below it. std::_Uninit_copy<Elem*, Elem*,
// allocator<Elem> > is the real header instance (exact at 0x00bb50f0: 14-dword rep movsd per element). _Tidy 0x00bbdcd0
// is declared by address.

namespace f3m_00bb5880 {

struct ElemB58 {
    unsigned m_aData[14];
};




// std::_Vector_const_iterator (release, _SECURE_SCL: _Mycont + _Myptr)
template<class _Myvec>
struct ConstIterB58 {
    const _Myvec* _Mycont;
    ElemB58* _Myptr;
    ConstIterB58(ElemB58* _Ptr, const _Myvec* _Pvector)
    {
        _SCL_SECURE_VALIDATE(_Pvector != NULL && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast);
        this->_Mycont = _Pvector;
        _Myptr = _Ptr;
    }
    ElemB58* _Checked_iterator_base() const { return _Myptr; }
};

struct VectorB58 {
    typedef ConstIterB58<VectorB58> const_iterator;
    std::allocator<ElemB58> _Alval;
    ElemB58* _Myfirst;
    ElemB58* _Mylast;
    ElemB58* _Myend;

    VectorB58* FUN_00bb5880(const VectorB58& _Right);   // the copy constructor, under the pack's name

    unsigned size() const { return (_Myfirst == 0 ? 0 : _Mylast - _Myfirst); }
    const_iterator begin() const { return const_iterator(_Myfirst, this); }
    const_iterator end() const { return const_iterator(_Mylast, this); }

    unsigned max_size() const { return (this->_Alval.max_size()); }
    static void FUN_00bc5f00() { _THROW(std::length_error, "vector<T> too long"); }   // _Xlen

    bool FUN_00bb57d0(unsigned _Capacity)   // _Buy
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return (false);
        else if (max_size() < _Capacity)
            FUN_00bc5f00();
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return (true);
    }

    ElemB58* _Ucopy(const_iterator _First, const_iterator _Last, ElemB58* _Ptr)
    {
        return std::_Uninit_copy(_First._Checked_iterator_base(), _Last._Checked_iterator_base(), _Ptr, this->_Alval,
                            std::_Ptr_cat(_First, _Ptr), std::_Range_checked_iterator_tag());
    }

    void FUN_00bbdcd0();                      // _Tidy
};

VectorB58* VectorB58::FUN_00bb5880(const VectorB58& _Right)
{
    if (FUN_00bb57d0(_Right.size()))
        try {
            _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
        }
        catch (...) {
            FUN_00bbdcd0();
            throw;
        }
    return this;
}

}

}   // namespace f3m_00bb5880
