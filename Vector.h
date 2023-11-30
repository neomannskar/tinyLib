#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
} Vector;

void VecInit(Vector* vector) {
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

void VecApp(Vector* vector, void* element) {
    if (vector->size == vector->capacity) {
        vector->capacity = (vector->capacity == 0) ? 1 : vector->capacity * 2;
        vector->data = (void**) realloc(vector->data, vector->capacity * sizeof(void*));
    }

    vector->data[vector->size] = element;
    vector->size++;
}

void* VecGet(const Vector* vector, size_t index) {
    if (index >= vector->size) {
        return NULL;
    }
    return vector->data[index];
}

void VecFree(Vector* vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}
