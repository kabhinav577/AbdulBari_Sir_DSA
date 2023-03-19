#include <stdio.h>

void LengthOfString (char s[])
{
    printf("\nCharacter are : ");
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\nlength is %d ", i);
}

int main()
{
    char name[] = "ABHINAV";
    LengthOfString(name);
    return 0;
}