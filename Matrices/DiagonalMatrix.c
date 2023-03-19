#include <stdio.h>

struct Matrix
{
    int M[10];
    int n;
};


void Set(struct Matrix *m, int i, int j, int k)
{
    if(i==j)
    {
        m->M[i-1]=k;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i==j)
    {
        return m.M[i-1];
    }
    else {
        return 0;
    }
}

void Display ( struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if(i==j)
             printf("%d ", m.M[i]);
            else
             printf("0 "); 
        }
        printf("\n");
    }
    
}

int main()
{
    struct Matrix m;
    m.n=4;
 
    Set(&m,1,1,2); Set(&m,2,2,4); Set(&m,3,3,6); Set(&m,4,4,8);
    printf("%d is element\n", Get(m,3,3));

    Display(m);

    return 0;
}