// gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp: NiBSplineFloatInterpolator (10 functions)
#include "f3_common.h"
#include "nibsplinefloatinterpolator_decls.h"
// Calls the base NiBSplineInterpolator::LoadBinary, then reads m_fFloatValue and m_kFloatCPHandle from the stream input.
// @fnv 0x00a50cd0
// pdb: NiBSplineFloatInterpolator::LoadBinary | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
void NiBSplineFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    stream.input->Read(m_fFloatValue);
    stream.input->Read(m_kFloatCPHandle);
}

// @fnv 0x00a50a20
// pdb: NiBSplineFloatInterpolator::GetDimension | NiBSplineFloatInterpolator.obj | fnv360_1110_retail, objrun, medium
// pdb params: usChannel
int __stdcall FUN_00a50a20(unsigned short v)
{
    unsigned short z = 0;
    return z == v;
}

struct CPX
{
    unsigned char pad[0x20];
    unsigned int handle;
};
// @fnv 0x00a50a60
// pdb: NiBSplineFloatInterpolator::GetControlHandle | NiBSplineFloatInterpolator.obj | fnv360_1110_retail, objrun, high
// pdb params: usChannel
// pdb: NiBSplineFloatInterpolator::GetControlHandle | NiBSplineFloatInterpolator.obj | fnv360_1110_retail, objrun, high (was: GetHandleByIndex)
unsigned int __fastcall NiBSplineFloatInterpolator_GetControlHandle(CPX* self, int, unsigned short idx)
{
    unsigned int r = 0xffff;
    if (idx == 0)
        r = self->handle;
    return r;
}

namespace fnv_00a50a80 {
struct CPX
{
    unsigned char pad[0x20];
    unsigned int handle;
};
// @fnv 0x00a50a80
// pdb: NiBSplineFloatInterpolator::SetControlHandle | NiBSplineFloatInterpolator.obj | fnv360_1110_retail, objrun, high
// pdb params: kControlHandle, usChannel
// pdb: NiBSplineFloatInterpolator::SetControlHandle | NiBSplineFloatInterpolator.obj | fnv360_1110_retail, objrun, high (was: SetHandleIfFirstIndex)
void __fastcall NiBSplineFloatInterpolator_SetControlHandle(CPX* self, int, unsigned int h, unsigned short idx)
{
    if (idx == 0)
        self->handle = h;
}
}  // namespace fnv_00a50a80

struct IsEqX
{
    bool NiBSplineInterpolator_IsEqual(void*);
};
struct FInterpX
{
    unsigned char pad[0x1c];
    float f1c;
    unsigned int h;
};
// Returns true when NiBSplineInterpolator_IsEqual matches other and both f1c and h are equal; otherwise false.
// @fnv 0x00a50b30
// pdb: NiBSplineFloatInterpolator::IsEqual | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkObject
bool __fastcall IsInterpEqual(FInterpX* self, int, FInterpX* other)
{
    if (!reinterpret_cast<IsEqX*>(self)->NiBSplineInterpolator_IsEqual(other))
        return false;
    if (self->f1c != other->f1c)
        return false;
    return other->h == self->h ? true : false;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00a50b80
// pdb: BSFaceGenImage::`scalar deleting destructor' | BSFaceGenImage.obj | fnv360_0822_retail, vtable, medium
void* __fastcall FUN_00a50b80(void* self, int, unsigned int flags)
{
    FUN_00a57f80(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x24);
    return self;
}

struct CloningProcess
{
};
struct FUN_00a57f20_shell
{
    void FUN_00a57f20(int, int);
};
struct FUN_00a50110_obj
{
    void NiBSplineInterpolator_CopyMembers(FUN_00a50110_obj*, CloningProcess&);
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern int DAT_010997f4;
struct FUN_00a50c20Cls
{
    char _pad[0x1c];
    float m_fFloatValue;
    unsigned int m_kFloatCPHandle;
    FUN_00a50c20Cls* Clone(CloningProcess&);
};
// Allocates a new object, initialises it, copies the float value and handle from this, and returns the clone.
// @fnv 0x00a50c20
// pdb: NiBSplineFloatInterpolator::CreateClone | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, objrun, high
// pdb params: kCloning
FUN_00a50c20Cls* FUN_00a50c20Cls::Clone(CloningProcess& kCloning)
{
    FUN_00a50c20Cls* pkObject = (FUN_00a50c20Cls*)BSFadeNode::operator new(0x24);
    if (pkObject)
    {
        ((FUN_00a57f20_shell*)pkObject)->FUN_00a57f20(0, 0);
        *(void**)pkObject = (void*)&DAT_010997f4;
        pkObject->m_kFloatCPHandle = 0xffff;
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00a50110_obj*)this)->NiBSplineInterpolator_CopyMembers((FUN_00a50110_obj*)pkObject, kCloning);
    pkObject->m_fFloatValue = m_fFloatValue;
    pkObject->m_kFloatCPHandle = m_kFloatCPHandle;
    return pkObject;
}

struct NiBSplineEvalTarget
{
    void FUN_00a52550(float t, float* out, int one, unsigned int m18, unsigned int handle);
};

struct FUN_00a50ba0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    float m08;
    float m0c;
    float m10;
    NiBSplineEvalTarget* m14;
    unsigned int m18;
    float m1c;
    unsigned int m20;
    bool EvaluateAt(float v, unsigned int unused, float* out);
};

