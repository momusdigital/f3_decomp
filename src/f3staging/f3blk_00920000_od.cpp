// src/f3staging/f3blk_00920000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0092eaa0 (community match, verified in this file)
namespace f3m_0092eaa0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
}
extern unsigned long DAT_010f3170;
namespace f3m_0092eaa0 {
struct hkThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    static hkThreadMemory* getInstance() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};
typedef void (__cdecl* hkErrorReportFunction)(const char* msg, void* obj);
}

class hkBaseObject {
public:
    virtual ~hkBaseObject() throw() {}
};
class hkReferencedObject : public hkBaseObject {
public:
    static void* operator new(unsigned int n) throw() {
        void* p = f3m_0092eaa0::hkThreadMemory::getInstance()->FUN_008f6d30(n, 0x15);
        ((unsigned short*)p)[2] = (unsigned short)n;
        return p;
    }
    hkReferencedObject() throw() : referenceCount(1) {}
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
class hkFileSystem : public hkReferencedObject {
public:
    hkFileSystem() throw() {}
};
class hkNativeFileSystem : public hkFileSystem {
public:
    hkNativeFileSystem() throw() {}
    virtual ~hkNativeFileSystem() throw();
};

namespace f3m_0092eaa0 {
class FUN_0092efd0 : public hkReferencedObject {
public:
    FUN_0092efd0(hkErrorReportFunction func, void* obj) throw();
    int pad[8];
};

extern bool DAT_010f3408;
struct Singletons { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); };
extern Singletons* DAT_010f3404;
void __cdecl FUN_0092e830(void* memory) throw();
void __cdecl FUN_0092e8f0(void* threadMemory) throw();
void __cdecl FUN_0056b5b0(hkFileSystem* fs) throw();
void __cdecl FUN_0056b560(hkReferencedObject* error) throw();
void __cdecl hkBaseSystem_initSingletons() throw();

// pdb: hkBaseSystem::init | hkBaseSystem.obj | fnv360_0822_retail, uvref, medium
// pdb params: memoryRouter, errorReportFunction, errorReportObject
int __cdecl FUN_0092eaa0(void* memoryManager, void* threadMemory, hkErrorReportFunction errorReportFunction, void* errorReportObject)
{
    if (!DAT_010f3408) {
        if (memoryManager) {
            FUN_0092e830(memoryManager);
            if (threadMemory) {
                FUN_0092e8f0(threadMemory);
                FUN_0056b5b0(new hkNativeFileSystem());
                FUN_0056b560(new FUN_0092efd0(errorReportFunction, errorReportObject));
                hkBaseSystem_initSingletons();
                DAT_010f3404->v3();
                DAT_010f3408 = true;
            } else {
    char buf[] = "No thread memory manager specified. \t\t\t\t\t\t\t\t\t  You must specify a thread memory manager when initializing hkBaseSystem.";
                errorReportFunction(buf, errorReportObject);
                return 1;
            }
        } else {
    char buf[] = "No memory manager system specified. \t\t\t\t\t\t\t\t You must specify a memory manager when initializing hkBaseSystem. \t\t\t\t\t\t\t\t Use hkPoolMemory if no memory manager is present or no custom memory \t\t\t\t\t\t\t\t manager is available.";
            errorReportFunction(buf, errorReportObject);
            return 1;
        }
    }
    return 0;
}
}

// @f3 0x00925b30 (community match, verified in this file)
namespace f3m_00925b30 {
namespace f3m_00925b30 {

typedef float hkReal;

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setMul4(hkReal r, const hkVector4& v)
    { for (int i = 0; i < 4; i++) m_quad[i] = r * v.m_quad[i]; }
    __forceinline void addMul4(hkReal rr, const hkVector4& v)
    { hkReal r = rr; m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1]; m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3]; }
    __forceinline void addMul4b(hkReal r, const hkVector4& v)
    { m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1]; m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        for (int i = 0; i < 4; i++) m_quad[i] = a.m_quad[i] + b.m_quad[i];
    }
    __forceinline void add4l(const hkVector4& a)
    { for (int i = 0; i < 4; i++) m_quad[i] += a.m_quad[i]; }
    __forceinline void add4(const hkVector4& a)
    {
        m_quad[0] += a.m_quad[0]; m_quad[1] += a.m_quad[1]; m_quad[2] += a.m_quad[2]; m_quad[3] += a.m_quad[3];
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    { return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2]; }
    __forceinline void setRotatedDir(const struct hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    { const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1); const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2); const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0); set(nx, ny, nz, 0.0f); }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.m_quad[3]; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4b(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

class BodyBase
{
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void getRotation(hkQuaternion& q);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

class Body : public BodyBase
{
public:
    hkVector4 m_offset;

    void FUN_008fe990(const hkVector4& p);
    void FUN_00925b30(const hkVector4& pos);
};

}

// pdb: bhkRigidBodyT::SetPosition | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: arPos
void f3m_00925b30::Body::FUN_00925b30(const hkVector4& pos)
{
    if (this && unk08)
    {
        hkQuaternion q;
        getRotation(q);
        hkVector4 v;
        v.setRotatedDir(q, m_offset);
        v.add4(pos);
        FUN_008fe990(v);
    }
}
}   // namespace f3m_00925b30

// @f3 0x0093cb50 (community match, verified in this file)
namespace f3m_0093cb50 {
namespace o55_0093cb50 {

struct Klass {
    int FUN_009b0760() const;
};

struct Variant {
    void* object;
    const Klass* klass;
};

struct Tracker;

struct Bool {
    char value;
    Bool() {}
    operator bool() const { return value != 0; }
};

struct ClassView {
    Variant variant;
    ClassView() {}
    const Klass& getClass() const { return *variant.klass; }
};

struct MemberView {
    struct SimpleArray {
        void* data;
        int size;
    };
    void* address;
    const void* member;

    MemberView() {}
    MemberView& FUN_0093d600(const Variant& v, const char* name);
    Bool FUN_0093d640() const;
    void*& FUN_0093d670(int index) const;
    SimpleArray& FUN_0093d760(int index) const;
    ClassView FUN_0093d810() const;
};

// pdb: hkDataObjectNative::hasMember | hkDataObjectNative.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|vtable) + skyrim(caller_sim), high
static __declspec(noinline) void hkDataObjectNative_hasMember(Variant& obj, const char* name)
{
    MemberView field;
    field.FUN_0093d600(obj, name);
    if (field.FUN_0093d640()) {
        field.FUN_0093d670(0) = 0;
    }
}

__declspec(noinline) void __cdecl FUN_0093cb40(Variant& oldObj, Variant& newObj, Tracker& tracker)
{
    hkDataObjectNative_hasMember(newObj, "contactBody");
}

}

void __cdecl FUN_0093cb50(o55_0093cb50::Variant& oldObj, o55_0093cb50::Variant& newObj, o55_0093cb50::Tracker& tracker)
{
    using namespace o55_0093cb50;
    MemberView oldWheels;
    oldWheels.FUN_0093d600(oldObj, "wheelsInfo");
    MemberView newWheels;
    newWheels.FUN_0093d600(newObj, "wheelsInfo");

    MemberView::SimpleArray& oldArray = oldWheels.FUN_0093d760(0);
    MemberView::SimpleArray& newArray = newWheels.FUN_0093d760(0);

    Variant oldVariant = { 0, &oldWheels.FUN_0093d810().getClass() };
    Variant newVariant = { 0, &newWheels.FUN_0093d810().getClass() };
    int oldSize = oldVariant.klass->FUN_009b0760();
    int newSize = newVariant.klass->FUN_009b0760();
    for (int i = 0; i < oldArray.size; i++) {
        oldVariant.object = static_cast<char*>(oldArray.data) + i * oldSize;
        newVariant.object = static_cast<char*>(newArray.data) + i * newSize;
        FUN_0093cb40(oldVariant, newVariant, tracker);
    }
}
}   // namespace f3m_0093cb50

// @f3 0x0093f1e0 (community match, verified in this file)
namespace f3m_0093f1e0 {
// 0x0093f1e0 = CollectClassDefinitions::defineClassClass(const hkClass&)
// Havok 5.5.0, hkSerialize.lib / hkVersionUtil.obj (Common/Serialize/Version/hkVersionUtil.cpp, lines 349-502).
// Matches under Havok's own flags plus /Gy: /MT /Ox /Ob1 /Oi /Ot /GF /GS- /Gy
// (/Gy only puts each function in its own section, which the checker needs to bind the static helper below).
//
// The class and inline definitions below are the Havok 5.5.0 SDK's (hkBaseTypes.h, hkThreadMemory.h, hkArray.h/.inl,
// hkString.h/.inl, hkPointerMap.h, hkCachedHashMap.h, hkStringMap.h, hkClass.h, hkClassEnum.h/.inl, hkClassMember.h,
// hkInternalClassMember.h, hkTypedUnion.h/.inl, hkVersionUtil.h), preprocessed and cut down to what this function
// uses: member functions it does not call are removed, every data member and virtual function is kept.
// The release build compiles HK_ASSERT to nothing, so the three asserts of the member loop are not written here,
// the 'hkResult res' they test is not kept, and the original's empty 'if( getNumDeclaredInterfaces() > 0 ) {}'
// is a plain call. The original spellings (unused local, empty if) give the same bytes; neither is needed.
// Functions of other objects carry the project's address names; the SDK name is in the comment beside each.

typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

class hkClass;
class hkClassEnum;
class hkClassMember;
class hkCustomAttributes;
class hkTypedUnion;
class hkMemory;
struct hkInternalCustomAttributes;

struct hkVariant
{
	void* m_object;
	const hkClass* m_class;
};

typedef int hkBool32;

class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline operator bool() const
		{
			return m_bool != 0;
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
	private:
		STORAGE m_storage;
};

template<typename BITS, typename STORAGE>
class hkFlags
{
	public:
		hkFlags()
		{
		}
		hkFlags(STORAGE s)
		{
			m_storage = s;
		}
	private:
		STORAGE m_storage;
};

// ---- hkThreadLocalData.h / hkThreadMemory.h
extern "C" {
	__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}

template<typename T>
class hkThreadLocalData
{
	public:
		__forceinline T getData() const
		{
			return (T)(hkUlong)TlsGetValue(m_slotID) ;
		}
		unsigned long m_slotID;
};

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
	HK_MEMORY_CLASS_ARRAY
};

