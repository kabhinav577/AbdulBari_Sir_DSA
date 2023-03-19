#include <stdio.h>

void CompareString(char P[], char Q[])
{
    int i, j;
    for (i = 0, j = 0; P[i] != '\0' && Q[j] != '\0'; i++, j++)
    {
        if (P[i] != Q[i])
            break;
    }
    if (P[i] == Q[j])
        printf("String is Equal.");
    else if (P[i] < Q[i])
        printf("String is Smaller.");
    else
        printf("String is Greater.");
}


int main()
{
    char A[] = "PAINTER";
    char B[] = "PAINTER";
    
    CompareString(A,B);
    return 0;
}