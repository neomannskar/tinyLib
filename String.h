#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *content;
    size_t length;
    size_t capacity;
} String;

void StrCap(String *string, const size_t cap) {
    string->capacity = (string->capacity > cap) ? string->capacity : cap;
}

size_t length(const char* str) {
    size_t length = 0;
    while(str[length] != '\0') length++;
    return length;
}

size_t StrLen(String *string) {
    if (string->length == 0) {
        if (string->content != NULL) {
            while(string->content[string->length] != '\0') string->length++;
            return string->length;
        } else {
            return 0;
        }
    } else return string->length;
}

String StrApp(String *string, const char *newContent) {
    String newStr; 
    newStr.length = StrLen(string) + length(newContent);
    newStr.content = (char*) malloc(newStr.length);
    
    size_t i = 0;
    while(string->content[i] != '\0') {
        newStr.content[i] = string->content[i];
        i++;
    }
    
    size_t j = 0;
    while(newContent[j] != '\0') {
        newStr.content[i + j] = newContent[j];
        j++;
    }

    newStr.content[newStr.length] = '\0';

    string->content = newStr.content;
    string->length = newStr.length;

    return newStr;
}

void StrFree(String *string) {
    if(string != NULL)
        free(string->content);
}
