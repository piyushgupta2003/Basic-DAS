#include <stdio.h>

void printArray(int* A, int n) 
{
    for (int i = 0; i < n; i++) 
    {  
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n) // 
{
    int key, i, j;
    
    for (i = 1; i <= n-1; i++) // Start from the second element (index 1)
    {
        key = A[i];
        j = i - 1;

        // Move elements of A[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {2, 56, 14, 5, 44, 32};
    int n = 6;

    insertionSort(A, n);
    printArray(A, n);

    return 0;
}
