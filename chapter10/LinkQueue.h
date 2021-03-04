#ifndef LINKQUEUE_H_INCLUDE
#define LINKQUEUE_H_INCLUDE

#include "BinaryTree.h"

typedef struct BinaryTreeNode BinaryTreeNode;

typedef struct QueueNode {
    BinaryTreeNode * data;
    struct QueueNode * next;
}QueueNode;

typedef struct LinkQueue {
    QueueNode * head;
    QueueNode * tail;
}LinkQueue;

void InitQueue (LinkQueue * queue);

void EnQueue (LinkQueue * queue, BinaryTreeNode * node);

BinaryTreeNode * DeQueue (LinkQueue * queue);

int IsEmptyQueue (LinkQueue * queue);

void PrintQueue (LinkQueue * queue);

#endif