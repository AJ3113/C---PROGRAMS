#include<stdio.h>
int comparison = 0;
int n;

void printarray(int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n)
    {
        comparison++;
        if(arr[left] > arr[largest])
            largest = left;
    }

    if(right < n)
    {
        comparison++;
        if(arr[right] > arr[largest])
            largest = right;
    }

    if(largest != i)
    {
        int x = arr[i];
        int y = arr[largest];

        swap(&arr[i], &arr[largest]);

        printf("\nAfter swapping %d and %d:\n", x, y);
        printarray(arr);

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    // Build Max Heap
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    printf("\nMax Heap formed:\n");
    printarray(arr);

    // Heap Sort
    for(int i = n-1; i > 0; i--)
    {
        int x = arr[0];
        int y = arr[i];

        swap(&arr[0], &arr[i]);
 
        printf("\nAfter moving maximum element to position %d:\n", i);
        printarray(arr);

        heapify(arr, i, 0);
    }
}

int main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nArray before sorting:\n");
    printarray(arr);

    heapsort(arr, n);

    printf("\nSorted array:\n");
    printarray(arr);

    printf("\nTotal comparisons = %d\n", comparison);

    return 0;
}