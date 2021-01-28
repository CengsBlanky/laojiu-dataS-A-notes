#include "SeqQueue.h"

void testQueue();

DataType endata = {1, "zhangsan"};

DataType enDatas[] = {
    {1, "wansda"},
    {2, "wansda"},
    {3, "wansda"},
    {4, "wansda"},
    {5, "wansda"}
};

int main(int argc, char const *argv[])
{
    testQueue();
    return 0;
}

void testQueue() {
    SeqQueue * queue = malloc(sizeof(SeqQueue));
    InitSeqQueue(queue);

    Enqueue(queue, &endata);
    Enqueue(queue, enDatas);
    Enqueue(queue, enDatas + 1);
    Enqueue(queue, enDatas + 2);

    DataType * deData = malloc(sizeof(DataType));
    Dequeue(queue, deData);

    PrintQueue(queue);
}