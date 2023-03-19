#include <stdio.h>

int main()
{
    char S[] = "finding";
    long int H = 0, x = 0;

    for (int i = 0; S[i] != '\0'; i++)
    {
        x = 1;
        x = x << (S[i] - 97);   // f is ascii value 102  and perform 102 -97 = 5 store in bitwise array

        if( (x & H) > 0)
        {
            printf("%c is Duplicate.\n", S[i]);
        }
        else 
        {
            H = x | H;
        }
    }
    
    return 0;
}