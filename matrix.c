#include <stdio.h>

#define N 4

void multiplyMatrices(int firstMatrix[N][N], int secondMatrix[N][N], int result[N][N], int *innermostLoopCount, int *outermostLoopCount, int *totalMultiplications, int *totalAdditions) {
    int i, j, k;

    // Initializing elements of matrix result to 0.
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            result[i][j] = 0;
        }
    }

    // Resetting the counts
    *innermostLoopCount = 0;
    *outermostLoopCount = 0;
    *totalMultiplications = 0;
    *totalAdditions = 0;

    // Multiplying firstMatrix and secondMatrix and storing in result.
    for (i = 0; i < N; ++i) {
        (*outermostLoopCount)++; // Increment outermost loop count
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                (*innermostLoopCount)++; // Increment innermost loop count
                (*totalMultiplications)++; // Increment multiplications count
                (*totalAdditions)++; // Increment additions count
            }
        }
    }
}

int main() {
    int firstMatrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int secondMatrix[N][N] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int result[N][N]; // To store result of multiplication
    int innermostLoopCount, outermostLoopCount, totalMultiplications, totalAdditions;

    multiplyMatrices(firstMatrix, secondMatrix, result, &innermostLoopCount, &outermostLoopCount, &totalMultiplications, &totalAdditions);

    // Displaying the result
    printf("Resultant matrix is: \n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", result[i][j]);
            if (j == N - 1)
                printf("\n");
        }
    }

    // Displaying the counts
    printf("Outermost loop runs: %d times\n", outermostLoopCount);
    printf("Innermost loop runs: %d times\n", innermostLoopCount);
    printf("Total number of multiplications: %d\n", totalMultiplications);
    printf("Total number of additions: %d\n", totalAdditions);

    return 0;
}
