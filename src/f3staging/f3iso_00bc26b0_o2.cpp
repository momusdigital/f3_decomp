#include <new>
// src/f3staging/f3iso_00bc26b0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00bc26b0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bc26b0 (community match, verified in this file)
namespace f3m_00bc26b0 {
namespace Sbc26b0_ {

struct ValObj;

template <class T>
struct EmptyAlloc
{
};

struct EmptyComp
{
};

struct StrStorage
{
    EmptyAlloc<char> allocator;
    union
    {
        char inlineBuf[16];
        char* heapBuf;
    } buf;
    unsigned int len;
    unsigned int cap;
};

struct KeyValPair
{
    const StrStorage key;
    ValObj* mapped;
};

struct TreeNode
{
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    KeyValPair value;
    char color;
    char isNil;
};

struct TreeMap
{
    EmptyComp comp;
    EmptyAlloc<TreeNode> nodeAlloc;
    EmptyAlloc<TreeNode*> ptrAlloc;
    EmptyAlloc<KeyValPair> valAlloc;
    TreeNode* head;
    unsigned int count;

    void FUN_00bc26b0(TreeNode* where);
};

// pdb: std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,CIdvBezierSpline *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,CIdvBezierSpline *> >,0> >::_Lrotate | IdvSpline.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _Wherenode
void TreeMap::FUN_00bc26b0(TreeNode* where)
{
    TreeNode* node = where->right;
    where->right = node->left;
    if (!node->left->isNil)
        node->left->parent = where;
    node->parent = where->parent;
    if (where == head->parent)
        head->parent = node;
    else if (where == where->parent->left)
        where->parent->left = node;
    else
        where->parent->right = node;
    node->left = where;
    where->parent = node;
}

}
}   // namespace f3m_00bc26b0
