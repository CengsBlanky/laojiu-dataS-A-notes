#include "SeqStack.h"

void InitSeqStack (SeqStack * stack) {
    stack->length = 0;
    stack->top = -1;
}

int PushSeqStack (SeqStack * stack, DataType * data) {
    if (stack->length == MAX_STACK_SIZE) {
        printf("Stack full\n");
        return FALSE;
    }
    stack->top++;
    stack->length++;
    if (data) {
        stack->datas[stack->top] = *data;
    }
    return OK;
}

int PopSeqStack (SeqStack * stack, DataType * popData) {
    if (stack->top == -1) {
        printf("Stack empty\n");
        return FALSE;
    }
    *popData = stack->datas[stack->top];
    stack->top--;
    stack->length--;
    return OK;
}

int GetSeqTop (SeqStack * stack, DataType * top) {
    if (stack->top == -1) {
        printf("stack empty\n");
        return FALSE;
    } 
    *top = stack->datas[stack->top];
    return OK;
}

// get stack length
int GetSeqStackLength (SeqStack * stack) {
    return stack->length;
}

// clear stack
void ClearStack (SeqStack * stack) {
    stack->length = 0;
    stack->top = -1;
}

// print stack from top
void printSeqStackFromTop (SeqStack * stack) {
    int top = stack->top;
    while (top >= 0) {
        printf("id: %d\tname: %s\t--%p\n", stack->datas[top].id, stack->datas[top].name, stack->datas + top);
        top--;
    }
}