class hkThreadMemory
{
	public:
		void* FUN_008f6d30( int nbytes, HK_MEMORY_CLASS cl );          // allocateChunk
		void FUN_008f6d90(void*, int nbytes, HK_MEMORY_CLASS );        // deallocateChunk
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
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
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
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
	// hkThreadMemory__s_threadMemoryInstance, an hkThreadLocalData<hkThreadMemory*>; the pack unit declares it as
	// 'extern unsigned long DAT_010f3170' (its only member, the TLS slot id), so the SDK type is bound here.
	return reinterpret_cast<const hkThreadLocalData<hkThreadMemory*>&>(DAT_010f3170).getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

// ---- hkArray.h / hkArray.inl
namespace hkArrayUtil
{
	void __cdecl FUN_00901e90(void*, int numElem, int sizeElem);    // _reserve
	void __cdecl FUN_00901f10(void* array, int sizeElem);           // _reserveMore
}

template <typename T>
class hkArray
{
	public:
		__forceinline hkArray();
		__forceinline hkArray(int size, const T& fill);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline const_iterator begin() const;
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
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
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
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::hkArray(int n, const T& t)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().FUN_008f6d30(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
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
		hkThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::FUN_00901e90(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::FUN_00901f10( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}

// ---- hkString.h / hkString.inl
class hkString
{
	public:
		__forceinline hkString();
		__forceinline hkString(const char* s);
	private:
		__forceinline	void setLength( int length );
	public:
		__forceinline ~hkString();
		void FUN_009236d0(const char* format, ...);               // printf
		__forceinline const char* cString() const;
		hkString& FUN_00923830 (const hkString& other);           // operator+=
		hkString& FUN_00923890 (const char* other);               // operator+=
	private:
		hkArray<char> m_string;
	public:
		static int __cdecl FUN_009233f0(const char* src);                          // strLen
		static void __cdecl FUN_009234e0(void* dst, const void* src, int n);       // memCpy
};

__forceinline const char* hkString::cString() const
{
	return m_string.begin();
}

__forceinline void hkString::setLength( int length )
{
	m_string.setSize( length + 1 );
}

__forceinline hkString::hkString()
:m_string(1, 0)
{
}

__forceinline hkString::hkString(const char* s)
{
	if( s != 0 )
	{
		setLength( FUN_009233f0(s) );
		hkString::FUN_009234e0(m_string.begin(), s, m_string.getSize() );
	}
	else
	{
		setLength(0);
		m_string[0] = 0;
	}
}

__forceinline hkString::~hkString()
{
}

// ---- hkPointerMap.h
template <typename T>
class hkPointerMapBase
{
	public:
		T FUN_009227d0( T key, T def ) const;                     // getWithDefault
	protected:
		T* m_elem;
		int m_numElems;
		int m_hashMod;
};

template <typename K, typename V>
class hkPointerMap
{
	public:
		__forceinline V getWithDefault( K key, V def ) const
		{
			return (V)m_map.FUN_009227d0( hkUlong(key), hkUlong(def) );
		}
	protected:
		hkPointerMapBase<hkUlong> m_map;
};

// ---- hkClassMember.h
class hkClassMember
{
	public:
		enum Type
		{
			TYPE_VOID = 0,
			TYPE_BOOL,
			TYPE_CHAR,
			TYPE_INT8,
			TYPE_UINT8,
			TYPE_INT16,
			TYPE_UINT16,
			TYPE_INT32,
			TYPE_UINT32,
			TYPE_INT64,
			TYPE_UINT64,
			TYPE_REAL,
			TYPE_VECTOR4,
			TYPE_QUATERNION,
			TYPE_MATRIX3,
			TYPE_ROTATION,
			TYPE_QSTRANSFORM,
			TYPE_MATRIX4,
			TYPE_TRANSFORM,
			TYPE_ZERO,
			TYPE_POINTER,
			TYPE_FUNCTIONPOINTER,
			TYPE_ARRAY,
			TYPE_INPLACEARRAY,
			TYPE_ENUM,
			TYPE_STRUCT,
			TYPE_SIMPLEARRAY,
			TYPE_HOMOGENEOUSARRAY,
			TYPE_VARIANT,
			TYPE_CSTRING,
			TYPE_ULONG,
			TYPE_FLAGS,
			TYPE_MAX
		};
		enum FlagValues
		{
			FLAGS_NONE = 0,
			ALIGN_8 = 128,
			ALIGN_16 = 256,
			NOT_OWNED = 512,
			SERIALIZE_IGNORED = 1024
		};
		typedef hkFlags<FlagValues, hkUint16> Flags;
	private:
		const char* m_name;
		const hkClass* m_class;
		const hkClassEnum* m_enum;
		hkEnum<Type,hkUint8> m_type;
		hkEnum<Type,hkUint8> m_subtype;
		hkInt16 m_cArraySize;
		Flags m_flags;
		hkUint16 m_offset;
		const hkCustomAttributes* m_attributes;
};

// ---- hkClassEnum.h / hkClassEnum.inl
class hkClassEnum
{
	public:
		class Item
		{
			public:
				Item( int v, const char* n) : m_value(v), m_name(n) { }
				const char* getName() const { return m_name; }
				int getValue() const { return m_value; }
			private:
				int m_value;
				const char* m_name;
		};
		enum FlagValues
		{
			FLAGS_NONE = 0
		};
		typedef hkFlags<FlagValues, hkUint32> Flags;
		const char* getName() const;
		int getNumItems() const;
		const hkClassEnum::Item& getItem(int i) const;
		hkResult FUN_009b2320( int val, const char** name ) const;   // getNameOfValue
		inline const Flags& getFlags() const;
	private:
		const char* m_name;
		const class Item* m_items;
		int m_numItems;
		class hkCustomAttributes* m_attributes;
		Flags m_flags;
};

inline const char* hkClassEnum::getName() const
{
	return m_name;
}

inline int hkClassEnum::getNumItems() const
{
	return m_numItems;
}

inline const hkClassEnum::Item& hkClassEnum::getItem(int i) const
{
	return m_items[i];
}

inline const hkClassEnum::Flags& hkClassEnum::getFlags() const
{
	return m_flags;
}

// ---- hkClass.h
class hkClass
{
	public:
		enum FlagValues
		{
			FLAGS_NONE = 0,
			FLAGS_NOT_SERIALIZABLE = 1
		};
		typedef hkFlags<FlagValues, hkUint32> Flags;
		const char* FUN_009b0490() const;                              // getName
		const hkClass* FUN_009b04a0() const;                           // getParent
		int FUN_009b0560() const;                                      // getNumDeclaredInterfaces
		const hkClassEnum& FUN_009b0900(int i) const;                  // getDeclaredEnum
		int FUN_009b0620() const;                                      // getNumDeclaredEnums
		const hkClassMember& FUN_009b06b0(int i) const;                // getDeclaredMember
		int FUN_009b06a0() const;                                      // getNumDeclaredMembers
		int FUN_009b0710(const char* name) const;                      // getMemberIndexByName
		hkResult FUN_009b0910(int memberIndex, hkTypedUnion& value) const;   // getDefault
		hkUint32 FUN_009b0bb0(int signatureFlags = 0) const;           // getSignature
	protected:
		const char* m_name;
		const hkClass* m_parent;
		int m_objectSize;
		int m_numImplementedInterfaces;
		const class hkClassEnum* m_declaredEnums;
		int m_numDeclaredEnums;
		const class hkClassMember* m_declaredMembers;
		int m_numDeclaredMembers;
		const void* m_defaults;
		const hkCustomAttributes* m_attributes;
		Flags m_flags;
		int m_describedVersion;
};

// ---- hkCachedHashMap.h / hkStringMap.h
template <typename Operations>
class hkCachedHashMap
{
	public:
		typedef class Dummy* Iterator;
		hkBool FUN_009b0e40( Iterator i ) const;                       // isValid
		void FUN_009b0e60( hkUlong key, hkUlong val );                 // insert
		Iterator FUN_009b0f20( hkUlong key ) const;                    // findKey
		hkBool hasKey( hkUlong key ) const { return FUN_009b0e40(FUN_009b0f20(key)); }
	protected:
		hkUlong* m_elem;
		int m_numElems;
		int m_hashMod;
		Operations m_ops;
};

struct hkStringMapOperations
{
};

class hkStringMapBase : public hkCachedHashMap<hkStringMapOperations>
{
};

template <typename V>
class hkStringMap
{
	public:
		__forceinline void insert( const char* key, V val )
		{
			m_map.FUN_009b0e60( hkUlong(key), hkUlong(val) );
		}
		__forceinline hkBool hasKey( const char* key ) const
		{
			return m_map.hasKey( hkUlong(key) );
		}
	protected:
		hkStringMapBase m_map;
};

// ---- hkVersionUtil.h
class CollectClassDefinitions
{
public:
	CollectClassDefinitions(const hkArray<const hkClass*>& originalClassList,
							hkPointerMap<const hkClassEnum*, char*>& enumNameFromPointer,
							hkStringMap<hkBool32>& enumDoneFlagFromName);

	const hkString& getClassExternList() const;

	const hkString& getClassDefinitionList() const;

	void FUN_0093f1e0(const hkClass& klass);                           // defineClassClass

private:
	const hkClassEnum* m_classMemberEnumType;
	const hkArray<const hkClass*>& m_originalClassList;
	hkString m_classExternList;
	hkString m_classDefinitionList;
	hkPointerMap<const hkClassEnum*, char*>& m_enumNameFromPointer;
	hkStringMap<hkBool32>& m_enumDoneFlagFromName;
	hkStringMap<hkBool32> m_doneClasses;
};

// ---- hkInternalClassMember.h
struct hkInternalClassMember
{
	const char* m_name;
	const hkClass* m_class;
	const hkClassEnum* m_enum;
	hkUint8 m_type;
	hkUint8 m_subtype;
	hkUint16 m_cArraySize;
	hkUint16 m_flags;
	hkUint16 m_offset;
	const hkInternalCustomAttributes* m_attributes;
};

// ---- hkTypedUnion.h / hkTypedUnion.inl
class hkTypedUnion
{
	public:
		inline hkTypedUnion();
		struct EnumVariant
		{
			int m_value;
			const hkClassEnum* m_enum;
		};
		union Storage
		{
			bool m_bool;
			char m_char;
			hkInt8 m_int8;
			hkUint8 m_uint8;
			hkInt16 m_int16;
			hkUint16 m_uint16;
			hkInt32 m_int32;
			hkUint32 m_uint32;
			hkInt64 m_int64;
			hkUint64 m_uint64;
			float m_float;
			float m_float4[4];
			float m_float12[12];
			float m_float16[16];
			hkVariant m_variant;
			EnumVariant m_enumVariant;
			hkUlong m_ulong;
			hkInt32 m_maxSize[16];
		};
	private:
		hkEnum<hkClassMember::Type, hkInt32> m_type;
		__declspec(align(16)) Storage m_elem;
};

inline hkTypedUnion::hkTypedUnion() :
	m_type(hkClassMember::TYPE_VOID)
{
}

// ---- hkVersionUtil.cpp
static const char s_externClass[] = "\textern hkClass %sClass; /* 0x%p */\r\n";
static const char s_enumItemsStart[] = "\tstatic const hkInternalClassEnumItem %sEnumItems[] =\r\n\t{\r\n";
static const char s_enumItemDefinition[] = "\t\t{%d, \"%s\"},\r\n";
static const char s_enumItemsEnd[] = "\t};\r\n";
static const char s_enumsStart[] = "\tstatic const hkInternalClassEnum %sEnums[] =\r\n\t{\r\n";
static const char s_enumDefinition[] = "\t\t{\"%s\", %sEnumItems, %d, HK_NULL, %d },\r\n";
static const char s_enumsEnd[] = "\t};\r\n";
static const char s_enumExtern[] = "\textern const hkClassEnum* %sEnum = reinterpret_cast<const hkClassEnum*>(&%sEnums[%d]);\r\n";
static const char s_membersStart[] = "\tstatic hkInternalClassMember %sClass_Members[] =\r\n\t{\r\n";
static const char s_memberDefinition[] = "\t\t{ \"%s\", %s, %s, hkClassMember::%s, hkClassMember::%s, %d, %d, 0, HK_NULL },\r\n";
static const char s_membersEnd[] = "\t};\r\n";
static const char s_classDefinition[] = "\thkClass %sClass(\r\n\t\t\"%s\",\r\n\t\t%s,\r\n\t\t0,\r\n\t\t%s,\r\n\t\t%d,\r\n\t\t%s,\r\n\t\t%d,\r\n\t\t%s,\r\n\t\t%s,\r\n\t\t%s\r\n\t);\r\n";

// generateDefaults: static helper of the same file, called with the ordinary cdecl convention.
void FUN_0093ed10(const hkClass& klass, hkArray<int>& memIdxWithDefault, hkString& outputString);

// generateEnum: static helper of the same file. The optimizer gives it a private register convention
// (classEnum in edi), so the call in FUN_0093f1e0 needs this body in the same file.
static inline void FUN_0093ec30(const char* completeEnumName, const hkClassEnum& classEnum, hkString& outputString)
{
	hkString buffer;
	buffer.FUN_009236d0(s_enumItemsStart, completeEnumName);
	outputString.FUN_00923830(buffer);
	for( int item = 0; item < classEnum.getNumItems(); ++item )
	{
		const hkClassEnum::Item& enumItem = classEnum.getItem(item);
		buffer.FUN_009236d0(s_enumItemDefinition, enumItem.getValue(), enumItem.getName());
		outputString.FUN_00923830(buffer);
	}
	outputString.FUN_00923890(s_enumItemsEnd);
}

void CollectClassDefinitions::FUN_0093f1e0(const hkClass& klass)
{
	if( m_doneClasses.hasKey(klass.FUN_009b0490()) )
	{
		return;
	}

	hkString buffer;
	buffer.FUN_009236d0(s_externClass, klass.FUN_009b0490(), klass.FUN_009b0bb0());
	m_classExternList.FUN_00923830(buffer);

	m_doneClasses.insert(klass.FUN_009b0490(), 1);
	bool defineClass = false;
	for( int i = 0; i < m_originalClassList.getSize(); ++i )
	{
		if( &klass == m_originalClassList[i] )
		{
			defineClass = true;
			break;
		}
	}

	if( !defineClass )
	{
		return;
	}

	if( klass.FUN_009b04a0() )
	{
		FUN_0093f1e0(*klass.FUN_009b04a0());
	}

	hkString parent = "HK_NULL";
	hkString interfaces = "HK_NULL";
	hkString enums = "HK_NULL";
	hkString members = "HK_NULL";
	hkString numMembers = "0";
	hkString defaults = "HK_NULL";

	hkString enumItemsDefinitionList;
	hkString enumsDefinitionList;
	hkString enumExtern;
	hkString classDefinitionList;

	if( klass.FUN_009b04a0() )
	{
		parent.FUN_009236d0("&%sClass", klass.FUN_009b04a0()->FUN_009b0490());
	}
	klass.FUN_009b0560();

	if( klass.FUN_009b0620() > 0 )
	{
		enums.FUN_009236d0("reinterpret_cast<const hkClassEnum*>(%sEnums)", klass.FUN_009b0490());

		buffer.FUN_009236d0(s_enumsStart, klass.FUN_009b0490());
		enumsDefinitionList.FUN_00923830(buffer);

		for( int e = 0; e < klass.FUN_009b0620(); ++e )
		{
			const hkClassEnum& classEnum = klass.FUN_009b0900(e);
			const char* completeEnumName = m_enumNameFromPointer.getWithDefault(&classEnum, 0);
			if( m_enumDoneFlagFromName.hasKey(completeEnumName) )
			{
				continue;
			}

			m_enumDoneFlagFromName.insert(completeEnumName, 1);
			FUN_0093ec30(completeEnumName, classEnum, enumItemsDefinitionList);

			buffer.FUN_009236d0(s_enumDefinition, classEnum.getName(), completeEnumName, classEnum.getNumItems(), classEnum.getFlags());
			enumsDefinitionList.FUN_00923830(buffer);

			buffer.FUN_009236d0(s_enumExtern, completeEnumName, klass.FUN_009b0490(), e);
			enumExtern.FUN_00923830(buffer);
		}
		enumsDefinitionList.FUN_00923890(s_enumsEnd);
	}
	enumsDefinitionList.FUN_00923830(enumExtern);

	classDefinitionList.FUN_00923830(enumItemsDefinitionList);
	classDefinitionList.FUN_00923830(enumsDefinitionList);

	if( klass.FUN_009b06a0() > 0 )
	{
		hkArray<int> memIdxWithDefault;
		hkTypedUnion defaultValue;

		members.FUN_009236d0("reinterpret_cast<const hkClassMember*>(%sClass_Members)", klass.FUN_009b0490());
		numMembers.FUN_009236d0("int(sizeof(%sClass_Members)/sizeof(hkInternalClassMember))", klass.FUN_009b0490());

		buffer.FUN_009236d0(s_membersStart, klass.FUN_009b0490());
		classDefinitionList.FUN_00923830(buffer);

		for( int i = 0; i < klass.FUN_009b06a0(); ++i )
		{
			hkString memClass = "HK_NULL";
			hkString memEnum = "HK_NULL";
			const hkInternalClassMember& mem = reinterpret_cast<const hkInternalClassMember&>(klass.FUN_009b06b0(i));
			if( klass.FUN_009b0910(klass.FUN_009b0710(mem.m_name), defaultValue) == HK_SUCCESS )
			{
				memIdxWithDefault.pushBack(i);
			}
			if( mem.m_class )
			{
				memClass.FUN_009236d0("&%sClass", mem.m_class->FUN_009b0490());
				FUN_0093f1e0(*mem.m_class);
			}
			if( mem.m_enum )
			{
				char* enumName = m_enumNameFromPointer.getWithDefault(mem.m_enum, 0);
				memEnum.FUN_009236d0("%sEnum", enumName);
			}
			const char* memTypeName;
			m_classMemberEnumType->FUN_009b2320(mem.m_type, &memTypeName);
			const char* memSubTypeName;
			m_classMemberEnumType->FUN_009b2320(mem.m_subtype, &memSubTypeName);
			buffer.FUN_009236d0(s_memberDefinition,
				mem.m_name,
				memClass.cString(),
				memEnum.cString(),
				memTypeName,
				memSubTypeName,
				mem.m_cArraySize,
				mem.m_flags);
			classDefinitionList.FUN_00923830(buffer);
		}
		classDefinitionList.FUN_00923890(s_membersEnd);
		if( memIdxWithDefault.getSize() > 0 )
		{
			defaults.FUN_009236d0("&%s_Default", klass.FUN_009b0490());
			FUN_0093ed10(klass, memIdxWithDefault, buffer);
			classDefinitionList.FUN_00923830(buffer);
		}
	}

	buffer.FUN_009236d0(s_classDefinition,
		klass.FUN_009b0490(),
		klass.FUN_009b0490(),
		parent.cString(),
		interfaces.cString(),
		klass.FUN_009b0560(),
		enums.cString(),
		klass.FUN_009b0620(),
		members.cString(),
		numMembers.cString(),
		defaults.cString());
	classDefinitionList.FUN_00923830(buffer);
	m_classDefinitionList.FUN_00923830(classDefinitionList);
}
}   // namespace f3m_0093f1e0

// @f3 0x00931eb0 (community match, verified in this file)
// 0x00931eb0: hkpAabbUtil::initOffsetAabbInput(const hkMotionState* motionState, OffsetAabbInput& input) of Havok
// 5.5.0 (hkpCollide, hkpAabbUtil.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets up the transforms for a swept (offset) AABB: the inverse end transform, the start transform, and, by the
// body's rotation angle over the step, one interpolated transform or several along the sweep, each with the cosine
// correction in its w component.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the compile of the full
// source); those declarations are the SDK's text with its names. It reproduces the SDK's release object (1891 bytes)
// under Havok's own flags. The parentheses of the first cosine approximation, 1.0f - ( deltaAngle * deltaAngle * 0.5f ),
// matter: they keep a node the optimizer hashes, which numbers every later common subexpression one higher and so
// fixes the x87 operand order of the third inlined rotation interpolation, inside the loop. Only the function carries
// the packet's name.
namespace f3m_00931eb0 {

typedef float  hkReal;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
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
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
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
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
		void* onRowEmpty(int row);
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
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQuaternion), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkSweptTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}
inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}
inline hkSimdReal hkVector4::lengthInverse4() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z) + (w*w);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize4()
	{
		this->mul4( this->lengthInverse4() );
		;
	}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
