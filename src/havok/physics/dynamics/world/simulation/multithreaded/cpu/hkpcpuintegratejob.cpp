// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuintegratejob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuintegratejob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Owner {
    unsigned int field00, field04, field08, field0c;
    unsigned int field10, field14, field18, field1c;
    unsigned int field20, field24, field28, field2c;
    void* payload;
};
struct Record {
    unsigned int key;
    unsigned int value;
    unsigned int extra;
    unsigned char* first;
    unsigned char* second;
    unsigned short kind;
    unsigned short extraKind;
    unsigned short firstIndex;
    unsigned short secondIndex;
};
struct Block {
    Block() { count = 0; firstEnd = 0; next = 0; }
    static void* operator new(unsigned int) throw();
    Block* next;
    Owner* owner;
    void* payload;
    unsigned int firstOffset;
    unsigned int firstEnd;
    int count;
    Record firstRecord;
};
struct Group {
    Group() { next = 0; boundary = false; count = 0; limit = 0; }
    static void* operator new(unsigned int) throw();
    Group* next;
    Owner* owner;
    void* payload;
    unsigned int firstOffset;
    unsigned int secondOffset;
    unsigned int firstLength;
    unsigned int secondLength;
    bool boundary;
    unsigned short count;
    Group* limit;
    unsigned int field24, field28, field2c;
};
struct Allocator { virtual void unused(); virtual void* allocate(unsigned int size); };
struct AllocationContext { unsigned int field00, field04, field08, field0c; Allocator* allocator; void* allocate(unsigned int size) { return allocator->allocate(size); } };
void* __cdecl FUN_00c85750();
inline void* Block::operator new(unsigned int) throw() { return ((AllocationContext*)FUN_00c85750())->allocate(0x1000); }
inline void* Group::operator new(unsigned int) throw() { return ((AllocationContext*)FUN_00c85750())->allocate(0x30); }

struct SizePointer { unsigned int* value; SizePointer(unsigned int* p):value(p) {} unsigned int& operator*() const { return *value; } };

#include <xmmintrin.h>
#include <windows.h>
inline void* operator new(unsigned int, void* ptr) { return ptr; }
__declspec(nothrow) void* FUN_00c85750();
__declspec(nothrow) void FUN_00c908c0(void*,void*,int,int);
extern DWORD DAT_0126835c;
struct FlagByte {
    char value;
    FlagByte() {}
    FlagByte(bool b) : value((char)b) {}
    operator bool() const { return value != 0; }
    FlagByte& operator=(bool b) { value=(char)b; return *this; }
    FlagByte operator==(bool b) const { return int(value)==int(b); }
    FlagByte operator!=(bool b) const { return int(value)!=int(b); }
};
struct TaskAllocator {
    virtual void unused();
    virtual void* allocate(int bytes) throw();
    virtual void release(void* ptr,int bytes) throw();
    virtual void unused0c();
    virtual void freeBuffer(void* ptr,int bytes) throw();
    template<class T> void freeElements(void* ptr,int n) {
        const int stride=sizeof(T);
        freeBuffer(ptr,n*stride);
    }
};
struct TaskMemory {
    unsigned char* stackTop;
    int unknown04,unknown08;
    TaskAllocator* temporary;
    TaskAllocator* heap;
    static TaskMemory& GetMonitorStream() { return *(TaskMemory*)FUN_00c85750(); }
    TaskAllocator& tempAllocator() { return *temporary; }
    TaskAllocator& heapAllocator() { return *heap; }
    template<class T> T* takeStack(int n) {
        unsigned char* result=stackTop;
        stackTop += (n*int(sizeof(T))+127)&~127;
        return (T*)result;
    }
    void returnStack(void* ptr) { stackTop=(unsigned char*)ptr; }
};
struct HeapPolicy { static TaskAllocator& get(const void*) { return TaskMemory::GetMonitorStream().heapAllocator(); } };
struct TempPolicy { static TaskAllocator& get(const void*) { return TaskMemory::GetMonitorStream().tempAllocator(); } };
template<class T> struct SmallList {
    T* data;
    unsigned short count;
    unsigned short capacity;
    const T* begin() const { return data; }
    const T* end() const { return data+count; }
};
template<class T> __forceinline void defaultRange(T* p,int n) { for(int i=0;i<n;++i) new(p+i) T; }
template<class T> __forceinline void copyRange(T* p,int n,const T& value) { for(int i=0;i<n;++i) new(p+i) T(value); }
template<class T> __forceinline void destroyRange(T* p,int n) { for(int i=0;i<n;++i) (p+i)->~T(); }

struct DelayInit {};
template<class T> class TaskArrayBase {
protected:
    T* data;
    int count;
    int capacity;
public:
    TaskArrayBase(DelayInit) {}
    TaskArrayBase() : data(0), count(0), capacity((int)0x80000000) {}
    int GetLogicalSize() const { return count; }
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data+count; }
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
    void clear() { destroyRange(data,count); count=0; }
    void setSizeUnchecked(int n) { destroyRange(data+n,count-n); defaultRange(data+count,n-count); count=n; }
    void reserveWith(TaskAllocator& alloc,int n) {
        int old=capacity&0x3fffffff;
        if (old<n) { int grown=old+old; if(n>=grown) grown=n; FUN_00c908c0(&alloc,this,grown,sizeof(T)); }
    }
    void pushBackUnchecked(const T& entry) {
        copyRange(data+count,1,entry);
        ++count;
    }
    T* expandByUnchecked(int n) { int old=count; count=old+n; defaultRange(data+old,count-old); return data+old; }
    void releaseWith(TaskAllocator& alloc) {
        clear();
        if(!(capacity&(int)0x80000000)) alloc.freeElements<T>(data,capacity&0x3fffffff);
        data=0; capacity=(int)0x80000000;
    }
};

template<class T,class Policy=HeapPolicy> class TaskArray : public TaskArrayBase<T> {
public:
    TaskArray(DelayInit d) : TaskArrayBase<T>(d) {}
    TaskArray() : TaskArrayBase<T>() {}
    void reserve(int n) { reserveWith(Policy::get(this),n); }
    void closeArray() { releaseWith(Policy::get(this)); }
};
template<class T> class StackArray : public TaskArray<T> {
    T* local;
public:
    StackArray(int n) { data=TaskMemory::GetMonitorStream().takeStack<T>(n); capacity=n|(int)0x80000000; local=data; }
    void closeStack() {
        if(data==local) clear();
        TaskMemory::GetMonitorStream().returnStack(local);
        TaskArray<T>::closeArray();
    }
};
struct IndexPair { unsigned long key,value; };
class EntityIndexMap {
    IndexPair* data;
    int count,mask;
    void FUN_00cb1830(void*,int) throw();
    int FUN_00cb1870(TaskAllocator*,unsigned long,unsigned long) throw();
    unsigned long LookupHashEntry(unsigned long,unsigned long) const throw();
    void ProcessArgument(TaskAllocator*) throw();
    void FUN_00a29680() throw();
    void growMap(TaskAllocator*,int) throw();
public:
    EntityIndexMap(void* ptr,int bytes) { FUN_00cb1830(ptr,bytes); }
    void closeMap() { ProcessArgument(TaskMemory::GetMonitorStream().heap); FUN_00a29680(); }
    void insert(unsigned long key,unsigned long val) { FUN_00cb1870(TaskMemory::GetMonitorStream().heap,key,val); }
    unsigned long FindValueForKey(unsigned long key,unsigned long value) const { return LookupHashEntry(key,value); }
};

