#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3]; //= {{1,2,3}, {4,5,6}, {7,8,9}};
    int *b[3];  // for base in stack and 2nd dimensional array point in heap memory 
    int **c;   // for Both are in heap memory

    // printf("Enter the value : ");
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         scanf("%d", &a[i][j]);
    //     }
    // }

    // Here are b variables store base in stack and point to heap memory for 2d array
    b[0] = (int *)malloc(3*sizeof(int));
    b[1] = (int *)malloc(3*sizeof(int));
    b[2] = (int *)malloc(3*sizeof(int));


    // Here are c variables store 2D_array in heap memory
    c=(int **)malloc(3*sizeof(int)); 

    c[0] = (int *)malloc(3*sizeof(int));
    c[1] = (int *)malloc(3*sizeof(int));
    c[2] = (int *)malloc(3*sizeof(int));
    c[0][0] = 1; 
    c[0][1] = 1; 
    c[0][2] = 1; 
    c[1][0] = 1; 
    c[1][1] = 1; 
    c[1][2] = 1; 
    c[2][0] = 1; 
    c[2][1] = 1; 
    c[2][2] = 1; 
    
    printf("This is Your 2D-Arrray: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}