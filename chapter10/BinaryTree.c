#include "BinaryTree.h"

static int id = 1;

void InitBinaryTree (BinaryTree * tree) {
    tree->root = NULL;
    tree->depth = 0;
    tree->diameter = 0;
    tree->nodesCount = 0;
}

// malloc root before call this function
int CreateBinaryTree (BinaryTreeNode * root) {
    if (!root) return 0;
    char input[NAME_SIZE];
    gets(input);
    input[strlen(input)] = '\0';
    if (strcmp(input, "#") == 0) return 0;
    strcpy(root->data.name, input);
    root->data.id = id++;
    root->leftNode = malloc(sizeof(BinaryTreeNode));
    root->rightNode = malloc(sizeof(BinaryTreeNode));
    printf("Please input left node name:\n");
    if (CreateBinaryTree(root->leftNode) == 0) {
        printf("end input left node\n");
        free(root->leftNode);
        root->leftNode = NULL;
    }
    printf("Please input right node name:\n");
    if (CreateBinaryTree(root->rightNode) == 0) {
        printf("end input right node\n");
        free(root->rightNode);
        root->rightNode = NULL;
    }
    return 1;
}

void PreOrderPrint (BinaryTreeNode * root) {
    // root->left->right
    if (root) {
        printf("[%d, %s]->", root->data.id, root->data.name);
        PreOrderPrint(root->leftNode);
        PreOrderPrint(root->rightNode);
    } 
}

void InOrderPrint (BinaryTreeNode * root) {
    if (root) {
        InOrderPrint(root->leftNode);
        printf("[%d, %s]->", root->data.id, root->data.name);
        InOrderPrint(root->rightNode);
    }
}

void InOrderPrint_Stack (BinaryTreeNode * root) {
    LinkStack * stack = malloc(sizeof(LinkStack));
    InitLinkStack(stack);
    BinaryTreeNode * nodePoint = malloc(sizeof(BinaryTreeNode));
    while (root || !IsEmpty(stack)) {
        if (root) {
            Push(stack, root);
            root = root->leftNode;
        } else {
            Pop(stack, &nodePoint);
            printf("[%d, %s]->", nodePoint->data.id, nodePoint->data.name);
            root = nodePoint->rightNode;
        }
    }
    free(nodePoint);
    nodePoint = NULL;
}