inline void hkMatrix3::operator= ( const hkMatrix3& a )
{
	m_col0 = a.getColumn(0);
	m_col1 = a.getColumn(1);
	m_col2 = a.getColumn(2);
}
hkVector4& hkTransform::getTranslation()
{
	return m_translation;
}
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
void hkTransform::setRotation(const hkQuaternion& quatRotation)
{
	m_rotation.set(quatRotation);
}
hkTime hkSweptTransform::getBaseTime() const
{
	return hkTime(m_centerOfMass0(3));
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}
void hkSweptTransform::_approxTransformAt( hkTime t, hkTransform& transformOut ) const
{
	hkSimdReal dt = hkSimdReal((t - getBaseTime()) * getInvDeltaTime());
	hkQuaternion q;
	q.m_vec.setInterpolate4( m_rotation0.m_vec, m_rotation1.m_vec, dt );
	q.m_vec.normalize4();
	transformOut.setRotation( q );
	transformOut.getTranslation().setInterpolate4( m_centerOfMass0, m_centerOfMass1, dt);
	hkVector4 centerShift;
	centerShift._setRotatedDir( transformOut.getRotation(), m_centerOfMassLocal);
	transformOut.getTranslation().sub4( centerShift );
}
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMotionState), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
const hkTransform& hkMotionState::getTransform() const
{
	return m_transform;
}
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}
class hkAabb;
class hkpAabbUtil
{
	public:
		static void __cdecl calcAabb( const float* vertexArray, int numVertices, int striding, hkAabb& aabbOut );
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, const hkVector4& center, float extraRadius, hkAabb& aabbOut);
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, float extraRadius, hkAabb& aabbOut);
	public:
		struct OffsetAabbInput
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpAabbUtil::OffsetAabbInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkPadSpu<const hkMotionState*> m_motionState;
			hkTransform m_transforms[4];
			hkPadSpu<int> m_numTransforms;
			hkTransform m_startTransform;
			hkTransform m_endTransformInv;
		};
		__forceinline static void __cdecl sweepAabb(const hkMotionState* motionstate, hkReal tolerance, const hkAabb& aabbIn, hkAabb& aabbOut);
		static void __cdecl hkAabbUtil_initOffsetAabbInput(const hkMotionState* motionstate, OffsetAabbInput& input);
		static void __cdecl sweepOffsetAabb(const OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut);
};
// pdb: hkAabbUtil::initOffsetAabbInput | hkAabbUtil.obj | fnv360_0822_retail, uconst + bridge(uconst|uconst) + skyrim(uconst), high
void hkpAabbUtil::hkAabbUtil_initOffsetAabbInput(const hkMotionState* motionState, OffsetAabbInput& input)
{
	input.m_motionState = motionState;
	input.m_endTransformInv.setInverse( motionState->getTransform() );
	const hkSweptTransform& swept = motionState->getSweptTransform();
	swept._approxTransformAt( swept.getBaseTime(), input.m_startTransform );
	if ( swept.getInvDeltaTime() != 0.0f )
	{
		const hkReal deltaTime = 1.0f / swept.getInvDeltaTime();
		hkReal deltaAngle = motionState->m_deltaAngle(3);
		if ( deltaAngle <= 3.14159265358979f * 0.125f )
		{
			hkReal cosApprox = 1.0f - ( deltaAngle * deltaAngle * 0.5f );
			input.m_transforms[0] = input.m_startTransform;
			input.m_transforms[0].getTranslation()(3) = 1.0f / cosApprox;
			input.m_numTransforms = 1;
			return;
		}
		if ( deltaAngle <= 3.14159265358979f * 0.25f )
		{
			hkReal time = swept.getBaseTime() + deltaTime * 0.5f;
			motionState->getSweptTransform()._approxTransformAt( time, input.m_transforms[0] );
			hkReal cosApprox = 1.0f - deltaAngle * deltaAngle * 0.25f * 0.5f;
			input.m_transforms[0].getTranslation()(3) = 1.0f / cosApprox;
			input.m_numTransforms = 1;
			return;
		}
		{
			hkReal parts = (deltaAngle + 3.14159265358979f * 0.125f) / (3.14159265358979f * 0.125f);
			hkReal partsInv = 1.0f / parts;
			input.m_numTransforms = 0;
			for ( hkReal p = 1.0f; p < parts; p += 2.0f )
			{
				hkReal time = swept.getBaseTime() + p * partsInv * deltaTime;
				hkTransform& t = input.m_transforms[input.m_numTransforms];
				input.m_numTransforms = input.m_numTransforms + 1;
				motionState->getSweptTransform()._approxTransformAt( time, t );
				t.getTranslation()(3) = 1.0824f;
			}
		}
		return;
	}
	input.m_numTransforms = 0;
}

}  // namespace f3m_00931eb0

