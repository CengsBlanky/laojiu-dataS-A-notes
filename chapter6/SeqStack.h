#include "DataType.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 255
#define OK 1
#define FALSE 0

typedef struct SeqStack {
    DataType datas[MAX_STACK_SIZE];
    int top;
    int length;
}SeqStack;

// init
void InitSeqStack (SeqStack * stack);

// push and get the pushed data
int PushSeqStack (SeqStack * stack, DataType * data);

// pop and get pop data
int PopSeqStack (SeqStack * stack, DataType * data);

// get top data
int GetSeqTop (SeqStack * stack, DataType * top);

// get stack length
int GetSeqStackLength (SeqStack * stack);

// clear stack
void ClearStack (SeqStack * stack);

// print stack from top
void printSeqStackFromTop (SeqStack * stack);