struct TaskEntity;
struct __declspec(align(16)) InternalConstraint {
    void* m_pHavokConstraint;
    TaskEntity* m_kActorEntries[2];
    void* atoms;
    unsigned short atomSize;
    unsigned char m_ucCallbackRequest;
    unsigned char m_priority;
    unsigned short m_iSchemaByteSize;
    unsigned short unknown16;
    unsigned short m_iSolverElementTemporaryCount;
    unsigned char m_ucByteAfterTemporaryCount;
    FlagByte m_kRuntimeFlagByte;
    void* m_pRuntime;
    unsigned short m_usTrailingValue;
    unsigned short unknown22;
    int unknown24,unknown28,unknown2c;
    void* getAtoms() const { return atoms; }
    unsigned short getAtomsSize() const { return atomSize; }
};
struct TaskTransform { __m128 axis0,axis1,axis2,translation; };
struct TaskEntity {
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;
    int unknown48;
    int unknown4c;
    int unknown50;
    int unknown54;
    int unknown58;
    int unknown5c;
    int unknown60;
    int unknown64;
    int unknown68;
    int unknown6c;
    int unknown70;
    int unknown74;
    int unknown78;
    int unknown7c;
    int unknown80;
    int unknown84;
    int unknown88;
    int unknown8c;
    int unknown90;
    int unknown94;
    int unknown98;
    int unknown9c;
    int unknowna0;
    unsigned int m_uiFilterInfo;
    unsigned short storageIndex,unknownaa;
    SmallList<InternalConstraint> constraints;
    int unknownb4;
    int unknownb8;
    int unknownbc;
    int unknownc0;
    int unknownc4;
    int unknownc8;
    int unknowncc;
    int unknownd0;
    int unknownd4;
    int unknownd8;
    int unknowndc;
    int unknowne0;
    int unknowne4;
    int unknowne8;
    int unknownec;

    TaskTransform transform;
    const SmallList<InternalConstraint>& getConstraintMasters() const { return constraints; }
    TaskEntity* getMotion() { return this; }
    const TaskTransform& getTransform() const { return transform; }
};
struct SolverStats { int unknown00,maximumSchemaSize,schemaSize,m_iSolverResultCount; };
struct SceneIsland {
    int unknown00;
    SolverStats m_kConstraintInfo;
    int unknown14,unknown18;
    int m_iConstraintCount;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;

    TaskArray<TaskEntity*> entities;
    const TaskArray<TaskEntity*>& GetEntities() const { return entities; }
};
struct JobHeader {
    int unknown00,unknown04,unknown08,unknown0c,unknown10,unknown14,unknown18,unknown1c;
    int unknown20,unknown24,unknown28,unknown2c;
    void* m_pAccumulatorA;
    void* m_pVelocityAccumulatorB;
    unsigned short m_usValueAt38,m_usValueAt3A;
    unsigned char* m_pByteArrayAt3C;
    int* m_pIntegerArrayAt40;
    int unknown44,unknown48,unknown4c,unknown50;
    unsigned short m_usTaskMetadata,unknown56;
    FlagByte m_kFirstTaskFlagByte,m_kSecondTaskFlagByte;
};
struct __declspec(align(128)) BuildTask {
    struct BuildTaskData {
        void* m_kBridgeAtoms;
        void* ms_uiThreadLocalStorageIndex;
        void* m_pRuntime;
        const TaskTransform* m_kBodyALocalFrame;
        const TaskTransform* m_kBodyBLocalFrame;
        unsigned short m_iAtomsSize,m_usTrailingValue,m_usSecondTrailingValue,m_usThirdTrailingValue;
    };
    BuildTask* m_next;
    JobHeader* m_pJobHeader;
    void* m_pVelocityAccumulatorA;
    unsigned char* m_akBufferStates;
    unsigned char* m_akBuildBuffer;
    int m_iBuildItemCount;
    BuildTaskData m_akBuildTaskEntries[144];
    static void* operator new(unsigned int n) throw() { return TaskMemory::GetMonitorStream().heap->allocate(n); }
    BuildTask() { m_iBuildItemCount=0; m_akBuildBuffer=0; m_next=0; }
};
struct __declspec(align(16)) SolveTask {
    SolveTask* m_next;
    JobHeader* m_pJobHeader;
    void* m_pVelocityAccumulatorA;
    const unsigned char* m_akBufferStates;
    int* m_pIntegerValues;
    int m_iFirstSolveTaskValue,m_iSecondSolveTaskValue;
    FlagByte m_kSolveTaskFlagByte;
    unsigned short m_usSolverElementCount;
    SolveTask* m_pNextSolveTask;
    int unknown24,unknown28,unknown2c;
    static void* operator new(unsigned int n) throw() { return TaskMemory::GetMonitorStream().heap->allocate(n); }
    SolveTask() { m_next=0; m_kSolveTaskFlagByte=false; m_usSolverElementCount=0; m_pNextSolveTask=0; }
};
struct BuildCollection {
    struct ConstraintBuildTaskLink { const InternalConstraint* m_pInternalConstraint; BuildTask::BuildTaskData* m_pBuildTaskEntry; };
    BuildTask* m_pBuildTask;
    int m_iEntryCount;
    ConstraintBuildTaskLink* m_pInternalConstraint;
    int m_iEntryCapacity;
};
struct SolveCollection { SolveTask* m_pTasks; unsigned short m_usTaskCount; };
struct MonitorStream {
    struct CommandTimingEntry { const char* m_pCommandName; unsigned int m_uiStartTicks,m_uiEndTicks; };
    struct CommandFilterEntry { const char* m_pCommandName; float m_uiFilterValue; };
    char* start;
    char* current;
    char* capacity;
    char* limit;
    static MonitorStream& GetMonitorStream() { return *(MonitorStream*)TlsGetValue(DAT_0126835c); }
    FlagByte memoryAvailable() { return current<limit; }
    char* GetStreamEnd() { return current; }
    void setEnd(char* ptr) { current=ptr; }
};
struct __declspec(align(8)) ProbeEntry {
    const InternalConstraint* constraint;
    unsigned short firstIndex;
    unsigned short secondIndex;
};
struct __declspec(align(16)) ProbeCallback : ProbeEntry {
    BuildTask::BuildTaskData* output;
};

extern const char str_010d3f1c[], str_010d3d60[], str_010d3f08[], str_010d3d70[], str_010c41f8[];

struct SceneInput { SceneInput(SceneIsland* v):p(v) {} SceneIsland* p;  operator SceneIsland*() const { return p; } SceneIsland* operator->() const { return p; } };


namespace fnv_00d95cf0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" int (__stdcall *DAT_00fdf04c)(unsigned long, void*);

typedef short sshort;
typedef unsigned char byte;

extern const char DAT_010cc5c4[], DAT_010cc5bc[], DAT_010cc5b0[], DAT_010d3f64[], DAT_010d3f54[], DAT_01076f38[], DAT_010d3f48[], DAT_010d3f38[], DAT_010d3f2c[];

struct FlagByte {
    char value;
    __forceinline FlagByte() {}
    __forceinline FlagByte(bool b) { value = (char)b; }
    __forceinline operator bool() const { return value != 0; }
    __forceinline FlagByte& operator=(bool b) { value = (char)b; return *this; }
};

template <class E, class S> struct EnumField {
    S storage;
    __forceinline EnumField() {}
    __forceinline EnumField(E e) { storage = (S)e; }
    __forceinline void operator=(E e) { storage = (S)e; }
};

template <class T> struct TlsSlot {
    unsigned long slotId;
    __forceinline T get() const { return (T)TlsGetValue(slotId); }
    __forceinline void set(T p) { DAT_00fdf04c(slotId, (void*)p); }
};

template <class T> struct PaddedPtr {
    T storage;
    __forceinline PaddedPtr() {}
    __forceinline PaddedPtr(T e) : storage(e) {}
    __forceinline void operator=(T e) { storage = e; }
    __forceinline T val() const { return storage; }
    __forceinline T operator->() const { return storage; }
    __forceinline operator T() const { return val(); }
};

struct SyncCheck {
    template <class T> static __forceinline void verify(int id, const T& obj) {}
};

struct MonitorStream {
    PaddedPtr<char*> start;
    PaddedPtr<char*> current;
    PaddedPtr<char*> capacity;
    PaddedPtr<char*> limit;
    struct EventHeader { const char* tag; };
    struct CommandTimingEntry : EventHeader {
        unsigned int time0;
        unsigned int time1;
        __forceinline void setTime();
    };
    struct SplitTimerCommand : CommandTimingEntry { const char* splitTag; };
    static __forceinline MonitorStream& GetMonitorStream();
    __forceinline char* __cdecl GetStreamEnd() { return current.val(); }
    __forceinline char* __cdecl getLimit() { return limit.val(); }
    __forceinline FlagByte __cdecl memoryAvailable() { return GetStreamEnd() < getLimit(); }
    __forceinline void __cdecl setEnd(char* ptr) { current = ptr; }
};

__forceinline void MonitorStream::CommandTimingEntry::setTime() {
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    time0 = ticks;
}

extern TlsSlot<MonitorStream*> DAT_0126835c;

