#include <stdio.h>

struct Array
{
    int A[10];
    int total_size;
    int used_size;
};

void Display(struct Array arr)
{
    printf("\nElements are\n");
    for (int i = 0; i < arr.used_size; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void insertSort(struct Array *arr, int x)
{
    int i = arr->used_size - 1;
    if (arr->used_size == arr->total_size)
    {
        printf("Array is full!");
        return;
    }
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->used_size++;
}

void isSorted(struct Array arr)
{
    for (int i = 0; i < arr.used_size - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            printf("FALSE\n");
           return;
        } 
    }
    printf("TRUE\n");
    
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // insertSort(&arr, -1);

    isSorted(arr);

    Display(arr);
    return 0;
}