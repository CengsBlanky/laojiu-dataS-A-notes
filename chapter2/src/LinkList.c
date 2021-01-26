#include "LinkList.h"

#define TRUE 1
#define FALSE 0

void initLinkList (LinkList *list, ElementType *datas, int length) {
    for (int i = 0; i < length; i++) {
        insertNode(list, i + 1, *datas++);
    }
}

void insertNode (LinkList *list, int position, ElementType data) {
    if (position < 0 || position > list->length + 1) {
        printf("position out of range!!!\n");
    }
    // 创建一个节点作为要插入的节点
    Node * insertNode = malloc(sizeof(Node));
    insertNode->data = data;
    insertNode->next = NULL;
    Node * beforeNode = list->header;
    if (position == 1) {
        insertNode->next = beforeNode;
        list->header = insertNode;
        list->length++;
        return;
    }
    for (int i = 1; beforeNode && i < position - 1; i++) {
        beforeNode = beforeNode->next;
    }
    if (beforeNode) {
        insertNode->next = beforeNode->next;
        beforeNode->next = insertNode;
        list->length++;
    }
}

void printLinkList (LinkList *list) {
    if (isEmpty(list)) {
        puts("empty list~");
        return;
    }
    Node *temp = list->header;
    do {
        printf("id: %d\tname: %s --> %p\n", temp->data.id, temp->data.name, temp);
    } while (temp = temp->next);
}

ElementType * deleteNode(LinkList *list, int position) {
    Node *deleteNode = NULL;
    ElementType *deletedData = malloc(sizeof(ElementType));
    if (position < 0 || position > list->length) {
        printf("position out of range!\n");
        return NULL;
    }
    if (position == 1) {
        deleteNode = list->header;
        list->header = list->header->next;
        list->length--;
        *deletedData = deleteNode->data;
        free(deleteNode);
        return deletedData;
    }
    Node * beforeNode = list->header;
    for (int i = 1; i < position - 1 && beforeNode; i++)
    {
        beforeNode = beforeNode->next;
    }
    if (beforeNode) {
        deleteNode = beforeNode->next;
        beforeNode->next = deleteNode->next;
        list->length--;
    }
    *deletedData = deleteNode->data;
    free(deleteNode);
    return deletedData;
}

Node * getLinklistNode(LinkList *list, int position) {
    Node * foundNode = list->header;
    for (int i = 1; i < position; i++) {
        foundNode = foundNode->next;
    }
    return foundNode;
}

int isEmpty (LinkList * list) {
    return list->length == 0 ? TRUE : FALSE;
}

void clearList(LinkList * list) {
    Node * currentNode = list->header;
    Node * nextNode; 
    while (currentNode) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    list->header = NULL;
    list->length = 0;
}