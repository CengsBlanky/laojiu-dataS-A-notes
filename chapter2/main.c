#include "DataList.h"

void testDataList();

ElementType elements[] = {
    {1, "三国演义"},
    {2, "西游记"},
    {3, "红楼梦"},
    {4, "水浒传"},
};

ElementType insertSingleElement = {5, "金瓶梅"};

int main(int argc, char const *argv[])
{
    testDataList();
    return 0;
}

void testDataList ()
{
    SeqList list;
    initDataElement(&list, elements, 4);
    printDataList(&list, (&list)->length);
    puts("After insert element:");
    insertElement(&list, insertSingleElement, 2);
    printDataList(&list, (&list)->length);
}