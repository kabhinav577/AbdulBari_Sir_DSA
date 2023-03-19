#include <stdio.h>

int isAnagram(char P[], char Q[])
{
    int i, H[26] = {0};

    for (i = 0; P[i] != '\0'; i++)
    {
        H[P[i] - 97] += 1;
    }

    for (i = 0; Q[i] != '\0'; i++)
    {
        H[Q[i] - 97] -= 1;
        if (H[Q[i] - 97] < 0)
        {
            printf("NOt Anagram");
            break;
        }
    }
   if (Q[i] == '\0')
     printf("It's Anagram");
}

int main()
{
    char A[] = "decimal";
    char B[] = "medocal";

    isAnagram(A, B);
    return 0;
}