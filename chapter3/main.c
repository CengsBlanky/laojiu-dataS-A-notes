#include "CircularLinkedList.h"

void testCircularLinkedList();

DataElement datas[] = {
    {1, "三国演义"},
    {2, "水浒传"},
    {3, "梁山伯与祝英台"},
    {4, "红楼梦"},
    {5, "西游记"}
};

DataElement insertDemo = {100, "奥特曼大战变形金刚"};

int main(int argc, char const *argv[])
{
    printf("start testing\n");
    testCircularLinkedList();
    return 0;
}


void testCircularLinkedList () {
    // init
    CircularLinkedList clist = {0, NULL};
    CircularLinkedList * list = &clist;
    list->length = 0;
    list->header = NULL;
    int initLength = sizeof(datas) / sizeof(datas[0]);
    int insertPosition = 1;
    int getPosition = 4;
    int getId = 100;
    int deletePosition = 3;

    // init
    printf("init length: %d\n", initLength);
    initCircularList(list, datas, initLength);
    printList(list);

    // insert
    insertData(list, &insertDemo, insertPosition);
    puts("After insert");
    printList(list);

    // get by position
    DataElement *getDataByPosition =getByPosition(list, getPosition);
    puts("what we have:");
    printf("id: %dname: %s --> %p\n", getDataByPosition->id, getDataByPosition->name, getDataByPosition);
    // get by id
    DataElement *getDataById = getById(list, getId);
    printf("id: %dname: %s --> %p\n", getDataById->id, getDataById->name, getDataById);

    puts("Now delete");
    deleteByPosition(list, deletePosition);
    puts("after delete:");
    printList(list);
    deleteById(list, getId);
    puts("After delete:");
    printList(list);

    printf("list length: %d\n", list->length);

    printf("is list empty? %s\n", isEmpty(list) == 1 ? "yes" : "no");
    clearList(list);
    puts("list cleared");
    printf("is list empty? %s\n", isEmpty(list) == 1 ? "yes" : "no");
    printList(list);
}