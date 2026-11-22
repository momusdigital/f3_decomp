// gamebryo2.2/corelibs/nimain/nirefobject.cpp: NiRefObject, ScrapHeapTaskQueue (1 function)
#include "f3_common.h"
#include "NiRefObject.h"
#pragma optimize("gty", on)
// @fnv 0x00cfcc20
// pdb: hkpReportContactMgr::cleanup | hkpReportContactMgr.obj | fnv360_0822_retail, vtable, high
void NiRefObject::DeleteThis()
{
    delete this;
}
#pragma optimize("", off)
#include "nirefobject_queue.h"
