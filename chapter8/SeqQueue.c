#include "SeqQueue.h"

// init
void InitSeqQueue (SeqQueue * queue) {
    queue->front = 0;
    queue->rear = 0;
}

// enqueue
int Enqueue (SeqQueue * queue, DataType * data) {
    if (isFull(queue)) {
        printf("queue is full.\n");
        return FALSE;
    }
    queue->datas[queue->rear] = *data;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return OK;
}

// dequeue
int Dequeue (SeqQueue * queue, DataType * data) {
    if (isEmpty(queue)) {
        printf("empty queue.\n");
        return FALSE;
    }
    *data = queue->datas[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return OK;
}

// is empty
int isEmpty (SeqQueue * queue) {
    return queue->rear == queue->front;
}

// is full
int isFull (SeqQueue * queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// print
void PrintQueue (SeqQueue * queue) {
    if (isEmpty(queue)) {
        return;
    }
    int index = queue->front;

    do {
        printf("id: %d\tname: %s\t%p\n", queue->datas[index].id, queue->datas[index].name, &queue->datas[index]);
        index = (index + 1) % MAX_SIZE;
    } while (index != queue->rear);
}