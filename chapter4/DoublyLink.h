#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataType.h"

typedef struct DoublyNode {
    DataType data;
    struct DoublyNode * prev;
    struct DoublyNode * next;
}DoublyNode;

typedef struct DoublyLink {
    DoublyNode * header;
    int length;
}DoublyLink;

// init
void initList (DoublyLink * list, DataType * datas, int length);

// insert list
void insertListByPos (DoublyLink * list, DataType * datas, int position);

// printList
void printList (DoublyLink * list);

//print list reverse
void printListReverse (DoublyLink * list);

// delete by position
DataType * deleteByPos (DoublyLink * list, int position);

// get by position
DataType * getByPos (DoublyLink * list, int position);

// is empty
int isEmpty (DoublyLink * list);

// clear
void clearDoublyList (DoublyLink * list);
