#include <stdio.h>

void VowelCount( char S[])
{
    int i, vCount = 0, cCount = 0 ;
    for ( i = 0; S[i] != '\0'; i++)
    {
        if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U')
        {
          vCount++;
        }
        else if(( S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
        {
            cCount++;
        }
    }
    printf("%d Vowels and %d Consonants \n", vCount, cCount);
}

void WordCounter(char S[])
{
    int wordCount = 1;
    for (int i = 0; S[i] != '\0'; i++)
    {
        if(S[i] == ' ' && S[i+1] != ' ')
        {
            wordCount++;
        }
    }
   printf("%d Word\n", wordCount); 
}

int main()
{
    char A[] = "How are You";
    VowelCount(A);
    WordCounter(A);
    return 0;
}