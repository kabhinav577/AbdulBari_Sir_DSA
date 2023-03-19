#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(4 * sizeof(int));
    p[0] = 12;
    p[1] = 10;
    p[2] = 15;
    p[3] = 18;
    q = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", p[i]);
    }

    return 0;
}