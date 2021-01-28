 #include "LinkStack.h"

// init
void InitStack (LinkStack * stack) {
    stack->length = 0;
    stack->top = NULL;
}

// insert into link stack
int PushLinkStack (LinkStack * stack, DataType * data) {
    // allocate memory for node
    StackNode * pushNode = malloc(sizeof(StackNode));
    if (!pushNode) {
        printf("Not enough memory!\n");
        return FALSE;
    }
    pushNode->data = *data;
    pushNode->next = NULL;
    StackNode * top = stack->top;
    pushNode->next = top;
    stack->top = pushNode;
    stack->length++;
    return OK;
}

// delete data in link stack
int PopLinkStack (LinkStack * stack, DataType * deletedData) {
    if (stack->length == 0) {
        printf("empty stack!\n");
        return FALSE;
    }
    StackNode * deleteNode = stack->top;
    *deletedData = deleteNode->data;
    stack->top = deleteNode->next;
    free(deleteNode);
    stack->length--;
    return OK;
}

// get top
int GetTop (LinkStack * stack, DataType * getData) {
    if (stack->length == 0) {
        printf("empty stack!\n");
        return FALSE;
    }
    *getData = stack->top->data;
    return OK;
}

// print
void PrintStack (LinkStack * stack) {
    StackNode * node = stack->top;
    while (node) {
        printf("id: %d\tname: %s\t%p\n", node->data.id, node->data.name, node);
        node = node->next;
    }
}

// clear stack
void ClearStack (LinkStack * stack) {
    StackNode * node = stack->top;
    StackNode * temp;
    while (node) {
        temp = node;
        free(node);
        node = temp->next;
    }
    stack->length = 0;
    stack->top = NULL;
}