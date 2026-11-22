#include "f3_common.h"
// src/havok/animation/animation/mapper/hkaskeletonmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaSkeletonMapper.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkaBone
{
    hkStringPtr m_name;
    hkBool m_bLockTranslation;
};

class hkaSkeleton : public hkReferencedObject
{
  public:
    hkStringPtr m_name;
    hkArray<hkInt16> m_kParentIndices;
    hkArray<hkaBone> m_kBones;
};

class hkaSkeletonMapperDataSimpleMapping
{
  public:
    hkInt16 m_sBoneA;
    hkInt16 m_sBoneB;
    int unk04;
    int unk08;
    int unk0c;
    hkQsTransform m_kAFromBTransform;
};

struct hkOstream
{
    int unk00;
    int unk04;
    int unk08;
    hkOstream* FUN_00cb1600(void* buf, int size);
    void FUN_00cc00e0();
    hkOstream& FUN_00cc01c0(const char*);
    hkOstream& WriteName(const hkStringPtr&);
    hkOstream& WriteFloat(hkReal);
};

struct hkError
{
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual int message(int type, int id, const char* description, const char* file, int line) = 0;
};

#include <math.h>
// Clamps the input to the domain of asin and returns the result, substituting the sign of pi/2 when the magnitude is at least 1.0f.
// @fnv 0x00ce0c40
// pdb: hkMath::asin | hkaLookAtIkSolver.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: r
float ClampAsin(float angle)
{
    float original = angle;
    angle = fabsf(angle);
    if (angle >= 1.0f)
    {
        if (original > 0.0f)
            angle = 1.5707963705062866f;
        else
            angle = -1.5707963705062866f;
    }
    else
    {
        return asinf(original);
    }
    return angle;
}

