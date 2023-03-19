#include <stdio.h>


void perm(char S[], int k)
{
    static int A[10] = {0};
    static char Result[10];

    if (S[k] == '\0')
    {

        Result[k] = '\0';
        printf("%s\t", Result);
    }
    else
    {
        for (int i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Result[k] = S[i];
                A[i] = 1;
                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }
}

void Swap( char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// l is Starting of string
// h is Ending of String 


void Perm1( char S[], int l, int h)
{
   if (l== h)
   {
    printf("%s\t", S);
   }
   else 
   {
     for (int i = l; i <= h; i++)
     {
        Swap(&S[l], &S[i]);
        Perm1(S, l+1, h);
        Swap(&S[l], &S[i]); // Backtracking
     }
   }
}



int main()
{
    char S[] = "ABC";
    // perm(S, 0);  // This is function take Static Array and store the value in Array
    Perm1(S, 0 , 2);
    return 0;
}