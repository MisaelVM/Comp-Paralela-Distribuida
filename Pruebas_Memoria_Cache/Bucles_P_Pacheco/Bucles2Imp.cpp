#include <iostream>

#define MAX 8100

double A[MAX][MAX], x[MAX], y[MAX];

int main()
{
    int i, j;
    for (j = 0; j < MAX; j++)
        for (i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];

    return 0;
}
