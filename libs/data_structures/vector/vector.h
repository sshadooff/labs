#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>

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

bool isEmpty(Vector *v);

bool isFull(Vector *v);

int getVectorValue(Vector *v, size_t i);

void pushBack(Vector *v, int x);

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void popBack(Vector *v);

void test_popBack_notEmptyVector();

#endif //VECTOR_VECTOR_H
