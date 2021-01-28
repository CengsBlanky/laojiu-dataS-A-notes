#include <stdio.h>
#include <stdlib.h>
#include "DataType.h"

#define MAX_SIZE 255

#define OK 1
#define FALSE 0

typedef struct SeqQueue {
    DataType datas[MAX_SIZE];
    int front;
    int rear;
}SeqQueue;

// init
void InitSeqQueue (SeqQueue * queue);

// enqueue
int Enqueue (SeqQueue * queue, DataType * data);

// dequeue
int Dequeue (SeqQueue * queue, DataType * data);

// is empty
int isEmpty (SeqQueue * queue);

// is full
int isFull (SeqQueue * queue);

// print
void PrintQueue (SeqQueue * queue);