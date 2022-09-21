#include <iostream>

#define MAX 1000
#define BLOCK MAX / 50

double X[MAX][MAX], Y[MAX][MAX], M[MAX][MAX];

int main()
{
    int ii, jj, kk, i, j, k;
    for (ii = 0; ii < MAX; ii += BLOCK)
        for (jj = 0; jj < MAX; jj += BLOCK)
            for (kk = 0; kk < MAX; kk += BLOCK)
                for (i = ii; i < ii + BLOCK; i++)
                    for (j = jj; j < jj + BLOCK; j++)
                        for (k = kk; k < kk + BLOCK; k++)
                            M[i][j] += X[i][k] * Y[k][j];
    return 0;
}
