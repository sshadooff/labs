#ifndef MAIN_C_VECTORVOID_H
#define MAIN_C_VECTORVOID_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <limits.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

vectorVoid creatVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

#endif //MAIN_C_VECTORVOID_H