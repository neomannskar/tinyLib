#include <stdio.h>

#include "String.h"
#include "Vector.h"

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Vector intVector;
    VecInit(&intVector);

    int a = 10;
    int b = 20;
    VecApp(&intVector, &a);
    VecApp(&intVector, &b);

    printf("Int Vector: %d, %d\n", *(int*)VecGet(&intVector, 0), *(int*)VecGet(&intVector, 1));

    VecFree(&intVector);

    Vector structVector;
    VecInit(&structVector);
    

    Point p1 = {1, 2};
    Point p2 = {3, 4};

    VecApp(&structVector, &p1);
    VecApp(&structVector, &p2);

    Point* point1 = (Point*)VecGet(&structVector, 0);
    Point* point2 = (Point*)VecGet(&structVector, 1);

    printf("Struct Vector: (%d, %d), (%d, %d)\n", point1->x, point1->y, point2->x, point2->y);

    VecFree(&structVector);

    return 0;
}
