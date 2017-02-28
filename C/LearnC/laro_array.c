//
// Created by larobyo on 21/02/2017.
//

#include "laro_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedef struct array {
//    int *array;
//    int size;
//} Array;

#define BLOCK_SIZE 5
#define INIT_SIZE 10

Array laro_array_create()
{
    Array arrar;
    arrar.size = INIT_SIZE;
    arrar.array = (int*)malloc(sizeof(int) * INIT_SIZE);
    return arrar;
}

int *laro_array_at(Array *array, int index)
{
    if (index >= array->size) {
        array_increase(array, (index/BLOCK_SIZE + 1) * BLOCK_SIZE - array->size);
    }
    return &(array->array[index]);
}

int laro_array_size(Array *array)
{
    return array->size;
}

void laro_array_increase(Array *array, int more_size)
{
    int *new_array = (int*)malloc(sizeof(int) * (array->size + more_size));
    memcpy(new_array, array->array, sizeof(int) * array->size);
    free(array->array);
    array->array = new_array;
    array->size += more_size;
}

void laro_array_free(Array *array)
{
    free(array->array);
    array->size = 0;
    array->array = NULL;
}

