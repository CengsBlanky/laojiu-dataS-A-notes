#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataElement.h"
#include "LinkStack.h"

typedef struct BinaryTreeNode {
    DataElement data;
    struct BinaryTreeNode * leftNode;
    struct BinaryTreeNode * rightNode;
}BinaryTreeNode;

typedef struct BinaryTree {
    BinaryTreeNode * root;
    int depth;  // tree depth
    int nodesCount;
    int diameter;       // 从叶节点到叶节点的最长路径
}BinaryTree;

void InitBinaryTree (BinaryTree * tree);

int CreateBinaryTree (BinaryTreeNode * root);

void PreOrderPrint (BinaryTreeNode * root);

void InOrderPrint (BinaryTreeNode * root);

void InOrderPrint_Stack (BinaryTreeNode * root);

#endif