struct TaskAllocator {
    virtual ~TaskAllocator();
    virtual void* allocate(int bytes);
    virtual void release(void* p, int bytes);
    virtual void* acquireBuffer(int& reqBytesInOut);
    virtual void releaseBuffer(void* p, int bytes);
    template <class T> __forceinline T* allocBuf(int& reqCountInOut) {
        const int elemSize = sizeof(T);
        int n = reqCountInOut * elemSize;
        void* p = acquireBuffer(n);
        reqCountInOut = n / elemSize;
        return static_cast<T*>(p);
    }
    template <class T> __forceinline void freeBuf(void* p, int count) {
        const int elemSize = sizeof(T);
        releaseBuffer(p, count * elemSize);
    }
};

struct TaskMemory {
    int stack0, stack1, stack2, stack3;
    TaskAllocator* heapAlloc;
    TaskAllocator* debugAlloc;
    TaskAllocator* solverAlloc;
    static __forceinline TaskMemory& GetMonitorStream() { return *(TaskMemory*)FUN_00c85750(); }
    __forceinline TaskAllocator& heap() { return *heapAlloc; }
    __forceinline TaskAllocator& solver() { return *solverAlloc; }
};

template <class T> struct TaskArrayBase {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int GetLogicalSize() const { return count; }
    __forceinline int getCapacity() const { return capacityAndFlags & 0x3FFFFFFF; }
    __forceinline T* begin() const { return data; }
    __forceinline T& operator[](int i) const { return data[i]; }
};

template <class T> struct TaskArray : TaskArrayBase<T> {
    __forceinline TaskArray() { this->data = 0; this->count = 0; this->capacityAndFlags = 0x80000000; }
};

enum PacketKind { PACKET_DYNAMICS = 0, PACKET_MAX = 16 };
enum PacketMode { MODE_INVALID, MODE_ENABLED, MODE_DISABLED };

struct PacketBase {
    __declspec(align(16)) byte subType;
    EnumField<PacketKind, byte> kind;
    EnumField<PacketMode, byte> mode;
    byte unk03;
    unsigned short size;
    sshort affinity;
    __forceinline PacketBase() {}
    __forceinline PacketBase(PacketKind k, unsigned int sub, unsigned short sz, PacketMode m)
        : subType((byte)sub), kind(k), mode(m), size(sz), affinity(-1) {}
};

struct Command : PacketBase {
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    __forceinline Command() {}
};

struct __declspec(align(16)) QueueStorage : Command {
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c;
};

struct QueryStepBase {
    __declspec(align(16)) float substepDt;
    float microStepDt, substepInvDt, frameDt, frameInvDt, invNumSteps, invTotalSteps;
    float maxViolationSq, rhsFactor, virtMassFactor, frictionRhsFactor;
};

struct ConstraintQueryIn : QueryStepBase {
    __forceinline ConstraintQueryIn() {}
    __declspec(align(16)) const void* bodyA;
    const void* bodyB;
    const void* transformA;
    const void* transformB;
    float tau, damping;
    void* constraintInstance;
    void* constraintRuntime;
    void* violatedConstraints;
    unsigned int accumIndexA, accumIndexB;
    void* runtimeMainMem;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};

struct StepTiming { int unk00, unk04, unk08, unk0c; };
struct SolverParams { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c; };
struct AccelVec { int x, y, z, w; };

struct Context {
    StepTiming timing;
    SolverParams solver;
    AccelVec gravityStep;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    FlagByte buildOnSpu;
};

struct Observer {
    virtual ~Observer();
    virtual void unused04();
    virtual void unused08();
    virtual void apply(const Context& ctx);
};

struct Settings {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    void* collisionInput;
    int unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    FlagByte skipObservers;
    FlagByte directIntegrate;
    unsigned short unkb2;
    int minIslandSize;
    int unkb8, unkbc, unkc0, unkc4;
    FlagByte wantSparseCheck;
    byte unkc9;
    unsigned short unkca;
    int unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc;
    Context context;
    __forceinline void* getCollisionInput() const { return collisionInput; }
};

struct SceneIsland {
    int unk00, unk04, unk08;
    int schemaSize;
    int numSolverResults;
    int numSolverElemTemps;
    Settings* world;
    int numConstraints;
    int unk20;
    byte splitCounter;
    bool sparseEnabled : 2;
    bool isSparse : 2;
    byte flagBits : 4;
    unsigned short unk26;
    int unk28, unk2c, unk30, unk34;
    TaskArrayBase<Observer*> observers;
    int unk44;
    TaskArrayBase<void*> entities;
    __forceinline const TaskArrayBase<void*>& GetEntities() const { return entities; }
    __forceinline Settings* getWorld() { return world; }
};

struct BuildCollection {
    void* buildTasks;
    int numBuildTasks;
    void* callbackConstraints;
    int numCallbackConstraints;
    __forceinline BuildCollection() { buildTasks = 0; numBuildTasks = 0; callbackConstraints = 0; numCallbackConstraints = 0; }
};

struct SolveCollection {
    void* firstSolveTask;
    unsigned short numSolveTasks;
    __forceinline SolveCollection() { firstSolveTask = 0; numSolveTasks = 0; }
};

struct JobHeader {
    __forceinline void* operator new(unsigned int nbytes) { return TaskMemory::GetMonitorStream().heap().allocate(nbytes); }
    unsigned int openJobs;
    unsigned int unfinishedJobs;
    unsigned int shouldDeactivate;
    unsigned int refCount;
    unsigned int exportFinishedCount;
    void* buffer;
    void* impulseLimits;
    int bufferCapacity;
    FlagByte exportFinished;
    byte splitRequested;
    unsigned short unk22;
    void* accumulatorsBase;
    int unk28, unk2c;
    void* schemasBase;
    int unk34, unk38;
    void* solverTempBase;
    void* unk40;
    int numSolverResults;
    int numSolverElemTemps;
    const void* queryIn;
    void* const* allEntities;
    unsigned short numAllEntities;
    unsigned short entitiesCapacity;
    FlagByte unk58;
    FlagByte unk59;
    unsigned short unk5a;
    TaskArray<void*> splitIslands;
    BuildCollection tasks;
    SolveCollection solveTasks;
    __forceinline JobHeader() : refCount(1), exportFinishedCount(1), buffer(0), impulseLimits(0), bufferCapacity(0) {}
};

struct DynamicsPacket : PacketBase {
    unsigned short islandIndex;
    unsigned short unk12;
    SceneIsland* island;
    JobHeader* header;
    void* threadData;
    __forceinline DynamicsPacket(unsigned int subType, unsigned short sz, const DynamicsPacket& src, PacketMode m)
        : PacketBase(PACKET_DYNAMICS, subType, sz, m) {
        islandIndex = src.islandIndex;
        island = src.island;
        header = src.header;
        threadData = src.threadData;
    }
};

struct SplitPacket : DynamicsPacket {
    __forceinline SplitPacket(const DynamicsPacket& src, unsigned short sz, unsigned int subType)
        : DynamicsPacket(subType, sz, src, MODE_DISABLED) {}
};

struct ExportPacket : SplitPacket {
    void* solveTask;
    __forceinline ExportPacket(const DynamicsPacket& src, unsigned short sz, const JobHeader& hdr, unsigned int subType)
        : SplitPacket(src, sz, subType) { solveTask = hdr.solveTasks.firstSolveTask; }
};

struct MotionPacket : ExportPacket {
    void* buffer;
    unsigned short numEntities;
    unsigned short firstEntityIdx;
    int unk38;
    FlagByte applyForces;
    __forceinline void* operator new(unsigned int, void* p) { return p; }
    __forceinline MotionPacket(const DynamicsPacket& src, const JobHeader& hdr)
        : ExportPacket(src, 0x40, hdr, 11) {
        firstEntityIdx = 0;
        numEntities = hdr.numAllEntities;
        buffer = hdr.buffer;
        applyForces = false;
    }
};

struct BroadPacket : DynamicsPacket {
    unsigned short numIslands;
    __forceinline void* operator new(unsigned int, void* p) { return p; }
    __forceinline BroadPacket(const DynamicsPacket& src, JobHeader* hdr)
        : DynamicsPacket(12, 48, src, MODE_DISABLED) {
        header = hdr;
        numIslands = 1;
    }
};

