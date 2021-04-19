/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 14:12:23 CST Thursday
 * @filename: main.c
 */

#include "BinaryTree.h"

void TestBinaryTreeCreation();
void TestBinaryTreeTraverse();

int main(int argc, char *argv[]) {
    // test binary tree
    // TestBinaryTreeCreation();
    TestBinaryTreeTraverse();
    system("pause");
    return 0;
}

void TestBinaryTreeCreation() {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    InitBinaryTree(tree);
    tree->root = malloc(sizeof(TreeNode));
    CreateBinaryTree(tree->root);
}

void TestBinaryTreeTraverse() {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    InitBinaryTree(tree);
    tree->root = malloc(sizeof(TreeNode));
    CreateBinaryTree(tree->root);

    printf("\nPreOrder:\n");
    PreOrderTraverse(tree->root);
    printf("\nMiddleOrder:\n");
    MiddleOrderTraverse(tree->root);
}
