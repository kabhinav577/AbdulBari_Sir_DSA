#include <stdio.h>
#include <string.h>

// void DuplicateChar(int *A[])
// {
//     int count;
//     for (int i = 0; A[i] != '\0'; i++)
//     {
//         count = 1;
//         for(int j = i +1; A[j] != '\0'  ; j++)
//         {
//             if(A[i] == A[j] && A[i] != ' ')
//             {
//                 count++;
//                 A[j] = '0';
//             }
//         }
//         if(count > 1 && A[i] != '0')
//           printf("%c\n", A[i]);
//     }

// }

void HDuplicateChar(char S[])
{
    int H[26];
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; S[i] != '\0'; i++)
    {
        H[S[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c is Appearing %d times.\n", i + 97, H[i]);
        }
    }
}

int main()
{
    char S[] = "finding";
    // DuplicateChar(&A);
    HDuplicateChar(S);

    return 0;
}