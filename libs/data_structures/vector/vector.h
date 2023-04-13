#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE_MAX 1000000

typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector creatVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

#endif //VECTOR_VECTOR_H
