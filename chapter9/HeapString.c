#include "HeapString.h"

void generatePrefixTable (HeapString * string, int * table);

void InitString(HeapString * hString, char * str) {
    hString->length = strlen(str);
    hString->str = malloc(sizeof(str));
    printf("string len is: %d\nstring pointer is: %p\n", hString->length, hString->str);
    for (int i = 0; i < hString->length; i++) {
        hString->str[i] = str[i];
    }
}

status CompareString(HeapString * targetStr, HeapString * comStr, int index) {
    puts("====================");
    PrintString(targetStr);
    PrintString(comStr);
    puts("====================");
    int j = 0;
    while (index < targetStr->length && j < comStr->length) {
        printf("%c compare %c\n", targetStr->str[index], comStr->str[j]);
        if (targetStr->str[index] == comStr->str[j]) {
            index++;
            j++;
        } else {
            index = index - j + 1;
            j = 0;
        }
        printf("index: %d\tj: %d\n", index, j);
        puts("===========================");
    }
    if (j == comStr->length) {
        return index - j;
    } else {
        return NONE;
    }
}

void PrintString(HeapString * targetStr) {
    for (int i = 0; i < targetStr->length; i++) {
        putchar(targetStr->str[i]);
    }
    puts("");
}

void KMPCompare (HeapString * string, HeapString * pattern) {

}

void generatePrefixTable (HeapString * string) {
    int i = 2;
    int * prefix = malloc(sizeof(int) * string->length);
    prefix[0] = 0;
    int k = 0;
    while (i < string->length) {
        if (string->str[i] == string->str[k]) {
            k++;
            prefix[i] = k;
            i++;
        } else {
            k = prefix[k];
        }
    }
}