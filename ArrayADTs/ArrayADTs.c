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

void Append(struct Array *arr, int x)
{
    if (arr->used_size < arr->total_size)
        arr->A[arr->used_size++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->used_size)
    {
        for (int i = arr->used_size; i > index; i--)
            arr->A[i] = arr->A[i - 1];

        arr->A[index] = x;
        arr->used_size++;
    }
}

int Delete (struct Array *arr, int index)
{
    int x = 0;
    if (index>=0 && index<=arr->used_size)
    {
        x = arr->A[index];
        for (int i = index; i < arr->used_size -1; i++)
            arr->A[i] = arr->A[i+1];
        arr->used_size--;
        return x;
    }
    return 0;
    
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    
    // Append(&arr, 8);
    // Insert(&arr, 2, 8);
    // printf("Deleting Number is : %d\n", Delete(&arr, 1));
    Display(arr);
    return 0;
}