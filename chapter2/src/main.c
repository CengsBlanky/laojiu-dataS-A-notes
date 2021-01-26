#include "LinkList.h"

void testLinkList();

ElementType elements[] = {
    {1, "三国演义"},
    {2, "西游记"},
    {3, "红楼梦"},
    {4, "水浒传"},
};

ElementType insertSingleElement = {5, "金瓶梅"};

int main(int argc, char const *argv[])
{
    // testDataList();
    testLinkList();
    return 0;
}

void testLinkList () {
    LinkList list;
    list.header = NULL;
    list.length = 0;
    LinkList *listptr = &list;
    // init 
    initLinkList(listptr, elements, sizeof(elements) / sizeof(elements[0]));
    puts("After init:");
    printLinkList(listptr);

    ElementType insertData = {12, "儒林外传"};
    int position = 5;
    insertNode(listptr, position, insertData);
    puts("After insert:");
    printLinkList(listptr);

    int deletePosition = 1;
    ElementType *deleteData = deleteNode(listptr, deletePosition);
    printf("After delete node %dth, LinkList are:\n", deletePosition);
    printLinkList(listptr);
    printf("delete node is:\nid: %d\tname: %s --> %p\n", deleteData->id, deleteData->name, deleteData);
    free(deleteData);

    Node * getNode;
    int getPosition = 4;
    getNode = getLinklistNode(listptr, getPosition);
    printf("get node is:\nid: %d\tname: %s --> %p\n", getNode->data.id, getNode->data.name, getNode);
    free(getNode);

    printf("list is empty? %s\n", isEmpty(listptr) == 1 ? "yes" : "no");
    clearList(listptr);
    puts("After clear list:");
    printLinkList(listptr);
    printf("list is empty? %s\n", isEmpty(listptr) == 1 ? "yes" : "no");
}