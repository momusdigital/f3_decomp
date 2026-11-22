#include <new>
// src/f3staging/f3iso_00943180_o2.cpp - Fallout 3 ISOLATED unit (19 Nov 2026) for 0x00943180 alone: its original passes arguments in registers to
// a static helper of its own file, which only works without other code (16-byte-aligned locals) in the unit. Write the helper
// static in your candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00943180 (community match, verified in this file)
namespace f3m_00943180 {
// FUN_00943250 = Havok 5.5.0 hkCompatUtil::updateNamedVariantClassName(hkArray<hkVariant>&, const ClassRename*,
// hkObjectUpdateTracker&) (hkCompat.lib, hkCompatUtil.obj, hkCompatUtil.cpp lines 44-65). The stock release object is
// byte-exact against the game (dl\hkmap_release_multithreaded_open.tsv, 226 bytes).
// Source: Havok 5.5.0 SDK (approved source): hkCompatUtil.h and the headers it includes (hkClass, hkClassMemberAccessor,
// hkArray, hkString, hkVersionRegistry, hkObjectUpdateTracker), cut by hktrim to what these functions use.
// RECONSTRUCTED, not SDK text (hkCompatUtil.cpp is not shipped; only hkCompatUtil.h is): the bodies of the three
// functions of the object in file order, from the hybrid object's line records and locals (tools\hkobj.py):
//   FUN_00943180 = file-local updateNamedVariantClassName(hkVariant&, ...)   (lines 16-32, 116 bytes release)
//   FUN_00943200 = file-local updateAllNamedVariantsClassName(...)           (lines 34-42, 67 bytes release)
//   FUN_00943250 = hkCompatUtil::updateNamedVariantClassName(hkArray&, ...)  (lines 44-65, 226 bytes release)
// The FUN_ names are the project's game-address names for the Havok functions (the real caller of the two file-local
// functions is FUN_00943250, which is in this file). Nothing else is invented: no extra locals, helpers or casts.
namespace f3m_00943180 {
typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
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

template <typename T>
class hkSingleton
{
	public:
		static T* s_instance;
};

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
		__forceinline int getSize() const;
		__forceinline T& expandOne( );
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
	;
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
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
		static char* __cdecl strDup(const char* src);
};

template <typename T>
class hkPointerMapBase
{
	public:
		                class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
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
		int getObjectSize() const;
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
			                class MustEndWithSemiColon;
        };
		hkClassMemberAccessor(const hkVariant& v, const char* memberName);
		Cstring& asCstring(int index=0) const;
		SimpleArray& asSimpleArray(int index=0) const;
		struct Vector4
		{
			hkReal r[4];
			                class MustEndWithSemiColon;
		};
		struct Matrix3
		{
			Vector4 v[3];
			                class MustEndWithSemiColon;
		};
		struct Transform
		{
			Vector4 r[3];
			Vector4 t;
			                class MustEndWithSemiColon;
		};
		typedef Matrix3 Rotation;
		hkClassAccessor object() const;
	private:
		void* m_address;
		const hkClassMember* m_member;
};

class hkClassAccessor
{
	public:
		                class MustEndWithSemiColon;
		inline const hkClass& getClass() const;
	private:
		hkVariant m_variant;
};

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
		;
		__forceinline V getWithDefault( const char* key, V def ) const
		;
		Iterator getIterator() const
		;
		V getValue( Iterator i ) const
		;
		Iterator getNext( Iterator i ) const
		;
		hkBool isValid( Iterator i ) const
		;
	protected:
		hkStringMapBase m_map;
};

class hkDynamicClassNameRegistry : public hkClassNameRegistry
{
	public:
		virtual const char* getName() const
		{
			return m_name;
		}
		virtual void setName(const char* name)
		{
			m_name = name;
		}
		virtual const hkClass* getClassByName( const char* className ) const
		{
			return m_map.getWithDefault(className, 0);
		}
		virtual void getClasses( hkArray<const hkClass*>& classes ) const
		{
			hkStringMap<const hkClass*>::Iterator iter = m_map.getIterator();
			while (m_map.isValid(iter))
			{
				classes.expandOne() = m_map.getValue(iter);
				iter = m_map.getNext(iter);
			}
		}
		virtual void registerClass( const hkClass* klass, const char* name = 0 )
		{
			m_map.insert( name ? name : klass->getName(), klass );
		}
		virtual void registerList( const hkClass* const * classes)
		{
			const hkClass* const * ci = classes;
			while(*ci != 0)
			{
				registerClass( *ci );
				++ci;
			}
		}
		virtual void merge(const hkStringMap<const hkClass*>& mergeFromMap)
		{
			hkStringMap<const hkClass*>::Iterator iter = mergeFromMap.getIterator();
			while (mergeFromMap.isValid(iter))
			{
				registerClass( mergeFromMap.getValue(iter) );
				iter = mergeFromMap.getNext(iter);
			}
		}
		virtual void merge(const hkClassNameRegistry& mergeFrom)
		{
			hkArray<const hkClass*> classes;
			mergeFrom.getClasses(classes);
			for( int i = 0; i < classes.getSize(); ++i )
			{
				registerClass( classes[i] );
			}
		}
	protected:
		const char* m_name;
		hkStringMap<const hkClass*> m_map;
};

class hkStaticClassNameRegistry;

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


static void FUN_00943180( hkVariant& namedVariantInOut, const hkVersionRegistry::ClassRename* renames, hkObjectUpdateTracker& tracker )
{
	hkClassMemberAccessor className(namedVariantInOut, "className");
	hkClassMemberAccessor::Cstring& namedVariantClassName = className.asCstring();
	while( renames->oldName && namedVariantClassName )
	{
		if( hkString::strCmp( namedVariantClassName, renames->oldName ) == 0 )
		{
			char* variantClassName = hkString::strDup( renames->newName );
			tracker.addAllocation( variantClassName );
			namedVariantClassName = variantClassName;
			break;
		}
		++renames;
	}
}

static void FUN_00943200( hkClassMemberAccessor::SimpleArray& namedVariantsArray, const hkClass& namedVariantClass, const hkVersionRegistry::ClassRename* renames, hkObjectUpdateTracker& tracker )
{
	for( int i = 0; i < namedVariantsArray.size; ++i )
	{
		void* namedVariantObjPtr = static_cast<char*>(namedVariantsArray.data) + namedVariantClass.getObjectSize() * i;
		hkVariant namedVariant = { namedVariantObjPtr, &namedVariantClass };
		FUN_00943180( namedVariant, renames, tracker );
	}
}

void __cdecl FUN_00943250( hkArray<hkVariant>& objectsInOut, const hkVersionRegistry::ClassRename* renames, hkObjectUpdateTracker& tracker )
{
	if( renames->oldName == 0 )
	{
		return;
	}
	for( int i = 0; i < objectsInOut.getSize(); ++i )
	{
		const hkClass* klass = objectsInOut[i].m_class;
		if( hkString::strCmp( klass->getName(), "hkRootLevelContainer" ) == 0 )
		{
			hkClassMemberAccessor namedVariants( objectsInOut[i], "namedVariants" );
			hkClassMemberAccessor::SimpleArray& namedVariantsArray = namedVariants.asSimpleArray();
			FUN_00943200( namedVariantsArray, namedVariants.object().getClass(), renames, tracker );
		}
		if( hkString::strCmp( klass->getName(), "hkRootLevelContainerNamedVariant" ) == 0 )
		{
			FUN_00943180( objectsInOut[i], renames, tracker );
		}
	}
}

} // namespace f3m_00943180

}   // namespace f3m_00943180
