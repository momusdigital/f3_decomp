#include "f3_common.h"
// src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/socket/bsd/hkbsdsocket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __stdcall closesocket(int);
struct FUN_00da2dc0_class
{
    int m_kPointA;                // +0x00
    int m_kPointB;                // +0x04
    int m_iThirdValue;                // +0x08
    int m_iFourthElementInteger;                // +0x0c
    int m_usTrailingValue;  // +0x10
    int m_f;                // +0x14
    int m_g;                // +0x18
    int m_h;                // +0x1c
    int m_pSocket;          // +0x20
    void CloseSocket();
};
// @fnv 0x00da2dc0
// pdb: hkBsdSocket::close | hkBsdSocket.obj | fnv360_0822_retail, vtable, medium
void FUN_00da2dc0_class::CloseSocket()
{
    if (m_pSocket != -1)
    {
        closesocket(m_pSocket);
        m_pSocket = -1;
    }
}

extern int DAT_0102e388;
extern int DAT_010d5030;

struct hkBsdSocket
{
    void __thiscall CloseSocket();
    void __thiscall Destroy();
};

// @fnv 0x00da3080
// pdb: hkBsdSocket::~hkBsdSocket | hkBsdSocket.obj | tesv_win, hash, low
void __thiscall hkBsdSocket::Destroy()
{
    *(int*)this = (int)&DAT_010d5030;
    this->CloseSocket();
    *(int*)((char*)this + 0x14) = (int)&DAT_0102e388;
    *(int*)((char*)this + 8) = (int)&DAT_0102e388;
    *(int*)this = (int)&DAT_0102e388;
}

extern "C" void __cdecl FUN_00d2b850(void);
extern "C" void __cdecl hkBsdSocket_createSocket(void*);
extern int DAT_010d5030;

struct FUN_00da30a0_cls
{
    void* m_vft;
    char m_auiShapeKeys[28];
    int m_field_0x20;
    void hkBsdSocket_createSocket();
    void* __thiscall InitWithParam(int param);
};

// Calls FUN_00d2b850, sets the vtable to DAT_010d5030 and m_field_0x20 to param, calls hkBsdSocket_createSocket if param is -1, and returns this.
// @fnv 0x00da30a0
// pdb: hkBsdSocket::hkBsdSocket | hkBsdSocket.obj | tesv_win, call_gap, low
void* __thiscall FUN_00da30a0_cls::InitWithParam(int param)
{
    FUN_00d2b850();
    m_vft = &DAT_010d5030;
    m_field_0x20 = param;
    if (param == -1)
        hkBsdSocket_createSocket();
    return this;
}

struct FUN_00da2db0_cls
{
    char m_auiShapeKeys[0x20];
    int m_pSocket;
    bool* __thiscall hkBsdSocket_isOk(bool* pOut);
};

// @fnv 0x00da2db0
// pdb: hkBsdSocket::isOk | hkBsdSocket.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_open), high
bool* FUN_00da2db0_cls::hkBsdSocket_isOk(bool* pOut)
{
    *pOut = (m_pSocket != -1);
    return pOut;
}

extern "C" int __stdcall FUN_00ee6d5c(int, int, int, int);
extern "C" int __cdecl FUN_00ee6d50(void);

struct FUN_00da2e60_cls
{
    void* m_vft;  // +0x00
    char m_auiShapeKeys[0x1c];
    int m_pSocket;  // +0x20
    int hkBsdSocket_write(int, int);
};

// @fnv 0x00da2e60
// pdb: hkBsdSocket::write | hkBsdSocket.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun), high
int FUN_00da2e60_cls::hkBsdSocket_write(int a, int b)
{
    int r;
    if (m_pSocket != -1)
    {
        r = FUN_00ee6d5c(m_pSocket, a, b, 0);
        if (r > 0 && r != -1)
            return r;
        if (FUN_00ee6d50() != 0x2733)
        {
            void** vft = *(void***)this;
            void(__thiscall * fn)(void*) = (void(__thiscall*)(void*))vft[4];
            fn(this);
        }
    }
    return 0;
}

int __stdcall FUN_00ee6d4a(int, int, int);