// If v differs from m08, computes t from m0c/m10 and evaluates the spline into m1c, then writes m1c to out and caches v in m08.
// @fnv 0x00a50ba0
// pdb: NiBSplineFloatInterpolator::Update | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, objrun, medium
// pdb params: fTime, pkInterpTarget, fValue
bool FUN_00a50ba0_cls::EvaluateAt(float afTime, unsigned int unused, float* pfOut)
{
    float t;
    if (m08 == afTime)
    {
        *pfOut = m1c;
        return true;
    }
    unsigned int handle = m20;
    if (handle != 0xffff)
    {
        t = (afTime - m0c) / (m10 - m0c);
        m14->FUN_00a52550(t, &m1c, 1, m18, handle);
    }
    *pfOut = m1c;
    m08 = afTime;
    return true;
}

struct FloatInterpStreamBinaryView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(FloatInterpStreamBinaryView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct FloatInterpStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    FloatInterpStreamBinaryView* m_pUnderlyingStream;
};

struct NiBSplineInterpolatorStand
{
    void* vtable;
    char unk04[0x18];
    void LoadStream(NiStream& stream);
};

struct FUN_00a50c70_cls : NiBSplineFloatInterpolator
{
    void NiBSplineFloatInterpolator_SaveBinary(NiStream& stream);
};

// Loads the base interpolator stream, then reads m_fFloatValue and m_kFloatCPHandle from the stream's binary view.
// @fnv 0x00a50c70
// pdb: NiBSplineFloatInterpolator::SaveBinary | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
// pdb: NiBSplineFloatInterpolator::SaveBinary | NiBSplineFloatInterpolator.obj | fnv360_0822_retail, caller_sim, high (was: LoadFloatInterpolator)
void FUN_00a50c70_cls::NiBSplineFloatInterpolator_SaveBinary(NiStream& stream)
{
    reinterpret_cast<NiBSplineInterpolatorStand*>(this)->LoadStream(stream);
    FloatInterpStreamView* s = reinterpret_cast<FloatInterpStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&m_fFloatValue);
    s->m_pUnderlyingStream->Load(&m_kFloatCPHandle);
}

#include <windows.h>
struct SpawnedRef
{
    virtual void Vslot00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

extern int DAT_0109ae8c;

struct FUN_00a57f80_cls
{
    void* m_vptr00;
    unsigned int unk04, unk08, unk0C, unk10;
    SpawnedRef* m_14;
    SpawnedRef* m_18;

    void BaseTeardown();
    void FUN_00a57f80();
};

// Releases the two SpawnedRef pointers m_14 and m_18 via InterlockedDecrement and DeleteThis, then calls BaseTeardown.
// @fnv 0x00a57f80
// pdb: NiBSplineInterpolator::~NiBSplineInterpolator | NiBSplineInterpolator.obj | fnv360_0822_retail, objrun, high
void FUN_00a57f80_cls::FUN_00a57f80()
{
    *(void* volatile*)&m_vptr00 = (void*)&DAT_0109ae8c;
    SpawnedRef* second = *(SpawnedRef* volatile*)&m_18;
    if (second != 0)
    {
        if (InterlockedDecrement(&second->m_iObjectReferenceCount) == 0)
        {
            second->DeleteThis();
        }
    }
    SpawnedRef* first = m_14;
    if (first != 0)
    {
        if (InterlockedDecrement(&first->m_iObjectReferenceCount) == 0)
        {
            first->DeleteThis();
        }
    }
    BaseTeardown();
}
