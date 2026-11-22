// src/f3staging/f3blk_00920000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00924630 (community match, verified in this file)
#include <math.h>
namespace f3m_00924630 {

struct F3M_00924630
{
    float x;
    float y;
    float z;
    float w;

    void FUN_00924630(const float* v);
};

void F3M_00924630::FUN_00924630(const float* v)
{
    __declspec(align(16)) float w[4];
    int i0 = 0;
    int i1 = i0 + 1;
    int i2 = i0 + 2;

    float a = (float)fabs(v[0]);
    float b = (float)fabs(v[1]);
    float c = (float)fabs(v[2]);

    if (b < a)
    {
        a = b;
        i1 = 0;
        i0 = i2 - 1;
    }
    if (c < a)
    {
        i2 = i0;
    }

    float zz = 0.0f;
    w[2] = zz;
    w[1] = zz;
    w[0] = zz;
    w[i1] = v[i2];
    w[i2] = -v[i1];

    float sq = w[1] * w[1] + w[0] * w[0] + w[2] * w[2];
    float s;
    if (sq != zz)
        s = 1.0f / (float)sqrt(sq);
    else
        s = zz;

    w[0] *= s;
    w[1] *= s;
    w[2] *= s;
    x = w[0];
    y = w[1];
    z = w[2];
    this->w = zz;
}
}   // namespace f3m_00924630

// @f3 0x0092a8f0 (community match, verified in this file)
namespace f3m_0092a8f0 {
namespace c_0092a8f0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
    void Set(float ax, float ay, float az, float aw = 0.0f) { x = ax; y = ay; z = az; w = aw; }
};
struct A { virtual void a0(); int unk04; };
struct B { virtual void b0(); };
struct C { virtual void c0(); };
struct Base : A, B, C {
    Base(void* info);
    int unk10[12];
};
struct Derived : Base {
    Derived(void* info);
    virtual void a0();
    virtual void b0();
    virtual void c0();
    Vec4 unk40;
    int unk50[0x1c];
    int unkc0;
};
// pdb: ahkpCharacterProxy::ahkpCharacterProxy | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
Derived::Derived(void* info) : Base(info)
{
    unkc0 = 0;
    Vec4 t;
    t.Set(0.0f, 0.0f, 1.0f);
    unk40 = t;
}
}
}   // namespace f3m_0092a8f0

