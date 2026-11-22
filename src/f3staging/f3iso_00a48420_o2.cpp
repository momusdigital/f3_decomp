#include <new>
// src/f3staging/f3iso_00a48420_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a48420 alone: its served file holds two declarations of the one function.
// Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a48420 (community match, verified in this file)
namespace f3m_00a48420 {
namespace XmlClassFilter {
int __cdecl hkString_strCmp(const char* a, const char* b);

struct XmlElement_9730;
struct XmlNode_9730 {
    int unk00;
    int unk04;
    int type;
    const char* name;
    const char* cString() const { return name; }
    XmlElement_9730* asElement() { return type == 1 ? (XmlElement_9730*)this : 0; }
    XmlNode_9730* asEnd() { return type == 2 ? this : 0; }
};
struct XmlElement_9730 : XmlNode_9730 {
    const char* FUN_00a80eb0(const char* attribute, const char* defaultValue);
};

static __declspec(noinline) bool FUN_00a48420(const char* className)
{
    return className && hkString_strCmp(className, "hkClass")
        && hkString_strCmp(className, "hkClassMember")
        && hkString_strCmp(className, "hkClassEnum")
        && hkString_strCmp(className, "hkClassEnumItem");
}

struct XmlReader_9730 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_depth;
    int m_readObjects;
    int m_stop;
    int FUN_00a81960(XmlNode_9730** node, void* stream);
    int FUN_00a49670(XmlElement_9730* element, XmlNode_9730** node, void* stream);
    int FUN_00a49730(XmlNode_9730** node, void* stream);
};

int XmlReader_9730::FUN_00a49730(XmlNode_9730** node, void* stream)
{
    int result = FUN_00a81960(node, stream);
    if (result == 0 && m_stop == 0) {
        if (XmlElement_9730* element = (*node)->asElement()) {
            const char* className = element->FUN_00a80eb0("class", 0);
            if (!(m_depth > 0) && (hkString_strCmp(element->cString(), "hkobject") || FUN_00a48420(className))) {
                if (m_readObjects && !hkString_strCmp(element->cString(), "hkobject") && FUN_00a48420(className))
                    result = FUN_00a49670(element, node, stream);
            } else {
                m_depth++;
                if (!hkString_strCmp(element->cString(), "hkparam") && !hkString_strCmp("attributes", element->FUN_00a80eb0("name", 0))) {
                    m_depth--;
                    result = FUN_00a49670(element, node, stream);
                }
            }
        } else if ((*node)->asEnd()) {
            if (m_depth > 0)
                m_depth--;
        }
    }
    return result;
}
}
}   // namespace f3m_00a48420
