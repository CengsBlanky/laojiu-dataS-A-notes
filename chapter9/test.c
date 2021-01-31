#include "HeapString.h"

void testString();

int main(int argc, char const *argv[])
{
    testString();
    return 0;
}

void testString() {
    HeapString * initStr = malloc(sizeof(HeapString));
    InitString(initStr, "aaaaaaaaaaaaaaaaabdee");
    PrintString(initStr);

    HeapString * comStr = malloc(sizeof(HeapString));
    InitString(comStr, "bdae");

    int point = CompareString(initStr, comStr, 0);
    printf("point is:%d\n", point);
}