/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/21 19:46:53 中国标准时间 Wednesday
 * @filename: LinkedQueue.c
 */

#include "LinkedQueue.h"

void InitLinkedQueue(LinkedQueue * linkedQueue) {
    linkedQueue->qFront = malloc(sizeof(QueueNode));
    linkedQueue->qFront->next = NULL;
    // 空队列的头尾指针都指向同一个初始化的内存区域
    linkedQueue->qRear = linkedQueue->qFront;
}

// 入栈
void enQueue(TreeNode * data, LinkedQueue * linkedQueue) {

}

// 出栈
void deQueue(TreeNode * data, LinkedQueue * linkedQueue);
