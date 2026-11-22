// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) int __stdcall WSAStartup(unsigned short version, void* data);
// @fnv 0x00ee6d86
// pdb: NiFile::DirectoryExists | NiFile.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pcDirName
int __stdcall FUN_00ee6d86(unsigned short version, void* data)
{
    return WSAStartup(version, data);
}
