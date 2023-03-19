#include <stdio.h>

void Display(int a[])
{
    printf("\nElements in Array are : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

void SumOfPair(int a[])
{
    int k = 10;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (a[i] + a[j] == k)
                printf("%d + %d = %d\n", a[i], a[j], k);
        }
    }
    printf("\n");
}

void HSumOfPair(int a[], int max)
{
    int k = 10;
    int B[max + 1];
    for (int i = 0; i <= max; i++)
    {
        B[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        B[a[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        if (B[k - a[i]] != 0)
        {
            printf("%d + %d = %d\n", a[i], k - a[i], k);
        }
        B[a[i]]++;
    }
    printf("\n");
}

// For Sorted Array pair of Sum of k----->

void sSumOfPair(int a[], int n, int k)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            printf("%d + %d = %d \n", a[i], a[j], k);
            i++;
            j--;
        }    
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    printf("\n\n");
}

int main()
{
    int A[10] = {6, 3, 8, 10, 15, 7, 5, 2, 9, 14};
    int B[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14}; // Sorted Array
    Display(B);
    // SumOfPair(A);
    // HSumOfPair(A, 15);  // this Function doesn't work
    sSumOfPair(B, 10, 10);
    return 0;
}