// @f3 0x0093a410 (community match, verified in this file)
#include <math.h>
namespace f3m_0093a410 {

namespace hk93a410 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

class hkBool
{
	public:
		inline hkBool() {}
		inline hkBool(bool b) { m_bool = static_cast<char>(b); }
		inline operator bool() const { return m_bool != 0; }
	private:
		char m_bool;
};

namespace hkMath
{
	inline hkReal sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal fabs(hkReal r) { return ::fabsf(r); }
}


class hkVector4
{
	public:
		__forceinline hkReal& operator() (int i) { return (&x)[i]; }
		__forceinline const hkReal& operator() (int i) const { return (&x)[i]; }
		__forceinline void operator= (const hkVector4& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}
		__forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
		{
			x = a;
			y = b;
			z = c;
			w = d;
		}
		__forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
		{
			x = v0.x - v1.x;
			y = v0.y - v1.y;
			z = v0.z - v1.z;
			w = v0.w - v1.w;
		}
		__forceinline void setZero4()
		{
			x = y = z = w = 0;
		}
		__forceinline void mul4(hkSimdRealParameter rs)
		{
			hkReal s = hkReal(rs);
			x *= s;
			y *= s;
			z *= s;
			w *= s;
		}
		__forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
		{
			const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
			const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
			const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
			this->set( nx, ny, nz , 0.0f );
		}
		__forceinline hkSimdReal length3() const
		{
			return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
		}
		__forceinline hkSimdReal lengthInverse3() const
		{
			hkReal l2 = (x*x) + (y*y) + (z*z);
			return l2 ? hkMath::sqrtInverse(l2) : 0;
		}
		__forceinline void normalize3()
		{
			this->mul4( this->lengthInverse3() );
		}

		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkMatrix3
{
	public:
		__forceinline hkVector4& getColumn(int x) { return (&m_col0)[x]; }
		__forceinline const hkVector4& getColumn(int x) const { return (&m_col0)[x]; }
		void FUN_0096ce80( const hkMatrix3& a, const hkMatrix3& b );

		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class hkRotation : public hkMatrix3
{
};

class hkTransform
{
	public:
		__forceinline hkVector4& getTranslation() { return m_translation; }
		__forceinline hkRotation& getRotation() { return m_rotation; }
		__forceinline hkVector4& getColumn(int x) { return m_rotation.getColumn(x); }

		hkRotation m_rotation;
		hkVector4 m_translation;
};

namespace hkVector4Util
{
	__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
	{
		int min = 0;
		int ok1 = 1;
		int ok2 = 2;

		hkReal a0 = hkMath::fabs(vectorIn(0));
		hkReal a1 = hkMath::fabs(vectorIn(1));
		hkReal a2 = hkMath::fabs(vectorIn(2));

		if( a1 < a0 )
		{
			ok1 = 0;
			min = 1;
			a0 = a1;
		}

		if(a2 < a0)
		{
			ok2 = min;
		}

		biVectorOut.setZero4();
		biVectorOut(ok1) =  vectorIn(ok2);
		biVectorOut(ok2) = -vectorIn(ok1);
	}

	__forceinline void buildOrthonormal( const hkVector4& dir, hkMatrix3& out )
	{
		out.getColumn(0) = dir;
		calculatePerpendicularVector( dir, out.getColumn(1));
		out.getColumn(1).normalize3();
		out.getColumn(2).setCross( dir, out.getColumn(1));
	}

	__forceinline void buildOrthonormal( const hkVector4& dir, const hkVector4& dir2, hkMatrix3& out )
	{
		out.getColumn(0) = dir;
		out.getColumn(2).setCross( dir, dir2 );
		if ( out.getColumn(2).length3() < 1.192092896e-07F )
		{
			buildOrthonormal( dir, out );
			return;
		}
		out.getColumn(2).normalize3();
		out.getColumn(1).setCross( out.getColumn(2), dir );
	}
}

class hkClass;
class hkClassEnum
{
	public:
		int FUN_009b2360(const char* name, int* value) const;
};

class hkClassMember
{
	public:
		inline const char* getName() const { return m_name; }
		inline int getOffset() const { return m_offset; }
		const hkClass& FUN_0093d890() const;
		const hkClassEnum& FUN_0093d8b0() const;

		const char* m_name;
		const hkClass* m_class;
		const hkClassEnum* m_enum;
		hkUint8 m_type;
		hkUint8 m_subtype;
		hkInt16 m_cArraySize;
		hkUint16 m_flags;
		hkUint16 m_offset;
};

class hkClass
{
	public:
		int FUN_009b0630() const;
		const hkClassMember& FUN_009b0650(int i) const;
		int FUN_009b0760() const;
};

struct hkVariant
{
	void* m_object;
	const hkClass* m_class;
};

class hkClassAccessor;
class hkConstraintMotor;

class hkClassMemberAccessor
{
	public:
		struct Vector4
		{
			__declspec(align(16)) hkReal r[4];
		};
		struct Matrix3
		{
			Vector4 v[3];
		};
		struct Transform
		{
			Vector4 r[3];
			Vector4 t;
		};
		typedef Matrix3 Rotation;

		inline hkClassMemberAccessor(const hkVariant& v, const char* memberName) { FUN_0093d600(v, memberName); }

		void FUN_0093d600(const hkVariant& v, const char* memberName);
		const hkClassMember& FUN_0093d790() const;
		void* FUN_0093d660() const;
		void*& FUN_0093d670(int index = 0) const;
		hkBool& FUN_0093d690(int index = 0) const;
		hkReal& FUN_0093d6a0(int index = 0) const;
		hkInt16& FUN_0093d6e0(int index = 0) const;
		hkUint8& FUN_0093d710(int index = 0) const;
		Vector4& FUN_0093d720(int index = 0) const;
		Rotation& FUN_0093d750(int index = 0) const;
		hkClassMemberAccessor FUN_0093d7a0(const char* name) const;
		hkClassAccessor FUN_0093d810() const;

	private:
		void* m_address;
		const hkClassMember* m_member;
};

class hkClassAccessor
{
	public:
		inline hkClassAccessor(hkVariant& v) { FUN_0093d7f0(v); }
		void FUN_0093d7f0(hkVariant& v);
		inline const hkClass& getClass() const { return *m_variant.m_class; }

		inline hkClassMemberAccessor member(const char* memberName) const
		{
			return hkClassMemberAccessor(m_variant, memberName);
		}

	private:
		hkVariant m_variant;
};

class hkObjectUpdateTracker
{
	public:
		virtual ~hkObjectUpdateTracker() {}
		virtual void v1() = 0;
		virtual void v2() = 0;
		virtual void v3() = 0;
		virtual void v4() = 0;
		virtual void objectPointedBy( void* object, void* fromWhere ) = 0;
};

static short DAT_0105f5d8 = -1;
static short DAT_0105f560 = -1;
static short DAT_0105f568 = -1;
static short DAT_0105f56c = -1;
static short DAT_0105f570 = -1;
static short DAT_0105f578 = -1;

static int FUN_009366b0( const hkClassMemberAccessor& newAtoms )
{
	const hkClass& atomClass = newAtoms.FUN_0093d810().getClass();
	const hkClassMember& lastMember = atomClass.FUN_009b0650( atomClass.FUN_009b0630() - 1 );
	return newAtoms.FUN_0093d7a0( lastMember.getName() ).FUN_0093d790().getOffset() + lastMember.FUN_0093d890().FUN_009b0760();
}

static hkInt16 FUN_00936710( const hkClassAccessor& memAcc, const char* typeName )
{
	int ret;
	memAcc.member("type").FUN_0093d790().FUN_0093d8b0().FUN_009b2360( typeName, &ret );
	return static_cast<hkInt16>(ret);
}

void __cdecl FUN_009367e0( const hkClassAccessor& local, const hkClassMemberAccessor::Transform& transformA, const hkClassMemberAccessor::Transform& transformB );

static void FUN_00936ab0( const hkClassAccessor& linear, hkUint8 axisIndex )
{
	if ( DAT_0105f560 == -1 ) DAT_0105f560 = FUN_00936710( linear, "TYPE_LIN" );
	linear.member("type").FUN_0093d6e0() = DAT_0105f560;
	linear.member("axisIndex").FUN_0093d710() = axisIndex;
}

static void FUN_00936bd0( const hkClassAccessor& linearLimit, hkUint8 axisIndex, hkReal minLimit, hkReal maxLimit )
{
	if ( DAT_0105f568 == -1 ) DAT_0105f568 = FUN_00936710( linearLimit, "TYPE_LIN_LIMIT" );
	linearLimit.member("type").FUN_0093d6e0() = DAT_0105f568;
	linearLimit.member("axisIndex").FUN_0093d710() = axisIndex;
	linearLimit.member("min").FUN_0093d6a0() = minLimit;
	linearLimit.member("max").FUN_0093d6a0() = maxLimit;
}

static void FUN_00936c80( const hkClassAccessor& linearFriction, hkUint8 enabled, hkUint8 frictionAxis, hkReal maxFrictionForce )
{
	if ( DAT_0105f56c == -1 ) DAT_0105f56c = FUN_00936710( linearFriction, "TYPE_LIN_FRICTION" );
	linearFriction.member("type").FUN_0093d6e0() = DAT_0105f56c;
	linearFriction.member("isEnabled").FUN_0093d710() = enabled;
	linearFriction.member("frictionAxis").FUN_0093d710() = frictionAxis;
	linearFriction.member("maxFrictionForce").FUN_0093d6a0() = maxFrictionForce;
}

static void FUN_00936d30( const hkClassAccessor& linearMotor, hkBool enabled, hkUint8 motorAxis, hkInt16 initializedOffset, hkInt16 previousTargetAngleOffset, hkReal targetPosition, hkConstraintMotor* motor )
{
	if ( DAT_0105f570 == -1 ) DAT_0105f570 = FUN_00936710( linearMotor, "TYPE_LIN_MOTOR" );
	linearMotor.member("type").FUN_0093d6e0() = DAT_0105f570;
	linearMotor.member("isEnabled").FUN_0093d690() = enabled;
	linearMotor.member("motorAxis").FUN_0093d710() = motorAxis;
	linearMotor.member("initializedOffset").FUN_0093d6e0() = initializedOffset;
	linearMotor.member("previousTargetPositionOffset").FUN_0093d6e0() = previousTargetAngleOffset;
	linearMotor.member("targetPosition").FUN_0093d6a0() = targetPosition;
	linearMotor.member("motor").FUN_0093d670() = motor;
}

static void FUN_00936eb0( const hkClassAccessor& angular, hkUint8 firstConstrainedAxis, hkUint8 numConstrainedAxes )
{
	if ( DAT_0105f578 == -1 ) DAT_0105f578 = FUN_00936710( angular, "TYPE_ANG" );
	angular.member("type").FUN_0093d6e0() = DAT_0105f578;
	angular.member("firstConstrainedAxis").FUN_0093d710() = firstConstrainedAxis;
	angular.member("numConstrainedAxes").FUN_0093d710() = numConstrainedAxes;
}

inline hkClassMemberAccessor::Vector4 getVector4( const hkClassMemberAccessor::Vector4& v )
{
	hkClassMemberAccessor::Vector4 r;
	reinterpret_cast<hkVector4&>(r) = reinterpret_cast<const hkVector4&>(v);
	return r;
}
}

using namespace hk93a410;

void __cdecl FUN_0093a410( hkVariant& oldObj, hkVariant& newObj, hkObjectUpdateTracker& tracker )
{
	hkClassMemberAccessor newAtoms(newObj, "atoms");
	hkClassAccessor oldData(oldObj);
	if ( DAT_0105f5d8 == -1 ) DAT_0105f5d8 = static_cast<short>( FUN_009366b0(newAtoms) );

	hkTransform transformB;
	{
		hkClassAccessor basisB = oldData.member("basisB").FUN_0093d810();
		hkClassMemberAccessor::Vector4 pivotB = getVector4( basisB.member("pivot").FUN_0093d720() );
		hkClassMemberAccessor::Vector4 shaftB = getVector4( basisB.member("shaft").FUN_0093d720() );
		hkClassMemberAccessor::Vector4 perpToShaftB = getVector4( basisB.member("perpToShaft").FUN_0093d720() );
		hkVector4Util::buildOrthonormal( reinterpret_cast<const hkVector4&>(shaftB), reinterpret_cast<const hkVector4&>(perpToShaftB), transformB.getRotation() );
		transformB.getTranslation() = reinterpret_cast<const hkVector4&>(pivotB);
	}

	hkTransform transformA;
	{
		hkClassAccessor basisA = oldData.member("basisA").FUN_0093d810();
		hkClassMemberAccessor::Vector4 pivotA = getVector4( basisA.member("pivot").FUN_0093d720() );
		basisA.member("shaft").FUN_0093d720();
		hkClassMemberAccessor::Matrix3 aTb = basisA.member("BtoAoffsetRotation").FUN_0093d750();
		transformA.getRotation().FUN_0096ce80( reinterpret_cast<const hkMatrix3&>(aTb), transformB.getRotation() );
		transformA.getTranslation() = reinterpret_cast<const hkVector4&>(pivotA);
	}

	FUN_009367e0( newAtoms.FUN_0093d7a0("transforms").FUN_0093d810(), reinterpret_cast<const hkClassMemberAccessor::Transform&>(transformA), reinterpret_cast<const hkClassMemberAccessor::Transform&>(transformB) );

	hkBool isMotorActive = oldData.member("motor").FUN_0093d670() != 0;

	FUN_00936d30( newAtoms.FUN_0093d7a0("motor").FUN_0093d810(), isMotorActive, 0, 0x40, 0x44, oldData.member("motorTargetPosition").FUN_0093d6a0(), static_cast<hkConstraintMotor*>( oldData.member("motor").FUN_0093d670() ) );

	if ( newAtoms.FUN_0093d7a0("motor").FUN_0093d810().member("motor").FUN_0093d670() )
	{
		tracker.objectPointedBy( newAtoms.FUN_0093d7a0("motor").FUN_0093d810().member("motor").FUN_0093d670(), newAtoms.FUN_0093d7a0("motor").FUN_0093d810().member("motor").FUN_0093d660() );
	}

	FUN_00936c80( newAtoms.FUN_0093d7a0("friction").FUN_0093d810(), !isMotorActive, 0, oldData.member("maxFrictionForce").FUN_0093d6a0() );
	FUN_00936eb0( newAtoms.FUN_0093d7a0("ang").FUN_0093d810(), 0, 3 );
	FUN_00936ab0( newAtoms.FUN_0093d7a0("lin0").FUN_0093d810(), 1 );
	FUN_00936ab0( newAtoms.FUN_0093d7a0("lin1").FUN_0093d810(), 2 );

	FUN_00936bd0( newAtoms.FUN_0093d7a0("linLimit").FUN_0093d810(), 0, oldData.member("minLimit").FUN_0093d6a0(), oldData.member("maxLimit").FUN_0093d6a0() );
}
}   // namespace f3m_0093a410

// @f3 0x0093acb0 (community match, verified in this file)
// FUN_0093acb0 = Havok 5.5.0 WheelConstraintData_400b1_400b2 (hkCompat.lib, hkCompat_hk400b1_hk400b2.obj).
// Written from the Havok 5.5.0 SDK (approved source). No .cpp ships: the body and the static
// helpers are rebuilt from the hybrid object's line records (1027-1077; helpers 251-420), locals and blocks; SDK-form
// source w2\sdk.cpp, cut with hktrim.py; corrected in audit: struct Vector4 has the library's own constructor body, the SDK's hkVector4 constructors are restored.
namespace f3m_0093acb0 {
typedef float  hkReal;
typedef float  hkFloat32;
typedef double hkDouble64;
typedef signed char		hkChar;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
typedef void* hk_va_list;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

