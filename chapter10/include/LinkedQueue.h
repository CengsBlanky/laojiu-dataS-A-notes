/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/21 19:21:02 中国标准时间 Wednesday
 * @filename: LinkedQueue.h
 */

#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

#include "TreeNode.h"

typedef struct qNode {
    TreeNode * data;
    struct qNode * next;
}QueueNode;

typedef struct {
    QueueNode * qFront; // 队头指针
    QueueNode * qRear; // 队尾指针
}LinkedQueue;

void InitLinkedQueue(LinkedQueue * linkedQueue);

// 入栈
void enQueue(TreeNode * data, LinkedQueue * linkedQueue);

// 出栈
void deQueue(TreeNode * data, LinkedQueue * linkedQueue);

#endif

