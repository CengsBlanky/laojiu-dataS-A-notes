#include "SeqStack.h"

void TestSeqStack();

int main(int argc, char const *argv[])
{
    TestSeqStack();
    return 0;
}

void TestSeqStack () {
    SeqStack * stack = malloc(sizeof(SeqStack));
    InitSeqStack(stack);

    DataType pushData = {1, "meguri"};
    PushSeqStack(stack, &pushData);
    printSeqStackFromTop(stack);
    PopSeqStack(stack, &pushData);
    puts("After pop:");
    printSeqStackFromTop(stack);
    for (int i = 0; i < 10; i++) {
        PushSeqStack(stack, &pushData);
    }
    puts("10 added:");
    printSeqStackFromTop(stack);
    printf("stack length is %d\n", GetSeqStackLength(stack));

}