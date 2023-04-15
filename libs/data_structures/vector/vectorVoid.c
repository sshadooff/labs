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

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

    if (index >= v->size) {
        fprintf(stderr, "Wrong value: index = %llu", index);
        exit(1);
    }
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

