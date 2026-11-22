// Overflow unit of the 0x00940000 window (17 Nov 2026): 0x00943200 and 0x00943250 pass an argument in a register only
// in a translation unit with no 16-byte-aligned locals, which f3blk_00940000_o2.cpp and _od.cpp both have.

// @f3 0x00943250 (community match, verified in this file)
namespace f3m_00943250 {
namespace compat55 {

struct ClassMember;

struct ClassInfo
{
    const char* getName() const throw();
    int getObjectSize() const throw();
};

struct Variant
{
    void* m_object;
    const ClassInfo* m_class;
};

template <typename T>
struct Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const throw() { return m_size; }
    T& operator[](int i) throw() { return m_data[i]; }
};

struct ClassRename
{
    const char* oldName;
    const char* newName;
};

struct UpdateTracker
{
    virtual ~UpdateTracker() throw();
    virtual void unused04() throw();
    virtual void unused08() throw();
    virtual void addAllocation(void* p) throw();
};

struct ClassAccessor
{
    Variant m_variant;
    const ClassInfo& getClass() const throw() { return *m_variant.m_class; }
};

struct MemberAccessor
{
    struct SimpleArray
    {
        void* data;
        int size;
    };

    MemberAccessor(const Variant& v, const char* memberName) throw();
    char*& asCstring(int index = 0) const throw();
    SimpleArray& asSimpleArray(int index = 0) const throw();
    ClassAccessor object() const throw();

    void* m_address;
    const ClassMember* m_member;
};

int strCmp(const char* a, const char* b) throw();
char* strDup(const char* s) throw();

static __declspec(noinline) void updateNamedVariantClassName(Variant& v, const ClassRename* renames, UpdateTracker& tracker) throw()
{
    MemberAccessor className(v, "className");
    char*& name = className.asCstring();
    while (renames->oldName && name)
    {
        if (strCmp(name, renames->oldName) == 0)
        {
            char* newName = strDup(renames->newName);
            tracker.addAllocation(newName);
            name = newName;
            return;
        }
        renames++;
    }
}

static __declspec(noinline) void updateAllNamedVariantsClassName(MemberAccessor::SimpleArray& namedVariantArray, const ClassInfo& namedVariantClass, const ClassRename* renames, UpdateTracker& tracker) throw()
{
    for (int i = 0; i < namedVariantArray.size; ++i)
    {
        Variant namedVariant = { (char*)namedVariantArray.data + i * namedVariantClass.getObjectSize(), &namedVariantClass };
        updateNamedVariantClassName(namedVariant, renames, tracker);
    }
}

}

using compat55::ClassInfo;
using compat55::MemberAccessor;

void FUN_00943250(compat55::Array<compat55::Variant>& objectsInOut, const compat55::ClassRename* renames, compat55::UpdateTracker& tracker)
{
    if (renames->oldName == 0)
    {
        return;
    }

    for (int i = 0; i < objectsInOut.getSize(); ++i)
    {
        const ClassInfo* klass = objectsInOut[i].m_class;
        if (compat55::strCmp(klass->getName(), "hkRootLevelContainer") == 0)
        {
            MemberAccessor namedVariants(objectsInOut[i], "namedVariants");
            MemberAccessor::SimpleArray& namedVariantArray = namedVariants.asSimpleArray();
            compat55::updateAllNamedVariantsClassName(namedVariantArray, namedVariants.object().getClass(), renames, tracker);
        }
        if (compat55::strCmp(klass->getName(), "hkRootLevelContainerNamedVariant") == 0)
        {
            compat55::updateNamedVariantClassName(objectsInOut[i], renames, tracker);
        }
    }
}
}   // namespace f3m_00943250

