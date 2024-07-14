#ifndef TINYLIB_VECTOR_H_
#define TINYLIB_VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./lib/error.h"

typedef struct {
    void** data;
    size_t size, capacity;
} Vector;

enum Err tl_vinit(Vector *vector) {
    if (vector == NULL) {
        tl_error("tl_vinit(Vector*)", "Vector* is NULL.");
        return TINYLIB_FAILURE;
    }
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    return TINYLIB_SUCCESS;
}

Vector *tl_vcreate() {
    Vector *vector = (Vector*)malloc(sizeof(Vector));
    if (vector == NULL) {
        tl_error("tl_vcreate(Vector*)", "Memory allocation failed.");
        return NULL;
    }
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    return vector;
}

enum Err tl_vpush(Vector *vector, void* element) {
    if (vector == NULL) {
        tl_error("tl_vpush(Vector*, void*)", "Vector* is NULL.");
        return TINYLIB_FAILURE;
    }

    if (vector->size == vector->capacity) {
        vector->capacity = (vector->capacity == 0) ? 1 : vector->capacity * 2;
        vector->data = (void**) realloc(vector->data, vector->capacity * sizeof(void*));
    }

    vector->data[vector->size] = element;
    vector->size++;
    return TINYLIB_SUCCESS;
}

void* tl_vpop(Vector *vector) {
    if (vector == NULL) {
        tl_error("tl_vpop(Vector*)", "Vector* is NULL.");
        return NULL;
    }

    if (vector->size == 0) {
        tl_error("tl_vpop(Vector*)", "Vector is empty.");
        return NULL;
    }

    void* element = vector->data[vector->size - 1];
    vector->size--;

    if (vector->size > 0 && vector->size == vector->capacity / 4) {
        vector->capacity /= 2;
        vector->data = (void**) realloc(vector->data, vector->capacity * sizeof(void*));
    }

    return element;
}

void* tl_vget(const Vector *vector, size_t index) {
    if (vector == NULL) {
        tl_error("tl_vget(Vector*)", "Vector* is NULL.");
        return;
    }

    if (index >= vector->size) {
        return NULL;
    }
    return vector->data[index];
}

enum Err tl_vdrop(Vector *vector) {
    if (vector == NULL) {
        tl_error("tl_vdrop(Vector*)", "Vector* is NULL.");
        return TINYLIB_FAILURE;
    }

    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    return TINYLIB_SUCCESS;
}

enum Err tl_vfree(Vector *vector) {
    if (vector == NULL) {
        tl_error("tl_vfree(Vector*)", "Vector* is NULL.");
        return TINYLIB_FAILURE;
    }

    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    free(vector);
    return TINYLIB_SUCCESS;
}

#endif // TINYLIB_VECTOR_H_
