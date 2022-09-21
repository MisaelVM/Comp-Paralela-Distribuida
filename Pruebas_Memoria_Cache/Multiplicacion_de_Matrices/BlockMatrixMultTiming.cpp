#include <iostream>
#include <chrono>

#define MAX 1500

double X[MAX][MAX], Y[MAX][MAX], M[MAX][MAX];

int main()
{
    for (unsigned int n = 100; n <= MAX; n += 100) {
        int ii, jj, kk, i, j, k;

        float mean_time = 0.f;
        for (int ss = 0; ss < 20; ++ss) {
            // Initialization
            for (i = 0; i < MAX; ++i)
                for (j = 0; j < MAX; ++j)
                    M[i][j] = 0;

            const int BLOCK = n / 50;
            auto start = std::chrono::high_resolution_clock::now();
            for (ii = 0; ii < n; ii += BLOCK)
                for (jj = 0; jj < n; jj += BLOCK)
                    for (kk = 0; kk < n; kk += BLOCK)
                        for (i = ii; i < ii + BLOCK; i++)
                            for (j = jj; j < jj + BLOCK; j++)
                                for (k = kk; k < kk + BLOCK; k++)
                                    M[i][j] += X[i][k] * Y[k][j];
            auto end = std::chrono::high_resolution_clock::now();

            float time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            mean_time += time;
        }
        mean_time /= 20;
        std::cout << n << " " << mean_time << "\n";
    }

    return 0;
}
