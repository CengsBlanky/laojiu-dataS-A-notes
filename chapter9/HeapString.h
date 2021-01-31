#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define FALSE 0
#define NONE -1
#define ERROR -0
#define OVERFLOW -1

typedef int status;

typedef struct HeapString {
    char * str;
    int length;
}HeapString;

void InitString(HeapString * hString, char * str);

status CompareString(HeapString * targetStr, HeapString * comStr, int index);

status SubString(HeapString * targetStr, int index);

void PrintString(HeapString * targetStr);

void KMPCompare (HeapString * string, HeapString * pattern);