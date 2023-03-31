#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define M 1700
#define N 1000
#define K 800

double A[M][K], B[K][N], C[M][N];

int main()
{
    int i, j, k;
    double start_time, end_time;

    // Initialize matrices
    for (i = 0; i < M; i++) {
        for (j = 0; j < K; j++) {
            A[i][j] = i + j;
        }
    }
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            B[i][j] = i + j;
        }
    }

    // Multiply matrices sequentially
    clock_t t;
    t = clock();
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    // Print result and execution time
    printf("Matrix multiplication (SEQ) completed in %f seconds\n", time_taken);

    return 0;
}
