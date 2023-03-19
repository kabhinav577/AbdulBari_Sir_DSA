#include <stdio.h>
// Sorted missing Number for Single element for n natural Number ---->
void nSingleMissNum(int a[])
{
    int sum =0 , s;
    for (int i = 0; i < 10; i++)
    {
        sum+=a[i];
    }
    s=11*(11+1)/2;

    printf("Missing Number is %d ", s-sum);
}

//Sorted Missing number for single element for natural is starting for any number which pass through function ->
void singleMissNum(int a[], int l)
{
    int diff;
    diff = l-0;
    for (int i = 0; i < 11; i++)
    {
        if (a[i] - i != diff)
        {
            printf("Missing Element is %d \n", i+diff);
            break;
        }
        
    }
    
}

// Sorted missing Number for Multiple element---->

void MultiMissNum( int a[], int l)
{
    int diff;
    diff = l;
    for (int i = 0; i < 10; i++)
    {
        if(a[i] - i != diff)
        {
            while (diff < a[i] - i)
            {
                printf("%d ", i+diff);
                diff++;
            }
            
        } 
    }
    
}

int main()
{
    
    int A[10] = {1,2,3,4,6,7,8,9,10,11};
    int A1[10] = {5,6,7,8,10,11,12,13,14,15};
    int A2[10] = {5,6,7,9,10,14,15,16,17,18};
    // singleMissNum(A1 , 5);
    MultiMissNum(A2, 5);
    // nSingleMissNum(A);
    return 0;
}