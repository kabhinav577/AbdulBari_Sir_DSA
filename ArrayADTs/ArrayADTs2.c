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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/////////// Get Method //////////////

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.used_size)
        return arr.A[index];
    return -1;
}

/////////// Set Method   //////////////

int Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->used_size)
        return arr->A[index] = x;
}

//////// Max Method   ////////////

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.used_size; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

///////// Min Method  ///////

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.used_size; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

///////// Sum Method  /////////

int Sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.used_size; i++)
        s += arr.A[i];
    return s;
}


//////// Average Method  //////////

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.used_size;
}



int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // printf("\n%d\n", Get(arr, 4));
    // printf("\n%d\n", Set(&arr, 4, 7));
    // printf("\n%d\n", Max(arr));
    // printf("\n%d\n", Min(arr));
    printf("\n%d\n", Sum(arr));
    printf("\n%f\n", Avg(arr));

    Display(arr);
    return 0;
}