#include <new>
// src/f3staging/f3iso_00a83750_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a83750 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a83750 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace f3m_00a83310 {
struct Text83310 { char* data; int length; int capacity; };
struct Entry83310 { int key; int offset; };
struct Entries83310 { Entry83310* data; int size; unsigned int capacity; };
struct Buffer83310 {
    Text83310* text;
    int __thiscall FUN_00a84d20(int length, int alignment);
};
void __cdecl FUN_009234e0(void* dst, const void* src, unsigned int size);
void __cdecl FUN_00901f10(Entries83310* entries, int stride);
static __declspec(noinline) int FUN_00a83310(Entries83310* entries, int key, Text83310* str, Buffer83310* buffer)
{
    int length = str->length;
    if (length - 1 == 1 && str->data[0] == 0)
        return 1;
    int offset = buffer->FUN_00a84d20(length, 16);
    Text83310* output = buffer->text;
    char* source = str->data;
    FUN_009234e0(output->data + offset, source, length);
    if (entries->size == (entries->capacity & 0x3fffffff))
        FUN_00901f10(entries, 8);
    Entry83310* data = entries->data;
    int index = entries->size;
    data[index].key = key;
    data[index].offset = offset;
    ++entries->size;
    buffer->text->length = (buffer->text->length + length + 15) & ~15;
    return 0;
}
}
namespace f3m_00a82b80 {
struct Token34 {
    virtual void Destroy(int);
    int unk04;
    int type;
};
struct Parser34 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int Next(Token34** out, void* stream);
    virtual void Remove(Token34* token);
    void Skip(void* stream);
};

static __declspec(noinline) void FUN_00a82b80(Parser34* parser, void* stream) {
    int depth = 1;
    Token34* token = 0;
    int seen = 0;
    while (parser->Next(&token, stream) == 0) {
        if (!token)
            return;
        switch (token->type) {
        case 1:
            ++depth;
            break;
        case 2:
            if (--depth == 0) {
                parser->Remove(token);
                return;
            }
            break;
        case 3:
            if (!seen)
                seen = 1;
            break;
        }
        token->Destroy(1);
        token = 0;
    }
}
}
namespace f3m_00a82e90 {
namespace b1821 {

struct XBool {
    char m_bool;
    XBool() {}
    operator bool() const { return m_bool != 0; }
};

struct XIstream {
    XBool FUN_00a49c20() const throw();          
    XIstream& FUN_00a49f40(bool& v) throw();
    XIstream& FUN_00a4a100(char* v, int n) throw();
    XIstream& FUN_00a4a170(short& v) throw();
    XIstream& FUN_00a4a1c0(unsigned short& v) throw();
    XIstream& FUN_00a4a210(int& v) throw();
    XIstream& FUN_00a4a250(unsigned int& v) throw();
    XIstream& FUN_00a4a290(__int64& v) throw();
    XIstream& FUN_00a4a2d0(unsigned __int64& v) throw();
    XIstream& operator>>(float& v) throw();       
    XIstream& operator>>(bool& v) throw() { return FUN_00a49f40(v); }
    XIstream& operator>>(short& v) throw() { return FUN_00a4a170(v); }
    XIstream& operator>>(unsigned short& v) throw() { return FUN_00a4a1c0(v); }
    XIstream& operator>>(int& v) throw() { return FUN_00a4a210(v); }
    XIstream& operator>>(unsigned int& v) throw() { return FUN_00a4a250(v); }
    XIstream& operator>>(__int64& v) throw() { return FUN_00a4a290(v); }
    XIstream& operator>>(unsigned __int64& v) throw() { return FUN_00a4a2d0(v); }
};

struct XOstream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00923070(void** b, int n) throw();
    XOstream& operator<<(const char* s) throw();  
    XOstream& operator<<(int v) throw();          
    void FUN_00943a60() throw();
};

struct XLogger {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Log(int a, unsigned int h, const char* m, const char* f, int line) throw();
};

extern XLogger* DAT_010f3364; void __cdecl FUN_00923500(void* p, int v, int n) throw();

}

