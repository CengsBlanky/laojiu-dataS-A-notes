#include "DataList.h"

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
        return;
    }    
    list->length--;
    
}
// print datalist
void printDataList(SeqList * list, int length)
{
    for (int i = 0; i < length; i++) {
        printf("id: %d\tname: %s\n", list->datas[i].id, list->datas[i].name);
    }
    
}