struct FinishPacket : DynamicsPacket {
    int unk20;
    __forceinline FinishPacket(const DynamicsPacket& src, JobHeader* hdr)
        : DynamicsPacket(2, 48, src, MODE_ENABLED) {
        header = hdr;
    }
};

}  // namespace fnv_00d95cf0

// @f3 0x00a240d0 (community match, verified in this file)
// Havok 5.5.0 createBuildJacobianAndSolveJacobianTaskCollection (hkpDynamics, hkpCpuIntegrateJob.cpp) for game 0x00a240d0.
// The hk* declarations and inline definitions below are the SDK's own, cut to what this function uses; the classes
// marked "stand-in" keep only the members read here at their offsets.
extern "C" unsigned __int64 __rdtsc(void);
#pragma intrinsic(__rdtsc)
enum hkResult { HK_SUCCESS = 0, HK_FAILURE = 1 };
class hkOstream; class hkClass; class hkpJacobianSchema; class hkpWorld; class hkpEntity; class hkpSimulationIsland;
class hkpConstraintQueryIn; struct hkpImpulseLimitBreachedHeader; class hkMemory; class hkFinishLoadedObjectFlag; class hkStreamWriter; class hkTrackerTypeTreeNode;
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long hkUlong;
typedef __int64 hkInt64;
typedef unsigned int hk_size_t;
typedef hkUint16 hkObjectIndex;
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
#include "havok/hkTimeFunctionHelper.h"
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row, HK_MEMORY_CLASS cl);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateChunk(int numberOfObjects, HK_MEMORY_CLASS cl)
{
	return static_cast<TYPE*>(hkThreadMemory::getInstance().allocateChunk(numberOfObjects*int(sizeof(TYPE)), cl));
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateChunk(TYPE* ptr, int numberOfObjects, HK_MEMORY_CLASS cl)
{
	hkThreadMemory::getInstance().deallocateChunk(static_cast<void*>(ptr), numberOfObjects*int(sizeof(TYPE)), cl);
}
template <typename T>
class hkArray
{
		friend class hkArraySpu;
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline int hkArray<T>::getCapacityAndFlags() const
{
    return m_capacityAndFlags;
}
template <typename T>
__forceinline hkBool hkArray<T>::isEmpty() const
{
	return m_size == 0;
}
template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline hkArray<T>::hkArray(int n)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().allocateChunk(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
		m_size(n),
		m_capacityAndFlags(n)
{
}
template <typename T>
__forceinline hkArray<T>::hkArray(int n, const T& t)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().allocateChunk(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
		m_size(n),
		m_capacityAndFlags(n)
{
	for(int i = 0; i < n; ++i)
	{
		m_data[i] = t;
	}
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
template <typename T>
__forceinline void hkArray<T>::clearAndDeallocate()
{
	releaseMemory();
	m_data = 0;
	m_size = 0;
	m_capacityAndFlags = DONT_DEALLOCATE_FLAG | (m_capacityAndFlags & LOCKED_FLAG);
}
template <typename T>
__forceinline void hkArray<T>::pushBackUnchecked(const T& t)
{
	m_data[m_size++] = t;
}
template <typename T>
__forceinline void hkArray<T>::setSizeUnchecked(int n)
{
	m_size = n;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::end()
{
	return m_data + m_size;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::end() const
{
	return m_data + m_size;
}
template <typename T>
class hkSmallArray
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkSmallArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkSmallArray();
		explicit __forceinline hkSmallArray(int size);
		__forceinline ~hkSmallArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline hkBool isLocked();
		__forceinline T& expandOne( );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void removeAt(int index);
		void removeAtAndCopy(int index);
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		int indexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		__forceinline void pushBack(const T& e);
		__forceinline T& back();
		__forceinline const T& back() const;
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		__forceinline void reserve(int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		void clearAndDeallocate();
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
	public:
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline hkSmallArray<T>::hkSmallArray(int n)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().allocateChunk(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
		m_size(hkUint16(n)),
		m_capacityAndFlags(hkUint16(n))
{
}
template <typename T>
__forceinline int hkSmallArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
typename hkSmallArray<T>::iterator hkSmallArray<T>::begin()
{
	return m_data;
}
template <typename T>
typename hkSmallArray<T>::iterator hkSmallArray<T>::end()
{
	return m_data + m_size;
}
template <typename T>
typename hkSmallArray<T>::const_iterator hkSmallArray<T>::begin() const
{
	return m_data;
}
template <typename T>
typename hkSmallArray<T>::const_iterator hkSmallArray<T>::end() const
{
	return m_data + m_size;
}
int hkThreadMemory::constSizeToRow( int size )
{
	if (size <= 8 )	return 1;
	else if (size <= 16 )	return 2;
	else if (size <= 32 )	return 3;
	else if (size <= 48 )	return 4;
	else if (size <= 64 )	return 5;
	else if (size <= 96 )	return 6;
	else if (size <= 128 )	return 7;
	else if (size <= 160 )	return 8;
	else if (size <= 192 )	return 9;
	else if (size <= 256 )	return 10;
	else if (size <= 320 )	return 11;
	else if (size <= 512 )	return 12;
	else if (size <= 1024)	return 13;
	else if (size <= 2048)	return 14;
	else if (size <= 4096)	return 15;
	else if (size <= 8192)	return 16;
	else
	{
		__debugbreak();
		return -1;
	}
}
void* hkThreadMemory::allocateChunkConstSize(int nbytes, HK_MEMORY_CLASS cl)
{
	int row = constSizeToRow(nbytes);
	if( void* p = m_free_list[row].get() )
	{
		return p;
	}
	return onRowEmpty(row, cl);
}
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0 )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
template <typename T>
class hkPointerMapBase
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MAP); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkPointerMapBase), HK_MEMORY_CLASS_MAP); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MAP); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
		hkPointerMapBase();
		hkPointerMapBase(int numElements);
		hkPointerMapBase(void* ptr, int sizeInBytes);
		~hkPointerMapBase();
		Iterator getIterator() const;
		T getKey( Iterator i ) const;
		T getValue( Iterator i ) const;
		void setValue( Iterator i, T val );
		Iterator getNext( Iterator i ) const;
		hkBool isValid( Iterator i ) const;
		void insert( T key, T val );
		Iterator findKey( T key ) const;
		hkBool hasKey( T key ) const { return isValid(findKey(key)); }
		T getWithDefault( T key, T def ) const;
		hkResult get( T key, T* out ) const;
		void remove( Iterator it );
		hkResult remove( T key );
		int getSize() const { return m_numElems & static_cast<int>(NUM_ELEMS_MASK); }
		int getCapacity() const { return (m_hashMod + 1) & static_cast<int>(NUM_ELEMS_MASK); }
		int getMemSize() const;
		void* getMemStart() const { return m_elem; }
		hkBool isOk() const;
		void clear();
		void swap(hkPointerMapBase& other);
		void reserve( int numElements );
		inline hkBool wasReallocated() const { return ( (m_numElems & static_cast<int>(DONT_DEALLOCATE_FLAG)) == 0 ); }
		static int __cdecl getSizeInBytesFor(int numOfKeys);
	protected:
		static __forceinline T __cdecl pointerHash(T addr, int mod);
		void resizeTable(int capacity);
	protected:
		enum
		{
			NUM_ELEMS_MASK = int(0x7FFFFFFF),
			DONT_DEALLOCATE_FLAG = int(0x80000000)
		};
		T* m_elem;
		int m_numElems;
		int m_hashMod;
};
struct hkpSolverElemTemp
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverElemTemp), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	union
	{
		hkReal m_impulseApplied;
		hkReal m_usedImpulseFactor;
		hkReal m_deltaRhs;
	};
};
typedef void hkpConstraintRuntime;
template <typename T>
class hkLocalArray : public hkArray<T>
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkLocalArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkLocalArray( int capacity )
		{
			this->m_data = hkAllocateStack<T>(capacity);
			this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline void discardAndResize(int newsize)
		{
			hkDeallocateStack<T>( m_localMemory );
			m_localMemory = this->m_data = hkAllocateStack<T>(newsize);
			this->m_size = newsize;
			this->m_capacityAndFlags = newsize | hkArray<T>::DONT_DEALLOCATE_FLAG;
		}
		void assertNotResized()
		{
		}
		hkBool wasReallocated() const
		{
			return m_localMemory != this->m_data;
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};
template <typename T>
class hkFixedArray
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkFixedArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T* begin();
		__forceinline const T* begin() const;
	protected:
		__forceinline	hkFixedArray(){}
		hkPadSpu<T*> m_data;
		int m_debugSize;
};
template <typename T>
class hkLocalBuffer: public hkFixedArray<T>
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkLocalBuffer<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkLocalBuffer(int n, const char* what = 0 );
		__forceinline ~hkLocalBuffer();
};
template <typename T>
__forceinline hkLocalBuffer<T>::hkLocalBuffer( int capacity, const char* what )
{
	this->m_data = hkAllocateStack<T>(capacity);
}
template <typename T>
__forceinline hkLocalBuffer<T>::~hkLocalBuffer()
{
	hkDeallocateStack( this->m_data.val() );
}
template <typename T>
__forceinline T& hkFixedArray<T>::operator[] (int i)
{
	return m_data[i];
}
template <typename T>
__forceinline const T& hkFixedArray<T>::operator[] (int i) const
{
	return m_data[i];
}
template <typename T>
T* hkFixedArray<T>::begin()
{
	return m_data;
}
template <typename T>
const T* hkFixedArray<T>::begin() const
{
	return m_data;
}

