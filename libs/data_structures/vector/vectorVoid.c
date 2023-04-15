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