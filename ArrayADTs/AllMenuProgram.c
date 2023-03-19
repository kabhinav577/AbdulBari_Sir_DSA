#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];

        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

int Search(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
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

int Sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

int main()
{
    struct Array arr;
    int ch;
    int x, index;
    printf("Enter Size of Array : ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    do
    {
        printf("\n Menu \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index ");
            scanf("%d %d", &index, &x);
            Insert(&arr, index, x);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = Delete(&arr, index);
            printf("Deleted element is %d\n", x);
           break;
        case 3:
            printf("Enter element to search ");
            scanf("%d", &x);
            index = Search(arr, x);
            printf("Element index %d", index);
           break;
        case 4:
            printf("Sum is %d\n", Sum(arr));
           break;   
        case 5:Display(arr);   
        }
    } while (ch<6);
    
    return 0;
}