#include <stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Bubblesort(int* A, int n) {
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) {
        printf("working on pass %d\n",i+1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
         {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main() {
    int A[] = {2, 56, 14, 5, 44, 32};
    int n = 6;

    printf("Original array: ");
    printArray(A, n);

    Bubblesort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
