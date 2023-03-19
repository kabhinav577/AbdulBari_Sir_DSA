#include <stdio.h>
#include <stdlib.h>

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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse(struct Array *arr)
{
    int *B;
    B = (int *)malloc(arr->used_size * sizeof(int));
    int i, j;
    for (i = arr->used_size - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->used_size; i++)
        arr->A[i] = B[i];
}

void Reverse1(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->used_size - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // Reverse(&arr);
    Reverse1(&arr);
    Display(arr);
    return 0;
}