// stand-ins (members used here, at the SDK's offsets)
class hkTransform { public: hkReal m_elements[16]; };
class hkpVelocityAccumulator { public: hkReal m_elements[32]; };
struct hkpConstraintAtom { enum CallbackRequest { CALLBACK_REQUEST_NONE = 0, CALLBACK_REQUEST_NEW_CONTACT_POINT = 1, CALLBACK_REQUEST_SETUP_PPU_ONLY = 2, CALLBACK_REQUEST_SETUP_CALLBACK = 4 }; };
struct hkpConstraintInfo { int m_maxSizeOfSchema; int m_sizeOfSchemas; int m_numSolverResults; int m_numSolverElemTemps; };
class hkpConstraintInstance { public: enum ConstraintPriority { PRIORITY_INVALID, PRIORITY_PSI, PRIORITY_TOI, PRIORITY_TOI_HIGHER, PRIORITY_TOI_FORCED }; };
__declspec(align(16)) struct hkConstraintInternal
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_DYNAMICS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkConstraintInternal), HK_MEMORY_CLASS_DYNAMICS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_DYNAMICS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	inline hkpEntity* getOtherEntity( const hkpEntity* entity ) const;
	inline hkpEntity* getMasterEntity() const;
	inline hkpEntity* getSlaveEntity() const;
	inline struct hkpConstraintAtom* getAtoms() const { return m_atoms; }
	inline hkUint16 getAtomsSize() const { return m_atomsSize; }
	inline void clearConstraintInfo( );
	public:
		class hkpConstraintInstance* m_constraint;
		class hkpEntity*	  m_entities[2];
	protected:
		friend class hkpWorldConstraintUtil;
		struct hkpConstraintAtom* m_atoms;
		hkUint16 m_atomsSize;
	public:
		hkUint8	m_callbackRequest;
		hkEnum<hkpConstraintInstance::ConstraintPriority,hkUint8> m_priority;
		hkUint16 m_sizeOfSchemas;
		hkUint16 m_numSolverResults;
		hkUint16 m_numSolverElemTemps;
		inline void getConstraintInfo( hkpConstraintInfo& info ) const;
		inline void addConstraintInfo( const hkpConstraintInfo& delta );
		inline void subConstraintInfo( const hkpConstraintInfo& delta );
		hkUint8	m_whoIsMaster;
		hkBool m_isNormalType;
		hkpConstraintRuntime*	m_runtime;
		hkUint16			m_runtimeSize;
		hkObjectIndex		m_slaveIndex;
		friend class hkpSaveContactPointsUtil;
};