// @f3 0x00962880 (community match, verified in this file)
namespace f3m_00962880 {
// 0x00962880: hkaSkeletonMapper::checkMapping( const hkaSkeletonMapperData& mapping ) of Havok 5.5.0 (hkaAnimation,
// hkaSkeletonMapper.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), a static member: it warns when a simple mapping
// between two bones whose B bone has its translation locked carries a translation (error over 0.01), and when no bone
// of skeleton B has its translation locked. The two warnings are HK_WARN_ALWAYS, which the release build keeps; their
// file name and line numbers are the library's (".\Mapper\hkaSkeletonMapper.cpp", lines 232 and 253).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and the
// preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the full compile); those declarations are the
// SDK's text with its names. Only the function carries the packet's name.
namespace f3m_00962880 {

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
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
class hkClass;
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
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
template <typename T>
class hkSingleton
{
	public:
		static T* s_instance;
		static __forceinline T& __cdecl getInstance()
		{
			return *s_instance;
		}
		static void __cdecl replaceInstance(T* t)
		{
			if(s_instance)
			{
				s_instance->removeReference();
			}
			s_instance = t;
		}
		static hkBool __cdecl isInitialised()
		{
			return s_instance != 0;
		}
	protected:
		hkSingleton() { }
		hkSingleton(const hkSingleton&);
		hkSingleton& operator= (const hkSingleton&);
};
class hkOstream;
class hkStreamWriter;
class hkString;
template<typename T> class hkArray;
namespace hkOstreamManip
{
typedef hkOstream& (__cdecl *function)(hkOstream&);
}
class hkOstream : public hkReferencedObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_STREAM)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_STREAM); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_STREAM)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_STREAM); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		explicit hkOstream(hkStreamWriter* sr);
		explicit hkOstream(const char* filename);
		hkOstream(void* mem, int memSize, hkBool isString=false);
		explicit hkOstream( hkArray<char>& buf );
		~hkOstream();
		hkBool isOk() const;
		hkOstream& operator<< (const void* p);
		hkOstream& operator<< (hkBool b);
		hkOstream& operator<< (char c);
		hkOstream& operator<< (signed char c);
		hkOstream& operator<< (unsigned char c);
		hkOstream& operator<< (const char* s);
		hkOstream& operator<< (const signed char* s);
		hkOstream& operator<< (const unsigned char* s);
		hkOstream& operator<< (short s);
		hkOstream& operator<< (unsigned short s);
		hkOstream& operator<< (int i);
		hkOstream& operator<< (unsigned int u);
		hkOstream& operator<< (float f);
		hkOstream& operator<< (double d);
		hkOstream& operator<< (hkInt64 i);
		hkOstream& operator<< (hkUint64 u);
		hkOstream& operator<< (const hkString& str);
		int write( const char* buf, int nbytes);
		void printf( const char *fmt, ...);
		void flush();
		hkOstream& operator<< (hkOstreamManip::function f);
		hkStreamWriter* getStreamWriter();
		void setStreamWriter(hkStreamWriter* newWriter);
	protected:
		hkStreamWriter*	m_writer;
};
class hkError : public hkReferencedObject, public hkSingleton<hkError>
{
	public:
		enum Message
		{
			MESSAGE_REPORT,
			MESSAGE_WARNING,
			MESSAGE_ASSERT,
			MESSAGE_ERROR
		};
		virtual int message(Message m, int id, const char* description, const char* file, int line) = 0;
		virtual void setEnabled( int id, hkBool enabled ) = 0;
		virtual hkBool isEnabled( int id ) = 0;
		virtual void enableAll() = 0;
		virtual void sectionBegin(int id, const char* sectionName) {}
		virtual void sectionEnd() {}
};
class hkErrStream : public hkOstream
{
	public:
		hkErrStream( void* buf, int bufSize );
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
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
typedef float hkReal;
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
class hkQsTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQsTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}
class hkaSkeleton;
class hkaSkeletonMapperData
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperData), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct SimpleMapping
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperData::SimpleMapping), HK_MEMORY_CLASS_ANIMATION); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SimpleMapping()
			{
				m_boneA = 0;
				m_boneB = 0;
				m_aFromBTransform.setIdentity();
			}
			hkInt16 m_boneA;
			hkInt16 m_boneB;
			hkQsTransform m_aFromBTransform;
		};
		struct ChainMapping
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperData::ChainMapping), HK_MEMORY_CLASS_ANIMATION); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			ChainMapping()
			{
				m_startBoneA = 0;
				m_endBoneA = 0;
				m_startBoneB = 0;
				m_endBoneB = 0;
				m_startAFromBTransform.setIdentity();
				m_endAFromBTransform.setIdentity();
			}
			hkInt16 m_startBoneA;
			hkInt16 m_endBoneA;
			hkInt16 m_startBoneB;
			hkInt16 m_endBoneB;
			hkQsTransform m_startAFromBTransform;
			hkQsTransform m_endAFromBTransform;
		};
		hkaSkeletonMapperData()
		{
			m_skeletonA = 0;
			m_skeletonB = 0;
			m_keepUnmappedLocal = true;
		}
		hkaSkeletonMapperData( hkFinishLoadedObjectFlag f ) : m_simpleMappings(f), m_chainMappings(f), m_unmappedBones(f) {}
		const hkaSkeleton* m_skeletonA;
		const hkaSkeleton* m_skeletonB;
		hkArray<struct SimpleMapping> m_simpleMappings;
		hkArray<struct ChainMapping> m_chainMappings;
		hkArray<hkInt16> m_unmappedBones;
		hkBool m_keepUnmappedLocal;
};
class hkaPose;
class hkaSkeletonMapper : public hkReferencedObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkaSkeletonMapper( const hkaSkeletonMapperData& mapping );
		virtual ~hkaSkeletonMapper();
		enum ConstraintSource
		{
			NO_CONSTRAINTS,
			REFERENCE_POSE,
			CURRENT_POSE
		};
		void __cdecl mapPose(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpaceInOut, ConstraintSource source ) const;
		void __cdecl mapPose(const hkaPose& poseAIn, hkaPose& poseBInOut, ConstraintSource source ) const;
	public:
		class hkaSkeletonMapperData m_mapping;
	public:
		static void __cdecl hkaSkeletonMapper_checkMapping(const hkaSkeletonMapperData& mapping);
	public:
		hkaSkeletonMapper( hkFinishLoadedObjectFlag f ) : hkReferencedObject(f), m_mapping(f) { }
};
class hkaBone
{
	public:
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaBone), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		char * m_name;
		hkBool m_lockTranslation;
};
class hkaSkeleton
{
	public:
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeleton), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkaSkeleton();
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
	public:
		__forceinline hkaSkeleton( hkFinishLoadedObjectFlag flag ) {}
};
// pdb: hkaSkeletonMapper::checkMapping | hkaSkeletonMapper.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkaSkeletonMapper::hkaSkeletonMapper_checkMapping( const hkaSkeletonMapperData& m_mapping )
{
	for ( int i = 0; i < m_mapping.m_simpleMappings.getSize(); i++ )
	{
		const hkaSkeletonMapperData::SimpleMapping& simpleMapping = m_mapping.m_simpleMappings[i];
		const hkInt16 boneIdA = simpleMapping.m_boneA;
		const hkInt16 boneIdB = simpleMapping.m_boneB;
		const hkaBone* boneA = m_mapping.m_skeletonA->m_bones[boneIdA];
		const hkaBone* boneB = m_mapping.m_skeletonB->m_bones[boneIdB];
		if ( boneB->m_lockTranslation )
		{
			const hkVector4& trans = simpleMapping.m_aFromBTransform.getTranslation();
			const hkReal err = trans.length3();
			if ( err > 0.01f )
			{
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Bones A:" << boneA->m_name << " and B:" << boneB->m_name << " are not fully aligned (error :" << err << ")."; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabbaefbf, assertBuf, ".\\Mapper\\hkaSkeletonMapper.cpp", 232); } else;
			}
		}
	}
	hkBool atLeastOne = false;
	for ( int i = 0; i < m_mapping.m_skeletonB->m_numBones; i++ )
	{
		const hkaBone* bone = m_mapping.m_skeletonB->m_bones[i];
		if ( bone->m_lockTranslation )
		{
			atLeastOne = true;
			break;
		}
	}
	if ( !atLeastOne )
	{
		if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "None of the bones in skeleton have translations locked - did you forget to lock translations ?."; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba77a5, assertBuf, ".\\Mapper\\hkaSkeletonMapper.cpp", 253); } else;
	}
}

}  // namespace f3m_00962880
}   // namespace f3m_00962880
