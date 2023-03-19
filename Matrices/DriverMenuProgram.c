#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A, n, ch, i, j, x;
    printf("\nEnter Dimension : ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));

    do
    {
        printf("\nMenu :  \n");
        printf("1. Create\n");
        printf("2. Get\n");
        printf("3. Set\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        printf("\n Creating Matrix\n");
            for (i = 1; i <= n; i++)
                scanf("%d", A[i - 1]);
            break;
        case 2:
            printf("\n Enter indices.");
            scanf("%d", &i, &j);
            if (i == j)
                printf("%d ", A[i - 1]);
            else
                printf("0 ");
            break;
        case 3:
            printf("\nEnter the row, column and element:\n");
            scanf("%d %d %d", &i, &j, &x);
            if (i == j)
                A[i - 1] = x;
            break;
        case 4:
            printf("\nDisplay Matrices\n");
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        printf("%d ", A[i - 1]);
                    }
                    else
                    {
                        printf("0 ");
                    }
                }
                printf("\n");
            }
        }
    } while (ch < 5);

    return 0;
}