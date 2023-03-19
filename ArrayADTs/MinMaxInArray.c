#include <stdio.h>

void Display (int a[], int n)
{
    printf("\nElements in Array are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n"); 
}

void MinMax(int a[], int n)
{
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i] < min)
          min = a[i];
        else if ( a[i] > max)
          max = a[i];  
    }
    printf("Maximum Number in array is %d, Minimum number in array is %d.", max, min);
    printf("\n\n");
}

int main()
{
    int A[10] = {5,8,3,9,6,2,10,7,-1,4};
    Display(A, 10);
    MinMax(A, 10);
    return 0;
}