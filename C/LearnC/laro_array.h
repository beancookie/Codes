//
// Created by larobyo on 21/02/2017.
//

#ifndef LEARNC_ARRAY_H
#define LEARNC_ARRAY_H

// the array
typedef struct array {
    int *array;
    int size;
} Array;

Array laro_array_create();
int *laro_array_at(Array *array, int index);
int laro_array_size(Array *array);
void laro_array_increase(Array *array, int more_size);
void laro_array_free(Array *array);

#endif //LEARNC_ARRAY_H
