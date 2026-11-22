// gamebryo2.2/corelibs/nisystem/console/nifilename.cpp: FileNameComponents (1 function)
#include "f3_common.h"
#include "nifilename_packet.h"
// Initialises the object and splits path into drive, directory, filename and extension buffers via _splitpath_s.
// @fnv 0x00aa27d0
// pdb: NiFilename::NiFilename | NiFilename.obj | fnv360_0822_retail, call_gap, low
// pdb params: pcFullPath
FileNameComponents::FileNameComponents(const char* path)
{
    m_acDirectoryComponent[0] = 0;
    _splitpath_s(path, m_acDriveLetter, 3, m_acFolderPath, 256, m_acBaseName, 256, m_acExtension, 256);
}

#pragma optimize("", off)
