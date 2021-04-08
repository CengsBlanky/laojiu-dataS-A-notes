/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 13:16:11 CST Thursday
 * @filename: TreeNode.h
 */

#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include "ElementType.h"

typedef struct TreeNode{
    ElementType data;
    struct TreeNode *leftNode;
    struct TreeNode *rightNode;
}TreeNode;

#endif