struct FUN_00da2de0_class
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();

    char m_auiShapeKeys[0x1c];
    int m_pSocket;

    int hkBsdSocket_createSocket();
};

// @fnv 0x00da2de0
// pdb: hkBsdSocket::createSocket | hkBsdSocket.obj | fnv360_0721_beta, objrun + bridge(hash|objrun) + skyrim(hash), high
int FUN_00da2de0_class::hkBsdSocket_createSocket()
{
    this->f4();

    int result = FUN_00ee6d4a(2, 1, 0);
    bool success = result == -1;
    m_pSocket = result;
    return success;
}

struct FUN_00da2f90_cls
{
    char m_auiShapeKeys[0x20];
    int m_pSocket;
    bool FUN_00da2f90(int a, int b, int c);
};
extern "C" int __stdcall FUN_00ee6d7a(int, int, int, int);
// @fnv 0x00da2f90
// pdb: hkBsdSocket::asyncSelect | hkBsdSocket.obj | tesv_win, hash, low
bool FUN_00da2f90_cls::FUN_00da2f90(int aiArg1, int aiArg2, int c)
{
    return FUN_00ee6d7a(m_pSocket, aiArg1, aiArg2, ((c & 3) | ((c & 0xc) << 2))) != 0;
}

// FUN_00ee6d9e: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 21 (setsockopt, stdcall, 5 args).
extern "C" __declspec(dllimport) int __stdcall setsockopt(unsigned int s, int level, int optname, const char* optval,
                                                          int optlen);

// @fnv 0x00ee6d9e
// pdb: D3DXMatrixMultiply | d3dx9_42.dll | tesv_win, objrun_open, low
int __stdcall FUN_00ee6d9e(unsigned int s, int level, int optname, const char* optval, int optlen)
{
    return setsockopt(s, level, optname, optval, optlen);
}

extern "C" int __stdcall FUN_00ee6d56(int, void*, int, int);
extern "C" int __cdecl FUN_00ee6d50(void);

struct FUN_00da2e10_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_pSocket;

    int Read(void* buf, int len);
};

// @fnv 0x00da2e10
// pdb: hkBsdSocket::read | hkBsdSocket.obj | fnv360_0822_retail, vtable, high
// pdb params: buf, nbytes
int FUN_00da2e10_cls::Read(void* buf, int len)
{
    if (m_pSocket != -1)
    {
        int res = FUN_00ee6d56(m_pSocket, buf, len, 0);
        if (res > 0 && res != -1)
        {
            return res;
        }
        if (FUN_00ee6d50() != 0x2733)
        {
            v4();
        }
    }
    return 0;
}

struct FUN_00cbbd40_router
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int, int);
};
struct FUN_00cbbd40_holder
{
    int unk0;
    int unk4;
    int unk8;
    FUN_00cbbd40_router* unkC;
};
extern "C" FUN_00cbbd40_holder* __cdecl FUN_00c85750(void);
struct FUN_00cbbd40_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_00cbbd40();
};
// @fnv 0x00cbbd40
void FUN_00cbbd40_cls::FUN_00cbbd40()
{
    FUN_00cbbd40_holder* pHolder = FUN_00c85750();
    FUN_00cbbd40_router* r = pHolder->unkC;
    int iOldValue = m_8;
    m_iWordAt04 = 0;
    if (!(iOldValue & 0x80000000))
        r->f4(m_iWordAt00, iOldValue & 0x3fffffff);
    m_iWordAt00 = 0;
    m_8 = 0x80000000;
}

struct S00da2ff0_Msg
{
    int unk00;
    int unk04;
    int unk08;
    void __thiscall Init(void*, int);
    void __thiscall Done();
    void __thiscall Add(const char*);
};

struct S00da2ff0_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int, int, void*, const char*, int);
};

