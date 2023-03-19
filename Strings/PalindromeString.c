#include <stdio.h>

int main()
{
    char A[] = "LIRIL";
    char B[7];
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    printf("%s \n", B);
    int k, l;
    for (k = 0, l = 0; A[k] != '\0' && B[l] != '\0'; k++, l++)
    {
        if (A[k] != B[l])
           break; 
    }
    if ( A[k] == B[l])
      printf("String is Palindrome!");
    else 
      printf("String is Not Palindrome!");  
    
    return 0;
}