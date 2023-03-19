#include <stdio.h>

void ReverseString(char S[]) // With Swaping
{
    char temp;
    int i, j;
    for ( j = 0; S[j] != '\0' ; j++)
    {
        
    }
    j =j-1;
    for ( i = 0; i < j; i++, j--)
    {
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
    printf("%s \n", S);
}

void ReverseString1(char S[])
{
    char B[7];
    int i , j;
    for ( i = 0; S[i] != '\0' ; i++)
    {
    
    }
    i = i-1;
    for( j=0 ; i >= 0 ; j++, i--)
    {
        B[j] = S[i];
    }
    B[j] = '\0';
    printf("%s \n", B);
}



int main()
{
    char A[] = "PYTHON";
    // ReverseString(A);
    ReverseString1(A);
    return 0;
}