class hkpSimulationIsland
{
	public:
		virtual ~hkpSimulationIsland();
		hkUint16 m_memSizeAndFlags;
		hkUint16 m_referenceCount;
		hkpConstraintInfo m_constraintInfo;
		hkpWorld* m_world;
		int m_numConstraints;
		int m_unknown20[10];
		hkArray<hkpEntity*> m_entities;
};
class hkpMotion
{
	public:
		inline const hkTransform& getTransform() const { return m_transform; }
		int m_unknown00[4];
		hkTransform m_transform;
};
class hkpEntity
{
	public:
		inline const hkSmallArray<struct hkConstraintInternal>& getConstraintMasters() const { return m_constraintsMaster; }
		inline hkpMotion* getMotion() { return &m_motion; }
		int m_unknown00[36];
		hkUint32 m_solverData;
		hkObjectIndex m_storageIndex;
		hkObjectIndex m_unknown96;
		hkSmallArray<struct hkConstraintInternal> m_constraintsMaster;
		int m_unknownA0[12];
		hkpMotion m_motion;
};
struct hkpBuildJacobianTask;
struct hkpSolveConstraintBatchTask;
struct hkpBuildJacobianTaskCollection
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpBuildJacobianTaskCollection), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpBuildJacobianTask* m_buildJacobianTasks;
	int m_numBuildJacobianTasks;
	const hkConstraintInternal** m_callbackConstraints;
	int m_numCallbackConstraints;
};
struct hkpSolveJacobiansTaskCollection
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolveJacobiansTaskCollection), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpSolveConstraintBatchTask* m_firstSolveJacobiansTask;
	hkUint16 m_firstBatchSize;
};
struct hkpBuildJacobianTaskHeader
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpBuildJacobianTaskHeader), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	int m_openJobs;
	int m_numUnfinishedJobsForBroadphase;
	int m_islandShouldBeDeactivated;
	long m_referenceCount;
	int m_numIslandsAfterSplit;
	void* m_buffer;
	int m_bufferSize;
	signed char m_exportFinished;
	signed char m_splitCheckRequested;
	struct hkpImpulseLimitBreachedHeader* m_impulseLimitsBreached;
	int m_pad[3];
	hkpVelocityAccumulator* m_accumulatorsBase;
	hkpVelocityAccumulator* m_accumulatorsEnd;
	hkUint16 m_numApplyGravityJobs;
	hkUint16 m_numIntegrateVelocitiesJobs;
	hkpJacobianSchema* m_schemasBase;
	hkpSolverElemTemp* m_solverTempBase;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	const class hkpConstraintQueryIn* m_constraintQueryIn;
	hkpEntity*const* m_allEntities;
	hkUint16 m_numAllEntities;
	hkUint16 m_entitiesCapacity;
	hkBool m_solveInSingleThread;
	hkBool m_solveInSingleThreadOnPpuOnly;
	hkArray<hkpSimulationIsland*> m_newSplitIslands;
	hkpBuildJacobianTaskCollection m_tasks;
	hkpSolveJacobiansTaskCollection m_solveTasks;
};
struct hkpBuildJacobianTask
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpBuildJacobianTask), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	enum { MAX_NUM_ATOM_INFOS = 144 };
	struct AtomInfo
	{
		hkpConstraintAtom* m_atoms;
		hkpConstraintInstance* m_instance;
		void* m_runtime;
		const hkTransform* m_transformA;
		const hkTransform* m_transformB;
		hkUint16 m_atomsSize;
		hkUint16 m_runtimeSize;
		hkUint16 m_accumulatorIndexA;
		hkUint16 m_accumulatorIndexB;
	};
	hkpBuildJacobianTask()
	{
		m_numAtomInfos = 0;
		m_schemasOfNextTask = 0;
		m_next = 0;
	}
	hkpBuildJacobianTask* m_next;
	hkpBuildJacobianTaskHeader* m_taskHeader;
	const hkpVelocityAccumulator* m_accumulators;
	hkpJacobianSchema* m_schemas;
	hkpJacobianSchema* m_schemasOfNextTask;
	int m_numAtomInfos;
	AtomInfo m_atomInfos[MAX_NUM_ATOM_INFOS];
	hkUchar m_padding[0x1000 - 0x18 - 144*0x1c];
};
struct hkpSolveConstraintBatchTask
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolveConstraintBatchTask), HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpSolveConstraintBatchTask()
	{
		m_next = 0;
		m_isLastTaskInBatch = false;
		m_sizeOfNextBatch = 0;
		m_firstTaskInNextBatch = 0;
	}
	hkpSolveConstraintBatchTask* m_next;
	hkpBuildJacobianTaskHeader* m_taskHeader;
	hkpVelocityAccumulator* m_accumulators;
	const hkpJacobianSchema* m_schemas;
	hkpSolverElemTemp* m_solverElemTemp;
	int m_sizeOfSchemaBuffer;
	int m_sizeOfSolverElemTempBuffer;
	hkBool m_isLastTaskInBatch;
	hkUint16 m_sizeOfNextBatch;
	hkpSolveConstraintBatchTask* m_firstTaskInNextBatch;
	int m_pad[3];
};
namespace anon_00a240d0 {} using namespace anon_00a240d0; namespace anon_00a240d0 {
	__declspec(align(8)) struct hkConstraintInternalInfo
	{
		const hkConstraintInternal* m_internal;
		hkObjectIndex m_entityAIndex;
		hkObjectIndex m_entityBIndex;
	};
}
static __forceinline void createAndAppendNewTask( const hkpBuildJacobianTaskHeader* taskHeader, hkpBuildJacobianTaskCollection* outBuildCollection, hkpSolveJacobiansTaskCollection* outSolveCollection,
	hkpBuildJacobianTask*& prevBuildTask, hkpSolveConstraintBatchTask*& prevSolveTask, hkpSolveConstraintBatchTask*& firstTaskOfPreviousBatch, hkpSolveConstraintBatchTask*& firstTaskOfCurrentBatch,
	hkpJacobianSchema*& schemas, hkpSolverElemTemp*& elemTemp, hkLocalArray<hkConstraintInternalInfo>& constraintsForThisTask,
	int& batchIndexOfLastTask, int currentBatchIndex, hkUint16*& ptrToBatchSize,
	hkBool putOnPpuOnlyBuildJacobianTaskList, hkBool generateSolveTasks )
{
	hkpJacobianSchema*const schemaStart = schemas;
	hkpSolverElemTemp*const elemTempStart = elemTemp;
	{
		hkpBuildJacobianTask* buildTask = new hkpBuildJacobianTask;
		if ( !prevBuildTask )
		{
			if ( !putOnPpuOnlyBuildJacobianTaskList )
			{
				outBuildCollection->m_buildJacobianTasks = buildTask;
				outBuildCollection->m_numBuildJacobianTasks = 0;
			}
		}
		else
		{
			prevBuildTask->m_next = buildTask;
			prevBuildTask->m_schemasOfNextTask = schemas;
		}
		outBuildCollection->m_numBuildJacobianTasks++;
		buildTask->m_taskHeader = const_cast<hkpBuildJacobianTaskHeader*>(taskHeader);
		buildTask->m_numAtomInfos = constraintsForThisTask.getSize();
		buildTask->m_accumulators = taskHeader->m_accumulatorsBase;
		buildTask->m_schemas = schemaStart;
		int numConstraints = constraintsForThisTask.getSize();
		for (int i = 0; i < numConstraints; i++)
		{
			const hkConstraintInternalInfo& info = constraintsForThisTask[i];
			const hkConstraintInternal* ci = info.m_internal;
			hkpBuildJacobianTask::AtomInfo& atomInfo = buildTask->m_atomInfos[i];
			atomInfo.m_atoms = ci->getAtoms();
			atomInfo.m_atomsSize = ci->getAtomsSize();
			atomInfo.m_instance = ci->m_constraint;
			atomInfo.m_runtime = ci->m_runtime;
			atomInfo.m_runtimeSize = ci->m_runtimeSize;
			int entityAIndex = info.m_entityAIndex;
			int entityBIndex = info.m_entityBIndex;
			atomInfo.m_accumulatorIndexA = hkObjectIndex(entityAIndex + 1);
			atomInfo.m_accumulatorIndexB = hkObjectIndex(entityBIndex + 1);
			atomInfo.m_transformA = &ci->m_entities[0]->getMotion()->getTransform();
			atomInfo.m_transformB = &ci->m_entities[1]->getMotion()->getTransform();
			schemas = hkAddByteOffset( schemas, ci->m_sizeOfSchemas );
			elemTemp += ci->m_numSolverElemTemps;
		}
		constraintsForThisTask.clear();
		schemas = hkAddByteOffset( schemas, 16 );
		buildTask->m_schemasOfNextTask = schemas;
		elemTemp = reinterpret_cast<hkpSolverElemTemp*>( ( ((hkUlong(elemTemp)) + ((16)-1)) & (~((16)-1)) ) );
		prevBuildTask = buildTask;
	}
	if ( generateSolveTasks )
	{
		hkpSolveConstraintBatchTask* solveTask = new hkpSolveConstraintBatchTask;
		if ( prevSolveTask )
		{
			prevSolveTask->m_next = solveTask;
		}
		if ( currentBatchIndex != batchIndexOfLastTask )
		{
			if ( currentBatchIndex == 0 )
			{
				outSolveCollection->m_firstSolveJacobiansTask = solveTask;
			}
			batchIndexOfLastTask = currentBatchIndex;
			if ( prevSolveTask )
			{
				hkpSolveConstraintBatchTask* aTaskFromPreviousBatch = firstTaskOfPreviousBatch;
				hkUint16 batchSize = *ptrToBatchSize;
				while ( aTaskFromPreviousBatch && aTaskFromPreviousBatch != firstTaskOfCurrentBatch )
				{
					aTaskFromPreviousBatch->m_sizeOfNextBatch = batchSize;
					aTaskFromPreviousBatch->m_firstTaskInNextBatch = firstTaskOfCurrentBatch;
					aTaskFromPreviousBatch = aTaskFromPreviousBatch->m_next;
				}
				prevSolveTask->m_isLastTaskInBatch = true;
				ptrToBatchSize = &prevSolveTask->m_sizeOfNextBatch;
			}
			firstTaskOfPreviousBatch = firstTaskOfCurrentBatch;
			firstTaskOfCurrentBatch = solveTask;
		}
		(*ptrToBatchSize)++;
		solveTask->m_taskHeader = const_cast<hkpBuildJacobianTaskHeader*>(taskHeader);
		solveTask->m_accumulators = taskHeader->m_accumulatorsBase;
		solveTask->m_schemas = schemaStart;
		solveTask->m_solverElemTemp = elemTempStart;
		solveTask->m_sizeOfSchemaBuffer = int( hkUlong(schemas) - hkUlong(schemaStart) );
		solveTask->m_sizeOfSolverElemTempBuffer = int( hkUlong(elemTemp) - hkUlong(elemTempStart) );
		prevSolveTask = solveTask;
	}
}
// pdb: createBuildJacobianAndSolveJacobianTaskCollection | hkpCpuIntegrateJob.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
static void createBuildJacobianAndSolveJacobianTaskCollection(SceneIsland* islandArg, FlagByte forceCoherentConstraintOrderingInSolver, JobHeader* headerArg, BuildCollection* buildsArg, SolveCollection* solvesArg)
{
	hkpSimulationIsland*const island = reinterpret_cast<hkpSimulationIsland*>(islandArg);
	hkpBuildJacobianTaskHeader*const taskHeader = reinterpret_cast<hkpBuildJacobianTaskHeader*>(headerArg);
	hkpBuildJacobianTaskCollection*const outBuildCollection = reinterpret_cast<hkpBuildJacobianTaskCollection*>(buildsArg);
	hkpSolveJacobiansTaskCollection*const outSolveCollection = reinterpret_cast<hkpSolveJacobiansTaskCollection*>(solvesArg);

	HK_TIME_CODE_BLOCK("BuildJacTask", HK_NULL);
	hkpEntity*const*const bodies = island->m_entities.begin();
	int numBodies = island->m_entities.getSize();
	hkpEntity*const*const bodiesEnd = bodies + numBodies;
	hkLocalArray<hkConstraintInternalInfo> normalPriorityConstraints( island->m_numConstraints );
	hkLocalArray<hkConstraintInternalInfo> highPriorityConstraints( island->m_numConstraints );
	hkLocalArray<hkConstraintInternalInfo> callbackConstraints( island->m_numConstraints );
	int allConstraintsNormalType = 1;
	{
		int po2 = 64; while ( po2 < numBodies ) { po2 *= 2; }
		po2 *= 4;
		hkLocalBuffer<hkUlong> pointerBuffer( po2 );
		hkPointerMapBase<hkUlong> entityPtrToIndex( pointerBuffer.begin(), po2 * int(sizeof(hkUlong)) );
		for (int bi = 0; bi < numBodies; bi++)
		{
			entityPtrToIndex.insert( hkUlong(bodies[bi]), bi );
		}
		hkpEntity*const* b = bodies;
		hkUint32 accumOffset = sizeof(hkpVelocityAccumulator);
		int bi;
		for ( b = bodies, bi = 0; b < bodiesEnd; b++, bi++ )
		{
			hkpEntity* body = *b;
			if ( accumOffset != body->m_solverData )
			{
				body->m_solverData = accumOffset;
			}
			accumOffset += sizeof(hkpVelocityAccumulator);
			const hkConstraintInternal* c = body->getConstraintMasters().begin();
			const hkConstraintInternal* cEnd = body->getConstraintMasters().end();
			for ( ; c < cEnd; c++ )
			{
				hkConstraintInternalInfo info;
				info.m_internal = c;
				hkObjectIndex* entityIndices = &info.m_entityAIndex;
				const int whoIsSlave = 1 - c->m_whoIsMaster;
				entityIndices[c->m_whoIsMaster] = hkObjectIndex(bi);
				entityIndices[whoIsSlave] = hkObjectIndex(entityPtrToIndex.getWithDefault( hkUlong(c->m_entities[whoIsSlave]), 0xffff ));
				allConstraintsNormalType &= c->m_isNormalType;
				if ( c->m_callbackRequest & ( hkpConstraintAtom::CALLBACK_REQUEST_NEW_CONTACT_POINT | hkpConstraintAtom::CALLBACK_REQUEST_SETUP_PPU_ONLY ) )
				{
					callbackConstraints.pushBackUnchecked( info );
				}
				if ( c->m_priority < hkpConstraintInstance::PRIORITY_TOI_HIGHER )
				{
					normalPriorityConstraints.pushBackUnchecked( info );
				}
				else
				{
					highPriorityConstraints.pushBackUnchecked( info );
				}
			}
		}
	}
	HK_MONITOR_ADD_VALUE("NumEntities", float(numBodies), HK_MONITOR_TYPE_INT);
	HK_MONITOR_ADD_VALUE("NumConstraints", float(island->m_numConstraints), HK_MONITOR_TYPE_INT);
	HK_MONITOR_ADD_VALUE("NumJacobians", float(island->m_constraintInfo.m_numSolverResults), HK_MONITOR_TYPE_INT);
	taskHeader->m_solveInSingleThreadOnPpuOnly = !allConstraintsNormalType;
	taskHeader->m_solveInSingleThread = taskHeader->m_solveInSingleThreadOnPpuOnly || hkBool(false);
	hkBool generateSolveTasks = !taskHeader->m_solveInSingleThread;
	hkpJacobianSchema* schemas = taskHeader->m_schemasBase;
	hkpSolverElemTemp* elemTemp = taskHeader->m_solverTempBase;
	int currentBatchIndex = -1;
	int batchIndexOfLastTask = -1;
	hkUint16* ptrToBatchSize = &outSolveCollection->m_firstBatchSize;
	*ptrToBatchSize = 0;
	hkpBuildJacobianTask* prevBuildTask = 0;
	hkpSolveConstraintBatchTask* prevSolveTask = 0;
	hkpSolveConstraintBatchTask* firstTaskOfPreviousBatch = 0;
	hkpSolveConstraintBatchTask* firstTaskOfCurrentBatch = 0;
	hkLocalArray<hkConstraintInternalInfo> constraintsForNextTask( hkpBuildJacobianTask::MAX_NUM_ATOM_INFOS );
	hkLocalBuffer<int> entityGroup( numBodies );
	for (int il = 0; il < 2; il++)
	{
		hkBool putOnPpuOnlyBuildJacobianTaskList = false;
		hkLocalArray<hkConstraintInternalInfo>* sourceConstraints;
		switch ( il )
		{
			case 0: sourceConstraints = &normalPriorityConstraints; prevBuildTask = 0; break;
			default: sourceConstraints = &highPriorityConstraints; break;
		}
		while ( sourceConstraints->getSize() )
		{
			{ for (int i = 0; i < numBodies; entityGroup[i++] = 0) { } }
			int currentGroup = 1;
			currentBatchIndex++;
			hkConstraintInternalInfo* c = sourceConstraints->begin();
			hkConstraintInternalInfo*const cEnd = sourceConstraints->end();
			hkConstraintInternalInfo* nextConstraintLeftOut = sourceConstraints->begin();
			for ( ; c < cEnd; c++ )
			{
				const hkConstraintInternalInfo& info = *c;
				int fixedEntityGroup = 0;
				int& entityAGroup = info.m_entityAIndex == 0xffff ? fixedEntityGroup : entityGroup[info.m_entityAIndex];
				int& entityBGroup = info.m_entityBIndex == 0xffff ? fixedEntityGroup : entityGroup[info.m_entityBIndex];
				if ( constraintsForNextTask.getSize() == hkpBuildJacobianTask::MAX_NUM_ATOM_INFOS )
				{
					createAndAppendNewTask( taskHeader, outBuildCollection, outSolveCollection, prevBuildTask, prevSolveTask, firstTaskOfPreviousBatch, firstTaskOfCurrentBatch, schemas, elemTemp, constraintsForNextTask, batchIndexOfLastTask, currentBatchIndex, ptrToBatchSize, putOnPpuOnlyBuildJacobianTaskList, generateSolveTasks );
					currentGroup += generateSolveTasks;
				}
				if ( forceCoherentConstraintOrderingInSolver && currentGroup > 1 )
				{
					for ( ; c < cEnd; c++ )
					{
						*(nextConstraintLeftOut++) = *c;
					}
					break;
				}
				else
				{
					if ( (entityAGroup && entityAGroup != currentGroup) || (entityBGroup && entityBGroup != currentGroup) )
					{
						*(nextConstraintLeftOut++) = *c;
					}
					else
					{
						constraintsForNextTask.pushBackUnchecked( *c );
						entityAGroup = currentGroup;
						entityBGroup = currentGroup;
					}
				}
			}
			if ( constraintsForNextTask.getSize() )
			{
				createAndAppendNewTask( taskHeader, outBuildCollection, outSolveCollection, prevBuildTask, prevSolveTask, firstTaskOfPreviousBatch, firstTaskOfCurrentBatch, schemas, elemTemp, constraintsForNextTask, batchIndexOfLastTask, currentBatchIndex, ptrToBatchSize, putOnPpuOnlyBuildJacobianTaskList, generateSolveTasks );
				currentGroup++;
			}
			const int newSourceConstraintsSize = int( nextConstraintLeftOut - sourceConstraints->begin() );
			sourceConstraints->setSizeUnchecked( newSourceConstraintsSize );
		}
	}
	if ( generateSolveTasks )
	{
		hkpSolveConstraintBatchTask* aTaskFromPreviousBatch = firstTaskOfPreviousBatch;
		hkUint16 batchSize = *ptrToBatchSize;
		while ( aTaskFromPreviousBatch && aTaskFromPreviousBatch != firstTaskOfCurrentBatch )
		{
			aTaskFromPreviousBatch->m_sizeOfNextBatch = batchSize;
			aTaskFromPreviousBatch->m_firstTaskInNextBatch = firstTaskOfCurrentBatch;
			aTaskFromPreviousBatch = aTaskFromPreviousBatch->m_next;
		}
		prevSolveTask->m_isLastTaskInBatch = true;
		const hkUint32 numAccumulators = taskHeader->m_numAllEntities + 1;
		taskHeader->m_accumulatorsEnd = taskHeader->m_accumulatorsBase + numAccumulators;
		taskHeader->m_numApplyGravityJobs = hkUint16( (numAccumulators - 1) / 128 + 1 );
		taskHeader->m_numIntegrateVelocitiesJobs = hkUint16( (numAccumulators - 1) / 128 + 1 );
	}
	outBuildCollection->m_numCallbackConstraints = 0;
	outBuildCollection->m_callbackConstraints = 0;
	int numCC = callbackConstraints.getSize();
	if ( numCC )
	{
		const hkConstraintInternal** cc = hkAllocateChunk<const hkConstraintInternal*>( numCC, HK_MEMORY_CLASS_CONSTRAINT_SOLVER );
		outBuildCollection->m_numCallbackConstraints = numCC;
		outBuildCollection->m_callbackConstraints = cc;
		for (int i = 0; i < numCC; i++)
		{
			cc[i] = callbackConstraints[i].m_internal;
		}
	}
}