// @f3 0x0092ded0 (community match, verified in this file)
#include <math.h>
extern float DAT_00e3723c;
namespace f3m_0092ded0 {
struct S {float value; S(float f):value(f){}};
struct U {float x,y,z,w;};
struct __declspec(align(16)) V { float x,y,z,w;
 void hkVector4_setTransformedPos(void*,const V*);
 void FUN_008d2a80(const void*,const V*);
 void copy(const U&a){x=a.x;y=a.y;z=a.z;w=a.w;}
 void sub(const V&a,const V&b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
 void scale(const V&a,const S& s){float f=s.value;x=f*a.x;y=f*a.y;z=f*a.z;w=f*a.w;}
 void addscale(const V&a,float f){x+=f*a.x;y+=f*a.y;z+=f*a.z;w+=f*a.w;}
 // Fake match: double coordinate temporaries control x87 preload order;
 // the unused argument preserves the recovered helper's call shape.
 float dot(const V&a)const{double xx=x,yy=y,zz=z;return xx*xx+yy*yy+zz*zz;}
 void neg(){x=-x;y=-y;z=-z;w=-w;}
};
struct __declspec(align(16)) M { V a,b,c;
 void hkMatrix3_setCrossSkewSymmetric(const V*);
 void FUN_0096ce80(const M*,const M*);
 void FUN_0096cca0(const M*);
 int FUN_0096c8f0(float);
 void diagonal(float f){a.y=0.0f;a.z=0.0f;a.w=0.0f;b.x=0.0f;b.z=0.0f;b.w=0.0f;c.x=0.0f;c.y=0.0f;c.w=0.0f;a.x=f;b.y=f;c.z=f;}
};
struct Motion {
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual void v8();
 virtual void v9();
 virtual void inertia(M*);
 virtual void v11();
 virtual void v12();
 virtual void v13();
 virtual void v14();
 virtual void v15();
 virtual void linear(const V*);
 virtual void angular(const V*);
 virtual void v18();
 virtual void impulse(const V*,const V*);
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 int unka0;
 int unka4;
 int unka8;
 int unkac;
 int unkb0;
 int unkb4;
 int unkb8;
 int unkbc;
 int unkc0;
 int unkc4;
 int unkc8;
 float invMass; U linearVelocity,angularVelocity; float FUN_008f8410();
};
struct Body {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 int unka0;
 int unka4;
 int unka8;
 int unkac;
 int unkb0;
 int unkb4;
 int unkb8;
 int unkbc;
 int unkc0;
 int unkc4;
 int unkc8;
 int unkcc;
 Motion motion; Motion* hkpRigidBody_getStoredDynamicMotion(); void FUN_0090b500(); void FUN_00917120(const V*,V*);
};
struct Step {float start,end,dt,invDt;};
struct Action {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 Body* body; int unk1c; V mouse,grab; float damping,elasticity,maxForce,tau; int unk50; void (__cdecl **callbacks)(Action*,const Step&,const V&); int count; void hkpMouseSpringAction_applyAction(const Step&);
};
// pdb: hkpMouseSpringAction::applyAction | hkpMouseSpringAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Action::hkpMouseSpringAction_applyAction(const Step& step){
 V impulse,ang,lin,spring,world,r,delta;
 M K,cross,temp,inertia,temp2;
 float scalar,len,maxImpulse;
 Body* rb=body;
 world.hkVector4_setTransformedPos((char*)rb+0xe0,&mouse);
 delta.sub(world,grab);
 Motion* motion=rb->hkpRigidBody_getStoredDynamicMotion()?rb->hkpRigidBody_getStoredDynamicMotion():&rb->motion;
 scalar=motion->invMass;
 r.sub(world,*(V*)((char*)rb+0x130));
 cross.hkMatrix3_setCrossSkewSymmetric(&r);
 motion->inertia(&inertia);
 K.diagonal(scalar);
 temp.FUN_0096ce80(&cross,&inertia);
 temp2.FUN_0096ce80(&temp,&cross);
 K.FUN_0096cca0(&temp2);
 if(K.FUN_0096c8f0(DAT_00e3723c)==0){
 lin.copy(rb->motion.linearVelocity); scalar=tau; lin.scale(lin,scalar);
 rb->FUN_0090b500(); rb->motion.linear(&lin);
 ang.copy(rb->motion.angularVelocity); scalar=tau; ang.scale(ang,scalar);
 rb->FUN_0090b500(); rb->motion.angular(&ang);
 rb->FUN_00917120(&world,&r);
 scalar=elasticity*step.invDt; spring.scale(delta,scalar);
 scalar=damping; spring.addscale(r,scalar);
 impulse.FUN_008d2a80(&K,&spring); impulse.neg();
 len=impulse.dot(impulse);
 scalar=motion->FUN_008f8410(); maxImpulse=step.dt*scalar*maxForce;
 if(len>maxImpulse*maxImpulse){len=(float)sqrt(len);len=1.0f/len;len=len*maxImpulse;impulse.scale(impulse,len);}
 rb->FUN_0090b500(); rb->motion.impulse(&impulse,&world);
 for(int i=0;i<count;++i)callbacks[i](this,step,impulse);
 }
}
}   // namespace f3m_0092ded0

// @f3 0x00936710 (community match, verified in this file)
namespace f3m_00936710 {
// getTypeValueFromEnumName (static, hkCompat_hk400b1_hk400b2.cpp) written from the Havok 5.5.0 SDK (hkCompat.lib,
// hkCompat_hk400b1_hk400b2.obj, hybrid debug records lines 258-263: one call chain on line 260, HK_ASSERT on line 261
// (compiled out without HK_DEBUG), return on line 262). Accessor classes as declared in
// hk550\Source\Common\Base\Reflection\hkClassMemberAccessor.h (hkClassAccessor::member body verbatim). The pack names the
// function ?FUN_00936710@@YAFPAXPBD@Z, so the accessor arrives as void*. Caller: setBallSocketAtomData shape (same object).
namespace f3m_00936710 {
typedef short hkInt16;
enum hkResult { HK_SUCCESS = 0, HK_FAILURE = 1 };

class hkClass;
class hkClassEnum
{
public:
    hkResult getValueOfName(const char* name, int* val) const;
};

class hkClassMember
{
public:
    const hkClassEnum& getEnumClass() const;
};

struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};

class hkClassMemberAccessor
{
public:
    hkClassMemberAccessor(const hkVariant& v, const char* memberName);
    const hkClassMember& getClassMember() const;
    hkInt16& asInt16(int index = 0) const;
private:
    void* m_address;
    const hkClassMember* m_member;
};

class hkClassAccessor
{
public:
    inline hkClassMemberAccessor member(const char* memberName) const;
private:
    hkVariant m_variant;
};

hkClassMemberAccessor hkClassAccessor::member(const char* memberName) const
{
    return hkClassMemberAccessor(m_variant, memberName);
}
}