// @f3 0x00943200 (community match, verified in this file)
namespace f3m_00943200 {
// Shared reconstruction from checkpoint chk_04b1585bb8c547fc9386; independently rechecked in the repaired unit.
namespace ns_00943200 {
struct Klass { int FUN_009b0760(); };
struct Variant { void* object; Klass* klass; };
struct MemberAccessor
{
    void* member; void* object;
    MemberAccessor(Variant* variant, const char* memberName);
    char** FUN_0093d680(int index);
};
struct NameEntry { const char* oldName; const char* newName; };
struct Tracker
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C(char* name);
};
struct VariantArray { char* data; int size; };
int __cdecl hkString_strCmp(const char* a, const char* b);
char* __cdecl FUN_00923640(const char* name);

static __declspec(noinline) void FUN_00943180(Variant* variant, NameEntry* table, Tracker* tracker)
{
    MemberAccessor accessor(variant, "className");
    char** name = accessor.FUN_0093d680(0);
    NameEntry* e = table;
    const char* oldName = e->oldName;
    if (oldName)
    {
        do
        {
            const char* currentName = *name;
            if (!currentName)
                return;
            if (hkString_strCmp(currentName, oldName) == 0)
            {
                char* renamed = FUN_00923640(e->newName);
                tracker->vf0C(renamed);
                *name = renamed;
                return;
            }
            ++e;
            oldName = e->oldName;
        } while (oldName);
    }
}

// pdb: hkStatisticsCollector::addObjectMemory | hkStatisticsCollector.obj | fnv360_0822_debug, caller_sim, low
// pdb params: cls, obj, flags
static __declspec(noinline) void FUN_00943200(VariantArray* array, Tracker* tracker, Klass* klass, NameEntry* table)
{
    Variant variant;
    for (int i = 0; i < array->size; ++i)
    {
        variant.object = array->data + klass->FUN_009b0760() * i;
        variant.klass = klass;
        FUN_00943180(&variant, table, tracker);
    }
}

VariantArray* volatile g_array; Tracker* volatile g_tracker; Klass* volatile g_klass; NameEntry* volatile g_table;
void caller_of_FUN_00943200() { FUN_00943200(g_array, g_tracker, g_klass, g_table); }
}
}   // namespace f3m_00943200