		typedef unsigned __int64 hkUint64;
		typedef __int64 hkInt64;
		typedef long hkSystemTime;
			typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;

struct hkVariant
{
	void* m_object;
	const hkClass* m_class;
};

typedef int hkBool32;

class hkBool
{
	public:
		inline hkBool();
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum(ENUM e);
		operator ENUM() const;
	private:
		STORAGE m_storage;
};

template<typename BITS, typename STORAGE>
class hkFlags
{
	public:
		hkFlags();
		hkFlags(STORAGE s);
	private:
		STORAGE m_storage;
};

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

class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory& __cdecl getInstance();
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
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

class hkStreamWriter;

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
	public:
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline int getSize() const;
		typedef T* iterator;
		typedef const T* const_iterator;
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
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
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

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};

union hkQuadRealUnion
{
	hkReal r[4];
	hkQuadReal q;
};

class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
	private:
		int m_mask;
		friend class hkVector4;
};

extern "C"
{
	hkReal __cdecl hkMath_atan2fApproximation( hkReal x, hkReal y );
}

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

extern const hkQuadReal hkQuadReal0000;
extern const hkQuadReal hkQuadReal1111;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline hkQuadReal& getQuad();
		__forceinline void zeroElement( int i );
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); }             class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

inline hkQuadReal& hkVector4::getQuad()
{
	return reinterpret_cast<hkQuadReal&>(x);
}

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline hkVector4::hkVector4(hkReal a, hkReal b, hkReal c, hkReal d)
	: x(a), y(b), z(c), w(d)
{
}

