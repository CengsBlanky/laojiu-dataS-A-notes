#include "StaticLinkList.h"

void testStaticLinkList ();

int main(int argc, char const *argv[])
{
    testStaticLinkList();
    return 0;
}

void testStaticLinkList () {
    StaticLinkList slList;
    initSLL(slList);

    DataType * insertDataDemo = malloc(sizeof(DataType));
    insertDataDemo->id = 1;
    insertDataDemo->name = "zhangsan";
    insertSLL(slList, insertDataDemo, 1);
    printAll(slList);
    puts("======================");

    puts("insert again");
    insertDataDemo->id = 2;
    insertDataDemo->name = "lisi";
    insertSLL(slList, insertDataDemo, 2);
    puts("======================");
    printAll(slList);
    puts("======================");

    puts("insert at first");
    puts("======================");
    insertDataDemo->id = 0;
    insertDataDemo->name = "wangwu";
    insertSLL(slList, insertDataDemo, 1);
    printAll(slList);

    deleteByPosition(slList, 2);
    puts("after delete:");
    printAll(slList);
}