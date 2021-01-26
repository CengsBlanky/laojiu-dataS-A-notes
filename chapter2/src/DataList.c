#include "DataList.h"

#define TRUE 1
#define FALSE 0

// init datalist
void initDataElement(SeqList * list, ElementType * elements, int length)
{
    // if length exceed the MAX_LENGTH, return
    if (length > MAX_SIZE) {
        printf("exceeds the MAX_SIZE: %d, please check you data length\n", MAX_SIZE);
        return;
    }
    list->length = length;
    // user for loop to fullfill the list
    for (int i = 0; i < length; i++)
    {
        list->datas[i] = *(elements + i);
    }
    
}

// insert into datalist
void insertElement(SeqList * list, ElementType element, int index)
{
    // make sure index can not be larger than list length
    if (index > list->length) {
        printf("index out of range\n");
        return;
    }
    // make sure length would exceeds the MAX_SIZE
    if (list->length + 1 > MAX_SIZE) {
        printf("no more space!\n");
        return;
    }
    for (int i = list->length; i > index; i--)
    {
        list->datas[i] = list->datas[i - 1];
    }
    list->length++;
    list->datas[index] = element;
}

/** @param list
 *  @param index
 *  @return ElementType
 */
ElementType * deleteElement (SeqList *list, int index) {
    if (index > list->length - 1 || index < 0) {
        printf("index out of range!\n");
        exit(1);
    }    
    // 一定记得用完之后free
    ElementType *tempElement = malloc(sizeof(ElementType));
    *tempElement = getElement(list, index);
    for (int i = index; i < list->length - 1; i++)
    {
        list->datas[i] = list->datas[i + 1];
    }
    list->length--;
    return tempElement;
}
// print datalist
void printDataList(SeqList * list, int length)
{
    for (int i = 0; i < length; i++) {
        printf("id: %d\tname: %s\n", list->datas[i].id, list->datas[i].name);
    }
    
}

// get index element
ElementType getElement (SeqList *list, int index) {
    if (index < 0 || index > list->length - 1) {
        printf("index out of bound!\n");
        exit(1);
    }
    ElementType ret_val = list->datas[index];
    return ret_val;
}

// get elements length
int getElementLength (SeqList *list) {
    return list->length;
}

// clear elements
void clearElements (SeqList *list) {
    if (list->length == 0) {
        printf("elements is already empty!");
        return;
    }
    list->length = 0;
}

// is empty
int isEmpty (SeqList *list) {
    return list->length == 0 ? TRUE : FALSE;
}