#include <stdio.h>

#define MAX_ITERATIONS 1000000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int a;
    int b;
    int c;
} ComplexValues;

void performComplexCalculation(Point* point, int iterations, ComplexValues* complexValues) {
    for (int i = 0; i < iterations; ++i) {
        point->x = point->x * complexValues->a - point->y * complexValues->b + complexValues->c;
        point->y = complexValues->a * point->x * point->y + complexValues->b * point->y + complexValues->c;
    }
}

int main() {
    Point complexPoint = {1, 1};
    ComplexValues complexValues = {2, 3, 4};
    int totalIterations = 0;

    while (totalIterations < MAX_ITERATIONS) {
        performComplexCalculation(&complexPoint, totalIterations, &complexValues);
        if (complexPoint.x * complexPoint.x + complexPoint.y * complexPoint.y > 1000) {
            break;
        }
        totalIterations++;
    }

    printf("Complex point after %d iterations: (%d, %d)\n", totalIterations, complexPoint.x, complexPoint.y);

    return 0;
}
