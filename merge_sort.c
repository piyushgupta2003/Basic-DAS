#include <stdio.h>

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high) {
    int i, j, k;
    int B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++, k++;
        } else {
            B[k] = A[j];
            j++, k++;
        }
    }
    while (i <= mid) {
        B[k] = A[i];
        k++, i++;
    }
    while (j <= high) {
        B[k] = A[j];
        k++, j++;
    }

    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    int A[] = {2, 56, 14, 5, 44, 32, 5, 77, 8};
    int n = 9;

    printf("Original array: ");
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
