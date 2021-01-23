#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

// init datalist
void initDataElement(SeqList *list, ElementType * elements, int length);

// insert into datalist
void insertElement(SeqList *list, ElementType element, int index);

// print datalist
void printDataList(SeqList *list, int length);

// delete element
ElementType * deleteElement(SeqList *list, int index);