using namespace b1821;

static __declspec(noinline) int FUN_00a82e90(void* addr, XIstream* is, int type)
{
    float* f = (float*)addr;
    switch (type) {
    case 1: *is >> *(bool*)addr; break;
    case 2: is->FUN_00a4a100((char*)addr, 1); break;
    case 3: { int t; *is >> t; *(char*)addr = (char)t; break; }
    case 4: { int t; *is >> t; *(unsigned char*)addr = (unsigned char)t; break; }
    case 5: *is >> *(short*)addr; break;
    case 6: *is >> *(unsigned short*)addr; break;
    case 7: *is >> *(int*)addr; break;
    case 8: *is >> *(unsigned int*)addr; break;
    case 9: *is >> *(__int64*)addr; break;
    case 10: *is >> *(unsigned __int64*)addr; break;
    case 30: { unsigned __int64 t; *is >> t; *(unsigned int*)addr = (unsigned int)t; break; }
    case 11: *is >> f[0]; break;
    case 12:
    case 13:
        *is >> f[0] >> f[1] >> f[2] >> f[3];
        break;
    case 14:
    case 15:
        FUN_00923500(addr, 0, 0x30);
        *is >> f[0] >> f[1] >> f[2];
        *is >> f[4] >> f[5] >> f[6];
        *is >> f[8] >> f[9] >> f[10];
        break;
    case 16:
        *is >> f[0] >> f[1] >> f[2];
        *is >> f[4] >> f[5] >> f[6] >> f[7];
        *is >> f[8] >> f[9] >> f[10];
        f[3] = f[11] = 0.0f;
        break;
    case 17:
        *is >> f[0] >> f[1] >> f[2] >> f[3];
        *is >> f[4] >> f[5] >> f[6] >> f[7];
        *is >> f[8] >> f[9] >> f[10] >> f[11];
        *is >> f[12] >> f[13] >> f[14] >> f[15];
        break;
    case 18:
        *is >> f[0] >> f[1] >> f[2];
        *is >> f[4] >> f[5] >> f[6];
        *is >> f[8] >> f[9] >> f[10];
        *is >> f[12] >> f[13] >> f[14];
        f[3] = f[7] = f[11] = 0.0f;
        f[15] = 1.0f;
        break;
    default: {
        void* buf[128];
        XOstream s;
        s.FUN_00923070(buf, 0x200);
        s << "Class member unknown / unhandled: " << type;
        DAT_010f3364->Log(3, 0x19fca9ad, (const char*)buf, ".\\Serialize\\Xml\\hkXmlObjectReader.cpp", 0x103);
        s.FUN_00943a60();
        break;
    }
    }
    return is->FUN_00a49c20() ? 0 : 1;
}

}
namespace f3m_00a832b0 {
struct A832B0_Obj
{
    virtual void vf00(int value);
    int unk04;
    int unk08;
    int unk0c;

    __forceinline A832B0_Obj* asKind2() { return unk08 == 2 ? this : 0; }
};

struct A832B0_Owner
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c(A832B0_Obj** out, A832B0_Obj* item);
};

int __cdecl hkString_strCmp(int a, int b);

static __declspec(noinline) int FUN_00a832b0(A832B0_Owner* owner, A832B0_Obj* item, A832B0_Obj* other)
{
    int result = 0;
    A832B0_Obj* found = 0;

    owner->vf0c(&found, item);

    A832B0_Obj* kind2 = found->asKind2();
    if (kind2) {
        int b = other->unk0c;
        int a = kind2->unk0c;
        if (hkString_strCmp(a, b) != 0)
            result = 1;
    } else {
        result = 1;
    }

    if (found)
        found->vf00(1);

    return result;
}

}




