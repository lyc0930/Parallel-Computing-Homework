// serial versions of the Buffon - Laplace Needle simulation
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// drop n needles of length l onto grids, size of every cell of which is a * b
int BuffonLaplaceSimulation(double l, double a, double b, int n)
{
    int hits = 0;
    double x1, y1, x2, y2;
    double angle;
    for (int i = 0; i < n; i++)
    {
        x1 = a * (double)rand() / (double)RAND_MAX;
        y1 = b * (double)rand() / (double)RAND_MAX;
        angle = 2.0 * M_PI * (double)rand() / (double)RAND_MAX;
        x2 = x1 + l * cos(angle);
        y2 = y1 + l * sin(angle);
        if (x2 <= 0 || x2 >= a || y2 <= 0 || y2 >= b)
            hits++;
    }
    return hits;
}

int main()
{
    int needleNumber = 1000000;
    double l = 3.0;
    double a = 7.0;
    double b = 7.0;
    // (2l(a + b) - l^2) / (pi ab)
    clock_t start = clock();
    double pi = (2 * l * (a + b) - pow(l, 2)) / (a * b) * (needleNumber) / (BuffonLaplaceSimulation(l, a, b, needleNumber));
    clock_t end = clock();
    printf("time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Pi = %lf", pi);
    return 0;
}