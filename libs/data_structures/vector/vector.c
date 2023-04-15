#include "vector.h"

Vector creatVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (Vector) {
            data,
            0,
            n
    };
}

void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = newCapacity;
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->capacity = v->size;
}

void deleteVector(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(Vector *v) {
    return v->size == 0;
}

bool isFull(Vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(Vector *v, size_t i) {
    return *(v->data + i);
}

void pushBack(Vector *v, int x) {
    if (v->capacity == 0)
        v->capacity++;
    else if (isFull(v))
        reserve(v, 2 * v->capacity);

    *(v->data + v->size++) = x;
}

void test_pushBack_emptyVector() {
    Vector v = creatVector(0);
    assert(isEmpty(&v));

    pushBack(&v, 5);
    assert(v.size == 1 && v.capacity == 1);

    pushBack(&v, 1);
    assert(v.size == 2 && v.capacity == 2);

    pushBack(&v, 9);
    assert(v.size == 3 && v.capacity == 4);

    pushBack(&v, 12);
    assert(v.size == 4 && v.capacity == 4);

    pushBack(&v, 3);
    assert(v.size == 5 && v.capacity == 8);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    Vector v = creatVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(isFull(&v));

    pushBack(&v, 4);
    assert(v.size == 3 && v.capacity == 4);

    pushBack(&v, 7);
    assert(v.size == 4 && v.capacity == 4);

    pushBack(&v, 9);
    assert(v.size == 5 && v.capacity == 8);

    deleteVector(&v);
}

void popBack(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->size--;
}

void test_popBack_notEmptyVector() {
    Vector v = creatVector(0);
    pushBack(&v, 5);
    pushBack(&v, 7);

    assert(v.size == 2);
    popBack(&v);
    assert(v.size == 1);
    assert(v.capacity == 2);
}

int *atVector(Vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int *back(Vector *v) {
    return v->data + v->size - 1;
}

int *front(Vector *v) {
    return v->data;
}

void test_atVector_notEmptyVector() {
    Vector v = creatVector(0);
    pushBack(&v, 6);
    pushBack(&v, 14);
    pushBack(&v, 9);
    pushBack(&v, 5);
    assert(!isEmpty(&v));

    assert(*atVector(&v, 1) == 14);
    assert(*atVector(&v, 2) == 9);
}

void test_atVector_requestToLastElement() {
    Vector v = creatVector(0);
    pushBack(&v, 7);
    pushBack(&v, 2);
    pushBack(&v, 11);
    pushBack(&v, 36);
    assert(!isEmpty(&v));

    assert(*atVector(&v, 0) == 7);
    assert(*atVector(&v, 3) == 36);
}

void test_back_oneElementInVector() {
    Vector v = creatVector(0);
    pushBack(&v, 15);
    assert(!isEmpty(&v));

    assert(*back(&v) == 15);
}

void test_front_oneElementInVector() {
    Vector v = creatVector(0);
    pushBack(&v, 15);
    assert(!isEmpty(&v));

    assert(*front(&v) == 15);
}