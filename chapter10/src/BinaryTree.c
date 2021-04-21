/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/08 13:33:47 CST Thursday
 * @filename: BinaryTree.c
 */

#include <string.h>

#include "BinaryTree.h"

static int index_id = 1;
// mock data
char * nodeNames[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
int inputIndex = 0;

void InitBinaryTree (BinaryTree *tree) {
    tree->root = NULL;
    tree->depth = 0;
    tree->length = 0;
    tree->diameter = 0;
}

int CreateBinaryTree(TreeNode * node) {
    if (!node) return 0;
    char inputName[NAME_SIZE];
    // if (index_id == 1) {
    //     puts("请输入根节点: ");
    // }
    // fgets(inputName, NAME_SIZE, stdin);
    // if fgets only <enter>, finish node create
    if (strcmp(inputName, "\n") == 0) return 0;
    if (inputIndex == (sizeof(nodeNames) / sizeof(char *))) return 0;
    node->data.id = index_id++;
    strcpy(node->data.name, nodeNames[inputIndex++]);
    node->leftNode = malloc(sizeof(TreeNode));
    node->rightNode = malloc(sizeof(TreeNode));
    // printf("请输入左节点: ");
    if (CreateBinaryTree(node->leftNode) == 0) {
        free(node->leftNode);
        node->leftNode = NULL;
    }
    // printf("请输入右节点: ");
    if (CreateBinaryTree(node->rightNode) == 0) {
        free(node->rightNode);
        node->rightNode = NULL;
    }
    return 1;
}

// 二叉树的遍历
void PreOrderTraverse(TreeNode * node) {
    if (node) {
        printf("[%d, %s]->", node->data.id, node->data.name);
        PreOrderTraverse(node->leftNode);
        PreOrderTraverse(node->rightNode);
    }
}

void MiddleOrderTraverse(TreeNode * node) {
    if (node) {
        MiddleOrderTraverse(node->leftNode);
        printf("[%d, %s]->", node->data.id, node->data.name);
        MiddleOrderTraverse(node->rightNode);
    }
}

void PostOrderTraverse(TreeNode * node) {
    if (node) {
        PostOrderTraverse(node->leftNode);
        PostOrderTraverse(node->rightNode);
        printf("[%d, %s]->", node->data.id, node->data.name);
    }
}

void ZOrderTraverse(TreeNode * node) {
    // 1. 建立一个队列, 完成初始化工作
    LinkedQueue * queue = malloc(sizeof(LinkedQueue));
    InitLinkedQueue(queue);
    // 2. 把根结点入队
    enQueue(node, queue);
    // 3. 判断队列中是否还有结点
    while (IsEmptyQueue(queue) == 0) {
        // 只要不是空队列, 就出队一个结点
        node = deQueue(queue);
        // 打印出队的结点
        printf("[%d, %s]->", node->data.id, node->data.name);
        // 左右结点如果存在, 均入队
        if (node->rightNode != NULL) {
            enQueue(node->rightNode, queue);
        }
        if (node->leftNode != NULL) {
            enQueue(node->leftNode, queue);
        }
    }
}

void eddeQueue() {
    LinkedQueue * queue = malloc(sizeof(LinkedQueue));
    InitLinkedQueue(queue);
    int count = 10;
    int i = 0;
    char *name = "Tom baby";
    while (count--) {
        TreeNode * node = malloc(sizeof(TreeNode));
        node->data.id = i++;
        strcpy(node->data.name, name);
        enQueue(node, queue);
    }
    count = 10;
    printf("[");
    TreeNode * node = malloc(sizeof(TreeNode));
    while (count--) {
        node = deQueue(queue);
        printf("%d, %s, ", node->data.id, node->data.name);
    }
    printf("]\n");
}
