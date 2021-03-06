/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 13:30:21 CST Thursday
 * @filename: BinaryTree.h
 */

#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "TreeNode.h"
#include "LinkedQueue.h"

typedef struct BinaryTree {
    TreeNode * root;
    int length;
    int depth;
    int diameter; // 直径,从叶结点到叶结点的最长路径
}BinaryTree;

/**
 * 初始化空二叉树
 */
void InitBinaryTree (BinaryTree *tree);

/*
 * create binary tree
 */
int CreateBinaryTree(TreeNode * node);

/*
 * pre order traverse
 */
void PreOrderTraverse(TreeNode * node);

/* 
 * middle order traverse
 */
void MiddleOrderTraverse(TreeNode * node);

/* 
 * post order traverse
 */
void PostOrderTraverse(TreeNode * node);

/* 
 * 层序遍历的实现
 */

// 实现层序遍历
void ZOrderTraverse(TreeNode * node);


void eddeQueue();
#endif

