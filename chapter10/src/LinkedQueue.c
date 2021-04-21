/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/21 19:46:53 中国标准时间 Wednesday
 * @filename: LinkedQueue.c
 */

#include "LinkedQueue.h"
#include <string.h>

void InitLinkedQueue(LinkedQueue * linkedQueue) {
    linkedQueue->qFront = malloc(sizeof(QueueNode));
    linkedQueue->qFront->next = NULL;
    // 空队列的头尾指针都指向同一个初始化的内存区域
    linkedQueue->qRear = linkedQueue->qFront;
}

// 入栈
void enQueue(TreeNode * data, LinkedQueue * linkedQueue) {
    // 1. 将数据包装进队列节点(QueueNode):
    QueueNode * tempNode = malloc(sizeof(QueueNode));
    tempNode->data = data;
    tempNode->next = NULL;
    // 2. 将尾指针和尾指针的下一个节点都指向这个节点
    linkedQueue->qRear->next = tempNode;
    linkedQueue->qRear = tempNode;
}

// 出栈
TreeNode * deQueue(LinkedQueue * linkedQueue) {
    // 如果头结点和尾结点一样,说明队列已经空了
    if (linkedQueue->qFront == linkedQueue->qRear) return NULL;
    QueueNode * retNode = linkedQueue->qFront->next;
    // 1. 接收出栈结点的数据
    // 2. 移动头结点到下一个结点
    linkedQueue->qFront->next = retNode->next;
    // 如果目前出队的这个结点是尾结点指向的结点, 那么说明这个结点出队之后,队列为空
    if (linkedQueue->qRear == retNode) {
        // 头结点本身是一个结点,该结点的地址是不指向有效数据的
        // 此时将尾结点的值改为头结点的值,用以表示队列已经空了
        linkedQueue->qRear = linkedQueue->qFront;
    }
    return retNode->data;
}

int IsEmptyQueue(LinkedQueue * linkedQueue) {
    if (linkedQueue->qFront == linkedQueue->qRear) {
        return 1;
    } else {
        return 0;
    }
}
