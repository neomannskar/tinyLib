#include <stdio.h>

#include "String.h"
#include "Vector.h"

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Vector intVector;
    VectorInit(&intVector);

    int a = 10;
    int b = 20;
    VectorAdd(&intVector, &a);
    VectorAdd(&intVector, &b);

    printf("Int Vector: %d, %d\n", *(int*)VectorGet(&intVector, 0), *(int*)VectorGet(&intVector, 1));

    VectorFree(&intVector);

    Vector structVector;
    VectorInit(&structVector);
    

    Point p1 = {1, 2};
    Point p2 = {3, 4};

    VectorAdd(&structVector, &p1);
    VectorAdd(&structVector, &p2);

    Point* point1 = (Point*)VectorGet(&structVector, 0);
    Point* point2 = (Point*)VectorGet(&structVector, 1);

    printf("Struct Vector: (%d, %d), (%d, %d)\n", point1->x, point1->y, point2->x, point2->y);

    VectorFree(&structVector);

    return 0;
}
