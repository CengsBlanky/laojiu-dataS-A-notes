#include "CircularLinkedList.h"

// init
void initCircularList (CircularLinkedList * list, DataElement * datas, int length) {
    for (int i = 0; i < length; i++) {
        insertData(list, &(datas[i]), i + 1);
    }
}

// insert
void insertData (CircularLinkedList * list, DataElement * data, int position) {
    if (position < 1 || position > list->length + 1) {
        printf("position out of range!\n");
        return;
    }

    Node * insertNode = malloc(sizeof(Node));
    insertNode->element = *data;
    insertNode->next =NULL;
    Node * preNode = list->header;

    if (position == 1) {
        if (list->header == NULL) {
            insertNode->next = insertNode;
        } else {
            Node * lastNode = list->header;
            insertNode->next = list->header;
            while (lastNode->next != list->header) {
                lastNode = lastNode->next;
            }
            lastNode->next = insertNode;
        }
        list->header = insertNode;
        list->length++;
        return;
    }

    for (int i = 1; i < position - 1 && preNode; i++) {
        preNode = preNode->next;
    }
    if (preNode) {
        insertNode->next = preNode->next;
        preNode->next = insertNode;
        list->length++;
    }
}

// get by position
DataElement * getByPosition (CircularLinkedList * list, int position) {
    Node * foundNode = list->header;
    for (int i = 1; i < position; i++) {
        foundNode = foundNode->next;
    }
    DataElement * foundData = &foundNode->element;
    return foundData;
}

DataElement * getById (CircularLinkedList * list, int id) {
    Node * circularNode = list->header;
    DataElement * ret_data;
    do {
        if (id == circularNode->element.id) {
            break;
        }
        circularNode = circularNode->next;
    } while (circularNode != list->header);
    ret_data = &circularNode->element;
    return ret_data;
}

// delete by position
void deleteByPosition (CircularLinkedList * list, int position) {
    if (position < 1 || position > list->length) {
        printf("invalid position!\n");
        return;
    }

    Node * preNode = list->header;
    Node * lastNode = list->header;
    Node * deleteNode = NULL;
    do {
        lastNode = lastNode->next;
    } while (lastNode != list->header);
    if (position == 1) {
        deleteNode = list->header;
        list->header = deleteNode->next;
        lastNode->next = deleteNode->next;
        free(deleteNode);
        list->length--;
    }

    for (int i = 1; i < position - 1 && preNode; i++) {
        preNode = preNode->next;
    }
    if (preNode) {
        deleteNode = preNode->next;
        preNode->next = deleteNode->next;
        list->length--;
        free(deleteNode);
    }
}

// delete by id
void deleteById (CircularLinkedList * list, int id) {
    Node * deleteNode = list->header;
    Node * preDeleteNode = list->header;
    Node * lastNode = list->header;
    while (lastNode->next != list->header) {
        lastNode = lastNode->next;
    }
    if (deleteNode->element.id == id) {
        lastNode->next = deleteNode->next;
        list->header = deleteNode->next;
        free(deleteNode);
        list->length--;
        return;
    }

    do {
        deleteNode = preDeleteNode->next;
        if (deleteNode->element.id == id) {
            preDeleteNode->next = deleteNode->next;
            free(deleteNode);
            list->length--;
        }
    }while (deleteNode != list->header);

}

// is empty
int isEmpty (CircularLinkedList * list) {
    return list->length == 0 ? 1 : 0;
}

// clear
void clearList (CircularLinkedList * list) {
    Node * currentNode = list->header;
    Node * nextNode;
    for (int i = 0; i < list->length; i++) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    list->header = NULL;
    list->length = 0;
}

void printList(CircularLinkedList * list) {
    Node * node = list->header;
    if (node != NULL) {
        do {
            printf("id: %d\tname: %s --> %p\n", node->element.id, node->element.name, node);
            node = node->next;
        } while (node != list->header);
    }
}