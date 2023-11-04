#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *content;
    size_t length, capacity;
} String;

void StrInit(String *string, const char *initialContent) {
    size_t initialLength = strlen(initialContent);
    string->content = (char *) malloc(initialLength + 1);
    if (string->content) {
        strcpy(string->content, initialContent);
        string->length = initialLength;
        string->capacity = initialLength;
    } else {
        string->length = 0;
        string->capacity = 0;
    }
}

void StrCap(String *string, const size_t cap) {
    if (string->capacity < cap) {
        string->content = (char *)realloc(string->content, cap + 1);
        if (string->content) {
            string->capacity = cap;
        }
    }
}

size_t StrLen(String *string) {
    return string->length;
}

void StrApp(String *string, const char *newContent) {
    size_t newLength = string->length + strlen(newContent);
    StrCap(string, newLength);

    strcat(string->content, newContent);
    string->length = newLength;
}

void StrFree(String *string) {
    if (string->content) {
        free(string->content);
    }
    string->content = NULL;
    string->length = 0;
    string->capacity = 0;
}