static short FUN_00936710(void* memAcc, const char* typeName)
{
    int ret;
    static_cast<const f3m_00936710::hkClassAccessor*>(memAcc)->member("type").getClassMember().getEnumClass().getValueOfName(typeName, &ret);
    return static_cast<f3m_00936710::hkInt16>(ret);
}

namespace f3m_00936710 {
void setBallSocketAtomData(hkClassAccessor& ballSocket)
{
    static hkInt16 TYPE_BALL_SOCKET = -1;
    if (TYPE_BALL_SOCKET == -1)
    {
        TYPE_BALL_SOCKET = FUN_00936710(&ballSocket, "TYPE_BALL_SOCKET");
    }
    ballSocket.member("type").asInt16() = TYPE_BALL_SOCKET;
}
}
}   // namespace f3m_00936710

// @f3 0x00929670 (community match, verified in this file)
namespace f3m_00929670 {
// FUN_00929670 = Havok 5.5.0 hkpWorldOperationUtil::setRigidBodyMotionType (hkpDynamics.lib, hkpWorldOperationUtil.obj).
// Written from the SDK headers and the library objects' debug records (the .cpp is not shipped); reduced from
// sdk_final.cpp with hktrim.py. Declarations and inline bodies are SDK text in reduced form. See note.txt.
namespace f3m_00929670 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

class hkHalf
{
    private:
	    hkInt16 m_value;
};

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline TYPE val() const
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
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
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
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
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
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}

namespace hkSmallArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
}

template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		                class MustEndWithSemiColon;
		typedef T* iterator;
		typedef const T* const_iterator;
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
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
};

class hkVector4;
typedef const hkVector4& hkVector4Parameter;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_vec;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
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
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};

enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};

class hkpCollisionDispatcher;

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

class hkAabb;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;

class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			                class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				                class MustEndWithSemiColon;
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				                class MustEndWithSemiColon;
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
};

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		hkUint32 m_id;
};

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	protected:
		enum { OFFSET_INVALID = 127 };
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};

struct hkAabbUint32;

class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				                class MustEndWithSemiColon;
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};

struct hkpAgentNnEntry;

class hkpLinkedCollidable: public hkpCollidable
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		struct CollisionEntry
		{
			                class MustEndWithSemiColon;
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};

class hkMultiThreadCheck
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};

class hkpWorld;
class hkpPhantom;
class hkpRigidBody;

namespace hkWorldOperation
{
	enum Result
	{
		POSTPONED,
		DONE
	};
}

class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline hkpWorld* getWorld() const;
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
		void addReference();
		void removeReference();
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		virtual class hkMotionState* getMotionState() = 0;
		inline virtual ~hkpWorldObject();
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
};

inline hkpWorld* hkpWorldObject::getWorld() const
{
	return m_world;
}

inline hkpLinkedCollidable* hkpWorldObject::getLinkedCollidable()
{
	return &m_collidable;
}

class hkpMaterial
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
};

struct hkpSolverInfo
{
	                class MustEndWithSemiColon;
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		                class MustEndWithSemiColon;
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};

struct hkpConstraintInfo
{
	                class MustEndWithSemiColon;
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
};

class hkpEntity;

class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		~hkpConstraintInstance();
	public:
		virtual void entityAddedCallback(hkpEntity* entity);
		virtual void entityRemovedCallback(hkpEntity* entity);
		virtual void entityDeletedCallback( hkpEntity* entity );
		virtual InstanceType getType() const { return TYPE_NORMAL; }
	protected:
		friend class hkpSimpleContactConstraintData;
		friend class hkpSimulationIsland;
		class hkpConstraintOwner* m_owner;
		class hkpConstraintData*  m_data;
		struct hkpModifierConstraintAtom* m_constraintModifiers;
		class hkpEntity* m_entities[2];
	public:
		hkEnum<ConstraintPriority,hkUint8> m_priority;
	protected:
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
};

class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
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

class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	                class MustEndWithSemiColon;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline hkMotionState* getMotionState();
	virtual void setPosition(const hkVector4& position);
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	virtual void setTransform(const hkTransform& transform);
	virtual void setLinearVelocity(const hkVector4& newVel);
	virtual void setAngularVelocity(const hkVector4& newVel);
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
};

hkMotionState* hkpMotion::getMotionState()
{
	return &m_motionState;
}

class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
};

class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
};

class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;

class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		virtual ~hkpEntity();
		inline hkBool isFixed() const;
		void calcStatistics( hkStatisticsCollector* collector) const;
	public:
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				                class MustEndWithSemiColon;
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};

