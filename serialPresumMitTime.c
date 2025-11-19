#include <stdio.h>
#include <time.h>

void prefix_sum_serial(int *a, int *b, int n) {
    b[0] = a[0];
    for(int i = 1; i < n; i++) {
        b[i] = b[i-1] + a[i];
    }
}

int main() {
    int a[] = {1, 2, 1, 5, 0, 7, 3, 4, 2, 7};
    int n = sizeof(a)/sizeof(a[0]);
    int b[n];
    clock_t start, end;
    double elapsed;

    start = clock();
    prefix_sum_serial(a, b, n);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Serial prefix sum:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\nTime taken (serial): %f seconds\n", elapsed);

    return 0;
}

