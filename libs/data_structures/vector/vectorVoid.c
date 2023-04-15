#include "vectorVoid.h"

vectorVoid creatVectorV(size_t n, size_t baseTypeSize) {
    char *data = (char *) malloc(baseTypeSize * n);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {
            data,
            0,
            n,
            baseTypeSize
    };
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->data = (void *) realloc(v->data, v->baseTypeSize * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    v->capacity = v->size;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void test_getVectorValueV_emptyVector() {
    vectorVoid v = creatVectorV(0, sizeof(float));
    float x1 = 5.27f;
    float x;
    pushBackV(&v, &x1);
    getVectorValueV(&v, 0, &x);

    assert(v.size == 1 && v.capacity == 1 && x == x1);

    float x2 = -6.348f;
    pushBackV(&v, &x2);
    getVectorValueV(&v, 1, &x);

    assert(v.size == 2 && v.capacity == 2 && x == x2);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

    if (index >= v->size) {
        fprintf(stderr, "Wrong value: index = %llu", index);
        exit(1);
    }
}

void test_setVectorValueV_emptyVector() {
    vectorVoid v = creatVectorV(0, sizeof(char));
    char x1 = 'a';
    char x2 = 'b';
    pushBackV(&v, &x1);
    setVectorValueV(&v, 0, &x2);
    char x12;
    getVectorValueV(&v, 0, &x12);
    assert(v.size == 1 && v.capacity == 1 && x12 == x2);

    char x3 = 'c';
    char x4 = 'd';
    pushBackV(&v, &x3);
    setVectorValueV(&v, 1, &x4);
    getVectorValueV(&v, 1, &x12);
    assert(v.size == 2 && v.capacity == 2 && x12 == x4);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        v->capacity++;
    else if (isFullV(v))
        reserveV(v, 2 * v->capacity);

    char *destination = (char *) v->data + v->size++ * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void test_pushBackV_emptyVector() {
    vectorVoid v = creatVectorV(0, sizeof(int));
    assert(isEmptyV(&v));

    int x1 = 5;
    pushBackV(&v, &x1);
    assert(v.size == 1 && v.capacity == 1);

    int x2 = 1;
    pushBackV(&v, &x2);
    assert(v.size == 2 && v.capacity == 2);

    int x3 = 9;
    pushBackV(&v, &x3);
    assert(v.size == 3 && v.capacity == 4);

    int x4 = 12;
    pushBackV(&v, &x4);
    assert(v.size == 4 && v.capacity == 4);

    int x5 = 3;
    pushBackV(&v, &x5);
    assert(v.size == 5 && v.capacity == 8);

    deleteVectorV(&v);
}

void test_pushBackV_fullVector() {
    vectorVoid v = creatVectorV(2, sizeof(char));
    char x1 = 1;
    char x2 = 2;
    pushBackV(&v, &x1);
    pushBackV(&v, &x2);
    assert(isFullV(&v));

    char x3 = '4';
    pushBackV(&v, &x3);
    assert(v.size == 3 && v.capacity == 4);

    char x4 = '7';
    pushBackV(&v, &x4);
    assert(v.size == 4 && v.capacity == 4);

    char x5 = '9';
    pushBackV(&v, &x5);
    assert(v.size == 5 && v.capacity == 8);

    deleteVectorV(&v);
}

void test_popBackV_notEmptyVector() {
    vectorVoid v = creatVectorV(0, sizeof(float));
    float x1 = 5.27f;
    float x2 = 4.001f;
    pushBackV(&v, &x1);
    pushBackV(&v, &x2);

    assert(v.size == 2);
    popBackV(&v);
    assert(v.size == 1);
    assert(v.capacity == 2);
}