inline hkpSimulationIsland* hkpEntity::getSimulationIsland() const
{
	return m_simulationIsland;
}

inline hkBool hkpEntity::isFixed() const
{
	return m_motion.m_type == hkpMotion::MOTION_FIXED;
}

class hkStepInfo
{
	public:
		                class MustEndWithSemiColon;
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};

namespace hkSweptTransformUtil
{
		void __cdecl freezeMotionState( hkTime time, hkMotionState& motionState );
}

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

class hkpWorldCinfo : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum SolverType
		{
			SOLVER_TYPE_INVALID,
			SOLVER_TYPE_2ITERS_SOFT,
			SOLVER_TYPE_2ITERS_MEDIUM,
			SOLVER_TYPE_2ITERS_HARD,
			SOLVER_TYPE_4ITERS_SOFT,
			SOLVER_TYPE_4ITERS_MEDIUM,
			SOLVER_TYPE_4ITERS_HARD,
			SOLVER_TYPE_8ITERS_SOFT,
			SOLVER_TYPE_8ITERS_MEDIUM,
			SOLVER_TYPE_8ITERS_HARD,
			SOLVER_TYPE_MAX_ID
		};
		enum SimulationType
		{
			SIMULATION_TYPE_INVALID,
			SIMULATION_TYPE_DISCRETE,
			SIMULATION_TYPE_CONTINUOUS,
			SIMULATION_TYPE_MULTITHREADED,
		};
		enum ContactPointGeneration
		{
			CONTACT_POINT_ACCEPT_ALWAYS,
			CONTACT_POINT_REJECT_DUBIOUS,
			CONTACT_POINT_REJECT_MANY,
		};
		enum BroadPhaseBorderBehaviour
		{
			BROADPHASE_BORDER_ASSERT,
			BROADPHASE_BORDER_FIX_ENTITY,
			BROADPHASE_BORDER_REMOVE_ENTITY,
			BROADPHASE_BORDER_DO_NOTHING,
		};
	public:
		hkVector4 m_gravity;
		hkInt32 m_broadPhaseQuerySize;
		hkReal m_contactRestingVelocity;
		hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
		class hkAabb m_broadPhaseWorldAabb;
		hkReal m_collisionTolerance;
		class hkpCollisionFilter* m_collisionFilter;
		class hkpConvexListFilter* m_convexListFilter;
		hkReal m_expectedMaxLinearVelocity;
		int m_sizeOfToiEventQueue;
		hkReal m_expectedMinPsiDeltaTime;
		class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
		hkInt32 m_broadPhaseNumMarkers;
		hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
		hkReal m_solverTau;
		hkReal m_solverDamp;
		hkInt32 m_solverIterations;
		hkInt32 m_solverMicrosteps;
		hkBool m_forceCoherentConstraintOrderingInSolver;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_enableDeprecatedWelding;
		hkReal m_iterativeLinearCastEarlyOutDistance;
		hkInt32 m_iterativeLinearCastMaxIterations;
		hkReal m_highFrequencyDeactivationPeriod;
		hkReal m_lowFrequencyDeactivationPeriod;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
		hkUint8 m_deactivationIntegrateCounter;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		int m_maxSectorsPerCollideTask;
		hkBool m_processToisMultithreaded;
		int m_maxEntriesPerToiCollideTask;
		hkBool m_enableDeactivation;
		hkEnum<SimulationType, hkInt8> m_simulationType;
		hkBool m_enableSimulationIslands;
		hkUint32 m_minDesiredIslandSize;
		hkBool m_processActionsInSingleThread;
		hkReal m_frameMarkerPsiSnap;
		virtual ~hkpWorldCinfo() {}
};

struct hkpProcessCollisionInput;
class hkpTypedBroadPhaseDispatcher;
class hkpBroadPhase;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpActionListener;
class hkpConstraintListener;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;

enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};

enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};

enum hkpUpdateCollectionFilterMode
{
	HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS,
	HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS
};

struct hkpWorldDynamicsStepInfo
{
	                class MustEndWithSemiColon;
	hkStepInfo   m_stepInfo;
	hkpSolverInfo m_solverInfo;
};

enum hkpStepResult
{
	HK_STEP_RESULT_SUCCESS,
	HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};

