#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElemnets in array are :\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

struct Array *MergeArray(struct Array *arr, struct Array *arr1)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
            arr2->A[k++] = arr->A[i++];
        else
            arr2->A[k++] = arr1->A[j++];
    }

    for (; i < arr->length; i++)
        arr2->A[k++] = arr->A[i];
    for (; j < arr1->length; j++)
        arr2->A[k++] = arr1->A[j];

    arr2->length = arr->length + arr1->length;
    arr2->size = 12;
    return arr2;
}

int main()
{
    struct Array arr = {{1, 3, 5, 7, 9, 11}, 20, 6};
    struct Array arr1 = {{2, 4, 6, 8, 10, 12}, 20, 6};
    struct Array *arr2;
    arr2 = MergeArray(&arr, &arr1);
    Display(*arr2);
    return 0;
}