// Diagnostic reconstruction of the collection call in integrateJob, lines 950, 956 and 957.
void hkCpuIntegrateJobCaller( SceneIsland* island, JobHeader* taskHeader, FlagByte coherent )
{
    hkpBuildJacobianTaskHeader* header = reinterpret_cast<hkpBuildJacobianTaskHeader*>(taskHeader);
    hkpBuildJacobianTaskCollection outBuildCollection = { 0 };
    hkpSolveJacobiansTaskCollection outSolveCollection = { 0 };
    createBuildJacobianAndSolveJacobianTaskCollection( island, coherent, taskHeader, reinterpret_cast<BuildCollection*>(&outBuildCollection), reinterpret_cast<SolveCollection*>(&outSolveCollection) );
    header->m_tasks = outBuildCollection;
    header->m_solveTasks = outSolveCollection;
}

// @f3 0x00a23e70 (community match, verified in this file)
namespace f3m_00a23e70 {
namespace f3m_00a23e70
{
// 0x00a23e70 is Havok's createAndAppendNewTask compiled out of line (0x00a240d0 inlines it at both call sites).
// pdb: createAndAppendNewTask | hkpCpuIntegrateJob.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00a23e70( const hkpBuildJacobianTaskHeader* taskHeader, hkpBuildJacobianTaskCollection* outBuildCollection, hkpSolveJacobiansTaskCollection* outSolveCollection,
	hkpBuildJacobianTask*& prevBuildTask, hkpSolveConstraintBatchTask*& prevSolveTask, hkpSolveConstraintBatchTask*& firstTaskOfPreviousBatch, hkpSolveConstraintBatchTask*& firstTaskOfCurrentBatch,
	hkpJacobianSchema*& schemas, hkpSolverElemTemp*& elemTemp, hkLocalArray<hkConstraintInternalInfo>& constraintsForThisTask,
	int& batchIndexOfLastTask, int currentBatchIndex, hkUint16*& ptrToBatchSize,
	hkBool putOnPpuOnlyBuildJacobianTaskList, hkBool generateSolveTasks )
{
	hkpJacobianSchema*const schemaStart = schemas;
	hkpSolverElemTemp*const elemTempStart = elemTemp;
	{
		hkpBuildJacobianTask* buildTask = new hkpBuildJacobianTask;
		if ( !prevBuildTask )
		{
			if ( !putOnPpuOnlyBuildJacobianTaskList )
			{
				outBuildCollection->m_buildJacobianTasks = buildTask;
				outBuildCollection->m_numBuildJacobianTasks = 0;
			}
		}
		else
		{
			prevBuildTask->m_next = buildTask;
			prevBuildTask->m_schemasOfNextTask = schemas;
		}
		outBuildCollection->m_numBuildJacobianTasks++;
		buildTask->m_taskHeader = const_cast<hkpBuildJacobianTaskHeader*>(taskHeader);
		buildTask->m_numAtomInfos = constraintsForThisTask.getSize();
		buildTask->m_accumulators = taskHeader->m_accumulatorsBase;
		buildTask->m_schemas = schemaStart;
		int numConstraints = constraintsForThisTask.getSize();
		for (int i = 0; i < numConstraints; i++)
		{
			const hkConstraintInternalInfo& info = constraintsForThisTask[i];
			const hkConstraintInternal* ci = info.m_internal;
			hkpBuildJacobianTask::AtomInfo& atomInfo = buildTask->m_atomInfos[i];
			atomInfo.m_atoms = ci->getAtoms();
			atomInfo.m_atomsSize = ci->getAtomsSize();
			atomInfo.m_instance = ci->m_constraint;
			atomInfo.m_runtime = ci->m_runtime;
			atomInfo.m_runtimeSize = ci->m_runtimeSize;
			int entityAIndex = info.m_entityAIndex;
			int entityBIndex = info.m_entityBIndex;
			atomInfo.m_accumulatorIndexA = hkObjectIndex(entityAIndex + 1);
			atomInfo.m_accumulatorIndexB = hkObjectIndex(entityBIndex + 1);
			atomInfo.m_transformA = &ci->m_entities[0]->getMotion()->getTransform();
			atomInfo.m_transformB = &ci->m_entities[1]->getMotion()->getTransform();
			schemas = hkAddByteOffset( schemas, ci->m_sizeOfSchemas );
			elemTemp += ci->m_numSolverElemTemps;
		}
		constraintsForThisTask.clear();
		schemas = hkAddByteOffset( schemas, 16 );
		buildTask->m_schemasOfNextTask = schemas;
		elemTemp = reinterpret_cast<hkpSolverElemTemp*>( ( ((hkUlong(elemTemp)) + ((16)-1)) & (~((16)-1)) ) );
		prevBuildTask = buildTask;
	}
	if ( generateSolveTasks )
	{
		hkpSolveConstraintBatchTask* solveTask = new hkpSolveConstraintBatchTask;
		if ( prevSolveTask )
		{
			prevSolveTask->m_next = solveTask;
		}
		if ( currentBatchIndex != batchIndexOfLastTask )
		{
			if ( currentBatchIndex == 0 )
			{
				outSolveCollection->m_firstSolveJacobiansTask = solveTask;
			}
			batchIndexOfLastTask = currentBatchIndex;
			if ( prevSolveTask )
			{
				hkpSolveConstraintBatchTask* aTaskFromPreviousBatch = firstTaskOfPreviousBatch;
				hkUint16 batchSize = *ptrToBatchSize;
				while ( aTaskFromPreviousBatch && aTaskFromPreviousBatch != firstTaskOfCurrentBatch )
				{
					aTaskFromPreviousBatch->m_sizeOfNextBatch = batchSize;
					aTaskFromPreviousBatch->m_firstTaskInNextBatch = firstTaskOfCurrentBatch;
					aTaskFromPreviousBatch = aTaskFromPreviousBatch->m_next;
				}
				prevSolveTask->m_isLastTaskInBatch = true;
				ptrToBatchSize = &prevSolveTask->m_sizeOfNextBatch;
			}
			firstTaskOfPreviousBatch = firstTaskOfCurrentBatch;
			firstTaskOfCurrentBatch = solveTask;
		}
		(*ptrToBatchSize)++;
		solveTask->m_taskHeader = const_cast<hkpBuildJacobianTaskHeader*>(taskHeader);
		solveTask->m_accumulators = taskHeader->m_accumulatorsBase;
		solveTask->m_schemas = schemaStart;
		solveTask->m_solverElemTemp = elemTempStart;
		solveTask->m_sizeOfSchemaBuffer = int( hkUlong(schemas) - hkUlong(schemaStart) );
		solveTask->m_sizeOfSolverElemTempBuffer = int( hkUlong(elemTemp) - hkUlong(elemTempStart) );
		prevSolveTask = solveTask;
	}
}

void Caller00a23e70( const hkpBuildJacobianTaskHeader* taskHeader, hkpBuildJacobianTaskCollection* outBuildCollection, hkpSolveJacobiansTaskCollection* outSolveCollection,
	hkpBuildJacobianTask*& prevBuildTask, hkpSolveConstraintBatchTask*& prevSolveTask, hkpSolveConstraintBatchTask*& firstTaskOfPreviousBatch, hkpSolveConstraintBatchTask*& firstTaskOfCurrentBatch,
	hkpJacobianSchema*& schemas, hkpSolverElemTemp*& elemTemp, hkLocalArray<hkConstraintInternalInfo>& constraintsForThisTask,
	int& batchIndexOfLastTask, int currentBatchIndex, hkUint16*& ptrToBatchSize,
	hkBool putOnPpuOnlyBuildJacobianTaskList, hkBool generateSolveTasks )
{
	FUN_00a23e70( taskHeader, outBuildCollection, outSolveCollection, prevBuildTask, prevSolveTask, firstTaskOfPreviousBatch, firstTaskOfCurrentBatch,
		schemas, elemTemp, constraintsForThisTask, batchIndexOfLastTask, currentBatchIndex, ptrToBatchSize, putOnPpuOnlyBuildJacobianTaskList, generateSolveTasks );
}
}
}   // namespace f3m_00a23e70