// @f3 0x00940060 (community match, verified in this file)
namespace f3m_00940060 {
// FUN_00940060 = Havok 5.5.0 hkVersionUtil::updateSingleVersion (hkSerialize.lib, hkVersionUtil.obj;
// Source\Common\Serialize\Version\hkVersionUtil.cpp lines 740-894), with the file-static copyObjects it calls
// (game 0x0093fdc0, 660 bytes). Declarations and inline bodies are Havok 5.5.0 SDK header text in reduced form.
// The two function bodies were written from the SDK headers and the debug records of the hybrid library object.
namespace f3m_00940060 {

typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

class hkClass;

struct hkVariant
{
	void* m_object;
	const hkClass* m_class;
};

class hkBool
{
	public:
		inline operator bool() const
		;
	private:
		char m_bool;
};

template<typename BITS, typename STORAGE>
class hkFlags
{
	public:
		hkFlags(STORAGE s)
		{
			m_storage = s;
		}
	private:
		STORAGE m_storage;
};

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

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
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
		__forceinline void removeReference() const;
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

__forceinline void hkReferencedObject::removeReference() const
{
	if ( m_memSizeAndFlags != 0 )
	{
		--m_referenceCount;
		if ( m_referenceCount == 0 )
		{
			delete this;
		}
	}
}

template <typename T>
class hkSingleton
{
	public:
		static T* s_instance;
};

class hkStreamWriter;
template<typename T> class hkArray;

class hkOstream : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		explicit hkOstream( hkArray<char>& buf );
		~hkOstream();
		hkStreamWriter* getStreamWriter();
	protected:
		hkStreamWriter*	m_writer;
};

__forceinline hkStreamWriter*	hkOstream::getStreamWriter()
{
	return m_writer;
}

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
		__forceinline hkArray();
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		void removeAt(int index);
		__forceinline void pushBack(const T& e);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		static void __cdecl copy(T* dst, const T* src, int n);
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
__forceinline void __cdecl hkArray<T>::copy(T* dst, const T* src, int n)
{
	for(int i = 0; i < n; ++i)
	{
		dst[i] = src[i];
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
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
__forceinline hkArray<T>& hkArray<T>::operator= (const hkArray<T>& a)
{
	if(getCapacity() < a.m_size)
	{
		releaseMemory();
		m_data = static_cast<T*>( hkThreadMemory::getInstance().allocateChunk( a.m_size * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY));
		m_capacityAndFlags = a.m_size | (m_capacityAndFlags & static_cast<int>(LOCKED_FLAG));
	}
	m_size = a.m_size;
	copy(m_data, a.m_data, m_size);
	return *this;
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

template <typename T>
__forceinline void hkArray<T>::removeAt(int i)
{
	m_size--;
	m_data[i] = m_data[m_size];
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

class hkString
{
	public:
		                class MustEndWithSemiColon;
	public:
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
	private:
		hkArray<char> m_string;
	public:
		static int __cdecl strCmp(const char* s1, const char* s2 );
		static void __cdecl memCpy(void* dst, const void* src, int n);
};

template <typename T>
class hkPointerMapBase
{
	public:
		                class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
		hkPointerMapBase();
		~hkPointerMapBase();
		void insert( T key, T val );
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

template <typename K, typename V>
class hkPointerMap
{
	public:
		                class MustEndWithSemiColon;
		typedef hkPointerMapBase<hkUlong>::Iterator Iterator;
		__forceinline void insert( K key, V val )
		{
			m_map.insert( hkUlong(key), hkUlong(val) );
		}
	protected:
		hkPointerMapBase<hkUlong> m_map;
};

class hkCustomAttributes;

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
		const char* getName() const;
		typedef hkPointerMap<const hkClass*, hkInt32> UpdateFlagFromClassMap;
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

class hkClassNameRegistry : public hkReferencedObject
{
	public:
		virtual const char* getName() const = 0;
		virtual const hkClass* getClassByName( const char* className ) const = 0;
		virtual void getClasses( hkArray<const hkClass*>& classes ) const = 0;
};

template <typename Operations>
class hkCachedHashMap
{
	public:
		                class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
		~hkCachedHashMap();
		void insert( hkUlong key, hkUlong val );
		hkUlong getWithDefault( hkUlong key, hkUlong def ) const;
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
		                class MustEndWithSemiColon;
		typedef hkStringMapBase::Iterator Iterator;
		__forceinline void insert( const char* key, V val )
		{
			m_map.insert( hkUlong(key), hkUlong(val) );
		}
		__forceinline V getWithDefault( const char* key, V def ) const
		{
			return (V)m_map.getWithDefault( hkUlong(key), hkUlong(def) );
		}
	protected:
		hkStringMapBase m_map;
};

class hkDynamicClassNameRegistry;

class hkStaticClassNameRegistry;
class hkObjectUpdateTracker;

class hkVersionRegistry : public hkReferencedObject, public hkSingleton<hkVersionRegistry>
{
	public:
		typedef void (__cdecl *VersionFunc)(hkVariant& obj, hkVariant& newObj, hkObjectUpdateTracker& tracker);
		enum SignatureFlags
		{
			AUTO_SIGNATURE = 0xffffffff
		};
		enum VersionFlags
		{
			VERSION_MANUAL = 1<<1,
			VERSION_INPLACE = 1<<2,
			VERSION_COPY = 1<<3,
			VERSION_REMOVED = 1<<4,
			VERSION_VARIANT = 1<<5
		};
		struct ClassRename
		{
			const char* oldName;
			const char* newName;
			                class MustEndWithSemiColon;
		};
		struct ClassAction
		{
			hkUint32 oldSignature;
			hkUint32 newSignature;
			int  versionFlags;
			const char* oldClassName;
			VersionFunc versionFunc;
			                class MustEndWithSemiColon;
		};
		struct UpdateDescription
		{
			const ClassRename* m_renames;
			const ClassAction* m_actions;
			const hkClassNameRegistry* m_newClassRegistry;
			UpdateDescription* m_next;
			                class MustEndWithSemiColon;
		};
		typedef hkResult (__cdecl* UpdateFunction)(
			hkArray<hkVariant>& loadedObjects,
			hkObjectUpdateTracker& tracker );
		struct Updater
		{
			const char* fromVersion;
			const char* toVersion;
			UpdateDescription* desc;
			UpdateFunction optionalCustomFunction;
			                class MustEndWithSemiColon;
		};
		~hkVersionRegistry();
	public:
		hkArray<const Updater*> m_updaters;
		static const Updater* StaticLinkedUpdaters[];
		static const hkStaticClassNameRegistry* StaticLinkedClassRegistries[];
	private:
		mutable hkStringMap<hkDynamicClassNameRegistry*> m_versionToClassNameRegistryMap;
};

namespace hkVersionUtil
{
	void __cdecl copyDefaults( void* obj, const hkClass& oldClass, const hkClass& newClass );
	void __cdecl updateVariantClassPointers( void* obj, const hkClass& klass, hkClassNameRegistry& reg, int numObj=1 );
	hkResult __cdecl FUN_00940060(
		hkArray<hkVariant>& objectsInOut,
		hkObjectUpdateTracker& tracker,
		const hkVersionRegistry::UpdateDescription& updateDescription,
		const hkClassNameRegistry* newClassRegistry );
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

class hkRenamedClassNameRegistry : public hkClassNameRegistry
{
	public:
		hkRenamedClassNameRegistry( const hkVersionRegistry::ClassRename* renames = 0, const hkClassNameRegistry* originalRegistry = 0 )
			;
		~hkRenamedClassNameRegistry()
		{
			if( m_originalRegistry )
			{
				m_originalRegistry->removeReference();
			}
		}
		virtual const char* getName() const
		{
			return m_originalRegistry ? m_originalRegistry->getName() : 0;
		}
		virtual void getClasses( hkArray<const hkClass*>& classes ) const
		{
			if( m_originalRegistry )
			{
				m_originalRegistry->getClasses(classes);
			}
		}
		virtual const hkClass* getClassByName( const char* oldname ) const
		{
			const char* name = m_renames.getWithDefault( oldname, oldname );
			return m_originalRegistry ? m_originalRegistry->getClassByName(name) : 0;
		}
		const char* getRename( const char* oldName )
		{
			return m_renames.getWithDefault(oldName, 0);
		}
		void registerRenames( const hkVersionRegistry::ClassRename* renames )
		{
			if( renames )
			{
				for( const hkVersionRegistry::ClassRename* r = renames; r->oldName != 0; ++r )
				{
					m_renames.insert( r->oldName, r->newName );
				}
			}
		}
		hkStringMap<const char*> m_renames;
		const hkClassNameRegistry* m_originalRegistry;
};

class hkRelocationInfo
{
	public:
		                class MustEndWithSemiColon;
		hkRelocationInfo()
			: m_pool(0)
		{
		}
		~hkRelocationInfo();
		struct Local
		{
			int m_fromOffset;
			int m_toOffset;
		private:
			                class MustEndWithSemiColon;
		};
		struct Global
		{
			int m_fromOffset;
			void* m_toAddress;
			const hkClass* m_toClass;
		private:
			                class MustEndWithSemiColon;
		};
		struct Finish
		{
			int m_fromOffset;
			const char* m_className;
		private:
			                class MustEndWithSemiColon;
		};
		struct Import
		{
			int m_fromOffset;
			const char* m_identifier;
		private:
			                class MustEndWithSemiColon;
		};
		struct StringPool;
	public:
		hkArray<Local> m_local;
		hkArray<Global> m_global;
		hkArray<Finish> m_finish;
		hkArray<Import> m_imports;
		StringPool* m_pool;
};

class hkStructureLayout
{
	public:
		                class MustEndWithSemiColon;
		struct LayoutRules
		{
			hkUint8 m_bytesInPointer;
			hkUint8 m_littleEndian;
			hkUint8 m_reusePaddingOptimization;
			hkUint8 m_emptyBaseClassOptimization;
		private:
			                class MustEndWithSemiColon;
		};
		hkStructureLayout( const LayoutRules& rules );
		static const LayoutRules HostLayoutRules;
		static const LayoutRules MsvcWin32LayoutRules;
		static const LayoutRules MsvcXboxLayoutRules;
		static const LayoutRules MsvcAmd64LayoutRules;
		static const LayoutRules CwPs2LayoutRules;
		static const LayoutRules CwNgcLayoutRules;
		static const LayoutRules CwPspLayoutRules;
		static const LayoutRules CwWiiLayoutRules;
		static const LayoutRules Gcc32Ps2LayoutRules;
		static const LayoutRules Gcc151PspLayoutRules;
		static const LayoutRules Gcc295LinuxLayoutRules;
		static const LayoutRules Gcc33LinuxLayoutRules;
		static const LayoutRules Sn31Ps2LayoutRules;
		static const LayoutRules Sn10PspLayoutRules;
		static const LayoutRules Sn393NgcLayoutRules;
		static const LayoutRules Xbox360LayoutRules;
		static const LayoutRules GccPs3LayoutRules;
		static const LayoutRules Gcc40MacPpcLayoutRules;
		static const LayoutRules Gcc40MacIntelLayoutRules;
	protected:
		LayoutRules m_rules;
};

class hkObjectCopier : public hkReferencedObject
{
	public:
		enum ObjectCopierFlagBits
		{
			FLAG_NONE = 0x0,
			FLAG_APPLY_DEFAULT_IF_SERIALIZE_IGNORED = 0x1,
			FLAG_RESPECT_SERIALIZE_IGNORED = 0x2,
		};
		typedef hkFlags<ObjectCopierFlagBits,hkUint32> ObjectCopierFlags;
		hkObjectCopier(const hkStructureLayout& layoutIn, const hkStructureLayout& layoutOut, ObjectCopierFlags flags = FLAG_NONE);
		virtual ~hkObjectCopier();
		virtual hkResult copyObject(const void* dataIn, const hkClass& klassIn,
			hkStreamWriter* dataOut, const hkClass& klassOut, hkRelocationInfo& reloc );
	private:
		virtual const hkClass* lookupClass( const hkClass& klass )
		{
			return &klass;
		}
	protected:
		hkStructureLayout m_layoutIn;
		hkStructureLayout m_layoutOut;
		ObjectCopierFlags m_flags;
		hkBool m_byteSwap;
};

namespace anon_00940060 {} using namespace anon_00940060; namespace anon_00940060 {
	struct ActionFromClassName : public hkStringMap<const hkVersionRegistry::ClassAction*>
	{
		                class MustEndWithSemiColon;
		ActionFromClassName( const hkVersionRegistry::UpdateDescription& desc, hkArray<hkVariant>& objects, hkArray<int>& objectEditIndices );
	};
}

static void* copyObjects(
	const hkArray<hkVariant>& objectsIn,
	hkArray<hkVariant>& objectsOut,
	const hkArray<int>& objectIndices,
	hkObjectUpdateTracker& tracker )
{
	hkArray<char> buffer;
	hkOstream out( buffer );
	hkRelocationInfo relocations;
	hkPointerMap<const void*, int> overrides;
	for( int objectIndexIndex = 0; objectIndexIndex < objectIndices.getSize(); ++objectIndexIndex )
	{
		int objectIndex = objectIndices[objectIndexIndex];
		const hkVariant& oldVariant = objectsIn[objectIndex];
		hkObjectCopier copier( hkStructureLayout::HostLayoutRules, hkStructureLayout::HostLayoutRules );
		const hkClass* newClass = objectsOut[objectIndex].m_class;
		objectsOut[objectIndex].m_object = reinterpret_cast<void*>( hkUlong( buffer.getSize() ) );
		overrides.insert( oldVariant.m_object, buffer.getSize() );
		copier.copyObject( oldVariant.m_object, *oldVariant.m_class, out.getStreamWriter(), *newClass, relocations );
	}
	if( buffer.getSize() )
	{
		char* versioned = hkAllocateChunk<char>( buffer.getSize(), HK_MEMORY_CLASS_EXPORT );
		tracker.addChunk( versioned, buffer.getSize(), HK_MEMORY_CLASS_EXPORT );
		hkString::memCpy( versioned, buffer.begin(), buffer.getSize() );
		for( int objectIndexIndex = 0; objectIndexIndex < objectIndices.getSize(); ++objectIndexIndex )
		{
			int objectIndex = objectIndices[objectIndexIndex];
			hkVariant& v = objectsOut[objectIndex];
			v.m_object = versioned + hkUlong( v.m_object );
		}
		hkArray<hkRelocationInfo::Local>& local = relocations.m_local;
		for( int localIndex = 0; localIndex < local.getSize(); ++localIndex )
		{
			*reinterpret_cast<void**>( versioned + local[localIndex].m_fromOffset ) = versioned + local[localIndex].m_toOffset;
		}
		hkArray<hkRelocationInfo::Global>& global = relocations.m_global;
		for( int globalIndex = 0; globalIndex < global.getSize(); ++globalIndex )
		{
			void* p = global[globalIndex].m_toAddress;
			void* from = versioned + global[globalIndex].m_fromOffset;
			tracker.objectPointedBy( p, from );
		}
		return versioned;
	}
	return 0;
}

hkResult __cdecl hkVersionUtil::FUN_00940060(
	hkArray<hkVariant>& objectsInOut,
	hkObjectUpdateTracker& tracker,
	const hkVersionRegistry::UpdateDescription& updateDescription,
	const hkClassNameRegistry* newClassRegistry )
{
	hkRenamedClassNameRegistry newClassFromOldName( updateDescription.m_renames, newClassRegistry );
	const hkVersionRegistry::UpdateDescription* nextUpdateDescription = updateDescription.m_next;
	while( nextUpdateDescription )
	{
		newClassFromOldName.registerRenames( nextUpdateDescription->m_renames );
		nextUpdateDescription = nextUpdateDescription->m_next;
	}
	hkArray<int> objectEditIndices;
	ActionFromClassName actionFromClassName( updateDescription, objectsInOut, objectEditIndices );
	hkArray<int> objectCopyIndices;
	hkArray<int> removedIndices;
	hkArray<hkVariant> oldObjects;
	oldObjects = objectsInOut;
	{
		hkArray<int> withVariantIndices;
		for( int editIndexIndex = 0; editIndexIndex < objectEditIndices.getSize(); ++editIndexIndex )
		{
			int editIndex = objectEditIndices[editIndexIndex];
			const char* oldClassName = objectsInOut[editIndex].m_class->getName();
			const hkVersionRegistry::ClassAction* action = actionFromClassName.getWithDefault( oldClassName, 0 );
			const hkClass* newClass = newClassFromOldName.getClassByName( oldClassName );
			if( action->versionFlags & hkVersionRegistry::VERSION_REMOVED )
			{
				hkVariant& v = objectsInOut[editIndex];
				tracker.removeFinish( v.m_object );
				removedIndices.pushBack( editIndex );
			}
			else
			{
				objectsInOut[editIndex].m_class = newClass;
				if( action->versionFlags & hkVersionRegistry::VERSION_MANUAL )
				{
				}
				else if( action->versionFlags & hkVersionRegistry::VERSION_COPY )
				{
					objectCopyIndices.pushBack( editIndex );
				}
				else if( action->versionFlags & hkVersionRegistry::VERSION_INPLACE )
				{
					hkVariant& v = oldObjects[editIndex];
					hkVersionUtil::copyDefaults( v.m_object, *v.m_class, *newClass );
					tracker.removeFinish( v.m_object );
					tracker.addFinish( v.m_object, newClass->getName() );
				}
				if( action->versionFlags & hkVersionRegistry::VERSION_VARIANT )
				{
					withVariantIndices.pushBack( editIndex );
				}
				if( hkString::strCmp( newClass->getName(), oldClassName ) != 0 )
				{
					hkVariant& v = oldObjects[editIndex];
					tracker.removeFinish( v.m_object );
					tracker.addFinish( v.m_object, newClass->getName() );
				}
			}
		}
		copyObjects( oldObjects, objectsInOut, objectCopyIndices, tracker );
		for( int withVariantIndexIndex = 0; withVariantIndexIndex < withVariantIndices.getSize(); ++withVariantIndexIndex )
		{
			int withVariantIndex = withVariantIndices[withVariantIndexIndex];
			hkVariant& v = objectsInOut[withVariantIndex];
			hkVersionUtil::updateVariantClassPointers( v.m_object, *v.m_class, newClassFromOldName );
		}
	}
	{
		int SENTINEL = objectsInOut.getSize() + 1;
		int editIndexIndex = 0;
		int nextEdited = objectEditIndices.getSize() ? objectEditIndices[editIndexIndex] : SENTINEL;
		for( int i = 0; i < objectsInOut.getSize(); ++i )
		{
			if( i < nextEdited )
			{
				hkVariant& v = objectsInOut[i];
				if( const char* newName = newClassFromOldName.getRename( v.m_class->getName() ) )
				{
					const hkClass* c = newClassFromOldName.getClassByName( v.m_class->getName() );
					v.m_class = c;
					tracker.removeFinish( v.m_object );
					tracker.addFinish( v.m_object, newName );
				}
			}
			else if( i == nextEdited )
			{
				editIndexIndex += 1;
				nextEdited = editIndexIndex < objectEditIndices.getSize()
					? objectEditIndices[editIndexIndex]
					: SENTINEL;
			}
			else
			{
			}
		}
	}
	{
		for( int editIndexIndex = 0; editIndexIndex < objectEditIndices.getSize(); ++editIndexIndex )
		{
			int editIndex = objectEditIndices[editIndexIndex];
			hkVariant& oldObj = oldObjects[editIndex];
			hkVariant& newObj = objectsInOut[editIndex];
			const hkVersionRegistry::ClassAction* action = actionFromClassName.getWithDefault( oldObj.m_class->getName(), 0 );
			if( action && action->versionFunc )
			{
				action->versionFunc( oldObj, newObj, tracker );
			}
		}
	}
	{
		for( int copyIndexIndex = 0; copyIndexIndex < objectCopyIndices.getSize(); ++copyIndexIndex )
		{
			int copyIndex = objectCopyIndices[copyIndexIndex];
			tracker.replaceObject(
				oldObjects[copyIndex].m_object,
				objectsInOut[copyIndex].m_object,
				objectsInOut[copyIndex].m_class );
		}
		for( int removeIndexIndex = removedIndices.getSize() - 1; removeIndexIndex >= 0; --removeIndexIndex )
		{
			int removeIndex = removedIndices[removeIndexIndex];
			tracker.replaceObject( oldObjects[removeIndex].m_object, 0, 0 );
			objectsInOut.removeAt( removeIndex );
		}
	}
	return HK_SUCCESS;
}

} // namespace f3m_00940060
}   // namespace f3m_00940060
