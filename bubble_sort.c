#include <stdio.h>

void bubble_sort(int arr[], int n, int *num_exchanges, int *num_comparisons, int *outer_loop_iterations, int *inner_loop_iterations) {
    *num_exchanges = 0;
    *num_comparisons = 0;
    *outer_loop_iterations = 0;
    *inner_loop_iterations = 0;

    for (int i = 0; i < n-1; i++) {
        (*outer_loop_iterations)++;
        for (int j = 0; j < n-i-1; j++) {
            (*inner_loop_iterations)++;
            (*num_comparisons)++;
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*num_exchanges)++;
            }
        }
    }
}

int main() {
    int numbers[] = {55, 25, 15, 40, 35, 17, 65, 75, 10};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int num_exchanges, num_comparisons, outer_loop_iterations, inner_loop_iterations;

    bubble_sort(numbers, n, &num_exchanges, &num_comparisons, &outer_loop_iterations, &inner_loop_iterations);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Number of exchange operations: %d\n", num_exchanges);
    printf("Number of comparison operations: %d\n", num_comparisons);
    printf("Number of outer loop iterations: %d\n", outer_loop_iterations);
    printf("Number of inner loop iterations: %d\n", inner_loop_iterations);

    return 0;
}
