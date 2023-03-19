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

// with Loop
int binSearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.used_size - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

// With Recursion

int RbinSearch(int a[], int l, int h, int key)
{
    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RbinSearch(a, l, mid - 1, key);
        else
            return RbinSearch(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6, 8, 10, 12}, 10, 8};
    printf("\nSearching element index is %d\n", binSearch(arr, 6));
    printf("\nSearching element index is %d\n", RbinSearch(arr.A, 0, arr.used_size, 6));

    Display(arr);
    return 0;
}