namespace XmlReaderA83750 {

struct hkThreadMemory;
inline void* hkThreadLocalGet(unsigned int slot) { void* value = TlsGetValue(slot); return value; }
template <class T>
struct hkThreadLocalData
{
    unsigned long m_slotID;
    T getData() const { void* p = hkThreadLocalGet(m_slotID); return static_cast<T>(p); }
};
struct ThreadSlot { static hkThreadLocalData<hkThreadMemory*> DAT_010f3170; };

struct hkThreadMemory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCur;
    int unk24;
    char* m_stackBase;
    char* m_stackEnd;
    void deallocateChunk(void* p, int nbytes, int cls);

    static hkThreadMemory& getInstance() { hkThreadMemory* mem = ThreadSlot::DAT_010f3170.getData(); return *mem; }
    void* allocateStack(int nbytes)
    {
        int aligned = (nbytes + 16) & ~15;
        char* cur = m_stackCur;
        char* next = cur + aligned;
        if (next <= m_stackEnd)
        {
            m_stackCur = next;
            return cur;
        }
        return onStackOverflow(aligned);
    }
    void deallocateStack(void* p)
    {
        m_stackCur = (char*)p;
        if (p == m_stackBase)
            onStackUnderflow(p);
    }
};

extern "C" void FUN_00901e90(void* arr, int newCap, int elemSize);
extern "C" void FUN_00901f10(void* arr, int elemSize);
void __cdecl hkMemCpy(void* dst, const void* src, int n);
void __cdecl hkStrNcpy(char* dst, const char* src, int n);
char* __cdecl hkStrChr(const char* s, int c);
int __cdecl hkAtoi(const char* s);
int __cdecl hkStrCmp(const char* a, const char* b);

