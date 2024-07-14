#ifndef TINYLIB_STRING_H_
#define TINYLIB_STRING_H_

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./lib/error.h"

typedef struct {
    char *content;
    size_t length, capacity;
} String;

enum Err tl_strinit(String *string, const char *initialContent) {
    if (string == NULL) {
        tl_error("tl_strinit(String*, const char*)", "String* is NULL.");
        return TINYLIB_FAILURE;
    }
    if (initialContent == NULL) {
        tl_error("tl_strinit(String*, const char*)", "const char* is NULL.");
        return TINYLIB_FAILURE;
    }
    size_t initialLength = strlen(initialContent);
    string->content = (char *) malloc(initialLength + 1);
    if (string->content) {
        strcpy(string->content, initialContent);
        string->length = initialLength;
        string->capacity = initialLength;
    } else {
        tl_error("tl_strinit(String*, const char*)", "Memory allocation failed.");
        string->length = 0;
        string->capacity = 0;
    }
    return TINYLIB_SUCCESS;
}

enum Err tl_strcreate(const char *initialContent) {
    String *string = (String*)malloc(sizeof(String));
    if (string == NULL) {
        tl_error("tl_strcreate(String*, const char*)", "Memory allocation failed.");
        return TINYLIB_FAILURE;
    }
        
    if (initialContent == NULL) {
        tl_error("tl_strcreate(String*, const char*)", "const char* is NULL.");
        return TINYLIB_FAILURE;
    }

    size_t initialLength = strlen(initialContent);
    string->content = (char *) malloc(initialLength + 1);
    if (string->content) {
        strcpy(string->content, initialContent);
        string->length = initialLength;
        string->capacity = initialLength;
    } else {
        tl_error("tl_strinit(String*, const char*)", "Memory allocation failed.");
        string->length = 0;
        string->capacity = 0;
    }
    return TINYLIB_SUCCESS;
}

enum Err tl_strcap(String *string, const size_t cap) {
    if (string == NULL) {
        tl_error("tl_strcap(String*, const size_t)", "String* is NULL.");
        return TINYLIB_FAILURE;
    }

    if (string->capacity < cap) {
        char *newContent = (char *)realloc(string->content, cap + 1);
        if (newContent) {
            string->content = newContent;
            string->capacity = cap;
        } else {
            tl_error("tl_strcap(String*, const size_t)", "Memory reallocation failed.");
        }
    }
    return TINYLIB_SUCCESS;
}

size_t tl_strlen(const String *string) {
    if (string == NULL) {
        tl_error("tl_strlen(const String*)", "String* is NULL.");
        return 0;
    }
    return string->length;
}

enum Err tl_strapp(String *string, const char *newContent) {
    if (string == NULL) {
        tl_error("tl_strapp(String*, const char*)", "String* is NULL.");
        return TINYLIB_FAILURE;
    }

    if (newContent == NULL) {
        tl_error("tl_strapp(String*, const char*)", "const char* is NULL.");
        return TINYLIB_FAILURE;
    }

    size_t newLength = string->length + strlen(newContent);
    tl_strcap(string, newLength);

    if (string->content) {
        strcat(string->content, newContent);
        string->length = newLength;
    } else {
        tl_error("tl_strapp(String*, const char*)", "Appending failed due to previous memory allocation issue.");
    }
    return TINYLIB_SUCCESS;
}

void tl_strdrop(String *string) {
    if (string == NULL) {
        tl_error("tl_strdrop(String*)", "String* is NULL.");
        return TINYLIB_FAILURE;
    }

    if (string->content) {
        free(string->content);
    }
    string->content = NULL;
    string->length = 0;
    string->capacity = 0;
    return TINYLIB_SUCCESS;
}

void tl_strfree(String *string) {
    if (string == NULL) {
        tl_error("tl_strfree(String*)", "String* is NULL.");
        return TINYLIB_FAILURE;
    }

    if (string->content) {
        free(string->content);
    }
    string->content = NULL;
    string->length = 0;
    string->capacity = 0;
    free(string);
    return TINYLIB_SUCCESS;
}

#endif // TINYLIB_STRING_H_
