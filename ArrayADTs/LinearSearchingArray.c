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

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//////// linear search with decrement in indexes  ///////
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
        
    }
    return -1;
}

//////// search Number is replace the index with 0 index ///////
int LinearSearch1(struct Array *arr, int key)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
        
    }
    return -1;
}


int main()
{
    struct Array arr = {{2, 3, 4, 5, 6, 8, 10, 12}, 10, 8};
    
    printf("Searching Number on Index is : %d\n", LinearSearch(&arr, 10));
    Display(arr);

    // printf("Searching Number on Index is : %d\n", LinearSearch(&arr, 2));
    // Display(arr);
    return 0;
}