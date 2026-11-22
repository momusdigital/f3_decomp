// The viewer-string helpers: each formats one member for NiObject::GetViewerStrings ("name = value"), into a string
// allocated with NiAlloc that the caller frees.
// Names: FNV360_PDB (NiGetViewerString overloads, niviewerstrings.cpp).
#ifndef FNV_NIVIEWERSTRINGS_H
#define FNV_NIVIEWERSTRINGS_H
#include "layout_support.h"
#include "NiTPrimitiveArray.h"
char* NiGetViewerString(const char* pcName);
char* NiGetViewerString(const char* pcName, bool bValue);
char* NiGetViewerString(const char* pcName, char cValue);
char* NiGetViewerString(const char* pcName, unsigned char ucValue);
char* NiGetViewerString(const char* pcName, short sValue);
char* NiGetViewerString(const char* pcName, unsigned short usValue);
char* NiGetViewerString(const char* pcName, int iValue);
char* NiGetViewerString(const char* pcName, unsigned int uiValue);
char* NiGetViewerString(const char* pcName, long lValue);
char* NiGetViewerString(const char* pcName, unsigned long ulValue);
char* NiGetViewerString(const char* pcName, float fValue);
char* NiGetViewerString(const char* pcName, double dValue);
char* NiGetViewerString(const char* pcName, const char* pcValue);
char* NiGetViewerString(const char* pcName, void* pvValue);
#endif
