#include "DataElement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    DataElement element;
    struct Node *next;
}Node;

typedef struct CircularLinkedList {
    int length;
    Node * header;
}CircularLinkedList;

// init
void initCircularList (CircularLinkedList * list, DataElement * datas, int length);

// insert
void insertData (CircularLinkedList * list, DataElement * data, int position);

// get by position
DataElement * getByPosition (CircularLinkedList * list, int position);
// get by id
DataElement * getById (CircularLinkedList * list, int id);

// delete by position
void deleteByPosition (CircularLinkedList * list, int position);

// delete by id
void deleteById (CircularLinkedList * list, int id);

// is empty
int isEmpty (CircularLinkedList * list);

// clear
void clearList (CircularLinkedList * list);

// print list
void printList(CircularLinkedList * list);