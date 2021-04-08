#ifndef ELEMENTTYPE_H_INCLUDED
#define ELEMENTTYPE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024
#define NAME_SIZE 255

typedef struct {
    int id;
    char name[NAME_SIZE];
}ElementType;

#endif
