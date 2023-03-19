#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i - j == 1)
        m->A[i - 1] = x;
    if (i - j == 0)
        m->A[m->n - 1 + i - 1] = x;
    if (i - j == -1)
        m->A[(2 * m->n) - 1 + i - 1];
}

int Get(struct Matrix m, int i, int j)
{
    if (i - j == 1)
        return m.A[i - 1];
    if (i - j == 0)
        return m.A[m.n - 1 + i - 1];
    if (i - j == -1)
        return m.A[(2 * m.n) - 1 + i - 1];
}

void Display(struct Matrix m)
{
    int i, j;

    printf("\nMatrix is : \n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i - j == 1)
                printf("%d ", m.A[i - 1]);
            else if (i - j == 0)
                printf("%d ", m.A[m.n - 1 + i - 1]);
            else if (i - j == -1)
                printf("%d ", m.A[(2 * m.n) - 1 + i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix M;
    int i, j, x;

    printf("\nEnter Dimension of Matrix: ");
    scanf("%d", &M.n);
    M.A = (int *)malloc((3 * M.n - 2) * sizeof(int));

    printf("Enter all the elements of the Matrix: \n");
    for (i = 1; i <= M.n; i++)
    {
        for (j = 1; j <= M.n; j++)
        {
            scanf("%d", &x);
            Set(&M, i, j, x);
        }
    }

    Display(M);
    return 0;
}