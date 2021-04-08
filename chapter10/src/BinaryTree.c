/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 13:33:47 CST Thursday
 * @filename: BinaryTree.c
 */

#include <string.h>

#include "BinaryTree.h"

static int index_id = 1;

void InitBinaryTree (BinaryTree *tree) {
    tree->root = NULL;
    tree->depth = 0;
    tree->length = 0;
    tree->diameter = 0;
}

int CreateBinaryTree(TreeNode * node) {
    if (!node) return 0;
    char inputName[NAME_SIZE];
    if (index_id == 1) {
        puts("请输入根节点: ");
    }
    fgets(inputName, NAME_SIZE, stdin);
    // if gets only <enter> finish node create
    if (strcmp(inputName, "\n") == 0) return 0;
    node->data.id = index_id++;
    strcpy(node->data.name, inputName);
    node->leftNode = malloc(sizeof(TreeNode));
    node->rightNode = malloc(sizeof(TreeNode));
    printf("请输入左节点: ");
    if (CreateBinaryTree(node->leftNode) == 0) {
        free(node->leftNode);
        node->leftNode = NULL;
    }
    printf("请输入右节点: ");
    if (CreateBinaryTree(node->rightNode) == 0) {
        free(node->rightNode);
        node->rightNode = NULL;
    }
    return 1;
}
