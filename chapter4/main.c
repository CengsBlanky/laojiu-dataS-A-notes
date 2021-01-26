#include "DoublyLink.h"

void testDoublyList();

DataType initDatas[] = {
    {1, "三国演义"},
    {2, "红楼梦"},
    {3, "水浒传"},
    {4, "西游记"}
};

int main(int argc, char const *argv[])
{
    testDoublyList();
    return 0;
}

void testDoublyList () {
    DoublyLink listStr = {NULL, 0};
    DoublyLink * list = &listStr;
    // init
    int arrayLength = sizeof(initDatas) / sizeof(initDatas[0]);
    initList(list, initDatas, arrayLength);
    printList(list);

    // insert
    DataType insertDataTest = {12, "金瓶梅"};
    insertListByPos(list, &insertDataTest, 1);
    puts("after insert");
    printList(list);
    // puts("print list reversely:");
    // printListReverse(list);

    // delete node by position
    int deletePosition = 5;
    DataType * deletedData = deleteByPos(list, deletePosition);
    printf("deleted data is:\nid: %d\tname: %s\t-- %p\n", deletedData->id, deletedData->name, deletedData);
    printf("after delete position: %d\n", deletePosition);
    printList(list);
    
    // get by position
    int getPosition = list->length;
    DataType * getData = getByPos(list, getPosition);
    printf("position %d data is:\nid: %d\tname: %s\t-- %p\n", getPosition, getData->id, getData->name, getData);

    // clear
    printf("is list empty? %s\n", isEmpty(list) == 1 ? "yes" : "no");
    clearDoublyList(list);
    printList(list);
    printf("is list empty? %s\n", isEmpty(list) == 1 ? "yes" : "no");
}