class hkpWorld : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void updateCollisionFilterOnEntity( hkpEntity* entity,
			                                hkpUpdateCollisionFilterOnEntityMode updateMode,
											hkpUpdateCollectionFilterMode updateShapeCollectionFilter);
		enum ReintegrationRecollideMode
		{
			RR_MODE_REINTEGRATE = 1,
			RR_MODE_RECOLLIDE_BROADPHASE = 2,
			RR_MODE_RECOLLIDE_NARROWPHASE = 4,
			RR_MODE_ALL = 7
		};
		void calcStatistics( hkStatisticsCollector* collector ) const;
		enum MtAccessChecking
		{
			MT_ACCESS_CHECKING_ENABLED = 0,
			MT_ACCESS_CHECKING_DISABLED
		};
		~hkpWorld();
	public:
		hkpSimulation* m_simulation;
		hkVector4			m_gravity;
        hkpSimulationIsland* m_fixedIsland;
			hkpRigidBody*	m_fixedRigidBody;
        hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
        hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
        hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
        hkpWorldMaintenanceMgr* m_maintenanceMgr;
        hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
        hkpBroadPhase* m_broadPhase;
        hkpTypedBroadPhaseDispatcher*    m_broadPhaseDispatcher;
        hkpPhantomBroadPhaseListener*    m_phantomBroadPhaseListener;
        hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
        hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
        hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
        hkpProcessCollisionInput* m_collisionInput;
            hkpCollisionFilter*       m_collisionFilter;
            hkpCollisionDispatcher*   m_collisionDispatcher;
            hkpConvexListFilter*     m_convexListFilter;
        hkpWorldOperationQueue* m_pendingOperations;
			int m_pendingOperationsCount;
			int m_criticalOperationsLockCount;
			int m_criticalOperationsLockCountForPhantoms;
			hkBool m_blockExecutingPendingOperations;
			hkBool m_criticalOperationsAllowed;
            hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
			int m_pendingOperationQueueCount;
        mutable class hkMultiThreadCheck m_multiThreadCheck;
		hkBool m_processActionsInSingleThread;
		hkUint32 m_minDesiredIslandSize;
        class hkCriticalSection* m_modifyConstraintCriticalSection;
        class hkCriticalSection* m_worldLock;
        class hkCriticalSection* m_islandDirtyListCriticalSection;
		struct PropertyLock
		{
			                class MustEndWithSemiColon;
			hkUint32 m_key;
			mutable hkMultiThreadCheck m_multiThreadCheck;
		};
        class hkCriticalSection* m_propertyMasterLock;
		hkBool m_wantSimulationIslands;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_wantDeactivation;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		hkBool m_processToisMultithreaded;
		int m_maxSectorsPerCollideTask;
		int m_maxEntriesPerToiCollideTask;
        hkEnum<hkpWorldCinfo::SimulationType,hkInt32>  m_simulationType;
		static hkBool m_forceMultithreadedSimulation;
		class IgnoreForceMultithreadedSimulation
		{
			public:
				                class MustEndWithSemiColon;
			public:
				hkBool m_originalForceMultithreadedSimulationValue;
		};
	protected:
		hkUint32 m_lastEntityUid;
	public:
		friend class hkpWorldOperationUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpSimulation;
		friend class hkHalfstepSimulation;
		friend class hkpContinuousSimulation;
		friend class hkpMultiThreadedSimulation;
		friend class hkpSimpleConstraintContactMgr;
		hkArray<hkpPhantom*> m_phantoms;
        hkArray<hkpActionListener*>              m_actionListeners;
        hkArray<hkpEntityListener*>              m_entityListeners;
        hkArray<hkpPhantomListener*>             m_phantomListeners;
        hkArray<hkpConstraintListener*>          m_constraintListeners;
        hkArray<hkpWorldDeletionListener*>       m_worldDeletionListeners;
        hkArray<hkpIslandActivationListener*>    m_islandActivationListeners;
        hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
        hkArray<hkpWorldPostIntegrateListener*>  m_worldPostIntegrateListeners;
        hkArray<hkpWorldPostCollideListener*>    m_worldPostCollideListeners;
        hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
        hkArray<hkpIslandPostCollideListener*>   m_islandPostCollideListeners;
        hkArray<hkpCollisionListener*>           m_collisionListeners;
        hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
        class hkpBroadPhaseBorder*               m_broadPhaseBorder;
	public:
		struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
		hkVector4 m_broadPhaseExtents[2];
		int			m_broadPhaseNumMarkers;
		int			m_sizeOfToiEventQueue;
		hkInt32		m_broadPhaseQuerySize;
		hkInt32		m_broadPhaseUpdateSize;
        hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
	public:
		__forceinline void	lockCriticalOperations();
		__forceinline void	unlockCriticalOperations();
		__forceinline void	blockExecutingPendingOperations(hkBool block);
		__forceinline void	attemptToExecutePendingOperations();
	private:
		                void	internal_executePendingOperations();
	public:
		__forceinline void	allowCriticalOperations(hkBool allow);
};

