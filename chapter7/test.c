#include "LinkStack.h"

void testLinkStack ();

DataType datas[] = {
    {1, "spring"},
    {2, "summer"},
    {3, "autumn"},
    {4, "winter"}
};

int main(int argc, char const *argv[])
{
    testLinkStack();
    return 0;
}


void testLinkStack () {
    LinkStack * stack = malloc(sizeof(LinkStack));
    InitStack(stack);

    // push
    PushLinkStack(stack, &datas[0]);
    PushLinkStack(stack, &datas[2]);

    puts("---------------------");
    PrintStack(stack);
    puts("---------------------");
    
    DataType * topData = malloc(sizeof(DataType));
    GetTop(stack, topData);
    printf("top data is:\nid: %d\tname:%s\t%p\n", topData->id, topData->name, topData);

    // Pop
    DataType * deletedData = malloc(sizeof(DataType));
    PopLinkStack(stack, deletedData);

    puts("---------------------");
    PrintStack(stack);
    puts("---------------------");

    PushLinkStack(stack, &datas[1]);
    PushLinkStack(stack, &datas[2]);
    PushLinkStack(stack, &datas[3]);

    puts("===================");
    PrintStack(stack);
    puts("===================");

    puts("clear stack...");
    ClearStack(stack);

    PrintStack(stack);
}