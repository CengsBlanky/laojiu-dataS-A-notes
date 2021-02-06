#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

#include "BinaryTree.h"

typedef struct BinaryTreeNode BinaryTreeNode;

typedef struct StackFrame {
    BinaryTreeNode * data;
    struct StackFrame * next;
}StackFrame;

typedef struct LinkStack {
    StackFrame * top;
    int length;
}LinkStack;

void InitLinkStack (LinkStack * stack);

void Push (LinkStack * stack, BinaryTreeNode * node);

int Pop (LinkStack * stack, BinaryTreeNode * * nodePoint);

int IsEmpty (LinkStack * stack);

#endif