void hkpWorld::lockCriticalOperations()
{
	m_criticalOperationsLockCount++;
}

void hkpWorld::unlockCriticalOperations()
{
	m_criticalOperationsLockCount--;
}

void hkpWorld::blockExecutingPendingOperations(hkBool block)
{
	m_blockExecutingPendingOperations = block;
}

void hkpWorld::attemptToExecutePendingOperations()
{
	if ( !m_criticalOperationsLockCount && !m_blockExecutingPendingOperations )
	{
		if ( m_pendingOperationsCount )
	    {
		    internal_executePendingOperations();
	    }
	}
}

void hkpWorld::allowCriticalOperations(hkBool allow)
{
	m_criticalOperationsAllowed = allow;
}

struct hkpAgentNnTrack;

class hkpWorldOperationUtil
{
	public:
		enum FireCallbacks
		{
			DO_NOT_FIRE_CALLBACKS_AND_SUPPRESS_EXECUTION_OF_PENDING_OPERATIONS,
			DO_FIRE_CALLBACKS
		};
	public:
		static void __cdecl addEntitySI ( hkpWorld* world, hkpEntity* entity, hkpEntityActivation initialActivationState );
		static void __cdecl removeEntitySI ( hkpWorld* world, hkpEntity* entity );
		static hkpConstraintInstance*
					__cdecl addConstraintImmediately   ( hkpWorld* world, hkpConstraintInstance* constraint, FireCallbacks fireCallbacks = DO_FIRE_CALLBACKS );
		static __forceinline void
				__cdecl mergeIslandsIfNeeded(                 hkpEntity* entityA, hkpEntity* entityB);
		static void __cdecl mergeIslands    ( hkpWorld* world, hkpEntity* entityA, hkpEntity* entityB);
		static void __cdecl removeAttachedActionsFromFixedIsland  ( hkpWorld* world, hkpEntity* entity, hkArray<hkpAction*>& actionsToBeMoved );
		static void __cdecl removeAttachedActionsFromDynamicIsland( hkpWorld* world, hkpEntity* entity, hkArray<hkpAction*>& actionsToBeMoved );
		static void __cdecl addActionsToEntitysIsland             ( hkpWorld* world, hkpEntity* entity, hkArray<hkpAction*>& actionsToBeMoved );
		static void __cdecl FUN_00929670( hkpRigidBody* body, hkpMotion::MotionType newState, hkpEntityActivation initialActivationState, hkpUpdateCollisionFilterOnEntityMode queryBroadPhaseForNewPairs);
	private:
		static void __cdecl replaceMotionObject(hkpRigidBody* body, hkpMotion::MotionType newState, hkBool newStateNeedsInertia, hkBool oldStateNeedsInertia, hkpWorld* world );
		static void __cdecl removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus( hkpAgentNnTrack& trackToScan, hkpEntity* entity, hkpAgentNnTrack& agentsRemoved, hkpMotion::MotionType newMotionType);
		static void __cdecl removeAttachedConstraints( hkpEntity* entity, hkArray<hkpConstraintInstance*>& constraintsToBeMoved );
};

class hkpConstraintOwner: public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
	public:
		virtual void addConstraintToCriticalLockedIsland(      hkpConstraintInstance* constraint ){}
		virtual void removeConstraintFromCriticalLockedIsland( hkpConstraintInstance* constraint ){}
		virtual void addCallbackRequest( hkpConstraintInstance* constraint, int request ){}
		virtual void checkAccessRw() {}
	public:
		hkpConstraintInfo m_constraintInfo;
};

struct hkpProcessCollisionOutput;

struct hkpAgentNnSector
{
	                class MustEndWithSemiColon;
	hkUint8 m_data[ 512 ];
};

struct hkpAgentNnTrack
{
	hkpAgentNnTrack( )
	{
		m_bytesUsedInLastSector = 512;
	}
	                class MustEndWithSemiColon;
	hkUint32	m_bytesUsedInLastSector;
	hkInplaceArray<hkpAgentNnSector*,1> m_sectors;
};

