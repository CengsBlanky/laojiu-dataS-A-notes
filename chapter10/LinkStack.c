#include "LinkStack.h"

void InitLinkStack (LinkStack * stack) {
    stack->length = 0;
    stack->top = NULL;
}

void Push (LinkStack * stack, BinaryTreeNode * node) {
    StackFrame * frame = malloc(sizeof(StackFrame));
    frame->data = node;
    frame->next = stack->top;
    stack->top = frame;
    stack->length++;
}

int Pop (LinkStack * stack, BinaryTreeNode * * nodePoint) {
    if (IsEmpty(stack)) {
        return 0;
    }
    StackFrame * popFrame = stack->top;
    stack->top = popFrame->next;
    *nodePoint = popFrame->data;
    stack->length--;
    free(popFrame);
    return 1;
}

int IsEmpty (LinkStack * stack) {
    return stack->length == 0 ? 1 : 0;
}