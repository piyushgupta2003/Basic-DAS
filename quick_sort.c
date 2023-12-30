#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot && i <= high)
        {
            i++;
        }

        while (A[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i <= j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        printArray(A,9) ;
        quickSort(A, low, partitionIndex - 1); // For left quickSort
        quickSort(A, partitionIndex + 1, high); // For right quickSort
    }
}

int main()
{
    int A[] = {2, 56, 14, 5, 44, 32, 5, 77, 8};
    int n = 9;

    printf("Original array: ");
    printArray(A, n);

    quickSort(A, 0, n - 1);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
