#include <new>
// src/f3staging/f3iso_0095af90_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0095af90 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0095af90 (community match, verified in this file)
// 0x0095af90: switches a constraint back on (hkpResponseModifier::enableConstraint in Havok terms): the modifier
// that made the solver ignore the constraint is removed and the constraint's stored solver results are cleared.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0116913c;

namespace f3repair_0095af90_native {

typedef float hkReal;
typedef unsigned int hkUint32;



// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(::TlsGetValue(::DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        // Commands borrow storage from the monitor stream's arena.
        static __forceinline void* operator new(unsigned int, void* storage) throw()
        {
            return storage;
        }
        static __forceinline void operator delete(void*, void*) throw() {}

        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

// what the solver left behind for one constraint row
struct hkpSolverResults
{
    __forceinline void init()
    {
        m_impulseApplied = 0.0f;
        m_internalSolverData = 0.0f;
    }

    hkReal m_impulseApplied;
    hkReal m_internalSolverData;
};

typedef void hkpConstraintRuntime;

class hkpConstraintOwner
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void checkAccessRw();
};

class hkpConstraintData
{
public:
    struct RuntimeInfo
    {
        int m_sizeOfExternalRuntime;
        int m_numSolverResults;
    };

    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void getRuntimeInfo(hkBool wantRuntime, RuntimeInfo& infoOut) const;
};

struct hkpConstraintInternal
{
    void* m_constraint;
    void* m_entities[2];
    void* m_atoms;
    int unk10;
    int unk14;
    int unk18;
    hkpConstraintRuntime* m_runtime;
};

class hkpConstraintInstance
{
public:
    __forceinline hkpConstraintData* getData() const { return m_data; }
    __forceinline hkpConstraintRuntime* getRuntime() const { return m_internal->m_runtime; }

    void* m_vtable;
    int unk04;
    void* m_owner;
    hkpConstraintData* m_data;
    void* m_constraintModifiers;
    void* m_entities[2];
    int unk1c;
    int unk20;
    int unk24;
    hkpConstraintInternal* m_internal;
};

enum { TYPE_MODIFIER_IGNORE_CONSTRAINT = 0x1b };

// hkpWorldConstraintUtil::removeModifier


}

// The pack declares this function as EnableConstraintsAndZeroArrays(CE0020Target*, CE0020Subject*); its stand-in
// classes do not have the member offsets of this build, so the two objects are used as what they are in Havok terms:
// the constraint instance and the constraint owner.
void __cdecl FUN_009a9400(f3repair_0095af90_native::hkpConstraintInstance*, f3repair_0095af90_native::hkpConstraintOwner&, int);

// pdb: hkpResponseModifier::enableConstraint | hkpResponseModifier.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpResponseModifier_enableConstraint(f3repair_0095af90_native::hkpConstraintInstance* instance, f3repair_0095af90_native::hkpConstraintOwner& constraintOwner)
{
    using namespace f3repair_0095af90_native;



    constraintOwner.checkAccessRw();

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = new (mStream.getEnd()) hkMonitorStream::TimerCommand;
            h->m_commandAndMonitor = "TtEnblConstr";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    ::FUN_009a9400(instance, constraintOwner, TYPE_MODIFIER_IGNORE_CONSTRAINT);

    // the solver results start from zero again
    hkpConstraintRuntime* runtime = instance->getRuntime();
    if (runtime)
    {
        hkpConstraintData::RuntimeInfo rinfo;
        instance->getData()->getRuntimeInfo(hkBool(true), rinfo);
        hkpSolverResults* results = reinterpret_cast<hkpSolverResults*>(runtime);
        for (int i = 0; i < rinfo.m_numSolverResults; i++)
        {
            results[i].init();
        }
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = new (mStream.getEnd()) hkMonitorStream::TimerCommand;
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

namespace f3repair_0095af90_native {
typedef char VerifyBoolSize[(sizeof(hkBool) == 1) ? 1 : -1];
typedef char VerifyRuntimeInfoSize[(sizeof(hkpConstraintData::RuntimeInfo) == 8) ? 1 : -1];
typedef char VerifySolverResultSize[(sizeof(hkpSolverResults) == 8) ? 1 : -1];
typedef char VerifyMonitorStreamSize[(sizeof(hkMonitorStream) == 16) ? 1 : -1];
typedef char VerifyTimerCommandSize[(sizeof(hkMonitorStream::TimerCommand) == 12) ? 1 : -1];
typedef char VerifyInternalSize[(sizeof(hkpConstraintInternal) == 32) ? 1 : -1];
typedef char VerifyInstanceSize[(sizeof(hkpConstraintInstance) == 44) ? 1 : -1];
}
