#include <new>
// src/f3staging/f3iso_0097aa70_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0097aa70 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0097aa70 (community match, verified in this file)
namespace f3m_0097aa70 {
struct Backing {
    void* vtable; unsigned position; int state;
    unsigned (__cdecl *write)(Backing*,const void*,unsigned,unsigned*,unsigned);
    unsigned binaryWrite(const void* p,unsigned n,unsigned* sizes,unsigned count) {
        unsigned written=write(this,p,n,sizes,count);
        position+=written;
        return written;
    }
};
template<class T> inline void saveValue(Backing& out,const T* p,unsigned count=1) {
    unsigned size=sizeof(T);
    out.binaryWrite(p,count*size,&size,1);
}
struct Stream { char prefix[0x250]; Backing* backing; };
struct Object { virtual void destroy();virtual void stats();virtual void typeInfo();virtual void validate();virtual unsigned saveType(); };
struct Saver {
    virtual void destroy(bool);
    virtual void stats();
    virtual void typeInfo();
    virtual void save(Stream&);
    void FUN_008fbbb0(Object*);
};
Saver* FUN_0097a820(unsigned);
// pdb: bhkConstraintManager::SaveBinary | bhkConstraintManager.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream, apData
void FUN_0097aa70(Stream& stream,Object* object) {
    unsigned type=object->saveType();
    Saver* saver=FUN_0097a820(type);
    saver->FUN_008fbbb0(object);
    saveValue(*stream.backing,&type);
    saver->save(stream);
    saver->destroy(true);
}

}   // namespace f3m_0097aa70
