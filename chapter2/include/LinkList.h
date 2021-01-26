#include "DataElement.h"
#include <stdio.h>
#include <stdlib.h>

// define linklist node
typedef struct Node{
    ElementType data;
    struct Node *next;
}Node;

// define header node
typedef struct LinkList{
    Node *header;
    int length;
}LinkList;

// init LinkList
void initLinkList (LinkList *list, ElementType *datas, int length);

//insert node
void insertNode(LinkList *list, int position, ElementType data);

// print LinkList
void printLinkList(LinkList * list);

// delete node
ElementType * deleteNode(LinkList *list, int position);

// get node
Node * getLinklistNode(LinkList *list, int position);

// is list empty
int isEmpty (LinkList * list);

// clear linklist
void clearList(LinkList * list);