#include <stdio.h>

#define MAX_ITERATIONS 1000000

typedef struct {
    int x;
    int y;
} Point;

void performComplexCalculation(Point* point, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        point->x = point->x * point->x - point->y * point->y + 2;
        point->y = 2 * point->x * point->y + 3;
    }
}

int main() {
    Point complexPoint = {1, 1};
    int totalIterations = 0;

    while (totalIterations < MAX_ITERATIONS) {
        performComplexCalculation(&complexPoint, totalIterations);
        if (complexPoint.x * complexPoint.x + complexPoint.y * complexPoint.y > 1000) {
            break;
        }
        totalIterations++;
    }

    printf("Complex point after %d iterations: (%d, %d)\n", totalIterations, complexPoint.x, complexPoint.y);

    return 0;
}
