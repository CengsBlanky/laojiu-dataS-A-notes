#include "DoublyLink.h"

void initList (DoublyLink * list, DataType * datas, int length) {
    for (int i = 0; i < length; i++) {
        insertListByPos(list, datas + i, i + 1);
    }
}

void insertListByPos (DoublyLink * list, DataType * data, int position) {
    if (position < 1 || position > list->length + 1) {
        printf("position out of range");
        exit(1);
    }
    // allocate a node
    DoublyNode * node = malloc(sizeof(DoublyNode));
    node->data = *data;
    node->prev = NULL;
    node->next = NULL;    
    if (list->header == NULL) {
        list->header = node;
        list->length++;
        return;
    }
    DoublyNode * preNode = list->header;
    if (position == 1) {
        node->next = preNode;
        preNode->prev = node;
        list->header = node;
        list->length++;
        return;
    }

    for (int i = 1; i < position - 1 && preNode; i++) {
        preNode = preNode->next;
    }
    if (preNode) {
        node->next = preNode->next;
        if (preNode->next) {
            preNode->next->prev = node;
        }
        preNode->next = node;
        node->prev = preNode;
        list->length++;
    }
}

void printList (DoublyLink * list) {
    if (list->header == NULL)
        return;
    DoublyNode * node = list->header;
    for (int i = 0; i < list->length; i++) {
        printf("id: %d\tname: %s\t-- %p\n", node->data.id, node->data.name, node);
        node = node->next;
    }
}

void printListReverse (DoublyLink * list) {
    if (list->header == NULL)
        return;
    DoublyNode * lastNode = list->header;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    for (int i = 0; i < list->length; i++) {
        printf("id: %d\tname: %s\t-- %p\n", lastNode->data.id, lastNode->data.name, lastNode);
        lastNode = lastNode->prev;
    }
}

DataType * deleteByPos (DoublyLink * list, int position) {
    if (position < 1 || position > list->length) {
        printf("position out of range\n");
        exit(1);
    }
    DoublyNode * preNode = list->header;
    DataType * deleteDataPtr = malloc(sizeof(DataType));
    *deleteDataPtr = preNode->data;
    if (position == 1) {
        list->header = preNode->next;
        preNode->next->prev = NULL;
        free(preNode);
        list->length--;
        return deleteDataPtr;
    }

    for (int i = 1; i < position - 1 && preNode; i++) {
        preNode = preNode->next;
    }
    printf("preNode: %p\n", preNode);
    if (preNode) {
        DoublyNode * deleteNode = preNode->next;
        preNode->next = deleteNode->next;
        if (deleteNode->next) {
            deleteNode->next->prev = preNode;
        }
        *deleteDataPtr = deleteNode->data;
        free(deleteNode);
        list->length--;
    }
    return deleteDataPtr;
}

DataType * getByPos (DoublyLink * list, int position) {
    DoublyNode * getNode = list->header;
    for (int i = 1; i < position; i++) {
        getNode = getNode->next;
    }
    DataType * retData = malloc(sizeof(DataType));
    *retData = getNode->data;
    return retData;
}

int isEmpty (DoublyLink * list) {
    return list->length == 0 ? 1 : 0;
}

void clearDoublyList (DoublyLink * list) {
    DoublyNode * currentNode = list->header;
    DoublyNode * nextNode;
    while (currentNode) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    list->header = NULL;
    list->length = 0;
}