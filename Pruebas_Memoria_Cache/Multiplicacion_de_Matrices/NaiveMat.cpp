#define MAX 1000

double X[MAX][MAX], Y[MAX][MAX], M[MAX][MAX];

int main()
{
    int i, j, k;
    for (i = 0; i < MAX; ++i)
        for (j = 0; j < MAX; ++j) {
            M[i][j] = 0;
            for (k = 0; k < MAX; ++k)
                M[i][j] += X[i][k] * Y[k][j];
        }

    return 0;
}
