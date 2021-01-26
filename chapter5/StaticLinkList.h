#include "DataType.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SLL_SIZE 10

typedef struct StaticLinkList {
    DataType data;
    int cursor;
}StaticLinkList[MAX_SLL_SIZE];

// init
void initSLL (StaticLinkList slList);

// insert
void insertSLL (StaticLinkList slList, DataType * data, int position);

// print
void printSLL (StaticLinkList slLsit);

// print data
void printSLLDatas (StaticLinkList slList);

//print all
void printAll (StaticLinkList slList);

// get length
int getSLLLength (StaticLinkList slList);

// delet by position
void deleteByPosition (StaticLinkList slList, int position);