#include <stdio.h>
#include <stdlib.h>
#include "DataType.h"

#define OK 1
#define FALSE 0

typedef struct StackNode {
    DataType data;
    struct StackNode * next;
}StackNode;

typedef struct LinkStack {
    StackNode * top;
    int length;
}LinkStack;

// init
void InitStack (LinkStack * stack);

// insert into link stack
int PushLinkStack (LinkStack * stack, DataType * data);

// delete data in link stack
int PopLinkStack (LinkStack * stack, DataType * deletedData);

// get top
int GetTop (LinkStack * stack, DataType * getData);

// print
void PrintStack (LinkStack * stack);

// clear stack
void ClearStack (LinkStack * stack);