class hkpSimulationIsland : public hkpConstraintOwner
{
	public:
		                class MustEndWithSemiColon;
		void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpSimulation;
		friend class hkpContinuousSimulation;
		~hkpSimulationIsland();
		virtual void addConstraintToCriticalLockedIsland(      hkpConstraintInstance* constraint );
		virtual void removeConstraintFromCriticalLockedIsland( hkpConstraintInstance* constraint );
		virtual void addCallbackRequest( hkpConstraintInstance* constraint, int request );
	public:
		hkpWorld*	m_world;
		int m_numConstraints;
		hkObjectIndex m_storageIndex;
		hkObjectIndex m_dirtyListIndex;
		hkUchar m_splitCheckFrameCounter;
		bool m_splitCheckRequested:2;
		bool m_sparseEnabled:2;
		bool m_actionListCleanupNeeded:2;
		bool m_allowIslandLocking:2;
		bool m_isInActiveIslandsArray:2;
		bool m_activeMark:2;
		bool m_inIntegrateJob:2;
	protected:
		mutable hkMultiThreadCheck m_multiThreadCheck;
	public:
		hkReal m_timeSinceLastHighFrequencyCheck;
		hkReal m_timeSinceLastLowFrequencyCheck;
		hkArray<hkpAction*> m_actions;
		hkTime m_timeOfDeactivation;
			hkInplaceArray<hkpEntity*,1> m_entities;
		hkpAgentNnTrack m_agentTrack;
};

void hkpWorldOperationUtil::mergeIslandsIfNeeded( hkpEntity* entityA, hkpEntity* entityB )
{
	if ( !entityA->isFixed() && !entityB->isFixed() &&
	     entityA->getSimulationIsland() != entityB->getSimulationIsland() )
	{
		hkpWorldOperationUtil::mergeIslands(entityA->getWorld(), entityA, entityB);
	}
}

class hkpWorldCallbackUtil
{
	public:
		static void __cdecl fireInactiveEntityMoved( hkpWorld* world, hkpEntity* entity);
};

class hkpSimulation: public hkReferencedObject
{
	public:
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		~hkpSimulation();
		virtual hkpStepResult stepDeltaTime( hkReal physicsDeltaTime );
		virtual hkpStepResult integrate( hkReal physicsDeltaTime );
		virtual hkpStepResult collide();
		virtual hkpStepResult advanceTime();
		enum FindContacts
		{
			FIND_CONTACTS_DEFAULT = 0,
			FIND_CONTACTS_EXTRA
		};
		virtual void collideEntitiesDiscrete( hkpEntity** entities, int numEntities, hkpWorld* world, const hkStepInfo& stepInfo, FindContacts findExtraContacts  );
		static void collideEntitiesBroadPhaseDiscrete( hkpEntity** entities, int numEntities, hkpWorld* world );
		virtual void resetCollisionInformationForEntities( hkpEntity** entities, int numEntities, hkpWorld* world, hkBool skipReinitializationOfAgents = false );
		virtual void assertThereIsNoCollisionInformationForEntities( hkpEntity** entities, int numEntities, hkpWorld* world ) {}
		virtual void removeCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
		virtual void assertThereIsNoCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationQueue;
		virtual void reintegrateAndRecollideEntities( hkpEntity** entityBatch, int numEntities, hkpWorld* world, int reintegrateRecollideMode );
	protected:
		virtual void collideInternal( const hkStepInfo& stepInfoIn );
		typedef void (hkpSimulation::*AgentEntryProcessFunction)(hkpAgentNnEntry*, const hkpProcessCollisionInput&, hkpProcessCollisionOutput&);
	public:
		virtual void warpTime( hkReal deltaTime ) {}
	public:
		hkUint32 m_determinismCheckFrameCounter;
	protected:
		class hkpWorld* m_world;
		enum LastProcessingStep
		{
			INTEGRATE,
			COLLIDE
		};
        hkEnum<LastProcessingStep,hkUint8> m_lastProcessingStep;
		hkTime m_currentTime;
		hkTime m_currentPsiTime;
		hkReal m_physicsDeltaTime;
		hkTime m_simulateUntilTime;
		hkReal m_frameMarkerPsiSnap;
        hkUint32 m_previousStepResult;
};

class hkpRigidBody : public hkpEntity
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpRigidBody();
		inline hkpMotion::MotionType getMotionType() const;
		hkWorldOperation::Result setShape(const hkpShape* shape);
		virtual hkpRigidBody* clone() const;
	public:
		inline hkpMotion* getRigidMotion() const;
	protected:
		virtual hkMotionState* getMotionState();
};

inline hkpMotion* hkpRigidBody::getRigidMotion() const
{
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}

inline enum hkpMotion::MotionType hkpRigidBody::getMotionType() const
{
	return getRigidMotion()->getType();
}

extern "C"
{
	void __cdecl hkAgentNnMachine_AppendTrack( hkpAgentNnTrack& track, hkpAgentNnTrack& appendee);
}