inline hkVector4::hkVector4(const hkQuadReal& q)
	: x(q.x), y(q.y), z(q.z), w(q.w)
{
}

inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}

inline void hkVector4::zeroElement( int i )
{
	(*this)(i) = 0.0f;
}

inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
	}

inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}

inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}

inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}

void hkTransform::setTranslation(const hkVector4& t)
{
	m_translation = t;
}

hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}

class hkString
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkString& operator+= (const char* other);
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
		hkString replace(char from, char to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(char from, char to, ReplaceType=REPLACE_ALL);
	private:
		hkArray<char> m_string;
	public:
		template<int size>
		static __forceinline void __cdecl memCpy16(void* dst, const void* src);
		static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);
};

template <typename T>
class hkPointerMapBase
{
	public:
		                class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
		Iterator getIterator() const;
	protected:
		static __forceinline T __cdecl pointerHash(T addr, int mod);
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

template < typename T >
__forceinline T hkPointerMapBase<T>::pointerHash(T addr, int mod )
{
	return ((addr >> 4) * 2654435761U) & mod;
}

template < typename T >
inline typename hkPointerMapBase<T>::Iterator hkPointerMapBase<T>::getIterator() const
{
	int i;
	for( i = 0; i <= m_hashMod; ++i )
	{
		if( m_elem[i] != T(-1) )
		{
			break;
		}
	}
	return reinterpret_cast<Iterator>( T(i) );
}

template <typename K, typename V>
class hkPointerMap
{
	public:
		                class MustEndWithSemiColon;
		typedef hkPointerMapBase<hkUlong>::Iterator Iterator;
	protected:
		hkPointerMapBase<hkUlong> m_map;
};

class hkClassEnum;
class hkCustomAttributes;

class hkClassMember
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum Type
		{
			TYPE_VOID = 0,
			TYPE_BOOL,
			TYPE_CHAR,
			TYPE_INT8,
			TYPE_UINT8,
			TYPE_INT16,
			TYPE_UINT16,
			TYPE_INT32,
			TYPE_UINT32,
			TYPE_INT64,
			TYPE_UINT64,
			TYPE_REAL,
			TYPE_VECTOR4,
			TYPE_QUATERNION,
			TYPE_MATRIX3,
			TYPE_ROTATION,
			TYPE_QSTRANSFORM,
			TYPE_MATRIX4,
			TYPE_TRANSFORM,
			TYPE_ZERO,
			TYPE_POINTER,
			TYPE_FUNCTIONPOINTER,
			TYPE_ARRAY,
			TYPE_INPLACEARRAY,
			TYPE_ENUM,
			TYPE_STRUCT,
			TYPE_SIMPLEARRAY,
			TYPE_HOMOGENEOUSARRAY,
			TYPE_VARIANT,
			TYPE_CSTRING,
			TYPE_ULONG,
			TYPE_FLAGS,
			TYPE_MAX
		};
		enum FlagValues
		{
			FLAGS_NONE = 0,
			ALIGN_8 = 128,
            ALIGN_16 = 256,
            NOT_OWNED = 512,
            SERIALIZE_IGNORED = 1024
		};
		typedef hkFlags<FlagValues, hkUint16> Flags;
		enum DeprecatedFlagValues
		{
			DEPRECATED_SIZE_8 = 8,
			DEPRECATED_ENUM_8 = 8,
			DEPRECATED_SIZE_16 = 16,
			DEPRECATED_ENUM_16 = 16,
			DEPRECATED_SIZE_32 = 32,
			DEPRECATED_ENUM_32 = 32
		};
		inline const char* getName() const;
		inline void setType(hkClassMember::Type type);
		inline hkClassMember::Type getSubType() const;
		inline void setSubType(hkClassMember::Type subtype);
		inline hkBool hasClass() const;
		const hkClass& getStructClass() const;
		inline hkBool hasEnumClass() const;
		const hkClassEnum& getEnumClass() const;
		inline int getOffset() const;
		inline void setOffset(int offset);
		inline const Flags& getFlags() const;
		inline Flags& getFlags();
		struct TypeProperties
		{
			hkEnum<hkClassMember::Type,hkUint8> m_type;
			const char* m_name;
			short m_size;
			short m_align;
			                class MustEndWithSemiColon;
		};
	private:
		const char* m_name;
		const hkClass* m_class;
		const hkClassEnum* m_enum;
		hkEnum<Type,hkUint8> m_type;
		hkEnum<Type,hkUint8> m_subtype;
		hkInt16 m_cArraySize;
		Flags m_flags;
		hkUint16 m_offset;
		const hkCustomAttributes* m_attributes;
};

inline void hkClassMember::setType(hkClassMember::Type type)
{
	m_type = type;
}

class hkClassEnum
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		class Item
		{
			public:
				              __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				Item( int v, const char* n) : m_value(v), m_name(n) { }
				const char* getName() const { return m_name; }
				int getValue() const { return m_value; }
			private:
				int m_value;
				const char* m_name;
		};
		enum FlagValues
		{
			FLAGS_NONE = 0
		};
		typedef hkFlags<FlagValues, hkUint32> Flags;
		hkClassEnum( const char* name, const Item* items, int numItems );
		const char* getName() const;
		int getNumItems() const;
		const hkClassEnum::Item& getItem(int i) const;
		hkResult getNameOfValue( int val, const char** name ) const;
		hkResult getValueOfName( const char* name, int* val ) const;
		hkResult decomposeFlags( int flagValue, hkArray<const char*>& bitsOut, int& bitsOver ) const;
		hkUint32 getSignature() const;
		void writeSignature( hkStreamWriter* w ) const;
		const hkVariant* getAttribute(const char* name) const;
	private:
		const char* m_name;
		const class Item* m_items;
		int m_numItems;
		class hkCustomAttributes* m_attributes;
		Flags m_flags;
};

class hkTypedUnion;

