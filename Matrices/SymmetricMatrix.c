#include <stdio.h>

int main()
{
    int i, j, rows, columns, A[10][10], B[10][10], c = 1;
    printf("\nEnter the number of rows and columns : ");
    scanf("%d %d", &i, &j);

    printf("\n Enter the matrix elements \n");
    for (rows = 0; rows < i; rows++)
    {
        for (columns = 0; columns < j; columns++)
            scanf("%d", & A[rows][columns]);
    }

    // Finding Out the Transpose of Matrix

    for(rows = 0; rows < i; rows++)
    {
        for(columns = 0; columns < j; columns++)
           B[columns][rows] = A[rows][columns];
    }

    for ( rows = 0; rows < i; rows++)
    {
        for ( columns = 0; columns < j; columns++)
        {
            if (A[rows][columns] != B[rows][columns])
            {
                c++;
                break;
            }
            
        }
        
    }
    
    if (c == 1)
    {
        printf("\nThe Matrix is a Symmetric Mtarix.");
    }
    else
    {
        printf("\nThe Matrix is Not a Symmetric Mtarix.");
    }
    

    return 0;
}