// When the flag is clear, calls FUN_00ee6d86 with 0x202, reports failure, and sets the flag.
// @f3 0x00a28cc0 (community match, verified in this file)
extern char DAT_0116c258;
extern S00da2ff0_Err* DAT_010f3364;
int __stdcall FUN_00c208f8(unsigned short, void*);
// pdb: hkBsdNetworkInit | hkBsdSocket.obj | fnv360_0822_retail, ustr, high
// pdb: hkBsdNetworkInit | hkBsdSocket.obj | fnv360_0822_retail, ustr, high (was: InitWinsock)
void hkBsdNetworkInit()
{
    if (DAT_0116c258 == 0)
    {
        struct
        {
            int buf[0x80];
            int wsa[0x64];
        } L;
        if (FUN_00c208f8(0x202, L.wsa) == -1)
        {
            S00da2ff0_Msg ostr;
            ostr.Init(L.buf, 0x200);
            ostr.Add("(Windows)WSAStartup failed with error!");
            DAT_010f3364->v3(3, 0x321825f8, L.buf, ".\\System\\Io\\Socket\\Bsd\\hkBsdSocket.cpp", 0x48);
            ostr.Done();
        }
        DAT_0116c258 = 1;
    }
}


extern "C" void __cdecl FUN_00cb1280(void*, int, unsigned int);
extern "C" void __cdecl FUN_00cb1260(void*, const void*, unsigned int);
extern "C" int __stdcall FUN_00ee6d74(int);
extern "C" int __stdcall FUN_00ee6d6e(const char*);
extern "C" int __stdcall FUN_00ee6d68(const char*);
extern "C" int __stdcall FUN_00ee6d62(int, void*, int);
extern "C" int __cdecl FUN_00ee6d50(void);

static __declspec(noinline) bool* FUN_00da2eb0(int c, bool* out)
{
    *out = false;
    if (c >= '0' && c <= '9')
        *out = true;
    return out;
}

struct IPv4SocketAddress
{
    unsigned short family;
    unsigned short port;
    unsigned int address;
    unsigned int sin_zero_low;
    unsigned int sin_zero_high;
};
struct HostEntry
{
    char* name;
    char** aliases;
    short address_type;
    short address_length;
    char** addresses;
};
struct SocketConnector
{
    virtual void onInitialize();
    virtual void onConnected();
    virtual void onClose();
    virtual void onRead();
    virtual void onConnectionFailure();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int socket;
    int hkBsdSocket_createSocket();
    int hkBsdSocket_connect(const char* host, int port);
};

// Resolves the host to an IPv4 address, ensures a socket exists, and calls the connection routine with the address and port.
// @fnv 0x00da2ec0
// pdb: hkBsdSocket::connect | hkBsdSocket.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
int SocketConnector::hkBsdSocket_connect(const char* host, int port)
{
    IPv4SocketAddress target;
    FUN_00cb1280(&target, 0, sizeof(target));
    target.family = 2;
    target.port = (unsigned short)FUN_00ee6d74(port);

    if (*FUN_00da2eb0(host[0], (bool*)&port))
    {
        target.address = FUN_00ee6d6e(host);
    }
    else
    {
        HostEntry* pHostEntry = (HostEntry*)FUN_00ee6d68(host);
        if (!pHostEntry)
            return 1;
        FUN_00cb1260(&target.address, pHostEntry->addresses[0], pHostEntry->address_length);
    }

    if (socket == -1 && hkBsdSocket_createSocket())
        return 1;
    int iResult = FUN_00ee6d62(socket, &target, sizeof(target));
    if (iResult != -1)
        goto success;
    if (FUN_00ee6d50() == 0x2733)
        goto success;
    onConnectionFailure();
    return 1;
success:
    return 0;
}

unsigned short __stdcall FUN_00ee6d74(unsigned short usHostShort);
extern "C" int __stdcall FUN_00ee6d9e(unsigned int s, int level, int option, const void* value, int size);

struct sockaddr_inDA30
{
    short sin_family;
    unsigned short sin_port;
    unsigned long sin_addr;
    unsigned long sin_zero[2];
};

class hkStringBufDA30
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[32];

    void InitBuffer() throw();
    void FUN_00cbbd40() throw();
    void FUN_00d61c10(const char* pcString) throw();

    hkStringBufDA30()
    {
        InitBuffer();
    }
    ~hkStringBufDA30()
    {
        FUN_00cbbd40();
    }
    void operator=(const char* pcString)
    {
        FUN_00d61c10(pcString);
    }
};

