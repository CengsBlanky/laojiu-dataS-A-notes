#include "LinkQueue.h"

void InitQueue (LinkQueue * queue) {
    queue->head = malloc(sizeof(QueueNode));
    queue->head->next = NULL;
    queue->tail = queue->head;
}

void EnQueue (LinkQueue * queue, BinaryTreeNode * node) {
    QueueNode * enNode = malloc(sizeof(QueueNode));
    enNode->data = node;
    enNode->next = NULL;
    queue->tail->next = enNode;
    queue->tail = enNode;
}

BinaryTreeNode * DeQueue (LinkQueue * queue) {
    BinaryTreeNode * node = NULL;
    if (IsEmptyQueue(queue)) return NULL;
    QueueNode * deNode = queue->head->next;
    node = deNode->data;
    queue->head->next = deNode->next;
    if (deNode->next == NULL) {
        queue->tail = queue->head;
    }
    free(deNode);
    return node;
}

int IsEmptyQueue (LinkQueue * queue) {
    return queue->head == queue->tail ? 1 : 0;
}

void PrintQueue (LinkQueue * queue) {
    QueueNode * node = queue->head->next;
    BinaryTreeNode * data = node->data;
    while (!IsEmptyQueue(queue)) {
        puts("not empty");
        printf("[%d, %s]->", data->data.id, data->data.name);
        data = DeQueue(queue);
    }
    puts("");
}