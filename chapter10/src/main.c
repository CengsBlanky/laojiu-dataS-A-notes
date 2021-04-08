/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 14:12:23 CST Thursday
 * @filename: main.c
 */

#include "BinaryTree.h"

void TestBinaryTreeCreation();

int main(int argc, char *argv[]) {
    // test binary tree
    TestBinaryTreeCreation();
    return 0;
}

void TestBinaryTreeCreation() {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    InitBinaryTree(tree);
    tree->root = malloc(sizeof(TreeNode));
    CreateBinaryTree(tree->root);
}