// pdb: hkpWorldOperationUtil::setRigidBodyMotionType | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: body, newState, initialActivationState, collisionFilterUpdateMode
void hkpWorldOperationUtil::FUN_00929670( hkpRigidBody* body, hkpMotion::MotionType newState, hkpEntityActivation initialActivationState, hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode)
{
	hkpMotion::MotionType oldState = body->getMotionType();
	if ( oldState == newState )
	{
		return;
	}
	bool newStateNeedsInertia = newState != hkpMotion::MOTION_FIXED && newState != hkpMotion::MOTION_KEYFRAMED;
	bool oldStateNeedsInertia = oldState != hkpMotion::MOTION_FIXED && oldState != hkpMotion::MOTION_KEYFRAMED;
	if ( newStateNeedsInertia && !oldStateNeedsInertia && body->m_motion.m_savedMotion == 0 )
	{
		return;
	}
	body->addReference();
	hkpWorld* world = body->getWorld();
	bool changeBetweenFixedAndNonFixed = (oldState == hkpMotion::MOTION_FIXED) != (newState == hkpMotion::MOTION_FIXED);
	if ( world && changeBetweenFixedAndNonFixed )
	{
		hkInplaceArray<hkpConstraintInstance*, 16> constraintsToBeMoved;
		hkInplaceArray<hkpAction*, 16> actionsToBeMoved;
		hkpAgentNnTrack agentsToBeMoved;
		world->blockExecutingPendingOperations( true );
		world->allowCriticalOperations( false );
		removeAttachedConstraints( body, constraintsToBeMoved );
		if ( newState != hkpMotion::MOTION_FIXED )
		{
			removeAttachedActionsFromFixedIsland( world, body, actionsToBeMoved );
		}
		else
		{
			removeAttachedActionsFromDynamicIsland( world, body, actionsToBeMoved );
		}
		removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus( body->getSimulationIsland()->m_agentTrack, body, agentsToBeMoved, newState );
		if ( oldState != hkpMotion::MOTION_FIXED && body->m_simulationIsland->m_entities.getSize() > 2 )
		{
			body->m_simulationIsland->m_splitCheckRequested = true;
		}
		removeEntitySI( world, body );
		replaceMotionObject( body, newState, newStateNeedsInertia, oldStateNeedsInertia, world );
		addEntitySI( world, body, initialActivationState );
		addActionsToEntitysIsland( world, body, actionsToBeMoved );
		world->allowCriticalOperations( true );
		for ( int i = 0; i < constraintsToBeMoved.getSize(); i++ )
		{
			hkpConstraintInstance* constraint = constraintsToBeMoved[i];
			addConstraintImmediately( world, constraint, DO_NOT_FIRE_CALLBACKS_AND_SUPPRESS_EXECUTION_OF_PENDING_OPERATIONS );
			constraint->removeReference();
		}
		if ( newState != hkpMotion::MOTION_FIXED )
		{
			hkArray<hkpLinkedCollidable::CollisionEntry>& collisionEntries = body->getLinkedCollidable()->m_collisionEntries;
			for ( int i = 0; i < collisionEntries.getSize(); i++ )
			{
				hkpRigidBody* otherBody = static_cast<hkpRigidBody*>( collisionEntries[i].m_partner->getOwner() );
				mergeIslandsIfNeeded( body, otherBody );
			}
		}
		hkAgentNnMachine_AppendTrack( body->getSimulationIsland()->m_agentTrack, agentsToBeMoved );
		if ( newState == hkpMotion::MOTION_FIXED )
		{
			hkMotionState* ms = body->getRigidMotion()->getMotionState();
			hkSweptTransformUtil::freezeMotionState( world->m_dynamicsStepInfo.m_stepInfo.m_startTime, *ms );
			world->lockCriticalOperations();
			world->m_simulation->resetCollisionInformationForEntities( (hkpEntity**)&body, 1, world );
			hkpSimulation::collideEntitiesBroadPhaseDiscrete( (hkpEntity**)&body, 1, world );
			hkpWorldCallbackUtil::fireInactiveEntityMoved( body->m_world, body );
			world->unlockCriticalOperations();
		}
		world->updateCollisionFilterOnEntity( body, collisionFilterUpdateMode, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS );
		world->blockExecutingPendingOperations( false );
		world->attemptToExecutePendingOperations();
	}
	else
	{
		replaceMotionObject( body, newState, newStateNeedsInertia, oldStateNeedsInertia, world );
		if ( world )
		{
			world->updateCollisionFilterOnEntity( body, collisionFilterUpdateMode, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS );
		}
	}
	body->removeReference();
}

}
}   // namespace f3m_00929670
