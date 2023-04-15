#ifndef MAIN_C_VECTORVOID_H
#define MAIN_C_VECTORVOID_H

#include <limits.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

#endif //MAIN_C_VECTORVOID_H