enum hkUninit { HK_UNINIT };

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline hkArray(hkUninit) {}
    __forceinline ~hkArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int nbytes = getCapacity() * sizeof(T);
            hkThreadMemory::getInstance().deallocateChunk(m_data, nbytes, 0x17);
        }
    }
    int getSize() const { return m_size; }
    void setSizeUnchecked(int n) { m_size = n; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T* begin() { return m_data; }
    const T* begin() const { return m_data; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    __forceinline void reserve(int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newCap = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newCap, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline void pushBack(const T& t)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = t;
        m_size++;
    }
};

template <class T>
inline T* hkAllocateStack(int n)
{
    return (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
}

template <class T>
inline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

template <class T>
struct hkLocalArray : hkArray<T>
{
    T* m_localMemory;
    __forceinline hkLocalArray(int n)
    {
        m_data = hkAllocateStack<T>(n);
        m_capacityAndFlags = n | 0x80000000;
        m_localMemory = m_data;
    }
    __forceinline ~hkLocalArray()
    {
        hkDeallocateStack<T>(m_localMemory);
    }
};

struct hkString
{
    hkArray<char> m_string;
    __forceinline hkString() {}
    __forceinline ~hkString() {}
    __forceinline hkString(hkUninit u) : m_string(u) {}
    __forceinline hkString(const char* s, int len)
    {
        m_string.setSize(len + 1);
        hkMemCpy(m_string.m_data, s, len);
        m_string.m_data[len] = 0;
    }
    __forceinline hkString(const hkString& o)
    {
        m_string.setSize(o.m_string.m_size);
        hkStrNcpy(m_string.m_data, o.m_string.m_data, o.m_string.m_size);
    }
    __forceinline hkString& operator=(const hkString& o)
    {
        int n = o.m_string.getSize();
        m_string.setSize(n);
        hkMemCpy(m_string.m_data, o.m_string.m_data, n);
        return *this;
    }
    int getLength() const { return m_string.getSize() - 1; }
    const char* cString() const { return m_string.begin(); }
    char operator[](int i) const { return m_string[i]; }
    int indexOf(char c, int start, int end) const;
    __forceinline hkString substr(int index, int maxChars = 0x7fffffff) const
    {
        if (maxChars > getLength() - index)
            maxChars = getLength() - index;
        return hkString(m_string.m_data + index, maxChars);
    }
};

struct hkStreamReader;

struct XmlNode
{
    virtual ~XmlNode();
    int unk04;
    int m_type;
    const char* m_name;
    XmlNode* asStart() { return m_type == 1 ? this : 0; }
    XmlNode* asEnd() { return m_type == 2 ? this : 0; }
    const char* getName() const { return m_name; }
    const char* getAttribute(const char* name, const char* def);
};

void FUN_00a483b0(void* p);

struct XmlTreeList
{
    int unk00;
    int unk04;
    int unk08;
    XmlTreeList(int n);
    ~XmlTreeList();
    void* first();
    void* next(void* p, void (*fn)(void*));
};

struct XmlTree
{
    void (*m_fn)(void*);
    XmlTreeList m_list;
    XmlTree() : m_fn(FUN_00a483b0), m_list(4) {}
};

struct XmlParser
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int nextNode(XmlNode** out, hkStreamReader* reader);
    virtual void putBack(XmlNode* node);
    virtual void expandNode(XmlNode* start, XmlTree* tree, hkStreamReader* reader);
};

struct hkClass;
struct hkClassEnum
{
    int getValueOfName(const char* name, int* out) const;
};

struct hkClassMember
{
    const char* m_name;
    const hkClass* m_class;
    const hkClassEnum* m_enum;
    unsigned char m_type;
    unsigned char m_subtype;
    short m_cArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    unsigned char getType() const { return m_type; }
    unsigned char getSubType() const { return m_subtype; }
    int getOffset() const { return m_offset; }
    int getNumElements() const;
    int getSizeInBytes() const;
    const hkClass* getClass() const;
    const hkClass* getStructClass() const;
    int getArrayType() const;
    int getArrayMemberSize() const;
    const hkClassEnum* getEnumClass() const;
    void setEnumValue(void* addr, int value) const;
};

struct hkClass
{
    const hkClassMember* getMemberByName(const char* name) const;
    int getObjectSize() const;
};

extern hkClass DAT_0116a994;

struct Buffer
{
    hkArray<char>* m_buf;
    Buffer(hkArray<char>* b) : m_buf(b) {}
    int reserve(int nbytes, int pad);
    void advance(int nbytes, int pad)
    {
        int orig = m_buf->getSize();
        int size = (orig + nbytes + pad - 1) & ~(pad - 1);
        m_buf->setSizeUnchecked(size);
    }
    void* pointerAt(int offset) { return m_buf->begin() + offset; }
};

struct Local
{
    int m_from;
    int m_to;
};

struct Global
{
    int m_from;
    void* m_to;
    const hkClass* m_class;
};

struct Finish
{
    int m_from;
    const hkClass* m_class;
};

struct Import
{
    int m_from;
    const char* m_id;
};

struct hkRelocationInfo
{
    hkArray<Local> m_local;
    hkArray<Global> m_global;
    hkArray<Finish> m_finish;
    hkArray<Import> m_imports;
    void* m_pool;
    hkRelocationInfo();
    ~hkRelocationInfo();
    // Guess at the source: the original calls the out-of-line copy of this inline member at one site (the array
    // case, FUN_009b4940) and inlines it at the other sites (inline budget of this large function); the two
    // spellings reproduce that choice.
    void addLocalCall(int from, int to);
    __forceinline void addLocal(int from, int to)
    {
        Local f;
        f.m_from = from;
        f.m_to = to;
        m_local.pushBack(f);
    }
    void addGlobal(int from, void* to, const hkClass* k)
    {
        Global f;
        f.m_from = from;
        f.m_to = to;
        f.m_class = k;
        m_global.pushBack(f);
    }
    void addFinish(int from, const hkClass* k)
    {
        Finish f;
        f.m_from = from;
        f.m_class = k;
        m_finish.pushBack(f);
    }
    void addImport(int from, const char* name);
    void applyLocalAndGlobal(void* buffer);
};

struct hkIstream
{
    void* vtbl;
    int unk04;
    void* m_reader;
    hkIstream(const char* data, int len);
    ~hkIstream();
};

template <class T>
struct DummyArray
{
    T* data;
    int size;
    int capAndFlags;
};

struct DummyHomogeneousArray
{
    const hkClass* klass;
    void* data;
    int size;
};

void* __cdecl hkAddByteOffset(void* p, int n);
void* __cdecl FUN_00a4c6e0(void* p);

static inline bool isSpace(int c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// The text reader at 0x00a833a0 (Havok's getText) returns its hkString by value. The pack unit models it with an
// explicit out pointer, which makes the nine call sites load the out pointer (esi) before the parser (eax); the
// original loads eax first, as a by-value return (hidden pointer set up last) does, so it is declared here that way.
struct hkThreadMemoryAlloc { void* allocateChunk(int n, int cls); };
struct XmlChars { virtual ~XmlChars(); int unk04; int m_type; hkString m_text; void canonicalize(const char* s); };
static __declspec(noinline) hkString getTextV(XmlParser& parser, hkStreamReader* reader, bool canon)
{
    hkString ret(HK_UNINIT);
    char* p = (char*)((hkThreadMemoryAlloc*)&hkThreadMemory::getInstance())->allocateChunk(1, 0x17);
    ret.m_string.m_data = p;
    ret.m_string.m_size = 1;
    ret.m_string.m_capacityAndFlags = 1;
    p[0] = 0;
    XmlNode* node = 0;
    parser.nextNode(&node, reader);
    XmlChars* chars = (node->m_type == 3) ? (XmlChars*)node : 0;
    if (chars)
    {
        if (canon)
            chars->canonicalize("(),");
        ret = chars->m_text;
        delete node;
    }
    else if (node->asEnd())
    {
        parser.putBack(node);
    }
    return ret;
}

static __forceinline int extractCstring(int memberStartOffset, const hkString* text, Buffer* buffer, hkRelocationInfo* reloc)
{
    return f3m_00a83310::FUN_00a83310((f3m_00a83310::Entries83310*)reloc, memberStartOffset,
                                      (f3m_00a83310::Text83310*)text, (f3m_00a83310::Buffer83310*)buffer);
}

static __forceinline void skipElement(XmlParser* parser, hkStreamReader* reader)
{
    f3m_00a82b80::FUN_00a82b80((f3m_00a82b80::Parser34*)parser, reader);
}

static __forceinline int readSinglePod(void* addr, hkIstream* is, int type)
{
    return f3m_00a82e90::FUN_00a82e90(addr, (f3m_00a82e90::b1821::XIstream*)is, type);
}

static __forceinline int consumeEnd(XmlParser* parser, hkStreamReader* reader, XmlNode* start)
{
    return f3m_00a832b0::FUN_00a832b0((f3m_00a832b0::A832B0_Owner*)parser, (f3m_00a832b0::A832B0_Obj*)reader,
                                      (f3m_00a832b0::A832B0_Obj*)start);
}

static __forceinline void offsetRelocs(hkRelocationInfo& dst, hkRelocationInfo& src, int offset)
{
    int i;
    for (i = 0; i < src.m_local.getSize(); ++i)
    {
        Local& l = src.m_local[i];
        dst.addLocal(l.m_from + offset, l.m_to + offset);
    }
    for (i = 0; i < src.m_global.getSize(); ++i)
    {
        Global& g = src.m_global[i];
        dst.addGlobal(g.m_from + offset, g.m_to, g.m_class);
    }
    for (i = 0; i < src.m_finish.getSize(); ++i)
    {
        Finish& f = src.m_finish[i];
        dst.addFinish(f.m_from + offset, f.m_class);
    }
    for (i = 0; i < src.m_imports.getSize(); ++i)
    {
        Import& im = src.m_imports[i];
        dst.addImport(im.m_from + offset, im.m_id);
    }
}

static __declspec(noinline) int loadSimpleArray(const hkClassMember& member, const hkString& text, Buffer& buffer, hkRelocationInfo& reloc)
{
    int numElements = 0;
    int mtype = member.getArrayType();
    switch (mtype)
    {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
    case 30:
    {
        int elemSize = member.getArrayMemberSize();
        hkIstream iss(text.cString(), text.getLength());
        while (readSinglePod(buffer.pointerAt(buffer.reserve(elemSize, 1)), &iss, mtype) == 0)
        {
            numElements += 1;
            buffer.advance(elemSize, 1);
        }
        break;
    }
    case 20:
    case 21:
    case 28:
    {
        int start = 0;
        for (int i = 0; i < text.getLength(); ++i)
        {
            if (isSpace(text[i]))
            {
                if (start != i)
                {
                    hkLocalArray<char> name(i - start + 1);
                    hkMemCpy(name.begin(), text.cString() + start, i - start);
                    name.setSize(i - start + 1);
                    name[i - start] = 0;
                    reloc.addImport(buffer.reserve(4, 1), name.begin());
                    buffer.advance(4, 1);
                    numElements += 1;
                }
                start = i + 1;
            }
        }
        if (start != text.getLength())
        {
            reloc.addImport(buffer.reserve(4, 1), text.cString() + start);
            buffer.advance(4, 1);
            numElements += 1;
        }
        if (mtype == 28)
        {
            numElements /= 2;
        }
        break;
    }
    default:
        break;
    }
    buffer.reserve(0, 16);
    buffer.advance(0, 16);
    return numElements;
}

}

using namespace XmlReaderA83750;

int __cdecl FUN_00a83750(const hkClass* klass, int classStart, Buffer* buffer, XmlNode* topElement, XmlParser* parser, hkStreamReader* reader, hkRelocationInfo* reloc)
{
    XmlNode* node;
    while (parser->nextNode(&node, reader) == 0)
    {
        if (XmlNode* startElement = node->asStart())
        {
            const hkClassMember* member = klass->getMemberByName(startElement->getAttribute("name", 0));
            if (member == 0)
            {
                XmlTree tree;
                parser->expandNode(startElement, &tree, reader);
                for (void* it = tree.m_list.first(); it; it = tree.m_list.next(it, tree.m_fn))
                {
                }
                continue;
            }
            switch (member->getType())
            {
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
            case 30:
            {
                hkString text = getTextV(*parser, reader, 1);
                hkIstream iss(text.cString(), text.getLength());
                void* addr = buffer->pointerAt(member->getOffset() + classStart);
                int numElem = member->getNumElements();
                int elemSize = member->getSizeInBytes() / numElem;
                for (int i = 0; i < numElem; ++i)
                {
                    readSinglePod(addr, &iss, member->getType());
                    addr = hkAddByteOffset(addr, elemSize);
                }
                break;
            }
            case 29:
            {
                hkString text = getTextV(*parser, reader, 0);
                extractCstring(member->getOffset() + classStart, &text, buffer, reloc);
                break;
            }
            case 20:
            case 21:
            {
                if (member->getType() == 20 && member->getSubType() == 2)
                {
                    hkString text = getTextV(*parser, reader, 0);
                    extractCstring(member->getOffset() + classStart, &text, buffer, reloc);
                    break;
                }
                hkString text = getTextV(*parser, reader, 1);
                int count = 0;
                int numElem = member->getNumElements();
                int elemSize = member->getSizeInBytes() / numElem;
                int memberStart = member->getOffset() + classStart;
                int start = 0;
                int i;
                for (i = 0; count < numElem && i < text.getLength(); ++i)
                {
                    if (isSpace(text[i]))
                    {
                        if (start != i)
                        {
                            hkLocalArray<char> name(i - start + 1);
                            hkMemCpy(name.begin(), text.cString() + start, i - start);
                            name.setSize(i - start + 1);
                            name[i - start] = 0;
                            reloc->addImport(memberStart + elemSize * count, name.begin());
                            count++;
                        }
                        start = i + 1;
                    }
                }
                if (start != text.getLength() && count < numElem)
                {
                    reloc->addImport(memberStart + elemSize * count, text.cString() + start);
                }
                break;
            }
            case 22:
            case 23:
            case 26:
            {
                int numElements = -1;
                int arrayStart = buffer->reserve(0, 1);
                if (member->getSubType() == 25)
                {
                    numElements = hkAtoi(startElement->getAttribute("numelements", 0));
                    const hkClass* sclass = member->getClass();
                    if (sclass)
                    {
                        int objSize = sclass->getObjectSize();
                        buffer->reserve(objSize * numElements, 16);
                        buffer->advance(objSize * numElements, 16);
                        for (int i = 0; i < numElements; ++i)
                        {
                            XmlNode* child = 0;
                            parser->nextNode(&child, reader);
                            FUN_00a83750(sclass, arrayStart + i * objSize, buffer, child->asStart(), parser, reader, reloc);
                            delete child;
                        }
                    }
                    else
                    {
                        skipElement(parser, reader);
                    }
                }
                else if (member->getSubType() == 24 || member->getSubType() == 31)
                {
                }
                else if (member->getArrayType() == 29)
                {
                    numElements = hkAtoi(startElement->getAttribute("numelements", 0));
                    buffer->reserve(numElements * 4, 16);
                    buffer->advance(numElements * 4, 16);
                    for (int i = 0; i < numElements; ++i)
                    {
                        XmlNode* child = 0;
                        parser->nextNode(&child, reader);
                        hkString text = getTextV(*parser, reader, 0);
                        extractCstring(arrayStart + i * 4, &text, buffer, reloc);
                        delete child;
                        parser->nextNode(&child, reader);
                        delete child;
                    }
                }
                else if (member->getSubType() == 0)
                {
                    skipElement(parser, reader);
                    numElements = 0;
                }
                else
                {
                    hkString text = getTextV(*parser, reader, member->getSubType() != 25);
                    numElements = loadSimpleArray(*member, text, *buffer, *reloc);
                }
                DummyArray<char>* arr = (DummyArray<char>*)FUN_00a4c6e0(buffer->m_buf->m_data + member->m_offset + classStart);
                arr->data = 0;
                arr->size = numElements;
                if (numElements > 0)
                    reloc->addLocalCall(member->getOffset() + classStart, arrayStart);
                if (member->getType() != 26)
                    arr->capAndFlags = numElements | 0xc0000000;
                break;
            }
            case 24:
            {
                hkString text = getTextV(*parser, reader, 0);
                if (text.getLength() != 0)
                {
                    const hkClassEnum* e = member->getEnumClass();
                    int val = 0;
                    e->getValueOfName(text.cString(), &val);
                    member->setEnumValue(buffer->pointerAt(member->getOffset() + classStart), val);
                }
                break;
            }
            case 25:
            {
                for (int i = 0; i < member->getNumElements(); ++i)
                {
                    XmlNode* child = 0;
                    parser->nextNode(&child, reader);
                    XmlNode* start = child->asStart();
                    if (start == 0)
                    {
                        parser->putBack(child);
                        break;
                    }
                    if (member->getClass())
                    {
                        // offset and sc named: with the plain expression the callee-saved map of the whole
                        // function changes (reader loses edi); these two named values restore it.
                        int offset = member->getOffset();
                        const hkClass* sc = member->getStructClass();
                        int structStart = classStart + offset + i * sc->getObjectSize();
                        FUN_00a83750(member->getStructClass(), structStart, buffer, start, parser, reader, reloc);
                        delete child;
                    }
                    else
                    {
                        skipElement(parser, reader);
                    }
                }
                break;
            }
            case 27:
            {
                int numElements = hkAtoi(startElement->getAttribute("numelements", 0));
                hkLocalArray<char> classStorage(0x400);
                Buffer classBuffer(&classStorage);
                int classOffset;
                {
                    XmlNode* child = 0;
                    parser->nextNode(&child, reader);
                    XmlNode* classStartElem = child->asStart();
                    hkRelocationInfo classReloc;
                    classBuffer.reserve(DAT_0116a994.getObjectSize(), 16);
                    classBuffer.advance(DAT_0116a994.getObjectSize(), 16);
                    FUN_00a83750(&DAT_0116a994, 0, &classBuffer, classStartElem, parser, reader, &classReloc);
                    classOffset = buffer->reserve(classStorage.getSize(), 16);
                    buffer->advance(classStorage.getSize(), 16);
                    hkMemCpy(buffer->pointerAt(classOffset), classBuffer.m_buf->m_data, classStorage.getSize());
                    offsetRelocs(*reloc, classReloc, classOffset);
                    classReloc.applyLocalAndGlobal(classBuffer.m_buf->m_data);
                    delete child;
                }
                const hkClass* hclass = (const hkClass*)classBuffer.pointerAt(0);
                int objSize = hclass->getObjectSize();
                int arrayStart = buffer->reserve(0, 1);
                int total = objSize * numElements;
                buffer->reserve(total, 16);
                buffer->advance(total, 16);
                for (int i = 0; i < numElements; ++i)
                {
                    XmlNode* child = 0;
                    parser->nextNode(&child, reader);
                    FUN_00a83750(hclass, arrayStart + i * objSize, buffer, child->asStart(), parser, reader, reloc);
                    delete child;
                }
                DummyHomogeneousArray* h = (DummyHomogeneousArray*)FUN_00a4c6e0(buffer->m_buf->m_data + member->m_offset + classStart);
                h->klass = 0;
                h->data = 0;
                h->size = numElements;
                reloc->addLocal(member->getOffset() + classStart, classOffset);
                if (numElements > 0)
                    reloc->addLocal(member->getOffset() + classStart + 4, arrayStart);
                break;
            }
            case 28:
            {
                hkString text = getTextV(*parser, reader, 1);
                int sp = text.indexOf(' ', 0, 0x7fffffff);
                if (sp != -1)
                {
                    int memberStart = member->getOffset() + classStart;
                    hkString s = text.substr(0, sp);
                    reloc->addImport(memberStart, s.cString());
                    s = text.substr(sp + 1);
                    reloc->addImport(memberStart + 4, s.cString());
                }
                break;
            }
            case 31:
            {
                hkString text = getTextV(*parser, reader, 0);
                if (text.getLength() != 0)
                {
                    const hkClassEnum* e = member->getEnumClass();
                    hkString copy(text);
                    int value = 0;
                    char* p = copy.m_string.m_data;
                    while (p)
                    {
                        char* next = 0;
                        char* bar = hkStrChr(p, '|');
                        if (bar)
                        {
                            *bar = 0;
                            next = bar + 1;
                        }
                        if (*p >= '0' && *p <= '9')
                        {
                            value |= hkAtoi(p);
                        }
                        else
                        {
                            int v = 0;
                            if (e->getValueOfName(p, &v) == 0)
                                value |= v;
                        }
                        p = next;
                    }
                    member->setEnumValue(buffer->pointerAt(member->getOffset() + classStart), value);
                }
                break;
            }
            }
            if (consumeEnd(parser, reader, startElement) == 1)
            {
                delete node;
                return 1;
            }
        }
        else if (XmlNode* end = node->asEnd())
        {
            if (topElement && hkStrCmp(end->getName(), topElement->getName()) == 0)
            {
                delete node;
                return 0;
            }
        }
        delete node;
    }
    return 1;
}
