#ifndef MAIN_C_VECTORVOID_H
#define MAIN_C_VECTORVOID_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
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

bool isEmptyV(vectorVoid *v);

bool isFullV(vectorVoid *v);

void getVectorValueV(vectorVoid *v, size_t index, void *destination);

void test_getVectorValueV_emptyVector();

void setVectorValueV(vectorVoid *v, size_t index, void *source);

void test_setVectorValueV_emptyVector();

void popBackV(vectorVoid *v);

void pushBackV(vectorVoid *v, void *source);

void test_pushBackV_emptyVector();

void test_pushBackV_fullVector();

void test_popBackV_notEmptyVector();

#endif //MAIN_C_VECTORVOID_H