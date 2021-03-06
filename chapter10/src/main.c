/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 14:12:23 CST Thursday
 * @filename: main.c
 */

#include "BinaryTree.h"

void TestBinaryTreeCreation();
void TestBinaryTreeTraverse();
void TestZTraverse();
void queueTest();

int main(int argc, char *argv[]) {
    // test binary tree
    // TestBinaryTreeCreation();
    // TestBinaryTreeTraverse();
    TestZTraverse();
    // eddeQueue();
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
    printf("\nPostOrder:\n");
    PostOrderTraverse(tree->root);
}

void TestZTraverse() {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    InitBinaryTree(tree);
    tree->root = malloc(sizeof(TreeNode));
    CreateBinaryTree(tree->root);
    puts("Z traverse result: \n");
    ZOrderTraverse(tree->root);
}

void queueTest() {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    InitBinaryTree(tree);
    tree->root = malloc(sizeof(TreeNode));
    CreateBinaryTree(tree->root);
}
