#include "BinaryTree.h"

static int id = 1;

char * numbers[] = {"A", "B", "D", "#", "#", "#", "C", "E", "#", "#", "F", "#", "#"};
static int charIndex = 0;

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
    strcpy(input, numbers[charIndex++]);
    if (strcmp(input, "#") == 0) return 0;
    strcpy(root->data.name, input);
    root->data.id = id++;
    root->leftNode = malloc(sizeof(BinaryTreeNode));
    root->rightNode = malloc(sizeof(BinaryTreeNode));
    if (CreateBinaryTree(root->leftNode) == 0) {
        free(root->leftNode);
        root->leftNode = NULL;
    }
    if (CreateBinaryTree(root->rightNode) == 0) {
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

void PostOrderPrint (BinaryTreeNode * root) {
    if (root) {
        PostOrderPrint(root->leftNode);
        PostOrderPrint(root->rightNode);
        printf("[%d, %s]->", root->data.id, root->data.name);
    }
}

void ZOrderPrint_Queue (BinaryTreeNode * root) {
    if (!root) return;
    LinkQueue * queue = malloc(sizeof(LinkQueue));
    InitQueue(queue);
    BinaryTreeNode * curNode = root;
    EnQueue(queue, curNode);
    // PrintQueue(queue);
    puts("into while loop");
    while (!IsEmptyQueue(queue)) {
        curNode = DeQueue(queue);
        printf("[%d, %s]->", curNode->data.id, curNode->data.name);
        if (curNode->leftNode != NULL) {
            EnQueue(queue, curNode->leftNode);
        }
        if (curNode->rightNode != NULL) {
            EnQueue(queue, curNode->rightNode);
        }
    }
}

void TestQueue (BinaryTreeNode * root) {
    LinkQueue linkQueue;
    InitQueue(&linkQueue);
    for (int i = 0; i < 13; i++) {
        EnQueue(&linkQueue, root);
    }
    PrintQueue(&linkQueue);
}