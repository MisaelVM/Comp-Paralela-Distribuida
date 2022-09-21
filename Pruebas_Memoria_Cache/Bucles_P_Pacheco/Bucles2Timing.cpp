#include <iostream>
#include <chrono>

#define MAX 8192

double A[MAX][MAX], x[MAX], y[MAX];

int main()
{
    for (unsigned int n = 100; n <= MAX; n += 100) {
        int i, j;

        float mean_time = 0.f;
        for (int ss = 0; ss < 20; ++ss) {
            auto start = std::chrono::high_resolution_clock::now();
            for (j = 0; j < n; j++)
                for (i = 0; i < n; i++)
                    y[i] += A[i][j] * x[j];
            auto end = std::chrono::high_resolution_clock::now();

            float time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            mean_time += time;
        }
        mean_time /= 20;
        std::cout << n << " " << mean_time << "\n";
    }

    return 0;
}