class hkOstreamDA30
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;

    void FUN_00cb1600(void* pvBuffer, int iSize) throw();
    void FUN_00cc00e0() throw();
    hkOstreamDA30& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamDA30& GridCellArray_MoveItem(const hkStringBufDA30& kString) throw();
    hkOstreamDA30& WriteInt(int i) throw();

    hkOstreamDA30(void* pvBuffer, int iSize)
    {
        FUN_00cb1600(pvBuffer, iSize);
    }
    ~hkOstreamDA30()
    {
        FUN_00cc00e0();
    }
};

class hkBsdSocketDA30
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void close() throw();

    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    unsigned int m_pSocket;

    int hkBsdSocket_createSocket() throw();
    int hkBsdSocket_listen(int iPort) throw();
};

// Binds the socket to the given port, sets it to listen with backlog 2, and logs the host name and port.
// @f3 0x00a28d90 (community match, verified in this file)
int __stdcall FUN_00c2090a(unsigned int,const void*,int);
int __stdcall FUN_00c20904(unsigned int,int);
int __stdcall FUN_00c208fe(char*,int);
struct Heap573 {char* FUN_008f6d30(unsigned int,int);void FUN_008f6d90(void*,unsigned int,int);};
extern unsigned long DAT_010f3170;
extern Heap573* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_00901e90(void*,int,int);
int __cdecl FUN_009233f0(const char*);
void __cdecl FUN_009234e0(void*,const void*,unsigned int);
extern char DAT_00e85a58,DAT_00e85a6c,DAT_00e859d8;
struct String573 {
    char* data;int count;unsigned int flags;
    __forceinline void Reserve(int requested){int capacity=flags&0x3fffffff;if(capacity<requested){int grown=2*capacity;if(requested>=grown)grown=requested;FUN_00901e90(this,grown,1);}}
    __forceinline void Assign(const char* source){
        if(*source){int length=FUN_009233f0(source);Reserve(length+1);count=length+1;FUN_009234e0(data,source,count);}
        else{Reserve(1);count=1;*data=0;}
    }
};
struct Report573 {
    int unk00,unk04,unk08;
    void FUN_00923070(void*,int);
    Report573& FUN_00943710(const char*);
    Report573& FUN_00943b80(const String573&);
    Report573& FUN_009437d0(int);
    void FUN_00943a60();
};
// pdb: hkBsdSocket::listen | hkBsdSocket.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(ustr), high
int hkBsdSocketDA30::hkBsdSocket_listen(int port) throw(){
    if(hkBsdSocket_createSocket()!=0)return 1;
    sockaddr_inDA30 address;
    address.sin_family=2;address.sin_addr=0;address.sin_port=FUN_00ee6d74(port);
    int on=1;
    FUN_00ee6d9e(m_pSocket,0xffff,4,&on,4);
    if(FUN_00c2090a(m_pSocket,&address,16)==-1){close();return 1;}
    if(FUN_00c20904(m_pSocket,2)==-1){close();return 1;}
    String573 host;
    Heap573* (__stdcall* lookup)(unsigned long)=DAT_00d9b080;
    Heap573* heap=lookup(DAT_010f3170);
    host.data=heap->FUN_008f6d30(1,23);host.count=1;host.flags=1;host.data[0]=0;
    unsigned int hostname[64];
    FUN_00c208fe((char*)hostname,256);
    host.Assign((const char*)hostname);
    unsigned int reportBuffer[128];
    Report573 report;
    report.FUN_00923070(reportBuffer,512);
    report.FUN_00943710(&DAT_00e85a58).FUN_00943b80(host).FUN_00943710(&DAT_00e85a6c).FUN_009437d0(port);
    DAT_010f3364->v3(0,-1,reportBuffer,&DAT_00e859d8,364);
    report.FUN_00943a60();
    if((host.flags&0x80000000u)==0){unsigned int capacity=host.flags&0x3fffffff;Heap573* oldHeap=lookup(DAT_010f3170);oldHeap->FUN_008f6d90(host.data,capacity,23);}
    return 0;
}