class hkClass
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum SignatureFlags
		{
			SIGNATURE_LOCAL = 1
		};
		enum FlagValues
        {
			FLAGS_NONE = 0,
			FLAGS_NOT_SERIALIZABLE = 1
        };
		typedef hkFlags<FlagValues, hkUint32> Flags;
		int getNumDeclaredEnums() const;
		const hkClassMember& getMember(int i) const;
		hkClassMember& getMember(int i);
		int getNumMembers() const;
		const hkClassMember& getDeclaredMember(int i) const;
		int getNumDeclaredMembers() const;
		const hkClassMember* getMemberByName(const char* name) const;
		int getMemberIndexByName(const char* name) const;
		int getObjectSize() const;
		void setObjectSize(int size);
		hkBool hasVtable() const;
		hkResult getDefault(int memberIndex, hkStreamWriter* w) const;
		hkResult getDefault(int memberIndex, hkTypedUnion& value) const;
		hkUint32 getSignature(int signatureFlags = 0) const;
		int getDescribedVersion() const;
		void writeSignature( hkStreamWriter* w ) const;
		const hkVariant* getAttribute(const char* id) const;
		const Flags& getFlags() const;
		Flags& getFlags();
		typedef hkPointerMap<const hkClass*, hkInt32> UpdateFlagFromClassMap;
		static void __cdecl updateMetadataInplace( hkClass** c, int sourceVersion );
		static void __cdecl updateMetadataInplace( hkClass* c, UpdateFlagFromClassMap& updatedAlready, int sourceVersion );
	private:
		hkResult retrieveMember(int memberIndex, const void*& defaultOut, const hkClassMember*& memberOut) const;
	protected:
		const char* m_name;
		const hkClass* m_parent;
		int m_objectSize;
		int m_numImplementedInterfaces;
		const class hkClassEnum* m_declaredEnums;
		int m_numDeclaredEnums;
		const class hkClassMember* m_declaredMembers;
		int m_numDeclaredMembers;
		const void* m_defaults;
		const hkCustomAttributes* m_attributes;
		Flags m_flags;
		int m_describedVersion;
};

class hkClassAccessor;

class hkClassMemberAccessor
{
	public:
		                class MustEndWithSemiColon;
		typedef void* Pointer;
		typedef char* Cstring;
		struct SimpleArray
		{
			void* data;
			int size;
			                class MustEndWithSemiColon;
		};
        struct HomogeneousArray
        {
            hkClass* klass;
            void* data;
            int size;
			      __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
        };
		hkClassMemberAccessor( void* object, const hkClassMember* member );
		hkClassMemberAccessor(const hkVariant& v, const char* memberName);
		hkClassMemberAccessor(void* object, const hkClass& klass, const char* memberName);
		hkBool isOk() const;
		const hkClassMember& getClassMember() const;
		void* asRaw() const;
		void* getAddress() const;
		Pointer& asPointer(int index=0) const;
		Cstring& asCstring(int index=0) const;
		hkBool& asBool(int index=0) const;
		hkReal& asReal(int index=0) const;
		hkInt32& asInt32(int index=0) const;
		hkUint32& asUint32(int index=0) const;
		hkUlong& asUlong(int index=0) const;
		hkInt16& asInt16(int index=0) const;
		hkUint16& asUint16(int index=0) const;
		hkInt8& asInt8(int index=0) const;
		hkUint8& asUint8(int index=0) const;
		SimpleArray& asSimpleArray(int index=0) const;
		struct Vector4
		{
			void setCross( const Vector4& v1, const Vector4& v2)
			{
				r[0] = v1.r[1]*v2.r[2] - v1.r[2]*v2.r[1];
				r[1] = v1.r[2]*v2.r[0] - v1.r[0]*v2.r[2];
				r[2] = v1.r[0]*v2.r[1] - v1.r[1]*v2.r[0];
				r[3] = 0;
			}
			hkReal r[4];
			              __forceinline void __cdecl operator delete[](void*, void*) ; class MustEndWithSemiColon;
		};
		Vector4& asVector4(int index=0) const;
		struct Matrix3
		{
			Vector4 v[3];
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkClassMemberAccessor::Matrix3), HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); }         class MustEndWithSemiColon;
		};
		struct Transform
		{
			Vector4 r[3];
			Vector4 t;
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); }               class MustEndWithSemiColon;
		};
		Transform& asTransform(int index=0) const;
		typedef Matrix3 Rotation;
		Rotation& asRotation(int index=0) const;
		hkClassMemberAccessor member(const char* name) const;
		hkClassAccessor object() const;
		hkClassMemberAccessor(){;}
	private:
		void* m_address;
		const hkClassMember* m_member;
};

class hkClassAccessor
{
	public:
		                class MustEndWithSemiColon;
		hkClassAccessor(hkVariant& v);
		inline hkClassMemberAccessor member(const char* memberName) const;
		inline const hkClass& getClass() const;
	private:
		hkVariant m_variant;
};

hkClassMemberAccessor hkClassAccessor::member(const char* memberName) const
{
	return hkClassMemberAccessor(m_variant, memberName);
}

const hkClass& hkClassAccessor::getClass() const
{
	return *m_variant.m_class;
}

inline const char* hkClassMember::getName() const
{
	return m_name;
}

inline int hkClassMember::getOffset() const
{
	return m_offset;
}

namespace hkVector4Util
{
	__forceinline void __cdecl calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut);
	__forceinline void __cdecl setMul( const hkMatrix3& aTb, const hkMatrix3& bTc, hkMatrix3& aTcOut );
	__forceinline void __cdecl dot3_3vs3( const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut);
	__forceinline void __cdecl dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut);
	__forceinline void __cdecl dot3_2vs2( const hkVector4& a0, const hkVector4& a2, const hkVector4& b0, const hkVector4& b1, hkVector4& dotsOut);
	__forceinline void __cdecl buildOrthonormal( const hkVector4& dir, hkMatrix3& out );
	__forceinline void __cdecl buildOrthonormal( const hkVector4& dir, const hkVector4& dir2, hkMatrix3& out );
	__forceinline hkSimdReal __cdecl distToLineSquared( const hkVector4& a, const hkVector4& b, const hkVector4& p );
	__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
	__forceinline void __cdecl reserveRegisters( hkUint32 registerMask );
	__forceinline void __cdecl releaseRegisters( hkUint32 registerMask );
	hkUint32 __cdecl packQuaternionIntoInt32( hkVector4Parameter qin);
	__forceinline void __cdecl unPackInt32IntoQuaternion( hkUint32 ivalue, hkVector4& qout );
	__forceinline void memClear16( void* dest, int numQuads);
	enum { AABB_UINT32_MAX_FVALUE = 0x7ffe0000 };
}

inline void __cdecl hkVector4Util::calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
	int min = 0;
	int ok1 = 1;
	int ok2 = 2;
	hkReal a0 = hkMath::fabs(vectorIn(0));
	hkReal a1 = hkMath::fabs(vectorIn(1));
	hkReal a2 = hkMath::fabs(vectorIn(2));
	if( a1 < a0 )
	{
		ok1 = 0;
		min = 1;
		a0 = a1;
	}
	if(a2 < a0)
	{
		ok2 = min;
		min = 2;
	}
	biVectorOut.setZero4();
	biVectorOut(ok1) =  vectorIn(ok2);
	biVectorOut(ok2) = -vectorIn(ok1);
}

inline void __cdecl hkVector4Util::buildOrthonormal( const hkVector4& dir, hkMatrix3& out )
{
	out.getColumn(0) = dir;
	calculatePerpendicularVector( dir, out.getColumn(1));
	out.getColumn(1).normalize3();
	out.getColumn(2).setCross( dir, out.getColumn(1));
}

void __cdecl hkVector4Util::buildOrthonormal( const hkVector4& dir, const hkVector4& dir2, hkMatrix3& out )
{
	out.getColumn(0) = dir;
	out.getColumn(2).setCross( dir, dir2 );
	if ( out.getColumn(2).length3() < 1.192092896e-07F )
	{
		buildOrthonormal( dir, out );
		return;
	}
	out.getColumn(2).normalize3();
	out.getColumn(1).setCross( out.getColumn(2), dir );
}

class hkObjectUpdateTracker : public hkReferencedObject
{
	public:
		virtual void addAllocation(void* p) = 0;
		virtual void addChunk(void* p, int n, HK_MEMORY_CLASS c) = 0;
		virtual void objectPointedBy( void* object, void* fromWhere ) = 0;
		virtual void replaceObject( void* oldObject, void* newObject, const hkClass* newClass ) = 0;
		virtual void addFinish( void* newObject, const char* className ) = 0;
		virtual void removeFinish( void* oldObject ) = 0;
};

struct Vector4 : public hkVector4
{
	Vector4( const hkClassMemberAccessor::Vector4& v )
	{
		hkQuadRealUnion u;
		u.r[0] = v.r[0];
		u.r[1] = v.r[1];
		u.r[2] = v.r[2];
		u.r[3] = v.r[3];
		getQuad() = u.q;
	}
};

static int getSizeOfAtoms( const hkClassMemberAccessor& newAtoms )
{
	const hkClass& atomClass = newAtoms.object().getClass();
	const hkClassMember& lastMember = atomClass.getMember( atomClass.getNumMembers() - 1 );
	return newAtoms.member( lastMember.getName() ).getClassMember().getOffset() + lastMember.getStructClass().getObjectSize();
}

static hkInt16 getTypeValueFromEnumName( const hkClassAccessor& memAcc, const char* typeName )
{
	int ret;
	hkResult res = memAcc.member( "type" ).getClassMember().getEnumClass().getValueOfName( typeName, &ret );
	return static_cast<hkInt16>( ret );
}

static void setLocalTransformsAtomData( const hkClassAccessor& local, const hkClassMemberAccessor::Transform& transformA, const hkClassMemberAccessor::Transform& transformB )
{
	static hkInt16 TYPE_SET_LOCAL_TRANSFORMS = -1;
	if( TYPE_SET_LOCAL_TRANSFORMS == -1 ) TYPE_SET_LOCAL_TRANSFORMS = getTypeValueFromEnumName( local, "TYPE_SET_LOCAL_TRANSFORMS" );
	local.member( "type" ).asInt16() = TYPE_SET_LOCAL_TRANSFORMS;
	local.member( "transformA" ).asTransform() = transformA;
	local.member( "transformB" ).asTransform() = transformB;
}

static void setLocalRotationsAtomData( const hkClassAccessor& rotations, const hkClassMemberAccessor::Matrix3& rotationA, const hkClassMemberAccessor::Matrix3& rotationB )
{
	static hkInt16 TYPE_SET_LOCAL_ROTATIONS = -1;
	if( TYPE_SET_LOCAL_ROTATIONS == -1 ) TYPE_SET_LOCAL_ROTATIONS = getTypeValueFromEnumName( rotations, "TYPE_SET_LOCAL_ROTATIONS" );
	rotations.member( "type" ).asInt16() = TYPE_SET_LOCAL_ROTATIONS;
	rotations.member( "rotationA" ).asRotation() = rotationA;
	rotations.member( "rotationB" ).asRotation() = rotationB;
}

