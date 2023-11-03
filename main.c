#include <stdio.h>

#include "String.h"

int main() {
    printf("Hello World!\n\n");
    String str;
    str.content = "Hello";
    printf("%s\n\n", str.content);
    str = StrApp(&str, " World");
    printf("%s\n\n", str.content);
    StrFree(&str);
    return 0;
}