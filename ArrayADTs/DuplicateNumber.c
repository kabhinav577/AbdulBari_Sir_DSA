#include <stdio.h>


void Display( int a[])
{
    printf("\nElements in array are : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
   printf("\n\n");
}

void Duplicate1(int a[])
{
    int lastDuplicate = 0;
    for (int i = 0; i < 10; i++)
    {
        if(a[i] == a[i+1] && a[i] != lastDuplicate)
        {
            printf("%d ", a[i]);
            lastDuplicate = a[i];
        }
    }
}

void DuplicateCount(int a[])
{
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if(a[i] == a[i+1])
        {
            j = i + 1;
            while (a[j] == a[i]) j++;
            printf("%d is appearing %d times.\n", a[i], j-1);
            i = j - 1;
        }
    }
    
}

void HashDuplicate( int a[], int max)
{
    int B[max + 1];
    for (int i = 0; i <= max  ; i++)
    {
        B[i] = 0;
    }
    
    for (int i = 0; i < 10; i++)
    {
        B[a[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if(B[i] > 1){
            printf("%d is Appearing %d times.\n", i, B[i]);
        }
    }
    printf("\n");
}

void UnsortedDuplicate(int a[])
{
    int count;
    for (int i = 0; i < 9; i++)
    {
        count = 1;
        if(a[i] != -1)
        {
            for (int j = i +1 ; j < 10; j++)
            {
                if (a[i] == a[j])
                {
                    count++;
                    a[j]= -1;
                }
                
            }
           if ( count > 1)
            printf("%d is Appearing %d times.\n", a[i], count); 
        }
    }
    printf("\n");
}

int main()
{
    int A[10] = {1,3,4,4,5,6,6,6,8,9};
    // int B[10] = {2,3,5,6,8,5,6,5,9,4};
    Display(A);
    // Duplicate1(A);
    // printf("\n");
    // DuplicateCount(A); // this function doesn't working properly
    // HashDuplicate(A, 9);
    // UnsortedDuplicate(B);
    return 0;
}