static void setLinearAtomData( const hkClassAccessor& linear, hkUint8 axisIndex )
{
	static hkInt16 TYPE_LIN = -1;
	if( TYPE_LIN == -1 ) TYPE_LIN = getTypeValueFromEnumName( linear, "TYPE_LIN" );
	linear.member( "type" ).asInt16() = TYPE_LIN;
	linear.member( "axisIndex" ).asUint8() = axisIndex;
}

static void setLinearSoftAtomData( const hkClassAccessor& linearSoft, hkUint8 axisIndex, hkReal tau, hkReal damping )
{
	static hkInt16 TYPE_LIN_SOFT = -1;
	if( TYPE_LIN_SOFT == -1 ) TYPE_LIN_SOFT = getTypeValueFromEnumName( linearSoft, "TYPE_LIN_SOFT" );
	linearSoft.member( "type" ).asInt16() = TYPE_LIN_SOFT;
	linearSoft.member( "axisIndex" ).asUint8() = axisIndex;
	linearSoft.member( "tau" ).asReal() = tau;
	linearSoft.member( "damping" ).asReal() = damping;
}

static void setLinearLimitAtomData( const hkClassAccessor& linearLimit, hkUint8 axisIndex, hkReal minLimit, hkReal maxLimit )
{
	static hkInt16 TYPE_LIN_LIMIT = -1;
	if( TYPE_LIN_LIMIT == -1 ) TYPE_LIN_LIMIT = getTypeValueFromEnumName( linearLimit, "TYPE_LIN_LIMIT" );
	linearLimit.member( "type" ).asInt16() = TYPE_LIN_LIMIT;
	linearLimit.member( "axisIndex" ).asUint8() = axisIndex;
	linearLimit.member( "min" ).asReal() = minLimit;
	linearLimit.member( "max" ).asReal() = maxLimit;
}

static void set2dAngAtomData( const hkClassAccessor& atom2dAng, hkUint8 freeRotationAxis )
{
	static hkInt16 TYPE_2D_ANG = -1;
	if( TYPE_2D_ANG == -1 ) TYPE_2D_ANG = getTypeValueFromEnumName( atom2dAng, "TYPE_2D_ANG" );
	atom2dAng.member( "type" ).asInt16() = TYPE_2D_ANG;
	atom2dAng.member( "freeRotationAxis" ).asUint8() = freeRotationAxis;
}

void __cdecl FUN_0093acb0( hkVariant& oldObj, hkVariant& newObj, hkObjectUpdateTracker& )
{
	hkClassMemberAccessor newAtoms( newObj, "atoms" );
	hkClassAccessor newData( newObj );
	hkClassAccessor oldData( oldObj );
	static hkInt16 sizeOfAllAtoms = -1;
	if( sizeOfAllAtoms == -1 ) sizeOfAllAtoms = static_cast<hkInt16>( getSizeOfAtoms( newAtoms ) );
	hkTransform transformA;
	hkTransform transformB;
	{
		hkClassAccessor basisA = oldData.member( "basisA" ).object();
		Vector4 pivot = basisA.member( "pivot" ).asVector4();
		transformA.getRotation().setIdentity();
		transformA.setTranslation( pivot );
	}
	{
		hkClassAccessor basisB = oldData.member( "basisB" ).object();
		Vector4 pivot = basisB.member( "pivot" ).asVector4();
		Vector4 suspensionAxis = basisB.member( "suspensionAxis" ).asVector4();
		hkVector4Util::buildOrthonormal( suspensionAxis, transformB.getRotation() );
		transformB.setTranslation( pivot );
	}
	setLocalTransformsAtomData( newAtoms.member( "suspensionBase" ).object(), reinterpret_cast<hkClassMemberAccessor::Transform&>( transformA ), reinterpret_cast<hkClassMemberAccessor::Transform&>( transformB ) );
	setLinearLimitAtomData( newAtoms.member( "lin0Limit" ).object(), 0, oldData.member( "suspensionMinLimit" ).asReal(), oldData.member( "suspensionMaxLimit" ).asReal() );
	setLinearSoftAtomData( newAtoms.member( "lin0Soft" ).object(), 0, oldData.member( "suspensionStrength" ).asReal(), oldData.member( "suspensionDamping" ).asReal() );
	setLinearAtomData( newAtoms.member( "lin1" ).object(), 1 );
	setLinearAtomData( newAtoms.member( "lin2" ).object(), 2 );
	hkRotation rotationA;
	hkRotation rotationB;
	{
		hkClassAccessor basisA = oldData.member( "basisA" ).object();
		Vector4 axle = basisA.member( "axle" ).asVector4();
		hkVector4Util::buildOrthonormal( axle, rotationA );
	}
	{
		hkClassAccessor basisB = oldData.member( "basisB" ).object();
		Vector4 referenceAxle = basisB.member( "referenceAxle" ).asVector4();
		Vector4 steeringAxis = basisB.member( "steeringAxis" ).asVector4();
		reinterpret_cast<hkVector4&>( newData.member( "initialAxleInB" ).asVector4() ) = referenceAxle;
		reinterpret_cast<hkVector4&>( newData.member( "initialSteeringAxisInB" ).asVector4() ) = steeringAxis;
		hkVector4Util::buildOrthonormal( referenceAxle, steeringAxis, rotationB );
	}
	setLocalRotationsAtomData( newAtoms.member( "steeringBase" ).object(), reinterpret_cast<hkClassMemberAccessor::Matrix3&>( rotationA ), reinterpret_cast<hkClassMemberAccessor::Matrix3&>( rotationB ) );
	set2dAngAtomData( newAtoms.member( "2dAng" ).object(), 0 );
}
}

// @f3 0x00939390 (community match, verified in this file)
namespace f3m_00939390 {

namespace point_plane_compat {
using namespace ::f3m_0093a410::hk93a410;

namespace WheelMath = ::f3m_0093acb0;
static __forceinline WheelMath::hkVector4 pointPlaneNormal(const WheelMath::hkClassMemberAccessor::Vector4& raw)
{
    WheelMath::hkQuadRealUnion lanes;
    lanes.r[0] = raw.r[0];
    lanes.r[1] = raw.r[1];
    lanes.r[2] = raw.r[2];
    lanes.r[3] = raw.r[3];
    WheelMath::hkVector4 normal;
    normal.getQuad() = lanes.q;
    return normal;
}
static __forceinline void normalizePointPlaneColumn(WheelMath::hkVector4& v)
{
    WheelMath::hkReal l2 = (v(0)*v(0)) + (v(1)*v(1)) + (v(2)*v(2));
    WheelMath::hkSimdReal inverseLength;
    if (l2 != 0.0f)
        inverseLength = WheelMath::hkMath::sqrtInverse(l2);
    else
        inverseLength = 0.0f;
    v.mul4(inverseLength);
}

static __forceinline void buildPointPlaneOrthonormal(const WheelMath::hkVector4& dir, WheelMath::hkMatrix3& out)
{
    out.getColumn(0) = dir;
    {
        int minAxis = 0, first = 1, second = 2;
        WheelMath::hkReal a0 = WheelMath::hkMath::fabs(dir(0));
        WheelMath::hkReal a1 = WheelMath::hkMath::fabs(dir(1));
        WheelMath::hkReal a2 = WheelMath::hkMath::fabs(dir(2));
        if (a1 < a0) { first = 0; minAxis = 1; a0 = a1; }
        if (a2 < a0) { second = minAxis; minAxis = 2; }
        WheelMath::hkVector4& perp = out.getColumn(1);
        perp.setZero4();
        perp(first) = dir(second);
        perp(second) = -dir(first);
    }
    normalizePointPlaneColumn(out.getColumn(1));
    out.getColumn(2).setCross(dir,out.getColumn(1));
}

void __cdecl FUN_00939390(hkVariant& oldObject, hkVariant& newObject, hkObjectUpdateTracker&)
{
    hkTransform xf;
    hkClassMemberAccessor atoms(newObject, "atoms");
    hkClassAccessor oldData(oldObject);
    static short DAT_0105f5d0 = -1;
    if (DAT_0105f5d0 == -1)
        DAT_0105f5d0 = static_cast<short>(FUN_009366b0(atoms));

    hkClassMemberAccessor::Vector4 pa = getVector4(oldData.member("pivotInA").FUN_0093d720());
    hkClassMemberAccessor::Vector4 pb = getVector4(oldData.member("pivotInB").FUN_0093d720());
    const WheelMath::hkVector4 normal = pointPlaneNormal(reinterpret_cast<const WheelMath::hkClassMemberAccessor::Vector4&>(oldData.member("planeNormalA").FUN_0093d720()));
    xf.getColumn(0).y = 0.0f; xf.getColumn(0).z = 0.0f; xf.getColumn(0).w = 0.0f;
    xf.getColumn(1).x = 0.0f; xf.getColumn(1).z = 0.0f; xf.getColumn(1).w = 0.0f;
    xf.getColumn(2).x = 0.0f; xf.getColumn(2).y = 0.0f; xf.getColumn(2).w = 0.0f;
    xf.getColumn(0).x = 1.0f; xf.getColumn(1).y = 1.0f; xf.getColumn(2).z = 1.0f;
    xf.getTranslation() = reinterpret_cast<const hkVector4&>(pb);

    WheelMath::hkTransform frame;
    buildPointPlaneOrthonormal(normal,frame.getRotation());
    frame.setTranslation(reinterpret_cast<const WheelMath::hkVector4&>(pa));

    FUN_009367e0(atoms.FUN_0093d7a0("transforms").FUN_0093d810(),
        reinterpret_cast<const hkClassMemberAccessor::Transform&>(xf),
        reinterpret_cast<const hkClassMemberAccessor::Transform&>(frame));
    FUN_00936ab0(atoms.FUN_0093d7a0("lin").FUN_0093d810(), 0);
}
}
}   // namespace f3m_00939390
